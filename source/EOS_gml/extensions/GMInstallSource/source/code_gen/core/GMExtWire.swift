import Foundation

enum GMError: Error {
    case bufferUnderflow
    case bufferOverflow
    case corrupt(String)
    case unknownTag(UInt8)
    case typeMismatch(String)
    case notImplemented(String)
}

enum GMKind: UInt8 {
    case uInt8 = 1
    case int8 = 2
    case uInt16 = 3
    case int16 = 4
    case uInt32 = 5
    case int32 = 6
    case float16 = 7
    case float32 = 8
    case float64 = 9
    case bool = 10
    case string = 11
    case text = 13

    case uInt64 = 12

    case typedStruct = 249
    case typedArray = 250
    case undefined = 251
    case pointer = 252
    case buffer = 253
    case array = 254
    case object = 255  // C++ calls it Struct, GML exposes objects

    init(tag: UInt8) throws {
        guard let k = GMKind(rawValue: tag) else {
            throw GMError.unknownTag(tag)
        }
        self = k
    }
}

public indirect enum GMValue {
    case null
    case bool(Bool)

    case uInt8(UInt8)
    case int8(Int8)
    case uInt16(UInt16)
    case int16(Int16)
    case uInt32(UInt32)
    case int32(Int32)
    case uInt64(UInt64)

    case float16(UInt16)  // raw 16-bit payload
    case float32(Float)
    case float64(Double)

    case string(String)
    case text(String)

    case array([GMValue])
    case object([String: GMValue])

    var kind: GMKind {
        switch self {
        case .null: return .undefined
        case .bool: return .bool
        case .uInt8: return .uInt8
        case .int8: return .int8
        case .uInt16: return .uInt16
        case .int16: return .int16
        case .uInt32: return .uInt32
        case .int32: return .int32
        case .uInt64: return .uInt64
        case .float16: return .float16
        case .float32: return .float32
        case .float64: return .float64
        case .string: return .string
        case .text: return .text
        case .array: return .array
        case .object: return .object
        }
    }
}

public protocol IByteWriter {
    var remaining: Int { get }
    mutating func writeBytes(_ bytes: UnsafeRawPointer, count: Int) throws
}

public extension IByteWriter {
    mutating func write<T>(_ v: T) throws {
        var tmp = v
        try withUnsafeBytes(of: &tmp) { raw in
            try writeBytes(raw.baseAddress!, count: raw.count)
        }
    }

    private mutating func writeStringPayload(_ s: String) throws {
        let bytes = Array(s.utf8)
        try write(Int32(bytes.count).littleEndian)
        try bytes.withUnsafeBytes { raw in
            try writeBytes(raw.baseAddress!, count: raw.count)
        }
        try write(UInt8(0))
    }

    /// Encode a raw value using the codec layout (no GMKind tag).
    mutating func writeRaw<Value>(_ value: Value) throws {
        let mirror = Mirror(reflecting: value)

        // 1) Optionals -> Bool + inner payload
        if mirror.displayStyle == .optional {
            if let some = mirror.children.first?.value {
                try write(UInt8(1))          // hasValue = true
                try writeRaw(some)
            } else {
                try write(UInt8(0))          // hasValue = false
            }
            return
        }

        // 2) Fast path for primitives / strings / ITypedStruct
        switch value {
        case let x as Int8:   try write(x.littleEndian)
        case let x as UInt8:  try write(x)
        case let x as Int16:  try write(x.littleEndian)
        case let x as UInt16: try write(x.littleEndian)

        case let x as Int:
            let v32 = Int32(truncatingIfNeeded: x)
            try write(v32.littleEndian)

        case let x as Int32:  try write(x.littleEndian)
        case let x as UInt32: try write(x.littleEndian)
        case let x as Int64:  try write(x.littleEndian)
        case let x as UInt64: try write(x.littleEndian)

        case let x as Bool:
            try write(UInt8(x ? 1 : 0))

        case let x as Float:
            try write(x.bitPattern.littleEndian)

        case let x as Double:
            try write(x.bitPattern.littleEndian)

        case let s as String:
            try writeStringPayload(s)        // length + utf8 + NUL

        case let s as ITypedStruct:
            try s.encode(&self)              // pure payload, no tag/codecID
            return

        default:
            // 3) Collections -> Int32 length + elems
            if mirror.displayStyle == .collection {
                let elems = mirror.children.map { $0.value }

                try write(Int32(elems.count).littleEndian)
                for e in elems {
                    try writeRaw(e)
                }
                return
            }

            if mirror.displayStyle == .dictionary {
                throw GMError.typeMismatch(
                    "writeRaw: dictionaries are not supported as codec-level values"
                )
            }

            throw GMError.typeMismatch("writeRaw: unsupported type \(type(of: value))")
        }
    }

