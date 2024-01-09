.set LOCALID_PIDGEY, 5
.set LOCALID_TYLER, 6

Route1_MapScripts::
	.byte 0

Route1_Storyline_State9::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 22
	goto_if_eq Route1_Tyler_Left
	compare VAR_TEMP_0, 23
	goto_if_eq Route1_Tyler_Middle
	goto Route1_Tyler_Right
	end

Route1_Tyler_Left::
	applymovement LOCALID_TYLER WLD4
	waitmovement 0
	call Route1_TylerIntro
	applymovement LOCALID_TYLER, WU2R3U3R3U2R6
	applymovement OBJ_EVENT_ID_PLAYER, WU3R3U3R3U2R5
	applymovement OBJ_EVENT_ID_FOLLOWER, WU4R3U3R3U2R4
	waitmovement 0
	goto Route1_TylerGrass
	end

Route1_Tyler_Middle::
	applymovement LOCALID_TYLER WD4
	waitmovement 0
	call Route1_TylerIntro
	applymovement LOCALID_TYLER, WU2R2U2R3U3R6
	applymovement OBJ_EVENT_ID_PLAYER, WU3R2U2R3U3R5
	applymovement OBJ_EVENT_ID_FOLLOWER, WU4R2U2R3U3R4
	waitmovement 0
	goto Route1_TylerGrass
	end

Route1_Tyler_Right::
	applymovement LOCALID_TYLER WRD4
	waitmovement 0
	call Route1_TylerIntro
	applymovement LOCALID_TYLER, WU2R2U3R2U2R6
	applymovement OBJ_EVENT_ID_PLAYER, WU3R2U3R2U2R5
	applymovement OBJ_EVENT_ID_FOLLOWER, WU4R2U3R2U2R4
	waitmovement 0
	goto Route1_TylerGrass
	end

Route1_TylerIntro::
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox Route1_Text_HeyPlayer, MSGBOX_DEFAULT
	closemessage
	hideface 1
	playbgm MUS_FOLLOW_ME, TRUE
	return

Route1_TylerGrass::
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox Route1_Text_ListenCarefully, MSGBOX_DEFAULT
	hideface 1
	release
	end

Route1_WestExitPrevention::
	lock
	applymovement LOCALID_TYLER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_SURPRISED, 1, 1
	msgbox Route1_Text_ComeBack, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkRight
	waitmovement 0
	release
	end

Route1_PidgeyIntro::
	setobjectmovementtype LOCALID_PIDGEY, MOVEMENT_TYPE_NONE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	playse SE_PIN
	waitse
	playmoncry SPECIES_PIDGEY, 0
	speakername Speaker_Text_Pidgey
	msgbox Route1_PidgeyIntro_Pidgey, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	applymovement LOCALID_TYLER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 35
	goto_if_eq Route1_PidgeyIntro_Left
	compare VAR_TEMP_0, 36
	goto_if_eq Route1_PidgeyIntro_LeftMiddle
	compare VAR_TEMP_0, 37
	goto_if_eq Route1_PidgeyIntro_Left
	goto Route1_PidgeyIntro_Right
	end

Route1_PidgeyIntro_Left::
	applymovement LOCALID_TYLER, WFR2U4
	waitmovement 0
	goto Route1_PidgeyMain
	end

Route1_PidgeyIntro_LeftMiddle::
	applymovement LOCALID_TYLER, WFRU4
	waitmovement 0
	goto Route1_PidgeyMain
	end

Route1_PidgeyIntro_Right::
	applymovement LOCALID_TYLER, WFR3U4
	waitmovement 0
	goto Route1_PidgeyMain
	end

Route1_PidgeyMain::
	delay 30
	applymovement LOCALID_TYLER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	delay 10
	applymovement LOCALID_TYLER, Common_Movement_FacePlayer
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_SURPRISED, 1, 1
	msgbox Route1_PidgeyMain_ItsAPidgey, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement LOCALID_TYLER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_PIDGEY, Levitate
	waitmovement 0
	delay 30
	applymovement LOCALID_PIDGEY, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	speakername Speaker_Text_Pidgey
	msgbox Route1_PidgeyIntro_Pidgey, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PIDGEY, FlyUp
	playse SE_PIN
	waitse
	waitmovement 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 35
	goto_if_eq Route1_PidgeyFly_Left
	compare VAR_TEMP_0, 36
	goto_if_eq Route1_PidgeyFly_LeftMiddle
	compare VAR_TEMP_0, 37
	goto_if_eq Route1_PidgeyFly_RightMiddle
	goto Route1_PidgeyFly_Right
	end

