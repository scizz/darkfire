GreendaleVillage_House1_MapScripts::
	.byte 0

GreendaleVillage_House1_Woman::
	lockall
	faceplayer
	goto_if_set FLAG_ROUTE_3_QUEST_COMPLETED, GreendaleVillage_House1_Woman_Quest_Completed
	msgbox GreendaleVillage_House1_Text_Woman_1, MSGBOX_DEFAULT
	goto_if_set FLAG_ROUTE_3_QUEST_STARTED, GreendaleVillage_House1_Woman_Quest_Started
	releaseall
	end

GreendaleVillage_House1_Woman_Quest_Started::
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	checkitem ITEM_LETTER, 1
	compare VAR_RESULT, 1
	goto_if_ge GreendaleVillage_House1_Woman_Quest_Got_Letter
	msgbox GreendaleVillage_House1_Text_Woman_3, MSGBOX_DEFAULT
	releaseall
	end

GreendaleVillage_House1_Woman_Quest_Got_Letter::
	msgbox GreendaleVillage_House1_Text_Woman_4, MSGBOX_DEFAULT
	delay 30
	msgbox Action_Letter_Handover, MSGBOX_DEFAULT
	removeitem ITEM_LETTER, 1
	delay 30
	applymovement 1, Common_Movement_Heart
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox GreendaleVillage_House1_Text_Woman_5, MSGBOX_DEFAULT
	setflag FLAG_ROUTE_3_QUEST_COMPLETED
	releaseall
	end

GreendaleVillage_House1_Woman_Quest_Completed::
	msgbox GreendaleVillage_House1_Text_Woman_2, MSGBOX_DEFAULT
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
