.set LOCALID_OLD_MAN, 1

NorthstarCity_Lighthouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NorthstarCity_Lighthouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NorthstarCity_Lighthouse_OnWarp
	.byte 0

NorthstarCity_Lighthouse_OnFrame:
	map_script_2 VAR_STORYLINE_STATE, 1, NorthstarCity_Lighthouse_TelescopeAfter
	.2byte 0

NorthstarCity_Lighthouse_OnWarp:
	map_script_2 VAR_STORYLINE_STATE, 1, NorthstarCity_Lighthouse_InitRoomObjects
	.2byte 0

NorthstarCity_Lighthouse_InitRoomObjects::
	showfollower
	setobjectxy LOCALID_OLD_MAN, 36, 5
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_OLD_MAN, DIR_NORTH
	end

NorthstarCity_Lighthouse_TelescopeAfter::
	lock
	applymovement 1, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox NorthstarCity_Lighthouse_Text_TrainerAreYouOkay, MSGBOX_AUTOCLOSE
	delay 30
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox NorthstarCity_Lighthouse_Text_OhThisIs, MSGBOX_AUTOCLOSE
	setflag FLAG_NORTHSTAR_LIGHTHOUSE_COMPLETE
	setvar VAR_STORYLINE_STATE, 3
	release
	end

NorthstarCity_Lighthouse_Old_Man::
	lock
	goto_if_set FLAG_NORTHSTAR_LIGHTHOUSE_COMPLETE, NorthstarCity_Lighthouse_Old_Man_Complete
	applymovement 1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NorthstarCity_Lighthouse_Text_NotNow, MSGBOX_AUTOCLOSE
	delay 30
	faceplayer
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox NorthstarCity_Lighthouse_Text_OhATrainer, MSGBOX_AUTOCLOSE
	delay 30
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	msgbox NorthstarCity_Lighthouse_Text_IHaveTriedToTrack, MSGBOX_AUTOCLOSE
	delay 20
	faceplayer
	msgbox NorthstarCity_Lighthouse_Text_IveLeftMyGlasses, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NorthstarCity_Lighthouse_Old_Man_Yes
	goto NorthstarCity_Lighthouse_Old_Man_No
	end

NorthstarCity_Lighthouse_Old_Man_Yes::
	msgbox NorthstarCity_Lighthouse_Text_ThankYouChild, MSGBOX_AUTOCLOSE
	goto NorthstarCity_Lighthouse_Old_Man_Move
	end

NorthstarCity_Lighthouse_Old_Man_No::
	msgbox NorthstarCity_Lighthouse_Text_ItWillOnlyTakeASecond, MSGBOX_AUTOCLOSE
	goto NorthstarCity_Lighthouse_Old_Man_Move
	end

NorthstarCity_Lighthouse_Old_Man_Move::
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 3
	goto_if_eq NorthstarCity_Lighthouse_Old_Man_MovePlayerTop
	compare VAR_TEMP_0, 4
	goto_if_eq NorthstarCity_Lighthouse_Old_Man_MovePlayerMiddle
	goto NorthstarCity_Lighthouse_Old_Man_MovePlayerBottom
	end

NorthstarCity_Lighthouse_Old_Man_MovePlayerTop::
	applymovement 1, Common_Movement_WalkLeftSlow
	waitmovement 0
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkRight
	waitmovement 0 
	goto NorthstarCity_Lighthouse_Old_Man_UseTelescope
	end

NorthstarCity_Lighthouse_Old_Man_MovePlayerMiddle::
	applymovement 1, Common_Movement_WalkUpSlow
	waitmovement 0
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto NorthstarCity_Lighthouse_Old_Man_UseTelescope
	end

NorthstarCity_Lighthouse_Old_Man_MovePlayerBottom::
	applymovement 1, Common_Movement_WalkLeftSlow
	waitmovement 0
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto NorthstarCity_Lighthouse_Old_Man_UseTelescope
	end

NorthstarCity_Lighthouse_Old_Man_UseTelescope::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	special HealPlayerParty
	setfollowerwarppos DIR_NORTH
	warpsilent MAP_NORTHSTAR_CITY_TELESCOPE_SEA, 10, 6
	waitstate
	end

NorthstarCity_Lighthouse_Old_Man_Complete::
	faceplayer
	msgbox NorthstarCity_Lighthouse_Text_IWonderIfTheBoat, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Lighthouse_Text_TrainerAreYouOkay:
	.string "Trainer? Are you okay?\n"
	.string "Did you manage to track them?\p"
	.string "…\n"
	.string "…$"

NorthstarCity_Lighthouse_Text_OhThisIs:
	.string "Oh, this is just terrible news!\n"
	.string "I just can't believe it!\p"
	.string "The research notes are rumored to\n"
	.string "contain information about dark energy.\p"
	.string "These SUBO scoundrels have a thirst\n"
	.string "for power, there's no denying that.\p"
	.string "If they can harness the power of dark\n"
	.string "energy, our region will be doomed.\p"
	.string "Please, Trainer, restore peace to our\n"
	.string "city and get rid of these thugs!$"

NorthstarCity_Lighthouse_Text_NotNow:
	.string "Not now, my dear Grandson, not now…$"

NorthstarCity_Lighthouse_Text_OhATrainer:
	.string "Oh, a Trainer!\p"
	.string "Let me tell you, I am very glad you\n"
	.string "are here!\p"
	.string "Listen…\n"
	.string "I need your help.\p"
	.string "Today, one of the Government Officials\n"
	.string "was visiting the city on business.\p"
	.string "Then, out of nowhere, these rotten SUBO\n"
	.string "thugs appeared shortly thereafter.\p"
	.string "They started demanding research notes\n"
	.string "belonging to the Government Official!\p"
	.string "News quickly broke out, and a boat was\n"
	.string "quickly assigned to the Official, who\l"
	.string "hastily boarded it and set sail.\p"
	.string "Just as he departed the Northstar City\n"
	.string "docks, the SUBO hijacked another boat!\l"
	.string "They are giving chase to him now!$"

NorthstarCity_Lighthouse_Text_IHaveTriedToTrack:
	.string "I have tried to track their movements\n"
	.string "with my trusty telescope here, but…$"

NorthstarCity_Lighthouse_Text_IveLeftMyGlasses:
	.string "I've left my glasses down in the docks!\n"
	.string "I can't see a darn thing!\p"
	.string "Could you look through the telescope\n"
	.string "for me and track what's going on?$"

NorthstarCity_Lighthouse_Text_ThankYouChild:
	.string "Thank you, child!\n"
	.string "Your eyes are better than mine!$"

NorthstarCity_Lighthouse_Text_ItWillOnlyTakeASecond:
	.string "It will only take a second, child.\n"
	.string "Your eyes are better than mine!$"

NorthstarCity_Lighthouse_Text_IWonderIfTheBoat:
	.string "I wonder if the boat that the SUBO\n"
	.string "stole will ever be recovered…$"
