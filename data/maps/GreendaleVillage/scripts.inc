.set LOCALID_COOLTRAINER, 7
.set LOCALID_RANGER, 8
.set LOCALID_YOUNGSTER, 6
.set LOCALID_NURSE1, 1
.set LOCALID_HOST, 3
.set LOCALID_NURSE2, 2
.set LOCALID_ROSE, 9

GreendaleVillage_MapScripts::
	.byte 0

GreendaleVillage_Tournament::
	lock
	setrespawn HEAL_LOCATION_GREENDALE_VILLAGE
	special HealPlayerParty
	removeobject LOCALID_ROSE
	setflag FLAG_HIDE_GREENDALE_VILLAGE_ROSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 25
	call_if_eq GreendaleVillage_Tournament_Left
	compare VAR_TEMP_0, 26
	call_if_eq GreendaleVillage_Tournament_Middle
	goto GreendaleVillage_Tournament_Right
	end

GreendaleVillage_Tournament_Left::
	applymovement OBJ_EVENT_ID_PLAYER, WURU
	applymovement OBJ_EVENT_ID_FOLLOWER, WUURFFU
	waitmovement 0
	goto GreendaleVillage_Tournament_Main
	end

GreendaleVillage_Tournament_Middle::
	applymovement OBJ_EVENT_ID_PLAYER, WU2
	applymovement OBJ_EVENT_ID_FOLLOWER, WU2
	waitmovement 0
	goto GreendaleVillage_Tournament_Main
	end

GreendaleVillage_Tournament_Right::
	applymovement OBJ_EVENT_ID_PLAYER, WULU
	applymovement OBJ_EVENT_ID_FOLLOWER, WUULFFU
	waitmovement 0
	goto GreendaleVillage_Tournament_Main
	end

GreendaleVillage_Tournament_Main::
	goto_if_set FLAG_START_GREENDALE_VILLAGE_TOURNAMENT, GreendaleVillage_Tournament_ToPos
	delay 30
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_IAmVerySorry, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_BugCatcher
	msgbox GreendaleVillage_Text_AwwThisIsntFair, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername SpeakerName_Text_Ranger
	msgbox GreendaleVillage_Text_ThisMeansIWont, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_YOUNGSTER, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_YOUNGSTER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_BugCatcher
	msgbox GreendaleVillage_Text_WaitATrainer, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_YOUNGSTER, WR3FD
	waitmovement 0
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_BugCatcher
	msgbox GreendaleVillage_Text_HeyYou, MSGBOX_AUTOCLOSE
	applymovement LOCALID_YOUNGSTER, WL3FR
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	goto GreendaleVillage_Tournament_ToPos
	end

GreendaleVillage_Tournament_ToPos::
	applymovement OBJ_EVENT_ID_PLAYER, WR3UFL
	applymovement OBJ_EVENT_ID_FOLLOWER, WUR4UFFL
	waitmovement 0
	goto_if_set FLAG_START_GREENDALE_VILLAGE_TOURNAMENT, Greendale_Tournament_Battle
	goto GreendaleVillage_Tournament_Begin
	end

GreendaleVillage_Tournament_Begin::
	setflag FLAG_START_GREENDALE_VILLAGE_TOURNAMENT
	applymovement LOCALID_COOLTRAINER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_BugCatcher
	msgbox GreendaleVillage_Text_ThereHostWeHave, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_ErmWellWasnt, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_BugCatcher
	msgbox GreendaleVillage_Text_WeUnderstand, MSGBOX_AUTOCLOSE
	goto Greendale_Tournament_Battle
	end

