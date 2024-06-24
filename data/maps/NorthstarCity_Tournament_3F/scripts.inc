.set LOCALID_ROSE, 4
.set LOCALID_SUBO, 7
.set LOCALID_RAKAZ, 8
.set LOCALID_DIRECTOR, 9

NorthstarCity_Tournament_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NorthstarCity_Tournament_3F_OnTransition
	.byte 0

NorthstarCity_Tournament_3F_OnTransition:
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_SUBO, NorthstarCity_Tournament_3F_MoveRose
	end

NorthstarCity_Tournament_3F_MoveRose::
	goto_if_unset FLAG_NORTHSTAR_TOURNAMENT_SUBO_2F, NorthstarCity_Tournament_3F_MoveRose2
	end

NorthstarCity_Tournament_3F_MoveRose2::
	setobjectxyperm LOCALID_ROSE, 1, 10
	end

NorthstarCity_Tournament_3F_Psychic::
	msgbox NorthstarCity_Tournament_3F_Text_Psychic, MSGBOX_NPC
	end

NorthstarCity_Tournament_3F_Fat_Guy::
	msgbox NorthstarCity_Tournament_3F_Text_Fat_Guy, MSGBOX_NPC
	end

NorthstarCity_Tournament_3F_SUBO_Door::
	msgbox NorthstarCity_Tournament_3F_Text_SUBO_Door, MSGBOX_NPC
	end

NorthstarCity_Tournament_3F_Hide4FObjects::
	lock
	setflag FLAG_NORTHSTAR_TOURNAMENT_ENTRANCE
	setflag FLAG_NORTHSTAR_TOURNAMENT_OLD_MAN
	setflag FLAG_NORTHSTAR_TOURNAMENT_BLACK_BELT
	setflag FLAG_NORTHSTAR_TOURNAMENT_ACE_TRAINER
	setflag FLAG_NORTHSTAR_TOURNAMENT_SAILOR
	setflag FLAG_NORTHSTAR_TOURNAMENT_POKE_BALL
	setvar VAR_STORYLINE_STATE, 1
	release
	end

NorthstarCity_Tournament_3F_SUBOBattle::
	lock
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WD3
	waitmovement 0
	playbgm MUS_SUBO_THEME, TRUE
	applymovement LOCALID_RAKAZ, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Rakaz
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_GiveItUp, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_SUBO, Common_Movement_FaceUp
	waitmovement 0
	emote LOCALID_SUBO, 7
	playse SE_PIN
	waitse
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq NorthstarCity_Tournament_3F_SUBOBattle_Male
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_BossShesHere, MSGBOX_AUTOCLOSE
	hideface 1
	goto NorthstarCity_Tournament_3F_SUBOBattleNext
	end

NorthstarCity_Tournament_3F_SUBOBattle_Male::
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_BossHesHere, MSGBOX_AUTOCLOSE
	hideface 1
	goto NorthstarCity_Tournament_3F_SUBOBattleNext
	end

NorthstarCity_Tournament_3F_SUBOBattleNext::
	applymovement LOCALID_RAKAZ, Common_Movement_FaceUp
	waitmovement 0
	emote LOCALID_RAKAZ, 8
	playse SE_PIN
	waitse
	applymovement LOCALID_RAKAZ, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Rakaz
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_WhatInTheWorld, MSGBOX_AUTOCLOSE
	hideface 1
	emote LOCALID_DIRECTOR, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_DIRECTOR, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername2 CommonName_Text_Director
	showface FS_DIRECTOR, FSE_NORMAL, 0, 0
	msgbox NorthstarCity_Tournament_3F_Text_PlayerYourNameIsPlayer, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUpFast
	applymovement LOCALID_SUBO, Common_Movement_WalkUpFast
	waitmovement 0
	applymovement LOCALID_SUBO, Common_Movement_WalkInPlaceUp
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_ThisIsIt, MSGBOX_AUTOCLOSE
	hideface 1
	clearflag FLAG_NORTHSTAR_TOURNAMENT_ROSE
	addobject LOCALID_ROSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 3
	goto_if_eq NorthstarCity_Tournament_3F_SUBOBattleNextLeft
	goto NorthstarCity_Tournament_3F_SUBOBattleNextRight
	end

NorthstarCity_Tournament_3F_SUBOBattleNextLeft::
	applymovement LOCALID_ROSE, WFL8D2
	waitmovement 0
	applymovement LOCALID_ROSE, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	goto NorthstarCity_Tournament_3F_SUBORoseBattle
	end

NorthstarCity_Tournament_3F_SUBOBattleNextRight::
	applymovement LOCALID_ROSE, WFL9D2
	waitmovement 0
	applymovement LOCALID_ROSE, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	goto NorthstarCity_Tournament_3F_SUBORoseBattle
	end

NorthstarCity_Tournament_3F_SUBORoseBattle::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq NorthstarCity_Tournament_3F_SUBORoseBattle_Male
	goto NorthstarCity_Tournament_3F_SUBORoseBattle_Female
	end

