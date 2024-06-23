GreendaleVillage_Mart_MapScripts::
	.byte 0

GreendaleVillage_Mart_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GreendaleVillage_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GreendaleVillage_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_SMOKE_BALL
	.2byte ITEM_NONE
	release
	end

GreendaleVillage_Mart_Fat_Guy::
	msgbox GreendaleVillage_Mart_Text_Fat_Guy, MSGBOX_NPC
	end

GreendaleVillage_Mart_Bug_Catcher::
	msgbox GreendaleVillage_Mart_Text_Bug_Catcher, MSGBOX_NPC
	end

GreendaleVillage_Mart_Text_Fat_Guy:
	.string "{COLOR}{BLUE}Why can't humans eat Rare Candies?\n"
	.string "Like, man, they look so good…$"

GreendaleVillage_Mart_Text_Bug_Catcher:
	.string "{COLOR}{BLUE}I wasted all my Great Balls catching\n"
	.string "Bug-type Pokémon in Anheim Forest.\p"
	.string "I'd better stock up on more!$"
