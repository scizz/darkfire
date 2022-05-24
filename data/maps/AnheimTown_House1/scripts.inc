AnheimTown_House1_MapScripts::
	.byte 0

AnheimTown_House1_Man::
	msgbox AnheimTown_House1_Text_Man, MSGBOX_NPC
	end

AnheimTown_House1_Little_Boy::
	msgbox AnheimTown_House1_Text_Little_Boy, MSGBOX_NPC
	end

AnheimTown_House1_Text_Man:
	.string "{COLOR}{BLUE}Huh, wha-?\n"
	.string "Who are you?\p"
	.string "Who do you work for?\n"
	.string "Are you one of those SUBO guys?\p"
	.string "Go away!$"

AnheimTown_House1_Text_Little_Boy:
	.string "{COLOR}{BLUE}I accidentally knocked this\n"
	.string "painting off the wall.\n"
	.string "Please don't tell my dad.\n"
	.string "He seems in a bad mood…$"