Greendale_Tournament_Battle::
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_AhaOkayEhem, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_COOLTRAINER, WR2
	applymovement LOCALID_RANGER, WL2
	delay 10
	applymovement LOCALID_YOUNGSTER, WR2
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, WL2
	applymovement OBJ_EVENT_ID_FOLLOWER, WL2
	waitmovement 0
	delay 10
	applymovement LOCALID_HOST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_GoodLuckToEveryone, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_YOUNGSTER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_BugCatcher
	msgbox GreendaleVillage_Text_IDidntSleep, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GREENDALE_DAVIS, GreendaleDavis_Text_Defeated
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_BugCatcher
	msgbox GreendaleVillage_Text_ThisTournamentIsStupid, MSGBOX_AUTOCLOSE
	applymovement LOCALID_YOUNGSTER, RD6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_COOLTRAINER, Common_Movement_FaceDown
	applymovement LOCALID_RANGER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_RANGER, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	random 2
	switch VAR_RESULT
	case 0, GreendaleVillage_Tournament_Battle_Ranger
	case 1, GreendaleVillage_Tournament_Battle_CoolTrainer
	end

GreendaleVillage_Tournament_Battle_Ranger::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	applymovement LOCALID_RANGER, Common_Movement_FaceLeft
	applymovement LOCALID_COOLTRAINER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_AceTrainer
	msgbox GreendaleVillage_Text_HahaWhatAWimp, MSGBOX_AUTOCLOSE
	applymovement LOCALID_COOLTRAINER, WD6
	waitmovement 0
	applymovement LOCALID_RANGER, WL2FR
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WUFL
	applymovement OBJ_EVENT_ID_FOLLOWER, WUFFL
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_AndThatsTheEnd, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_NURSE1, Common_Movement_WalkDown
	applymovement LOCALID_NURSE2, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_RANGER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_NURSE2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Nurse
	msgbox GreendaleVillage_Text_ThatWasAGreatBattle, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement LOCALID_NURSE2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Nurse
	msgbox GreendaleVillage_Text_GoodLuckInTheNext, MSGBOX_AUTOCLOSE
	applymovement LOCALID_NURSE1, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_NURSE1, Common_Movement_FaceDown
	applymovement LOCALID_NURSE2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_NURSE2, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_RANGER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_AllRightTrainers, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_Ranger
	msgbox GreendaleVillage_Text_ImGoingToMoveUp, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GREENDALE_SOPHIA, GreendaleSophia_Text_Defeated
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_RANGER, WD6
	waitmovement 0
	goto GreendaleVillage_Tournament_Rose
	end

GreendaleVillage_Tournament_Battle_CoolTrainer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	applymovement LOCALID_COOLTRAINER, Common_Movement_FaceRight
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername SpeakerName_Text_Ranger
	msgbox GreendaleVillage_Text_PfftWhatAWimp, MSGBOX_AUTOCLOSE
	applymovement LOCALID_RANGER, WLD6
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WUFL
	applymovement OBJ_EVENT_ID_FOLLOWER, WUFFL
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox GreendaleVillage_Text_AndThatsTheEnd, MSGBOX_AUTOCLOSE
	applymovement LOCALID_NURSE1, Common_Movement_WalkDown
	applymovement LOCALID_NURSE2, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_COOLTRAINER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_NURSE2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Nurse
	msgbox GreendaleVillage_Text_ThatWasAGreatBattle, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement LOCALID_NURSE2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Nurse
	msgbox GreendaleVillage_Text_GoodLuckInTheNext, MSGBOX_AUTOCLOSE
	applymovement LOCALID_NURSE1, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_NURSE1, Common_Movement_FaceDown
	applymovement LOCALID_NURSE2, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_NURSE2, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_COOLTRAINER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_AllRightTrainers, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_COOLTRAINER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_AceTrainer
	msgbox GreendaleVillage_Text_ThatTrainerWasWeak, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_JONATHAN, GreendaleJonathan_Text_Defeated
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_COOLTRAINER, WD6
	waitmovement 0
	goto GreendaleVillage_Tournament_Rose
	end

