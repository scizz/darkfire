UnionCity_House1_2F_MapScripts::
	.byte 0

UnionCity_House1_2F_NestBall::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_UNION_CITY_HOUSE_1_2F_NEST_BALL, UnionCity_House1_2F_NestBall_Given
	msgbox UnionCity_House1_2F_Text_ThisBallIsUgly, MSGBOX_AUTOCLOSE
	giveitem ITEM_NEST_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_UNION_CITY_HOUSE_1_2F_NEST_BALL
	goto UnionCity_House1_1F_OldLadyGiven
	end

UnionCity_House1_2F_NestBall_Given::
	msgbox UnionCity_House1_2F_Text_MyGrandpaSaysThereAre27, MSGBOX_AUTOCLOSE
	release
	end

UnionCity_House1_2F_OldMan::
	msgbox UnionCity_House1_2F_Text_EachPokeBallHas, MSGBOX_NPC
	end

UnionCity_House1_2F_Text_ThisBallIsUgly:
	.string "{COLOR}{RED}This ball is ugly…\n"
	.string "You can have it.$"

UnionCity_House1_2F_Text_MyGrandpaSaysThereAre27:
	.string "{COLOR}{RED}My grandpa says there are 27 different\n"
	.string "types of Poké Balls.\p"
	.string "They each have their own unique design\n"
	.string "and strength.\p"
	.string "I would collect them all, but I'd\n"
	.string "rather collect Pokémon plushies.$"

UnionCity_House1_2F_Text_EachPokeBallHas:
	.string "Each Poké Ball has unique strengths.\p"
	.string "Standard Poké Ball for regular use,\n"
	.string "Great Ball for tougher Pokémon, and\l"
	.string "Ultra Ball for the trickiest.\p"
	.string "Quick Ball works best early in battle,\n"
	.string "Dusk Ball excels in dark places, and\l"
	.string "Heavy Ball, well, for heavy Pokémon.\p"
	.string "Choose wisely based on the situation.\n"
	.string "Happy catching!$"
