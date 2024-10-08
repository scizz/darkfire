NorthstarCity_Apartments_MapScripts::
	.byte 0

NorthstarCity_Apartments_Little_Boy::
	msgbox NorthstarCity_Apartments_Text_Little_Boy, MSGBOX_NPC
	end

NorthstarCity_Apartments_Father::
	msgbox NorthstarCity_Apartments_Text_Father, MSGBOX_NPC
	end

NorthstarCity_Apartments_Lass::
	msgbox NorthstarCity_Apartments_Text_Lass, MSGBOX_NPC
	end

NorthstarCity_Apartments_Picnicker::
	msgbox NorthstarCity_Apartments_Text_Picnicker, MSGBOX_NPC
	end

NorthstarCity_Apartments_Chef::
	msgbox NorthstarCity_Apartments_Text_Chef, MSGBOX_NPC
	end

NorthstarCity_Apartments_Reporter::
	msgbox NorthstarCity_Apartments_Text_Reporter, MSGBOX_NPC
	end

NorthstarCity_Apartments_Fat_Guy::
	msgbox NorthstarCity_Apartments_Text_Fat_Guy, MSGBOX_NPC
	end

NorthstarCity_Apartments_Old_Man::
	msgbox NorthstarCity_Apartments_Text_Old_Man, MSGBOX_NPC
	end

NorthstarCity_Apartments_Sailor::
	msgbox NorthstarCity_Apartments_Text_Sailor, MSGBOX_NPC
	end	

NorthstarCity_Apartments_Expert_M::
	msgbox NorthstarCity_Apartments_Text_Expert_M, MSGBOX_NPC
	end

NorthstarCity_Apartments_Expert_F::
	msgbox NorthstarCity_Apartments_Text_Expert_F, MSGBOX_NPC
	end

NorthstarCity_Apartments_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_MIST_NORTHSTAR, NorthstarCity_Apartments_TMMistReceived
	msgbox NorthstarCity_Apartments_Text_Hiker, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM17, 1
	setflag FLAG_RECEIVED_TM_MIST_NORTHSTAR
	goto NorthstarCity_Apartments_TMMistReceived
	end

NorthstarCity_Apartments_TMMistReceived:
	msgbox NorthstarCity_Apartments_Text_MistReceived, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Apartments_SheenySeedWife::
	msgbox NorthstarCity_Apartments_Text_SheenySeedWife, MSGBOX_NPC
	end

NorthstarCity_Apartments_SheenySeedPlushie::
	lock
	msgbox NorthstarCity_Apartments_Text_SheenySeedPlushie, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Apartments_SheenySeedCollector::
	lock
	faceplayer
	goto_if_set FLAG_SHEENY_SEED_QUEST_START, NorthstarCity_Apartments_SheenySeedCollector_QuestStarted
	msgbox NorthstarCity_Apartments_Text_OhHeyTherePlayer, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq NorthstarCity_Apartments_SheenySeedCollector_Yes
	msgbox NorthstarCity_Apartments_Text_OhThatsAShame, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Apartments_SheenySeedCollector_Yes::
	setflag FLAG_SHEENY_SEED_QUEST_START
	msgbox NorthstarCity_Apartments_Text_FantasticIllBeHere, MSGBOX_AUTOCLOSE
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_2
	call_if_eq VAR_RESULT, FALSE, NorthstarCity_Apartments_SheenySeedCollector_StartQuest
	release
	end

NorthstarCity_Apartments_SheenySeedCollector_StartQuest::
	startquest QUEST_2
	return

NorthstarCity_Apartments_SheenySeedCollector_QuestStarted::
	msgbox NorthstarCity_Apartments_Text_AhYoureBack, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq NorthstarCity_Apartments_SheenySeedCollector_TradeYes
	msgbox NorthstarCity_Apartments_Text_TakeYourTime, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Apartments_SheenySeedCollector_TradeYes::
	checkitem ITEM_SHEENY_SEED, 10
	compare VAR_RESULT, 1
	goto_if_ge NorthstarCity_Apartments_SheenySeedCollector_CompleteTrade
	msgbox NorthstarCity_Apartments_Text_ItAppearsYouDontHaveEnoughSeeds, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Apartments_SheenySeedCollector_CompleteTrade::
	msgbox NorthstarCity_Apartments_Text_YouHandedOver, MSGBOX_AUTOCLOSE
	delay 30
	msgbox NorthstarCity_Apartments_Text_ExcellentTheseSeeds, MSGBOX_AUTOCLOSE
	giveitem ITEM_GLEAMING_SEED, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	removeitem ITEM_SHEENY_SEED, 10
	clearflag FLAG_SHEENY_SEED_QUEST_START
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_1
	msgbox NorthstarCity_Apartments_Text_GleamingSeedsAreSaid, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Apartments_Meowth::
	lock
	playmoncry SPECIES_MEOWTH, 0
	speakername CommonName_Text_Meowth
	msgbox NorthstarCity_Apartments_Text_Meowth, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