GreendaleVillage_Tournament_Rose::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_AndWeHaveAWinner, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_NURSE1, WD2FR
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_NURSE1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_Nurse
	msgbox GreendaleVillage_Text_ItsAGoodThingWeHave, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement LOCALID_NURSE1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_Nurse
	msgbox GreendaleVillage_Text_ThereYouGoHoney, MSGBOX_AUTOCLOSE
	applymovement LOCALID_NURSE1, WU2FD
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_OkayPlayerAreYouReady, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_NURSE1, Common_Movement_FaceRight
	delay 10
	applymovement LOCALID_HOST, Common_Movement_FaceRight
	delay 10
	applymovement LOCALID_NURSE2, Common_Movement_FaceRight
	waitmovement 0
	opendoor 30, 24
	waitdooranim
	clearflag FLAG_HIDE_GREENDALE_VILLAGE_ROSE
	addobject LOCALID_ROSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceRight
	waitmovement 0
	applymovement LOCALID_ROSE, Common_Movement_WalkDown
	waitmovement 0
	closedoor 30, 24
	waitdooranim
	applymovement OBJ_EVENT_ID_FOLLOWER, WDL2UFFR
	applymovement LOCALID_ROSE, WDL3
	waitmovement 0
	applymovement LOCALID_NURSE1, Common_Movement_FaceDown
	applymovement LOCALID_HOST, Common_Movement_FaceDown
	delay 10
	applymovement LOCALID_NURSE2, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_Dots, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_ROSE, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_OhItsYouAgain, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, LFDWL
	applymovement OBJ_EVENT_ID_FOLLOWER, LFDWL
	waitmovement 0
	goto GreendaleVillage_Tournament_Rose_Battle
	end

GreendaleVillage_Tournament_Rose_Battle::
	trainerbattle_no_intro TRAINER_GREENDALE_CHAMPION_ROSE, GreendaleChampionRose_Text_Defeated
	applymovement LOCALID_ROSE, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_OkayYouBeatMe, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_ROSE, WD6
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, WRFU
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	playfanfare MUS_OBTAIN_SYMBOL
	special DoDomeConfetti
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_AndWeHaveANewChampion, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	hideface 1
	applymovement LOCALID_HOST, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_TheWayYouHandled, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_HM01, 1
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_TeachThisHM, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_HOST, Common_Movement_FaceLeft
	delay 30
	applymovement LOCALID_HOST, Common_Movement_FaceRight
	delay 30
	applymovement LOCALID_HOST, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Announcer
	showface FS_ANNOUNCER, FSE_NORMAL, 1, 1
	msgbox GreendaleVillage_Text_WellIDontKnow, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_FOLLOWER, WDRFUD16FD
	applymovement OBJ_EVENT_ID_PLAYER, D16FD
	applymovement LOCALID_NURSE1, WD8
	applymovement LOCALID_NURSE2, WD8
	applymovement LOCALID_HOST, D16WLD7
	waitmovement 0
	removeobject LOCALID_YOUNGSTER
	removeobject LOCALID_RANGER
	removeobject LOCALID_COOLTRAINER
	removeobject LOCALID_NURSE1
	removeobject LOCALID_HOST
	removeobject LOCALID_NURSE2
	removeobject LOCALID_ROSE
	setflag FLAG_HIDE_GREENDALE_VILLAGE_ROSE
	setflag FLAG_BADGE01_GET
	setvar VAR_STORYLINE_STATE, 12
	release
	end

GreendaleVillage_Sign::
	msgbox GreendaleVillage_Text_Sign, MSGBOX_SIGN
	end

GreendaleVillage_Sign_School::
	msgbox GreendaleVillage_Text_Sign_School, MSGBOX_SIGN
	end

GreendaleVillage_Sign_Park::
	msgbox GreendaleVillage_Text_Sign_Park, MSGBOX_SIGN
	end

GreendaleVillage_Old_Woman::
	msgbox GreendaleVillage_Text_Old_Woman, MSGBOX_NPC
	end

GreendaleVillage_Old_Man::
	msgbox GreendaleVillage_Text_Old_Man, MSGBOX_NPC
	end

GreendaleVillage_Woman::
	msgbox GreendaleVillage_Text_Woman, MSGBOX_NPC
	end

