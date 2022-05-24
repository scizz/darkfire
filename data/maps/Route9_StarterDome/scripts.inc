Route9_StarterDome_MapScripts::
	.byte 0

Route9_StarterDome_Aide_Left_Table::
	msgbox Route9_StarterDome_Text_Aide_Left_Table, MSGBOX_NPC
	end

Route9_StarterDome_Aide_PC::
	lock
	faceplayer
	msgbox Route9_StarterDome_Text_Aide_PC, MSGBOX_DEFAULT
	applymovement 12, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

Route9_StarterDome_Aide_Walk_Around::
	msgbox Route9_StarterDome_Text_Aide_Walk_Around, MSGBOX_NPC
	end

Route9_StarterDome_Aide_Right_Table::
	msgbox Route9_StarterDome_Text_Aide_Right_Table, MSGBOX_NPC
	end

Route9_StarterDome_Aide_Bed::
	lock
	faceplayer
	goto_if_set FLAG_STARTER_DOME_POTION Route9_StarterDome_Aide_Bed_Given
	msgbox Route9_StarterDome_Text_Aide_Bed, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 1
	setflag FLAG_STARTER_DOME_POTION
	goto Route9_StarterDome_Aide_Bed_Given

Route9_StarterDome_Aide_Bed_Given::
	msgbox Route9_StarterDome_Text_Aide_Bed_Given, MSGBOX_DEFAULT
	release
	end

Route9_StarterDome_Ace_Trainer::
	msgbox Route9_StarterDome_Text_Ace_Trainer, MSGBOX_NPC
	end

Route9_StarterDome_Little_Girl::
	msgbox Route9_StarterDome_Text_Little_Girl_Male, MSGBOX_NPC
	end

Route9_StarterDome_Mother::
	msgbox Route9_StarterDome_Text_Mother, MSGBOX_NPC
	end

Route9_StarterDome_Little_Boy::
	lock
	faceplayer
	msgbox Route9_StarterDome_Text_Little_Boy, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Route9_StarterDome_Girl::
	msgbox Route9_StarterDome_Text_Girl, MSGBOX_NPC
	end

Route9_StarterDome_Fat_Guy::
	msgbox Route9_StarterDome_Text_Fat_Guy, MSGBOX_NPC
	end

Route9_StarterDome_Youngster::
	msgbox Route9_StarterDome_Text_Youngster, MSGBOX_NPC
	end

Route9_StarterDome_Text_Aide_Left_Table:
	.string "{COLOR}{BLUE}H-wha'?\p"
	.string "Oh…\p"
	.string "Hello, kid…\n"
	.string "Sorry. I'm working right now.\p"
	.string "Go play with that machine behind me,\n"
	.string "or something… It's a special PC.$"

Route9_StarterDome_Text_Aide_PC:
	.string "{COLOR}{BLUE}The Pokémon Dome Laboratory is truly a\n"
	.string "technological miracle.\p"
	.string "We use state-of-the-art machinery to\n"
	.string "harness renewable energy sources such\l"
	.string "as the sun and the wind to provide\l"
	.string "cosy housing for all Pokémon here.$"

Route9_StarterDome_Text_Aide_Walk_Around:
	.string "{COLOR}{BLUE}The Rangers' Federation is helping us\n"
	.string "with breeding, training and studying\l"
	.string "certain rare Pokémon within this Dome.\p"
	.string "But, none of it would be possible\n"
	.string "without the aid we receive from the\l"
	.string "Tenjo Government.$"

Route9_StarterDome_Text_Aide_Right_Table:
	.string "{COLOR}{BLUE}Thanks to our Beginner Trainer\n"
	.string "Program, dozens of Trainers will be\l"
	.string "able to start their quest after\l"
	.string "earning their first Pokémon.\p"
	.string "The children of today are so lucky!$"

Route9_StarterDome_Text_Aide_Bed:
	.string "{COLOR}{BLUE}What's that?\p"
	.string "You came all this way from Chandra\n"
	.string "Village?\p"
	.string "Goodness me, that's quite a long way\n"
	.string "away.\p"
	.string "Tell you what…\n"
	.string "Take this!$"

Route9_StarterDome_Text_Aide_Bed_Given:
	.string "{COLOR}{BLUE}If you need to heal your Pokémon,\n"
	.string "just use these beds over here.\p"
	.string "You can also access our special PC if\n"
	.string "you need to change your party.\p"
	.string "It's the big machine by the entrance\n"
	.string "of the Dome.$"

Route9_StarterDome_Text_Ace_Trainer:
	.string "{COLOR}{BLUE}Fire-types are the best!\p"
	.string "There's nothing and nobody on this\n"
	.string "earth that can change my mind.\p"
	.string "Fire-types for life!$"

Route9_StarterDome_Text_Little_Girl_Female:
	.string "{COLOR}{RED}Wah!\p"
	.string "You scared me, lady!$"

Route9_StarterDome_Text_Little_Girl_Male:
	.string "{COLOR}{RED}Wah!\p"
	.string "You scared me, mister!$"

Route9_StarterDome_Text_Mother:
	.string "{COLOR}{RED}I'm here to witness my daughter get\n"
	.string "her first Pokémon.\l"
	.string "It is truly a special moment.\p"
	.string "It reminds me of the time when my two\n"
	.string "sons got their first Pokémon, too.\l"
	.string "You should have seen their faces!\p"
	.string "My daughter's natural love for Pokémon\n"
	.string "and people tells me that she will be a\l"
	.string "better Trainer than her elder brothers.$"

Route9_StarterDome_Text_Little_Boy:
	.string "{COLOR}{BLUE}Look! Water-type Pokémon!\n"
	.string "My favorite…\p"
	.string "I know I'll get Squirtle when I'm 10.$"

Route9_StarterDome_Text_Girl:
	.string "{COLOR}{RED}I don't know what starter Pokémon I\n"
	.string "should pick… They are all cute!$"

Route9_StarterDome_Text_Fat_Guy:
	.string "{COLOR}{BLUE}I can feel the heat of those Fire-type\n"
	.string "Pokémon even through the glass!\p"
	.string "Pokémon are such amazing creatures.$"

Route9_StarterDome_Text_Youngster:
	.string "{COLOR}{BLUE}$I think I'm gonna go for a Water-type\n"
	.string "Pokémon. Water-types are my thing!\p"
	.string "I want to Surf the Tenjo seas with\n"
	.string "one, some day…$"
