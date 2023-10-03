LaveriaCity_Mart_MapScripts::
	.byte 0

LaveriaCity_Mart_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_RECEIVED_ROUTE_9_AWAKENING, LaveriaCity_Mart_ExpandedItems
	pokemart LaveriaCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LaveriaCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE
	release
	end

LaveriaCity_Mart_ExpandedItems::
	pokemart LaveriaCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LaveriaCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_AWAKENING
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE
	release
	end

LaveriaCity_Mart_Aroma_Lady::
	msgbox LaveriaCity_Mart_Text_Aroma_Lady, MSGBOX_NPC
	end

LaveriaCity_Mart_Guitarist::
	msgbox LaveriaCity_Mart_Text_Guitarlist, MSGBOX_NPC
	end

LaveriaCity_Mart_Boy::
	msgbox LaveriaCity_Mart_Text_Boy, MSGBOX_NPC
	end

LaveriaCity_Mart_Text_Aroma_Lady:
	.string "{COLOR}{RED}Even if a Pokémon is weak now,\n"
	.string "it will grow stronger.\p"
	.string "The most important thing is love for\n"
	.string "your Pokémon!$"

LaveriaCity_Mart_Text_Guitarlist:
	.string "{COLOR}{BLUE}I'm gonna stock up on Poké Balls.\p"
	.string "Some dude told me there are some rare\n"
	.string "Pokémon to find in Route 7.$"

LaveriaCity_Mart_Text_Boy:
	.string "{COLOR}{BLUE}Do you use Repels?\p"
	.string "It keeps wild Pokémon away when you're\n"
	.string "in a hurry.$"