GreendaleVillage_Little_Boy::
	msgbox GreendaleVillage_Text_Little_Boy, MSGBOX_NPC
	end

GreendaleVillage_Little_Girl::
	msgbox GreendaleVillage_Text_Little_Girl, MSGBOX_NPC
	end

GreendaleVillage_Vendor::
	lock
	faceplayer
	goto_if_set FLAG_GREENDALE_VILLAGE_GREAT_BALL, GreendaleVillage_Vendor_Given
	msgbox GreendaleVillage_Text_Vendor, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_GREENDALE_VILLAGE_GREAT_BALL
	goto GreendaleVillage_Vendor_Given

GreendaleVillage_Vendor_Given::
	msgbox GreendaleVillage_Text_Vendor_Given, MSGBOX_DEFAULT
	release
	end

WURU:
	walk_up
	walk_right
	walk_up
	step_end

WUURFFU:
	walk_up
	walk_up
	walk_right
	follower_face_up
	step_end
	
WU2:
	walk_up
	walk_up
	step_end
	
WULU:
	walk_up
	walk_left
	walk_up
	step_end
	
WUULFFU:
	walk_up
	walk_up
	walk_left
	follower_face_up
	step_end
	
WR3FD:
	walk_right
	walk_right
	walk_right
	face_down
	step_end
	
WL3FR:
	walk_left
	walk_left
	walk_left
	face_right
	step_end
	
WR3UFL:
	walk_right
	walk_right
	walk_right
	walk_up
	face_left
	step_end
	
WUR4UFFL:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	follower_face_left
	step_end
	
WR2:
	walk_right
	walk_right
	step_end
	
RD6:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

WLD6:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
WUFL:
	walk_up
	face_left
	step_end
	
WUFFL:
	walk_up
	follower_face_left
	step_end
	
WL2FR:
	walk_left
	walk_left
	face_right
	step_end
	
WD6:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
WD2FR:
	walk_down
	walk_down
	face_right
	step_end
	
WU2FD:
	walk_up
	walk_up
	face_down
	step_end

WDL2UFFR:
	walk_down
	walk_left
	walk_left
	walk_up
	follower_face_right
	step_end
	
WDL3:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end
	
LFDWL:
	lock_facing_direction
	walk_slow_left
	unlock_facing_direction
	face_right
	step_end
	
WDRFUD16FD:
	walk_down
	walk_right
	face_up
	delay_16
	follower_face_down
	step_end
	
D16FD:
	delay_16
	face_down
	step_end
	
WD8:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
D16WLD7:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SpeakerName_Text_Nurse:
	.string "Nurse$"

SpeakerName_Text_AceTrainer:
	.string "Ace Trainer$"

SpeakerName_Text_BugCatcher:
	.string "Bug Catcher$"

SpeakerName_Text_Ranger:
	.string "Ranger$"
	
GreendaleVillage_Text_IAmVerySorry:
	.string "{COLOR}{RED}I am very sorry, everyone.\p"
	.string "Without a minimum of four Trainers,\n"
	.string "the Greendale Tournament cannot begin…$"

GreendaleVillage_Text_AwwThisIsntFair:
	.string "{COLOR}{BLUE}Aww! This isn't fair!\n"
	.string "I have been preparing a lot for this!$"

GreendaleVillage_Text_ThisMeansIWont:
	.string "{COLOR}{RED}This means that I won't be able to take\n"
	.string "part in the Rangers' Federation exam…$"

GreendaleVillage_Text_WaitATrainer:
	.string "{COLOR}{BLUE}Wait!\n"
	.string "A Trainer!!$"

GreendaleVillage_Text_HeyYou:
	.string "{COLOR}{BLUE}Hey, you!\n"
	.string "You're here for the tournament, right?\p"
	.string "Yes! Yes you are!\n"
	.string "Quickly! Come this way!$"

GreendaleVillage_Text_ThereHostWeHave:
	.string "{COLOR}{BLUE}There, Host!\n"
	.string "We have four participants!\l"
	.string "The Greendale Tournament can happen!$"

