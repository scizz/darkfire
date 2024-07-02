.set LOCALID_SUBO_1, 34
.set LOCALID_GOV, 35
.set LOCALID_SUBO_2, 36
.set LOCALID_SAILOR_BOAT, 27
.set LOCALID_SAILOR_ONE, 14

NorthstarCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NorthstarCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NorthstarCity_OnFrame
	.byte 0

NorthstarCity_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 38, NorthstarCity_AfterTournament
	.2byte 0

NorthstarCity_OnTransition:
	call_if_unset FLAG_BADGE03_GET, NorthstarCity_HideSailors
	call_if_set FLAG_BADGE03_GET, NorthstarCity_ShowSailor
	end

NorthstarCity_HideSailors::
	removeobject 14
	removeobject 27
	removeobject 28
	setflag FLAG_HIDE_NORTHSTAR_CITY_SAILOR_ONE
	setflag FLAG_HIDE_NORTHSTAR_CITY_SAILOR_TWO
	return

NorthstarCity_ShowSailor::
	clearflag FLAG_HIDE_NORTHSTAR_CITY_SAILOR_TWO
	addobject 27
	addobject 28
	return

NorthstarCity_AfterTournament::
	applymovement LOCALID_SAILOR_ONE, Common_Movement_FaceUp
	waitmovement 0
	emote LOCALID_SAILOR_ONE, 7
	playse SE_PIN
	waitse
	msgbox NorthstarCity_Text_OhTrainer, MSGBOX_AUTOCLOSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 68
	goto_if_eq NorthstarCity_AfterTournament_Left
	goto NorthstarCity_AfterTournament_Right
	end

NorthstarCity_AfterTournament_Left::
	applymovement LOCALID_SAILOR_ONE, WL2
	waitmovement 0
	goto NorthstarCity_AfterTournamentEnd
	end

NorthstarCity_AfterTournament_Right::
	applymovement LOCALID_SAILOR_ONE, WR2
	waitmovement 0
	goto NorthstarCity_AfterTournamentEnd
	end

NorthstarCity_AfterTournamentEnd::
	applymovement LOCALID_SAILOR_ONE, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox Northstar_City_Text_WhatANiceSurprise, MSGBOX_AUTOCLOSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 68
	goto_if_eq NorthstarCity_AfterTournament_EndLeft
	goto NorthstarCity_AfterTournament_EndRight
	end

NorthstarCity_AfterTournament_EndLeft::
	applymovement LOCALID_SAILOR_ONE, WR8
	waitmovement 0
	goto NorthstarCity_AfterTournament_EndHide
	end

NorthstarCity_AfterTournament_EndRight::
	applymovement LOCALID_SAILOR_ONE, WR4U7
	waitmovement 0
	goto NorthstarCity_AfterTournament_EndHide
	end

NorthstarCity_AfterTournament_EndHide::	
	removeobject LOCALID_SAILOR_ONE
	setflag FLAG_HIDE_NORTHSTAR_CITY_SAILOR_ONE
	clearflag FLAG_NORTHSTAR_SUBO_TAKEOVER
	setvar VAR_STORYLINE_STATE, 39
	end

NorthstarCity_Sign::
	msgbox NorthstarCity_Text_Sign, MSGBOX_SIGN
	end

NorthstarCity_Tournament_Sign::
	msgbox NorthstarCity_Text_Tournament_Sign, MSGBOX_SIGN
	end

NorthstarCity_Old_Man::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Old_Man_Badge
	msgbox NorthstarCity_Text_Old_Man, MSGBOX_AUTOCLOSE
	releaseall
	end

NorthstarCity_Old_Man_Badge::
	msgbox NorthstarCity_Text_Old_Man_Badge, MSGBOX_AUTOCLOSE
	releaseall
	end

NorthstarCity_Youngster::
	msgbox NorthstarCity_Text_Youngster, MSGBOX_NPC
	end

NorthstarCity_Thug::
	msgbox NorthstarCity_Text_Thug, MSGBOX_NPC
	end

NorthstarCity_SUBO_1::
	msgbox NorthstarCity_Text_SUBO_1, MSGBOX_NPC
	end

