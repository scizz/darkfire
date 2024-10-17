Route12_MapScripts::
	.byte 0

Route12_EventScript_Marcel:: @ACE TRAINER
	trainerbattle_single TRAINER_MARCEL, Route12_Text_MarcelIntro, Route12_Text_MarcelDefeated
	msgbox Route12_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Chip:: @ RUIN MANIAC
	trainerbattle_single TRAINER_CHIP, Route12_Text_ChipIntro, Route12_Text_ChipDefeated
	msgbox Route12_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Wendy:: @ ACE TRAINER
	trainerbattle_single TRAINER_WENDY, Route12_Text_WendyIntro, Route12_Text_WendyDefeated
	msgbox Route12_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Jessica:: @ BEAUTY
	trainerbattle_single TRAINER_JESSICA, Route12_Text_JessicaIntro, Route12_Text_JessicaDefeated
	msgbox Route12_Text_JessicaPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Cale:: @ BUG MANIAC
	trainerbattle_single TRAINER_CALE, Route12_Text_CaleIntro, Route12_Text_CaleDefeated
	msgbox Route12_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route12_Woman_2::
	msgbox Route12_Text_Woman_2, MSGBOX_NPC
	end

Route12_Fisherman::
	msgbox Route12_Text_Fisherman, MSGBOX_NPC
	end

Route12_Text_Woman_2:
	.string "{COLOR}{RED}Sometimes I come here just to listen\n"
	.string "to the sound of the waterfalls.\l"
	.string "It's soothing, don't you think?\p"
	.string "Waterway City is up ahead.\p"
	.string "It might be busy, but out here, it's\n"
	.string "like the whole world slows down.\p"
	.string "You should take a moment and relax\n"
	.string "before joining the hustle and bustle.$"

Route12_Text_Fisherman:
	.string "{COLOR}{BLUE}You see that bridge up ahead?\p"
	.string "It's a lifeline for travelers going to\n"
	.string "Waterway City.\p"
	.string "It's also the best spot to reel in\n"
	.string "some rare catches.\p"
	.string "The current's strong under there, so\n"
	.string "you never know what might bite.$"