GreendaleVillage_Text_ErmWellWasnt:
	.string "{COLOR}{RED}Erm… Well wasn't that lucky…\n"
	.string "All right, then!\p"
	.string "The rules are simple.\p"
	.string "You will battle the Trainer standing\n"
	.string "opposite you.\p"
	.string "Whoever wins the battle will face the\n"
	.string "winner of the battle next to you!\p"
	.string "After each battle your Pokémon will be\n"
	.string "healed by the two nurses next to me.\p"
	.string "Whoever is the last person standing\n"
	.string "will go through to the final battle\l"
	.string "with our Greendale Champion!\p"
	.string "Does everyone understand?$"

GreendaleVillage_Text_WeUnderstand:
	.string "{COLOR}{BLUE}We understand!\n"
	.string "Get on with it!$"

GreendaleVillage_Text_AhaOkayEhem:
	.string "{COLOR}{RED}Aha… Ehem…\n"
	.string "Okay!\p"
	.string "Participants! Without further ado,\n"
	.string "step toward your opponent!$"

GreendaleVillage_Text_GoodLuckToEveryone:
	.string "{COLOR}{RED}Good luck to everyone!$"

GreendaleVillage_Text_IDidntSleep:
	.string "{COLOR}{BLUE}I didn't sleep last night in\n"
	.string "preparation for this moment!\p"
	.string "Here I come!$"

GreendaleVillage_Text_ThisTournamentIsStupid:
	.string "{COLOR}{BLUE}This tournament is stupid…\n"
	.string "I'm outta here!$"

GreendaleVillage_Text_PfftWhatAWimp:
	.string "{COLOR}{RED}Pfft… What a wimp.\n"
	.string "I'll return stronger next time!$"

GreendaleVillage_Text_AndThatsTheEnd:
	.string "{COLOR}{RED}…\n"
	.string "And that's the end of the first battle!\p"
	.string "We are now down to the last remaining\n"
	.string "participants!\p"
	.string "Nurses!\n"
	.string "Heal both Trainers!$"

GreendaleVillage_Text_ThatWasAGreatBattle:
	.string "{COLOR}{RED}That was a great battle.\n"
	.string "Let me heal your Pokémon for you.$"

GreendaleVillage_Text_GoodLuckInTheNext:
	.string "{COLOR}{RED}Good luck in the next round!$"

GreendaleVillage_Text_AllRightTrainers:
	.string "{COLOR}{RED}All right, Trainers! Are you ready?\n"
	.string "Let's get the next battle started!$"

GreendaleVillage_Text_ThatTrainerWasWeak:
	.string "{COLOR}{BLUE}That last Trainer was weak…\n"
	.string "I hope you're more of a challenge.$"

GreendaleVillage_Text_HahaWhatAWimp:
	.string "{COLOR}{BLUE}Haha, what a wimp!\n"
	.string "Not to worry - I will return stronger!$"

GreendaleVillage_Text_ImGoingToMoveUp:
	.string "{COLOR}{RED}I'm going to move up the ranks of the\n"
	.string "Rangers' Federation, starting now!$"

GreendaleVillage_Text_AndWeHaveAWinner:
	.string "{COLOR}{RED}And we have a winner!\p"
	.string "Congratulations, er, what's your name\n"
	.string "again?\p"
	.string "…\n"
	.string "…\p"
	.string "{PLAYER}!\n"
	.string "Congratulations!\p"
	.string "As the last Trainer standing, you will\n"
	.string "now face our Greendale Champion, Rose.\p"
	.string "Nurses! Heal {PLAYER}!$"

GreendaleVillage_Text_ItsAGoodThingWeHave:
	.string "{COLOR}{RED}It's a good thing we have a big supply\n"
	.string "of healing items, isn't it? Hehe.$"

GreendaleVillage_Text_ThereYouGoHoney:
	.string "{COLOR}{RED}There you go, honey.\n"
	.string "Good as new!$"

