.set LOCALID_PROF, 21
.set LOCALID_GIRL_1, 17
.set LOCALID_LITTLE_GIRL_1, 18
.set LOCALID_MOTHER_1, 19
.set LOCALID_YOUNGSTER_1, 16
.set LOCALID_DAZ_2, 14
.set LOCALID_LITTLE_GIRL_2, 20
.set LOCALID_DAZ_1, 15

Route9_StarterDome_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_StarterDome_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route9_StarterDome_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, Route9_StarterDome_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route9_StarterDome_OnWarp
	.byte 0

Route9_StarterDome_OnTransition:
	compare VAR_STORYLINE_STATE, 1
	goto_if_ne Route9_StarterDome_HideLittleGirlDaz1
	call Route9_StarterDome_HideLittleGirlDaz2
	end

Route9_StarterDome_HideLittleGirlDaz1::
	removeobject LOCALID_LITTLE_GIRL_2
	removeobject LOCALID_DAZ_2
	setflag FLAG_HIDE_STARTER_DOME_DAZ_LITTLE_GIRL
	end

Route9_StarterDome_HideLittleGirlDaz2::
	removeobject LOCALID_LITTLE_GIRL_1
	removeobject LOCALID_DAZ_1
	setflag FLAG_ROUTE_9_STARTER_DOME_INTRO_COMPLETE
	return

Route9_StarterDome_OnFrame:
	map_script_2 VAR_STORYLINE_STATE, 0, Route9_StarterDome_Intro
	map_script_2 VAR_STORYLINE_STATE, 1, Route9_StarterDome_BackToEntrance
	.2byte 0

Route9_StarterDome_OnLoad:
	call_if_set FLAG_ROUTE_9_STARTER_DOME_COMPLETE, Route9_StarterDome_OpenStarterDoor
	end

Route9_StarterDome_OpenStarterDoor::
	setmetatile 18, 30, 530, 0
	setmetatile 19, 30, 530, 0
	setmetatile 18, 29, 528, 0
	setmetatile 19, 29, 528, 0
	return

Route9_StarterDome_OnWarp:
	map_script_2 VAR_STORYLINE_STATE, 1, Route9_StarterDome_InitRoomObjects
	.2byte 0

Route9_StarterDome_InitRoomObjects::
	updatefollowerpokemongraphic
	applymovement OBJ_EVENT_ID_FOLLOWER, WDFFU
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	showfollower
	end

Route9_StarterDome_Aide_Left_Table::
	msgbox Route9_StarterDome_Text_Aide_Left_Table, MSGBOX_NPC
	end

Route9_StarterDome_Aide_PC::
	lock
	faceplayer
	msgbox Route9_StarterDome_Text_Aide_PC, MSGBOX_DEFAULT
	applymovement 12, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

Route9_StarterDome_Aide_Walk_Around::
	msgbox Route9_StarterDome_Text_Aide_Walk_Around, MSGBOX_NPC
	end

Route9_StarterDome_Aide_Right_Table::
	msgbox Route9_StarterDome_Text_Aide_Right_Table, MSGBOX_NPC
	end

Route9_StarterDome_Aide_Bed::
	lock
	faceplayer
	goto_if_set FLAG_STARTER_DOME_POTION Route9_StarterDome_Aide_Bed_Given
	msgbox Route9_StarterDome_Text_Aide_Bed, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 1
	setflag FLAG_STARTER_DOME_POTION
	goto Route9_StarterDome_Aide_Bed_Given

Route9_StarterDome_Aide_Bed_Given::
	msgbox Route9_StarterDome_Text_Aide_Bed_Given, MSGBOX_DEFAULT
	release
	end

Route9_StarterDome_Ace_Trainer::
	msgbox Route9_StarterDome_Text_Ace_Trainer, MSGBOX_NPC
	end

Route9_StarterDome_Little_Girl::
	msgbox Route9_StarterDome_Text_Little_Girl_Male, MSGBOX_NPC
	end

Route9_StarterDome_Mother::
	msgbox Route9_StarterDome_Text_Mother, MSGBOX_NPC
	end

