AnheimTown_Mart_MapScripts::
	.byte 0

AnheimTown_Mart_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart AnheimTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
AnheimTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_NONE
	release
	end

AnheimTown_Mart_Old_Lady::
	msgbox AnheimTown_Mart_Text_Old_Lady, MSGBOX_NPC
	end

AnheimTown_Mart_Girl::
	msgbox AnheimTown_Mart_Text_Girl, MSGBOX_NPC
	end

AnheimTown_Mart_Boy::
	msgbox AnheimTown_Mart_Text_Boy, MSGBOX_NPC
	end

AnheimTown_Mart_Text_Old_Lady:
	.string "The odds of going to the store for a\n"
	.string "loaf of bread and coming out with a\l"
	.string "loaf of bread are three billion to one!$"

AnheimTown_Mart_Text_Girl:
	.string "{COLOR}{RED}When I shop, the world gets better,\n"
	.string "and the world is better, but then it's\l"
	.string "not, and I need to do it again!$"

AnheimTown_Mart_Text_Boy:
	.string "{COLOR}{BLUE}In battle, X Sp. Atk or X Sp. Def is\n"
	.string "crucial.\p"
	.string "It jacks up the power of some moves\n"
	.string "even though it's only for one battle.$"
