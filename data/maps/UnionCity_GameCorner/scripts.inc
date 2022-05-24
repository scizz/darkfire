UnionCity_GameCorner_MapScripts::
	.byte 0

UnionCity_GameCorner_Girl::
	lock
	faceplayer
	msgbox UnionCity_GameCorner_Text_Girl, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

UnionCity_GameCorner_Ace_Trainer::
	lock
	faceplayer
	msgbox UnionCity_GameCorner_Text_Ace_Trainer, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

UnionCity_GameCorner_Aroma_Lady::
	lock
	faceplayer
	msgbox UnionCity_GameCorner_Text_Aroma_Lady, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

UnionCity_GameCorner_Old_Man_1::
	lock
	faceplayer
	msgbox UnionCity_GameCorner_Text_Old_Man_1, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

UnionCity_GameCorner_Old_Man_2::
	lock
	faceplayer
	msgbox UnionCity_GameCorner_Text_Old_Man_2, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

UnionCity_GameCorner_Text_Girl:
	.string "{COLOR}{RED}What's up?\n"
	.string "Do you need some Coins?\p"
	.string "If you can't win any then you can buy\n"
	.string "some at the counter over there!$"

UnionCity_GameCorner_Text_Ace_Trainer:
	.string "{COLOR}{BLUE}My life experience has taught me\n"
	.string "nothing happens by chance.\p"
	.string "Even the idea of roulette - it is not\n"
	.string "chance it ends up in a certain place.\l"
	.string "It's the forces that are at play.$"

UnionCity_GameCorner_Text_Aroma_Lady:
	.string "{COLOR}{RED}You need a Coin Case to play the games\n"
	.string "in here.\p"
	.string "You can't buy it anywhere but people\n"
	.string "in the city regularly give them out.$"

UnionCity_GameCorner_Text_Old_Man_1:
	.string "In gambling, the many must lose in\n"
	.string "order that the few may win.$"

UnionCity_GameCorner_Text_Old_Man_2:
	.string "True luck consists not in holding the\n"
	.string "best of the cards at the table.\p"
	.string "The luckiest is the one who knows just\n"
	.string "when to rise and go home.$"
