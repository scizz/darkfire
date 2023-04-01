.set LOCALID_BLACKBELT, 1
.set LOCALID_RANGER, 2
.set LOCALID_PSYCHIC, 3
.set LOCALID_ACE_TRAINER, 4
.set LOCALID_GENTLEMAN, 5
.set LOCALID_SAILOR, 6

NorthstarArena_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NorthstarArena_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NorthstarArena_OnWarp
	.byte 0

NorthstarArena_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 2, NorthstarArena_EventStart
	.2byte 0

NorthstarArena_OnWarp:
	map_script_2 VAR_STORYLINE_STATE, 2, NorthstarArena_InitRoomObjects
	.2byte 0

NorthstarArena_InitRoomObjects::
	applymovement OBJ_EVENT_ID_FOLLOWER, WRFFL
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	showfollower
	end

NorthstarArena_EventStart::
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_PSYCHIC, NorthstarArena_RangerBattle
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_RANGER, NorthstarArena_PsychicBattle
	end

NorthstarArena_PsychicBattle::
	msgbox NorthstarArena_Text_TheArenaHasBeenSet, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_PSYCHIC, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PSYCHIC, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_IDidntGetAllTheWay, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 3
	goto NorthstarArena_NextRound
	end

NorthstarArena_RangerBattle::
	msgbox NorthstarArena_Text_TheArenaHasBeenSet, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_RANGER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarArena_Text_SoYoureTheNewTrainer, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	delay 30
	setvar VAR_STORYLINE_STATE, 3
	goto NorthstarArena_NextRound
	end

NorthstarArena_NextRound::
	warpsilent MAP_NORTHSTAR_CITY_TOURNAMENT_4F, 10, 7
	waitstate
	end

NorthstarArena_Text_TheArenaHasBeenSet:
	.string "{COLOR}{RED}Announcer: The arena is ready!\n"
	.string "Trainers, are you?!$"

NorthstarArena_Text_SoYoureTheNewTrainer:
	.string "{COLOR}{RED}So…\pYou're the new Trainer around,\n"
	.string "aren't you?\p"
	.string "Time to find out if you can stand up\n"
	.string "to a Ranger of northern Tenjo!$"

NorthstarArena_Text_IDidntGetAllTheWay:
	.string "{COLOR}{BLUE}I didn't get all the way here by\n"
	.string "being a pushover…\l"
	.string "And this time's no different!\p"
	.string "Here I come!$"
