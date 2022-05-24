GreendaleVillage_RoseHouse_MapScripts::
	.byte 0

GreendaleVillage_RoseHouse_Father::
	goto_if_set FLAG_TEMP_1, GreendaleVillage_RoseHouse_Father_Spoken_To
	msgbox GreendaleVillage_RoseHouse_Text_Father, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

GreendaleVillage_RoseHouse_Father_Spoken_To::
	msgbox GreendaleVillage_RoseHouse_Text_Father_Spoken_To, MSGBOX_NPC
	end

GreendaleVillage_RoseHouse_Mother::
	goto_if_set FLAG_TEMP_2, GreendaleVillage_RoseHouse_Mother_Spoken_To
	msgbox GreendaleVillage_RoseHouse_Text_Mother, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end

GreendaleVillage_RoseHouse_Mother_Spoken_To::
	msgbox GreendaleVillage_RoseHouse_Text_Mother_Spoken_To, MSGBOX_NPC
	end

GreendaleVillage_RoseHouse_Text_Father:
	.string "{COLOR}{BLUE}Hello, {PLAYER}!\n"
	.string "It's a real pleasure to see you again!$"

GreendaleVillage_RoseHouse_Text_Father_Spoken_To:
	.string "{COLOR}{BLUE}I am such a proud father.\n"
	.string "Rose is surely growing up fast!$"

GreendaleVillage_RoseHouse_Text_Mother:
	.string "{COLOR}{RED}Hello, {PLAYER}!\n"
	.string "What a nice surprise!\p"
	.string "Rose has set off on her own journey.\p"
	.string "If you ever see her, please tell her\n"
	.string "that we miss her!$"

GreendaleVillage_RoseHouse_Text_Mother_Spoken_To:
	.string "{COLOR}{RED}Rose has set off on her own journey.\p"
	.string "If you ever see her, please tell her\n"
	.string "that we miss her!$"