NorthstarCity_Tournament_3F_SUBORoseBattle_Male::
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_ANGRY, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_HeIsNotAlone, MSGBOX_AUTOCLOSE
	hideface 1
	goto NorthstarCity_Tournament_3F_SUBORoseBattle_Begin
	end

NorthstarCity_Tournament_3F_SUBORoseBattle_Female::
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_ANGRY, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_SheIsNotAlone, MSGBOX_AUTOCLOSE
	hideface 1
	goto NorthstarCity_Tournament_3F_SUBORoseBattle_Begin
	end

NorthstarCity_Tournament_3F_SUBORoseBattle_Begin::
	emote LOCALID_RAKAZ, 5
	playse SE_PIN
	waitse
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_RAKAZ, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RAKAZ, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Rakaz
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_ICanHardlyBelieve, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO, Common_Movement_WalkUpFast
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUpFast
	applymovement LOCALID_RAKAZ, Common_Movement_WalkUpFast
	applymovement LOCALID_ROSE, Common_Movement_WalkDownFast
	waitmovement 0
	special RemoveCameraObject
	trainerbattle_no_intro TRAINER_SUBO_THUG_RYAN, SuboThugRyan_Text_Defeated
	playbgm MUS_SUBO_THEME, TRUE
	emote LOCALID_ROSE, 5
	playse SE_PIN
	waitse
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_HowDidILose, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_RAKAZ, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Rakaz
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_HehYoureAnIdiot, MSGBOX_AUTOCLOSE
	hideface 1
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 3
	goto_if_eq NorthstarCity_Tournament_3F_SUBOBattleNextLeftRakaz
	goto NorthstarCity_Tournament_3F_SUBOBattleNextRightRakaz
	end

NorthstarCity_Tournament_3F_SUBOBattleNextLeftRakaz::
	applymovement LOCALID_RAKAZ, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	goto NorthstarCity_Tournament_3F_RakazDepart
	end

NorthstarCity_Tournament_3F_SUBOBattleNextRightRakaz::
	applymovement LOCALID_RAKAZ, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	goto NorthstarCity_Tournament_3F_RakazDepart
	end

NorthstarCity_Tournament_3F_RakazDepart::
	speakername CommonName_Text_Rakaz
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_AndYouPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	fadescreen 1
	removeobject LOCALID_SUBO
	removeobject LOCALID_RAKAZ
	removeobject 2
	removeobject 3
	removeobject 6
	setflag FLAG_NORTHSTAR_TOURNAMENT_SUBO
	applymovement LOCALID_ROSE, WLFU
	waitmovement 0
	delay 60
	fadescreen 0
	applymovement LOCALID_ROSE, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_PlayerIAmGoingToStay, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_ROSE, WDL2FD
	waitmovement 0
	setobjectxyperm LOCALID_ROSE, 1, 10
	setvar VAR_STORYLINE_STATE, 9
	release
	end

NorthstarCity_Tournament_3F_Rose::
	lock
	faceplayer
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_PlayerIAmGoingToStay, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_ROSE, Common_Movement_FaceDown
	waitmovement 0
	release
	end

NorthstarCity_Tournament_3F_Director::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_3F_DirectorB3
	speakername CommonName_Text_Director
	showface FS_DIRECTOR, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_WelcomeTrainer, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

NorthstarCity_Tournament_3F_DirectorB3::
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_SUBO_2F, NorthstarCity_Tournament_3F_DirectorB3D
	speakername CommonName_Text_Director
	showface FS_DIRECTOR, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_PlayerPleaseGetTheseThugs, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

NorthstarCity_Tournament_3F_DirectorB3D::
	speakername CommonName_Text_Director
	showface FS_DIRECTOR, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_3F_Text_PlayerItIsGoodToSeeYou, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

NorthstarCity_Tournament_3F_Reiss::
	trainerbattle_single TRAINER_SUBO_THUG_REISS, NorthstarTournament3F_Text_ReissIntro, NorthstarTournament3F_Text_ReissDefeated
	msgbox NorthstarTournament3F_Text_ReissPostBattle, MSGBOX_AUTOCLOSE
	end

NorthstarCity_Tournament_3F_Lei::
	trainerbattle_single TRAINER_SUBO_THUG_LEI, NorthstarTournament3F_Text_LeiIntro, NorthstarTournament3F_Text_LeiDefeated
	msgbox NorthstarTournament3F_Text_LeiPostBattle, MSGBOX_AUTOCLOSE
	end

WFL8D2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

WFL9D2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

WDL2FD:
	walk_down
	walk_left
	walk_left
	face_down
	step_end

NorthstarCity_Tournament_3F_Text_Psychic:
	.string "Something very sinister is brewing in\n"
	.string "the horizon of the Tenjo region…\p"
	.string "You don't believe me?\p"
	.string "I suppose you do not sense it, like I\n"
	.string "do…$"

