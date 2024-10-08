NightmareHall_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NightmareHall_OnWarp
	.byte 0

NightmareHall_OnWarp:
	map_script_2 VAR_STORYLINE_STATE, 0, NightmareHall_InitRoomObjects
	.2byte 0

NightmareHall_InitRoomObjects::
	removeobject 5
	setflag FLAG_TEMP_2
	setflag FLAG_SYS_TELESCOPE_USE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

NightmareHall_Sign::
	msgbox NightmareHall_Text_Sign, MSGBOX_SIGN
	end

NightmareHall_CutSceneTrigger::
	applymovement OBJ_EVENT_ID_PLAYER, WU2
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU2
	waitmovement 0
	applymovement 2, Common_Movement_FaceDown
	playse SE_PIN
	emote 2, 7
	waitse
	msgbox NightmareHall_Text_Hey, MSGBOX_AUTOCLOSE
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	emote 1, 7
	applymovement 7, Common_Movement_FaceDown
	playse SE_PIN
	emote 7, 7
	applymovement 3, Common_Movement_FaceDown
	playse SE_PIN
	emote 3, 7
	waitmovement 0
	delay 30
	applymovement 8, Common_Movement_WalkDown
	waitmovement 0
	msgbox NightmareHall_Text_Relax, MSGBOX_AUTOCLOSE
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, StepDownLocked
	waitmovement 0
	delay 30
	applymovement 8, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox NightmareHall_Text_Coward, MSGBOX_AUTOCLOSE
	delay 30
	applymovement 8, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	delay 10
	msgbox NightmareHall_Text_SeeThis, MSGBOX_AUTOCLOSE
	applymovement 9, Common_Movement_WalkDown
	waitmovement 0
	applymovement 9, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NightmareHall_Text_DraculOne, MSGBOX_AUTOCLOSE
	emote 8, 8
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 8, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	delay 10
	msgbox NightmareHall_Text_YesBoss, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 9, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NightmareHall_Text_Spectate, MSGBOX_AUTOCLOSE
	applymovement 8, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	delay 30
	msgbox NightmareHall_Text_YesBossTwo, MSGBOX_AUTOCLOSE
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUpSlow
	waitmovement 0
	delay 30
	applymovement 8, Common_Movement_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_FaceUp
	applymovement 1, Common_Movement_FaceUp
	applymovement 7, Common_Movement_FaceRight
	applymovement 3, Common_Movement_FaceLeft
	applymovement 10, Common_Movement_FaceDown
	applymovement 9, Common_Movement_FaceDown
	waitmovement 0
	emote 7, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 7, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NightmareHall_Text_Sandslash, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_FERALIGATR, 0
	waitmoncry
	applymovement 6, Common_Movement_WalkRightFaster
	applymovement 4, Common_Movement_WalkLeftFaster
	waitmovement 0
	playse SE_M_WATERFALL
	waitse
	emote 3, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NightmareHall_Text_Houndour, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_HOUNDOOM, 0
	waitmoncry
	delay 30
	playse SE_M_EMBER
	waitse
	applymovement 6, StepLeftLocked
	waitmovement 0
	emote 2, 7
	playse SE_PIN
	waitse
	waitmovement 0
	emote 1, 7
	playse SE_PIN
	waitse
	waitmovement 0
	playmoncry SPECIES_FERALIGATR, 1
	waitmoncry
	emote 7, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 7, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NightmareHall_Text_Sandslash_Hurt, MSGBOX_AUTOCLOSE
	delay 30
	emote 3, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NightmareHall_Text_Houndour_Final, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_HOUNDOOM, 0
	waitmoncry
	delay 30
	applymovement 4, Common_Movement_WalkLeftFaster
	waitmovement 0
	playse SE_M_EMBER
	waitse
	playmoncry SPECIES_FERALIGATR, 1
	waitmoncry
	delay 30
	playse SE_M_EMBER
	applymovement 6, Common_Movement_JumpInPlaceRight
	waitmovement 0
	setobjectnewmovementtype 6, MOVEMENT_TYPE_INVISIBLE
	waitse
	release
	emote 7, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 7, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NightmareHall_Text_Sandslash_Fainted, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NightmareHall_Text_Houndour_Return, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceSlowLeft
	playse SE_BALL_THROW
	waitse
	waitmovement 0
	clearflag FLAG_TEMP_2
	addobject 5
	setobjectxy 4, 0, 0
	hideobjectat 4, MAP_NIGHTMARE_HALL
	applymovement 5, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_2
	applymovement 5, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_3
	applymovement 5, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_4
	waitse
	delay 30
	applymovement 3, WalkLeftTwo
	waitmovement 0
	setobjectxy 5, 0, 0
	hideobjectat 5, MAP_NIGHTMARE_HALL
	playse SE_CLICK
	waitse
	applymovement 3, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	delay 10
	msgbox NightmareHall_Text_Pathetic, MSGBOX_AUTOCLOSE
	applymovement 7, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NightmareHall_Text_WhatDoWeDo, MSGBOX_AUTOCLOSE
	emote 8, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 8, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox NightmareHall_Text_YourProblem, MSGBOX_AUTOCLOSE
	emote 7, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 7, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NightmareHall_Text_YesSir, MSGBOX_AUTOCLOSE
	delay 30
	playse SE_PIN
	emote 8, 7
	waitse
	applymovement 8, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox NightmareHall_Text_SeeThisKid, MSGBOX_AUTOCLOSE
	applymovement 9, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	delay 10
	msgbox NightmareHall_Text_DraculTwo, MSGBOX_AUTOCLOSE
	emote 8, 8
	playse SE_PIN
	waitse
	applymovement 8, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NightmareHall_Text_YesBoss, MSGBOX_AUTOCLOSE
	applymovement 9, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NightmareHall_Text_SeenTooMuch, MSGBOX_AUTOCLOSE
	applymovement 8, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox NightmareHall_Text_WhatShouldWeDo, MSGBOX_AUTOCLOSE
	applymovement 9, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NightmareHall_Text_Pinsir, MSGBOX_AUTOCLOSE
	playse SE_UNLOCK
	waitse
	playse SE_UNLOCK
	waitse
	emote 1, 7
	playse SE_PIN
	waitse
	emote 2, 7
	playse SE_PIN
	waitse
	emote 8, 7
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 8, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox NightmareHall_Text_GetTheKid, MSGBOX_AUTOCLOSE
	playse SE_UNLOCK
	waitse
	playse SE_UNLOCK
	waitse
	applymovement 7, Common_Movement_FaceDown
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	applymovement 1, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceDown
	waitmovement 0
	applymovement 10, Common_Movement_FaceDown
	applymovement 9, Common_Movement_FaceDown
	waitmovement 0
	emote OBJ_EVENT_ID_PLAYER, 7
	playse SE_PIN
	waitse
	waitmovement 0
	delay 60
	fadescreen 1
	fadeoutbgm 1
	setweather WEATHER_NONE
	doweather
	playse SE_UNLOCK
	waitse
	playse SE_UNLOCK
	waitse
	speakername SpeakerName_Text_QuestionMark
	msgbox NightmareHall_Text_Player, MSGBOX_AUTOCLOSE
	delay 30
	playse SE_UNLOCK
	waitse
	playse SE_UNLOCK
	waitse
	speakername SpeakerName_Text_QuestionMark
	msgbox NightmareHall_Text_OpenDoor, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_0, 1
	fadeinbgm 9
	setflag FLAG_REMOVE_WARP_FADE
	warpsilent MAP_CHANDRA_VILLAGE_PLAYER_HOUSE_2F, 8, 6
	waitstate
	end

