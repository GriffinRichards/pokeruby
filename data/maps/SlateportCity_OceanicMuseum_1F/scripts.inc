SlateportCity_OceanicMuseum_1F_MapScripts:: @ 8155ACA
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OceanicMuseum_1F_MapScript1_155AD0
	.byte 0

SlateportCity_OceanicMuseum_1F_MapScript1_155AD0:: @ 8155AD0
	.ifdef SAPPHIRE
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_AQUA_MEMBER_F
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_AQUA_MEMBER_M
	.else
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAGMA_MEMBER_F
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MAGMA_MEMBER_M
	.endif
	end

SlateportCity_OceanicMuseum_1F_EventScript_155ADB:: @ 8155ADB
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E1DE, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155AE4:: @ 8155AE4
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_155B06
	end

SlateportCity_OceanicMuseum_1F_EventScript_155AF5:: @ 8155AF5
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_155B06
	end

SlateportCity_OceanicMuseum_1F_EventScript_155B06:: @ 8155B06
	showmoneybox 0, 0
	nop
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E18D, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_155B2D
	closemessage
	hidemoneybox 0, 0
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_155B8D
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_155B2D:: @ 8155B2D
	checkmoney 50, 0
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_155B5A
	removemoney 50, 0
	updatemoneybox 0, 0
	nop
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E1DE, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox 0, 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_155B5A:: @ 8155B5A
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_155B7B
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E1F5, MSGBOX_DEFAULT
	closemessage
	hidemoneybox 0, 0
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_155B8D
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_155B7B:: @ 8155B7B
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E22D, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox 0, 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_155B8D:: @ 8155B8D
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_155B8F:: @ 8155B8F
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E2BB, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155B98:: @ 8155B98
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E2E3, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BA1:: @ 8155BA1
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E338, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BAA:: @ 8155BAA
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E36F, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BB3:: @ 8155BB3
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E3A9, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BBC:: @ 8155BBC
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E3ED, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BC5:: @ 8155BC5
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E6C9, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BCE:: @ 8155BCE
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E741, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BD7:: @ 8155BD7
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E7C4, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BE0:: @ 8155BE0
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E892, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BE9:: @ 8155BE9
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E944, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BF2:: @ 8155BF2
	msgbox SlateportCity_OceanicMuseum_1F_Text_17EA19, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155BFB:: @ 8155BFB
	msgbox SlateportCity_OceanicMuseum_1F_Text_17EB0D, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C04:: @ 8155C04
	msgbox SlateportCity_OceanicMuseum_1F_Text_17EBBC, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C0D:: @ 8155C0D
	msgbox SlateportCity_OceanicMuseum_1F_Text_17EC98, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C16:: @ 8155C16
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E434, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C1F:: @ 8155C1F
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E477, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C28:: @ 8155C28
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E4D7, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C31:: @ 8155C31
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E540, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C3A:: @ 8155C3A
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement 13, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 13, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E582, MSGBOX_DEFAULT
	giveitem ITEM_TM46_THIEF
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_155CC2
	setflag FLAG_RECEIVED_TM46
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E606, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_155C98
	compare VAR_FACING, 2
	goto_if_ne SlateportCity_OceanicMuseum_1F_EventScript_155CAD
	end

SlateportCity_OceanicMuseum_1F_EventScript_155C98:: @ 8155C98
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_155CD3
	waitmovement 0
	setflag FLAG_HIDE_SCARED_GRUNT_OCEANIC_MUSEUM
	playse SE_EXIT
	removeobject 13
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_155CAD:: @ 8155CAD
	applymovement 13, SlateportCity_OceanicMuseum_1F_Movement_155CCC
	waitmovement 0
	setflag FLAG_HIDE_SCARED_GRUNT_OCEANIC_MUSEUM
	playse SE_EXIT
	removeobject 13
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_155CC2:: @ 8155CC2
	msgbox SlateportCity_OceanicMuseum_1F_Text_17E695, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_155CCC:: @ 8155CCC
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_155CD3:: @ 8155CD3
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end
