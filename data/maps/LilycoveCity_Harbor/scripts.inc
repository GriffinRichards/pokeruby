LilycoveCity_Harbor_MapScripts:: @ 8159893
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_MapScript1_159899
	.byte 0

LilycoveCity_Harbor_MapScript1_159899:: @ 8159899
	setescapewarp MAP_LILYCOVE_CITY, 255, 12, 33
	end

LilycoveCity_Harbor_EventScript_1598A2:: @ 81598A2
	lock
	faceplayer
	checkitem ITEM_EON_TICKET, 1
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_Harbor_EventScript_1599EE
	goto LilycoveCity_Harbor_EventScript_1598BA
	end

LilycoveCity_Harbor_EventScript_1598BA:: @ 81598BA
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_1598CD
	msgbox LilycoveCity_Harbor_Text_18B306, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_1598CD:: @ 81598CD
	msgbox LilycoveCity_Harbor_Text_18B36F, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_Harbor_EventScript_159929
	message LilycoveCity_Harbor_Text_18B406
	waitmessage
	goto LilycoveCity_Harbor_EventScript_1598F1
	end

LilycoveCity_Harbor_EventScript_1598F1:: @ 81598F1
	multichoicedefault 18, 6, 56, 2, 0
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_159933
	case 1, LilycoveCity_Harbor_EventScript_15995B
	case 2, LilycoveCity_Harbor_EventScript_1599E4
	case 127, LilycoveCity_Harbor_EventScript_1599E4
	end

LilycoveCity_Harbor_EventScript_159929:: @ 8159929
	msgbox LilycoveCity_Harbor_Text_18B3A9, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_159933:: @ 8159933
	msgbox LilycoveCity_Harbor_Text_18B47D, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_15997E
	setvar VAR_PORTHOLE_STATE, 5
	call LilycoveCity_Harbor_EventScript_15998A
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_15995B:: @ 815995B
	msgbox LilycoveCity_Harbor_Text_18B499, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Harbor_EventScript_15997E
	call LilycoveCity_Harbor_EventScript_15998A
	warp MAP_BATTLE_TOWER_OUTSIDE, 255, 19, 23
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_15997E:: @ 815997E
	message LilycoveCity_Harbor_Text_18B4E2
	waitmessage
	goto LilycoveCity_Harbor_EventScript_1598F1
	end

LilycoveCity_Harbor_EventScript_15998A:: @ 815998A
	msgbox LilycoveCity_Harbor_Text_18B4B3, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_1599D9
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_1599CE
	delay 30
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
	setvar VAR_0x8004, 2
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_1599CE:: @ 81599CE
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_159A86
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_1599D9:: @ 81599D9
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_159A89
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_1599E4:: @ 81599E4
	msgbox LilycoveCity_Harbor_Text_18B45B, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_1599EE:: @ 81599EE
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_1598BA
	goto_if_set FLAG_ENCOUNTERED_LATIAS_OR_LATIOS, LilycoveCity_Harbor_EventScript_1598BA
	goto_if_unset FLAG_SYS_HAS_EON_TICKET, LilycoveCity_Harbor_EventScript_1598BA
	msgbox LilycoveCity_Harbor_Text_1C50F2, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	delay 60
	addobject 4
	delay 30
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Harbor_Text_1C5120, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 30
	removeobject 4
	compare VAR_FACING, 2
	call_if_eq LilycoveCity_Harbor_EventScript_1599D9
	compare VAR_FACING, 4
	call_if_eq LilycoveCity_Harbor_EventScript_1599CE
	delay 30
	hideobjectat LOCALID_PLAYER, MAP_PETALBURG_CITY
	special ScrSpecial_HealPlayerParty
	setvar VAR_0x8004, 2
	call Common_EventScript_FerryDepart
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_Movement_159A86:: @ 8159A86
	walk_right
	walk_in_place_fastest_up
	step_end

LilycoveCity_Harbor_Movement_159A89:: @ 8159A89
	walk_up
	step_end

@ 8159A8B
	walk_up
	step_end

LilycoveCity_Harbor_EventScript_159A8D:: @ 8159A8D
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_159AA2
	msgbox LilycoveCity_Harbor_Text_18B504, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_159AA2:: @ 8159AA2
	msgbox LilycoveCity_Harbor_Text_18B58E, MSGBOX_DEFAULT
	release
	end
