.set LOCALID_NURSE, 3

WaterwayCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WaterwayCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

WaterwayCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_WATERWAY_CITY
	end

WaterwayCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

WaterwayCity_PokemonCenter_1F_Psychic::
	msgbox WaterwayCity_PokemonCenter_1F_Text_Psychic, MSGBOX_NPC
	end

WaterwayCity_PokemonCenter_1F_Guitarist::
	msgbox WaterwayCity_PokemonCenter_1F_Text_Guitarist, MSGBOX_NPC
	end

WaterwayCity_PokemonCenter_1F_Text_Psychic:
	.string "{COLOR}{BLUE}You've got an interesting aura…\n"
	.string "I can sense it.\p"
	.string "Every Trainer has a different energy,\n"
	.string "but yours is particularly strong.\p"
	.string "Have you experienced something lately\n"
	.string "that's boosted your bond with Pokémon?$"

WaterwayCity_PokemonCenter_1F_Text_Guitarist:
	.string "{COLOR}{BLUE}Hey, dude!\p"
	.string "I travel from town to town, playing\n"
	.string "tunes and battling Trainers.\p"
	.string "I've been writing a new song inspired\n"
	.string "by my Jolteon's electric moves.\l"
	.string "It's got a real shock to it!$"
