VictoryRoad_1F_MapScripts:: @ 815DE83
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_MapScript1_15DE89
	.byte 0

VictoryRoad_1F_MapScript1_15DE89:: @ 815DE89
	call_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VictoryRoad_1F_EventScript_15DE93
	end

VictoryRoad_1F_EventScript_15DE93:: @ 815DE93
	setflag FLAG_HIDE_WALLY_BATTLE_VICTORY_ROAD
	return

VictoryRoad_1F_EventScript_15DE97:: @ 815DE97
	lockall
	addobject 4
	applymovement 4, VictoryRoad_1F_Movement_15DF07
	waitmovement 0
	goto VictoryRoad_1F_EventScript_15DED3
	end

VictoryRoad_1F_EventScript_15DEAB:: @ 815DEAB
	lockall
	addobject 4
	applymovement 4, VictoryRoad_1F_Movement_15DF13
	waitmovement 0
	goto VictoryRoad_1F_EventScript_15DED3
	end

VictoryRoad_1F_EventScript_15DEBF:: @ 815DEBF
	lockall
	addobject 4
	applymovement 4, VictoryRoad_1F_Movement_15DF1E
	waitmovement 0
	goto VictoryRoad_1F_EventScript_15DED3
	end

VictoryRoad_1F_EventScript_15DED3:: @ 815DED3
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox VictoryRoad_1F_Text_19782B, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_1, VictoryRoad_1F_Text_197943
	msgbox VictoryRoad_1F_Text_197967, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_WALLY_BATTLE_VICTORY_ROAD
	moveobjectoffscreen 4
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	setvar VAR_VICTORY_ROAD_1F_STATE, 1
	releaseall
	end

VictoryRoad_1F_Movement_15DF07:: @ 815DF07
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

VictoryRoad_1F_Movement_15DF13:: @ 815DF13
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

VictoryRoad_1F_Movement_15DF1E:: @ 815DF1E
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

VictoryRoad_1F_EventScript_15DF28:: @ 815DF28
	msgbox VictoryRoad_1F_Text_197967, MSGBOX_NPC
	end

VictoryRoad_1F_EventScript_15DF31:: @ 815DF31
	trainerbattle_single TRAINER_WALLY_3, VictoryRoad_1F_Text_1979BA, VictoryRoad_1F_Text_197A23
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_1F_EventScript_15DF58
	msgbox VictoryRoad_1F_Text_197A47, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_15DF58:: @ 815DF58
	trainerbattle_rematch TRAINER_WALLY_3, VictoryRoad_1F_Text_1979BA, VictoryRoad_1F_Text_197A23
	msgbox VictoryRoad_1F_Text_197A47, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_15DF6F:: @ 815DF6F
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_197AD1, VictoryRoad_1F_Text_197B1A
	msgbox VictoryRoad_1F_Text_197B36, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_15DF86:: @ 815DF86
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_197B99, VictoryRoad_1F_Text_197BE1
	msgbox VictoryRoad_1F_Text_197BF7, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_15DF9D:: @ 815DF9D
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_197C45, VictoryRoad_1F_Text_197C8D
	msgbox VictoryRoad_1F_Text_197CAF, MSGBOX_AUTOCLOSE
	end
