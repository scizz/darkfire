.set LOCALID_BLACKBELT, 1
.set LOCALID_RANGER, 2
.set LOCALID_PSYCHIC, 3
.set LOCALID_ACE_TRAINER, 4
.set LOCALID_GENTLEMAN, 5
.set LOCALID_SAILOR, 6

NorthstarArena_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NorthstarArena_OnWarp
	.byte 0

NorthstarArena_OnWarp:
	map_script_2 VAR_STORYLINE_STATE, 1, NorthstarArena_InitRoomObjects
	.2byte 0

NorthstarArena_InitRoomObjects::
	showfollower
	setobjectxyperm OBJ_EVENT_ID_FOLLOWER, 7, 5
	end
