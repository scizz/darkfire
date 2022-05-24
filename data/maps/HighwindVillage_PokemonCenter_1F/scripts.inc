HighwindVillage_PokemonCenter_1F_MapScripts::
	.byte 0

HighwindVillage_PokemonCenter_1F_Hiker::
	msgbox HighwindVillage_PokemonCenter_1F_Text_Hiker, MSGBOX_NPC
	end

HighwindVillage_PokemonCenter_1F_Ranger_F::
	lock
	faceplayer
	msgbox HighwindVillage_PokemonCenter_1F_Text_Ranger_F, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HighwindVillage_PokemonCenter_1F_Ranger_F_Yes
	msgbox HighwindVillage_PokemonCenter_1F_Text_Ranger_F_No, MSGBOX_DEFAULT
	release
	end

HighwindVillage_PokemonCenter_1F_Ranger_F_Yes::
	msgbox HighwindVillage_PokemonCenter_1F_Text_Ranger_F_Yes, MSGBOX_DEFAULT
	release
	end 

HighwindVillage_PokemonCenter_1F_Text_Hiker:
	.string "I'm from Northstar City.\p"
	.string "I came all this way to have a go at\n"
	.string "hiking Mt. Tamarok.\p"
	.string "I love a good challenge!$"

HighwindVillage_PokemonCenter_1F_Text_Ranger_F:
	.string "{COLOR}{RED}Nothing like a nice, warm place to\n"
	.string "rest after hard work in the mountains!\p"
	.string "Say, did you visit the Ranger's Lodge\n"
	.string "here in Highwind Village yet?$"

HighwindVillage_PokemonCenter_1F_Text_Ranger_F_No:
	.string "{COLOR}{RED}Drop by when you get the chance.\p"
	.string "We could sure use some help from a\n"
	.string "Trainer like you!$"

HighwindVillage_PokemonCenter_1F_Text_Ranger_F_Yes:
	.string "{COLOR}{RED}Our headquarters impressed you, I bet.$"
