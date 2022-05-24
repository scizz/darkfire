PinleafTown_MapScripts::
	.byte 0

PinleafTown_Vendor::
	msgbox PinleafTown_Text_Vendor, MSGBOX_NPC
	end

PinleafTown_Woman::
	msgbox PinleafTown_Text_Woman, MSGBOX_NPC
	end

PinleafTown_Man_1::
	msgbox PinleafTown_Text_Man_1, MSGBOX_NPC
	end

PinleafTown_Little_Girl::
	msgbox PinleafTown_Text_Little_Girl, MSGBOX_NPC
	end

PinleafTown_Little_Ace_Trainer::
	msgbox PinleafTown_Text_Little_Ace_Trainer, MSGBOX_NPC
	end

PinleafTown_Guitarist::
	msgbox PinleafTown_Text_Guitarist, MSGBOX_NPC
	end

PinleafTown_Man_2::
	msgbox PinleafTown_Text_Man_2, MSGBOX_NPC
	end

PinleafTown_Old_Man::
	msgbox PinleafTown_Text_Old_Man, MSGBOX_NPC
	end

PinleafTown_SUBO_1::
	msgbox PinleafTown_Text_SUBO_1, MSGBOX_NPC
	end

PinleafTown_SUBO_2::
	msgbox PinleafTown_Text_SUBO_2, MSGBOX_NPC
	end

PinleafTown_SUBO_3::
	msgbox PinleafTown_Text_SUBO_3, MSGBOX_NPC
	end

PinleafTown_Maniac::
	msgbox PinleafTown_Text_Maniac, MSGBOX_NPC
	end

PinleafTown_Flower_Girl::
	msgbox PinleafTown_Text_Flower_Girl, MSGBOX_NPC
	end

PinleafTown_Fat_Guy::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_PINLEAF_PP_UP, PinleafTown_Fat_Guy_Given
	msgbox PinleafTown_Text_Fat_Guy MSGBOX_NPC
	giveitem ITEM_PP_UP, 1
	setflag FLAG_RECEIVED_PINLEAF_PP_UP
	goto PinleafTown_Fat_Guy_Given

PinleafTown_Fat_Guy_Given::
	msgbox PinleafTown_Text_Fat_Guy_Given, MSGBOX_DEFAULT
	releaseall
	end

PinleafTown_Old_Lady::
	msgbox PinleafTown_Text_Old_Lady, MSGBOX_NPC
	end

PinleafTown_Son::
	msgbox PinleafTown_Text_Son, MSGBOX_NPC
	end

PinleafTown_Text_Vendor:
	.string "{COLOR}{BLUE}Hi, Trainer!\p"
	.string "The owner of this house recently moved\n"
	.string "out.\p"
	.string "I am just here with my team getting\n"
	.string "it cleaned up and ready to be sold!\p"
	.string "If you're interested in purchasing the\n"
	.string "house, please check back later.$"

PinleafTown_Text_Woman:
	.string "{COLOR}{RED}There used to be a bus station here,\n"
	.string "but there's been some trouble over in\l"
	.string "Mayhem City with the SUBO.\p"
	.string "For that reason, I suppose the bus\n"
	.string "won't be coming around here anymore…$"

PinleafTown_Text_Man_1:
	.string "{COLOR}{BLUE}I saw children climbing up the vines\n"
	.string "on those logs.\p"
	.string "I hope they didn't get hurt…$"

PinleafTown_Text_Little_Girl:
	.string "{COLOR}{RED}The countryside's pretty, but I really\n"
	.string "wanna move to the city when I grow up!$"

PinleafTown_Text_Little_Ace_Trainer:
	.string "{COLOR}{BLUE}I'm just passing through here, but\n"
	.string "here's a quick heads up.\p"
	.string "There are Trainers in this town looking\n"
	.string "to battle, so be on your guard.$"

PinleafTown_Text_Guitarist:
	.string "{COLOR}{BLUE}This town doesn't have a PokéCenter\n"
	.string "or PokéMart.\p"
	.string "Instead, we got this shop over here\n"
	.string "and there's an Inn just north.$"

PinleafTown_Text_Man_2:
	.string "{COLOR}{BLUE}This here's Mowell Farm, and I'm Mr.\n"
	.string "Mowell.\p"
	.string "We ain't the largest farm in Pinleaf,\n"
	.string "but we're sure the proudest one!\p"
	.string "We don't tolerate intruders, though.\n"
	.string "Especially with all the crop theft\l"
	.string "going on around recently!$"

PinleafTown_Text_Old_Man:
	.string "Used to be real quiet around here…\p"
	.string "Now with all those SUBO running around\n"
	.string "and Pokémon invading our crops, things\l"
	.string "have changed too much!$"

PinleafTown_Text_SUBO_1:
	.string "{COLOR}{BLUE}Hey! Can't you see we're busy here?!\n"
	.string "Leave us alone, you bully!$"

PinleafTown_Text_SUBO_2:
	.string "{COLOR}{BLUE}What are you lookin' at, kiddo?\p"
	.string "We ain't goin' anywhere, so you might\n"
	.string "wanna turn ‘round and leave!$"

PinleafTown_Text_SUBO_3:
	.string "{COLOR}{BLUE}What is going on here?\p"
	.string "How am I supposed to sneak around with\n"
	.string "these weird things blocking the way?!$"

PinleafTown_Text_Maniac:
	.string "Say…\n"
	.string "Is that the Northstar City Badge?\p"
	.string "You ought to go visit the Rangers'\n"
	.string "Federation Lodge in Highwind Village.\p"
	.string "I'm certain they will let a Trainer\n"
	.string "of your calibre inside.$"

PinleafTown_Text_Flower_Girl:
	.string "{COLOR}{RED}The flowers are so beautiful around\n"
	.string "here!\p"
	.string "I chose to work at the Flower &\n"
	.string "Berry Shop for this reason.$"

PinleafTown_Text_Fat_Guy:
	.string "{COLOR}{BLUE}I am so glad the Sudowoodo have been\n"
	.string "dealt with…\p"
	.string "I was trying to get to the Inn for\n"
	.string "some food and a quick nap, but I could\l"
	.string "not find a way past the darned things.\p"
	.string "…\p"
	.string "Wait, it was you who dealt with them?!\n"
	.string "Incredible!\p"
	.string "Take this as a token of my thanks!$"

PinleafTown_Text_Fat_Guy_Given:
	.string "{COLOR}{BLUE}PP Ups, as the name suggests, raises\n"
	.string "the base PP of your Pokémon's move.\p"
	.string "It also increases the Pokémon's\n"
	.string "happiness a little!$"

PinleafTown_Text_Old_Lady:
	.string "Welcome to Longfield Farm, child.\p"
	.string "I heard folk all around Pinleaf are\n"
	.string "having problems, but not this farm.\p"
	.string "My Grandson is looking out for us,\n"
	.string "and he is pretty strong.$"

PinleafTown_Text_Son:
	.string "{COLOR}{BLUE}Placeholder.$"