NorthstarCity_Guitarist::
	msgbox NorthstarCity_Text_Guitarist, MSGBOX_NPC
	end

NorthstarCity_Nerd::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Nerd_Badge
	msgbox NorthstarCity_Text_Nerd, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Nerd_Badge::
	msgbox NorthstarCity_Text_Nerd_Badge, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Fat_Man::
	msgbox NorthstarCity_Text_Fat_Man, MSGBOX_NPC
	end

NorthstarCity_SUBO_2::
	lockall
	msgbox NorthstarCity_Text_SUBO_2, MSGBOX_DEFAULT
	closemessage
	applymovement 12, Common_Movement_FacePlayer
	waitmovement 0
	emote 12, 8
	playse SE_PIN
	waitse
	msgbox NorthstarCity_Text_SUBO_2_Caught, MSGBOX_DEFAULT
	applymovement 12, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

NorthstarCity_Old_Man_2::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq NorthstarCity_Old_Man_2_Male
	msgbox NorthstarCity_Text_Old_Man_2_Female, MSGBOX_NPC
	end

NorthstarCity_Old_Man_2_Male::
	msgbox NorthstarCity_Text_Old_Man_2_Male, MSGBOX_NPC
	end

NorthstarCity_Ace_Trainer::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Ace_Trainer_Badge
	msgbox NorthstarCity_Text_Ace_Trainer, MSGBOX_DEFAULT
	release
	end

NorthstarCity_Ace_Trainer_Badge::
	msgbox NorthstarCity_Text_Ace_Trainer_Badge, MSGBOX_DEFAULT
	release
	end

NorthstarCity_Woman_3::
	msgbox NorthstarCity_Text_Woman_3, MSGBOX_NPC
	end

NorthstarCity_Girl::
	msgbox NorthstarCity_Text_Girl, MSGBOX_NPC
	end

NorthstarCity_SUBO_3::
	msgbox NorthstarCity_Text_SUBO_3, MSGBOX_NPC
	end

NorthstarCity_Sailor_1::
	msgbox NorthstarCity_Text_Sailor_1, MSGBOX_NPC
	end

NorthstarCity_Sailor_2::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Text_Sailor_2_Badge
	msgbox NorthstarCity_Text_Sailor_2, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Sailor_3::
	msgbox NorthstarCity_Text_Sailor_3, MSGBOX_NPC
	end

NorthstarCity_Sailor_4::
	msgbox NorthstarCity_Text_Sailor_4, MSGBOX_NPC
	end

NorthstarCity_Sailor_5::
	msgbox NorthstarCity_Text_Sailor_5, MSGBOX_NPC
	end

NorthstarCity_Fisherman::
	msgbox NorthstarCity_Text_Fisherman, MSGBOX_NPC
	end

NorthstarCity_PokeFan_M::
	msgbox NorthstarCity_Text_PokeFan_M, MSGBOX_NPC
	end

NorthstarCity_Receptionist::
	msgbox NorthstarCity_Text_Receptionist, MSGBOX_NPC
	end

NorthstarCity_GuitaristViktor::
	trainerbattle_single TRAINER_GUITARIST_VIKTOR, NorthstarCity_Text_GuitaristViktorIntro, NorthstarCity_Text_GuitaristViktorDefeated
	msgbox NorthstarCity_Text_GuitaristViktorPostBattle, MSGBOX_AUTOCLOSE
	end

NorthstarCity_PsychicBlake::
	trainerbattle_single TRAINER_PSYCHIC_BLAKE, NorthstarCity_Text_PsychicBlakeIntro, NorthstarCity_Text_PsychicBlakeDefeated
	msgbox NorthstarCity_Text_PsychicBlakePostBattle, MSGBOX_AUTOCLOSE
	end

NorthstarCity_GuitaristMarcus::
	trainerbattle_single TRAINER_GUITARIST_MARCUS, NorthstarCity_Text_GuitaristMarcusIntro, NorthstarCity_Text_GuitaristMarcusDefeated
	msgbox NorthstarCity_Text_GuitaristMarcusPostBattle, MSGBOX_AUTOCLOSE
	end