NorthstarCity_Apartments_TitanTradeSequence::
	lock
	faceplayer
	goto_if_set FLAG_COMPLETE_TRADE_ARON, NorthstarCity_Apartments_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ARON
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	msgbox NorthstarCity_Apartments_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NorthstarCity_Apartments_DeclineTrade
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, NorthstarCity_Apartments_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	specialvar VAR_RESULT, GetTradeSpecies 
	goto_if_ne VAR_RESULT, VAR_0x8009, NorthstarCity_Apartments_NotRequestedMon 
	copyvar VAR_0x8004, VAR_0x8008
	special CreateInGameTradePokemon 
	special DoInGameTradeScene 
	waitstate
	msgbox NorthstarCity_Apartments_TradeThanks, MSGBOX_DEFAULT
	updatefollowerpokemongraphic
	setflag FLAG_COMPLETE_TRADE_ARON
	release
	end
 
NorthstarCity_Apartments_DeclineTrade::
	msgbox NorthstarCity_Apartments_DeclineTrade_Text, MSGBOX_DEFAULT
	release
	end
 
NorthstarCity_Apartments_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox NorthstarCity_Apartments_WrongMon_Text, MSGBOX_DEFAULT
	release
	end
 
NorthstarCity_Apartments_TradeCompleted::
	msgbox NorthstarCity_Apartments_TradeCompleted_Text, MSGBOX_DEFAULT
	release
	end
 
NorthstarCity_Apartments_TradeCompleted_Text:
	.string "{COLOR}{BLUE}Hey!\n"
	.string "How's Titan doing?\p"
	.string "Your Houndour is doing just fine.\n"
	.string "Thanks again for trading with me!$"
 
NorthstarCity_Apartments_Text_WillingToTradeIt:
	.string "{COLOR}{BLUE}Check out this {STR_VAR_2}!\n"
	.string "Oh, I can see that you want it!\p"
	.string "I'll tell you what.\p"
	.string "I might be willing to trade it for a\n"
	.string "{STR_VAR_1}. How about it?$"
 
NorthstarCity_Apartments_DeclineTrade_Text:
	.string "{COLOR}{BLUE}Oh… Thats too bad.\n"
	.string "Maybe next time…$"
 
NorthstarCity_Apartments_WrongMon_Text:
	.string "{COLOR}{BLUE}Huh? That is not a {STR_VAR_1}…\n"
	.string "I cannot trade with you.$"
 
NorthstarCity_Apartments_TradeThanks:
	.string "{COLOR}{BLUE}Thanks!\n"
	.string "Take good care of Titan!$"

CommonName_Text_Meowth:
	.string "Meowth$"

NorthstarCity_Apartments_Text_Meowth:
	.string "Meow, meowth!$"

NorthstarCity_Apartments_Text_Little_Boy:
	.string "{COLOR}{BLUE}I spend a lot of time studying because\n"
	.string "it's snowing all the time outside.\p"
	.string "I wonder if students in colder\n"
	.string "climates get better grades…$"

NorthstarCity_Apartments_Text_Father:
	.string "{COLOR}{BLUE}I'm a manager at a construction\n"
	.string "company.\p"
	.string "Guess who built this apartment\n"
	.string "complex?!\p"
	.string "Well… it wasn't me.\n"
	.string "But I sure would've liked it to be.$"

NorthstarCity_Apartments_Text_Lass:
	.string "{COLOR}{RED}I love my Meowth.\n"
	.string "She always keeps me company.\p"
	.string "I expect to grow old with her!$"

NorthstarCity_Apartments_Text_Picnicker:
	.string "{COLOR}{RED}I have a huge fear of bugs…\p"
	.string "Thankfully, they don't usually show\n"
	.string "up in these climates!$"

NorthstarCity_Apartments_Text_Chef:
	.string "{COLOR}{BLUE}The best job is the one I have: Ship's\n"
	.string "Cook.\p"
	.string "I go on voyages to exotic places\n"
	.string "all the time and get paid for it.\p"
	.string "Plus, I love cooking!$"

NorthstarCity_Apartments_Text_Reporter:
	.string "{COLOR}{BLUE}I used to work at the TV Station as a\n"
	.string "journalist, but I called it quits.\l"
	.string "Now, I work as an independent.\p"
	.string "I have no job security, but I couldn't\n"
	.string "be happier, to be honest.$"

NorthstarCity_Apartments_Text_Fat_Guy:
	.string "{COLOR}{BLUE}Sometimes I book a ticket to Laveria\n"
	.string "City, just to get access to the\l"
	.string "all-you-can-eat buffet.\p"
	.string "I can't resist that special sauce they\n"
	.string "put on the chicken! Mmmmh…$"

NorthstarCity_Apartments_Text_Old_Man:
	.string "Looking through the windows at the\n"
	.string "city's skyscrapers…\p"
	.string "Watching the snow fall ever so\n"
	.string "lightly…\p"
	.string "Now, that's a good retirement plan,\n"
	.string "if I've ever heard of any.$"

NorthstarCity_Apartments_Text_Sailor:
	.string "{COLOR}{BLUE}Lately, shady characters have been\n"
	.string "showing up in the docks where I work.\p"
	.string "I don't like 'em.\n"
	.string "I don't like 'em at all…$"

