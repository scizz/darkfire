HighwindVillage_MapScripts::
	.byte 0

HighwindVillage_Sign::
	msgbox HighwindVillage_Text_Sign, MSGBOX_SIGN
	end

HighwindVillage_Sign_Rangers_Lodge::
	msgbox HighwindVillage_Text_Sign_Rangers_Lodge, MSGBOX_SIGN
	end

HighwindVillage_Grandma::
	msgbox HighwindVillage_Text_Grandma, MSGBOX_NPC
	end

HighwindVillage_Little_Boy::
	msgbox HighwindVillage_Text_Little_Boy, MSGBOX_NPC
	end

HighwindVillage_Text_Sign:
	.string "Highwind Village\n"
	.string "It's never too cold for ice cream!$"

HighwindVillage_Text_Sign_Rangers_Lodge:
	.string "Rangers' Federation Lodge\n"
	.string "Members only.$"

HighwindVillage_Text_Grandma:
	.string "This village is the quietest in all of\n"
	.string "Tenjo, I bet you.\p"
	.string "The loudest thing is the whirring of\n"
	.string "the icy wind.$"

HighwindVillage_Text_Little_Boy:
	.string "{COLOR}{BLUE}Wee! Look what I built! A snowman!\n"
	.string "He'll never melt, there's no way.$"