NorthstarCity_PsychicTony::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_GUITARIST_VIKTOR, NorthstarCity_PsychicTonyNotDefeated
	goto_if_not_defeated TRAINER_GUITARIST_VIKTOR, NorthstarCity_PsychicTonyNotDefeated
	goto_if_not_defeated TRAINER_GUITARIST_VIKTOR, NorthstarCity_PsychicTonyNotDefeated
	msgbox NorthstarCity_Text_PsychicTony1, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_PSYCHIC_TONY, PsychicTony_Text_Defeated
	msgbox NorthstarCity_Text_PsychicTony2, MSGBOX_AUTOCLOSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 35
	goto_if_eq NorthstarCity_PsychicTonyPlayerLeft
	goto NorthstarCity_PsychicTonyPlayerBelow
	end

NorthstarCity_PsychicTonyNotDefeated::
	msgbox NorthstarCity_Text_PsychicTony, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_PsychicTonyPlayerLeft::
	applymovement 7, Common_Movement_FaceDown
	waitmovement 0
	emote 7, 7
	playse SE_PIN
	waitse
	applymovement 7, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement 4, Common_Movement_FaceUp
	delay 5
	applymovement 5, Common_Movement_FaceUp
	applymovement 6, Common_Movement_FaceUp
	waitmovement 0
	msgbox NorthstarCity_Text_PsychicTony3, MSGBOX_AUTOCLOSE
	applymovement 7, WD6
	delay 5
	applymovement 5, WD6
	delay 5
	applymovement 6, WD6
	applymovement 4, WD6
	waitmovement 0
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	setflag FLAG_HIDE_NORTHSTAR_CITY_THUGS
	release
	end

NorthstarCity_PsychicTonyPlayerBelow::
	applymovement 7, Common_Movement_FaceLeft
	waitmovement 0
	emote 7, 7
	playse SE_PIN
	waitse
	applymovement 7, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement 4, Common_Movement_FaceUp
	delay 5
	applymovement 5, Common_Movement_FaceUp
	applymovement 6, Common_Movement_FaceUp
	waitmovement 0
	msgbox NorthstarCity_Text_PsychicTony3, MSGBOX_AUTOCLOSE
	applymovement 5, WD6
	delay 5
	applymovement 6, WD6
	delay 5
	applymovement 4, WD6
	applymovement 7, WL2D7
	delay 5
	waitmovement 0
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	setflag FLAG_HIDE_NORTHSTAR_CITY_THUGS
	release
	end

NorthstarCity_Storyline_SUBO::
	lock
	emote LOCALID_SUBO_2, 3
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	applymovement LOCALID_GOV, Common_Movement_FaceDown
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_ThatsIt, MSGBOX_AUTOCLOSE
	hideface 1
	emote LOCALID_GOV, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_GOV, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_GovOfficial
	showface FS_OFFICIAL, FSE_NORMAL, 0, 0
	msgbox Northstar_City_Text_Never, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement LOCALID_GOV, Common_Movement_FaceLeft
	emote LOCALID_GOV, 7
	playse SE_PIN
	delay 5
	applymovement LOCALID_SUBO_1, Common_Movement_FaceLeft
	emote LOCALID_SUBO_1, 7
	playse SE_PIN
	delay 10
	applymovement LOCALID_SUBO_2, Common_Movement_FaceLeft
	emote LOCALID_SUBO_2, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_GOV, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername2 CommonName_Text_GovOfficial
	showface FS_OFFICIAL, FSE_NORMAL, 0, 0
	msgbox Northstar_City_Text_OhATrainer, MSGBOX_AUTOCLOSE
	hideface 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 26
	goto_if_eq NorthstarCity_Storyline_SUBO_MoveGovTop
	compare VAR_TEMP_1, 27
	goto_if_eq NorthstarCity_Storyline_SUBO_MoveGovMiddle
	goto NorthstarCity_Storyline_SUBO_MoveGovBottom
	end

NorthstarCity_Storyline_SUBO_MoveGovTop::
	applymovement LOCALID_GOV, WFL6UFR
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_BattleSetUp
	end

