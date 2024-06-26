PinleafTown_FlowerShop_MapScripts::
	.byte 0

PinleafTown_FlowerShop_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PINLEAF_LUM_BERRY, PinleafTown_FlowerShop_Girl_Given
	msgbox PinleafTown_FlowerShop_Text_Girl, MSGBOX_DEFAULT
	giveitem ITEM_LUM_BERRY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PINLEAF_LUM_BERRY
	goto PinleafTown_FlowerShop_Girl_Given

PinleafTown_FlowerShop_Girl_Given::
	msgbox PinleafTown_FlowerShop_Text_Girl_Given, MSGBOX_DEFAULT
	release
	end

PinleafTown_FlowersShop_Shopkeeper::
	msgbox PinleafTown_FlowerShop_Text_Shopkeeper, MSGBOX_AUTOCLOSE
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