Route9_StarterDome_Little_Boy::
	lock
	faceplayer
	msgbox Route9_StarterDome_Text_Little_Boy, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Route9_StarterDome_Girl::
	msgbox Route9_StarterDome_Text_Girl, MSGBOX_NPC
	end

Route9_StarterDome_Fat_Guy::
	msgbox Route9_StarterDome_Text_Fat_Guy, MSGBOX_NPC
	end

Route9_StarterDome_Youngster::
	msgbox Route9_StarterDome_Text_Youngster, MSGBOX_NPC
	end

Route9_StarterDome_Woman::
	msgbox Route9_StarterDome_Text_Woman, MSGBOX_NPC
	end

Route9_StarterDome_Sailor::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_ROUTE_9_AWAKENING, Route9_Awakening_Received
	msgbox Route9_Text_SailorOne, MSGBOX_DEFAULT
	giveitem ITEM_AWAKENING, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_ROUTE_9_AWAKENING
	goto Route9_Awakening_Received
	end

Route9_Awakening_Received::
	msgbox Route9_Text_SailorTwo, MSGBOX_DEFAULT
	releaseall
	end

Route9_StarterDome_Intro::
	removeobject 2
	removeobject 3
	removeobject 8
	removeobject 9
	setflag FLAG_HIDE_STARTER_DOME_TRAINERS_2
	applymovement LOCALID_DAZ_1, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	updatefollowerpokemongraphic
	showfollower
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	applymovement LOCALID_DAZ_1, WRFU
	waitmovement 0
	delay 10
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_NowThatEveryone, MSGBOX_AUTOCLOSE
	hideface 0
	playbgm MUS_FOLLOW_ME, TRUE
	applymovement LOCALID_PROF, WL2
	delay 5
	applymovement LOCALID_GIRL_1, WU2
	delay 10
	applymovement LOCALID_LITTLE_GIRL_1, WU2
	delay 5
	applymovement LOCALID_MOTHER_1, WU2
	delay 5
	applymovement LOCALID_YOUNGSTER_1, WU2
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, WU2
	applymovement OBJ_EVENT_ID_FOLLOWER, WU2
	delay 5
	applymovement LOCALID_DAZ_1, WU2
	waitmovement 0
	applymovement LOCALID_PROF, WL6U14RUR8FD
	applymovement LOCALID_GIRL_1, WL7U14R10UFD
	applymovement LOCALID_LITTLE_GIRL_1, WL8U14RUR7FD
	applymovement LOCALID_MOTHER_1, WL9U14RUR6FD
	applymovement LOCALID_YOUNGSTER_1, D10WUL7U14R10FD
	applymovement LOCALID_DAZ_1, D5WUL9U14R9FD
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, D10WUL8U14R8FD
	applymovement OBJ_EVENT_ID_CAMERA, D10WUL8U14R8FD
	applymovement OBJ_EVENT_ID_FOLLOWER, D10WU2L8U14R7FD
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WSD3
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_DownHereIsTheGrass, MSGBOX_AUTOCLOSE
	hideface 0
	delay 60
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WSU3
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_BulbasaurChikoritaAndTreecko, MSGBOX_AUTOCLOSE
	hideface 0
	waitmovement 0
	applymovement LOCALID_LITTLE_GIRL_1, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_LittleGirl
	msgbox Route9_StarterDome_Text_MommyICanSee, MSGBOX_AUTOCLOSE
	applymovement LOCALID_LITTLE_GIRL_1, Common_Movement_FaceDown
	waitmovement 0 
	special RemoveCameraObject
	applymovement LOCALID_PROF, WU6FL
	delay 5
	applymovement LOCALID_LITTLE_GIRL_1, WU6FL
	delay 5
	applymovement LOCALID_MOTHER_1, WRU5FL
	applymovement LOCALID_GIRL_1, WLU5FL
	delay 5
	applymovement LOCALID_DAZ_1, D16WULU4FL
	applymovement LOCALID_YOUNGSTER_1, WUFLD32WLU4FL
	delay 5
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, D48WU4FL
	applymovement OBJ_EVENT_ID_CAMERA, D48WU4FL
	applymovement OBJ_EVENT_ID_FOLLOWER, D48WRU3FFL
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WSL3
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_ToTheLeftIsTheFireArea, MSGBOX_AUTOCLOSE
	hideface 0
	delay 60
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WSR3
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_CharmanderCyndaquilAndTorchic, MSGBOX_AUTOCLOSE
	hideface 0
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_FaceRight
	delay 5
	applymovement LOCALID_LITTLE_GIRL_1, Common_Movement_FaceRight
	applymovement LOCALID_GIRL_1, Common_Movement_FaceRight
	delay 5
	applymovement LOCALID_MOTHER_1, Common_Movement_FaceRight
	delay 5
	applymovement LOCALID_DAZ_1, Common_Movement_FaceRight
	applymovement LOCALID_YOUNGSTER_1, Common_Movement_FaceRight
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WSR3
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_AndToTheRightIsTheWaterArea, MSGBOX_AUTOCLOSE
	hideface 0
	delay 60
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WSL3
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_SquirtleTotodileAndMudkip, MSGBOX_AUTOCLOSE
	hideface 0
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement LOCALID_MOTHER_1, Common_Movement_FaceUp
	applymovement LOCALID_GIRL_1, Common_Movement_FaceUp
	delay 5
	applymovement LOCALID_DAZ_1, Common_Movement_FaceUp
	delay 5
	applymovement LOCALID_YOUNGSTER_1, Common_Movement_FaceUp
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceUp
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_OkayThatConcludes, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_DAZ_1, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_DAZ_1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_DAZ_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 0, 0
	msgbox Route9_StarterDome_Text_SweetPlayerDoYouKnow, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route9_StarterDome_Yes
	goto Route9_StarterDome_No
	end