NorthstarCity_Storyline_SUBO_MoveGovMiddle::
	applymovement LOCALID_GOV, WFL3DL3UFR
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_BattleSetUp
	end

NorthstarCity_Storyline_SUBO_MoveGovBottom::
	applymovement LOCALID_GOV, WFL6DFR
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_BattleSetUp
	end

NorthstarCity_Storyline_SUBO_BattleSetUp::
	applymovement LOCALID_GOV, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement 0
	speakername2 CommonName_Text_GovOfficial
	showface FS_OFFICIAL, FSE_NORMAL, 0, 0
	msgbox Northstar_City_Text_TrainerPlease, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceRight
	waitmovement 0
	emote LOCALID_SUBO_2, 3
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_SoThisIsHow, MSGBOX_AUTOCLOSE
	hideface 1
	compare VAR_TEMP_1, 26
	goto_if_eq NorthstarCity_Storyline_SUBO_MoveSUBOTop
	compare VAR_TEMP_1, 27
	goto_if_eq NorthstarCity_Storyline_SUBO_MoveSUBOMiddle
	goto NorthstarCity_Storyline_SUBO_MoveSUBOBottom
	end

NorthstarCity_Storyline_SUBO_MoveSUBOTop::
	applymovement LOCALID_SUBO_2, WL2U2L
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_Battle
	end

NorthstarCity_Storyline_SUBO_MoveSUBOMiddle::
	applymovement LOCALID_SUBO_2, WL2UL
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_Battle
	end

NorthstarCity_Storyline_SUBO_MoveSUBOBottom::
	applymovement LOCALID_SUBO_2, WL3
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_Battle
	end

NorthstarCity_Storyline_SUBO_Battle::
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	playbgm MUS_SUBO_THEME, TRUE
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_YoullStandUp, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_SUBO_THUG_REX, SuboThugRex_Text_Defeated
	emote LOCALID_SUBO_1, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_NoWorries, MSGBOX_AUTOCLOSE
	hideface 1
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 26
	goto_if_eq NorthstarCity_Storyline_SUBO_MoveSUBO2Top
	compare VAR_TEMP_1, 27
	goto_if_eq NorthstarCity_Storyline_SUBO_MoveSUBO2Middle
	goto NorthstarCity_Storyline_SUBO_MoveSUBO2Bottom
	end

NorthstarCity_Storyline_SUBO_MoveSUBO2Top::
	applymovement LOCALID_SUBO_1, WL2DL2FU
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_Battle2
	end

NorthstarCity_Storyline_SUBO_MoveSUBO2Middle::
	applymovement LOCALID_SUBO_1, WL4FD
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_Battle2
	end

NorthstarCity_Storyline_SUBO_MoveSUBO2Bottom::
	applymovement LOCALID_SUBO_1, WL2DL2FD
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_Battle2
	end

NorthstarCity_Storyline_SUBO_Battle2::
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_SayGoodbye, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_SUBO_THUG_ARIK_1, SuboThugArik1_Text_Defeated
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 26
	goto_if_eq NorthstarCity_Storyline_SUBO_MoveSUBOAfterBattleTop
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_FaceUp
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_IDidntStand, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_ThereAreMore, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_2, Common_Movement_WalkUp
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_ClearSUBO
	end

NorthstarCity_Storyline_SUBO_MoveSUBOAfterBattleTop::
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_FaceDown
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_IDidntStand, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox Northstar_City_Text_ThereAreMore, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_2, Common_Movement_WalkDown
	waitmovement 0
	goto NorthstarCity_Storyline_SUBO_ClearSUBO
	end

NorthstarCity_Storyline_SUBO_ClearSUBO::
	applymovement LOCALID_SUBO_1, WL9
	applymovement LOCALID_SUBO_2, WL9
	waitmovement 0
	emote LOCALID_GOV, 2
	playse SE_PIN
	waitse
	applymovement LOCALID_GOV, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement 0
	speakername2 CommonName_Text_GovOfficial
	showface FS_OFFICIAL, FSE_NORMAL, 0, 0
	msgbox Northstar_City_Text_ThankYou, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_GOV, WL6
	waitmovement 0
	removeobject LOCALID_SUBO_1
	removeobject LOCALID_GOV
	removeobject LOCALID_SUBO_2
	setflag FLAG_HIDE_NORTHSTAR_CITY_SUBO_GOV
	setvar VAR_STORYLINE_STATE, 26
	release
	end