    /// Convenience: List<T> = Int32 length + elements.
    mutating func writeRawList<T>(_ xs: [T]) throws {
        try write(Int32(xs.count).littleEndian)
        for x in xs {
            try writeRaw(x)
        }
    }

    /// Convenience: Vector<T> = fixed-count, no length prefix.
    mutating func writeRawVector<T>(_ xs: [T]) throws {
        for x in xs {
            try writeRaw(x)
        }
    }

    /// Convenience: Fixed-size array, same layout as vector.
    mutating func writeRawFixedArray<T>(_ xs: [T]) throws {
        for x in xs {
            try writeRaw(x)
        }
    }

    mutating func writeGMValue(_ value: Any) throws {
        let mirror = Mirror(reflecting: value)

        // Optionals -> undefined / inner
        if mirror.displayStyle == .optional {
            if let some = mirror.children.first?.value {
                try writeGMValue(some)
            } else {
                try write(GMKind.undefined.rawValue)
            }
            return
        }

        switch value {
        case let x as Int8:
            try write(GMKind.int8.rawValue)
            try write(x.littleEndian)

        case let x as UInt8:
            try write(GMKind.uInt8.rawValue)
            try write(x.littleEndian)

        case let x as Int16:
            try write(GMKind.int16.rawValue)
            try write(x.littleEndian)

        case let x as UInt16:
            try write(GMKind.uInt16.rawValue)
            try write(x.littleEndian)

        case let x as Int:
            let v32 = Int32(truncatingIfNeeded: x)
            try write(GMKind.int32.rawValue)
            try write(v32.littleEndian)

        case let x as Int32:
            try write(GMKind.int32.rawValue)
            try write(x.littleEndian)

        case let x as UInt32:
            try write(GMKind.uInt32.rawValue)
            try write(x.littleEndian)

        case let x as Int64:
            try write(GMKind.uInt64.rawValue)
            try write(x.littleEndian)

        case let x as UInt64:
            try write(GMKind.uInt64.rawValue)
            try write(Int64(bitPattern: x).littleEndian)

        case let x as Bool:
            try write(GMKind.bool.rawValue)
            try write(UInt8(x ? 1 : 0))

        case let x as Float:
            try write(GMKind.float32.rawValue)
            try write(x.bitPattern.littleEndian)

        case let x as Double:
            try write(GMKind.float64.rawValue)
            try write(x.bitPattern.littleEndian)

        case let s as String:
            try write(GMKind.string.rawValue)
            try writeStringPayload(s)

        case let s as ITypedStruct:
            try write(GMKind.typedStruct.rawValue)
            try write(type(of: s).codecID.littleEndian)
            try s.encode(&self)

        default:
            if mirror.displayStyle == .collection {
                let elems = mirror.children.map { $0.value }
                try write(GMKind.array.rawValue)
                try write(UInt16(elems.count).littleEndian)
                for e in elems {
                    try writeGMValue(e)
                }
                return
            }

            if mirror.displayStyle == .dictionary {
                var dict: [(String, Any)] = []
                dict.reserveCapacity(mirror.children.count)
                for child in mirror.children {
                    guard let pair = child.value as? (key: Any, value: Any) else { continue }
                    guard let keyStr = pair.key as? String else {
                        throw GMError.typeMismatch("GM object key is not String")
                    }
                    dict.append((keyStr, pair.value))
                }

                try write(GMKind.object.rawValue)
                try write(UInt16(dict.count).littleEndian)

                for (k, val) in dict {
                    try write(GMKind.string.rawValue)
                    try writeStringPayload(k)
                    try writeGMValue(val)
                }
                return
            }

            throw GMError.typeMismatch("writeGMValue: unsupported type \(type(of: value))")
        }
    }
}

