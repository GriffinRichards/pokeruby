SootopolisCity_MapScripts:: @ 814D07D
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_MapScript1_14D08D
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MapScript1_14D10D
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_MapScript1_14D165
	.byte 0

SootopolisCity_MapScript1_14D08D:: @ 814D08D
	call_if_unset FLAG_LEGEND_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_14D0A0
	call_if_set FLAG_LEGEND_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_14D0B1
	end

SootopolisCity_EventScript_14D0A0:: @ 814D0A0
	setobjectxyperm 3, 31, 18
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, 1
	return

SootopolisCity_EventScript_14D0B1:: @ 814D0B1
	call_if_unset FLAG_LEGENDARY_BATTLE_COMPLETED, SootopolisCity_EventScript_14D0BB
	return

SootopolisCity_EventScript_14D0BB:: @ 814D0BB
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, 1
	return

SootopolisCity_MapScript1_14D10D:: @ 814D10D
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	call_if_set FLAG_LEGENDARY_BATTLE_COMPLETED, SootopolisCity_EventScript_14D159
	call_if_set FLAG_SYS_WEATHER_CTRL, SootopolisCity_EventScript_14D123
	end

SootopolisCity_EventScript_14D123:: @ 814D123
	call Common_EventScript_SetLegendaryWeather
	setobjectxyperm 1, 29, 19
	setobjectxyperm 2, 33, 19
	compare VAR_SOOTOPOLIS_STATE, 1
	call_if_eq SootopolisCity_EventScript_14D142
	return

SootopolisCity_EventScript_14D142:: @ 814D142
	setobjectxyperm 10, 29, 6
	setobjectmovementtype 10, 10
	setobjectxyperm 5, 30, 6
	setobjectmovementtype 5, 9
	return

SootopolisCity_EventScript_14D159:: @ 814D159
	setobjectxyperm 10, 31, 33
	setobjectmovementtype 10, 8
	return

SootopolisCity_MapScript1_14D165:: @ 814D165
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
	end

SootopolisCity_EventScript_14D16E:: @ 814D16E
	lock
	faceplayer
	goto_if_set FLAG_LEGENDARY_BATTLE_COMPLETED, SootopolisCity_EventScript_14D183
	msgbox SootopolisCity_Text_1696A4, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D183:: @ 814D183
	msgbox SootopolisCity_Text_16A455, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D18D:: @ 814D18D
	msgbox SootopolisCity_Text_16A2B2, MSGBOX_NPC
	end

SootopolisCity_EventScript_14D196:: @ 814D196
	msgbox SootopolisCity_Text_16A2FB, MSGBOX_NPC
	end

SootopolisCity_EventScript_14D19F:: @ 814D19F
	lock
	faceplayer
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_RECEIVED_BERRY_SOOTOPOLIS, SootopolisCity_EventScript_14D241
	msgbox SootopolisCity_Text_1C63F2, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, ITEM_CHERI_BERRY
	giveitem VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_RECEIVED_BERRY_SOOTOPOLIS
	msgbox SootopolisCity_Text_1C64D0, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_EventScript_14D1FF
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_14D220
	end

SootopolisCity_EventScript_14D1FF:: @ 814D1FF
	giveitem ITEM_FIGY_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_1C650B, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D220:: @ 814D220
	giveitem ITEM_IAPAPA_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_1C650B, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D241:: @ 814D241
	msgbox SootopolisCity_Text_1C6540, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SootopolisCity_EventScript_14D25E
	msgbox SootopolisCity_Text_1C6626, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D25E:: @ 814D25E
	msgbox SootopolisCity_Text_1C65D4, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D268:: @ 814D268
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_EventScript_14D27D
	msgbox SootopolisCity_Text_16A4D6, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D27D:: @ 814D27D
	msgbox SootopolisCity_Text_16A531, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D287:: @ 814D287
	lock
	faceplayer
	goto_if_set FLAG_LEGENDARY_BATTLE_COMPLETED, SootopolisCity_EventScript_14D29C
	msgbox SootopolisCity_Text_169813, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D29C:: @ 814D29C
	msgbox SootopolisCity_Text_16A587, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D2A6:: @ 814D2A6
	lock
	faceplayer
	goto_if_set FLAG_LEGENDARY_BATTLE_COMPLETED, SootopolisCity_EventScript_14D2BB
	msgbox SootopolisCity_Text_1698A0, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D2BB:: @ 814D2BB
	msgbox SootopolisCity_Text_16A614, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D2C5:: @ 814D2C5
	lock
	faceplayer
	goto_if_set FLAG_LEGENDARY_BATTLE_COMPLETED, SootopolisCity_EventScript_14D2DA
	msgbox SootopolisCity_Text_1697A7, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D2DA:: @ 814D2DA
	msgbox SootopolisCity_Text_16A6AE, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_14D2E4:: @ 814D2E4
	msgbox SootopolisCity_Text_16972B, MSGBOX_NPC
	end