Route1_PidgeyFly_Left::
	applymovement LOCALID_PIDGEY, WRD2
	waitmovement 0
	goto Route1_PidgeyBattle
	end

Route1_PidgeyFly_LeftMiddle::
	applymovement LOCALID_PIDGEY, WR2D2
	waitmovement 0
	goto Route1_PidgeyBattle
	end

Route1_PidgeyFly_RightMiddle::
	applymovement LOCALID_PIDGEY, WR3D2
	waitmovement 0
	goto Route1_PidgeyBattle
	end

Route1_PidgeyFly_Right::
	applymovement LOCALID_PIDGEY, WR4D2
	waitmovement 0
	goto Route1_PidgeyBattle
	end

Route1_PidgeyBattle::
	applymovement LOCALID_PIDGEY, FlyDown
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	applymovement 3, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_FacePlayer
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_SHOCKED, 1, 1
	msgbox Route1_PidgeyBattle_PlayerLookOut, MSGBOX_DEFAULT
	hideface 1
	setwildbattle SPECIES_PIDGEY, 4, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_PIDGEY, 1
	waitmoncry
	delay 10
	fadescreen 1
	delay 60
	removeobject LOCALID_PIDGEY
	setflag FLAG_HIDE_ROUTE_1_PIDGEY
	fadescreen 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 35
	goto_if_eq Route1_PidgeyPlayer_Left
	goto Route1_PidgeyPlayer_Other
	end

Route1_PidgeyPlayer_Left::
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto Route1_PidgeyFinal
	end

Route1_PidgeyPlayer_Other::
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto Route1_PidgeyFinal
	end

Route1_PidgeyFinal::
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox Route1_PidgeyFinal_WayToGo, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_TYLER, WU6
	waitmovement 0
	removeobject LOCALID_TYLER
	setflag FLAG_HIDE_ROUTE_1_TYLER
	setvar VAR_STORYLINE_STATE, 10
	setvar VAR_TEMP_3, 1
	end

Route1_Tyler::
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox Route1_Text_Tyler, MSGBOX_DEFAULT
	hideface 1
	end

Route1_Jump_Event::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_1_POND_JUMP, Route1_Jump_Event_Complete
	msgbox Route1_Jump_Text, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement 2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route1_Jump_Text_2, MSGBOX_NPC
	applymovement 2, WalkRightFaceDown
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox Route1_Jump_Text_3, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement 2, JumpDown
	playse SE_LEDGE
	waitse
	waitmovement 0
	delay 30
	applymovement 2, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	applymovement 2, JumpUpWalkLeft
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox Route1_Jump_Text_4, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, StepLeftFaceRight
	applymovement OBJ_EVENT_ID_FOLLOWER, StepLeftFaceRight
	applymovement 2, StepLeftUpFaceDown
	waitmovement 0
	setflag FLAG_ROUTE_1_POND_JUMP
	release
	end

Route1_Jump_Event_Complete::
	msgbox Route1_Jump_Text_5, MSGBOX_NPC
	end

Route1_Old_Man::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_3, 1, Route1_Old_Man_Pidgey
	msgbox Route1_Old_Man_Text, MSGBOX_DEFAULT
	release
	end

Route1_Old_Man_Pidgey::
	msgbox Route1_Old_Man_Text_Pidgey, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	release
	end

Route1_Boy::
	msgbox Route1_Boy_Text, MSGBOX_NPC
	end

Route1_Location_Sign::
	msgbox Route1_Location_Sign_Text, MSGBOX_SIGN
	end

WLD4:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WD4:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WRD4:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WU2R3U3R3U2R6:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WU3R3U3R3U2R5:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WU4R3U3R3U2R4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WU2R2U2R3U3R6:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WU3R2U2R3U3R5:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WU4R2U2R3U3R4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WU2R2U3R2U2R6:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
WU3R2U3R2U2R5:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WU4R2U3R2U2R4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WFRU4:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WFR2U4:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WFR3U4:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Levitate:
	levitate
	step_end

WRD2:
	walk_right
	walk_down
	walk_down
	step_end

WR2D2:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

WR3D2:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

WR4D2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

FlyUp:
	stop_levitate
	fly_up
	step_end

FlyDown:
	fly_down
	step_end

Route1_Text_HeyPlayer:
	.string "{COLOR}{BLUE}Hey, {PLAYER}!\p"
	.string "I decided to bring my Pokémon here\n"
	.string "after our battle at my house.\p"
	.string "You can toughen up your Pokémon in\n"
	.string "areas with a lot of grass.\p"
	.string "Here, I'll show you a cool area…\n"
	.string "Follow me!$"

