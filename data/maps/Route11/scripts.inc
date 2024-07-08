Route11_MapScripts::
	.byte 0

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

Route11_Text_Sign:
	.string "Route 11\n"
	.string "{LEFT_ARROW} Pinleaf Town$"

Route11_Text_Sign_Ernie:
	.string "Ernie's House$"

Route11_Text_Boy:
	.string "{COLOR}{BLUE}Me?\n"
	.string "I'm not a Trainer. But I wish I was.\p"
	.string "There are so many wild Pokémon out\n"
	.string "there that it's dangerous to be out\l"
	.string "here without one$"

Route11_Text_GreetingsTrainer:
	.string "{COLOR}{RED}Greetings, Trainer!\p"
	.string "I liked you the instant I saw you,\n"
	.string "so take this!$"

Route11_Text_BeSafeOutThere:
	.string "{COLOR}{RED}Be safe out there.\n"
	.string "You never know where evil lurks!$"

Route11_Text_Gloom:
	.string "Gloooom!$"

Route11_Text_Sign_Demo::
	.string "End of demo.$"
