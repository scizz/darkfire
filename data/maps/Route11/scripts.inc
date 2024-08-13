Route11_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route11_OnFrame
	.byte 0

Route11_OnFrame:
	map_script_2 VAR_ERNIE_STATE, 2, Route11_EndOfBeta
	.2byte 0

Route11_EndOfBeta::
	lock
	msgbox Route11_Text_Sign_Demo, MSGBOX_AUTOCLOSE
	setvar VAR_ERNIE_STATE, 3
	release
	end

Route11_Sign::
	msgbox Route11_Text_Sign, MSGBOX_SIGN
	end

Route11_Sign_Ernie::
	msgbox Route11_Text_Sign_Ernie, MSGBOX_SIGN
	end

Route11_Sign_Demo::
	msgbox Route11_Text_Sign_Demo, MSGBOX_SIGN
	end

Route11_Boy::
	msgbox Route11_Text_Boy, MSGBOX_NPC
	end

Route11_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, Route11_Text_CedricIntro, Route11_Text_CedricDefeated
	msgbox Route11_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route11_Text_DaisyIntro, Route11_Text_DaisyDefeated
	msgbox Route11_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route11_Text_JasmineIntro, Route11_Text_JasmineDefeated
	msgbox Route11_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Safeguard::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_11_SAFEGUARD_GIVEN, Route11_SafeguardGiven
	msgbox Route11_Text_GreetingsTrainer, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM20, 1
	goto Route11_SafeguardGiven
	end

Route11_SafeguardGiven::
	msgbox Route11_Text_BeSafeOutThere, MSGBOX_AUTOCLOSE
	setflag FLAG_ROUTE_11_SAFEGUARD_GIVEN
	release
	end

Route11_Gloom::
	lock
	pokemonfaceplayer 2
	playmoncry SPECIES_GLOOM, 0
	speakername CommonName_Text_Gloom
	msgbox Route11_Text_Gloom, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	emote 2 6
	playse SE_PIN
	waitse
	release
	end

Route11_Ernie::
	lock
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	playse SE_BANG
	special ShakeCamera
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 10
	playse SE_PIN
	emote OBJ_EVENT_ID_PLAYER, 8
	waitse
	delay 30
	msgbox WhatWasThat, MSGBOX_AUTOCLOSE
	setvar VAR_ERNIE_STATE, 1
	release
	end

Route11_Text_Sign:
	.string "Route 11\n"
	.string "{RIGHT_ARROW} Pinleaf Town$"

Route11_Text_Sign_Ernie:
	.string "Ernie's House$"

Route11_Text_Boy:
	.string "{COLOR}{BLUE}Me?\n"
	.string "I'm not a Trainer. But I wish I was.\p"
	.string "There are so many wild Pokémon out\n"
	.string "there, that it's dangerous to be out\l"
	.string "here without one.$"

Route11_Text_GreetingsTrainer:
	.string "{COLOR}{RED}Greetings, Trainer!\p"
	.string "I liked you the instant I saw you,\n"
	.string "so take this!$"

Route11_Text_BeSafeOutThere:
	.string "{COLOR}{RED}Be safe out there.\n"
	.string "You never know where evil lurks!$"

Route11_Text_Gloom:
	.string "Gloooom!$"

Route11_Text_Sign_Demo:
	.string "You have reached the end of Pokémon\n"
	.string "Darkfire Beta 0.2.1…\p"
	.string "Thank you, {PLAYER}, for\n"
	.string "playing our game!\p"
	.string "Rest assured, Beta 0.3.0 is already in\n"
	.string "development, so stay tuned for more!\p"
	.string "You can follow our progress on Discord:\n"
	.string "discord.gg/3JSSNbw (case sensitive)\l"
	.string "See you there! - Karl & Ray$"

WhatWasThat:
	.string "???\n"
	.string "What was that?\p"
	.string "It came from inside the house!$"
