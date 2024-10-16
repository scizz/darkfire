WaterwayCity_House7_MapScripts::
	.byte 0

WaterwayCity_House7_Text_Woman::
	msgbox WaterwayCity_House7_Text_Woman, MSGBOX_NPC
	end

WaterwayCity_House7_Text_LittleGirl::
	msgbox WaterwayCity_House7_Text_LittleGirl, MSGBOX_NPC
	end

WaterwayCity_House7_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_GIVEN_WATERWAY_CITY_DIVE_BALL, WaterwayCity_House7_FishermanGiven
	msgbox WaterwayCity_House7_Text_Fisherman, MSGBOX_AUTOCLOSE
	giveitem ITEM_DIVE_BALL, 1
	setflag FLAG_GIVEN_WATERWAY_CITY_DIVE_BALL
	goto WaterwayCity_House7_FishermanGiven
	end

WaterwayCity_House7_FishermanGiven::
	msgbox WaterwayCity_House7_Text_FishermanGiven, MSGBOX_AUTOCLOSE
	release
	end

WaterwayCity_House7_Text_Fisherman:
	.string "{COLOR}{BLUE}I used to fish in these streams every\n"
	.string "day with my trusty Poliwag.\p"
	.string "One time, we hooked a Gyarados, but I\n"
	.string "wasn't prepared!\p"
	.string "Ever since, I carry extra Dive Balls.\p"
	.string "Here, take one…$"

WaterwayCity_House7_Text_FishermanGiven:
	.string "{COLOR}{BLUE}Carry extra Poké Balls around with\n"
	.string "you, wherever you go.\p"
	.string "It's always good to be ready for the\n"
	.string "unexpected.$"

WaterwayCity_House7_Text_LittleGirl:
	.string "{COLOR}{RED}Shh…\n"
	.string "I'm studying Water-type Pokémon now!\p"
	.string "Did you know that some can live in\n"
	.string "both fresh and saltwater?$"

WaterwayCity_House7_Text_Woman:
	.string "{COLOR}{RED}Oh, my daughter?\p"
	.string "She's always got her nose in a book,\n"
	.string "studying everything about Pokémon.\p"
	.string "She says she wants to be a Pokémon\n"
	.string "Professor one day.$"
