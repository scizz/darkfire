Route9_MapScripts::
	.byte 0

Route9_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_Sign_Dome::
	msgbox Route9_Text_Sign_Dome, MSGBOX_SIGN
	end

Route9_Old_Man::
	lockall
	faceplayer
	goto_if_set FLAG_ROUTE_9_AERIAL_ACE, Route9_Old_Man_Given
	msgbox Route9_Text_Old_Man, MSGBOX_DEFAULT
	giveitem ITEM_TM40, 1
	setflag FLAG_ROUTE_9_AERIAL_ACE
	goto Route9_Old_Man_Given

Route9_Old_Man_Given::
	msgbox Route9_Text_Old_Man_Given, MSGBOX_DEFAULT
	releaseall
	end

Route9_EventScript_Cristin::
	trainerbattle_single TRAINER_CRISTIN, Route9_Text_CristinIntro, Route9_Text_CristinDefeated
	msgbox Route9_Text_CristinPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route9_Text_CoraIntro, Route9_Text_CoraDefeated
	msgbox Route9_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route9_Text_JosephIntro, Route9_Text_JosephDefeated
	msgbox Route9_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Text_Sign:
	.string "Route 9\n"
	.string "Starter Dome, Route 10 {DOWN_ARROW}$"

Route9_Text_Sign_Dome:
	.string "Starter Dome\n"
	.string "Get your starter Pokémon here!$"

Route9_Text_Old_Man:
	.string "And there a brave Charizard stood…\p"
	.string "He looked weak after being hit with a\n"
	.string "powerful Hydro Pump attack.\p"
	.string "Suddenly, Charizard flew towards his\n"
	.string "opponent at a great speed!\p"
	.string "Yes, yes, he turned into a blur with\n"
	.string "white streaks surrounding his body!\p"
	.string "With one swift slash… One quick dash…\p"
	.string "Clash!\p"
	.string "His opponent faints!\p"
	.string "And that, my friend, is the story of\n"
	.string "Aerial Ace.\l"
	.string "Take it - I insist!$"

Route9_Text_Old_Man_Given:
	.string "TM40 contains Aerial Ace!\n"
	.string "It's a fast move that can't be evaded.$"
