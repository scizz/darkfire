.set LOCALID_RANGER, 3

RockfallCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RockfallCave_B1F_OnFrame
	.byte 0

RockfallCave_B1F_OnFrame:
	map_script_2 VAR_RANGER_EVENT_1, 3, RockfallCave_B1F_RangerEvent1Finish
	.2byte 0

RockfallCave_B1F_RangerEvent1Main::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 7, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	playmoncry SPECIES_CHARMANDER, 0
	waitmoncry
	msgbox RockfallCave_B1F_Text_TheRangersCharmanderUsedFlash, MSGBOX_DEFAULT
	playse SE_M_REFLECT
	animateflash 0
	setflashlevel 0
	closemessage
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox RockfallCave_B1F_Text_HowInTheWorld, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_RANGER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox RockfallCave_B1F_Text_OhTrainerYouMadeIt, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_RANGER, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox RockfallCave_B1F_Text_IWasJustInvestigating, MSGBOX_AUTOCLOSE
	hideface 1
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	playse SE_BANG
	special ShakeCamera
	waitse
	playse SE_BANG
	special ShakeCamera
	waitse
	applymovement LOCALID_RANGER, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox RockfallCave_B1F_Text_WaitDoYouHearThis, MSGBOX_AUTOCLOSE
	hideface 1
	playmoncry SPECIES_LARVITAR, 0
	waitmoncry
	applymovement LOCALID_RANGER, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement 7, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU2
	waitmovement 0
	playse SE_BANG
	special ShakeCamera
	waitse
	playmoncry SPECIES_LARVITAR, 0
	waitmoncry
	applymovement LOCALID_RANGER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox RockfallCave_B1F_Text_ItsALarvitar, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_CAMERA, WD2
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_RANGER, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_RANGER_EVENT_1, 2
	release
	end

RockfallCave_B1F_RangerEvent1Finish::
	lock
	applymovement LOCALID_RANGER, WU3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceDown
	waitmovement 0
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox RockfallCave_B1F_Text_GreatJobTrainer, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_RANGER, WD3RD2
	applymovement 7, DDWRDRD2
	waitmovement 0
	removeobject LOCALID_RANGER
	removeobject 7
	setflag FLAG_HIDE_ROCKFALL_CAVE_B1F_RANGER
	setvar VAR_RANGER_EVENT_1, 4
	release
	end

RockfallCave_B1F_Ranger::
	lock
	faceplayer
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox RockfallCave_B1F_Text_Ranger, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

RockfallCave_B1F_Larvitar::
	lockall
	playmoncry SPECIES_LARVITAR, 0
	speakername CommonName_Text_Larvitar
	msgbox RockfallCave_B1F_Text_Larvitar, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_LARVITAR, 15, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_LARVITAR, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject 4
	setflag FLAG_HIDE_ROCKFALL_CAVE_B1F_LARVITAR
	setvar VAR_RANGER_EVENT_1, 3
	fadescreen 0
	releaseall
	end

RockfallCave_B1F_Charmander::
	lock
	faceplayer
	playmoncry SPECIES_CHARMANDER, 0
	speakername CommonName_Text_Charmander
	msgbox RockfallCave_B1F_Text_Char, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

WD3RD2:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

DDWRDRD2:
	delay_16
	delay_16
	walk_right
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

RockfallCave_B1F_Text_HowInTheWorld:
	.string "{COLOR}{BLUE}How in the world did the rocks in\n"
	.string "this cave form like this?\p"
	.string "I've never seen anything like it…$"

RockfallCave_B1F_Text_OhTrainerYouMadeIt:
	.string "{COLOR}{BLUE}Oh, Trainer!\n"
	.string "You made it here!$"

RockfallCave_B1F_Text_IWasJustInvestigating:
	.string "{COLOR}{BLUE}I was just investigating these rocks\n"
	.string "here… Fascinating stuff, right?$"

RockfallCave_B1F_Text_WaitDoYouHearThis:
	.string "{COLOR}{BLUE}Wait - do you hear this?\p"
	.string "No, not the waterfall.\n"
	.string "It sounds like rocks are breaking…$"

RockfallCave_B1F_Text_ItsALarvitar:
	.string "{COLOR}{BLUE}It's a Larvitar!\n"
	.string "Go deal with it, Trainer!$"

RockfallCave_B1F_Text_Ranger:
	.string "{COLOR}{BLUE}Larvitar! Up ahead!\n"
	.string "Go and deal with it, Trainer!$"

RockfallCave_B1F_Text_Larvitar:
	.string "Graar!$"

RockfallCave_B1F_Text_GreatJobTrainer:
	.string "{COLOR}{BLUE}Great job, Trainer!\n"
	.string "You did good!\p"
	.string "It looks like the Larvitar was eating\n"
	.string "soil, like they usually do.\p"
	.string "This one ate much of the cave, by\n"
	.string "the looks of it!\p"
	.string "I bet that's how the rocks we jumped\n"
	.string "on earlier formed in the first place.\p"
	.string "Anyway, thank you kindly for your\n"
	.string "service, Trainer.\p"
	.string "I'll report back to the Rangers'\n"
	.string "Fedaration now the problem is solved!$"

RockfallCave_B1F_Text_TheRangersCharmanderUsedFlash:
	.string "The Ranger's Charmander used Flash…$"

RockfallCave_B1F_Text_Char:
	.string "Char!$"
