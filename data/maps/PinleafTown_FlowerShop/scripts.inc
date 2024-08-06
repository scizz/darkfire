PinleafTown_FlowerShop_MapScripts::
	.byte 0

PinleafTown_FlowerShop_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PINLEAF_CHESTO_BERRY, PinleafTown_FlowerShop_Girl_Given
	msgbox PinleafTown_FlowerShop_Text_Girl, MSGBOX_DEFAULT
	giveitem ITEM_CHESTO_BERRY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PINLEAF_CHESTO_BERRY
	goto PinleafTown_FlowerShop_Girl_Given

PinleafTown_FlowerShop_Girl_Given::
	msgbox PinleafTown_FlowerShop_Text_Girl_Given, MSGBOX_DEFAULT
	release
	end

PinleafTown_FlowerShop_Shopkeeper::
	goto_if_ge VAR_STORYLINE_STATE, 42, PinleafTown_FlowerShop_Next_Given
	msgbox PinleafTown_FlowerShop_Text_Shopkeeper, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_STORYLINE_STATE, 41, PinleafTown_FlowerShop_Next
	end

PinleafTown_FlowerShop_Next::
	playse SE_PIN
	emote 1, 7
	waitse
	msgbox UnlessDotDotDot, MSGBOX_AUTOCLOSE
	giveitem ITEM_WAILMER_PAIL, 1
	setvar VAR_STORYLINE_STATE, 42
	goto PinleafTown_FlowerShop_Next_Given
	end

PinleafTown_FlowerShop_Next_Given::
	msgbox UseTheWailmerPail, MSGBOX_AUTOCLOSE
	release
	end

PinleafTown_FlowerShop_Text_Girl:
	.string "{COLOR}{RED}Flowers are for everyone!\p"
	.string "You get a flower! They get a flower!\n"
	.string "Everyone gets a flower!\p"
	.string "Same goes with Berries.\n"
	.string "Here's a Berry!$"

PinleafTown_FlowerShop_Text_Girl_Given:
	.string "{COLOR}{RED}We make a living by what we get, but\n"
	.string "we make a life by what we give!$"

PinleafTown_FlowerShop_Text_Shopkeeper:
	.string "{COLOR}{RED}How will we ever get rid of the\n"
	.string "Sudowoodo?\p"
	.string "They will keep blocking the road\n"
	.string "forever…$"

UnlessDotDotDot:
	.string "{COLOR}{RED}Unless…\p"
	.string "Wait a minute, take this.$"

UseTheWailmerPail:
	.string "{COLOR}{RED}You can use the Wailmer Pail to spray\n"
	.string "water on things, like Berry trees, to\l"
	.string "help them grow!\p"
	.string "Though, some Pokémon don't like being\n"
	.string "sprayed with it… Especially Sudowoodo.$"