struct BufferWriter: IByteWriter {
    private let base: UnsafeMutableRawPointer
    private let size: Int
    private var offset: Int = 0

    init(base: UnsafeMutableRawPointer, size: Int) {
        self.base = base
        self.size = size
    }

    var remaining: Int { size - offset }

    mutating func writeBytes(_ bytes: UnsafeRawPointer, count: Int) throws {
        guard remaining >= count else { throw GMError.bufferOverflow }
        base.advanced(by: offset).copyMemory(from: bytes, byteCount: count)
        offset += count
    }
}

final class VectorWriter: IByteWriter {
    private(set) var data = Data()

    var remaining: Int { .max }  // “infinite” like a vector, practically

    func writeBytes(_ bytes: UnsafeRawPointer, count: Int) throws {
        let buffer = UnsafeRawBufferPointer(start: bytes, count: count)
        data.append(contentsOf: buffer)
    }

    // convenience
    func clear() { data.removeAll(keepingCapacity: true) }
}

public protocol IByteReader {
    var remaining: Int { get }
    mutating func readBytes(_ count: Int) throws -> UnsafeRawBufferPointer
}

struct BufferReader: IByteReader {
    private let base: UnsafeRawPointer
    private let size: Int
    private var offset: Int = 0

    init(base: UnsafeRawPointer, size: Int) {
        self.base = base
        self.size = size
    }

    var remaining: Int { size - offset }

    mutating func readBytes(_ count: Int) throws -> UnsafeRawBufferPointer {
        guard remaining >= count else { throw GMError.bufferUnderflow }
        let ptr = base.advanced(by: offset)
        offset += count
        return UnsafeRawBufferPointer(start: ptr, count: count)
    }
}

public extension IByteReader {

    private mutating func readPrimitive<T>() throws -> T {
        let rb = try readBytes(MemoryLayout<T>.size)
        return rb.baseAddress!.assumingMemoryBound(to: T.self).pointee
    }

    private mutating func readUInt8() throws -> UInt8  { try readPrimitive() }
    private mutating func readInt8()  throws -> Int8   { try readPrimitive() }

    private mutating func readUInt16() throws -> UInt16 { UInt16(littleEndian: try readPrimitive()) }
    private mutating func readInt16()  throws -> Int16  { Int16(littleEndian:  try readPrimitive()) }
    private mutating func readUInt32() throws -> UInt32 { UInt32(littleEndian: try readPrimitive()) }
    private mutating func readInt32()  throws -> Int32  { Int32(littleEndian:  try readPrimitive()) }
    private mutating func readUInt64() throws -> UInt64 { UInt64(littleEndian: try readPrimitive()) }
    private mutating func readInt64()  throws -> Int64  { Int64(littleEndian:  try readPrimitive()) }

    private mutating func readFloat32() throws -> Float {
        let bits: UInt32 = try readUInt32()
        return Float(bitPattern: bits)
    }

    private mutating func readFloat64() throws -> Double {
        let bits: UInt64 = try readUInt64()
        return Double(bitPattern: bits)
    }

    private mutating func readBool() throws -> Bool {
        try readUInt8() != 0
    }

    private mutating func readString() throws -> String {
        let len: Int32 = try readInt32()
        let count = Int(len)
        guard remaining >= count + 1 else { throw GMError.bufferUnderflow }

        let bytesBuf = try readBytes(count)
        let nul: UInt8 = try readUInt8()
        guard nul == 0 else { throw GMError.corrupt("String missing NUL") }

        return String(decoding: bytesBuf, as: UTF8.self)
    }