NorthstarCity_Apartments_Text_Expert_M:
	.string "My wife and I used to train Pokémon in\n"
	.string "our youth.\p"
	.string "We liked to challenge other Trainers,\n"
	.string "like you, to double battles!$"

NorthstarCity_Apartments_Text_Expert_F:
	.string "I wish my Pokémon were still with\n"
	.string "us…\p"
	.string "Age can be a terrible thing.$"

NorthstarCity_Apartments_Text_Hiker:
	.string "In the good ol' days, I used to enjoy\n"
	.string "hiking around Mt. Tamarok.\p"
	.string "One time hiking, I got caught in a\n"
	.string "blistering snowstorm at sub-zero\l"
	.string "temperatures.\p"
	.string "Slowly, I noticed a dark silhoutte\n"
	.string "emerge from the mist ahead.\p"
	.string "It looked like a Piloswine.\n"
	.string "A hungry and an angry one.\p"
	.string "As I got closer, I realized it was\n"
	.string "just a large doll, lodged in the snow.\p"
	.string "Today, I still wonder who would place\n"
	.string "such a thing there…\p"
	.string "You gotta protect yourself out there,\n"
	.string "kid!\p"
	.string "I know…\n"
	.string "Take this!$"

NorthstarCity_Apartments_Text_MistReceived:
	.string "TM17 contains Protect!\p"
	.string "It prevents any attacks targeted at\n"
	.string "the user from striking.\p"
	.string "Be careful out there!$"

NorthstarCity_Apartments_Text_OhHeyTherePlayer:
	.string "{COLOR}{BLUE}Oh, greetings, Trainer!\p"
	.string "I've been studying Hoothoot and\n"
	.string "Noctowl for years, you know.\l"
	.string "Fascinating creatures, really!\p"
	.string "I'm on a quest to gather some Sheeny\n"
	.string "Seeds, that Hoothoot often carry.\p"
	.string "If you happen to come across any\n"
	.string "during your travels, I'd be willing\l"
	.string "to trade with you!\p"
	.string "I will offer 1 Gleaming Seed for every\n"
	.string "10 Sheeny Seeds you can spare.\l"
	.string "Could you please gather them for me?$"

NorthstarCity_Apartments_Text_FantasticIllBeHere:
	.string "{COLOR}{BLUE}Fantastic!\p"
	.string "I'll be here eagerly awaiting your\n"
	.string "collection of 10 Sheeny Seeds.\p"
	.string "Hoothoot usually hold onto those seeds\n"
	.string "tightly, so keep an eye out!$"

NorthstarCity_Apartments_Text_TakeYourTime:
	.string "{COLOR}{BLUE}Take your time, Trainer.\p"
	.string "I'll be here, always ready to discuss\n"
	.string "the wonders of Hoothoot and Noctowl!$"

NorthstarCity_Apartments_Text_OhThatsAShame:
	.string "{COLOR}{BLUE}Oh, that's a shame…\p"
	.string "Well, if you change your mind, I'll be\n"
	.string "right here, surrounded by plushies.$"

NorthstarCity_Apartments_Text_AhYoureBack:
	.string "{COLOR}{BLUE}Ah, you're back!\p"
	.string "Did you manage to gather 10 Sheeny\n"
	.string "Seeds from the Hoothoot?\p"
	.string "If so, I'm ready to make a trade.\n"
	.string "What do you say?$"

NorthstarCity_Apartments_Text_YouHandedOver:
	.string "You handed over 10 Sheeny Seeds\n"
	.string "to the man.$"

NorthstarCity_Apartments_Text_ExcellentTheseSeeds:
	.string "{COLOR}{BLUE}Excellent!\n"
	.string "These sheeny seeds are perfect.\p"
	.string "As promised, here's a Gleaming Seed\n"
	.string "for your efforts…$\p"

NorthstarCity_Apartments_Text_GleamingSeedsAreSaid:
	.string "{COLOR}{BLUE}Gleaming Seeds are said to attract\n"
	.string "Noctowl and bring good luck.\p"
	.string "Thanks for helping me with my\n"
	.string "Owl Pokémon research!\p"
	.string "If you ever come across more Sheeny\n"
	.string "Seeds, don't hesitate to find me here!$"

NorthstarCity_Apartments_Text_ItAppearsYouDontHaveEnoughSeeds:
	.string "{COLOR}{BLUE}Huh?\p"
	.string "It appears you don't have enough\n"
	.string "Sheeny Seeds…\p"
	.string "When you collect 10 Sheeny Seeds,\n"
	.string "please return to me.$"

NorthstarCity_Apartments_Text_SheenySeedPlushie:
	.string "It's a soft Hoothoot plushie.$"

NorthstarCity_Apartments_Text_SheenySeedWife:
	.string "{COLOR}{RED}My husband's owl obsession is reaching\n"
	.string "new heights…\p"
	.string "I've got feathers all over the house,\n"
	.string "and he's hooting in his sleep.\p"
	.string "He can sleep ouside with the Noctowl\n"
	.string "tonight!$"
