UnionCity_House1_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UnionCity_House1_1F_OnTransition
	.byte 0

UnionCity_House1_1F_OnTransition:
	goto_if_eq VAR_UNION_CITY_HOUSE_1_1F_OLD_LADY_STATE, 0, UnionCity_House1_1F_HideOldLady2
	end

UnionCity_House1_1F_HideOldLady2::
	removeobject 2
	setflag FLAG_HIDE_UNION_CITY_HOUSE_1_1F_OLD_LADY_2
	end

UnionCity_House1_1F_OldLadyState::
	clearflag FLAG_HIDE_UNION_CITY_HOUSE_1_1F_OLD_LADY_2
	addobject 2
	setvar VAR_UNION_CITY_HOUSE_1_1F_OLD_LADY_STATE, 2
	end

UnionCity_House1_1F_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_UNION_CITY_HOUSE_1_1F_SPINARAK, UnionCity_House1_1F_DrinkTea
	msgbox UnionCity_House1_1F_Text_MyDearTrainer, MSGBOX_AUTOCLOSE
	release
	end

UnionCity_House1_1F_DrinkTea::
	msgbox UnionCity_House1_1F_Text_WhatsThatTheSpiderIsGone, MSGBOX_AUTOCLOSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 5
	goto_if_eq UnionCity_House1_1F_MoveLadyDownTwo
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 3, WR2D2R6
	waitmovement 0
	goto UnionCity_House1_1F_OldLadyEndScript
	end

UnionCity_House1_1F_OldLadyEndScript::
	removeobject 3
	setflag FLAG_HIDE_UNION_CITY_HOUSE_1_1F_OLD_LADY_1
	setvar VAR_UNION_CITY_HOUSE_1_1F_OLD_LADY_STATE, 1
	release
	end

UnionCity_House1_1F_MoveLadyDownTwo::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 3, WD2R9
	waitmovement 0
	goto UnionCity_House1_1F_OldLadyEndScript
	end

UnionCity_House1_1F_Spinarak::
	lockall
	setrespawn HEAL_LOCATION_UNION_CITY
	setflag FLAG_PREVENT_BATTLE_FLEE
	playmoncry SPECIES_SPINARAK, 0
	speakername CommonName_Text_Spinarak
	msgbox UnionCity_House1_1F_Text_Spinarak, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_SPINARAK, 5, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_SPINARAK, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject 1
	setflag FLAG_HIDE_UNION_CITY_HOUSE_1_1F_SPINARAK
	clearflag FLAG_PREVENT_BATTLE_FLEE
	fadescreen 0
	releaseall
	end

UnionCity_House1_1F_OldLady2::
	lock
	faceplayer
	goto_if_eq VAR_UNION_CITY_HOUSE_1_1F_OLD_LADY_STATE, 3, UnionCity_House1_1F_OldLadyGiven
	msgbox UnionCity_House1_1F_AhMyCoffee, MSGBOX_AUTOCLOSE
	giveitem ITEM_PEARL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_UNION_CITY_HOUSE_1_1F_OLD_LADY_STATE, 3
	goto UnionCity_House1_1F_OldLadyGiven
	end

UnionCity_House1_1F_OldLadyGiven::
	msgbox UnionCity_House1_1F_AlthoughPearlsCantBeSold, MSGBOX_AUTOCLOSE
	release
	end

WR2D2R6:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WD2R9:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

UnionCity_House1_1F_Text_Spinarak:
	.string "Tshshh!$"

UnionCity_House1_1F_Text_MyDearTrainer:
	.string "My dear Trainer, please help me!\n"
	.string "There is a spider in my kitchen!$"

UnionCity_House1_1F_Text_WhatsThatTheSpiderIsGone:
	.string "What's that?\n"
	.string "The spider is gone?\p"
	.string "Gosh, thank you so much!\n"
	.string "I really can't stand spiders!\p"
	.string "Hopefully my coffee hasn't turned\n"
	.string "too cold…\p"
	.string "Now, if you'd excuse me, my dear.$"

UnionCity_House1_1F_AhMyCoffee:
	.string "Ah, my coffee is still hot…\n"
	.string "How perfect!\p"
	.string "What's that?\n"
	.string "You'd like something for your deed?\p"
	.string "Very well, darling, take this.$"

UnionCity_House1_1F_AlthoughPearlsCantBeSold:
	.string "Although Pearls can't be sold in\n"
	.string "Marts, collectors pay big for them.\p"
	.string "Be sure to keep any that you find\n"
	.string "along your travels, my dear.$"
