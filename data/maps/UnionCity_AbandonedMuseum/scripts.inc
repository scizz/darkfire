.set LOCALID_SUBO_PUSH, 10
.set LOCALID_SUBO_F, 11
.set LOCALID_SUBO_L, 12
.set LOCALID_SUBO_M, 13
.set LOCALID_NERD, 14
.set LOCALID_PRESIDENT, 15
.set LOCALID_RATTATA, 16
.set LOCALID_POKE_BALL, 17

UnionCity_AbandonedMuseum_MapScripts::
	.byte 0

UnionCity_SUBO_Event::
	lock
	removeobject LOCALID_POKE_BALL
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 33
	goto_if_eq UnionCity_SUBO_Event_Left
	goto UnionCity_SUBO_Event_Right
	end

UnionCity_SUBO_Event_Left::
	applymovement LOCALID_NERD, WFU5
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_GetOut, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, WFRFL
	applymovement OBJ_EVENT_ID_FOLLOWER, WFRFFL
	waitmovement 0
	goto UnionCity_SUBO_QuestionMark
	end

UnionCity_SUBO_Event_Right::
	applymovement LOCALID_NERD, WFU6
	waitmovement 0
	applymovement LOCALID_NERD, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_GetOut, MSGBOX_AUTOCLOSE
	goto UnionCity_SUBO_QuestionMark
	end

UnionCity_SUBO_QuestionMark::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	applymovement LOCALID_NERD, WFU4L7
	waitse
	waitmovement 0
	goto UnionCity_SUBO_Event_Push
	end

UnionCity_SUBO_Event_Push::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, WLD
	waitmovement 0
	applymovement LOCALID_SUBO_PUSH, WFD3R3D2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PushBack
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, FFRX
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, WFRFU
	waitmovement 0
	applymovement LOCALID_SUBO_PUSH, Common_Movement_FaceDown
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_WellWellWell, MSGBOX_AUTOCLOSE
	goto UnionCity_SUBO_Event_Main
	end

UnionCity_SUBO_Event_Main::
	applymovement OBJ_EVENT_ID_PLAYER, WDLD
	applymovement OBJ_EVENT_ID_FOLLOWER, WDDLFFD
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WD3
	waitmovement 0
	special RemoveCameraObject
	delay 30
	applymovement LOCALID_SUBO_L, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_RattataUseTackle, MSGBOX_AUTOCLOSE
	delay 10
	playmoncry SPECIES_RATTATA, 0
	msgbox UnionCity_AbandonedMuseum_Text_Grrat, MSGBOX_AUTOCLOSE
	waitmoncry
	applymovement LOCALID_RATTATA, JumpRightLeft
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_Waahhh, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_IllTellYouWhat, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_IReallyCant, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_TchRattata, MSGBOX_AUTOCLOSE
	delay 10
	playmoncry SPECIES_RATTATA, 0
	msgbox UnionCity_AbandonedMuseum_Text_Grratata, MSGBOX_AUTOCLOSE
	waitmoncry
	applymovement LOCALID_RATTATA, JumpRightLeft
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_WaahhhOkay, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_ThereWasntSoHard, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	delay 10
	playse SE_PIN
	waitse
	delay 10
	removeobject LOCALID_RATTATA
	clearflag FLAG_HIDE_ABANDONED_MUSEUM_POKE_BALL
	addobject LOCALID_POKE_BALL
	applymovement LOCALID_POKE_BALL, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_POKE_BALL, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_POKE_BALL, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	playse SE_PIN
	removeobject LOCALID_POKE_BALL
	waitse
	waitmovement 0
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_SpitItOut
	delay 30
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_UhHmh, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_HmmNorthOfAnheim, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_FaceUp
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_OhItSeemsWeHave, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SUBO_F, Common_Movement_FaceUp
	applymovement LOCALID_PRESIDENT, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_SUBO_M, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_PlayerRight, MSGBOX_AUTOCLOSE
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_HehDontFeelAlarmed
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU3
	applymovement LOCALID_SUBO_L, WU3
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	playbgm MUS_SUBO_THEME, TRUE
	msgbox UnionCity_AbandonedMuseum_Text_InFactIveBeenWatching, MSGBOX_AUTOCLOSE
	delay 10
	msgbox UnionCity_AbandonedMuseum_Text_DotDotDot, MSGBOX_AUTOCLOSE
	delay 10
	msgbox UnionCity_AbandonedMuseum_Text_AnywayHereWeAre, MSGBOX_AUTOCLOSE
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_AndMrPresident, MSGBOX_AUTOCLOSE
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_KeepItUp, MSGBOX_AUTOCLOSE
	fadescreen 1
	removeobject LOCALID_SUBO_F
	removeobject LOCALID_SUBO_M
	removeobject LOCALID_SUBO_L
	removeobject LOCALID_SUBO_PUSH
	removeobject 9
	removeobject 18
	removeobject 8
	removeobject 7
	removeobject 6
	removeobject 5
	removeobject 4
	delay 60
	fadescreen 0
	delay 30
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement LOCALID_PRESIDENT, WU2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_WhatWasThat, MSGBOX_AUTOCLOSE
	setvar VAR_STORYLINE_STATE, 14
	warpsilent MAP_UNION_CITY_GOV_OFFICE_3F, 2, 2
	end

