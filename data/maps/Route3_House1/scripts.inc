Route3_House1_MapScripts::
	.byte 0

Route3_House1_Man::
	lockall
	faceplayer
	goto_if_set FLAG_ROUTE_3_QUEST_STARTED, Route3_House1_Man_Quest_In_Progress
	msgbox Route3_House1_Text_Man_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route3_House1_Man_Yes
	msgbox Route3_House1_Man_Text_No, MSGBOX_DEFAULT
	releaseall
	end

Route3_House1_Man_Yes::
	msgbox Route3_House1_Text_Man_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route3_House1_Man_Quest_Accepted
	msgbox Route3_House1_Man_Text_No, MSGBOX_DEFAULT
	releaseall
	end

Route3_House1_Man_Quest_Accepted::
	msgbox Route3_House1_Text_Man_3, MSGBOX_DEFAULT
	giveitem ITEM_LETTER, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_3_QUEST_STARTED
	goto Route3_House1_Man_Quest_In_Progress
	
Route3_House1_Man_Quest_In_Progress::
	goto_if_set FLAG_ROUTE_3_QUEST_DELIVERED, Route3_House1_Man_Quest_Letter_Delivered
	msgbox Route3_House1_Text_Man_4, MSGBOX_DEFAULT
	releaseall
	end

Route3_House1_Man_Quest_Letter_Delivered::
	goto_if_set FLAG_ROUTE_3_QUEST_COMPLETED, Route3_House1_Man_Quest_Completed
	msgbox Route3_House1_Text_Man_5, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route3_House1_Man_Quest_Letter_Delivered_2
	msgbox Route3_House1_Man_Text_No, MSGBOX_DEFAULT
	releaseall
	end

Route3_House1_Man_Quest_Letter_Delivered_2::
	msgbox Route3_House1_Text_Man_6, MSGBOX_DEFAULT
	giveitem ITEM_TM39, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_3_QUEST_COMPLETED
	msgbox Route3_House1_Text_Man_7, MSGBOX_DEFAULT
	releaseall
	end

Route3_House1_Man_Quest_Completed::
	msgbox Route3_House1_Text_Man_8, MSGBOX_DEFAULT
	releaseall
	end

Route3_House1_Man_Text_No:
	.string "{COLOR}{BLUE}No?\n"
	.string "That's too bad…$"

Route3_House1_Text_Man_1:
	.string "{COLOR}{BLUE}Howdy!\n"
	.string "You're a Pokémon trainer, right?$"

Route3_House1_Text_Man_2:
	.string "{COLOR}{BLUE}Phew! That's great!\n"
	.string "Listen, I need you to do me a favor.\p"
	.string "I have a friend who lives in Greendale\n"
	.string "Village, past Anheim Forest.\p"
	.string "However, Pokémon have been acting very\n"
	.string "strange lately and it is not safe for\l"
	.string "me to walk through the forest alone.\p"
	.string "I need you to take this letter I wrote\n"
	.string "and deliver it to my friend, OK?$"

Route3_House1_Text_Man_3:
	.string "{COLOR}{BLUE}Marvellous! Just marvellous!\n"
	.string "Thank you so much!\p"
	.string "Here you go!$"

Route3_House1_Text_Man_4:
	.string "{COLOR}{BLUE}My friend lives in Greendale Village,\n"
	.string "please deliver my letter safely to her!$"

Route3_House1_Text_Man_5:
	.string "{COLOR}{BLUE}Hey, trainer! Nice to see you again!\n"
	.string "Did you deliver my letter safely?$"

Route3_House1_Text_Man_6:
	.string "{COLOR}{BLUE}Marvellous! Just marvellous!\n"
	.string "Thank you so much!\p"
	.string "Please take this as a token of my\n"
	.string "appreciation.$"

Route3_House1_Text_Man_7:
	.string "{COLOR}{BLUE}TM39 contains Rock Tomb!\p"
	.string "Rock Tomb deals damage and lowers the\n"
	.string "opponent's Speed.$"

Route3_House1_Text_Man_8:
	.string "{COLOR}{BLUE}Thanks again for delivering my letter\n"
	.string "safely to my friend.\n"
	.string "Feel free to fish in my garden pond\n"
	.string "anytime you like!$"
