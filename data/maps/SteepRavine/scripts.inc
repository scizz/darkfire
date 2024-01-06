SteepRavine_MapScripts::
	.byte 0

SteepRavine_ClimbUp::
	lock
	speakername CommonName_Text_Ranger
	msgbox SteepRavine_Text_IsThatYouTrainer, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq SteepRavine_ClimbUp_Yes
	msgbox SteepRavine_Text_JustLetMeKnow, MSGBOX_AUTOCLOSE
	release
	end

SteepRavine_ClimbUp_Yes::
	closemessage
	warp MAP_ROUTE6, 55, 18
	waitstate
	end

SteepRavine_Text_IsThatYouTrainer:
	.string "{COLOR}{BLUE}Is that you, Trainer?\n"
	.string "Do you want to come back up?$"

SteepRavine_Text_JustLetMeKnow:
	.string "{COLOR}{BLUE}Just let me know when you're done and\n"
	.string "I'll pull you back up to the surface!$"
