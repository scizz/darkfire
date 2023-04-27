PinleafTown_Mart_MapScripts::
	.byte 0

PinleafTown_Mart_Assistant::
	msgbox PinleafTown_Mart_Text_Assistant, MSGBOX_NPC
	end

PinleafTown_Mart_Girl::
	msgbox PinleafTown_Mart_Text_Girl, MSGBOX_NPC
	end

PinleafTown_Mart_Boy::
	msgbox PinleafTown_Mart_Text_Boy, MSGBOX_NPC
	end

PinleafTown_Mart_Text_Assistant:
	.string "{COLOR}{RED}Welcome to the Pinleaf Herb Shop!\p"
	.string "We have various medicinal herbs with\n"
	.string "amazing restorative powers.\p"
	.string "My assistant on your right will supply\n"
	.string "you with anything you need.$"

PinleafTown_Mart_Text_Girl:
	.string "{COLOR}{RED}I see the ladies go out to pick the\n"
	.string "herbs sold here every morning.\p"
	.string "They work unbelievably hard to keep\n"
	.string "this shop running.$"

PinleafTown_Mart_Text_Boy:
	.string "{COLOR}{BLUE}Oh, boy…\p"
	.string "The herbs sold here are very,\n"
	.string "very powerful medicines.\p"
	.string "They're sure to give you an edge in\n"
	.string "battle!\p"
	.string "Only thing is, Pokémon seem to hate\n"
	.string "the way they taste…$"
