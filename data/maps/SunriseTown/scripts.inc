SunriseTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunriseTown_OnTransition
	.byte 0

SunriseTown_OnTransition::
	goto_if_set FLAG_SUNRISE_TOWN_TUBER_KIDS_BEFORE, SunriseTown_End
	removeobject 8
	removeobject 9
	setflag FLAG_SUNRISE_TOWN_TUBER_KIDS_AFTER
	end

SunriseTown_End::
	end

SunriseTown_Sign::
	msgbox SunriseTown_Sign_Text, MSGBOX_SIGN
	end

SunriseTown_Hotel::
	msgbox SunriseTown_Hotel_Text, MSGBOX_SIGN
	end

SunriseTown_Little_Boy_Before::
	lock
	faceplayer
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_1, SunriseTown_Little_Boy_Before_Main
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_2, SunriseTown_Little_Boy_Before_Main
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_3, SunriseTown_Little_Boy_Before_Main
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_4, SunriseTown_Little_Boy_Before_Main
	msgbox SunriseTown_Little_Boy_Beach_Clear, MSGBOX_NPC
	applymovement 7, Common_Movement_FaceLeft
	applymovement 6, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement 6, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox SunriseTown_Little_Boy_Play, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 7, RunRight8
	applymovement 6, RunRight8
	waitmovement 0
	removeobject 6
	removeobject 7
	setflag FLAG_SUNRISE_TOWN_TUBER_KIDS_BEFORE
	clearflag FLAG_SUNRISE_TOWN_TUBER_KIDS_AFTER
	showobjectat 8, MAP_SUNRISE_TOWN
	showobjectat 9, MAP_SUNRISE_TOWN
	release
	end

SunriseTown_Little_Girl_Before::
	lock
	faceplayer
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_1, SunriseTown_Little_Girl_Before_Main
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_2, SunriseTown_Little_Girl_Before_Main
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_3, SunriseTown_Little_Girl_Before_Main
	goto_if_unset FLAG_SUNRISE_TOWN_KRABBY_4, SunriseTown_Little_Girl_Before_Main
	msgbox SunriseTown_Little_Girl_Beach_Clear, MSGBOX_NPC
	applymovement 6, Common_Movement_FaceRight
	applymovement 7, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement 7, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox SunriseTown_Little_Girl_Play, MSGBOX_NPC
	getplayerxy VAR_0x8000 VAR_0x8001
	compare VAR_0x8000 39
	call_if_eq SunriseTown_Player_Block
	applymovement 7, RunRight9
	applymovement 6, RunRight9
	waitmovement 0
	removeobject 6
	removeobject 7
	setflag FLAG_SUNRISE_TOWN_TUBER_KIDS_BEFORE
	clearflag FLAG_SUNRISE_TOWN_TUBER_KIDS_AFTER
	showobjectat 8, MAP_SUNRISE_TOWN
	showobjectat 9, MAP_SUNRISE_TOWN
	release
	end

SunriseTown_Little_Boy_After::
	msgbox SunriseTown_Little_Boy_After_Text, MSGBOX_NPC
	end

SunriseTown_Little_Girl_After::
	lock
	faceplayer
	goto_if_set FLAG_SUNRISE_TOWN_TUBER_PEARL, SunriseTown_Little_Girl_Given
	msgbox SunriseTown_Little_Girl_After_Text, MSGBOX_NPC
	giveitem ITEM_PEARL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_SUNRISE_TOWN_TUBER_PEARL
	goto SunriseTown_Little_Girl_Given

SunriseTown_Little_Girl_Given::
	msgbox SunriseTown_Little_Girl_Given_Text, MSGBOX_DEFAULT
	release
	end

SunriseTown_Player_Block::
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMove
	waitmovement 0
	return

SunriseTown_Little_Boy_Before_Main::
	msgbox SunriseTown_Little_Boy_Text, MSGBOX_NPC
	end

SunriseTown_Little_Girl_Before_Main::
	msgbox SunriseTown_Little_Girl_Text, MSGBOX_NPC
	end

SunriseTown_Boy::
	msgbox SunriseTown_Fifteen, MSGBOX_NPC
	end

SunriseTown_Girl::
	msgbox SunriseTown_Girl_Text, MSGBOX_NPC
	end

SunriseTown_Old_Man::
	msgbox SunriseTown_Old_Man_Text, MSGBOX_NPC
	end

