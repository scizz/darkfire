.set LOCALID_NURSE, 3

GreendaleVillage_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GreendaleVillage_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

GreendaleVillage_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_GREENDALE_VILLAGE
	end

GreendaleVillage_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

GreendaleVillage_PokemonCenter_1F_Boy::
	msgbox GreendaleVillage_PokemonCenter_1F_Text_Boy, MSGBOX_NPC
	end

GreendaleVillage_PokemonCenter_1F_Woman::
	msgbox GreendaleVillage_PokemonCenter_1F_Text_Woman, MSGBOX_NPC
	end

GreendaleVillage_PokemonCenter_1F_Text_Boy:
	.string "{COLOR}{BLUE}Even if a Pokémon faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from an HM.$"

GreendaleVillage_PokemonCenter_1F_Text_Woman:
	.string "{COLOR}{RED}In the city, we work until quitting\n"
	.string "time.\p"
	.string "On the farm, we work until the job is\n"
	.string "finished.$"
