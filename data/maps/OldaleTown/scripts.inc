OldaleTown_MapScripts:: @ 814DD62
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_MapScript1_14DD68
	.byte 0

OldaleTown_MapScript1_14DD68:: @ 814DD68
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_14DD92
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_14DD9E
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_14DD8C
	end

OldaleTown_EventScript_14DD8C:: @ 814DD8C
	setvar VAR_ROUTE102_ACCESSIBLE, 1
	return

OldaleTown_EventScript_14DD92:: @ 814DD92
	setobjectxyperm 3, 1, 11
	setobjectmovementtype 3, 9
	return

OldaleTown_EventScript_14DD9E:: @ 814DD9E
	setobjectxyperm 2, 13, 14
	setobjectmovementtype 2, 8
	return

OldaleTown_EventScript_14DDAA:: @ 814DDAA
	msgbox OldaleTown_Text_16B20E, MSGBOX_SIGN
	end

OldaleTown_EventScript_14DDB3:: @ 814DDB3
	msgbox OldaleTown_Text_16AEC0, MSGBOX_NPC
	end

OldaleTown_EventScript_14DDBC:: @ 814DDBC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_14DE79
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_14DE79
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_16AEF2, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case 1, OldaleTown_EventScript_14DE07
	case 2, OldaleTown_EventScript_14DE1E
	case 4, OldaleTown_EventScript_14DE35
	end

OldaleTown_EventScript_14DE07:: @ 814DE07
	applymovement 2, OldaleTown_Movement_14DE97
	applymovement LOCALID_PLAYER, OldaleTown_Movement_14DEC1
	waitmovement 0
	goto OldaleTown_EventScript_14DE4C
	end

OldaleTown_EventScript_14DE1E:: @ 814DE1E
	applymovement 2, OldaleTown_Movement_14DEA2
	applymovement LOCALID_PLAYER, OldaleTown_Movement_14DECB
	waitmovement 0
	goto OldaleTown_EventScript_14DE4C
	end

OldaleTown_EventScript_14DE35:: @ 814DE35
	applymovement LOCALID_PLAYER, OldaleTown_Movement_14DEB9
	applymovement 2, OldaleTown_Movement_14DE8E
	waitmovement 0
	goto OldaleTown_EventScript_14DE4C
	end

OldaleTown_EventScript_14DE4C:: @ 814DE4C
	msgbox OldaleTown_Text_16AF2F, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_EventScript_14DE83
	msgbox OldaleTown_Text_16AFE1, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_14DE79:: @ 814DE79
	msgbox OldaleTown_Text_16AFE1, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_14DE83:: @ 814DE83
	msgbox Text_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_14DE8E:: @ 814DE8E
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_14DE97:: @ 814DE97
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_14DEA2:: @ 814DEA2
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

@ 814DEAB
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_14DEB9:: @ 814DEB9
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_14DEC1:: @ 814DEC1
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_14DECB:: @ 814DECB
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ 814DED3
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_14DEDF:: @ 814DEDF
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_14DF26
	msgbox OldaleTown_Text_16B0CC, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_14DEFF:: @ 814DEFF
	lockall
	applymovement LOCALID_PLAYER, OldaleTown_Movement_14DFEC
	applymovement 3, OldaleTown_Movement_14DFEF
	waitmovement 0
	msgbox OldaleTown_Text_16B045, MSGBOX_DEFAULT
	closemessage
	applymovement 3, OldaleTown_Movement_14DFF5
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_14DF26:: @ 814DF26
	msgbox OldaleTown_Text_16B12A, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_14DF30:: @ 814DF30
	lockall
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto OldaleTown_EventScript_14DF92
	end

OldaleTown_EventScript_14DF41:: @ 814DF41
	lockall
	applymovement 4, OldaleTown_Movement_14DFDE
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto OldaleTown_EventScript_14DF92
	end

OldaleTown_EventScript_14DF5C:: @ 814DF5C
	lockall
	applymovement 4, OldaleTown_Movement_14DFE1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto OldaleTown_EventScript_14DF92
	end

OldaleTown_EventScript_14DF77:: @ 814DF77
	lockall
	applymovement 4, OldaleTown_Movement_14DFE3
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto OldaleTown_EventScript_14DF92
	end

OldaleTown_EventScript_14DF92:: @ 814DF92
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_EventScript_14DFAA
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_EventScript_14DFB8
	end

OldaleTown_EventScript_14DFAA:: @ 814DFAA
	msgbox OldaleTown_Text_16B196, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_14DFC6
	end

OldaleTown_EventScript_14DFB8:: @ 814DFB8
	msgbox OldaleTown_Text_16B1BE, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_14DFC6
	end

OldaleTown_EventScript_14DFC6:: @ 814DFC6
	closemessage
	applymovement 4, OldaleTown_Movement_14DFE5
	waitmovement 0
	removeobject 4
	setvar VAR_OLDALE_STATE, 2
	setflag FLAG_HIDE_RIVAL_OLDALE_TOWN
	releaseall
	end

OldaleTown_Movement_14DFDE:: @ 814DFDE
	walk_left
	walk_left
	step_end

OldaleTown_Movement_14DFE1:: @ 814DFE1
	walk_left
	step_end

OldaleTown_Movement_14DFE3:: @ 814DFE3
	face_left
	step_end

OldaleTown_Movement_14DFE5:: @ 814DFE5
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_14DFEC:: @ 814DFEC
	delay_8
	walk_right
	step_end

OldaleTown_Movement_14DFEF:: @ 814DFEF
	walk_fast_up
	walk_in_place_fastest_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_14DFF5:: @ 814DFF5
	walk_down
	walk_left
	step_end
