NorthstarCity_MapScripts::
	.byte 0

NorthstarCity_Old_Man::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Old_Man_Badge
	msgbox NorthstarCity_Text_Old_Man, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Old_Man_Badge::
	msgbox NorthstarCity_Text_Old_Man_Badge, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Youngster::
	msgbox NorthstarCity_Text_Youngster, MSGBOX_NPC
	end

NorthstarCity_Thug::
	msgbox NorthstarCity_Text_Thug, MSGBOX_NPC
	end

NorthstarCity_SUBO_1::
	msgbox NorthstarCity_Text_SUBO_1, MSGBOX_NPC
	end

NorthstarCity_Guitarist::
	msgbox NorthstarCity_Text_Guitarist, MSGBOX_NPC
	end

NorthstarCity_Nerd::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Nerd_Badge
	msgbox NorthstarCity_Text_Nerd, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Nerd_Badge::
	msgbox NorthstarCity_Text_Nerd_Badge, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Fat_Man::
	msgbox NorthstarCity_Text_Fat_Man, MSGBOX_NPC
	end

NorthstarCity_SUBO_2::
	lockall
	msgbox NorthstarCity_Text_SUBO_2, MSGBOX_DEFAULT
	applymovement 13, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 13, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox NorthstarCity_Text_SUBO_2_Caught, MSGBOX_DEFAULT
	applymovement 13, Common_Movement_FaceRight
	waitmovement 0
	releaseall
	end

NorthstarCity_Old_Man_2::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq NorthstarCity_Old_Man_2_Male
	msgbox NorthstarCity_Text_Old_Man_2_Female, MSGBOX_NPC
	end

NorthstarCity_Old_Man_2_Male::
	msgbox NorthstarCity_Text_Old_Man_2_Male, MSGBOX_NPC
	end

NorthstarCity_Ace_Trainer::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Ace_Trainer_Badge
	msgbox NorthstarCity_Text_Ace_Trainer, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Ace_Trainer_Badge::
	msgbox NorthstarCity_Text_Ace_Trainer_Badge, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Woman_3::
	msgbox NorthstarCity_Text_Woman_3, MSGBOX_NPC
	end

NorthstarCity_Girl::
	msgbox NorthstarCity_Text_Girl, MSGBOX_NPC
	end

NorthstarCity_SUBO_3::
	msgbox NorthstarCity_Text_SUBO_3, MSGBOX_NPC
	end

NorthstarCity_Sailor_1::
	msgbox NorthstarCity_Text_Sailor_1, MSGBOX_NPC
	end

NorthstarCity_Sailor_2::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Text_Sailor_2_Badge
	msgbox NorthstarCity_Text_Sailor_2, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_Sailor_3::
	msgbox NorthstarCity_Text_Sailor_3, MSGBOX_NPC
	end

NorthstarCity_Sailor_4::
	msgbox NorthstarCity_Text_Sailor_4, MSGBOX_NPC
	end

NorthstarCity_Sailor_5::
	msgbox NorthstarCity_Text_Sailor_5, MSGBOX_NPC
	end

NorthstarCity_Fisherman::
	msgbox NorthstarCity_Text_Fisherman, MSGBOX_NPC
	end

NorthstarCity_PokeFan_M::
	msgbox NorthstarCity_Text_PokeFan_M, MSGBOX_NPC
	end

NorthstarCity_Text_Old_Man_Badge:
	.string "That badge…\n"
	.string "You beat the Northstar Tournament!\p"
	.string "Seeing such young talent makes an old\n"
	.string "man like me smile from ear to ear!$"

NorthstarCity_Text_Old_Man:
	.string "Greetings!\n"
	.string "You look like a Trainer!\p"
	.string "We've had a strong surge of Trainers\n"
	.string "coming from the south recently.\p"
	.string "I'll bet that you are here for the\n"
	.string "Northstar Tournament.\l"
	.string "Am I right? Ha!$"

NorthstarCity_Text_Youngster:
	.string "{COLOR}{BLUE}Brrr…\p"
	.string "I can't believe I made it through all\n"
	.string "that snow. Alone!\p"
	.string "Where is my medal?!\p"
	.string "There has to be some sort of medal for\n"
	.string "this feat!$"

NorthstarCity_Text_Thug:
	.string "{COLOR}{BLUE}Yo, why're you here?\n"
	.string "You lookin' for trouble?\p"
	.string "Be glad I'm saving my energy, else I'd\n"
	.string "grind you to dust!$"

NorthstarCity_Text_SUBO_1:
	.string "{COLOR}{BLUE}I was looking for the Mart, but I got\n"
	.string "lost in this damned city.\p"
	.string "Why did we even come here?\n"
	.string "They never tell us anything.\l"
	.string "I should have never left Anheim Town…$"

NorthstarCity_Text_Guitarist:
	.string "{COLOR}{BLUE}Those SUBO showed up outta nowhere and\n"
	.string "started takin' our corners.\p"
	.string "That's how I ended up hanging around\n"
	.string "this back alley.\p"
	.string "I tried going back to my old spot, but\n"
	.string "their Pokémon are so tough, I just got\l"
	.string "sent packing to the Pokémon Center.\p"
	.string "Don't underestimate 'em like I did…$"