Route9_StarterDome_Yes::
	msgbox Route9_StarterDome_Text_AsGoodAsAny, MSGBOX_AUTOCLOSE
	hideface 0
	goto Route9_StarterDome_Main
	end

Route9_StarterDome_No::
	msgbox Route9_StarterDome_Text_IHeardThereWillBe, MSGBOX_AUTOCLOSE
	hideface 0
	goto Route9_StarterDome_Main
	end

Route9_StarterDome_Main::
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement LOCALID_DAZ_1, Common_Movement_FaceUp
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_LetsGetBack, MSGBOX_AUTOCLOSE
	hideface 0
	clearflag FLAG_HIDE_STARTER_DOME_DAZ_LITTLE_GIRL
	setvar VAR_STORYLINE_STATE, 1
	warpsilent MAP_ROUTE9_STARTER_DOME, 18, 34
	waitstate
	end

Route9_StarterDome_BackToEntrance::
	applymovement LOCALID_PROF, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_AllRightAreYouReady, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_PROF, Common_Movement_FaceUp
	waitmovement 0
	setmetatile 18, 30, 530, 0
	setmetatile 19, 30, 530, 0
	setmetatile 18, 29, 637, 0
	setmetatile 19, 29, 638, 0
	playse SE_PIN
	special DrawWholeMapView
	delay 10
	setmetatile 18, 29, 528, 0
	setmetatile 19, 29, 528, 0
	playse SE_PIN
	special DrawWholeMapView
	delay 10
	waitse
	applymovement LOCALID_PROF, WLFR
	waitmovement 0
	applymovement LOCALID_LITTLE_GIRL_2, WFRU3LU3
	delay 5
	applymovement LOCALID_GIRL_1, WURU4
	applymovement LOCALID_YOUNGSTER_1, WU2RU4
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, WRU
	applymovement OBJ_EVENT_ID_FOLLOWER, WURFFU
	applymovement LOCALID_MOTHER_1, D16U5
	waitmovement 0
	delay 30
	removeobject LOCALID_LITTLE_GIRL_2
	removeobject LOCALID_GIRL_1
	removeobject LOCALID_YOUNGSTER_1
	removeobject LOCALID_MOTHER_1
	applymovement LOCALID_PROF, WR2DWIPSD
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_PlayerIAmSoGlad, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_DAZ_2, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_DAZ_2, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_FaceLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route9_StarterDome_BackToEntranceMale
	goto Route9_StarterDome_BackToEntranceFemale
	end

