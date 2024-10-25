Route14_MapScripts::
	.byte 0

Route14_Girl_1::
	msgbox Route14_Text_Girl_1, MSGBOX_NPC
	end

Route14_Youngster::
	msgbox Route14_Text_Youngster, MSGBOX_NPC
	end

Route14_Text_Girl_1:
	.string "{COLOR}{RED}Greetings, Trainer.\p"
	.string "The road ahead is harsh and the desert\n"
	.string "is treacherous.\p"
	.string "Moonspring City is to the southeast.\p"
	.string "Choose your path carefully, or you\n"
	.string "will be lost in the shifting sands.$"

Route14_Text_Youngster:
	.string "{COLOR}{BLUE}I came all this way through Route 13,\n"
	.string "but now I can't seem to go on.\p"
	.string "The sight is pretty daunting.\n"
	.string "The sands just go on and on forever…$"
