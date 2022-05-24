NorthstarCity_TrainerSchool_MapScripts::
	.byte 0

NorthstarCity_TrainerSchool_Psychic::
	msgbox NorthstarCity_TrainerSchool_Text_Psychic, MSGBOX_NPC
	end

NorthstarCity_TrainerSchool_Little_Girl::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_NORTHSTAR_GREAT_BALL, NorthstarCity_TrainerSchool_Little_Girl_Given
	msgbox NorthstarCity_TrainerSchool_Text_Little_Girl, MSGBOX_NPC
	giveitem ITEM_GREAT_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_NORTHSTAR_GREAT_BALL
	closemessage
	releaseall
	end

NorthstarCity_TrainerSchool_Little_Girl_Given:
	msgbox NorthstarCity_TrainerSchool_Text_Little_Girl_Given, MSGBOX_DEFAULT
	releaseall
	end

NorthstarCity_TrainerSchool_Girl::
	msgbox NorthstarCity_TrainerSchool_Text_Girl, MSGBOX_NPC
	end

NorthstarCity_TrainerSchool_Teacher::
	msgbox NorthstarCity_TrainerSchool_Text_Teacher, MSGBOX_NPC
	end

NorthstarCity_TrainerSchool_Text_Psychic:
	.string "We are studying double battles!\n"
	.string "Here's what I have learned, so far…\p"
	.string "Moves like Discharge, Earthquake,\n"
	.string "Magnitude, Explosion, Self-Destruct,\l"
	.string "and Teeter Dance will hit all other\l"
	.string "Pokémon, including your ally.\p"
	.string "By using Earthquake when your other\n"
	.string "Pokémon is either a Flying-type or has\l"
	.string "Levitate, it will make it immune to\l"
	.string "the Ground-type Earthquake.$"

NorthstarCity_TrainerSchool_Text_Little_Girl:
	.string "{COLOR}{RED}This ball is ugly -- you can have it!$"

NorthstarCity_TrainerSchool_Text_Little_Girl_Given:
	.string "{COLOR}{RED}Red is my favorite color, so Poké\n"
	.string "Balls are my favorite ball!$"

NorthstarCity_TrainerSchool_Text_Girl:
	.string "{COLOR}{RED}I love double battles.\n"
	.string "I do as many of them as possible.\p"
	.string "Certain moves will hit both opposing\n"
	.string "Pokémon in a double battle.\p"
	.string "Some of these are: Air Cutter, Acid,\n"
	.string "Eruption, Heat Wave, Growl, Leer,\l"
	.string "Razor Leaf, Rock Slide, and Surf.\p"
	.string "Oh boy…\n"
	.string "I'm gonna ace this exam!$"

NorthstarCity_TrainerSchool_Text_Teacher:
	.string "Now, now…\n"
	.string "Don't distract my students.\p"
	.string "I don't get paid an average wage to\n"
	.string "build a new generation of idiots!$"
