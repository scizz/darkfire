WaterwayCity_PortHouse1_MapScripts::
	.byte 0

WaterwayCity_PortHouse1_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_GIVEN_WATERWAY_CITY_GOOD_ROD, WaterwayCity_PortHouse1_Fisherman_Given
	msgbox WaterwayCity_PortHouse1_Text_Fisherman, MSGBOX_AUTOCLOSE
	giveitem ITEM_GOOD_ROD, 1
	setflag FLAG_GIVEN_WATERWAY_CITY_GOOD_ROD
	goto WaterwayCity_PortHouse1_Fisherman_Given
	end

WaterwayCity_PortHouse1_Fisherman_Given::
	msgbox WaterwayCity_PortHouse1_Text_Fisherman_Given, MSGBOX_AUTOCLOSE
	release
	end

WaterwayCity_PortHouse1_Text_Fisherman:
	.string "{COLOR}{BLUE}Ahoy there!\p"
	.string "You've got the look of someone who's\n"
	.string "eager to explore the waters.\p"
	.string "Ever tried fishin'?\n"
	.string "It's not just about patience…\p"
	.string "It's about feelin' the rhythm of the\n"
	.string "water, knowing when to cast, and when\l"
	.string "to reel in.\p"
	.string "Here, take this, the Good Rod.\p"
	.string "With this, you'll be able to catch\n"
	.string "stronger Water-type Pokémon than with\l"
	.string "the Old Rod.\p"
	.string "And don't forget, some of the best\n"
	.string "catches are right off the shore!$"

WaterwayCity_PortHouse1_Text_Fisherman_Given:
	.string "{COLOR}{BLUE}Keep your line steady and your heart\n"
	.string "calm, and you'll be out reelin' in\l"
	.string "something amazing soon enough!$"
