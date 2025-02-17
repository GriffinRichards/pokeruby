SlateportCity_Harbor_MapScripts:: @ 8155F5D
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_MapScript1_155F63
	.byte 0

SlateportCity_Harbor_MapScript1_155F63:: @ 8155F63
	setescapewarp MAP_SLATEPORT_CITY, 255, 28, 13
	setvar VAR_TEMP_1, 0
	compare VAR_SLATEPORT_HARBOR_STATE, 1
	call_if_eq SlateportCity_Harbor_EventScript_155F89
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_155F85
	end

SlateportCity_Harbor_EventScript_155F85:: @ 8155F85
	clearflag FLAG_HIDE_SS_TIDAL_SLATEPORT_HARBOR
	return

SlateportCity_Harbor_EventScript_155F89:: @ 8155F89
	savebgm MUS_EVIL_TEAM
	setobjectxyperm 4, 12, 13
	setobjectmovementtype 4, 9
	setflag FLAG_HIDE_WORKERS_SLATEPORT_HARBOR
	return

SlateportCity_Harbor_EventScript_155F9B:: @ 8155F9B
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_155FD5
	end

SlateportCity_Harbor_EventScript_155FA7:: @ 8155FA7
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_155FD5
	end

SlateportCity_Harbor_EventScript_155FB3:: @ 8155FB3
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_155FD5
	end

SlateportCity_Harbor_EventScript_155FBF:: @ 8155FBF
	lockall
	setvar VAR_0x8008, 3
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_1560C2
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_155FD5
	end

SlateportCity_Harbor_EventScript_155FD5:: @ 8155FD5
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_17FD7D, MSGBOX_DEFAULT
	closemessage
	applymovement 6, SlateportCity_Harbor_Movement_15609B
	applymovement 7, SlateportCity_Harbor_Movement_15609B
	applymovement 8, SlateportCity_Harbor_Movement_1560A5
	waitmovement 0
	removeobject 6
	removeobject 7
	removeobject 8
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	compare VAR_0x8008, 0
	call_if_eq SlateportCity_Harbor_EventScript_15605C
	compare VAR_0x8008, 1
	call_if_eq SlateportCity_Harbor_EventScript_156071
	compare VAR_0x8008, 2
	call_if_eq SlateportCity_Harbor_EventScript_156086
	compare VAR_0x8008, 3
	call_if_eq SlateportCity_Harbor_EventScript_156086
	msgbox SlateportCity_Harbor_Text_17FE60, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_GRUNT_1_BLOCKING_HIDEOUT
	setflag FLAG_HIDE_GRUNT_2_BLOCKING_HIDEOUT
	moveobjectoffscreen 4
	setobjectmovementtype 4, 10
	releaseall
	end

SlateportCity_Harbor_EventScript_15605C:: @ 815605C
	applymovement 4, SlateportCity_Harbor_Movement_1560B3
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_156071:: @ 8156071
	applymovement 4, SlateportCity_Harbor_Movement_1560B9
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_156086:: @ 8156086
	applymovement 4, SlateportCity_Harbor_Movement_1560BE
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_15609B:: @ 815609B
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ 81560A0
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_1560A5:: @ 81560A5
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_1560B3:: @ 81560B3
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_1560B9:: @ 81560B9
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_1560BE:: @ 81560BE
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_1560C2:: @ 81560C2
	walk_up
	step_end

SlateportCity_Harbor_EventScript_1560C4:: @ 81560C4
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_1560D9
	msgbox SlateportCity_Harbor_Text_17FA0A, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_1560D9:: @ 81560D9
	msgbox SlateportCity_Harbor_Text_17FA73, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Harbor_EventScript_156135
	message SlateportCity_Harbor_Text_17FB0A
	waitmessage
	goto SlateportCity_Harbor_EventScript_1560FD
	end

SlateportCity_Harbor_EventScript_1560FD:: @ 81560FD
	multichoicedefault 18, 6, 52, 2, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_15613F
	case 1, SlateportCity_Harbor_EventScript_156167
	case 2, SlateportCity_Harbor_EventScript_1561DA
	case 127, SlateportCity_Harbor_EventScript_1561DA
	end

