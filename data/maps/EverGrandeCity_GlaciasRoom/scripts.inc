EverGrandeCity_GlaciasRoom_MapScripts:: @ 815B673
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_MapScript2_15B692
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_MapScript1_15B6A9
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_MapScript2_15B683
	.byte 0

EverGrandeCity_GlaciasRoom_MapScript2_15B683:: @ 815B683
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_15B68D
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_15B68D:: @ 815B68D
	turnobject LOCALID_PLAYER, 2
	end

EverGrandeCity_GlaciasRoom_MapScript2_15B692:: @ 815B692
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_15B69C
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_15B69C:: @ 815B69C
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_MapScript1_15B6A9:: @ 815B6A9
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_15B6BE
	compare VAR_ELITE_4_STATE, 3
	call_if_eq EverGrandeCity_GlaciasRoom_EventScript_15B6C4
	end

EverGrandeCity_GlaciasRoom_EventScript_15B6BE:: @ 815B6BE
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_15B6C4:: @ 815B6C4
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_15B6CA:: @ 815B6CA
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_15B6F1
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_190AF9, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_190C01
	goto EverGrandeCity_GlaciasRoom_EventScript_15B6FB
	end

EverGrandeCity_GlaciasRoom_EventScript_15B6F1:: @ 815B6F1
	msgbox EverGrandeCity_GlaciasRoom_Text_190C8F, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_15B6FB:: @ 815B6FB
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_190C8F, MSGBOX_DEFAULT
	release
	end