Route9_StarterDome_BackToEntranceMale::
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox Route9_StarterDome_Text_ProfHawthornePlayerBeatHes, MSGBOX_AUTOCLOSE
	hideface 1
	goto Route9_StarterDome_BackToEntranceNext
	end

Route9_StarterDome_BackToEntranceFemale::
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox Route9_StarterDome_Text_ProfHawthornePlayerBeatShes, MSGBOX_AUTOCLOSE
	hideface 1
	goto Route9_StarterDome_BackToEntranceNext
	end

Route9_StarterDome_BackToEntranceNext::
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_DidYouPlayer, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_AndWhoWouldYouBe, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_DAZ_2, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox Route9_StarterDome_Text_YeahTheyAre, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_LAUGHING, 0, 0
	msgbox Route9_StarterDome_Text_HahSuchFervor, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	message Route9_StarterDome_Text_OhPlayerIAlmostForgot
	waitmessage
	multichoice 21, 8, MULTI_CHOOSE_STONE, TRUE
	switch VAR_RESULT
	case 0, Route9_StarterDome_GiveThunderStone
	case 1, Route9_StarterDome_GiveFireStone
	case 2, Route9_StarterDome_GiveWaterStone
	case 3, Route9_StarterDome_GiveLeafStone
	case 4, Route9_StarterDome_GiveMoonStone
	case 5, Route9_StarterDome_GiveSunStone
	end

Route9_StarterDome_GiveThunderStone::
	hideface 0
	giveitem ITEM_THUNDER_STONE, 1
	goto Route9_StarterDome_EventEnd
	end

Route9_StarterDome_GiveFireStone::
	hideface 0
	giveitem ITEM_FIRE_STONE, 1
	goto Route9_StarterDome_EventEnd
	end

Route9_StarterDome_GiveWaterStone::
	hideface 0
	giveitem ITEM_WATER_STONE, 1
	goto Route9_StarterDome_EventEnd
	end

Route9_StarterDome_GiveLeafStone::
	hideface 0
	giveitem ITEM_LEAF_STONE, 1
	goto Route9_StarterDome_EventEnd
	end

Route9_StarterDome_GiveMoonStone::
	hideface 0
	giveitem ITEM_MOON_STONE, 1
	goto Route9_StarterDome_EventEnd
	end

Route9_StarterDome_GiveSunStone::
	hideface 0
	giveitem ITEM_SUN_STONE, 1
	goto Route9_StarterDome_EventEnd
	end

Route9_StarterDome_EventEnd::
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_StarterDome_Text_ExcellentIAmCertain, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement OBJ_EVENT_ID_PLAYER, D32FD
	applymovement LOCALID_DAZ_2, D32FD
	applymovement LOCALID_PROF, WRD4LFD
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_PROF
	waitse
	applymovement LOCALID_DAZ_2, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox Route9_StarterDome_Text_WellPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_DAZ_2, WU6
	waitmovement 0
	removeobject LOCALID_DAZ_2
	setflag FLAG_ROUTE_9_STARTER_DOME_COMPLETE
	setflag FLAG_HIDE_STARTER_DOME_DAZ_LITTLE_GIRL
	clearflag FLAG_HIDE_STARTER_DOME_TRAINERS_2 @addobject 2, 3, 8, 9
	setvar VAR_STORYLINE_STATE, 2
	end

WDFFU:
	lock_facing_direction
	walk_faster_down
	unlock_facing_direction
	step_end

WL6U14RUR8FD:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

WL7U14R10UFD:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end

WL8U14RUR7FD:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

WL9U14RUR6FD:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

D10WUL7U14R10FD:
	delay_8
	delay_8
	delay_8
	delay_8
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

D5WUL9U14R9FD:
	delay_8
	delay_8
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

