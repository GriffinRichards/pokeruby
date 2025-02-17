DewfordTown_Hall_MapScripts:: @ 8153292
	.byte 0

DewfordTown_Hall_EventScript_153293:: @ 8153293
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special TrendyPhraseIsOld
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Hall_EventScript_1532B2
	msgbox DewfordTown_Hall_Text_1754C9, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1532B2:: @ 81532B2
	msgbox DewfordTown_Hall_Text_175528, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1532BC:: @ 81532BC
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_17559E, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_1532CD:: @ 81532CD
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferRandomHobbyOrLifestyleString
	msgbox DewfordTown_Hall_Text_1755F9, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DewfordTown_Hall_EventScript_1532F6
	compare VAR_RESULT, NO
	goto_if_eq DewfordTown_Hall_EventScript_153300
	end

DewfordTown_Hall_EventScript_1532F6:: @ 81532F6
	msgbox DewfordTown_Hall_Text_175664, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_153300:: @ 8153300
	msgbox DewfordTown_Hall_Text_1756B7, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_15330A:: @ 815330A
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_17570D, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_153326:: @ 8153326
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_17574C, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_153342:: @ 8153342
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_175779, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_153353:: @ 8153353
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_175842, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_153363:: @ 8153363
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_1533CA
	case 4, DewfordTown_Hall_EventScript_1533CA
	case 1, DewfordTown_Hall_EventScript_1533D4
	case 5, DewfordTown_Hall_EventScript_1533CA
	case 2, DewfordTown_Hall_EventScript_1533DE
	case 6, DewfordTown_Hall_EventScript_1533DE
	case 3, DewfordTown_Hall_EventScript_1533E8
	case 7, DewfordTown_Hall_EventScript_1533DE
	end

DewfordTown_Hall_EventScript_1533CA:: @ 81533CA
	msgbox DewfordTown_Hall_Text_1758C4, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1533D4:: @ 81533D4
	msgbox DewfordTown_Hall_Text_1758E0, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1533DE:: @ 81533DE
	msgbox DewfordTown_Hall_Text_1758FB, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1533E8:: @ 81533E8
	msgbox DewfordTown_Hall_Text_175916, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1533F2:: @ 81533F2
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_15340A
	end

DewfordTown_Hall_EventScript_1533FE:: @ 81533FE
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_15340A
	end

DewfordTown_Hall_EventScript_15340A:: @ 815340A
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_153470
	case 1, DewfordTown_Hall_EventScript_153470
	case 2, DewfordTown_Hall_EventScript_15348C
	case 3, DewfordTown_Hall_EventScript_15348C
	case 4, DewfordTown_Hall_EventScript_1534A8
	case 5, DewfordTown_Hall_EventScript_1534A8
	case 6, DewfordTown_Hall_EventScript_1534C4
	case 7, DewfordTown_Hall_EventScript_1534E0
	end

DewfordTown_Hall_EventScript_153470:: @ 8153470
	call DewfordTown_Hall_EventScript_1534FD
	msgbox DewfordTown_Hall_Text_175935, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_153535
	msgbox DewfordTown_Hall_Text_1759A1, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_15348C:: @ 815348C
	call DewfordTown_Hall_EventScript_1534FD
	msgbox DewfordTown_Hall_Text_175A5C, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_153535
	msgbox DewfordTown_Hall_Text_175AD9, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1534A8:: @ 81534A8
	call DewfordTown_Hall_EventScript_1534FD
	msgbox DewfordTown_Hall_Text_175B46, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_153535
	msgbox DewfordTown_Hall_Text_175BA7, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1534C4:: @ 81534C4
	call DewfordTown_Hall_EventScript_1534FD
	msgbox DewfordTown_Hall_Text_175C41, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_153535
	msgbox DewfordTown_Hall_Text_175CC2, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1534E0:: @ 81534E0
	call DewfordTown_Hall_EventScript_1534FD
	msgbox DewfordTown_Hall_Text_175D6B, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_153535
	msgbox DewfordTown_Hall_Text_175DC3, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_1534FC:: @ 81534FC
	return

DewfordTown_Hall_EventScript_1534FD:: @ 81534FD
	applymovement 8, DewfordTown_Hall_Movement_153599
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_15351E
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_153534
	end

DewfordTown_Hall_EventScript_15351E:: @ 815351E
	compare VAR_FACING, 4
	goto_if_eq DewfordTown_Hall_EventScript_1534FC
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_153534:: @ 8153534
	return

DewfordTown_Hall_EventScript_153535:: @ 8153535
	applymovement 7, DewfordTown_Hall_Movement_15359B
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq DewfordTown_Hall_EventScript_153556
	compare VAR_0x8008, 1
	goto_if_eq DewfordTown_Hall_EventScript_153583
	end

DewfordTown_Hall_EventScript_153556:: @ 8153556
	compare VAR_FACING, 2
	call_if_eq DewfordTown_Hall_EventScript_15356D
	compare VAR_FACING, 1
	call_if_eq DewfordTown_Hall_EventScript_153578
	return

DewfordTown_Hall_EventScript_15356D:: @ 815356D
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_153578:: @ 8153578
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_153583:: @ 8153583
	compare VAR_FACING, 3
	goto_if_eq DewfordTown_Hall_EventScript_1534FC
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_153599:: @ 8153599
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_15359B:: @ 815359B
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_15359D:: @ 815359D
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM36, DewfordTown_Hall_EventScript_1535D1
	msgbox DewfordTown_Hall_Text_175E13, MSGBOX_DEFAULT
	giveitem ITEM_TM36_SLUDGE_BOMB
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM36
	release
	end

DewfordTown_Hall_EventScript_1535D1:: @ 81535D1
	msgbox DewfordTown_Hall_Text_175EBE, MSGBOX_DEFAULT
	release
	end