Route1_Text_ListenCarefully:
	.string "{COLOR}{BLUE}OK, {PLAYER}…\n"
	.string "I need you to listen carefully…\p"
	.string "Wild Pokémon jump out in grassy areas\n"
	.string "like these, and you should be prepared.\l"
	.string "Some Pokémon can be really strong!\p"
	.string "Let's train our Pokémon and see what we\n"
	.string "can find around here!$"

Route1_Text_ComeBack:
	.string "{COLOR}{BLUE}{PLAYER}! Come back!\n"
	.string "Don't leave me!$"

Route1_Text_Tyler:	
	.string "{COLOR}{BLUE}Let's train our Pokémon together,\n"
	.string "{PLAYER}!$"

Speaker_Text_Pidgey:
	.string "Pidgey$"

Route1_PidgeyIntro_Pidgey:
	.string "Pidgey: Gaaarr!$"

Route1_PidgeyIntro_Text_PlayerFoundSomething:
	.string "{COLOR}{BLUE}What's that, {PLAYER}?\n"
	.string "Have you found something?$"

Route1_PidgeyMain_ItsAPidgey:
	.string "{COLOR}{BLUE}Woah, it looks like a Pidgey!\p"
	.string "Be careful, {PLAYER}.\p"
	.string "Pidgeys can strike ferociously if they\n"
	.string "feel threatened or alarmed!$"

Route1_PidgeyBattle_PlayerLookOut:
	.string "{COLOR}{BLUE}{PLAYER}!\n"
	.string "Look out!$"

Route1_PidgeyFinal_WayToGo:
	.string "{COLOR}{BLUE}Good job, {PLAYER}!\n"
	.string "You handled that Pidgey really well!\p"
	.string "I was a little worried it was going to\n"
	.string "whip up a Sand Attack!\p"
	.string "…\p"
	.string "Anyway, with that Pidgey dealt with,\n"
	.string "I'm going to explore the town ahead.\p"
	.string "There's a really nice hotel there and I\n"
	.string "want to show people my new Pokémon.\p"
	.string "Oh…\n"
	.string "Also a quick heads up.\p"
	.string "I've heard they're having some issues\n"
	.string "with Krabby on the beach…\l"
	.string "So I definitely won't be going there!\p"
	.string "See ya!$"

Route1_Jump_Text:
	.string "{COLOR}{BLUE}Hey!\n"
	.string "A new Trainer!\p"
	.string "Listen…\p"
	.string "Do you see how close the pond banks are\n"
	.string "to each other right here?$"

Route1_Jump_Text_2:
	.string "{COLOR}{BLUE}…\n"
	.string "I'm gonna try and jump it!\p"
	.string "Haha!\n"
	.string "Watch and learn!$"

Route1_Jump_Text_3:
	.string "{COLOR}{BLUE}Okay!\n"
	.string "Here goes nothing!$"

Route1_Jump_Text_4:
	.string "{COLOR}{BLUE}Haha! Did you see that?!\n"
	.string "That was too easy!\p"
	.string "Now your turn!$"

Route1_Jump_Text_5:
	.string "{COLOR}{BLUE}You can jump over small gaps like this\n"
	.string "anywhere in the Tenjo region.\p"
	.string "Be sure to keep a look out for them.\n"
	.string "Who knows what secrets you'll find!$"

Route1_Old_Man_Text:
	.string "Lots of beginners go through this\n"
	.string "route, and I get to see them all.\p"
	.string "They remind me of when I was a wee\n"
	.string "lad, starting out my journey…\p"
	.string "Great things await ahead!$"

Route1_Old_Man_Text_Pidgey:
	.string "Incredible! Just incredible!\n"
	.string "You handled that Pidgey exceptionally!\p"
	.string "You are a real Trainer to watch!\n"
	.string "Bravo!$"

Route1_Boy_Text:
	.string "{COLOR}{BLUE}I managed to get this far without a\n"
	.string "Pokémon, but now I'm afraid to go on!$"

Route1_Location_Sign_Text:
	.string "Route 1\n"
	.string "The Route of New Beginnings!$"

JumpDown:
	jump_2_down
	step_end

JumpUpWalkLeft:
	jump_2_up
	walk_left
	step_end

WalkRightFaceDown:
	walk_right
	face_down
	step_end

StepLeftFaceRight:
	walk_left
	face_right
	step_end

StepLeftUpFaceDown:
	walk_left
	walk_up
	face_down
	step_end
