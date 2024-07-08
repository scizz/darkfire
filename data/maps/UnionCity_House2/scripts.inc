UnionCity_House2_MapScripts::
	.byte 0

UnionCity_House2_Girl_1::
	msgbox UnionCity_House2_Text_Girl_1, MSGBOX_NPC
	end

UnionCity_House2_Pokefan_M::
	lockall
	faceplayer
	goto_if_set FLAG_UNION_CITY_TM_BULK_UP, UnionCity_House_2_Pokefan_M_Given
	msgbox UnionCity_House2_Text_Pokefan_M_1, MSGBOX_DEFAULT
	giveitem ITEM_TM08, 1
	setflag FLAG_UNION_CITY_TM_BULK_UP
	goto UnionCity_House_2_Pokefan_M_Given

UnionCity_House_2_Pokefan_M_Given:
	msgbox UnionCity_House2_Text_Pokefan_M_2, MSGBOX_DEFAULT
	releaseall
	end

UnionCity_House2_Rich_Boy::
	msgbox UnionCity_House2_Text_Rich_Boy, MSGBOX_NPC
	end

UnionCity_House2_Boy::
	msgbox UnionCity_House2_Text_Boy, MSGBOX_NPC
	end

UnionCity_House2_Girl_2::
	msgbox UnionCity_House2_Text_Girl_2, MSGBOX_NPC
	end

UnionCity_House2_Little_Girl::
	msgbox UnionCity_House2_Text_Little_Girl, MSGBOX_NPC
	end

UnionCity_House2_Woman::
	msgbox UnionCity_House2_Text_Woman, MSGBOX_NPC
	end

UnionCity_House2_RiaTradeSequence::
	lock
	faceplayer
	goto_if_set FLAG_COMPLETE_TRADE_NIDORAN_F, UnionCity_House2_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_NIDORAN_F
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox UnionCity_House2_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UnionCity_House2_DeclineTrade
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UnionCity_House2_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	specialvar VAR_RESULT, GetTradeSpecies 
	goto_if_ne VAR_RESULT, VAR_0x8009, UnionCity_House2_NotRequestedMon 
	copyvar VAR_0x8004, VAR_0x8008
	special CreateInGameTradePokemon 
	special DoInGameTradeScene 
	waitstate
	msgbox UnionCity_House2_TradeThanks, MSGBOX_DEFAULT
	updatefollowerpokemongraphic
	setflag FLAG_COMPLETE_TRADE_NIDORAN_F
	release
	end
 
UnionCity_House2_DeclineTrade::
	msgbox UnionCity_House2_DeclineTrade_Text, MSGBOX_DEFAULT
	release
	end
 
UnionCity_House2_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox UnionCity_House2_WrongMon_Text, MSGBOX_DEFAULT
	release
	end
 
UnionCity_House2_TradeCompleted::
	msgbox UnionCity_House2_TradeCompleted_Text, MSGBOX_DEFAULT
	release
	end

UnionCity_House2_Squirtle::
	lock
	faceplayer
	playmoncry SPECIES_SQUIRTLE, 0
	speakername CommonName_Text_Squirtle
	msgbox UnionCity_House2_Text_Squirtle, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

CommonName_Text_Squirtle:
	.string "Squirtle$"

UnionCity_House2_Text_Squirtle:
	.string "Squirtle, squirt!$"
 
UnionCity_House2_TradeCompleted_Text:
	.string "{COLOR}{RED}Hey!\n"
	.string "How's Terra doing?\p"
	.string "Your Zigzagoon is doing just fine.\n"
	.string "Thanks again for trading with me!$"
 
UnionCity_House2_Text_WillingToTradeIt:
	.string "{COLOR}{RED}Check out this {STR_VAR_2}!\n"
	.string "Oh, I can see that you want it!\p"
	.string "I'll tell you what.\p"
	.string "I might be willing to trade it for a\n"
	.string "{STR_VAR_1}. How about it?$"
 
UnionCity_House2_DeclineTrade_Text:
	.string "{COLOR}{RED}Oh… Thats too bad.\n"
	.string "Maybe next time…$"
 
UnionCity_House2_WrongMon_Text:
	.string "{COLOR}{RED}Huh? That is not a {STR_VAR_1}…\n"
	.string "I cannot trade with you.$"
 
UnionCity_House2_TradeThanks:
	.string "{COLOR}{RED}Thanks!\n"
	.string "Take good care of Terra!$"

UnionCity_House2_Text_Girl_1:
	.string "{COLOR}{RED}When they were expanding the city of\n"
	.string "Union, my dad helped out.\p"
	.string "His Pokémon lifted super heavy rocks\n"
	.string "to clear a path!$"

UnionCity_House2_Text_Pokefan_M_1:
	.string "{COLOR}{BLUE}That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained Pokémon…\p"
	.string "You're obviously a skilled Trainer!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "TM to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

UnionCity_House2_Text_Pokefan_M_2:
	.string "{COLOR}{BLUE}TM08 contains Bulk Up!\pIt bulks up Pokémon's attack and\ndefense powers in battle.\pWhen Union City was first built, my\nPokémon used its power to clear large\lrocks and debris to form the paths.\pPretty neat, right?$"

UnionCity_House2_Text_Rich_Boy:
	.string "{COLOR}{BLUE}We all have a lot in common. The same\n"
	.string "earth, the same air, the same sky.\p"
	.string "Maybe if we started looking at what's\n"
	.string "the same, instead of looking at what's\l"
	.string "different, well, who knows?$"

UnionCity_House2_Text_Boy:
	.string "{COLOR}{BLUE}My friends decided to move closer to\n"
	.string "the Government Offices to feel safer.\p"
	.string "I've been seeing all these horror\n"
	.string "stories on the TV about this group\l"
	.string "of criminals who steal Pokémon.\p"
	.string "They call themselves the “SUBO”, or\n"
	.string "something like that…$"

UnionCity_House2_Text_Girl_2:
	.string "{COLOR}{RED}I can't, for the life of me, figure\n"
	.string "out why people would hurt Pokémon…\p"
	.string "Why do they call themselves a Secret\n"
	.string "Underground Battling Organization?\p"
	.string "It's hardly a secret about what these\n"
	.string "guys are up to…$"

UnionCity_House2_Text_Little_Girl:
	.string "{COLOR}{RED}I love plush dolls!\n"
	.string "I'm going to collect hundreds!$"

UnionCity_House2_Text_Woman:
	.string "{COLOR}{RED}My daughter is going through a phase\n"
	.string "where all she wants is plush dolls.\p"
	.string "At least she hasn't yet started the\n"
	.string "angsty teenager phase!$"
