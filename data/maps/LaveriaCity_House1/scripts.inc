LaveriaCity_House1_MapScripts::
	.byte 0

LaveriaCity_House1_Maniac::
	msgbox LaveriaCity_House1_Text_Maniac, MSGBOX_NPC
	end

LaveriaCity_House1_Fisherman::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD_LAVERIA_CITY, LaveriaCity_House1_Fisherman_Given
	msgbox LaveriaCity_House1_Text_Fisherman, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD, 1
	setflag FLAG_RECEIVED_OLD_ROD_LAVERIA_CITY
	goto LaveriaCity_House1_Fisherman_Given
	end

LaveriaCity_House1_Fisherman_Given::
	msgbox LaveriaCity_House1_Text_Fisherman_Given, MSGBOX_DEFAULT
	releaseall
	end

LaveriaCity_House1_Text_Maniac:
	.string "I sometimes see Trainers pass this\n"
	.string "city to climb the huge mountain in\l"
	.string "Route 7.\p"
	.string "It's funny seeing them hobble back\n"
	.string "to the Pokémon Center shortly after!$"

LaveriaCity_House1_Text_Fisherman:
	.string "{COLOR}{BLUE}Hmph…\p"
	.string "It's pointless fishing when the\n"
	.string "weather is like this…\l"
	.string "All the ponds and lakes are frozen!\p"
	.string "Here, kid, you can have this.$"

LaveriaCity_House1_Text_Fisherman_Given:
	.string "{COLOR}{BLUE}One thing I will always love about\n"
	.string "fishing is that you never know what\l"
	.string "Pokémon's gonna take the bait! Hah!$"
