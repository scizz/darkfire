NorthstarCity_ShippingCenter_MapScripts::
	.byte 0

NorthstarCity_ShippingCenter_Fat_Man::
	msgbox NorthstarCity_ShippingCenter_Text_Fat_Man, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Old_Man::
	msgbox NorthstarCity_ShippingCenter_Text_Old_Man, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Old_Lady::
	msgbox NorthstarCity_ShippingCenter_Text_Old_Lady, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Nerd_1::
	msgbox NorthstarCity_ShippingCenter_Text_Nerd_1, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Maniac::
	msgbox NorthstarCity_ShippingCenter_Text_Maniac, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Man::
	msgbox NorthstarCity_ShippingCenter_Text_Man, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Little_Boy::
	msgbox NorthstarCity_ShippingCenter_Text_Little_Boy, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Woman::
	msgbox NorthstarCity_ShippingCenter_Text_Woman, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Nerd_2::
	msgbox NorthstarCity_ShippingCenter_Text_Nerd_2, MSGBOX_NPC
	end

NorthstarCity_ShippingCenter_Boy::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_NORTHSTAR_SHIPPING_SUPER_POTION, NorthstarCity_ShippingCenter_Boy_Given
	msgbox NorthstarCity_ShippingCenter_Text_Boy, MSGBOX_NPC
	giveitem ITEM_SUPER_POTION, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_NORTHSTAR_SHIPPING_SUPER_POTION
	closemessage
	releaseall
	end

NorthstarCity_ShippingCenter_Boy_Given::
	msgbox NorthstarCity_ShippingCenter_Text_Boy_Given, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_ShippingCenter_Text_Fat_Man:
	.string "{COLOR}{BLUE}The SUBO stole a boat from the docks.\p"
	.string "It looked like they were giving chase\n"
	.string "to another boat. Goodness knows why.\p"
	.string "They must think they are pirates now,\n"
	.string "too. Ha!$"

NorthstarCity_ShippingCenter_Text_Old_Man:
	.string "You can't turn on the TV nowadays\n"
	.string "without seeing this “SOBU” group,\l"
	.string "or whatever you call them, plastered\l"
	.string "all over the darned television screen.\p"
	.string "Here's an idea…\p"
	.string "Instead of the government promoting all\n"
	.string "the fear-mongering, they should just\l"
	.string "do something about it!$"

NorthstarCity_ShippingCenter_Text_Old_Lady:
	.string "My husband likes to moan.\p"
	.string "Making a change in the world is\n"
	.string "everyone's responsibility, not just\l"
	.string "the government's…$"

NorthstarCity_ShippingCenter_Text_Nerd_1:
	.string "{COLOR}{BLUE}Northstar City is most famous for its\n"
	.string "tournament.\p"
	.string "Millions of people tune in every year\n"
	.string "to watch powerful Trainers fight for\l"
	.string "the number one spot.\p"
	.string "I wouldn't be able to handle the\n"
	.string "pressure, personally…\l"
	.string "That's why I'm an engineer!$"

NorthstarCity_ShippingCenter_Text_Maniac:
	.string "There are places in the Tenjo region\n"
	.string "that are still completely unexplored.\p"
	.string "Who knows what could be lurking\n"
	.string "there…$"

NorthstarCity_ShippingCenter_Text_Man:
	.string "{COLOR}{BLUE}As a lifeguard, I frequently get\n"
	.string "called out on rescue missions.\p"
	.string "One time, the rescue team and I\n"
	.string "received a call from a frantic\l"
	.string "mother who lost sight of her son.\p"
	.string "She said she lost sight of him while\n"
	.string "he was swimming in the water.\p"
	.string "After a couple hours of searching, we\n"
	.string "found out he was just playing on the\l"
	.string "scaffolding behind this building…\p"
	.string "We fined the mother for wasting our\n"
	.string "time.$"

NorthstarCity_ShippingCenter_Text_Little_Boy:
	.string "{COLOR}{BLUE}I'm here on vacation with my mom.\p"
	.string "Earlier, I saw that man over there out\n"
	.string "on speedboats with his friends.\l"
	.string "They looked so cool!\p"
	.string "Turns out they were looking for me\n"
	.string "when I was playing outside, hehehe.$"

NorthstarCity_ShippingCenter_Text_Woman:
	.string "{COLOR}{RED}Being a mother is tough.\p"
	.string "You can't take your eyes off your kids\n"
	.string "for one second without trouble arising!$"

NorthstarCity_ShippingCenter_Text_Nerd_2:
	.string "{COLOR}{BLUE}I designed the speedboat that was\n"
	.string "stolen by SUBO thugs.\p"
	.string "I can only hope that it will return in\n"
	.string "one piece…$"

NorthstarCity_ShippingCenter_Text_Boy:
	.string "{COLOR}{BLUE}I love collecting things!\p"
	.string "I just found an item on the docks\n"
	.string "while using my trusty Itemfinder.\p"
	.string "I don't have any Pokémon, though, so\n"
	.string "you can have it!$"

NorthstarCity_ShippingCenter_Text_Boy_Given:
	.string "{COLOR}{BLUE}If you have an Itemfinder, use it in\n"
	.string "urban areas, like in Northstar City.\p"
	.string "You'll be surprised what you can find!$"