NorthstarCity_Sailor_Boat::
	lock
	faceplayer
	speakername CommonName_Text_Sailor
	msgbox NorthstarCity_Text_Sailor_DoYouWantToSail, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq NorthstarCity_Sailor_Yes
	speakername CommonName_Text_Sailor
	msgbox NorthstarCity_Text_Sailor_NoWorries, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Sailor_Yes::
	speakername CommonName_Text_Sailor
	msgbox NorthstarCity_Text_Sailor_PerfectLetsGo, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAILOR_BOAT, Common_Movement_FaceRight
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SAILOR_BOAT
	waitse
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 36
	goto_if_eq NorthstarCity_Player_Left
	goto NorthstarCity_Player_Bottom
	end

NorthstarCity_Player_Left::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto NorthstarCity_Warp_To_Laveria
	end

NorthstarCity_Player_Bottom::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto NorthstarCity_Warp_To_Laveria
	end

NorthstarCity_Warp_To_Laveria::
	warp MAP_LAVERIA_CITY, 39, 43
	waitstate
	end

WR4U7:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WR8:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WL9:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WFL6UFR:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	face_right
	step_end

WFL3DL3UFR:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	face_right
	step_end

WFL6DFR:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	face_right
	step_end

WL2U2L:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	step_end

WL2UL:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

WL2DL2FU:
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	face_up
	step_end

WL4FD:
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

WL2DL2FD:
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	face_down
	step_end

WL2D7:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NorthstarCity_Text_OhTrainer:
	.string "{COLOR}{BLUE}Oh, Trainer!$"

Northstar_City_Text_WhatANiceSurprise:
	.string "{COLOR}{BLUE}What a nice surprise!\p"
	.string "It's your favorite Sailor, from\n"
	.string "Laveria City!\p"
	.string "…\n"
	.string "…\p"
	.string "I must say, I totally expected you to\n"
	.string "become Northstar City Champion!\p"
	.string "Especially after what ya did to Kojiro\n"
	.string "in Laveria City!\l"
	.string "Congratulations!\p"
	.string "Anyway, my boat is over at the docks.\n"
	.string "I'm sailin' back to Laveria soon.\p"
	.string "If ya fancy comin' back with me, come\n"
	.string "find me and I'll be happy to!\p"
	.string "See ya!$"

NorthstarCity_Text_Sign:
	.string "Northstar City\n"
	.string "{FONT_SMALL}“Where Frost Meets Frenzy!”$"

NorthstarCity_Text_Tournament_Sign:
	.string "Northstar TV Station\p"
	.string "The names of Trainers are scribbled\n"
	.string "all over the sign…$"

NorthstarCity_Text_Old_Man_Badge:
	.string "That badge…\n"
	.string "You beat the Northstar Tournament!\p"
	.string "Seeing such young talent makes an old\n"
	.string "man like me smile from ear to ear!$"

NorthstarCity_Text_Old_Man:
	.string "Greetings!\n"
	.string "You look like a Trainer!\p"
	.string "We've had a strong surge of Trainers\n"
	.string "coming from the south recently.\p"
	.string "I'll bet that you are here for the\n"
	.string "Northstar Tournament.\l"
	.string "Am I right? Ha!$"

NorthstarCity_Text_Youngster:
	.string "{COLOR}{BLUE}Brrr…\p"
	.string "I can't believe I made it through all\n"
	.string "that snow. Alone!\p"
	.string "Where is my medal?!\p"
	.string "There has to be some sort of medal for\n"
	.string "this feat!$"

NorthstarCity_Text_Thug:
	.string "{COLOR}{BLUE}Yo, why're you here?\n"
	.string "You lookin' for trouble?\p"
	.string "Be glad I'm saving my energy, else I'd\n"
	.string "grind you to dust!$"

