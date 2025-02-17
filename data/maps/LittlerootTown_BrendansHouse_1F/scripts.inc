LittlerootTown_BrendansHouse_1F_MapScripts:: @ 815263B
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_MapScript1_15264B
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_MapScript1_15268A
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_MapScript2_1526D0
	.byte 0

LittlerootTown_BrendansHouse_1F_MapScript1_15264B:: @ 815264B
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_BrendansHouse_1F_EventScript_152660
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_152673
	end

LittlerootTown_BrendansHouse_1F_EventScript_152660:: @ 8152660
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_152673:: @ 8152673
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_152680
	return

LittlerootTown_BrendansHouse_1F_EventScript_152680:: @ 8152680
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
	return

LittlerootTown_BrendansHouse_1F_MapScript1_15268A:: @ 815268A
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_1526C4
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_1526AC
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_1526B8
	end

LittlerootTown_BrendansHouse_1F_EventScript_1526AC:: @ 81526AC
	setobjectxyperm 1, 8, 4
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_1F_EventScript_1526B8:: @ 81526B8
	setobjectxyperm 1, 4, 5
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_1F_EventScript_1526C4:: @ 81526C4
	setobjectxyperm 1, 9, 8
	setobjectmovementtype 1, 7
	return

LittlerootTown_BrendansHouse_1F_MapScript2_1526D0:: @ 81526D0
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_152722
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_1526FA
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_152733
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 1, LittlerootTown_BrendansHouse_1F_EventScript_152744
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_1B6CDE
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_1526FA:: @ 81526FA
	lockall
	msgbox LittlerootTown_BrendansHouse_1F_Text_172574, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_152720
	applymovement 1, LittlerootTown_BrendansHouse_1F_Movement_152720
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_152720:: @ 8152720
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_152722:: @ 8152722
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_1B6956
	end

LittlerootTown_BrendansHouse_1F_EventScript_152733:: @ 8152733
	lockall
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_1B6ABF
	end

LittlerootTown_BrendansHouse_1F_EventScript_152744:: @ 8152744
	lockall
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_152782
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox LittlerootTown_BrendansHouse_1F_Text_1730C2, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_152782:: @ 8152782
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_152789:: @ 8152789
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_1B69B7
	end
