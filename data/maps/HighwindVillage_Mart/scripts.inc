HighwindVillage_Mart_MapScripts::
	.byte 0

HighwindVillage_Mart_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart HighwindVillage_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
HighwindVillage_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
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
	.2byte ITEM_NONE
	release
	end

HighwindVillage_Mart_Hiker::
	lock
	msgbox HighwindVillage_Mart_Text_Hiker, MSGBOX_DEFAULT
	delay 30
	faceplayer
	msgbox HighwindVillage_Mart_Text_Hiker_2, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HighwindVillage_Mart_Text_Hiker:
	.string "Ow! OK, OK!\n"
	.string "I'll get you that sweet!$"

HighwindVillage_Mart_Text_Hiker_2:
	.string "My Pokémon's a glutton…\p"
	.string "But I can't blame him, I'm hungry too\n"
	.string "after that trek through the snow.$"