NorthstarCity_Text_SUBO_1:
	.string "{COLOR}{BLUE}I was looking for the Mart, but I got\n"
	.string "lost in this damned city.\p"
	.string "Why did we even come here?\n"
	.string "They never tell us anything.\l"
	.string "I should have never left Anheim Town…$"

NorthstarCity_Text_Guitarist:
	.string "{COLOR}{BLUE}Those SUBO showed up outta nowhere and\n"
	.string "started takin' our corners.\p"
	.string "That's how I ended up hanging around\n"
	.string "this back alley.\p"
	.string "I tried going back to my old spot, but\n"
	.string "their Pokémon are so tough, I just got\l"
	.string "sent packing to the Pokémon Center.\p"
	.string "Don't underestimate 'em like I did…$"

NorthstarCity_Text_Nerd:
	.string "{COLOR}{BLUE}You mean to tell me you made it all\n"
	.string "the way here on foot?\p"
	.string "That is astonishing…\n"
	.string "You're quite the Trainer!$"

NorthstarCity_Text_Nerd_Badge:
	.string "{COLOR}{BLUE}Flying around on Pokémon is cool.\n"
	.string "Surfing around on Pokémon is cooler.\p"
	.string "But the Trainers who made it here on\n"
	.string "foot…"
	.string "They're the coolest.$"

NorthstarCity_Text_Fat_Man:
	.string "{COLOR}{BLUE}Northstar is the jewel of northern\n"
	.string "Tenjo, but we don't have a large Mart\l"
	.string "to compete with the one in Union City.\p"
	.string "Welp, at least we have our docks…$"

NorthstarCity_Text_SUBO_2:
	.string "{COLOR}{BLUE}Beep Beep…\p"
	.string "Favorable spot, taken. Over.\p"
	.string "…\n"
	.string "…\p"
	.string "Roger. I can see the target building\n"
	.string "from here.\p"
	.string "Standing by--$"

NorthstarCity_Text_SUBO_2_Caught:
	.string "{COLOR}{BLUE}Huh?!\n"
	.string "Who are you?!\p"
	.string "Get out of here, before I lose my\n"
	.string "temper!$"

NorthstarCity_Text_Old_Man_2_Female:
	.string "One of these SUBO people almost pushed\n"
	.string "me over earlier… The nerve of them!\p"
	.string "Young lady… Will you teach them a\n"
	.string "lesson for me?$"

NorthstarCity_Text_Old_Man_2_Male:
	.string "One of these SUBO people almost pushed\n"
	.string "me over earlier… The nerve of them!\p"
	.string "Young man… Will you teach them a\n"
	.string "lesson for me?$"

NorthstarCity_Text_Ace_Trainer:
	.string "{COLOR}{BLUE}Here for the tournament?\n"
	.string "Of course you are!\p"
	.string "Best of luck, to the both of us.$"

NorthstarCity_Text_Ace_Trainer_Badge:
	.string "{COLOR}{BLUE}Wow, you actually…\n"
	.string "You won the Northstar tournament!\p"
	.string "Heh, heh…\n"
	.string "I guess you're tougher than you look!$"

NorthstarCity_Text_Woman_3:
	.string "{COLOR}{RED}The farther you travel north in Tenjo,\n"
	.string "the rougher the people you'll find.\p"
	.string "No… I don't belong here.\n"
	.string "I'll get a ferry back to the south…$"

NorthstarCity_Text_Girl:
	.string "{COLOR}{RED}The Director of the Northstar TV\n"
	.string "Station is super talented.\p"
	.string "He makes it look like the tournament\n"
	.string "participants are battling in the sky!$"

NorthstarCity_Text_SUBO_3:
	.string "{COLOR}{BLUE}Yo, who in the world does that guy over\n"
	.string "there think he is?\p"
	.string "I went to board the ship but he almost\n"
	.string "beat me to a pulp!$"

NorthstarCity_Text_Sailor_1:
	.string "{COLOR}{BLUE}This is Tenjo's finest, right here…\n"
	.string "Northstar City's big and busy port!\p"
	.string "Feast your eyes, kid. As a sailor, I\n"
	.string "wouldn't have it any other way! Fwaha!$"

