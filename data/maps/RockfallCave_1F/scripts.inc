RockfallCave_1F_MapScripts::
	.byte 0

RockfallCave_1F_Maniac::
	msgbox RockfallCave_1F_Text_Maniac, MSGBOX_NPC
	end

RockfallCave_1F_Lass::
	msgbox RockfallCave_1F_Text_Lass, MSGBOX_NPC
	end

RockfallCave_1F_Blackbelt::
	msgbox RockfallCave_1F_Text_Blackbelt, MSGBOX_NPC
	end

RockfallCave_1F_EventScript_Dave::
	trainerbattle_single TRAINER_DAVE, RockfallCave_1F_Text_DaveIntro, RockfallCave_1F_Text_DaveDefeated
	msgbox RockfallCave_1F_Text_DavePostBattle, MSGBOX_AUTOCLOSE
	end

RockfallCave_1F_Text_Maniac:
	.string "I'm in here trying to find some rare\n"
	.string "Pokémon, but I'm having no luck…$"

RockfallCave_1F_Text_Lass:
	.string "{COLOR}{RED}That guy over there calls himself a\n"
	.string "Black Belt, but he looks like a wimp!$"

RockfallCave_1F_Text_Blackbelt:
	.string "Gah…\p"
	.string "I had to come inside this cave to get\n"
	.string "away from the flowers outside…\p"
	.string "I am allergic to pollen so every time\n"
	.string "flowers are nearby, I…\p"
	.string "I…\p"
	.string "ACHOOOO!!\p"
	.string "…\p"
	.string "Sniff.\p"
	.string "Guh…$"
