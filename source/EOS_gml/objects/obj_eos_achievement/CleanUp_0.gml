
ds_map_destroy(pending_requests)

if (sprite_exists(spr_unlocked)) {
	sprite_delete(spr_unlocked)
}

if (sprite_exists(spr_locked)) {
	sprite_delete(spr_locked)
}