SlateportCity_Harbor_EventScript_156135:: @ 8156135
	msgbox SlateportCity_Harbor_Text_17FAAD, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_15613F:: @ 815613F
	msgbox SlateportCity_Harbor_Text_17FB81, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_15618A
	setvar VAR_PORTHOLE_STATE, 1
	call SlateportCity_Harbor_EventScript_156196
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_156167:: @ 8156167
	msgbox SlateportCity_Harbor_Text_17FB9C, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_15618A
	call SlateportCity_Harbor_EventScript_156196
	warp MAP_BATTLE_TOWER_OUTSIDE, 255, 19, 23
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_15618A:: @ 815618A
	message SlateportCity_Harbor_Text_17FBE5
	waitmessage
	goto SlateportCity_Harbor_EventScript_1560FD
	end

SlateportCity_Harbor_EventScript_156196:: @ 8156196
	msgbox SlateportCity_Harbor_Text_17FBB6, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	compare VAR_FACING, 2
	call_if_eq SlateportCity_Harbor_EventScript_1561EF
	compare VAR_FACING, 4
	call_if_eq SlateportCity_Harbor_EventScript_1561E4
	delay 30
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
	setvar VAR_0x8004, 5
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_1561DA:: @ 81561DA
	msgbox SlateportCity_Harbor_Text_17FB5F, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_1561E4:: @ 81561E4
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_1561FA
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_1561EF:: @ 81561EF
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_1561FD
	waitmovement 0
	return

SlateportCity_Harbor_Movement_1561FA:: @ 81561FA
	walk_right
	walk_in_place_fastest_up
	step_end

SlateportCity_Harbor_Movement_1561FD:: @ 81561FD
	walk_up
	step_end

SlateportCity_Harbor_EventScript_1561FF:: @ 81561FF
	msgbox SlateportCity_Harbor_Text_17FC07, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_156208:: @ 8156208
	msgbox SlateportCity_Harbor_Text_17FC7C, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_156211:: @ 8156211
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_15626F
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_156265
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_156258
	compare VAR_SLATEPORT_HARBOR_STATE, 2
	goto_if_eq SlateportCity_Harbor_EventScript_15624E
	msgbox SlateportCity_Harbor_Text_17FD1C, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_15624E:: @ 815624E
	msgbox SlateportCity_Harbor_Text_17FE60, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_156258:: @ 8156258
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_17FF35, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_156265:: @ 8156265
	msgbox SlateportCity_Harbor_Text_1800A0, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_15626F:: @ 815626F
	compare VAR_TEMP_1, 1
	goto_if_eq SlateportCity_Harbor_EventScript_156380
	checkitem ITEM_SCANNER, 1
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_Harbor_EventScript_1562A7
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_15629D
	msgbox SlateportCity_Harbor_Text_18017B, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_15629D:: @ 815629D
	msgbox SlateportCity_Harbor_Text_1801EA, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_1562A7:: @ 81562A7
	message SlateportCity_Harbor_Text_18028B
	waitmessage
	goto SlateportCity_Harbor_EventScript_1562B3
	end

SlateportCity_Harbor_EventScript_1562B3:: @ 81562B3
	multichoice 0, 0, 46, 0
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_1562EA
	case 1, SlateportCity_Harbor_EventScript_15632A
	case 2, SlateportCity_Harbor_EventScript_15636A
	case 127, SlateportCity_Harbor_EventScript_15636A
	end

SlateportCity_Harbor_EventScript_1562EA:: @ 81562EA
	msgbox SlateportCity_Harbor_Text_1803DD, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_156374
	giveitem ITEM_DEEP_SEA_TOOTH
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_18046B, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_156380
	end

SlateportCity_Harbor_EventScript_15632A:: @ 815632A
	msgbox SlateportCity_Harbor_Text_180412, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SlateportCity_Harbor_EventScript_156374
	giveitem ITEM_DEEP_SEA_SCALE
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_18046B, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_156380
	end

SlateportCity_Harbor_EventScript_15636A:: @ 815636A
	msgbox SlateportCity_Harbor_Text_180360, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_156374:: @ 8156374
	message SlateportCity_Harbor_Text_180447
	waitmessage
	goto SlateportCity_Harbor_EventScript_1562B3
	end

SlateportCity_Harbor_EventScript_156380:: @ 8156380
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_180491, MSGBOX_DEFAULT
	release
	end
