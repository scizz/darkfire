Route13_MapScripts::
	.byte 0

Route13_Sign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_Guard::
	msgbox Route13_Text_Guard, MSGBOX_NPC
	end

Route13_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER, Route13_Text_SpencerIntro, Route13_Text_SpencerDefeat
	msgbox Route13_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Roland::
	trainerbattle_single TRAINER_ROLAND, Route13_Text_RolandIntro, Route13_Text_RolandDefeat
	msgbox Route13_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route13_Text_ChadIntro, Route13_Text_ChadDefeat
	msgbox Route13_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE, Route13_Text_GraceIntro, Route13_Text_GraceDefeat
	msgbox Route13_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY_1, Route13_Text_JennyIntro, Route13_Text_JennyDefeat
	msgbox Route13_Text_JennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Reli::
	trainerbattle_double TRAINER_RELI_AND_IAN, Route13_Text_ReliIntro, Route13_Text_ReliDefeat, Route13_Text_ReliNotEnoughMons
	msgbox Route13_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Ian::
	trainerbattle_double TRAINER_RELI_AND_IAN, Route13_Text_IanIntro, Route13_Text_IanDefeat, Route13_Text_IanNotEnoughMons
	msgbox Route13_Text_IanPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route13_Text_ChrisIntro, Route13_Text_ChrisDefeat
	msgbox Route13_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Daisuke::
	trainerbattle_single TRAINER_DAISUKE, Route13_Text_DaisukeIntro, Route13_Text_DaisukeDefeat
	msgbox Route13_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON, Route13_Text_CameronIntro, Route13_Text_CameronDefeat
	msgbox Route13_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Ernest::
	trainerbattle_single TRAINER_ERNEST_1, Route13_Text_ErnestIntro, Route13_Text_ErnestDefeat
	msgbox Route13_Text_ErnestPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_Sign:
	.string "Route 13\n"
	.string "Route 14 {DOWN_ARROW}$"

Route13_Text_Guard:
	.string "{COLOR}{BLUE}The environment up ahead is harsh,\n"
	.string "and it's a long way to shelter.\p"
	.string "Are you ready for it, Traveller?$"
