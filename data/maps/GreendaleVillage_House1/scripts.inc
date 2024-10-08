GreendaleVillage_House1_MapScripts::
	.byte 0

GreendaleVillage_House1_Woman::
	lockall
	faceplayer
	goto_if_set FLAG_ROUTE_3_QUEST_COMPLETED, GreendaleVillage_House1_Woman_Quest_Completed
	msgbox GreendaleVillage_House1_Text_Woman_1, MSGBOX_AUTOCLOSE
	goto_if_set FLAG_ROUTE_3_QUEST_STARTED, GreendaleVillage_House1_Woman_Quest_Started
	releaseall
	end

GreendaleVillage_House1_Woman_Quest_Started::
	emote 1, 7
	playse SE_PIN
	waitse
	checkitem ITEM_LETTER, 1
	compare VAR_RESULT, 1
	goto_if_ge GreendaleVillage_House1_Woman_Quest_Got_Letter
	msgbox GreendaleVillage_House1_Text_Woman_3, MSGBOX_AUTOCLOSE
	releaseall
	end

GreendaleVillage_House1_Woman_Quest_Got_Letter::
	msgbox GreendaleVillage_House1_Text_Woman_4, MSGBOX_AUTOCLOSE
	delay 30
	msgbox Action_Letter_Handover, MSGBOX_AUTOCLOSE
	removeitem ITEM_LETTER, 1
	delay 30
	emote 1, 6
	playse SE_PIN
	waitse
	msgbox GreendaleVillage_House1_Text_Woman_5, MSGBOX_AUTOCLOSE
	setflag FLAG_ROUTE_3_QUEST_DELIVERED
	releaseall
	end

GreendaleVillage_House1_Woman_Quest_Completed::
	msgbox GreendaleVillage_House1_Text_Woman_2, MSGBOX_AUTOCLOSE
	releaseall
	end

GreendaleVillage_House1_Text_Woman_1:
	.string "{COLOR}{RED}I have a friend who lives near Union\n"
	.string "City.\p"
	.string "He used to visit every weekend to keep\n"
	.string "me company, but I haven't heard\l"
	.string "anything from him in a while.\p"
	.string "I hope I haven't done anything to\n"
	.string "upset him…$"

GreendaleVillage_House1_Text_Woman_2:
	.string "{COLOR}{RED}I really hope my friend can visit me\n"
	.string "again once he finds a new Pokémon.$"

GreendaleVillage_House1_Text_Woman_3:
	.string "{COLOR}{RED}What's that? He wrote me a Letter?\n"
	.string "Please get it and return it to me!$"

GreendaleVillage_House1_Text_Woman_4:
	.string "{COLOR}{RED}What's that? He wrote me a Letter?\n"
	.string "Please, hand it over!$"

GreendaleVillage_House1_Text_Woman_5:
	.string "{COLOR}{RED}Wow, thank you so much for bringing\n"
	.string "this to me, my dear!\p"
	.string "If you see him again, please give him\n"
	.string "my best regards!$"

Action_Letter_Handover:
	.string "You handed the Letter to the lady.$"
