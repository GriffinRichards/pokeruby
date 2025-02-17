EverGrandeCity_HallOfFame_MapScripts:: @ 815BB84
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_HallOfFame_MapScript2_15BB9E
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_HallOfFame_MapScript2_15BB8F
	.byte 0

EverGrandeCity_HallOfFame_MapScript2_15BB8F:: @ 815BB8F
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_15BB99
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_15BB99:: @ 815BB99
	turnobject LOCALID_PLAYER, 2
	end

EverGrandeCity_HallOfFame_MapScript2_15BB9E:: @ 815BB9E
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_HallOfFame_EventScript_15BBA8
	.2byte 0

EverGrandeCity_HallOfFame_EventScript_15BBA8:: @ 815BBA8
	lockall
	applymovement 1, EverGrandeCity_HallOfFame_Movement_15BC59
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_15BC59
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_191841, MSGBOX_DEFAULT
	closemessage
	applymovement 1, EverGrandeCity_HallOfFame_Movement_15BC60
	applymovement LOCALID_PLAYER, EverGrandeCity_HallOfFame_Movement_15BC60
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_1918D7, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFastestUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	setvar VAR_TEMP_1, 1
	call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_15BC41
	compare VAR_RESULT, 1
	goto_if_eq EverGrandeCity_HallOfFame_EventScript_15BC4D
	end

EverGrandeCity_HallOfFame_EventScript_15BC41:: @ 815BC41
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	fadescreenspeed 1, 24
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_EventScript_15BC4D:: @ 815BC4D
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	fadescreenspeed 1, 24
	special GameClear
	waitstate
	releaseall
	end

EverGrandeCity_HallOfFame_Movement_15BC59:: @ 815BC59
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_HallOfFame_Movement_15BC60:: @ 815BC60
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
