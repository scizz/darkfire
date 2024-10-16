WaterwayCity_House3_MapScripts::
	.byte 0

WaterwayCity_House3_Boy::
	msgbox WaterwayCity_House3_Text_Boy, MSGBOX_NPC
	end

WaterwayCity_House3_Girl::
	lock
	faceplayer
	goto_if_set FLAG_GIVEN_WATERWAY_CITY_REVIVE, WaterwayCity_House3_Girl_Given
	msgbox WaterwayCity_House3_Text_Girl, MSGBOX_AUTOCLOSE
	giveitem ITEM_REVIVE, 1
	setflag FLAG_GIVEN_WATERWAY_CITY_REVIVE
	goto WaterwayCity_House3_Girl_Given
	end

WaterwayCity_House3_Girl_Given::
	msgbox WaterwayCity_House3_Text_Girl_Given, MSGBOX_AUTOCLOSE
	release
	end

WaterwayCity_House3_Text_Boy:
	.string "{COLOR}{BLUE}If you head south of Waterway City,\n"
	.string "you'll find yourself in the vast,\l"
	.string "scorching desert.\p"
	.string "Quite the contrast to all the water\n"
	.string "here, huh?\p"
	.string "It's a tough place to navigate.\p"
	.string "Sandstorms pop up out of nowhere, and\n"
	.string "the heat can wear you out fast.\p"
	.string "I've heard rumors of rare Ground and\n"
	.string "Rock-type Pokémon living there.$"

WaterwayCity_House3_Text_Girl:
	.string "{COLOR}{RED}You've been battling hard, haven't\n"
	.string "you?\p"
	.string "Here, take this…$"

WaterwayCity_House3_Text_Girl_Given:
	.string "{COLOR}{RED}Revive will always come in handy.\p"
	.string "It's great for when your Pokémon are\n"
	.string "too tired to keep going.$"
