.set LOCALID_SUBO_1, 4
.set LOCALID_SUBO_2, 5
.set LOCALID_GOVOFF, 6

NorthstarCity_TelescopeSea_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NorthstarCity_TelescopaSea_OnTransition
	.byte 0

NorthstarCity_TelescopaSea_OnTransition:
	call NorthstarCity_TelescopaSea_SetFlashLevel
	end

NorthstarCity_TelescopaSea_SetFlashLevel::
	setflashlevel 2
	return

NorthstarCity_TelescopeSea_SUBO::
	lock
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 20
	goto_if_eq NorthstarCity_TelescopeSea_L0
	compare VAR_TEMP_1, 21
	goto_if_eq NorthstarCity_TelescopeSea_L1
	compare VAR_TEMP_1, 22
	goto_if_eq NorthstarCity_TelescopeSea_L2
	compare VAR_TEMP_1, 23
	goto_if_eq NorthstarCity_TelescopeSea_L3
	compare VAR_TEMP_0, 42
	goto_if_eq NorthstarCity_TelescopeSea_T0
	compare VAR_TEMP_0, 43
	goto_if_eq NorthstarCity_TelescopeSea_T1
	compare VAR_TEMP_0, 44
	goto_if_eq NorthstarCity_TelescopeSea_T2
	compare VAR_TEMP_0, 45
	goto_if_eq NorthstarCity_TelescopeSea_T3
	compare VAR_TEMP_0, 46
	goto_if_eq NorthstarCity_TelescopeSea_T4
	compare VAR_TEMP_0, 47
	goto_if_eq NorthstarCity_TelescopeSea_T5
	compare VAR_TEMP_0, 48
	goto_if_eq NorthstarCity_TelescopeSea_T6
	compare VAR_TEMP_0, 49
	goto_if_eq NorthstarCity_TelescopeSea_T7
	compare VAR_TEMP_0, 50
	goto_if_eq NorthstarCity_TelescopeSea_T8
	goto NorthstarCity_TelescopeSea_T9
	end

NorthstarCity_TelescopeSea_L0::
	applymovement OBJ_EVENT_ID_PLAYER, WRD2R4
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_L1::
	applymovement OBJ_EVENT_ID_PLAYER, WRDR4
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_L2::
	applymovement OBJ_EVENT_ID_PLAYER, WR5
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_L3::
	applymovement OBJ_EVENT_ID_PLAYER, WRUR4
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T0::
	applymovement OBJ_EVENT_ID_PLAYER, WDR4D2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T1::
	applymovement OBJ_EVENT_ID_PLAYER, WDR3D2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T2::
	applymovement OBJ_EVENT_ID_PLAYER, WDR2D2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T3::
	applymovement OBJ_EVENT_ID_PLAYER, WDRD2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T4::
	applymovement OBJ_EVENT_ID_PLAYER, WD3
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T5::
	applymovement OBJ_EVENT_ID_PLAYER, WDLD2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T6::
	applymovement OBJ_EVENT_ID_PLAYER, WDL2D2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T7::
	applymovement OBJ_EVENT_ID_PLAYER, WDL3D2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T8::
	applymovement OBJ_EVENT_ID_PLAYER, WDL4D2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_T9::
	applymovement OBJ_EVENT_ID_PLAYER, WDL5D2
	goto NorthstarCity_TelescopeSea_SUBO_Main
	end

NorthstarCity_TelescopeSea_SUBO_Main::
	waitmovement 0
	applymovement LOCALID_GOVOFF, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	playbgm MUS_SUBO_THEME, 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NorthstarCity_TelescopeSea_Text_Hahaha, MSGBOX_AUTOCLOSE
	applymovement LOCALID_GOVOFF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarCity_TelescopeSea_Text_OhDear, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NorthstarCity_TelescopeSea_Text_WeKnow, MSGBOX_AUTOCLOSE
	applymovement LOCALID_GOVOFF, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_GOVOFF, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NorthstarCity_TelescopeSea_Text_ItSeems, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NorthstarCity_TelescopeSea_Text_IHope, MSGBOX_AUTOCLOSE
	applymovement LOCALID_GOVOFF, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_GOVOFF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarCity_TelescopeSea_Text_FineFine, MSGBOX_AUTOCLOSE
	delay 30
	setvar VAR_STORYLINE_STATE, 1
	setflag FLAG_NORTHSTAR_LIGHTHOUSE_COMPLETE
	warpsilent MAP_NORTHSTAR_CITY_LIGHTHOUSE, 36, 4
	end

WRD2R4:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WRDR4:
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WRUR4:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WDR4D2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

WDR3D2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

WDR2D2:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

WDRD2:
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

WDLD2:
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

WDL2D2:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

WDL3D2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

WDL4D2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

WDL5D2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

NorthstarCity_TelescopeSea_Text_Hahaha:
	.string "{COLOR}{BLUE}Hahaha! You didn't think we were done,\n"
	.string "did you?!$"

NorthstarCity_TelescopeSea_Text_OhDear:
	.string "Oh, dear… This isn't good…\n"
	.string "What am I to do now?$"

NorthstarCity_TelescopeSea_Text_WeKnow:
	.string "{COLOR}{BLUE}We know you're all outta Pokémon,\n"
	.string "so tell you what.\p"
	.string "Hand over those papers peacefully and\n"
	.string "we won't make a huge fuss about it.\p"
	.string "We'll let you go, peaceful-like.\n"
	.string "Promise!$"

NorthstarCity_TelescopeSea_Text_ItSeems:
	.string "It seems I have no choice…\p"
	.string "I sent a distress signal, but they\n"
	.string "won't be coming for a while.\p"
	.string "…\n"
	.string "Better do as they say…$"

NorthstarCity_TelescopeSea_Text_IHope:
	.string "{COLOR}{BLUE}I hope you're a good swimmer, because\n"
	.string "I'll sink your boat if you don't hurry!$"

NorthstarCity_TelescopeSea_Text_FineFine:
	.string "Fine, fine, here you go!\n"
	.string "Here are the papers, all the research…$"