NorthstarCity_Tournament_3F_Text_Fat_Guy:
	.string "{COLOR}{BLUE}I work for the station's camera crew.\p"
	.string "Couldn't find a better job even if I\n"
	.string "was the almighty President.\p"
	.string "I get paid to see hot Pokémon battles\n"
	.string "first-hand! How cool is that?!$"

NorthstarCity_Tournament_3F_Text_SUBO_Door:
	.string "{COLOR}{RED}Forget it, kid! I ain't movin'!\n"
	.string "Nope!\l"
	.string "You ain't getting out of this one!$"

NorthstarCity_Tournament_3F_Text_WelcomeTrainer:
	.string "Welcome, Trainer, to the Northstar TV\n"
	.string "Station.\p"
	.string "I know you are here for the tournament.\n"
	.string "I can see it in your eyes!\l"
	.string "I was a Trainer, once, as well.\p"
	.string "Go upstairs and talk to the staff\n"
	.string "there to sign up.\p"
	.string "Will you be the most impressive\n"
	.string "candidate?\l"
	.string "Good luck!$"

NorthstarCity_Tournament_3F_Text_PlayerPleaseGetTheseThugs:
	.string "{PLAYER}!\n"
	.string "Please get these thugs out of here!$"

NorthstarCity_Tournament_3F_Text_PlayerItIsGoodToSeeYou:
	.string "{PLAYER}!\n"
	.string "It is good to see you.\p"
	.string "Thank you so much for getting rid of\n"
	.string "the SUBO from my beloved station.\p"
	.string "The city thanks you!$"

NorthstarCity_Tournament_3F_Text_GiveItUp:
	.string "Give it up, Mr. Director!\p"
	.string "Either join our side or we will burn\n"
	.string "this place to the ground!\l"
	.string "The choice is yours!$"

NorthstarCity_Tournament_3F_Text_BossShesHere:
	.string "{COLOR}{BLUE}Boss!\n"
	.string "She's here!$"

NorthstarCity_Tournament_3F_Text_BossHesHere:
	.string "{COLOR}{BLUE}Boss!\n"
	.string "He's here!$"

NorthstarCity_Tournament_3F_Text_WhatInTheWorld:
	.string "What in the world have the others\n"
	.string "been doing?!\p"
	.string "…\p"
	.string "Ah, forget it.\p"
	.string "You should've left the premises,\n"
	.string "{PLAYER}.\p"
	.string "This can get rather perilous for\n"
	.string "wannabe champions of the law.$"

NorthstarCity_Tournament_3F_Text_PlayerYourNameIsPlayer:
	.string "{PLAYER}!\p"
	.string "Help me ward off these villains!\p"
	.string "They say they want the TV Station to\n"
	.string "broadcast content only favorable to\l"
	.string "the SUBO!$"

NorthstarCity_Tournament_3F_Text_ThisIsIt:
	.string "{COLOR}{BLUE}This is it, I'm fed up with this\n"
	.string "meddling scum.\p"
	.string "We can't be seen havin' any more\n"
	.string "trouble with just a single kid around!$"

NorthstarCity_Tournament_3F_Text_HeIsNotAlone:
	.string "{COLOR}{RED}He is not alone!\p"
	.string "Come on… Rakaz was your name, right?\n"
	.string "Bring it on!$"

NorthstarCity_Tournament_3F_Text_SheIsNotAlone:
	.string "{COLOR}{RED}She is not alone!\p"
	.string "Come on… Rakaz was your name, right?\n"
	.string "Bring it on!$"

NorthstarCity_Tournament_3F_Text_ICanHardlyBelieve:
	.string "I can hardly believe it's come up to\n"
	.string "this point…\p"
	.string "Fine.\p"
	.string "You leave me no choice but to introduce\n"
	.string "some real pain in your lives…$"

NorthstarCity_Tournament_3F_Text_HowDidILose:
	.string "{COLOR}{RED}Rose: H-how did I lose…$"

NorthstarCity_Tournament_3F_Text_HehYoureAnIdiot:
	.string "Heh…\n"
	.string "You're an idiot.\p"
	.string "That Zangoose would be much better\n"
	.string "suited fighting for the SUBO.$"

NorthstarCity_Tournament_3F_Text_AndYouPlayer:
	.string "And you, {PLAYER}…\p"
	.string "You can count yourself lucky that you\n"
	.string "didn't have to fight me today.\p"
	.string "Don't worry.\p"
	.string "The SUBO have other plans for you.\n"
	.string "You will see…$"

NorthstarCity_Tournament_3F_Text_PlayerIAmGoingToStay:
	.string "{COLOR}{RED}{PLAYER}.\p"
	.string "I am going to stay here with the\nDirector.\p"
	.string "It's up to you to clear the rest.$"

NorthstarCity_Tournament_3F_Text_YouveGotThis:
	.string "{COLOR}{RED}You've got this, {PLAYER}.\p"
	.string "Don't worry…\n"
	.string "I won't let anyone get to the Director.$"
