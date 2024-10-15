WaterwayCity_House2_MapScripts::
	.byte 0

WaterwayCity_House2_PokeFan_F::
	lock
	faceplayer
	goto_if_set FLAG_GIVEN_WATERWAY_CITY_SITRUS_BERRY, WaterwayCity_House2_PokeFan_F_Given
	msgbox WaterwayCity_House2_Text_PokeFan_F, MSGBOX_AUTOCLOSE
	giveitem ITEM_SITRUS_BERRY,1
	setflag FLAG_GIVEN_WATERWAY_CITY_SITRUS_BERRY
	goto WaterwayCity_House2_PokeFan_F_Given
	end

WaterwayCity_House2_PokeFan_F_Given::
	msgbox WaterwayCity_House2_Text_PokeFan_F_Given, MSGBOX_AUTOCLOSE
	release
	end

WaterwayCity_House2_Text_PokeFan_F:
	.string "{COLOR}{RED}I used to raise all kinds of Pokémon.\p"
	.string "One day, I discovered a special Berry\n"
	.string "that helps restore a Pokémon's health\l"
	.string "during tough battles.\p"
	.string "I grew some in my garden and kept some\n"
	.string "to share with Trainers like you.\l"
	.string "Here, take one!$"

WaterwayCity_House2_Text_PokeFan_F_Given:	
	.string "{COLOR}{RED}Berries hold magical properties.\p"
	.string "It is worth finding those which will\n"
	.string "help you the most!$"