WR6:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FaceLeftQuestionMark:
	face_left
	step_end

StepDownLocked:
	lock_facing_direction
	walk_slow_down
	unlock_facing_direction
	step_end

StepLeftLocked:
	lock_facing_direction
	walk_slow_left
	unlock_facing_direction
	step_end

BallBounce:
	jump_in_place_up_down
	step_end

WalkLeftTwo:
	walk_left
	walk_left
	step_end

RunDownTwelve:
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	step_end

NightmareHall_Text_Sign:
	.string "…Behold the Darkspace…\p"
	.string "…The total nothingness that precedes\n"
	.string "the machinations of the Original One…\p"
	.string "…That precedes the Universe…$"

NightmareHall_Text_Hey:
	.string "{COLOR}{RED}Hey!\n"
	.string "Who's this kid?!$"

NightmareHall_Text_Relax:
	.string "{COLOR}{BLUE}Relax, grunt.\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Kid, come here.$"

NightmareHall_Text_Coward:
	.string "{COLOR}{BLUE}…\n"
	.string "Heh, heh…\p"
	.string "So not only are you meddlesome, but\n"
	.string "you're also a coward.$"

NightmareHall_Text_SeeThis:
	.string "{COLOR}{BLUE}You see these Pokémon?\n"
	.string "They're horrendously powerful.\p"
	.string "So powerful, in fact, that if you\n"
	.string "do not leave this place immediately…$"