D10WUL8U14R8FD:
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_1
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

D10WU2L8U14R7FD:
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_1
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	follower_face_down
	step_end

WU6FL:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

WRU5FL:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

WLU5FL:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

D16WULU4FL:
	delay_16
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

WUFLD32WLU4FL:
	walk_up
	face_left
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

D48WU4FL:
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

D48WRU3FFL:
	delay_16
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	follower_face_left 
	step_end

WSD3:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

WSU3:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

WFRU3LU3:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WU2RU4:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WRU:
	walk_right
	walk_up
	step_end

WURFU:
	walk_up
	walk_right
	face_up
	step_end

WURFFU:
	walk_up
	walk_right
	follower_face_up
	step_end

D16U5:
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WRD4LFD:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

D32FD:
	delay_16
	delay_16
	face_down
	step_end

WURU4:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WR2DWIPSD:
	walk_right
	walk_right
	walk_down
	walk_in_place_slow_down
	step_end

Route9_StarterDome_Text_Aide_Left_Table:
	.string "{COLOR}{BLUE}The Pokémon Dome Laboratory is truly a\n"
	.string "technological miracle.\p"
	.string "We use state-of-the-art machinery to\n"
	.string "harness renewable energy sources such\l"
	.string "as the sun and the wind to provide\l"
	.string "cosy housing for all Pokémon here.$"

Route9_StarterDome_Text_Aide_PC:
	.string "{COLOR}{BLUE}H-wha'?\p"
	.string "Oh…\p"
	.string "Hello, kid…\n"
	.string "Sorry. I'm working right now.\p"
	.string "Go play with that machine behind me,\n"
	.string "or something… It's a special PC.$"

Route9_StarterDome_Text_Aide_Walk_Around:
	.string "{COLOR}{BLUE}The Rangers' Federation is helping us\n"
	.string "with breeding, training and studying\l"
	.string "certain rare Pokémon within this Dome.\p"
	.string "But, none of it would be possible\n"
	.string "without the aid we receive from the\l"
	.string "Tenjo Government.$"

Route9_StarterDome_Text_Aide_Right_Table:
	.string "{COLOR}{BLUE}Thanks to our Beginner Trainer\n"
	.string "Program, dozens of Trainers will be\l"
	.string "able to start their quest after\l"
	.string "earning their first Pokémon.\p"
	.string "The children of today are so lucky!$"

Route9_StarterDome_Text_Aide_Bed:
	.string "{COLOR}{BLUE}What's that?\p"
	.string "You came all this way from Chandra\n"
	.string "Village?\p"
	.string "Goodness me, that's quite a long way\n"
	.string "away.\p"
	.string "Tell you what…\n"
	.string "Take this!$"

Route9_StarterDome_Text_Aide_Bed_Given:
	.string "{COLOR}{BLUE}If you need to heal your Pokémon,\n"
	.string "just use these beds over here.\p"
	.string "You can also access our special PC if\n"
	.string "you need to change your party.\p"
	.string "It's the big machine by the entrance\n"
	.string "of the Dome.$"

Route9_StarterDome_Text_Ace_Trainer:
	.string "{COLOR}{BLUE}Fire-types are the best!\p"
	.string "There's nothing and nobody on this\n"
	.string "earth that can change my mind.\p"
	.string "Fire-types for life!$"

Route9_StarterDome_Text_Little_Girl_Female:
	.string "{COLOR}{RED}Wah!\p"
	.string "You scared me, lady!$"

Route9_StarterDome_Text_Little_Girl_Male:
	.string "{COLOR}{RED}Wah!\p"
	.string "You scared me, mister!$"

Route9_StarterDome_Text_Mother:
	.string "{COLOR}{RED}I'm here to witness my daughter get\n"
	.string "her first Pokémon.\l"
	.string "It is truly a special moment.\p"
	.string "It reminds me of the time when my two\n"
	.string "sons got their first Pokémon, too.\l"
	.string "You should have seen their faces!\p"
	.string "My daughter's natural love for Pokémon\n"
	.string "and people tells me that she will be a\l"
	.string "better Trainer than her elder brothers.$"