    mutating func readRaw<T>(_ type: T.Type = T.self) throws -> T {
        // Primitives
        if T.self == Int8.self    { return try readInt8()    as! T }
        if T.self == UInt8.self   { return try readUInt8()   as! T }
        if T.self == Int16.self   { return try readInt16()   as! T }
        if T.self == UInt16.self  { return try readUInt16()  as! T }
        if T.self == Int32.self   { return try readInt32()   as! T }
        if T.self == UInt32.self  { return try readUInt32()  as! T }
        if T.self == Int64.self   { return try readInt64()   as! T }
        if T.self == UInt64.self  { return try readUInt64()  as! T }
        if T.self == Bool.self    { return try readBool()    as! T }
        if T.self == Float.self   { return try readFloat32() as! T }
        if T.self == Double.self  { return try readFloat64() as! T }
        if T.self == String.self  { return try readString()  as! T }

        // ITypedStruct payloads
        if let structType = T.self as? ITypedStruct.Type {
            var tmp = self
            let anyStruct = try structType.init(&tmp)
            self = tmp
            return anyStruct as! T
        }

        throw GMError.typeMismatch("readRaw: unsupported type \(T.self)")
    }

    mutating func readRaw<Element>(_ type: [Element].Type) throws -> [Element] {
        // reuse your list layout: Int32 length + elements
        let count: Int32 = try readInt32()
        if count < 0 { throw GMError.corrupt("negative list size \(count)") }
        var result: [Element] = []
        result.reserveCapacity(Int(count))
        for _ in 0..<Int(count) {
            result.append(try readRaw(Element.self))
        }
        return result
    }

    mutating func readRawOptional<T>(_ type: T.Type = T.self) throws -> T? {
        let has = try readBool()
        if !has { return nil }
        return try readRaw(T.self)
    }

    /// Vector<T>: fixed-count, caller knows count (no length prefix)
    mutating func readRawVector<T>(_ type: T.Type = T.self, count: Int) throws -> [T] {
        var result: [T] = []
        result.reserveCapacity(count)
        for _ in 0..<count {
            result.append(try readRaw(T.self))
        }
        return result
    }

    /// Fixed-size array: same as vector but semantic name
    mutating func readRawFixedArray<T>(_ type: T.Type = T.self, count: Int) throws -> [T] {
        var result: [T] = []
        result.reserveCapacity(count)
        for _ in 0..<count {
            result.append(try readRaw(T.self))
        }
        return result
    }

    mutating func readGMFunction(_ dispatcher: GMDispatchQueue) throws -> GMFunction {
        let uid = try readRaw(UInt64.self)
        return GMFunction(id: uid, dispatcher: dispatcher)
    }

    mutating func readGMValue() throws -> GMValue {
        let tag = try readUInt8()
        let kind = try GMKind(tag: tag)

        switch kind {
        case .uInt8: return .uInt8(try readUInt8())
        case .int8: return .int8(try readInt8())
        case .uInt16: return .uInt16(try readUInt16())
        case .int16: return .int16(try readInt16())
        case .uInt32: return .uInt32(try readUInt32())
        case .int32: return .int32(try readInt32())
        case .uInt64: return .uInt64(try readUInt64())

        case .float16: return .float16(try readUInt16())
        case .float32: return .float32(try readFloat32())
        case .float64: return .float64(try readFloat64())

        case .bool: return .bool(try readBool())
        case .string: return .string(try readString())
        case .text: return .text(try readString())

        case .array:
            let sz = try readUInt16()
            var arr: [GMValue] = []
            arr.reserveCapacity(Int(sz))
            for _ in 0..<Int(sz) {
                arr.append(try readGMValue())
            }
            return .array(arr)

        case .object:
            let sz = try readUInt16()
            var dict: [String: GMValue] = [:]
            dict.reserveCapacity(Int(sz))
            for _ in 0..<Int(sz) {
                guard case .string(let key) = try readGMValue() else {
                    throw GMError.typeMismatch("object key not string")
                }
                dict[key] = try readGMValue()
            }
            return .object(dict)

        case .typedArray, .typedStruct:
            throw GMError.typeMismatch("Typed kinds never come from GML")

        case .undefined:
            return .null

        case .pointer, .buffer:
            throw GMError.notImplemented("pointer/buffer")
        }
    }
}

protocol ITypedStruct {
    static var codecID: UInt32 { get }

    init<R: IByteReader>(_ r: inout R) throws
    func encode<W: IByteWriter>(_ w: inout W) throws
}

enum GMFunctionAction: UInt8 {
    case execute = 1
    case release = 2
}

protocol GMDispatcher {
    func dispatch(_ packet: Data)
    func fetch(into output: inout BufferWriter) -> Double
}

public final class GMDispatchQueue: GMDispatcher {

