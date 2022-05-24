Route5_MapScripts::
	.byte 0

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
	msgbox Route5_Text_Camper, MSGBOX_NPC
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

Route5_Text_Sign:
	.string "Route 5\n"
	.string "The Route of Legends$"

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
	.string "here - but maybe a young trainer like\l"
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
