NorthstarCity_Interlink_MapScripts::
	.byte 0

NorthstarCity_Interlink_Chef::
	msgbox NorthstarCity_Interlink_Text_Chef, MSGBOX_NPC
	end

NorthstarCity_Interlink_Sailor::
	msgbox NorthstarCity_Interlink_Text_Sailor, MSGBOX_NPC
	end

NorthstarCity_Interlink_Text_Chef:
	.string "{COLOR}{BLUE}Hey, good lookin'.\n"
	.string "What you got cookin'?\p"
	.string "What? Not you, kid!\n"
	.string "I'm listening to music!$"

NorthstarCity_Interlink_Text_Sailor:
	.string "{COLOR}{BLUE}Well, hello, Trainer!\n"
	.string "Here's some Sailor advice!\p"
	.string "May your anchor be tight, may your\n"
	.string "cork be loose.\p"
	.string "May your rum be spiced, and your\n"
	.string "compass be true!\p"
	.string "Go get em, kid!$"
