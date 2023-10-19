.set LOCALID_NURSE, 3

UnionCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UnionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

UnionCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_UNION_CITY
	end

UnionCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

UnionCity_PokemonCenter_1F_Old_Man::
	msgbox UnionCity_PokemonCenter_1F_Text_Old_Man, MSGBOX_NPC
	end

UnionCity_PokemonCenter_1F_Girl::
	msgbox UnionCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

UnionCity_PokemonCenter_1F_Text_Old_Man:
	.string "Union City…\nHome of the Tenjo Government…\p"
	.string "The government is so out of control.\p"
	.string "It is so bloated and infested with\n"
	.string "fraud, deceit, corruption and total\l"
	.string "abuse of power.\p"
	.string "You'll understand what I'm saying,\n"
	.string "one day…$"

UnionCity_PokemonCenter_1F_Text_Girl:
	.string "{COLOR}{RED}The man next door gave me a TM!\p"
	.string "I used it to teach my Pokémon how to\n"
	.string "bulk up their power!$"