UnionCity_AbandonedMuseum_Old_Man::
	msgbox UnionCity_AbandonedMuseum_Text_Old_Man, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Girl::
	goto_if_set FLAG_ABANDONED_MUSEUM_COMPLETE, UnionCity_AbandonedMuseum_Girl_Complete
	msgbox UnionCity_AbandonedMuseum_Text_Girl, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Girl_Complete::
	msgbox UnionCity_AbandonedMuseum_Text_Girl_Complete, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Little_Girl::
	goto_if_set FLAG_ABANDONED_MUSEUM_COMPLETE, UnionCity_AbandonedMuseum_Little_Girl_Complete
	msgbox UnionCity_AbandonedMuseum_Text_Little_Girl, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Little_Girl_Complete::
	msgbox UnionCity_AbandonedMuseum_Text_Little_Girl_Complete, MSGBOX_NPC
	end

WFU5:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WFRFL:
	walk_fast_right
	face_left
	step_end

WFRFFL:
	walk_fast_right
	follower_face_left
	step_end

WFU6:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WFU4L7:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

WLD:
	walk_left
	walk_down
	step_end

WFD3R3D2:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	step_end

PushBack:
	jump_special_down
	step_end

FFRX:
	follower_face_right
	emote_exclamation_mark
	step_end

WFRFU:
	walk_fast_right
	follower_face_up
	step_end

WDLD:
	walk_down
	walk_left
	walk_down
	step_end

WDDLFFD:
	walk_down
	walk_down
	walk_left
	follower_face_down
	step_end

WD3:
	walk_down
	walk_down
	walk_down
	step_end

JumpRightLeft:
	jump_special_right
	lock_facing_direction
	jump_special_left
	unlock_facing_direction
	step_end

JumpInPlace:
	jump_in_place_left
	step_end

WU3:
	walk_up
	walk_up
	walk_up
	step_end

UnionCity_AbandonedMuseum_Text_Old_Man:
	.string "This museum was recently abandoned.\p"
	.string "It seems like nobody is interested in\n"
	.string "history anymore…\p"
	.string "At least the statues have not yet been\n"
	.string "destroyed so I can still examine them\l"
	.string "from time to time.$"

UnionCity_AbandonedMuseum_Text_Girl:
	.string "{COLOR}{RED}The old floor creaks and the shattered\n"
	.string "glass submits beneath my boots.\p"
	.string "There is nothing quite like the eerie\n"
	.string "feeling of an abandoned building.\p"
	.string "Not only that, but I often hear noises\n"
	.string "coming from the basement.\p"
	.string "If only I could find a way down there\n"
	.string "so I could investigate…$"

UnionCity_AbandonedMuseum_Text_Girl_Complete:
	.string "{COLOR}{RED}I heard somebody found their way down\n"
	.string "into the basement of this museum.\p"
	.string "I'm not too sure what unfolded down\n"
	.string "there, but I heard it was ugly.$"

UnionCity_AbandonedMuseum_Text_Little_Girl:
	.string "{COLOR}{RED}I don't know why my grandpa brought me\n"
	.string "to this place - it's scary!\p"
	.string "I heard strange noises coming from\n"
	.string "underground!$"

UnionCity_AbandonedMuseum_Text_Little_Girl_Complete:
	.string "{COLOR}{RED}My grandpa saw some bad guys fleeing\n"
	.string "from the city.\p"
	.string "I heard they were doing mean things in\n"
	.string "the basement of this museum!$"

UnionCity_AbandonedMuseum_Text_GetOut:
	.string "{COLOR}{BLUE}Get out! Get out!\n"
	.string "They're evil! They're monsters!$"

UnionCity_AbandonedMuseum_Text_WellWellWell:
	.string "{COLOR}{RED}Well, well, well…\n"
	.string "What do you think you're doing, punk?\p"
	.string "I think it's best for you to go and\n"
	.string "tell the boss exactly why you're here!$"

UnionCity_AbandonedMuseum_Text_RattataUseTackle:
	.string "{COLOR}{BLUE}Rattata!\n"
	.string "Use Tackle, now!$"

UnionCity_AbandonedMuseum_Text_Grrat:
	.string "{COLOR}{RED}Rattata: Grrat!$"

UnionCity_AbandonedMuseum_Text_Waahhh:
	.string "President: Waahhh!\n"
	.string "Please, make it stop!$"

UnionCity_AbandonedMuseum_Text_IllTellYouWhat:
	.string "{COLOR}{BLUE}I'll tell you what, Mr. President…\p"
	.string "I'll make it stop when you give us\n"
	.string "your classified research notes!$"

UnionCity_AbandonedMuseum_Text_IReallyCant:
	.string "President: I-I can't!\n"
	.string "I really can't!\p"
	.string "If these notes get into the wrong\n"
	.string "hands, Pokémon could enslave us all!$"

