AnheimTown_House3_MapScripts::
	.byte 0

AnheimTown_House3_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ANHEIM_TOWN_TEA, AnheimTown_House3_Woman_Received
	msgbox AnheimTown_House3_Text_Woman, MSGBOX_AUTOCLOSE
	giveitem ITEM_TEA, 1
	setflag FLAG_RECEIVED_ANHEIM_TOWN_TEA
	goto AnheimTown_House3_Woman_Received
	end

AnheimTown_House3_Woman_Received::
	msgbox AnheimTown_House3_Text_WomanGiven, MSGBOX_AUTOCLOSE
	release
	end

AnheimTown_House3_Girl::
	msgbox AnheimTown_House3_Text_Girl, MSGBOX_NPC
	end

AnheimTown_House3_Hiker::
	msgbox AnheimTown_House3_Text_Hiker, MSGBOX_NPC
	end

AnheimTown_House3_Text_Woman:
	.string "{COLOR}{RED}Hello, weary traveler!\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Yes.\n"
	.string "I see the fatigue in your eyes…\p"
	.string "Before you continue your journey,\n"
	.string "let me offer you a small token…$"

AnheimTown_House3_Text_WomanGiven:
	.string "{COLOR}{RED}Feel free to stay and share your tales\n"
	.string "of adventure or enjoy the serenity.\p"
	.string "I've always believed that the best\n"
	.string "stories are shared over a cup of tea.$"

AnheimTown_House3_Text_Girl:
	.string "{COLOR}{RED}Weary Trainers come here to rest and\n"
	.string "recover from the forest's embrace.\p"
	.string "The aroma of tasty, home-cooked meals\n"
	.string "lingers, and the crackling fireplace\l"
	.string "provides warmth for our tired bones.$"

AnheimTown_House3_Text_Hiker:
	.string "{COLOR}{BLUE}The quietude of the forest at night\n"
	.string "is unmatched.\p"
	.string "I come here to stargaze and ponder\n"
	.string "life's mysteries.\p"
	.string "Pokémon often join me, and together,\n"
	.string "we contemplate the cosmos.$"
