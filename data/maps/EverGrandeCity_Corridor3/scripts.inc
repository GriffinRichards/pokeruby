EverGrandeCity_Corridor3_MapScripts:: @ 815BA36
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Corridor3_MapScript2_15BA3C
	.byte 0

EverGrandeCity_Corridor3_MapScript2_15BA3C:: @ 815BA3C
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Corridor3_EventScript_15BA46
	.2byte 0

EverGrandeCity_Corridor3_EventScript_15BA46:: @ 815BA46
	turnobject LOCALID_PLAYER, 2
	end
