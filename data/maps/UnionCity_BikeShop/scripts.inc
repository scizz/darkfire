UnionCity_BikeShop_MapScripts::
	.byte 0

UnionCity_BikeShop_Owner::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_UNION_CITY_BIKE, UnionCity_BikeShop_Owner_Given
	goto_if_set FLAG_UNION_CITY_BIKE_QUEST_BEGIN, UnionCity_BikeShop_Owner_Begin
	msgbox UnionCity_BikeShop_Owner_Text_Intro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq UnionCity_BikeShop_Owner_Begin
	msgbox UnionCity_BikeShop_Owner_Text_No, MSGBOX_DEFAULT
	releaseall
	end

UnionCity_BikeShop_Owner_Begin::
	checkitem ITEM_SMOKE_BALL, 5
	compare VAR_RESULT, 1
	goto_if_ge UnionCity_BikeShop_Owner_Smoke_Balls
	msgbox UnionCity_BikeShop_Owner_Text_Quest, MSGBOX_DEFAULT
	setflag FLAG_UNION_CITY_BIKE_QUEST_BEGIN
	releaseall
	end

UnionCity_BikeShop_Owner_Smoke_Balls::
	removeitem ITEM_SMOKE_BALL, 5
	msgbox UnionCity_Bikeshop_Owner_Text_Quest_Got_Balls, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE, 1
	setflag FLAG_RECEIVED_UNION_CITY_BIKE
	goto UnionCity_BikeShop_Owner_Given
	end

UnionCity_BikeShop_Owner_Given::
	msgbox UnionCity_BikeShop_Owner_Text_Given, MSGBOX_DEFAULT
	releaseall
	end

UnionCity_BikeShop_Owner_Text_Intro:
	.string "{COLOR}{BLUE}Those Running Shoes…\n"
	.string "They're looking awfully filthy!\p"
	.string "…\n"
	.string "…\p"
	.string "I'll tell ya what!\p"
	.string "I'm looking to get some Smoke Balls for\n"
	.string "my friend's birthday party.\p"
	.string "I'm gonna set them off as a practical\n"
	.string "joke to startle everyone!\p"
	.string "I hear they sell them in Greendale\n"
	.string "Village.\p"
	.string "Bring me 5 Smoke Balls and I'll give\n"
	.string "you a brand new, shiny Bicycle. Deal?$"

UnionCity_BikeShop_Owner_Text_No:
	.string "{COLOR}{BLUE}No?\n"
	.string "Forget about a Bicycle, then!$"

UnionCity_BikeShop_Owner_Text_Quest:
	.string "{COLOR}{BLUE}Bring me 5 Smoke Balls and we'll talk\n"
	.string "about that free Bicycle!$"

UnionCity_Bikeshop_Owner_Text_Quest_Got_Balls:
	.string "{COLOR}{BLUE}Hello!\n"
	.string "…\p"
	.string "What's that?\n"
	.string "You managed to get the Smoke Balls?\p"
	.string "Far out! Thank you!\n"
	.string "As promised, here ya go!$"

UnionCity_BikeShop_Owner_Text_Given:
	.string "{COLOR}{BLUE}With the Mach Bike you will glide like\n"
	.string "the wind and leave folk tastin' dirt!$"
