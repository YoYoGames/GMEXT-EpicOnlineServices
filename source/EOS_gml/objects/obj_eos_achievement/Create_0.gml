
event_inherited();

//{ unlocked_description : "AchEpicTest UnLocked Desc", flavor_text : "AchEpicTest FlavorText", unlocked_icon_url : "https://d2fyye1bqi3u0k.cloudfront.net/750a6c35c15a4879baf3c4a2e02ca60d%2Ficons%2Fgold-trophy-png.png?Expires=1784072666&Signature=lQd1ngXJmvCw37bGyoDhxBIlPsQqG-iqL8QM2VQ1C06iHsLhHE-NTlcx2R7StVrdL~6Lwg0uwHTOLBuru2IhSd2mPmTFDAm3C6GJLQR4mVjMvQoX0MHlhNsd8Brj7qxqNP5sGwGPP~i78oJYYmXF~Uql9WqP-K~0YrAtslMlwwrAPCU24WpK0H5gvajRQaVSXqYcBC9ZtMjPgvdi4J4xJyOlF9fNwTIewwaiQ3CtP0y7h0IDibxhCUEBLGGgn8jvI7s2KaI3SBAa4bJLC9ugrKLIHElH-4zltfUdM1oOyN59Sz5U7tC6Z2si7EAcXeORdPFBxpqCTif7j~i~Jn46vQ__&Key-Pair-Id=APKAJQMTYOIXEXXNMKRQ", locked_icon_url : "https://d2fyye1bqi3u0k.cloudfront.net/750a6c35c15a4879baf3c4a2e02ca60d%2Ficons%2Fgold-trophy-locked.png?Expires=1784072666&Signature=MQQepmmYKMfBNTctfwZgR2CnkCTMjOGdKuyzs89kM9QpzzR~7rqoGLurFQFIse8WRPnaH-nOXGnt9F7OWy0PeD14PtElnxDr4z6srEO2EgTeUNtbDLLx-RW8grOfHoSu2smZLUHbn45pSo9L7OgBpIVTCnFFucM~uvBFZoS-42nGj3sZtoXjlmoQx8KPEFvQzD1VWQlWAAD8KqATPwLrtfQ747ATfhJtN21lCCf1SoWv~6hsmH6bOK7gvGF1c0AUj5hIUVZy6T6B~Flxmni44I5mzxtL7B9BIgSdNhrXjUUJOeGQnIBPBOLYUhEenSq1X9-PYOCopWwMM3co9N3ZNQ__&Key-Pair-Id=APKAJQMTYOIXEXXNMKRQ", achievement_id : "YYEpicTest_Achievement", locked_display_name : "AchEpicTest Locked", locked_description : "AchEpicTest Locked Desc", completion_description : "", is_hidden : 0, stat_thresholds_count : 1, unlocked_display_name : "AchEpicTest UnLocked" }

locked = true

spr_unlocked = noone
spr_locked = noone

pending_requests = ds_map_create()

show_debug_message(data)

// Prioritize unlocked icon if it exists
if (struct_exists(data, "unlocked_icon_url")){
	spr_unlocked = sprite_add(data.unlocked_icon_url,0,0,0,0,0)
}

if (struct_exists(data, "locked_icon_url")){
	spr_locked = sprite_add(data.unlocked_icon_url,0,0,0,0,0)
}
