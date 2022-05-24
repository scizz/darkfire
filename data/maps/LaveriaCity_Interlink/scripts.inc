LaveriaCity_Interlink_MapScripts::
	.byte 0

LaveriaCity_Interlink_Hiker::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE02_GET, LaveriaCity_Interlink_Hiker_Received
	msgbox LaveriaCity_Interlink_Text_Hiker, MSGBOX_DEFAULT
	releaseall
	end

LaveriaCity_Interlink_Hiker_Received::
	msgbox LaveriaCity_Interlink_Text_Hiker_Received, MSGBOX_DEFAULT
	releaseall
	end

LaveriaCity_Interlink_Woman::
	msgbox LaveriaCity_Text_Interlink_Woman, MSGBOX_NPC
	end

LaveriaCity_Interlink_Girl::
	msgbox LaveriaCity_Text_Interlink_Girl, MSGBOX_NPC
	end

LaveriaCity_Interlink_Text_Hiker:
	.string "I'm on strict orders to deny any\n"
	.string "rookie Trainers passin' by here!\p"
	.string "Beat the Laveria City Champion and I\n"
	.string "will consider lettin' ya through!$"

LaveriaCity_Interlink_Text_Hiker_Received:
	.string "That Badge…\p"
	.string "So ya beat the Laveria City Champion,\n"
	.string "after all?\p"
	.string "Props to ya, kid!\n"
	.string "You can go through to Mt. Tamarok.\p"
	.string "Good luck - you'll need it! Hahaha.$"

LaveriaCity_Text_Interlink_Woman:
	.string "{COLOR}{RED}I dropped my Itemfinder down into the\n"
	.string "Steep Ravine…\p"
	.string "I would abseil down there to retreive\n"
	.string "it, but the rope doesn't feel safe.\p"
	.string "Oh, well…\p"
	.string "I'll leave it for someone else to\ndiscover.\p"
	.string "Heck, even you can take it, if you\n"
	.string "like.$"

LaveriaCity_Text_Interlink_Girl:
	.string "{COLOR}{RED}The Pokémon in Route 9 aren't all\n"
	.string "too powerful.\p"
	.string "It's no wonder, though, with the\n"
	.string "amount of new Trainers visiting the\l"
	.string "Starter Dome…\p"
	.string "In fact, the Starter Dome is where I\n"
	.string "got my very first Pokémon, hehe.$"
