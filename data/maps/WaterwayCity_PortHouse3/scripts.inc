WaterwayCity_PortHouse3_MapScripts::
	.byte 0

WaterwayCity_PortHouse3_SailorOne::
	msgbox WaterwayCity_PortHouse3_Text_SailorOne, MSGBOX_NPC
	end

WaterwayCity_PortHouse3_SailorTwo::
	msgbox WaterwayCity_PortHouse3_Text_SailorTwo, MSGBOX_NPC
	end

WaterwayCity_Porthouse3_SailorThree::
	message WaterwayCity_Porthouse3_Text_AhoyMatey
	waitmessage
	multichoicedefault 21, 6, MULTI_WATERWAY_CITY_SAIL, 2, FALSE
	switch VAR_RESULT
	case 0, WaterwayCity_ChooseNorthstarCity
	case 1, WaterwayCity_ChooseLaveriaCity
	case 2, WaterwayCity_CancelSailSelect
	case MULTI_B_PRESSED, WaterwayCity_CancelSailSelect
	end

WaterwayCity_ChooseNorthstarCity::
	msgbox WaterwayCity_Text_RighteoThisWayNorthstar, MSGBOX_AUTOCLOSE
	warp MAP_NORTHSTAR_CITY, 92, 36
	waitstate
	end

WaterwayCity_ChooseLaveriaCity::
	msgbox WaterwayCity_Text_RighteoThisWayLaveria, MSGBOX_AUTOCLOSE
	warp MAP_LAVERIA_CITY, 39, 43
	waitstate
	end

WaterwayCity_CancelSailSelect::
	msgbox LaveriaCity_Text_JustLetMeKnow, MSGBOX_AUTOCLOSE
	release
	end

WaterwayCity_PortHouse3_Fisherman::
	msgbox WaterwayCity_PortHouse3_Text_Fisherman, MSGBOX_NPC
	end

WaterwayCity_PortHouse3_Old_Woman::
	msgbox WaterwayCity_PortHouse3_Text_Old_Woman, MSGBOX_NPC
	end

WaterwayCity_PortHouse3_Text_SailorOne:
	.string "{COLOR}{BLUE}Ever notice how the currents change\n"
	.string "around Waterway City?\p"
	.string "One day, they're gentle, and the next,\n"
	.string "they're pushing my boat all over!\p"
	.string "Some say it's the work of Water-type\n"
	.string "Pokémon beneath the surface, guiding\l"
	.string "the flow.\p"
	.string "Whatever it is, I don't mind.\p"
	.string "It keeps things interesting.$"

WaterwayCity_PortHouse3_Text_SailorTwo:
	.string "{COLOR}{BLUE}The boats around here get so much use,\n"
	.string "we're always repairing something!\p"
	.string "Whether it's a broken rudder or a torn\n"
	.string "sail, there's never a dull moment.$"

WaterwayCity_Porthouse3_Text_AhoyMatey:
	.string "{COLOR}{BLUE}{PLAYER}!\p"
	.string "It's your favorite Sailor!\n"
	.string "Welcome to my Boat House!\p"
	.string "If you're looking to revisit some\n"
	.string "places we've been before, I can get\l"
	.string "you there in no time!\p"
	.string "Where would you like to sail to?$"

WaterwayCity_Text_RighteoThisWayNorthstar:
	.string "{COLOR}{BLUE}Righteo!\n"
	.string "This way to Northstar City!$"

WaterwayCity_Text_RighteoThisWayLaveria:
	.string "{COLOR}{BLUE}Righteo!\n"
	.string "This way to Laveria City!$"

WaterwayCity_PortHouse3_Text_Fisherman:
	.string "{COLOR}{BLUE}Caught a huge Magikarp yesterday,\n"
	.string "biggest one I've ever seen!\p"
	.string "The thing nearly pulled me right into\n"
	.string "the water.\p"
	.string "They say Magikarp are weak, but when\n"
	.string "one that size thrashes around, you\l"
	.string "learn quick to hold on tight.$"

WaterwayCity_PortHouse3_Text_Old_Woman:
	.string "I used to sit by this very window,\n"
	.string "watching my husband set sail every\l"
	.string "morning.\p"
	.string "He always said the sea was like a\n"
	.string "living, breathing thing, full of moods\l"
	.string "and secrets.\p"
	.string "He'd come back with tales of Pokémon\n"
	.string "he'd seen, ones I couldn't imagine.\p"
	.string "Sometimes, I still hear the waves\n"
	.string "calling his name.$"
