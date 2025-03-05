
randomize()

function eos_create_code(digits = 4,characters = "0123456789")
{
	var str = ""
	repeat(digits)
		str += string_char_at(characters,irandom(string_length(characters)))
	
	return str
}
