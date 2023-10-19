.set LOCALID_NURSE, 1

LaveriaCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LaveriaCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LaveriaCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVERIA_CITY
	end

LaveriaCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LaveriaCity_PokemonCenter_1F_Fat_Guy::
	msgbox LaveriaCity_PokemonCenter_1F_Text_Fat_Guy, MSGBOX_NPC
	end

LaveriaCity_PokemonCenter_1F_Woman::
	msgbox LaveriaCity_PokemonCenter_1F_Text_Woman, MSGBOX_NPC
	end

LaveriaCity_PokemonCenter_1F_Bug_Catcher::
	msgbox LaveriaCity_PokemonCenter_1F_Text_Bug_Catcher, MSGBOX_NPC
	end

LaveriaCity_PokemonCenter_1F_Text_Fat_Guy:
	.string "{COLOR}{BLUE}Anyone who says that money can't buy\n"
	.string "happiness has clearly never spent\l"
	.string "their money on pizza!$"

LaveriaCity_PokemonCenter_1F_Text_Woman:
	.string "{COLOR}{RED}There are many types of Pokémon.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of Pokémon,\n"
	.string "a battle could be easy or hard.$"

LaveriaCity_PokemonCenter_1F_Text_Bug_Catcher:
	.string "{COLOR}{BLUE}When my Pokémon ate an\n"
	.string "Oran Berry, it regained HP!$"
