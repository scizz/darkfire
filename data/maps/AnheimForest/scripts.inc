AnheimForest_MapScripts::
	.byte 0

AnheimForest_Sign::
	msgbox AnheimForest_Text_Sign, MSGBOX_SIGN
	end

AnheimForest_Sign_Town::
	msgbox AnheimForest_Text_Sign_Town, MSGBOX_SIGN
	end

AnheimForest_EventScript_Matthew::
	trainerbattle_single TRAINER_MATTHEW, AnheimForest_Text_MatthewIntro, AnheimForest_Text_MatthewDefeated
	msgbox AnheimForest_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_LARRY::
	trainerbattle_single TRAINER_LARRY, AnheimForest_Text_LarryIntro, AnheimForest_Text_LarryDefeated
	msgbox AnheimForest_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_ROBIN::
	trainerbattle_single TRAINER_ROBIN, AnheimForest_Text_RobinIntro, AnheimForest_Text_RobinDefeated
	msgbox AnheimForest_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_DAVIS::
	trainerbattle_single TRAINER_DAVIS, AnheimForest_Text_DavisIntro, AnheimForest_Text_DavisDefeated
	msgbox AnheimForest_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_DOUG::
	trainerbattle_single TRAINER_DOUG, AnheimForest_Text_DougIntro, AnheimForest_Text_DougDefeated
	msgbox AnheimForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_Text_Sign:
	.string "Anheim Forest\n"
	.string "Please do not litter!$"

AnheimForest_Text_Sign_Town:
	.string "{UP_ARROW} Anheim Town$"
