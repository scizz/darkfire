WaterwayCity_MapScripts::
	.byte 0

WaterwayCity_Sign::
	msgbox WaterwayCity_Text_Sign, MSGBOX_SIGN
	end

WaterwayCity_Sign_ColossusTemple::
	msgbox WaterwayCity_Text_ColossusTemple, MSGBOX_SIGN
	end

WaterwayCity_Sign_Market::
	msgbox WaterwayCity_Text_WaterwayCityMarket, MSGBOX_SIGN
	end

WaterwayCity_Sign_MrSurfsHouse::
	msgbox WaterwayCity_Sign_Text_MrSurfsHouse, MSGBOX_SIGN
	end

WaterwayCity_PokeFan_F_1::
	msgbox WaterwayCity_Text_PokeFan_F_1, MSGBOX_NPC
	end

WaterwayCity_Woman_5_1::
	msgbox WaterwayCity_Text_Woman_5_1, MSGBOX_NPC
	end

WaterwayCity_BlackBelt::
	msgbox WaterwayCity_Text_BlackBelt, MSGBOX_NPC
	end

WaterwayCity_Woman_4::
	msgbox WaterwayCity_Text_Woman_4, MSGBOX_NPC
	end

WaterwayCity_Man_1::
	msgbox WaterwayCity_Text_Man_1, MSGBOX_NPC
	end

WaterwayCity_Girl_2::
	msgbox WaterwayCity_Text_Girl_2, MSGBOX_NPC
	end

WaterwayCity_Cook::
	msgbox WaterwayCity_Text_Cook, MSGBOX_NPC
	end

WaterwayCity_Old_Woman::
	msgbox WaterwayCity_Text_Old_Woman, MSGBOX_NPC
	end

WaterwayCity_Girl_1::
	msgbox WaterwayCity_Text_Girl_1, MSGBOX_NPC
	end

WaterwayCity_Cameraman::
	msgbox WaterwayCity_Text_Cameraman, MSGBOX_NPC
	end

WaterwayCity_PokeFan_F_2::
	msgbox WaterwayCity_Text_PokeFan_F_2, MSGBOX_NPC
	end

WaterwayCity_Sailor::
	msgbox WaterwayCity_Text_Sailor, MSGBOX_NPC
	end

WaterwayCity_Girl_3::
	msgbox WaterwayCity_Text_Girl_3, MSGBOX_NPC
	end

WaterwayCity_Mart_Employee_1::
	msgbox WaterwayCity_Text_Mart_Employee_1, MSGBOX_NPC
	end

WaterwayCity_Old_Man::
	msgbox WaterwayCity_Text_Old_Man, MSGBOX_NPC
	end

WaterwayCity_Rich_Boy::
	msgbox WaterwayCity_Text_Rich_Boy, MSGBOX_NPC
	end

WaterwayCity_Lass::
	msgbox WaterwayCity_Text_Lass, MSGBOX_NPC
	end

WaterwayCity_Woman_5_2::
	msgbox WaterwayCity_Text_Woman_5_2, MSGBOX_NPC
	end

WaterwayCity_School_Kid_M::
	msgbox WaterwayCity_Text_School_Kid_M, MSGBOX_NPC
	end

WaterwayCity_Man_4::
	msgbox WaterwayCity_Text_Man_4, MSGBOX_NPC
	end

WaterwayCity_PokeFan_M::
	msgbox WaterwayCity_Text_PokeFan_M, MSGBOX_NPC
	end

WaterwayCity_Gentleman::
	msgbox WaterwayCity_Text_Gentleman, MSGBOX_NPC
	end

WaterwayCity_Running_Triathlete_F::
	msgbox WaterwayCity_Text_Running_Triathlete_F, MSGBOX_NPC
	end

WaterwayCity_Man_1_2::
	msgbox WaterwayCity_Text_Man_1_2, MSGBOX_NPC
	end

WaterwayCity_Fisherman::
	msgbox WaterwayCity_Text_Fisherman, MSGBOX_NPC
	end

WaterwayCity_Youngster::
	msgbox WaterwayCity_Text_Youngster, MSGBOX_NPC
	end

WaterwayCity_Fat_Man::
	msgbox WaterwayCity_Text_Fat_Man, MSGBOX_NPC
	end

WaterwayCity_PokeFan_M_2::
	msgbox WaterwayCity_Text_PokeFan_M_2, MSGBOX_NPC
	end

WaterwayCity_Little_Girl::
	msgbox WaterwayCity_Text_Little_Girl, MSGBOX_NPC
	end

WaterwayCity_Girl_2_2::
	msgbox WaterwayCity_Text_Girl_2_2, MSGBOX_NPC
	end

