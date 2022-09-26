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
	@goto UnionCity_SUBO_Event_Main
	setvar VAR_TEMP_0, 1
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