NorthstarCity_Text_Nerd:
	.string "{COLOR}{BLUE}You mean to tell me you made it all\n"
	.string "the way here on foot?\p"
	.string "That is astonishing…\n"
	.string "You're quite the Trainer!$"

NorthstarCity_Text_Nerd_Badge:
	.string "{COLOR}{BLUE}Flying around on Pokémon is cool.\n"
	.string "Surfing around on Pokémon is cooler.\p"
	.string "But the Trainers who made it here on\n"
	.string "foot…"
	.string "They're the coolest.$"

NorthstarCity_Text_Fat_Man:
	.string "{COLOR}{BLUE}Northstar is the jewel of northern\n"
	.string "Tenjo, but we don't have a large Mart\l"
	.string "to compete with the one in Union City.\p"
	.string "Welp, at least we have our docks…$"

NorthstarCity_Text_SUBO_2:
	.string "{COLOR}{BLUE}Beep Beep…\p"
	.string "Favorable spot, taken. Over.\p"
	.string "…\n"
	.string "…\p"
	.string "Roger. I can see the target building\n"
	.string "from here.\p"
	.string "Standing by--$"

NorthstarCity_Text_SUBO_2_Caught:
	.string "{COLOR}{BLUE}Huh?!\n"
	.string "Who are you?!\p"
	.string "Get out of here, before I lose my\n"
	.string "temper!$"

NorthstarCity_Text_Old_Man_2_Female:
	.string "One of these SUBO people almost knocked\n"
	.string "me over earlier… The nerve of them!\p"
	.string "Young lady… Will you teach them a\n"
	.string "lesson for me?$"

NorthstarCity_Text_Old_Man_2_Male:
	.string "One of these SUBO people almost knocked\n"
	.string "me over earlier… The nerve of them!\p"
	.string "Young man… Will you teach them a\n"
	.string "lesson for me?$"

NorthstarCity_Text_Ace_Trainer:
	.string "{COLOR}{BLUE}Here for the tournament?\n"
	.string "Of course you are!\p"
	.string "Best of luck, to the both of us.$"

NorthstarCity_Text_Ace_Trainer_Badge:
	.string "{COLOR}{BLUE}Wow, you actually…\n"
	.string "You won the Northstar tournament!\p"
	.string "Heh, heh…\n"
	.string "I guess you're tougher than you look!$"

NorthstarCity_Text_Woman_3:
	.string "{COLOR}{RED}The farther you travel north in Tenjo,\n"
	.string "the rougher the people you'll find.\p"
	.string "No… I don't belong here.\n"
	.string "I'll get a ferry back to the south…$"

NorthstarCity_Text_Girl:
	.string "{COLOR}{RED}The Director of the Northstar TV\n"
	.string "Station is super talented.\p"
	.string "He makes it look like the tournament\n"
	.string "participants are battling in the sky!$"

NorthstarCity_Text_SUBO_3:
	.string "{COLOR}{BLUE}Yo, who in the world does that guy over\n"
	.string "there think he is?\p"
	.string "I went to board the ship but he almost\n"
	.string "beat me to a pulp!$"

NorthstarCity_Text_Sailor_1:
	.string "{COLOR}{BLUE}This is Tenjo's finest, right here…\n"
	.string "Northstar City's big and busy port!\p"
	.string "Feast your eyes, kid. As a sailor, I\n"
	.string "wouldn't have it any other way! Fwaha!$"

NorthstarCity_Text_Sailor_2:
	.string "{COLOR}{BLUE}I just got home from Slateport, and\n"
	.string "what do I see?\p"
	.string "The city's infested with SUBO scum!\n"
	.string "Unbelievable.$"

NorthstarCity_Text_Sailor_2_Badge:
	.string "{COLOR}{BLUE}I'm leaving on another journey to\n"
	.string "Hoenn soon.\p"
	.string "It'll be one of my last journeys\n"
	.string "before I settle down and retire.$"

NorthstarCity_Text_Sailor_3:
	.string "{COLOR}{BLUE}What're you doing here?\p"
	.string "You've not come to lend a hand with\n"
	.string "these crates, have you?$"

NorthstarCity_Text_Sailor_4:
	.string "{COLOR}{BLUE}Huff, huff, huff, work, work, work…\n"
	.string "Get out of my way, kid!$"

NorthstarCity_Text_Sailor_5:
	.string "{COLOR}{BLUE}There's traffic at the docks, as\n"
	.string "usual.\l"
	.string "Can't complain, though.\p"
	.string "More people, more business, more money\n"
	.string "for all of us!$"

NorthstarCity_Text_Fisherman:
	.string "{COLOR}{BLUE}Tried to fish here, nothing bites.\p"
	.string "Those darn ferries are scaring off\n"
	.string "the fish!$"

NorthstarCity_Text_PokeFan_M:
	.string "{COLOR}{BLUE}The building with the striking red\n"
	.string "roof you see is the shipping office.\p"
	.string "Any cargo that goes in or out the city\n"
	.string "is checked through there.\p"
	.string "I tried to get my son a job there,\n"
	.string "but all he wants to do is hang out\l"
	.string "with bad company in the upper west…$"
