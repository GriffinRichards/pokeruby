LilycoveCity_LilycoveMuseum_1F_MapScripts:: @ 815841B
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_15841C:: @ 815841C
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187348, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158425:: @ 8158425
	lockall
	applymovement 2, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_1873B9
	waitmessage
	multichoice 20, 8, 16, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_158458
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_15844F
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_15844F:: @ 815844F
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187459, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158458:: @ 8158458
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187495, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_158477
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_158481
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158477:: @ 8158477
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1874F5, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158481:: @ 8158481
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187534, MSGBOX_SIGN
	applymovement 2, LilycoveCity_LilycoveMuseum_1F_Movement_1584FC
	waitmovement 0
	removeobject 2
	switch VAR_FACING
	case 2, LilycoveCity_LilycoveMuseum_1F_EventScript_1584BD
	case 3, LilycoveCity_LilycoveMuseum_1F_EventScript_1584D2
	case 4, LilycoveCity_LilycoveMuseum_1F_EventScript_1584E7
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_1584BD:: @ 81584BD
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_158504
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_1584D2:: @ 81584D2
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_1584FE
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_1584E7:: @ 81584E7
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_158501
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_1584FC:: @ 81584FC
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_1584FE:: @ 81584FE
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_158501:: @ 8158501
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_158504:: @ 8158504
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_158507:: @ 8158507
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_18757F, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158510:: @ 8158510
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1875BE, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158519:: @ 8158519
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1875F8, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158522:: @ 8158522
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187641, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_15852B:: @ 815852B
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1876A1, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158534:: @ 8158534
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_18770C, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_15853D:: @ 815853D
LilycoveCity_LilycoveMuseum_2F_EventScript_15853D:: @ 815853D
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_18775F, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158546:: @ 8158546
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1877A9, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_15854F:: @ 815854F
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187810, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158558:: @ 8158558
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1878B7, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158561:: @ 8158561
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_18791D, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_15856A:: @ 815856A
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1879BF, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158573:: @ 8158573
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_1879E6, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_15857C:: @ 815857C
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187A1A, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_158585:: @ 8158585
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187AA0, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_15858E:: @ 815858E
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187B04, MSGBOX_NPC
	lockall
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_1585A3:: @ 81585A3
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_187B7F, MSGBOX_NPC
	end
