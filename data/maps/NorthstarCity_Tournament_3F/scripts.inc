NorthstarCity_Tournament_3F_MapScripts::
	.byte 0
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

NorthstarCity_Tournament_3F_Text_Psychic:
	.string "Something very sinister is brewing in\n"
	.string "the horizon of the Tenjo region…\p"
	.string "You don't believe me?\p"
	.string "I suppose you do not sense it, like I\n"
	.string "do.$"

NorthstarCity_Tournament_3F_Text_Fat_Guy:
	.string "{COLOR}{BLUE}I work for the station's camera crew -\n"
	.string "couldn't find a better job even if I\l"
	.string "was the almighty President.\p"
	.string "I get paid to see hot Pokémon battles\n"
	.string "first-hand - how cool is that?!$"

NorthstarCity_Tournament_3F_Text_SUBO_Door:
	.string "{COLOR}{RED}Forget it, kid! I ain't movin'!\n"
	.string "Nope!\p"
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
