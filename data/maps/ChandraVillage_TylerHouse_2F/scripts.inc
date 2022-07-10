ChandraVillage_TylerHouse_2F_MapScripts::
	.byte 0

ChandraVillage_TylerHouse_2F_ShowHideTyler::
	goto_if_set FLAG_HIDE_CHANDRA_VILLAGE_LAB_TYLER, ChandraVillage_TylerHouse_2F_ShowTyler
	removeobject 1
	removeobject 2
	setflag FLAG_HIDE_TYLERS_HOUSE_TYLER
	setflag FLAG_HIDE_TYLERS_HOUSE_BAG
	release
	end

ChandraVillage_TylerHouse_2F_ShowTyler::
	clearflag FLAG_HIDE_TYLERS_HOUSE_TYLER
	clearflag FLAG_HIDE_TYLERS_HOUSE_BAG
	addobject 1
	addobject 2
	release
	end

ChandraVillage_TylerHouse_2F_TylerIntro::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement 1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox ChandraVillage_TylerHouse_2F_Text_MyBagsPacked, MSGBOX_DEFAULT
	closemessage
	delay 60
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 2
	goto_if_eq ChandraVillage_TylerHouse_2F_Left
	compare VAR_TEMP_0, 3
	goto_if_eq ChandraVillage_TylerHouse_2F_Middle
	compare VAR_TEMP_0, 4
	goto_if_eq ChandraVillage_TylerHouse_2F_Right
	end

ChandraVillage_TylerHouse_2F_Left:
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox ChandraVillage_TylerHouse_2F_Text_Player, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	removeobject 2
	setflag FLAG_HIDE_TYLERS_HOUSE_BAG
	playse SE_BALL_TRAY_ENTER
	waitse
	delay 10
	applymovement 1, WL2D
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox ChandraVillage_TylerHouse_2F_Text_HowsItGoing, MSGBOX_DEFAULT
	goto_if_set FLAG_TAKEN_PIKACHU ChandraVillage_TylerHouse_2F_TylerTeamEevee
	goto ChandraVillage_TylerHouse_2F_TylerTeamPikachu
	end

ChandraVillage_TylerHouse_2F_Middle:
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox ChandraVillage_TylerHouse_2F_Text_Player, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	removeobject 2
	setflag FLAG_HIDE_TYLERS_HOUSE_BAG
	playse SE_BALL_TRAY_ENTER
	waitse
	delay 10
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox ChandraVillage_TylerHouse_2F_Text_HowsItGoing, MSGBOX_DEFAULT
	goto_if_set FLAG_TAKEN_PIKACHU ChandraVillage_TylerHouse_2F_TylerTeamEevee
	goto ChandraVillage_TylerHouse_2F_TylerTeamPikachu
	end

ChandraVillage_TylerHouse_2F_Right:
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox ChandraVillage_TylerHouse_2F_Text_Player, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	removeobject 2
	setflag FLAG_HIDE_TYLERS_HOUSE_BAG
	playse SE_BALL_TRAY_ENTER
	waitse
	delay 10
	applymovement 1, Common_Movement_WalkDown
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox ChandraVillage_TylerHouse_2F_Text_HowsItGoing, MSGBOX_DEFAULT
	goto_if_set FLAG_TAKEN_PIKACHU ChandraVillage_TylerHouse_2F_TylerTeamEevee
	goto ChandraVillage_TylerHouse_2F_TylerTeamPikachu
	end

ChandraVillage_TylerHouse_2F_TylerTeamEevee::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto ChandraVillage_TylerHouse_2F_TylerPostMatch
	end

ChandraVillage_TylerHouse_2F_TylerTeamPikachu::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto ChandraVillage_TylerHouse_2F_TylerPostMatch
	end

ChandraVillage_TylerHouse_2F_TylerPostMatch::
	msgbox ChandraVillage_TylerHouse_2F_Text_ThatWasSomeBattle, MSGBOX_DEFAULT
	closemessage
	goto ChandraVillage_TylerHouse_2F_CheckPosEnd
	end

ChandraVillage_TylerHouse_2F_CheckPosEnd::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 2
	goto_if_eq ChandraVillage_TylerHouse_2F_LeftEnd
	compare VAR_TEMP_0, 3
	goto_if_eq ChandraVillage_TylerHouse_2F_MiddleEnd
	compare VAR_TEMP_0, 4
	goto_if_eq ChandraVillage_TylerHouse_2F_RightEnd
	end

ChandraVillage_TylerHouse_2F_LeftEnd::
	applymovement 1, Common_Movement_WalkRight
	waitmovement 0
	applymovement 1, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto ChandraVillage_TylerHouse_2F_End
	end

ChandraVillage_TylerHouse_2F_MiddleEnd::
	applymovement OBJ_EVENT_ID_PLAYER, WLFR
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeft
	applymovement 1, WD2
	waitmovement 0
	goto ChandraVillage_TylerHouse_2F_End
	end

ChandraVillage_TylerHouse_2F_RightEnd::
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement 1, Common_Movement_WalkDown
	waitmovement 0
	goto ChandraVillage_TylerHouse_2F_End
	end

ChandraVillage_TylerHouse_2F_End::
	removeobject 1
	playse SE_EXIT
	waitse
	setflag FLAG_HIDE_TYLERS_HOUSE_TYLER
	setvar VAR_STORYLINE_STATE, 9
	setvar VAR_TYLERS_HOUSE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

WL2D:
	walk_left
	walk_left
	walk_down
	step_end

WD2:
	walk_down
	walk_down
	step_end

WLFR:
	walk_left
	face_right
	step_end

ChandraVillage_TylerHouse_2F_Text_MyBagsPacked:
	.string "{COLOR}{BLUE}My bag's packed. My Pokémon's ready.\n"
	.string "All set for an epic adventure!$"

ChandraVillage_TylerHouse_2F_Text_Player:
	.string "{COLOR}{BLUE}{PLAYER}!$"

ChandraVillage_TylerHouse_2F_Text_HowsItGoing:
	.string "{COLOR}{BLUE}How's it going, {PLAYER}?\p"
	.string "Did Professor Hawthorne give you a\n"
	.string "Pokémon, too?\lThat's awesome!\p"
	.string "…\p"
	.string "Oh, yes. I almost forgot!\n"
	.string "As promised, let's have that battle!\p"
	.string "But I warn you, {PLAYER},\n"
	.string "I won't hold back!\p"
	.string "Here I come!$"

ChandraVillage_TylerHouse_2F_Text_ThatWasSomeBattle:
	.string "{COLOR}{BLUE}That was some battle, {PLAYER}!\n"
	.string "You fought really well!\p"
	.string "I'm gonna go check out Route 1 and see\n"
	.string "what kind of Pokémon are around.\p"
	.string "Why don't you come join me soon and we\n"
	.string "can both train our Pokémon together?\p"
	.string "See ya!$"
