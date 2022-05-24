NorthstarCity_Tournament_2F_MapScripts::
	.byte 0

NorthstarCity_Tournament_2F_Girl_1::
	msgbox NorthstarCity_Tournament_2F_Text_Girl_1, MSGBOX_NPC
	end

NorthstarCity_Tournament_2F_Girl_2::
	msgbox NorthstarCity_Tournament_2F_Text_Girl_2, MSGBOX_NPC
	end

NorthstarCity_Tournament_2F_Camper::
	msgbox NorthstarCity_Tournament_2F_Text_Camper, MSGBOX_NPC
	end

NorthstarCity_Tournament_2F_Receptionist::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Receptionist_1_Badge
	msgbox NorthstarCity_Tournament_2F_Text_Receptionist, MSGBOX_NPC
	end

NorthstarCity_Tournament_2F_Little_Girl::
	msgbox NorthstarCity_Tournament_2F_Text_Little_Girl, MSGBOX_NPC
	end

NorthstarCity_Tournament_2F_SUBO::
	lockall
	faceplayer
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_NUGGET, NorthstarCity_Tournament_2F_SUBO_Given
	msgbox NorthstarCity_Tournament_2F_Text_SUBO, MSGBOX_DEFAULT
	giveitem ITEM_NUGGET, 1
	setflag FLAG_NORTHSTAR_TOURNAMENT_NUGGET
	closemessage
	goto NorthstarCity_Tournament_2F_SUBO_Given

NorthstarCity_Tournament_2F_SUBO_Given::
	msgbox NorthstarCity_Tournament_2F_Text_SUBO_Given, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Tournament_2F_Text_Girl_1:
	.string "{COLOR}{RED}It's thanks to the Northstar TV\n"
	.string "Station's special attention to\l"
	.string "Trainers that the viewers are glued to\l"
	.string "the screen.\p"
	.string "Everyone wants to become the next\n"
	.string "World Champion.\p"
	.string "It's ironic, really, because they can't\n"
	.string "get off the couch, also thanks to the\l"
	.string "TV Station.$"

NorthstarCity_Tournament_2F_Text_Girl_2:
	.string "{COLOR}{RED}The Northstar TV Station always\n"
	.string "broadcast interviews with the hottest\l"
	.string "Pokémon Trainers in the region!\p"
	.string "I am one of those inspired by their\n"
	.string "programmes and documentaries.$"

NorthstarCity_Tournament_2F_Text_Camper:
	.string "{COLOR}{BLUE}Alright, Kecleon.\p"
	.string "You remember our training?\n"
	.string "Let's do this!$"

NorthstarCity_Tournament_2F_Text_Receptionist:
	.string "{COLOR}{RED}We are accepting sign ups for the\n"
	.string "tournament at the top floor.$"

NorthstarCity_Tournament_2F_Text_Little_Girl:
	.string "{COLOR}{RED}I want to become a Pokémon Trainer and\n"
	.string "get into battles, too, when I'm older!$"

NorthstarCity_Tournament_2F_Text_SUBO:
	.string "{COLOR}{BLUE}Hello there!\n"
	.string "Welcome to the SUBO TV Station!\p"
	.string "At 4 P.M., we will be showcasing the\n"
	.string "best Underground Battles. Stay tuned!\l"
	.string "Hahahaha!$"

NorthstarCity_Tournament_2F_Text_SUBO_Given:
	.string "{COLOR}{BLUE}Found that trash under the desk!$"
