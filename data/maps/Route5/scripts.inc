.set LOCALID_SUBO_1, 10 @ Paul
.set LOCALID_SUBO_2, 11 @ George

Route5_MapScripts::
	.byte 0

Route5_SUBO::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	delay 10
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0
	msgbox Route5_Text_LookGeorge, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_DontSaySuchThings, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_SUBO_1, Common_Movement_FaceDown
	applymovement LOCALID_SUBO_2, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_ExclamationMark
	applymovement LOCALID_SUBO_2, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0
	msgbox Route5_Text_HeyYou, MSGBOX_AUTOCLOSE
	hideface 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 17
	goto_if_eq Route5_SUBO_Left
	goto Route5_SUBO_Right
	end

Route5_SUBO_Left::
	applymovement LOCALID_SUBO_1, WD2
	applymovement LOCALID_SUBO_2, WD3FL
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	playbgm MUS_SUBO_THEME, TRUE
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_YoureATrainer, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	msgbox Route5_Text_DotDotDot, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_WhatsTheMatter, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_IThinkWeAreGeorge, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_SUBO_1, Common_Movement_FaceDown
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_IsThatTrueGeorge, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_NoDontWorryGeorge, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_2, WURFL
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_YouThinkYouGeorge, MSGBOX_AUTOCLOSE
	hideface 0
	trainerbattle_no_intro TRAINER_SUBO_THUG_PAUL, SuboThugPaul_Text_Defeated
	applymovement LOCALID_SUBO_1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_ThisOneIsStrongGeorge, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_SUBO_2, WFL
	waitmovement 0
	applymovement LOCALID_SUBO_1, FLJSLFR
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_WalkLeft
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_GrrGetTheHeckGeorge, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_IllShowYouGeorge, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_SUBO_THUG_GEORGE, SuboThugGeorge_Text_Defeated
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_ScrewThis, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_2, WFU5
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_FaceUp
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_HeyGeorgeWait, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_YouWontGetAway, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_1, WFU5
	waitmovement 0
	removeobject LOCALID_SUBO_1
	removeobject LOCALID_SUBO_2
	setvar VAR_STORYLINE_STATE, 16
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

Route5_SUBO_Right::
	applymovement LOCALID_SUBO_2, WD2
	applymovement LOCALID_SUBO_1, WD3FR
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	playbgm MUS_SUBO_THEME, TRUE
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_YoureATrainer, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	msgbox Route5_Text_DotDotDot, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_WhatsTheMatter, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_IThinkWeArePaul, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_SUBO_2, Common_Movement_FaceDown
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_IsThatTruePaul, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_NoDontWorryPaul, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_1, WULFR
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_YouThinkYouPaul, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_SUBO_THUG_GEORGE, SuboThugGeorge_Text_Defeated
	applymovement LOCALID_SUBO_2, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	delay 10
	applymovement LOCALID_SUBO_1, WFR
	waitmovement 0
	applymovement LOCALID_SUBO_2, FRJSRFL
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkRight
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	hideface 1
	msgbox Route5_Text_ThisOneIsStrongGeorge, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_GrrGetTheHeckPaul, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_IllShowYouPaul, MSGBOX_AUTOCLOSE
	hideface 0
	trainerbattle_no_intro TRAINER_SUBO_THUG_PAUL, SuboThugPaul_Text_Defeated
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_George
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1 
	msgbox Route5_Text_ScrewThis, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_2, WFULU4
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_FaceUp
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_HeyGeorgeWait, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement LOCALID_SUBO_1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_Paul
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0 
	msgbox Route5_Text_YouWontGetAway, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_1, WFU5
	waitmovement 0
	removeobject LOCALID_SUBO_1
	removeobject LOCALID_SUBO_2
	setvar VAR_STORYLINE_STATE, 16
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

Route5_Sign::
	msgbox Route5_Text_Sign, MSGBOX_SIGN
	end

Route5_Sign_Myth::
	msgbox Route5_Text_Myth, MSGBOX_SIGN
	end

Route5_Sign_Myth_2::
	msgbox Route5_Text_Myth_2, MSGBOX_SIGN
	end

Route5_Sign_Rocks::
	msgbox Route5_Text_Rocks, MSGBOX_SIGN
	end

Route5_Woman::
	msgbox Route5_Text_Woman, MSGBOX_NPC
	end

Route5_Boy::
	msgbox Route5_Text_Boy, MSGBOX_NPC
	end

Route5_Girl::
	msgbox Route5_Text_Girl, MSGBOX_NPC
	end

Route5_Camper::
	lock
	faceplayer
	msgbox Route5_Text_Camper, MSGBOX_AUTOCLOSE
	applymovement 2, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Route5_EventScript_Pete::
	trainerbattle_single TRAINER_PETE_1, Route5_Text_PeteIntro, Route5_Text_PeteDefeated
	msgbox Route5_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Liana::
	trainerbattle_single TRAINER_LIANA, Route5_Text_LianaIntro, Route5_Text_LianaDefeated
	msgbox Route5_Text_LianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN, Route5_Text_EthanIntro, Route5_Text_EthanDefeated
	msgbox Route5_Text_EthanPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, Route5_Text_MarcIntro, Route5_Text_MarcDefeated
	msgbox Route5_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Trev::
	trainerbattle_single TRAINER_TREV, Route5_Text_TrevIntro, Route5_Text_TrevDefeated
	msgbox Route5_Text_TrevPostBattle, MSGBOX_AUTOCLOSE
	end