SootopolisCity_EventScript_14D2ED:: @ 814D2ED
	msgbox SootopolisCity_Text_16A6C7, MSGBOX_SIGN
	end

SootopolisCity_EventScript_14D2F6:: @ 814D2F6
	msgbox SootopolisCity_Text_16A711, MSGBOX_SIGN
	end

ClosedSootopolisDoorScript:: @ 814D2FF
	msgbox ClosedSootopolisDoorText, MSGBOX_SIGN
	end

SootopolisCity_EventScript_14D308:: @ 814D308
	lockall
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	playse SE_PIN
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 10, Common_Movement_Delay48
	waitmovement 0
	applymovement 10, SootopolisCity_Movement_14D413
	waitmovement 0
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_169988, MSGBOX_DEFAULT
	.else
	msgbox SootopolisCity_Text_169E0F, MSGBOX_DEFAULT
	.endif
	closemessage
	applymovement 10, SootopolisCity_Movement_14D417
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_14D440
	waitmovement 10
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_1699FD, MSGBOX_DEFAULT
	.else
	msgbox SootopolisCity_Text_169E82, MSGBOX_DEFAULT
	.endif
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_169AB7, MSGBOX_DEFAULT
	.else
	msgbox SootopolisCity_Text_169F3C, MSGBOX_DEFAULT
	.endif
	closemessage
	delay 30
	applymovement 5, SootopolisCity_Movement_14D46A
	applymovement 10, SootopolisCity_Movement_14D41D
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_14D445
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFastestRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	applymovement 10, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_169AE7, MSGBOX_DEFAULT
	.else
	msgbox SootopolisCity_Text_169F6B, MSGBOX_DEFAULT
	.endif
	closemessage
	delay 30
	applymovement 5, SootopolisCity_Movement_14D47C
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_14D457
	applymovement 10, SootopolisCity_Movement_14D42D
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_169BC7, MSGBOX_DEFAULT
	.else
	msgbox SootopolisCity_Text_16A06C, MSGBOX_DEFAULT
	.endif
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_169C99, MSGBOX_DEFAULT
	.else
	msgbox SootopolisCity_Text_16A13E, MSGBOX_DEFAULT
	.endif
	moveobjectoffscreen 5
	setobjectmovementtype 5, 9
	moveobjectoffscreen 10
	setobjectmovementtype 10, 10
	setvar VAR_SOOTOPOLIS_STATE, 2
	releaseall
	end

SootopolisCity_Movement_14D413:: @ 814D413
	walk_left
	walk_left
	walk_left
	step_end

SootopolisCity_Movement_14D417:: @ 814D417
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_fastest_down
	step_end

SootopolisCity_Movement_14D41D:: @ 814D41D
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

SootopolisCity_Movement_14D42D:: @ 814D42D
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_14D440:: @ 814D440
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_14D445:: @ 814D445
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SootopolisCity_Movement_14D457:: @ 814D457
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_14D46A:: @ 814D46A
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SootopolisCity_Movement_14D47C:: @ 814D47C
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_EventScript_14D48F:: @ 814D48F
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_169D37, MSGBOX_NPC
	.else
	msgbox SootopolisCity_Text_16A1DB, MSGBOX_NPC
	.endif
	end

SootopolisCity_EventScript_14D498:: @ 814D498
	lock
	faceplayer
	goto_if_set FLAG_LEGENDARY_BATTLE_COMPLETED, SootopolisCity_EventScript_14D4AD
	.ifdef SAPPHIRE
	msgbox SootopolisCity_Text_169DA6, MSGBOX_DEFAULT
	.else
	msgbox SootopolisCity_Text_16A249, MSGBOX_DEFAULT
	.endif
	release
	end

SootopolisCity_EventScript_14D4AD:: @ 814D4AD
	msgbox SootopolisCity_Text_16A33E, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	release
	end