    // Raw event frames: each Data is already `[uid][action][args...]`
    private var queue: [Data] = []
    private let lock = NSLock()

    // Packed payload persisted across fetch calls if buffer is too small.
    private var packed: Data? = nil

    func dispatch(_ packet: Data) {
        lock.lock()
        queue.append(packet)
        lock.unlock()
    }

    /// Packs pending events into a GM Array and writes it into `output`.
    /// Returns:
    ///  0.0 if nothing to send
    ///  >0  bytes actually written
    ///  <0  negative bytes needed (output too small)
    func fetch(into output: inout BufferWriter) -> Double {
        // If we don't already have a packed buffer, build one from the queue.
        if packed == nil {
            var local: [Data] = []
            
            // Steal all pending events in O(1-ish) under the lock.
            lock.lock()
            if !queue.isEmpty {
                local = queue
                queue.removeAll(keepingCapacity: true)
            }
            lock.unlock()
            
            // Nothing to send at all.
            if local.isEmpty {
                return 0.0
            }
            
            // Build a GM Array: [tag=Array][count:UInt16][frame1][frame2]...
            var vw = VectorWriter()  // dynamic Data-backed writer
            do {
                try vw.write(GMKind.array.rawValue)  // tag 254
                try vw.write(UInt16(local.count).littleEndian)  // number of frames
                
                for frame in local {
                    try frame.withUnsafeBytes { rawBuf in
                        try vw.writeBytes(rawBuf.baseAddress!, count: rawBuf.count)
                    }
                }
                
                packed = vw.data
            } catch {
                // On error, drop the attempt and pretend nothing to send
                packed = nil
                return 0.0
            }
        }
        
        guard let payload = packed else { return 0.0 }
        
        let bytesNeeded = payload.count
        if bytesNeeded > output.remaining {
            // Not enough space – keep `packed` so caller can retry with a bigger buffer.
            return -Double(bytesNeeded)
        }
        
        // We have room – copy it out.
        payload.withUnsafeBytes { rawBuf in
            try? output.writeBytes(rawBuf.baseAddress!, count: rawBuf.count)
        }
        
        // Success: clear packed and report how many bytes we wrote.
        packed = nil
        return Double(bytesNeeded)
    }

}

public final class GMFunction {
    private let uid: UInt64
    private weak var dispatcher: GMDispatchQueue?

    init(id: UInt64, dispatcher: GMDispatchQueue) {
        self.uid = id
        self.dispatcher = dispatcher
    }

    deinit {
        guard let dispatcher = dispatcher, uid != 0 else { return }

        let writer = VectorWriter()
        var w = writer
        try? w.write(uid.littleEndian)
        try? w.write(GMFunctionAction.release.rawValue)

        dispatcher.dispatch(writer.data)
    }

    /// Public entry – an *array argument* stays a single GM argument.
    func call(_ args: Any...) {
        callImpl(args)
    }

    /// Internal helper working on the `[Any]` list.
    private func callImpl(_ args: [Any]) {
        guard let dispatcher = dispatcher else { return }

        let writer = VectorWriter()
        var w = writer

        do {
            // [raw uid][raw action]
            try w.write(uid.littleEndian)
            try w.write(GMFunctionAction.execute.rawValue)

            // Encode args as a GM Array (tag 254)
            try w.write(GMKind.array.rawValue)
            try w.write(UInt16(args.count).littleEndian)

            for arg in args {
                try w.writeGMValue(arg)
            }

            dispatcher.dispatch(writer.data)
        } catch {
            // log or ignore
        }
    }
}

/// Thin wrapper around a raw pointer + length.
/// Does **not** own the memory – caller is responsible for lifetime.
public struct GMBuffer {
    let base: UnsafeMutableRawPointer
    let size: Int

    init(base: UnsafeMutableRawPointer, size: Int) {
        self.base = base
        self.size = size
    }

    /// Create a writer over this buffer (for filling it).
    func makeWriter() -> BufferWriter {
        BufferWriter(base: base, size: size)
    }

    /// Create a reader over this buffer (for reading from it).
    func makeReader() -> BufferReader {
        BufferReader(base: UnsafeRawPointer(base), size: size)
    }
}