Route9_StarterDome_Text_Little_Boy:
	.string "{COLOR}{BLUE}Look! Water-type Pokémon!\n"
	.string "My favorite…\p"
	.string "I know I'll get Squirtle when I'm 10.$"

Route9_StarterDome_Text_Girl:
	.string "{COLOR}{RED}I don't know what starter Pokémon I\n"
	.string "should pick… They are all cute!$"

Route9_StarterDome_Text_Fat_Guy:
	.string "{COLOR}{BLUE}I can feel the heat of those Fire-type\n"
	.string "Pokémon even through the glass!\p"
	.string "Pokémon are such amazing creatures.$"

Route9_StarterDome_Text_Youngster:
	.string "{COLOR}{BLUE}$I think I'm gonna go for a Water-type\n"
	.string "Pokémon. Water-types are my thing!\p"
	.string "I want to Surf the Tenjo seas with\n"
	.string "one, some day…$"

Route9_StarterDome_Text_Woman:
	.string "{COLOR}{RED}If you have a full party, feel free to\n"
	.string "use the red and white machine at the\l"
	.string "front of the Dome to access your PC.$"

Route9_Text_SailorOne:
	.string "{COLOR}{BLUE}Zzz…\n"
	.string "Wh- Huh?\p"
	.string "Oh, hello.\p"
	.string "If your Pokémon are as sleepy as I\n"
	.string "am, just use this on them!$"

Route9_Text_SailorTwo:
	.string "{COLOR}{BLUE}I would use these beds here to sleep,\n"
	.string "but I'm not sure if that's appropriate!$"

Route9_StarterDome_Text_NowThatEveryone:
	.string "Now that everyone is here, let's take\n"
	.string "a little tour of the Dome Laboratory!$"

Route9_StarterDome_Text_DownHereIsTheGrass:
	.string "Down here is the Grass Area of the\n"
	.string "Dome Laboratory.$"

Route9_StarterDome_Text_BulbasaurChikoritaAndTreecko:
	.string "Bulbasaur, Chikorita and Treecko\n"
	.string "can be found here among the trees.\p"
	.string "They like to hide in the grass, so\n"
	.string "you may have to look for them!$"

Route9_StarterDome_Text_MommyICanSee:
	.string "{COLOR}{RED}Mommy, I can see a Chikorita!$"

Route9_StarterDome_Text_ToTheLeftIsTheFireArea:
	.string "To the left is the Fire Area of the\n"
	.string "Dome Laboratory.$"

Route9_StarterDome_Text_CharmanderCyndaquilAndTorchic:
	.string "Charmander, Cyndaquil and Torchic are\n"
	.string "here, somewhere between the rocks.\p"
	.string "Be careful, don't get burned trying\n"
	.string "to catch them!$"

Route9_StarterDome_Text_AndToTheRightIsTheWaterArea:
	.string "And to the right is the Water Area of\n"
	.string "the Dome Laboratory.$"

Route9_StarterDome_Text_SquirtleTotodileAndMudkip:
	.string "Squirtle, Totodile and Mudkip like to\n"
	.string "swim in the pond here.\l"
	.string "They're tricky to reach!$"

Route9_StarterDome_Text_OkayThatConcludes:
	.string "Okay, that concludes our tour!\p"
	.string "Which one will you pick?\p"
	.string "Better think hard, and remember,\n"
	.string "you're allowed to choose only one!$"

Route9_StarterDome_Text_SweetPlayerDoYouKnow:
	.string "Sweet!\n"
	.string "{PLAYER}!\p"
	.string "Do you know which one you're gonna go\n"
	.string "after?$"

Route9_StarterDome_Text_IHeardThereWillBe:
	.string "I heard there will be more giveaways\n"
	.string "like this one in the future.\p"
	.string "But, for this time, I know for sure\n"
	.string "what I'm picking!$"

Route9_StarterDome_Text_PlayerItsTheMoment:
	.string "{PLAYER}!\nIt's the moment we've been waiting for!$"