WaterwayCity_Hiker::
	lockall
	faceplayer
	goto_if_set FLAG_GIVEN_WATERWAY_CITY_ESCAPE_ROPE, WaterwayCity_Hiker_Given
	msgbox WaterwayCity_Text_Hiker, MSGBOX_AUTOCLOSE
	giveitem ITEM_ESCAPE_ROPE, 1
	setflag FLAG_GIVEN_WATERWAY_CITY_ESCAPE_ROPE
	goto WaterwayCity_Hiker_Given
	end

WaterwayCity_Hiker_Given::
	msgbox WaterwayCity_Text_Hiker_Given, MSGBOX_AUTOCLOSE
	releaseall
	end

WaterwayCity_Text_Sign:
	.string "Waterway City\n"
	.string "{FONT_SMALL}“Where Streams Flow and Legends Grow!”$"

WaterwayCity_Text_ColossusTemple:
	.string "Colossus Temple$"

WaterwayCity_Text_WaterwayCityMarket:
	.string "Waterway City Market$"

WaterwayCity_Sign_Text_MrSurfsHouse:
	.string "Mr. Surf's House$"

WaterwayCity_Text_BlackBelt:
	.string "I'm used to training on solid ground,\n"
	.string "but the streams here add more dare!\p"
	.string "Balancing on slippery rocks and\n"
	.string "battling Water-type Pokémon has really\l"
	.string "sharpened my skills!$"

WaterwayCity_Text_Cameraman:
	.string "{COLOR}{BLUE}Outta the way, kiddo!\n"
	.string "You're ruinin' my amazing shot!$"

WaterwayCity_Text_Cook:
	.string "{COLOR}{BLUE}The secret to my dishes?\p"
	.string "It's the fresh water from the streams!\p"
	.string "Nothing beats the flavor of locally\n"
	.string "caught Water-type Pokémon like Krabby.\p"
	.string "My specialty today is a Spicy\n"
	.string "Tentacool Soup!$"

WaterwayCity_Text_Fat_Man:
	.string "{COLOR}{BLUE}Glug, glug…\p"
	.string "The food from the cantine here at the\n"
	.string "docks is stupendous, isn't it, Licki?$"

WaterwayCity_Text_Fisherman:
	.string "{COLOR}{BLUE}Nothing good bites here, for Muk's\n"
	.string "sake…\p"
	.string "I'll just have to take my boat and go\n"
	.string "south in the Antlean Channel to find\l"
	.string "up some good bites.$"

WaterwayCity_Text_Gentleman:
	.string "To the south from here is Route 13,\n"
	.string "also known as the Antlean Channel.\p"
	.string "These are some of the most shallow,\n"
	.string "warm waters in Tenjo.\p"
	.string "Though, you'll still need Surf to\n"
	.string "cross them.$"

WaterwayCity_Text_Girl_1:
	.string "{COLOR}{RED}I traveled here just to see the famous\n"
	.string "Waterway City!\p"
	.string "The bridges, the flowing water, it's\n"
	.string "all so beautiful.\p"
	.string "Make sure to take pictures!$"

WaterwayCity_Text_Girl_2:
	.string "{COLOR}{RED}Sometimes I dream about the Colossus\n"
	.string "Temple.\p"
	.string "In my dreams, the statues come to life\n"
	.string "and lead me through secret passages.\p"
	.string "I wonder if there's treasure hidden\n"
	.string "deep inside…$"

WaterwayCity_Text_Girl_2_2:
	.string "{COLOR}{RED}No, sweetie, we have Soda Pop at home.$"

WaterwayCity_Text_Girl_3:
	.string "{COLOR}{RED}I just came here, but my Pokémon are\n"
	.string "itching for adventure!\p"
	.string "Too bad I can't cross the channel\n"
	.string "south of here, 'cause none of my\l"
	.string "Pokémon can learn Surf…$"

WaterwayCity_Text_Lass:
	.string "{COLOR}{RED}Ahh…\p"
	.string "The running water, the fresh sea air,\n"
	.string "the blue sky.\l"
	.string "It's all so romantic!$"

WaterwayCity_Text_Little_Girl:
	.string "{COLOR}{RED}Mom, can we buy a Soda Pop?\n"
	.string "Please?$"

WaterwayCity_Text_Man_1:
	.string "{COLOR}{BLUE}The Colossus Temple has stood for\n"
	.string "centuries.\p"
	.string "They say the stones themselves were\n"
	.string "shaped by the hands of a Pokémon long\l"
	.string "forgotten by time.\p"
	.string "But its spirit might still linger…$"

WaterwayCity_Text_Man_1_2:
	.string "{COLOR}{BLUE}Oh boy!\p"
	.string "There's a boat service that takes you\n"
	.string "to Driftstream Town and back here!\p"
	.string "But it's out of commission for now…$"

