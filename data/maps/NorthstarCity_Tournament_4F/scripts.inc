.set LOCALID_SUBO_CROWD, 1
.set LOCALID_ROSE, 2
.set LOCALID_FAT_MAN, 3
.set LOCALID_POKEFAN_F, 4
.set LOCALID_ANNOUNCER, 5
.set LOCALID_CAMERA_LEFT, 6
.set LOCALID_CAMERA_RIGHT, 7
.set LOCALID_ITEM_BALL, 8
.set LOCALID_CAMERA_BOTTOM, 9
.set LOCALID_BLACKBELT_ARENA, 10
.set LOCALID_RANGER_ARENA, 11
.set LOCALID_PSYCHIC_ARENA, 12
.set LOCALID_ACE_TRAINER_ARENA, 13
.set LOCALID_GENTLEMAN_ARENA, 14
.set LOCALID_SAILOR_ARENA, 15
.set LOCALID_RECEPTIONIST, 16
.set LOCALID_ACE_TRAINER_DOOR, 17
.set LOCALID_BLACKBELT_DOOR, 18
.set LOCALID_GENTLEMAN_DOOR, 19
.set LOCALID_RAKAZ, 20
.set LOCALID_SUBO_DOOR, 21
.set LOCALID_SAILOR_DOOR, 22

NorthstarCity_Tournament_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NorthstarCity_Tournament_4F_OnFrame
	.byte 0

NorthstarCity_Tournament_4F_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 0, NorthstarCity_Tournament_4F_EventCheck
	.2byte 0

NorthstarCity_Tournament_4F_EventCheck::
	applymovement LOCALID_RECEPTIONIST, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, WU2L
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_STARTED, NorthstarCity_Tournament_Started
	msgbox NorthstarCity_Tournament_4F_Text_GreetingsIfYouveCome, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq NorthstarCity_Tournament_PartyCheck
	goto NorthstarCity_Tournament_NotReady
	end

NorthstarCity_Tournament_PartyCheck::
	getpartysize
	compare VAR_RESULT, 2
	goto_if_ge NorthstarCity_Tournament_Started
	goto NorthstarCity_Tournament_NotReady
	end

NorthstarCity_Tournament_NotReady::
	msgbox NorthstarCity_Tournament_4F_Text_PleaseComeBack, MSGBOX_AUTOCLOSE
	setflag FLAG_NORTHSTAR_TOURNAMENT_STARTED
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	warp MAP_NORTHSTAR_CITY_TOURNAMENT_3F, 15, 1
	waitstate
	end

NorthstarCity_Tournament_Started::
	setflag FLAG_NORTHSTAR_TOURNAMENT_STARTED
	end

WU2L:
	walk_up
	walk_up
	walk_left
	step_end

NorthstarCity_Tournament_4F_Text_GreetingsIfYouveCome:
	.string "{COLOR}{RED}Greetings!\p"
	.string "If you've come to watch the tournament,\n"
	.string "then too bad…\l"
	.string "The tickets have all sold out!\p"
	.string "… Oh? You're here to participate?\n"
	.string "What are your qualifications?\p"
	.string "…\n"
	.string "…\p"
	.string "It appears you are the victor of the\n"
	.string "Laveria Tournament.\l"
	.string "{PLAYER}, right?\p"
	.string "In this case, you do qualify for the\n"
	.string "Northstar TV Station Tournament!\p"
	.string "You're one of the last contestants to\n"
	.string "sign up.\p"
	.string "You ought to bring your best possible\n"
	.string "Pokémon and stock up lots of items\l"
	.string "to prepare for the challenge ahead.\p"
	.string "Seriously - this is going to be tough.\n"
	.string "Are you ready, {PLAYER}?$"

NorthstarCity_Tournament_4F_Text_PleaseComeBack:
	.string "{COLOR}{RED}Please come back when you are ready.$"
