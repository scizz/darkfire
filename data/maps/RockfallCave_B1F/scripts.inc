RockfallCave_B1F_MapScripts::
	.byte 0

RockfallCave_B1F_Ranger::
	msgbox RockfallCave_B1F_Text_Ranger, MSGBOX_NPC
	end

RockfallCave_B1F_Larvitar::
	lockall
	playmoncry SPECIES_LARVITAR, 0
	msgbox RockfallCave_B1F_Text_Larvitar, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_LARVITAR, 15, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_LARVITAR, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject 5
	setflag FLAG_HIDE_ROCKFALL_CAVE_B1F_LARVITAR
	@setvar VAR_RANGER_EVENT_LARVITAR, 2
	fadescreen 0
	releaseall
	end

RockfallCave_B1F_Text_Ranger:
	.string "{COLOR}{BLUE}Larvitar! Up ahead!\n"
	.string "Go and deal with it, Trainer!$"

RockfallCave_B1F_Text_Larvitar:
	.string "Larvitar: Graar!$"