SunriseTown_Fat_Guy::
	lock
	goto_if_set FLAG_SUNRISE_TOWN_HOTEL_COOK, SunriseTown_Cook_Talked_To
	msgbox SunriseTown_Fat_Guy_Snore, MSGBOX_NPC
	delay 30
	msgbox SunriseTown_Fat_Guy_Sleeping, MSGBOX_NPC
	release
	end

SunriseTown_Cook_Talked_To::
	msgbox SunriseTown_Fat_Guy_Awaken, MSGBOX_NPC
	applymovement 4, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement 4, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 4, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox SunriseTown_Fat_Guy_Run_Away, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, StepAside
	applymovement 4, RunAway
	waitmovement 0
	removeobject 4
	setflag FLAG_SUNRISE_TOWN_FAT_GUY
	release
	end

SunriseTown_Sign_Text:
	.string "Welcome to Sunrise Town!\n"
	.string "The Town of Illumination!$"

SunriseTown_Hotel_Text:
	.string "Welcome to Oritania Hotel.\n"
	.string "Enjoy your stay!$"

SunriseTown_Little_Girl_Text:
	.string "{COLOR}{RED}My brother is angry because of the wild\n"
	.string "Krabby that invaded the beach.\p"
	.string "We should've been playing, but now we\n"
	.string "can't…$"

SunriseTown_Little_Girl_Beach_Clear:
	.string "{COLOR}{RED}What? You got rid of all the Krabby?\n"
	.string "Oh my goodness! Thank you so much!$"

SunriseTown_Little_Girl_Play:
	.string "{COLOR}{RED}Come on, little brother!\n"
	.string "We can finally play on the beach!$"

SunriseTown_Little_Girl_After_Text:
	.string "{COLOR}{RED}Hey, it's you!\n"
	.string "Thanks for getting rid of the Krabby!\p"
	.string "Listen, I found this on the beach…\n"
	.string "You can have it since you helped us!$"

SunriseTown_Little_Girl_Given_Text:
	.string "{COLOR}{RED}I hope the Krabby don't ever return!$"

SunriseTown_Little_Boy_Text:
	.string "{COLOR}{BLUE}No fair! The adults won't let us play\n"
	.string "because of the wild Krabby…\p"
	.string "If I had a Pokémon, I'd go deal with\n"
	.string "the Krabby myself!$"

SunriseTown_Little_Boy_Beach_Clear:
	.string "{COLOR}{BLUE}What's that? The beach is now clear?\n"
	.string "Wow, th-that's great! Thank you!$"

SunriseTown_Little_Boy_Play:
	.string "{COLOR}{BLUE}Come on, sis!\n"
	.string "Let's go and play!$"

SunriseTown_Little_Boy_After_Text:
	.string "{COLOR}{BLUE}Hey, it's my friend!\n"
	.string "Thanks for getting rid of the Krabby!$"

SunriseTown_Fifteen:
	.string "{COLOR}{BLUE}I've been living in this town for 15\n"
	.string "years now…\p"
	.string "I still don't understand why they built\n"
	.string "the Pokémon Center over on the beach!$"

SunriseTown_Girl_Text:
	.string "{COLOR}{RED}Did you hear about the Krabby\n"
	.string "infestation on the beach? It's scary!\p"
	.string "They're currently looking for people to\n"
	.string "solve the problem…\p"
	.string "I'm so glad I never go down there!$"

SunriseTown_Old_Man_Text:
	.string "There is no end to education.\p"
	.string "It is not that you read a book, pass an\n"
	.string "examination, and finish with education.\p"
	.string "The whole of life, from the moment\n"
	.string "you are born to the moment you die,\l"
	.string "is a process of learning.$"

SunriseTown_Fat_Guy_Snore:
	.string "{COLOR}{BLUE}Zzz… Hrf…\n"
	.string "Zzzz…$"

SunriseTown_Fat_Guy_Sleeping:
	.string "He looks to be deeply asleep and won't\n"
	.string "budge an inch…$"

SunriseTown_Fat_Guy_Awaken:
	.string "{COLOR}{BLUE}…\n"
	.string "Zzz…\p"
	.string "…\n"
	.string "…\p"
	.string "Huh?$"

SunriseTown_Fat_Guy_Run_Away:
	.string "{COLOR}{BLUE}What's that?\n"
	.string "The food at the hotel is ready?!\p"
	.string "Hold on - I'm coming!$"

RunRight8:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

RunRight9:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PlayerMove:
	walk_up
	face_right
	step_end

StepAside:
	walk_fast_left
	face_right
	step_end

RunAway:
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