WaterwayCity_Text_Man_4:
	.string "{COLOR}{BLUE}There's a cave entrance down there…\p"
	.string "I've lived here all my life, and I've\n"
	.string "never been there.\p"
	.string "Rumors say that the city's ancient\n"
	.string "secret lies within that cave.$"

WaterwayCity_Text_Mart_Employee_1:
	.string "{COLOR}{BLUE}We stock supplies here, but if you\n"
	.string "want to buy anything, you'll have to\l"
	.string "go down to the docks.$"

WaterwayCity_Text_Old_Man:
	.string "You might think living in this city is\n"
	.string "like living in paradise, but no.\l"
	.string "It's only good if you're passing by!\p"
	.string "If you live here, you have to deal\n"
	.string "with the constant humidity that the\l"
	.string "waterfalls bring!$"

WaterwayCity_Text_Old_Woman:
	.string "The Colossus Temple has always been\n"
	.string "shrouded in mystery.\p"
	.string "Some say that one day, a chosen one\n"
	.string "will awaken the sleeping power within,\l"
	.string "and the city will witness a new era.$"

WaterwayCity_Text_PokeFan_F_1:
	.string "{COLOR}{RED}Hey, you're that Trainer from TV!\p"
	.string "And you came all the way from Chandra?\p"
	.string "You must've seen the whole of northern\n"
	.string "Tenjo at this point!\p"
	.string "If you're headed to Moonspring City,\n"
	.string "prepare to see southern Tenjo, too!$"

WaterwayCity_Text_PokeFan_F_2:
	.string "{COLOR}{RED}I come here to gaze at the sea…\n"
	.string "Wishing I could travel.\p"
	.string "You're lucky to be a Trainer, y'know!$"

WaterwayCity_Text_PokeFan_M:
	.string "{COLOR}{BLUE}You can drink the water behind me, but\n"
	.string "you can't drink the water in front…\l"
	.string "Isn't it funny how that works?$"

WaterwayCity_Text_PokeFan_M_2:
	.string "{COLOR}{BLUE}I think Waterway is the most beautiful\n"
	.string "city in Tenjo.\p"
	.string "But I guess I'm biased, since I live\n"
	.string "here.$"

WaterwayCity_Text_Rich_Boy:
	.string "{COLOR}{BLUE}Urp…\p"
	.string "That food from the cantine down at the\n"
	.string "docks I had earlier isn't sitting well…\p"
	.string "And there's not one bathroom in sight!\n"
	.string "I'm doomed!$"

WaterwayCity_Text_Running_Triathlete_F:
	.string "{COLOR}{RED}There's all sorts of merchandise in\n"
	.string "the market here at the docks.\p"
	.string "Every Monday, a Pokémon hairdresser\n"
	.string "sets up shop.$"

WaterwayCity_Text_Sailor:
	.string "{COLOR}{BLUE}Work, work and more work!\p"
	.string "Load crates, unload crates…\n"
	.string "Hoof…\p"
	.string "I could really use a Lava Cookie\n"
	.string "right now…$"

WaterwayCity_Text_School_Kid_M:
	.string "{COLOR}{BLUE}I'm glad all this SUBO stuff has\n"
	.string "stayed away from Waterway City…\l"
	.string "For now.\p"
	.string "But let them come!\p"
	.string "Me and Rhy are ready for them!$"

WaterwayCity_Text_Woman_4:
	.string "{COLOR}{RED}My Wartortle and I love to relax by\n"
	.string "the streams after a long day.\p"
	.string "The water here reminds him of home,\n"
	.string "I think.\p"
	.string "He could sit here for hours, just\n"
	.string "listening to the flowing currents…\l"
	.string "Can't say I blame him!$"

WaterwayCity_Text_Woman_5_1:
	.string "{COLOR}{RED}Careful, don't let your Pokémon wander\n"
	.string "too close to the streams!\l"
	.string "My little Pichu almost fell in once.\p"
	.string "But the water is so calm and clear,\n"
	.string "it's hard to resist.$"

WaterwayCity_Text_Woman_5_2:
	.string "{COLOR}{RED}Living by the water is so peaceful.\p"
	.string "The streams flow through every corner\n"
	.string "of the city, like they're guiding us.\p"
	.string "My morning walks are always refreshing\n"
	.string "with the sound of water by my side.$"

WaterwayCity_Text_Youngster:
	.string "{COLOR}{BLUE}See this item behind me?\n"
	.string "You want it?\p"
	.string "Too bad, I ain't movin'!\n"
	.string "Hahaha!$"

WaterwayCity_Text_Hiker:
	.string "You're going on a long journey, huh?\p"
	.string "Take this Escape Rope.\p"
	.string "It'll help you get out of tough spots\n"
	.string "when you need a quick exit.$"

WaterwayCity_Text_Hiker_Given:
	.string "Good luck on your journey, kiddo.$"
