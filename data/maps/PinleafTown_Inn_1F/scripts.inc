.set LOCALID_OLD_MAN, 4

PinleafTown_Inn_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PinleafTown_Inn_1F_OnTransition
	.byte 0

PinleafTown_Inn_1F_OnTransition:
	goto_if_set FLAG_PINLEAF_TOWN_INN_USED, PinleafTown_Inn_1F_MoveOldMan
	end

PinleafTown_Inn_1F_MoveOldMan::
	setobjectxyperm LOCALID_OLD_MAN, 2, 3
	end

PinleafTown_Inn_1F_Girl::
	msgbox PinleafTown_Inn_1F_Text_Girl, MSGBOX_NPC
	end

PinleafTown_Inn_1F_Man_1::
	goto_if_set FLAG_BADGE04_GET, PinleafTown_Inn_1F_Man_2
	msgbox PinleafTown_Inn_1F_Text_Man_1, MSGBOX_NPC
	end

PinleafTown_Inn_1F_Man_2::
	msgbox PinleafTown_Inn_1F_Text_Man_2, MSGBOX_NPC
	end

PinleafTown_Inn_1F_Old_Lady::
	msgbox PinleafTown_Inn_1F_Text_Old_Lady, MSGBOX_NPC
	end

PinleafTown_Inn_1F_Old_Man::
	lock
	faceplayer
	goto_if_set FLAG_PINLEAF_TOWN_INN_USED, PinleafTown_Inn_1F_Old_Man_After
	showmoneybox 0, 0
	msgbox WelcomeToOurInn, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq PinleafTown_Inn_1F_Old_Man_Yes
	compare VAR_RESULT, NO
	call_if_eq PinleafTown_Inn_1F_Old_Man_Yes
	applymovement LOCALID_OLD_MAN, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_OLD_MAN, Common_Movement_FaceDown
	waitmovement 0
	setflag FLAG_PINLEAF_TOWN_INN_USED
	setvar VAR_STORYLINE_STATE, 40
	release
	end

PinleafTown_Inn_1F_Old_Man_Yes::
	hidemoneybox
	msgbox WaitIRecogniseYou, MSGBOX_AUTOCLOSE
	return

PinleafTown_Inn_1F_Old_Man_After::
	msgbox FeelFreeToStay, MSGBOX_AUTOCLOSE
	release
	end

PinleafTown_Inn_1F_Text_Girl:
	.string "{COLOR}{RED}The fresh air here in the countryside\n"
	.string "is just something else.\p"
	.string "I may just quit as a Trainer and work\n"
	.string "in the Pinleaf Flower Shop!$"

PinleafTown_Inn_1F_Text_Man_1:
	.string "{COLOR}{BLUE}My luck is just the worst…\p"
	.string "I had to leave Farmond City in a hurry\n"
	.string "because SUBO took over the place.\p"
	.string "Now I'm stuck here in this Inn because\n"
	.string "the same thugs are blocking the road.\p"
	.string "Where is the Tenjo Police Department\n"
	.string "when you need them?!$"

PinleafTown_Inn_1F_Text_Man_2:
	.string "{COLOR}{BLUE}My luck is just the best!\p"
	.string "After getting pushed out of Farmond\n"
	.string "City, I realized this Inn is great!\p"
	.string "For this reason, I'm currently in the\n"
	.string "process of moving here to Pinleaf!$"

PinleafTown_Inn_1F_Text_Old_Lady:
	.string "The fact that there is no Pokémon\n"
	.string "Center in this town is what keeps my\l"
	.string "husband and I in business at this Inn.\p"
	.string "Interestingly enough, a Pokémon Center\n"
	.string "was planned to open some time ago…\p"
	.string "However, the loyal patrons in this\n"
	.string "town protested, and they sent a\l"
	.string "petition to the Tenjo Government.\p"
	.string "The petition prevented any\n"
	.string "developments from going ahead.$"

WelcomeToOurInn:
	.string "Hello there, welcome to our Inn.\p"
	.string "We've been housing dozens of people\n"
	.string "who are fleeing from the nearby city\l"
	.string "after it was taken over by SUBO.\p"
	.string "The good news is I can find you a\n"
	.string "place to stay, though!\p"
	.string "It's ¥20 for an overnight stay, with\n"
	.string "PC services.\p"
	.string "Shall I prepare a room for you?$"

WaitIRecogniseYou:
	.string "Wait…\n"
	.string "I recognize you! You're {PLAYER}!\p"
	.string "You thwarted the SUBO scum, right?\n"
	.string "Yes, yes you did!\l"
	.string "You're a national hero!\p"
	.string "Please, take a room free of charge.\n"
	.string "I insist!$"

FeelFreeToStay:
	.string "Feel free to stay as long as you like,\n"
	.string "{PLAYER}.$"