NorthstarCity_Text_Sailor_2:
	.string "{COLOR}{BLUE}I just got home from Slateport, and\n"
	.string "what do I see?\p"
	.string "The city's infested with SUBO scum!\n"
	.string "Unbelievable.$"

NorthstarCity_Text_Sailor_2_Badge:
	.string "{COLOR}{BLUE}I'm leaving on another journey to\n"
	.string "Hoenn soon.\p"
	.string "It'll be one of my last journeys\n"
	.string "before I settle down and retire.$"

NorthstarCity_Text_Sailor_3:
	.string "{COLOR}{BLUE}What're you doing here?\p"
	.string "You've not come to lend a hand with\n"
	.string "these crates, have you?$"

NorthstarCity_Text_Sailor_4:
	.string "{COLOR}{BLUE}Huff, huff, huff, work, work, work…\n"
	.string "Get out of my way, kid!$"

NorthstarCity_Text_Sailor_5:
	.string "{COLOR}{BLUE}There's traffic at the docks, as\n"
	.string "usual.\l"
	.string "Can't complain, though.\p"
	.string "More people, more business, more money\n"
	.string "for all of us!$"

NorthstarCity_Text_Fisherman:
	.string "{COLOR}{BLUE}Tried to fish here, nothing bites.\p"
	.string "Those darn ferries are scaring off\n"
	.string "the fish!$"

NorthstarCity_Text_PokeFan_M:
	.string "{COLOR}{BLUE}The building with the striking red\n"
	.string "roof you see is the shipping office.\p"
	.string "Any cargo that goes in or out the city\n"
	.string "is checked through there.\p"
	.string "I tried to get my son a job there,\n"
	.string "but all he wants to do is hang out\l"
	.string "with bad company in the upper west…$"

Northstar_City_Text_ThatsIt:
	.string "That's it, you're done pal!\n"
	.string "You're all outta Pokémon!\p"
	.string "Now hand over your Pokémon before we\n"
	.string "send you to the bottom of the sea!$"

Northstar_City_Text_Never:
	.string "Never!\n"
	.string "Not to you thugs!$"

Northstar_City_Text_OhATrainer:
	.string "Oh! A Trainer!\nI'm saved!$"

Northstar_City_Text_TrainerPlease:
	.string "Trainer, please, you have to put a\n"
	.string "stop to this!\p"
	.string "I am here to investigate a stolen boat,\n"
	.string "and these thugs have been chasing and\l"
	.string "harrassing me…\p"
	.string "You need to stop this!$"

Northstar_City_Text_SoThisIsHow:
	.string "So, this is how it's gonna go?$"

Northstar_City_Text_YoullStandUp:
	.string "You'll stand up for him?\n"
	.string "Fine.\p"
	.string "That's two bodies at the bottom of the\nsea!$"

Northstar_City_Text_ThisIsSuch:
	.string "This is such a huge mess…$"

Northstar_City_Text_NoWorries:
	.string "No worries!\n"
	.string "He won't beat me!$"

Northstar_City_Text_SayGoodbye:
	.string "Say goodbye to your Pokémon, kid!$"

Northstar_City_Text_HahHah:
	.string "Hah… Hah… The trek through the\n"
	.string "snow has sapped all my strength…$"

Northstar_City_Text_IDidntStand:
	.string "I didn't stand a chance…\n"
	.string "Now we're the ones all outta Pokémon. \p"
	.string "We gotta bail!$"

Northstar_City_Text_ThereAreMore:
	.string "There are more of us in this cursed,\n"
	.string "snow-ridden city.\p"
	.string "You better back down, because when we\n"
	.string "get some backup, things won't go so\l"
	.string "well for you…\p"
	.string "Disappear while you still can.\n"
	.string "You've been warned!$"