GreendaleVillage_Text_OkayPlayerAreYouReady:
	.string "{COLOR}{RED}Okay, {PLAYER},\n"
	.string "are you ready?\p"
	.string "I summon Rose to the stage!$"

GreendaleVillage_Text_Dots:
	.string "{COLOR}{RED}…$"

GreendaleVillage_Text_OhItsYouAgain:
	.string "{COLOR}{RED}Oh. It's you again.\n"
	.string "The kid from the forest.\p"
	.string "I was only in trouble because I didn't\n"
	.string "have my Pokémon with me, you know.\p"
	.string "Whatever.\n"
	.string "Let's get this over with.\p"
	.string "…\n"
	.string "…\p"
	.string "Move back?$"

GreendaleVillage_Text_OkayYouBeatMe:
	.string "{COLOR}{RED}Okay, you beat me.\n"
	.string "Fair and square.\p"
	.string "{PLAYER}, right?\p"
	.string "I'm Rose.\n"
	.string "Nice to meet you.\p"
	.string "…\n"
	.string "…\p"
	.string "Well, I'll see you around.$"

GreendaleVillage_Text_AndWeHaveANewChampion:
	.string "{COLOR}{RED}Annnddd we have a new Champion!\n"
	.string "{PLAYER} is the victor!$"

GreendaleVillage_Text_TheWayYouHandled:
	.string "{COLOR}{RED}The way you handled those battles was\n"
	.string "absolutely amazing!\p"
	.string "You are definitely one to watch!\n"
	.string "A fresh talent!\p"
	.string "Well, as the new Champion, please\n"
	.string "accept this award!$"

GreendaleVillage_Text_TeachThisHM:
	.string "{COLOR}{RED}Teach this HM to a Pokémon and it will\n"
	.string "be able to cut down small trees!\l"
	.string "Pretty nifty, right?$"

GreendaleVillage_Text_WellIDontKnow:
	.string "{COLOR}{RED}Well I don't know about the nurses, but\n"
	.string "I am exhausted after watching all of\l"
	.string "that battling!\p"
	.string "Take care, {PLAYER}.\n"
	.string "I'm sure we will meet again!$"

GreendaleVillage_Text_Sign:
	.string "Greendale Village\n"
	.string "{FONT_SMALL}“Our Scents Will Mesmerize Your Senses!”$"

GreendaleVillage_Text_Sign_School:
	.string "Greendale Village Trainer School$"

GreendaleVillage_Text_Sign_Park:
	.string "Greendale Village Park\n"
	.string "{FONT_SMALL}Thank you for not littering.$"

GreendaleVillage_Text_Old_Woman:
	.string "Life has always been the best living\n"
	.string "in this small village.\p"
	.string "I only wish I could see my grandson\n"
	.string "more often.\p"
	.string "He works as a Pokémon Researcher at\n"
	.string "the Government Offices in Union City.$"

GreendaleVillage_Text_Old_Man:
	.string "This is the real secret of life…\p"
	.string "To be completely engaged with what you\n"
	.string "are doing in the here and now.\p"
	.string "And instead of calling it work,\n"
	.string "realize it is play.$"

GreendaleVillage_Text_Woman:
	.string "{COLOR}{RED}My kids go to the Trainer School next\n"
	.string "door.\p"
	.string "I want them to become Trainers and\n"
	.string "spread their wings and fly!$"

GreendaleVillage_Text_Little_Boy:
	.string "{COLOR}{BLUE}Stranger… Help me catch her…\n"
	.string "Please!$"

GreendaleVillage_Text_Little_Girl:
	.string "{COLOR}{RED}You can't catch me!\n"
	.string "Hahaha!$"

GreendaleVillage_Text_Vendor:
	.string "{COLOR}{BLUE}We just finished stocking Great Balls\n"
	.string "inside our shop.\p"
	.string "Here's a free sample!$"

GreendaleVillage_Text_Vendor_Given:
	.string "{COLOR}{BLUE}Go inside our shop if you'd like to take\n"
	.string "a look at our wares!$"
