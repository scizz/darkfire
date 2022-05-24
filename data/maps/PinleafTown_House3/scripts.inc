PinleafTown_House3_MapScripts::
	.byte 0

PinleafTown_House3_Woman::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_PINLEAF_HP_UP, PinleafTown_House3_Woman_Given
	msgbox PinleafTown_House3_Text_Woman, MSGBOX_DEFAULT
	giveitem ITEM_HP_UP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PINLEAF_HP_UP
	goto PinleafTown_House3_Woman_Given

PinleafTown_House3_Woman_Given::
	msgbox PinleafTown_House3_Text_Woman_Given, MSGBOX_DEFAULT
	releaseall
	end

PinleafTown_House3_Man::
	goto_if_set FLAG_UNUSED_0x27C, PinleafTown_House3_Man_Other
	msgbox PinleafTown_House3_Text_Man, MSGBOX_NPC
	end

PinleafTown_House3_Man_Other::
	msgbox PinleafTown_House3_Text_Man_Other, MSGBOX_NPC
	end

PinleafTown_House3_Text_Woman:
	.string "{COLOR}{RED}Your Pokémon…\p"
	.string "They seem to adore you.\n"
	.string "You must be a wonderful Trainer.\p"
	.string "Here, take this.$"

PinleafTown_House3_Text_Woman_Given:
	.string "{COLOR}{RED}I love to offer gifts to Trainers\n"
	.string "whose Pokémon seem happy, hehe.$"

PinleafTown_House3_Text_Man:
	.string "{COLOR}{BLUE}Pinleaf Town has been overrun with all\n"
	.string "sorts of problems lately.\p"
	.string "Pokémon around here have gone crazy,\n"
	.string "I tell you!\p"
	.string "Maybe they're disturbed by those shady\n"
	.string "gangsters that have showed up in town.$"

PinleafTown_House3_Text_Man_Other:
	.string "{COLOR}{BLUE}Peace may have been returned to the\n"
	.string "town, but I fear the future…$"
