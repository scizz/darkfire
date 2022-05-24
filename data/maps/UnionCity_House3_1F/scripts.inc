UnionCity_House3_1F_MapScripts::
	.byte 0

UnionCity_House3_1F_Ace_Trainer_M::
	msgbox UnionCity_House3_1F_Text_Ace_Trainer_M, MSGBOX_NPC
	end

UnionCity_House3_1F_Woman::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_BALL_UNION_CITY, UnionCity_House3_1F_Woman_Given
	msgbox UnionCity_House3_1F_Text_Woman, MSGBOX_NPC
	giveitem ITEM_POKE_BALL, 1
	setflag FLAG_RECEIVED_POKE_BALL_UNION_CITY
	goto UnionCity_House3_1F_Woman_Given

UnionCity_House3_1F_Woman_Given::
	msgbox UnionCity_House3_1F_Text_Woman_Given, MSGBOX_DEFAULT
	releaseall
	end

UnionCity_House3_1F_Text_Ace_Trainer_M:
	.string "{COLOR}{BLUE}You know why being a Trainer is great?\n"
	.string "I'll tell you why!\p"
	.string "When you're battling, it doesn't\n"
	.string "matter if you're a kid or an adult.\l"
	.string "Everyone's equal in a Pokémon battle!$"

UnionCity_House3_1F_Text_Woman:
	.string "{COLOR}{RED}I love Pokémon battles.\p"
	.string "It's wonderful to see Pokémon compete,\n"
	.string "and we can just sit back and watch!\p"
	.string "Oh? You're a Trainer?\n"
	.string "Then, please, take this!$"

UnionCity_House3_1F_Text_Woman_Given:
	.string "{COLOR}{RED}There are a lot of rare Pokémon out\n"
	.string "there.\p"
	.string "It's always good to carry a lot of\n"
	.string "Poké Balls around with you.$"
