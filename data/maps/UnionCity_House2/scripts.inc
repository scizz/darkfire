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
