EverGrandeCity_Corridor5_MapScripts:: @ 815BA60
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Corridor5_MapScript2_15BA66
	.byte 0

EverGrandeCity_Corridor5_MapScript2_15BA66:: @ 815BA66
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Corridor5_EventScript_15BA70
	.2byte 0

EverGrandeCity_Corridor5_EventScript_15BA70:: @ 815BA70
	turnobject LOCALID_PLAYER, 2
	end
