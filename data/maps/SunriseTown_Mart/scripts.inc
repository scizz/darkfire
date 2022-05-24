SunriseTown_Mart_MapScripts::
	.byte 0

SunriseTown_Mart_Girl::
	msgbox SunriseTown_Mart_Text_Girl, MSGBOX_NPC
	end

SunriseTown_Mart_Boy::
	msgbox SunriseTown_Mart_Text_Boy, MSGBOX_NPC
	end

SunriseTown_Mart_Text_Girl:
	.string "{COLOR}{RED}I can't buy any Poké Balls.\n"
	.string "The clerk says they're all sold out.$"

SunriseTown_Mart_Text_Boy:
	.string "{COLOR}{BLUE}If a Pokémon gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your Pokémon from fainting,\n"
	.string "restore its HP with a Potion.$"
