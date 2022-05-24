Route2_MapScripts::
	.byte 0

Route2_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_North_Sign::
	msgbox Route2_Text_North_Sign, MSGBOX_SIGN
	end

Route2_Boy::
	msgbox Route2_Text_Boy, MSGBOX_NPC
	end

Route2_Boy_Beginner::
	lock
	faceplayer
	msgbox Route2_Text_Boy_Beginner, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route2_Boy_Beginner_Yes
	msgbox Route2_Text_Boy_Beginner_No, MSGBOX_DEFAULT
	release
	end

Route2_Boy_Beginner_Yes::
	msgbox Route2_Text_Boy_Beginner_Yes, MSGBOX_DEFAULT
	release
	end

Route2_Old_Woman::
	msgbox Route2_Text_Old_Woman, MSGBOX_NPC
	end

Route2_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY_1, Route2_Text_JoeyIntro, Route2_Text_JoeyDefeated
	msgbox Route2_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route2_Text_TianaIntro, Route2_Text_TianaDefeated
	msgbox Route2_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY, Route2_Text_RickyIntro, Route2_Text_RickyDefeated
	msgbox Route2_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
	end

Route2_Text_Sign:
	.string "Route 2\n"
	.string "{RIGHT_ARROW} Sunrise Town$"

Route2_Text_North_Sign:
	.string "Route 2\n"
	.string "{UP_ARROW} Union City$"

Route2_Text_Boy:
	.string "{COLOR}{BLUE}Did you know that 386 Pokémon can be\n"
	.string "found and caught in the Tenjo region?$"

Route2_Text_Boy_Beginner:
	.string "{COLOR}{BLUE}Tenjo is an exotic region that holds\n"
	.string "many, many mysteries.\p"
	.string "It's perfect for Pokémon Trainers to\n"
	.string "journey in.\p"
	.string "Are you a beginner?$"

Route2_Text_Boy_Beginner_Yes:
	.string "{COLOR}{BLUE}Oh, you're a beginner? I envy you!\n"
	.string "To re-live what I've lived…\p"
	.string "Good luck out there!$"

Route2_Text_Boy_Beginner_No:
	.string "{COLOR}{BLUE}No? Oh, I envy beginners…\n"
	.string "To re-live what I've lived…\p"
	.string "Anyways…\n"
	.string "Good luck out there!$"

Route2_Text_Old_Woman:
	.string "A recent rock slide made it impossible\n"
	.string "for anyone to visit the Beach Grotto.\l"
	.string "I used to go there as a child…\p"
	.string "My loyal Machop could have smashed\n"
	.string "these rocks in no time, but he's no\l"
	.string "longer with me…$"
