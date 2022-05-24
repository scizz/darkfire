AnheimTown_House2_MapScripts::
	.byte 0

AnheimTown_House2_Boy_1::
	msgbox AnheimTown_House2_Text_Boy_1, MSGBOX_NPC
	end

AnheimTown_House2_Girl::
	msgbox AnheimTown_House2_Text_Girl, MSGBOX_NPC
	end

AnheimTown_House2_Old_Man_1::
	lockall
	faceplayer
	msgbox AnheimTown_House2_Text_Old_Man_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq AnheimTown_House2_Old_Man_1_Yes
	msgbox AnheimTown_House2_Text_Old_Man_1_No, MSGBOX_DEFAULT
	releaseall
	end

AnheimTown_House2_Old_Man_1_Yes::
	msgbox AnheimTown_House2_Text_Old_Man_1_Yes, MSGBOX_DEFAULT
	releaseall
	end

AnheimTown_House2_Old_Man_2::
	msgbox AnheimTown_House2_Text_Old_Man_2, MSGBOX_NPC
	end

AnheimTown_House2_Boy_2::
	msgbox AnheimTown_House2_Text_Boy_2, MSGBOX_NPC
	end

AnheimTown_House2_Text_Boy_1:
	.string "{COLOR}{BLUE}Although this town is small in size,\n"
	.string "it has a history that is great.\p"
	.string "The first recorded Dragonite was seen\n"
	.string "flying above this very town, hundreds\l"
	.string "of years ago.$"

AnheimTown_House2_Text_Girl:
	.string "{COLOR}{RED}My daughter likes to stand at the\n"
	.string "front of the house and greet Hikers.\p"
	.string "She loves to tell the story of the\n"
	.string "Wise Pathfinder. Have you heard it?$"

AnheimTown_House2_Text_Old_Man_1:
	.string "Greetings, Trainer.\p"
	.string "Do you want to hear about the Mythical\n"
	.string "Pokémon, Celebi?$"

AnheimTown_House2_Text_Old_Man_1_No:
	.string "Very well.\n"
	.string "Goodbye.$"

AnheimTown_House2_Text_Old_Man_1_Yes:
	.string "Wonderful!\pThey say Celebi has the power to\n"
	.string "travel through time, and thus wanders\l"
	.string "from one age to the next.\p"
	.string "It is considered a diety by the\n"
	.string "forests.\p"
	.string "Plant life is said to grow in sheer\n"
	.string "abundance wherever Celebi visits.\p"
	.string "Like Mew, Celebi is a Pokémon shrouded\n"
	.string "in mystery.\p"
	.string "Its special techniques blend Grass and\n"
	.string "Psychic powers.$"

AnheimTown_House2_Text_Old_Man_2:
	.string "The Protector of The Forest was like\n"
	.string "no ordinary being.\p"
	.string "It was a green fairy-like creature.\p"
	.string "It had round toeless feet and clear\n"
	.string "wings on its back.\p"
	.string "It had a round head that comes to a\n"
	.string "curved point and large baby-blue eyes\l"
	.string "with thick black rings around them.\p"
	.string "From its head stemmed a pair of green\n"
	.string "antennae with blue tips.\p"
	.string "It was no ordinary being.\p"
	.string "It was extraordinary.$"

AnheimTown_House2_Text_Boy_2:
	.string "{COLOR}{BLUE}Grandpa is telling us the story of\n"
	.string "the Mythical Pokémon, Celebi.\p"
	.string "Celebi is known in legend as the\n"
	.string "“Voice of the Forest”.\p"
	.string "Grandpa says that Celebi only shows\n"
	.string "itself in areas and times of peace.\p"
	.string "With these SUBO guys running around,\n"
	.string "I doubt we will ever see Celebi…$"
