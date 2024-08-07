HighwindVillage_House2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HighwindVillage_House2_OnTransition
	.byte 0

HighwindVillage_House2_OnTransition:
	setvar VAR_TEMP_B, 5
	end

HighwindVillage_House2_Woman::
	msgbox HighwindVillage_House2_Text_Woman, MSGBOX_NPC
	end

HighwindVillage_House2_Old_Man::
	msgbox HighwindVillage_House2_Text_Old_Man, MSGBOX_NPC
	end

HighwindVillage_House2_HaroldTradeSequence::
	lock
	faceplayer
	goto_if_set FLAG_COMPLETE_TRADE_MAGIKARP, HighwindVillage_House2_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MAGIKARP
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox HighwindVillage_House2_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, HighwindVillage_House2_DeclineTrade
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, HighwindVillage_House2_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	specialvar VAR_RESULT, GetTradeSpecies 
	goto_if_ne VAR_RESULT, VAR_0x8009, HighwindVillage_House2_NotRequestedMon 
	copyvar VAR_0x8004, VAR_0x8008
	special CreateInGameTradePokemon 
	special DoInGameTradeScene 
	waitstate
	msgbox HighwindVillage_House2_TradeThanks, MSGBOX_DEFAULT
	updatefollowerpokemongraphic
	setflag FLAG_COMPLETE_TRADE_MAGIKARP
	release
	end
 
HighwindVillage_House2_DeclineTrade::
	msgbox HighwindVillage_House2_DeclineTrade_Text, MSGBOX_DEFAULT
	release
	end
 
HighwindVillage_House2_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox HighwindVillage_House2_WrongMon_Text, MSGBOX_DEFAULT
	release
	end
 
HighwindVillage_House2_TradeCompleted::
	msgbox HighwindVillage_House2_TradeCompleted_Text, MSGBOX_DEFAULT
	release
	end
 
HighwindVillage_House2_TradeCompleted_Text:
	.string "{COLOR}{BLUE}Hey!\n"
	.string "How's Leviathan doing?\p"
	.string "Your Swinub is doing just fine.\n"
	.string "Thanks again for trading with me!$"
 
HighwindVillage_House2_Text_WillingToTradeIt:
	.string "{COLOR}{BLUE}Check out this {STR_VAR_2}!\n"
	.string "Oh, I can see that you want it!\p"
	.string "I'll tell you what.\p"
	.string "I might be willing to trade it for a\n"
	.string "{STR_VAR_1}. How about it?$"
 
HighwindVillage_House2_DeclineTrade_Text:
	.string "{COLOR}{BLUE}Oh… Thats too bad.\n"
	.string "Maybe next time…$"
 
HighwindVillage_House2_WrongMon_Text:
	.string "{COLOR}{BLUE}Huh? That is not a {STR_VAR_1}…\n"
	.string "I cannot trade with you.$"
 
HighwindVillage_House2_TradeThanks:
	.string "{COLOR}{BLUE}Thanks!\n"
	.string "Take good care of Leviathan!$"

HighwindVillage_House2_Text_Woman:
	.string "{COLOR}{RED}I take care of Grandpa these days,\n"
	.string "since my brother is out in the field\l"
	.string "doing Ranger work.\p"
	.string "I only wish it would stop snowing!$"

HighwindVillage_House2_Text_Old_Man:
	.string "Fweh! It's too cold up here.\p"
	.string "My nose is running, and my feet are\n"
	.string "freezing.\p"
	.string "I should've retired to a warmer place!$"
