.set LOCALID_NURSE, 2

SunriseTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SunriseTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SUNRISE_TOWN
	end

SunriseTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SunriseTown_PokemonCenter_1F_Boy::
	msgbox SunriseTown_PokemonCenter_1F_Text_Boy, MSGBOX_NPC
	end

SunriseTown_PokemonCenter_1F_Old_Man::
	msgbox SunriseTown_PokemonCenter_1F_Text_Old_Man, MSGBOX_NPC
	end

SunriseTown_PokemonCenter_1F_Girl::
	msgbox SunriseTown_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

SunriseTown_PokemonCenter_1F_Text_Boy:
	.string "{COLOR}{BLUE}Pokémon Centers are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free!$"

SunriseTown_PokemonCenter_1F_Text_Old_Man:
	.string "That PC in the corner there is\n"
	.string "for any Pokémon Trainer to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

SunriseTown_PokemonCenter_1F_Text_Girl:
	.string "{COLOR}{RED}Recently, Pokémon have been going\n"
	.string "missing from their Trainers.\p"
	.string "Watch your back because the thieves\n"
	.string "might be coming for you, too.$"