Route9_StarterDome_Text_AllRightAreYouReady:
	.string "All right! Are you ready?\n"
	.string "Let the giveaway commence!$"

Route9_StarterDome_Text_PlayerIAmSoGlad:
	.string "{PLAYER}!\n"
	.string "I am so glad to see you here.\p"
	.string "Your journey must be coming along well\n"
	.string "if you've got all the way here from\l"
	.string "Chandra Village.$"

Route9_StarterDome_Text_ProfHawthornePlayerBeatShes:
	.string "Prof. Hawthorne!\p"
	.string "{PLAYER} beat the champion of Greendale\n"
	.string "Village!\l"
	.string "She's a rising star!$"

Route9_StarterDome_Text_AsGoodAsAny:
	.string "As good as any, I bet.\p"
	.string "I heard there will be more giveaways\n"
	.string "like this one in the future.\p"
	.string "But, for this time, I know for sure\n"
	.string "what I'm picking!$"

Route9_StarterDome_Text_LetsGetBack:
	.string "Let's get back, everybody.$"

Route9_StarterDome_Text_ProfHawthornePlayerBeatHes:
	.string "Prof. Hawthorne!\p"
	.string "{PLAYER} beat the champion of Greendale\n"
	.string "Village!\l"
	.string "He's a rising star!$"

Route9_StarterDome_Text_DidYouPlayer:
	.string "Did you, {PLAYER}?\n"
	.string "Congratulations!\p"
	.string "The road to glory is long still,\n"
	.string "though.$"

Route9_StarterDome_Text_AndWhoWouldYouBe:
	.string "And who would you be?\p"
	.string "…\n"
	.string "…\p"
	.string "Hold on a minute…\n"
	.string "You must be Daz, from Lumeria City.\p"
	.string "Aren't your parents running that\n"
	.string "popular battle club in the city?$"

Route9_StarterDome_Text_YeahTheyAre:
	.string "Yeah, they are. But I'm not gonna live\n"
	.string "in their shadow forever!\p"
	.string "I'm here to get my own Pokémon and\n"
	.string "make a name for myself!$"

Route9_StarterDome_Text_HahSuchFervor:
	.string "Hah… Such fervor!\n"
	.string "It'll get you far!$"

Route9_StarterDome_Text_OhPlayerIAlmostForgot:
	.string "Oh, {PLAYER}!\n"
	.string "I almost forgot!\p"
	.string "It just so happens that I have some\n"
	.string "evolutionary stones on me.\p"
	.string "They came in the mail as a special\n"
	.string "package from Union City.\p"
	.string "As a reward for coming this far in your\n"
	.string "journey, I'll let you choose one!\p"
	.string "Which evolutionary stone would you\n"
	.string "like, {PLAYER}?$"

Route9_StarterDome_Text_ThunderStone:
	.string "Are you sure you want to take the\n"
	.string "ThunderStone?$"

Route9_StarterDome_Text_WaterStone:
	.string "Are you sure you want to take the\n"
	.string "Water Stone?$"

Route9_StarterDome_Text_FireStone:
	.string "Are you sure you want to take the\n"
	.string "Fire Stone?$"

Route9_StarterDome_Text_LeafStone:
	.string "Are you sure you want to take the\n"
	.string "Leaf Stone?$"

Route9_StarterDome_Text_MoonStone:
	.string "Are you sure you want to take the\n"
	.string "Moon Stone?$"

Route9_StarterDome_Text_SunStone:
	.string "Are you sure you want to take the\n"
	.string "Sun Stone?$"

Route9_StarterDome_Text_ExcellentIAmCertain:
	.string "Excellent! I am certain that will help\n"
	.string "you on your journey.\p"
	.string "Anyway…\n"
	.string "Best of luck to you both.\p"
	.string "I apologize for being in a hurry, but I\n"
	.string "must head back to Chandra Village now.\p"
	.string "Good bye!$"

Route9_StarterDome_Text_WellPlayer:
	.string "Well, {PLAYER},\n"
	.string "I'll see you around!$"
