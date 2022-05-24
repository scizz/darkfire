GreendaleVillage_MapScripts::
	.byte 0

GreendaleVillage_Sign::
	msgbox GreendaleVillage_Text_Sign, MSGBOX_SIGN
	end

GreendaleVillage_Sign_School::
	msgbox GreendaleVillage_Text_Sign_School, MSGBOX_SIGN
	end

GreendaleVillage_Sign_Park::
	msgbox GreendaleVillage_Text_Sign_Park, MSGBOX_SIGN
	end

GreendaleVillage_Old_Woman::
	msgbox GreendaleVillage_Text_Old_Woman, MSGBOX_NPC
	end

GreendaleVillage_Old_Man::
	msgbox GreendaleVillage_Text_Old_Man, MSGBOX_NPC
	end

GreendaleVillage_Woman::
	msgbox GreendaleVillage_Text_Woman, MSGBOX_NPC
	end

GreendaleVillage_Little_Boy::
	msgbox GreendaleVillage_Text_Little_Boy, MSGBOX_NPC
	end

GreendaleVillage_Little_Girl::
	msgbox GreendaleVillage_Text_Little_Girl, MSGBOX_NPC
	end

GreendaleVillage_Vendor::
	lock
	faceplayer
	goto_if_set FLAG_GREENDALE_VILLAGE_GREAT_BALL, GreendaleVillage_Vendor_Given
	msgbox GreendaleVillage_Text_Vendor, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_GREENDALE_VILLAGE_GREAT_BALL
	goto GreendaleVillage_Vendor_Given

GreendaleVillage_Vendor_Given::
	msgbox GreendaleVillage_Text_Vendor_Given, MSGBOX_DEFAULT
	release
	end

GreendaleVillage_Text_Sign:
	.string "Greendale Village\n"
	.string "Let our scents mesmerize your senses!$"

GreendaleVillage_Text_Sign_School:
	.string "Welcome to the Greendale Village\n"
	.string "Trainer School.$"

GreendaleVillage_Text_Sign_Park:
	.string "Greendale Village Park.\n"
	.string "Thank you for not littering.$"

GreendaleVillage_Text_Old_Woman:
	.string "Life has always been the best living\n"
	.string "in this small village.\p"
	.string "I only wish I could see my grandson\n"
	.string "more often.\p"
	.string "He works as a Pokémon Researcher at\n"
	.string "the Government Offices in Union City.$"

GreendaleVillage_Text_Old_Man:
	.string "This is the real secret of life…\p"
	.string "To be completely engaged with what you\n"
	.string "are doing in the here and now.\p"
	.string "And instead of calling it work,\n"
	.string "realize it is play.$"

GreendaleVillage_Text_Woman:
	.string "{COLOR}{RED}My kids go to the Trainer School next\n"
	.string "door.\p"
	.string "I want them to become Trainers and\n"
	.string "spread their wings and fly!$"

GreendaleVillage_Text_Little_Boy:
	.string "{COLOR}{BLUE}Stranger… Help me catch her…\n"
	.string "Please!$"

GreendaleVillage_Text_Little_Girl:
	.string "{COLOR}{RED}You can't catch me!\n"
	.string "Hahaha!$"

GreendaleVillage_Text_Vendor:
	.string "{COLOR}{BLUE}We just finished stocking Great Balls\n"
	.string "inside our shop.\p"
	.string "Here's a free sample!$"

GreendaleVillage_Text_Vendor_Given:
	.string "{COLOR}{BLUE}Go inside our shop if you'd like to take\n"
	.string "a look at our wares!$"