UnionCity_AbandonedMuseum_Text_TchRattata:
	.string "{COLOR}{BLUE}Tch…\n"
	.string "Rattata, use Super Fang!$"

UnionCity_AbandonedMuseum_Text_Grratata:
	.string "{COLOR}{RED}Rattata: Grratata!!$"

UnionCity_AbandonedMuseum_Text_WaahhhOkay:
	.string "President: WAAHHH!\n"
	.string "Okay! Okay! Just make it stop!$"

UnionCity_AbandonedMuseum_Text_ThereWasntSoHard:
	.string "{COLOR}{BLUE}There… Wasn't so hard now, was it?\n"
	.string "Rattata! Return!$"

UnionCity_AbandonedMuseum_Text_SpitItOut:
	.string "{COLOR}{BLUE}Spit it out, idiot!$"

UnionCity_AbandonedMuseum_Text_UhHmh:
	.string "President: …\n"
	.string "Uh… Hmh…\p"
	.string "There is a Government Official north\n"
	.string "of Anheim Forest.\p"
	.string "He has all the documents you are\n"
	.string "looking for…$"

UnionCity_AbandonedMuseum_Text_HmmNorthOfAnheim:
	.string "{COLOR}{BLUE}Hmm… North of Anheim Forest…\p"
	.string "In that case we will clear the bridge\n"
	.string "of Spinirak that are blocking the way.$"

UnionCity_AbandonedMuseum_Text_OhItSeemsWeHave:
	.string "{COLOR}{BLUE}Oh…\n"
	.string "It seems we have a spectator…$"

UnionCity_AbandonedMuseum_Text_PlayerRight:
	.string "{COLOR}{BLUE}{PLAYER}, right?$"

UnionCity_AbandonedMuseum_Text_HehDontFeelAlarmed:
	.string "{COLOR}{BLUE}Hah, don't feel alarmed, I have eyes\n"
	.string "in every dark corner of this region.$"

UnionCity_AbandonedMuseum_Text_InFactIveBeenWatching:
	.string "{COLOR}{BLUE}In fact, I've been watching you battle\n"
	.string "for a while, {PLAYER}.\p"
	.string "Do you really think you managed to get\n"
	.string "here without alerting any of my men?\p"
	.string "Wrong.\pI purposely told my colleague here to\n"
	.string "alert you in Anheim Forest so you\l"
	.string "could find us in here.$"

UnionCity_AbandonedMuseum_Text_DotDotDot:
	.string "{COLOR}{BLUE}…\n"
	.string "…$"

UnionCity_AbandonedMuseum_Text_AnywayHereWeAre:
	.string "{COLOR}{BLUE}Anyway, here we are.\n"
	.string "Welcome to the SUBO territory.\p"
	.string "Your battling talents are quite\n"
	.string "extraordinary, {PLAYER}.\p"
	.string "In all honesty, with those skills you\n"
	.string "could fit right in with the SUBO.\p"
	.string "What is it that you desire most?\n"
	.string "Power? Fame? Riches?\p"
	.string "I can provide all of that to you.\p"
	.string "… Oh?\n"
	.string "Who am I?\p"
	.string "The Leader.\p"
	.string "The Grand Chief of the infamous and\n"
	.string "everlasting SUBO.\p"
	.string "The SUBO part? Secret Underground\n"
	.string "Battling Organization.\l"
	.string "We're the talk of the town right now.\p"
	.string "Sounds scary?\n"
	.string "It's not supposed to.\p"
	.string "We're just a group of like-minded\n"
	.string "people whose activities do not fit\l"
	.string "into the cynical, man-made paradigm\l"
	.string "of modern morals and empathy.\p"
	.string "Why? Because morals and empathy are\n"
	.string "signs of the weak.\p"
	.string "All throughout history, the weak have\n"
	.string "always perished, and only the strong\l"
	.string "have survived.\p"
	.string "The lion eats the deer.\p"
	.string "The deer eats the bird.\p"
	.string "The bird eats the worm.\p"
	.string "Tenjo politicians like to refer to\n"
	.string "themselves as “roaring lions”,\l"
	.string "yet we devour lions.\p"
	.string "We will control the minds of the people\n"
	.string "and use them all as our tools!$"

UnionCity_AbandonedMuseum_Text_AndMrPresident:
	.string "{COLOR}{BLUE}…and Mr. President here will help us\n"
	.string "do just that.$"

UnionCity_AbandonedMuseum_Text_KeepItUp:
	.string "{COLOR}{BLUE}Keep it up, {PLAYER}.\n"
	.string "We'll be watching you.$"

UnionCity_AbandonedMuseum_Text_WhatWasThat:
	.string "President: W-what was that?\n"
	.string "Oh, no, the region is in turmoil!\p"
	.string "How will I ever show my face to the\n"
	.string "innocent people of Tenjo again?\p"
	.string "What's worse, the group are on their\n"
	.string "way to steal my classified notes!\p"
	.string "Once they get a hold of those, hell\n"
	.string "itself will manifest before our eyes!\p"
	.string "Quickly, please come with me back to\n"
	.string "my office.$"
