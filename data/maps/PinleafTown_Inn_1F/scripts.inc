PinleafTown_Inn_1F_MapScripts::
	.byte 0

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

PinleafTown_Inn_1F_Text_Girl:
	.string "{COLOR}{RED}The fresh air here in the countryside\n"
	.string "is just something else.\p"
	.string "I may just quit as a Trainer and work\n"
	.string "here in the Flower Shop!$"

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
