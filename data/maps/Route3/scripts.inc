.set LOCALID_LARVITAR, 5
.set LOCALID_SCHOOL_KID, 6

Route3_MapScripts::
	.byte 0

Route3_Sign::
	msgbox Route3_Text_Sign, MSGBOX_SIGN
	end

Route3_LeftSign::
	msgbox Route3_Text_LeftSign, MSGBOX_SIGN
	end

Route3_EventScript_MiracleSeed::
	lockall
	faceplayer
	goto_if_set FLAG_ROUTE_3_MIRACLE_SEED, Route3_MiracleSeed_Received
	msgbox Route3_Text_MiracleSeedOne, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_3_MIRACLE_SEED
	goto Route3_MiracleSeed_Received
	end

Route3_MiracleSeed_Received::
	msgbox Route3_Text_MiracleSeedTwo, MSGBOX_DEFAULT
	releaseall
	end

Route3_Guitarist::
	msgbox Route3_Text_Guitarist, MSGBOX_NPC
	end

Route3_Girl::
	msgbox Route3_Text_Girl, MSGBOX_NPC
	end

Route3_Larvitar::
	lock
	faceplayer
	speakername CommonName_Text_Larvitar
	playmoncry SPECIES_LARVITAR, 0
	msgbox Route3_Text_Larvitar, MSGBOX_AUTOCLOSE
	waitmoncry
	applymovement LOCALID_LARVITAR, Common_Movement_FaceUp
	waitmovement 0
	release
	end

Route3_Nerd::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_ROUTE_3_LARVITAR, Route3_LarvitarBattleWon
	msgbox Route3_Text_NerdBeforeBattle, MSGBOX_DEFAULT
	release
	end

Route3_LarvitarBattleWon::
	goto_if_set FLAG_ROUTE_3_LARVITAR_BATTLE_POTION_GIVEN, Route3_PotionReceived
	msgbox Route3_Text_GivePotion, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 1
	setflag FLAG_ROUTE_3_LARVITAR_BATTLE_POTION_GIVEN
	goto Route3_PotionReceived
	end

Route3_PotionReceived::
	msgbox Route3_Text_ReceivedPotion, MSGBOX_DEFAULT
	release
	end

Route3_DoubleBattle::
	lockall
	delay 10
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq VAR_RESULT, DIR_SOUTH, Route3_DoubleBattle_South
	compare VAR_RESULT, DIR_NORTH
	call_if_eq VAR_RESULT, DIR_NORTH, Route3_DoubleBattle_North
	compare VAR_RESULT, DIR_EAST
	call_if_eq VAR_RESULT, DIR_EAST, Route3_DoubleBattle_East
	goto Route3_DoubleBattle_West
	end

Route3_DoubleBattle_North::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkDown
	waitmovement 0
	goto Route3_DoubleBattle_MoveCamera
	end

Route3_DoubleBattle_South::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, WLD2RD
	waitmovement 0
	goto Route3_DoubleBattle_MoveCamera
	end

Route3_DoubleBattle_East::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, WDRD
	waitmovement 0
	goto Route3_DoubleBattle_MoveCamera
	end

Route3_DoubleBattle_West::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, WDLD
	waitmovement 0
	goto Route3_DoubleBattle_MoveCamera
	end

Route3_DoubleBattle_MoveCamera::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WD2
	waitmovement 0
	goto Route3_DoubleBattle_GetPartySize
	end

Route3_DoubleBattle_GetPartySize::
	getpartysize
	compare VAR_RESULT, 2
	goto_if_ge Route3_DoubleBattle_Start
	goto Route3_DoubleBattle_NotReady
	end

Route3_DoubleBattle_NotReady::
	applymovement LOCALID_SCHOOL_KID, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox Route3_Text_HmmNoYouAreNotYetReady, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_CAMERA, WU2
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

Route3_DoubleBattle_Start::
	applymovement LOCALID_SCHOOL_KID, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox Route3_Text_WhatsThatYouWishToBattleMe, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_ROUTE_3_GORDON, Route3Gordon_Text_Defeated
	removeobject LOCALID_LARVITAR
	setflag FLAG_HIDE_ROUTE_3_LARVITAR
	emote LOCALID_SCHOOL_KID, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_SCHOOL_KID, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox Route3_Text_HowDidYouBeatMe, MSGBOX_AUTOCLOSE
	special RemoveCameraObject
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU2
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	setvar VAR_ROUTE_3_DOUBLE_BATTLE, 1
	releaseall
	end

WDRD:
	walk_down
	walk_right
	walk_down
	step_end

WLD2RD:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

Route3_Text_Sign:
	.string "Route 3\n"
	.string "{UP_ARROW} Anheim Forest$"

Route3_Text_LeftSign:
	.string "Route 3\n"
	.string "{LEFT_ARROW} Anheim Forest$"

Route3_Text_Guitarist:
	.string "{COLOR}{BLUE}I've got one piece of advice…\p"
	.string "Don't expect the world to be fair\n"
	.string "with you because you are fair.\p"
	.string "That's like expecting a lion not to\n"
	.string "eat you because you didn't eat it.$"

Route3_Text_Girl:
	.string "{COLOR}{RED}Anheim Forest is up ahead.\n"
	.string "It's full of Bug-type Pokémon!\p"
	.string "I want to explore inside but I'm\n"
	.string "too scared of bugs! Eww!$"

Route3_Text_MiracleSeedOne:
	.string "{COLOR}{BLUE}I love watching Pokémon battles.\p"
	.string "There's so much to learn when it comes\n"
	.string "to different types and abilities.\p"
	.string "Don't believe me? Take this…$"

Route3_Text_MiracleSeedTwo:
	.string "{COLOR}{BLUE}Miracle Seed boosts Grass-type moves\n"
	.string "when held by a Pokémon.\l"
	.string "Give it a try!$"

Route3_Text_Larvitar:
	.string "Grra!$"

Route3_Text_NerdBeforeBattle:
	.string "I just got done training my Larvitar\n"
	.string "in Anheim Forest.\p"
	.string "I'm itching to battle a Trainer so I\n"
	.string "can test its new abilities!$"

Route3_Text_GivePotion:
	.string "Kudos to you, Trainer.\n"
	.string "Here you go.$"

Route3_Text_ReceivedPotion:
	.string "You're gonna need that Potion at\n"
	.string "some point… Trust me, you will!$"

Route3_Text_HmmNoYouAreNotYetReady:
	.string "Hmm…\p"
	.string "No…\n"
	.string "You are not yet ready…\p"
	.string "Come back when you have more than one\n"
	.string "Pokémon…$"

Route3_Text_WhatsThatYouWishToBattleMe:
	.string "What's that?\n"
	.string "You wish to battle me?\p"
	.string "Very well!\n"
	.string "Bring your best Pokémon!$"

Route3_Text_HowDidYouBeatMe:
	.string "How did you beat me…\p"
	.string "Fine…\n"
	.string "Come and get your reward.$"