Northstar_City_Text_ThankYou:
	.string "Thank you for saving me, Trainer!\n"
	.string "What is your name?\p"
	.string "…\n"
	.string "…\p"
	.string "{PLAYER}?\n"
	.string "The Laveria City Champion?!\p"
	.string "Holy smokes… Talk about being in\n"
	.string "the right place at the right time!\p"
	.string "The SUBO stole a boat from these docks\n"
	.string "and chased my colleague.\p"
	.string "My colleague is in control of some\n"
	.string "extremely important documents.\p"
	.string "{PLAYER}…\n"
	.string "Please save my colleague!\p"
	.string "You can get a better view of the\n"
	.string "chase using the telescope in the\l"
	.string "lighthouse next to us.\p"
	.string "In the meantime, I must head back to\n"
	.string "deliver the news to the President.\p"
	.string "{PLAYER}, we are counting\non you!$"

NorthstarCity_Text_Sailor_DoYouWantToSail:
	.string "{COLOR}{BLUE}Alright!\p"
	.string "Do you want to sail back to Laveria\n"
	.string "City?$"

NorthstarCity_Text_Sailor_PerfectLetsGo:
	.string "{COLOR}{BLUE}Perfect!\n"
	.string "Let's go!$"

NorthstarCity_Text_Sailor_NoWorries:
	.string "{COLOR}{BLUE}No worries!\n"
	.string "Just let me know when you wanna sail!$"

NorthstarCity_Text_GuitaristMarcusIntro:
	.string "{COLOR}{BLUE}You've some nerve coming here, but me\n"
	.string "and my buddies will straighten you up!$"

NorthstarCity_Text_GuitaristMarcusDefeated:
	.string "Darn!\n"
	.string "I almost had it!$"

NorthstarCity_Text_GuitaristMarcusPostBattle:
	.string "{COLOR}{BLUE}This is our favorite corner to hang\n"
	.string "in.\p"
	.string "Nobody who can't keep up with us can\n"
	.string "roll here!$"

NorthstarCity_Text_GuitaristViktorIntro:
	.string "{COLOR}{BLUE}I told my pops a million times,\n"
	.string "working the docks ain't for me.\p"
	.string "I'd rather earn credit by beating up\n"
	.string "punks like you.\l"
	.string "That's always enough to get by! Hah!$"

NorthstarCity_Text_GuitaristViktorDefeated:
	.string "Now I ended up losin' my money…$"

NorthstarCity_Text_GuitaristViktorPostBattle:
	.string "{COLOR}{BLUE}I can't ever give up hanging out with\n"
	.string "my homies here.\p"
	.string "My pops' wasting his time trying to\n"
	.string "get me that job at the docks.$"

NorthstarCity_Text_PsychicBlakeIntro:
	.string "{COLOR}{BLUE}You're on our turf, yo!\n"
	.string "And that means trouble!\p"
	.string "You think you're ready for this?$"

NorthstarCity_Text_PsychicBlakeDefeated:
	.string "I'm sorry, homies, I couldn't…$"

NorthstarCity_Text_PsychicBlakePostBattle:
	.string "{COLOR}{BLUE}I may have lost to you, but my\n"
	.string "girlfriend thinks I'm hot stuff,\l"
	.string "and that's all that matters to me!$"

NorthstarCity_Text_PsychicTony:
	.string "{COLOR}{BLUE}Whaddya lookin' at, kid?\n"
	.string "We ain't movin' an inch!\p"
	.string "How can you expect us to budge when\n"
	.string "you can't even beat my boys in battle?$"

NorthstarCity_Text_PsychicTony1:
	.string "{COLOR}{BLUE}All right.\p"
	.string "So you beat my boys.\n"
	.string "Good for you.\p"
	.string "Truth is, they aren't all that strong\n"
	.string "anyway… But I am!\p"
	.string "Here I come!$"

NorthstarCity_Text_PsychicTony2:
	.string "{COLOR}{BLUE}You fought well, kid.\n"
	.string "I guess this is your spot now.$"

NorthstarCity_Text_PsychicTony3:
	.string "{COLOR}{BLUE}Come on, boys.\n"
	.string "Let's get outta here.$"

NorthstarCity_Text_Receptionist:
	.string "We're getting a few things cleaned\n"
	.string "in preparation for the tournament.\p"
	.string "Please check back later.$"