NightmareHall_Text_DraculOne:
	.string "Lucien…$"

NightmareHall_Text_YesBoss:
	.string "{COLOR}{BLUE}Yes, boss?$"

NightmareHall_Text_Spectate:
	.string "Let the kid spectate.$"

NightmareHall_Text_YesBossTwo:
	.string "{COLOR}{BLUE}Yes, boss…$"

NightmareHall_Text_Sandslash:
	.string "{COLOR}{BLUE}Feraligatr!\n"
	.string "Use Waterfall!$"

NightmareHall_Text_Houndour:
	.string "{COLOR}{BLUE}Houndoom!\n"
	.string "Use Fire Blast!$"

NightmareHall_Text_Sandslash_Hurt:
	.string "{COLOR}{BLUE}Feraligatr!\n"
	.string "No!$"

NightmareHall_Text_Houndour_Final:
	.string "{COLOR}{BLUE}Houndoom!\n"
	.string "It's burned! Finish it!$"

NightmareHall_Text_Sandslash_Fainted:
	.string "{COLOR}{BLUE}No! My Feraligatr!\n"
	.string "How did you defeat it with fire?!\p"
	.string "You've… You've vaporized it!\n"
	.string "You… You've burned it to ashes!\l"
	.string "It won't go back in its Poké Ball!\p"
	.string "… What?\n"
	.string "You've completely destroyed it!\p"
	.string "It can't be…\n"
	.string "How can your Pokémon be this strong?\l"
	.string "My Feraligatr… It's gone…\l"
	.string "Someone… Anyone…\n"
	.string "Please help me!$"

NightmareHall_Text_Houndour_Return:
	.string "{COLOR}{BLUE}Houndoom, return.$"

NightmareHall_Text_Pathetic:
	.string "{COLOR}{BLUE}Hmph…\n"
	.string "What a pathetic Pokémon…\p"
	.string "You're weak, Trainer.\n"
	.string "Pay up.$"

NightmareHall_Text_WhatDoWeDo:
	.string "{COLOR}{BLUE}I… I can't believe it…\n"
	.string "What do we do with the ashes?$"

NightmareHall_Text_YourProblem:
	.string "{COLOR}{BLUE}It's your problem.\p"
	.string "I suggest you clean it up.\n"
	.string "What's left of it, anyway.\p"
	.string "You don't want to be the next one who\n"
	.string "gets incinerated.$"

NightmareHall_Text_YesSir:
	.string "{COLOR}{BLUE}Yes, sir…$"

NightmareHall_Text_SeeThisKid:
	.string "{COLOR}{BLUE}You see this, kid?\n"
	.string "This is real battling.\p"
	.string "Pokémon Trainers have become soft.\n"
	.string "They've become weak and spineless.\p"
	.string "Pokémon aren't friends, they're\n"
	.string "merely our tools, our slaves…\p"
	.string "My name is Lucien.\n"
	.string "You'll wish you never had met me.\p"
	.string "I'll take your Pokémon and make them\n"
	.string "fight to the death.$"

NightmareHall_Text_DraculTwo:
	.string "Lucien…$"

NightmareHall_Text_SeenTooMuch:
	.string "The kid has seen too much.$"

NightmareHall_Text_WhatShouldWeDo:
	.string "{COLOR}{BLUE}What should we do to the kid, boss?$"

NightmareHall_Text_Pinsir:
	.string "Where's my Pinsir?\n"
	.string "It just learned Guillotine…$"

NightmareHall_Text_GetTheKid:
	.string "{COLOR}{BLUE}Grunts! Get the kid!$"

NightmareHall_Text_Player:
	.string "{COLOR}{RED}… {PLAYER}?$"

NightmareHall_Text_OpenDoor:
	.string "{COLOR}{RED}{PLAYER}!\n"
	.string "Open the door, you lazy child!$"
