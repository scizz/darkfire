SunriseTown_Hotel_1F_MapScripts::
	.byte 0

SunriseTown_Hotel_1F_Boy::
	msgbox SunriseTown_Hotel_1F_Text_Boy, MSGBOX_NPC
	end

SunriseTown_Hotel_1F_Girl::
	msgbox SunriseTown_Hotel_1F_Text_Girl, MSGBOX_NPC
	end

SunriseTown_Hotel_1F_Receptionist::
	msgbox SunriseTown_Hotel_1F_Text_Receptionist, MSGBOX_NPC
	end

SunriseTown_Hotel_1F_Chef::
	goto_if_set FLAG_SUNRISE_TOWN_FAT_GUY, SunriseTown_Hotel_1F_Chef_Complete
	msgbox SunriseTown_Hotel_1F_Text_Chef, MSGBOX_NPC
	setflag FLAG_SUNRISE_TOWN_HOTEL_COOK
	end

SunriseTown_Hotel_1F_Chef_Complete::
	msgbox SunriseTown_Hotel_1F_Text_Chef_Complete, MSGBOX_NPC
	end

SunriseTown_Hotel_1F_Text_Boy:
	.string "{COLOR}{BLUE}If you came here to find Trainers to\n"
	.string "battle, you'll be disappointed.\p"
	.string "Nobody here battles.\n"
	.string "They can't even deal with wild Krabby…\p"
	.string "Me? I-I'm just here for a relaxing\n"
	.string "holiday. Leave me alone!$"

SunriseTown_Hotel_1F_Text_Girl:
	.string "{COLOR}{RED}Recently, Pearls have been washed\n"
	.string "up along the Sunrise Town beach.\p"
	.string "Though they cannot be sold in shops,\n"
	.string "Big Pearls are highly sought after\l"
	.string "by collectors all around the region.$"

SunriseTown_Hotel_1F_Text_Receptionist:
	.string "{COLOR}{RED}Hello! Welcome to Oritania Hotel,\n"
	.string "the best hotel in Sunrise Town!\p"
	.string "It's also the only hotel, hehe.\n"
	.string "We are currently fully booked.$"

SunriseTown_Hotel_1F_Text_Chef:
	.string "{COLOR}{BLUE}The food is ready! Free of charge for\n"
	.string "the residents of the Oritania Hotel.\p"
	.string "Now, where was that mister who was\n"
	.string "staying here…\l"
	.string "He's never missed dinner time before.$"

SunriseTown_Hotel_1F_Text_Chef_Complete:
	.string "{COLOR}{BLUE}The food is ready! Free of charge for\n"
	.string "the residents of the Oritania Hotel.$"
