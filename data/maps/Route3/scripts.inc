Route3_MapScripts::
	.byte 0

Route3_EventScript_MiracleSeed::
	lockall
	faceplayer
	goto_if_set FLAG_ROUTE_3_MIRACLE_SEED, Route3_MiracleSeed_Received
	msgbox Route3_Text_MiracleSeedOne, MSGBOX_YESNO
	giveitem ITEM_MIRACLE_SEED, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_3_MIRACLE_SEED
	goto Route3_MiracleSeed_Received
	end

Route3_MiracleSeed_Received::
	msgbox Route3_Text_MiracleSeedTwo, MSGBOX_DEFAULT
	releaseall
	end

Route3_Guitarist::
	msgbox Route3_Text_Guitarist, MSGBOX_NPC
	end

Route3_Girl::
	msgbox Route3_Text_Girl, MSGBOX_NPC
	end

Route3_Larvitar::
	lock
	playmoncry SPECIES_LARVITAR, 0
	msgbox Route3_Text_Larvitar, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route3_Nerd::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_3_LARVITAR_BATTLE_WON, Route3_LarvitarBattleWon
	msgbox Route3_Text_NerdBeforeBattle, MSGBOX_DEFAULT
	release
	end

Route3_LarvitarBattleWon::
	goto_if_set FLAG_ROUTE_3_LARVITAR_BATTLE_POTION_GIVEN, Route3_PotionReceived
	msgbox Route3_Text_GivePotion, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 1
	setflag FLAG_ROUTE_3_LARVITAR_BATTLE_POTION_GIVEN
	goto Route3_PotionReceived
	end

Route3_PotionReceived::
	msgbox Route3_Text_ReceivedPotion, MSGBOX_DEFAULT
	release
	end

Route3_Text_Guitarist:
	.string "{COLOR}{BLUE}I've got one piece of advice…\p"
	.string "Don't expect the world to be fair\n"
	.string "with you because you are fair.\p"
	.string "That's like expecting a lion not to\n"
	.string "eat you because you didn't eat it.$"

Route3_Text_Girl:
	.string "{COLOR}{RED}Anheim Forest is up ahead.\n"
	.string "It's a forest full of Bug-type Pokémon!\p"
	.string "I want to explore inside but I'm\n"
	.string "too scared of bugs! Eww!$"

Route3_Text_MiracleSeedOne:
	.string "{COLOR}{BLUE}I love watching Pokémon battles.\p"
	.string "There's so much to learn when it comes\n"
	.string "to different types and abilities.\p"
	.string "Don't believe me? Take this…$"

Route3_Text_MiracleSeedTwo:
	.string "{COLOR}{BLUE}Miracle Seed boosts Grass-type moves\n"
	.string "when held by a Pokémon.\p"
	.string "Give it a try!$"

Route3_Text_Larvitar:
	.string "Larvitar: Grra!$"

Route3_Text_NerdBeforeBattle:
	.string "I just got done training my Larvitar\n"
	.string "in Anheim Forest.\p"
	.string "I'm itching to battle a Trainer so I\n"
	.string "can test its new abilities!$"

Route3_Text_GivePotion:
	.string "Kudos to you, Trainer.\n"
	.string "Here you go.$"

Route3_Text_ReceivedPotion:
	.string "You're gonna need that Potion at\n"
	.string "some point… Trust me, you will!$"