WURFL:
	walk_up
	walk_right
	face_left
	step_end

WD3FL:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

WFL:
	walk_faster_left
	step_end

FLJSLFR:
	face_left
	jump_special_left
	face_right
	step_end

WULFR:
	walk_up
	walk_left
	face_right
	step_end

WD3FR:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

WFR:
	walk_faster_right
	step_end

FRJSRFL:
	face_right
	jump_special_right
	face_left
	step_end

WFULU4:
	walk_faster_up
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

SpeakerName_Text_George:
	.string "George$"

SpeakerName_Text_Paul:
	.string "Paul$"

Route5_Text_Sign:
	.string "Route 5\n"
	.string "{FONT_SMALL}“The Path of Legends”$"

Route5_Text_Myth:
	.string "The one destin'd to awaken the\n"
	.string "sleeping Pokémon, heareth this…\p"
	.string "Who is't can navigateth termagant\n"
	.string "wat'rfalls liketh halcyon staircases.$"

Route5_Text_Myth_2:
	.string "Oh, bird of mine own soul, flyeth\n"
	.string "hence anon…$"

Route5_Text_Rocks:
	.string "Please do not play on the rocks!$"

Route5_Text_Woman:
	.string "{COLOR}{RED}It takes tremendous courage to face\n"
	.string "the coming challenges.\l"
	.string "The journey will be long and tough.\p"
	.string "I don't have what it takes to go past\n"
	.string "here - but maybe a young Trainer like\l"
	.string "you does.\p"
	.string "Best of luck!$"

Route5_Text_Boy:
	.string "{COLOR}{BLUE}We're pretty far from the big city\n"
	.string "here, so when it's dark, the whole\l"
	.string "glory of the night sky reveals itself.\p"
	.string "I'm here every night to see the stars!$"

Route5_Text_Girl:
	.string "{COLOR}{RED}My father is very welcoming and\n"
	.string "caring.\p"
	.string "Go inside and have a word with him if\n"
	.string "you're tired - he'll let you rest.$"

Route5_Text_Camper:
	.string "{COLOR}{BLUE}I always have my eye on that cave, but\n"
	.string "I can't yet find a path to get there…$"

Route5_Text_LookGeorge:
	.string "{COLOR}{BLUE}Look, George… All I'm saying is these\n"
	.string "stone tablets are old.\l"
	.string "They probably don't even work anymore.$"

Route5_Text_DontSaySuchThings:
	.string "Don't say such things, Paul.\p"
	.string "Everyone knows that whoever solves the\n"
	.string "puzzle will be granted eternal wisdom!$"

Route5_Text_HeyYou:
	.string "Hey, you!$"

Route5_Text_YoureATrainer:
	.string "You're a Trainer, right?\p"
	.string "What do you know about the stone\n"
	.string "tablets in this route?$"

Route5_Text_DotDotDot:
	.string "…$"

Route5_Text_WhatsTheMatter:
	.string "What's the matter, kid?\n"
	.string "Has Meowth caught your tongue?$"

Route5_Text_IThinkWeAreGeorge:
	.string "{COLOR}{BLUE}I think we are being mocked, George…$"

Route5_Text_IsThatTrueGeorge:
	.string "Is that true, kid? Are you mocking us?\n"
	.string "You think this is a game?\p"
	.string "Very well, then…\n"
	.string "We will settle this with a battle!$"

Route5_Text_NoDontWorryGeorge:
	.string "{COLOR}{BLUE}No. Don't worry, George.\n"
	.string "I will handle it myself.$"

Route5_Text_YouThinkYouGeorge:
	.string "{COLOR}{BLUE}You think you can make fun of us?\n"
	.string "Not on my watch! Let's go, punk!$"

Route5_Text_ThisOneIsStrongGeorge:
	.string "{COLOR}{BLUE}Th-this one is strong!$"

Route5_Text_GrrGetTheHeckGeorge:
	.string "Grr… Get the heck out of my way!$"

Route5_Text_IllShowYouGeorge:
	.string "I'll show you what a real battle is!$"

Route5_Text_ScrewThis:
	.string "{COLOR}{BLUE}Screw this… I'm outta here!$"

Route5_Text_HeyPaulWait:
	.string "Hey! Paul! Wait for me!$"

Route5_Text_HeyGeorgeWait:
	.string "Hey! George! Wait for me!$"

Route5_Text_YouWontGetAway:
	.string "You won't get away with this, kid!\n"
	.string "You won't be so lucky next time!$"

Route5_Text_IThinkWeArePaul:
	.string "I think we are being mocked, Paul…$"

Route5_Text_IsThatTruePaul:
	.string "{COLOR}{BLUE}Is that true, kid? Are you mocking us?\n"
	.string "You think this is a game?\p"
	.string "Very well, then…\n"
	.string "We will settle this with a battle!$"

Route5_Text_NoDontWorryPaul:
	.string "No. Don't worry, Paul\n"
	.string "I will handle him myself.$"

Route5_Text_YouThinkYouPaul:
	.string "You think you can make fun of us?\n"
	.string "Not on my watch! Let's go, punk!$"

Route5_Text_ThisOneIsStrongPaul:
	.string "Th-this one is strong!$"

Route5_Text_GrrGetTheHeckPaul:
	.string "{COLOR}{BLUE}Grr… Get the heck out of my way!$"

Route5_Text_IllShowYouPaul:
	.string "{COLOR}{BLUE}I'll show you what a real battle is!$"
