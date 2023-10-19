.set LOCALID_NURSE, 3

AnheimTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AnheimTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

AnheimTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_ANHEIM_TOWN
	end

AnheimTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

AnheimTown_PokemonCenter_1F_Gentleman::
	msgbox AnheimTown_PokemonCenter_1F_Text_Gentleman, MSGBOX_NPC
	end

AnheimTown_PokemonCenter_1F_Text_Gentleman:
	.string "Peace is a daily, a weekly, a monthly\n"
	.string "process.\p"
	.string "Gradually changing opinions, slowly\n"
	.string "eroding old barriers, quietly building\l"
	.string "new structures.$"
