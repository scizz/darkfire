NorthstarCity_Tournament_1F_MapScripts::
	.byte 0

NorthstarCity_Tournament_1F_Woman::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Woman_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Woman, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Woman_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Woman_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Nerd::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Nerd_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Nerd, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Nerd_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Nerd_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Old_Man::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Old_Man_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Old_Man, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Old_Man_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Old_Man_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Receptionist_1::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Receptionist_1_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Receptionist_1, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Receptionist_1_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Receptionist_1_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Receptionist_2::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Receptionist_1_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Receptionist_2, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Man::
	msgbox NorthstarCity_Tournament_1F_Text_Man, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Little_Girl::
	msgbox NorthstarCity_Tournament_1F_Text_Little_Girl, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Text_Woman:
	.string "{COLOR}{RED}I just made it to the city in time for\n"
	.string "the tournament, but my Pokémon are\l"
	.string "battered from the journey through the\l"
	.string "mountains and ice.\p"
	.string "Oh, well. Even if we lose, the battle\n"
	.string "we went through will harden us up.$"

NorthstarCity_Tournament_1F_Text_Woman_Badge:
	.string "{COLOR}{RED}The SUBO hijacking the TV Station\n"
	.string "hardened up my Pokémon and I more than\l"
	.string "the challenge of the tournament…\p"
	.string "Saying that, though - I really\n"
	.string "hope I never cross paths with those\l"
	.string "terrible scoundrels again!$"

NorthstarCity_Tournament_1F_Text_Nerd:
	.string "{COLOR}{BLUE}Here for the tournament.\p"
	.string "What, me, battle?\n"
	.string "No way!\p"
	.string "I'm just here to watch.$"

NorthstarCity_Tournament_1F_Text_Nerd_Badge:
	.string "{COLOR}{BLUE}I'm glad I didn't take part in the\n"
	.string "tournament this year.\p"
	.string "Why, you ask?\p"
	.string "Because you would have wiped the floor\n"
	.string "with me!$"

NorthstarCity_Tournament_1F_Text_Old_Man:
	.string "I used to work here. Now I'm just here\n"
	.string "for the complementary Lemonade I get\l"
	.string "as part of my retirement plan.\l"
	.string "And to watch the tournament, yes…\p"
	.string "But mainly for the Lemonade!$"

NorthstarCity_Tournament_1F_Text_Old_Man_Badge:
	.string "Those SUBO scum that raided this place\n"
	.string "are lucky that I am an Old Man!\p"
	.string "When I was working here in the past, I\n"
	.string "was a lot fitter and stronger.\p"
	.string "I would have quickly taken care of the\n"
	.string "SUBO as soon as they came through the\l"
	.string "doors! Hrrmph!\p"
	.string "Time for a Lemonade break…$"

NorthstarCity_Tournament_1F_Text_Receptionist_1:
	.string "{COLOR}{RED}Welcome to the Northstar TV Station.\p"
	.string "If you bought a subscription for our\n"
	.string "online television program and somehow\l"
	.string "regretted it, we apologize. No refunds!$"

NorthstarCity_Tournament_1F_Text_Receptionist_1_Badge:
	.string "{COLOR}{RED}Welcome to the Northstar TV Station.\n"
	.string "Thank you for saving us from the SUBO!$"

NorthstarCity_Tournament_1F_Text_Receptionist_2:
	.string "{COLOR}{RED}Welcome to the Northstar TV Station.\n"
	.string "You are here for the tournament?\p"
	.string "Please, go to the top floor and\n"
	.string "inquire with our staff there.$"

NorthstarCity_Tournament_1F_Text_Man:
	.string "{COLOR}{BLUE}I'll get you all the Poké Balls you\n"
	.string "want, and help you catch Pokémon, too!$"

NorthstarCity_Tournament_1F_Text_Little_Girl:
	.string "{COLOR}{RED}Papa, will you get me a Poké Ball like\n"
	.string "the one in that cover?$"
