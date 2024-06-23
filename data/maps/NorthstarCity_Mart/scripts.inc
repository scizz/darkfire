NorthstarCity_Mart_MapScripts::
	.byte 0

NorthstarCity_Mart_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart NorthstarCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
NorthstarCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

NorthstarCity_Mart_Hiker::
	msgbox NorthstarCity_Mart_Text_Hiker, MSGBOX_NPC
	end

NorthstarCity_Mart_Text_Hiker:
	.string "The trek from the base of Mt. Tamarok\n"
	.string "to here in this Mart was incredible.\p"
	.string "I live for the challenges of my mental\n"
	.string "and physical endurance!$"
