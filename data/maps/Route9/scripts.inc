.set LOCALID_DAZ_1, 9
.set LOCALID_GIRL, 11
.set LOCALID_LITTLE_GIRL, 7
.set LOCALID_MOTHER, 8
.set LOCALID_YOUNGSTER, 10
.set LOCALID_PROF, 6
.set LOCALID_DAZ_2, 12
.set LOCALID_SNORLAX, 13
.set LOCALID_MUDKIP, 16

Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route9_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, Route9_OnLoad
	.byte 0

Route9_OnFrame:
	map_script_2 VAR_STORYLINE_STATE, 20, Route9_DazBattle
	map_script_2 VAR_STORYLINE_STATE, 21, Route9_DazLost
	.2byte 0

Route9_OnLoad:
	call_if_set FLAG_ROUTE_9_SNORLAX, Route9_ClearPath
	end

Route9_OnTransition:
	compare VAR_STORYLINE_STATE, 20
	call_if_lt Route9_HideDaz2
	compare VAR_STORYLINE_STATE, 21
	call_if_eq Route9_HideDaz2
	end

Route9_ClearPath::
	setmetatile 34, 60, 1, 0
	setmetatile 35, 60, 1, 0
	return

Route9_HideDaz2::
	removeobject LOCALID_DAZ_2
	removeobject LOCALID_MUDKIP
	setflag FLAG_HIDE_DAZ_2_MUDKIP
	return

Route9_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_Sign_Dome::
	msgbox Route9_Text_Sign_Dome, MSGBOX_SIGN
	end

Route9_Boy::
	msgbox Route9_Text_Boy, MSGBOX_NPC
	end

Route9_Old_Man::
	lockall
	faceplayer
	goto_if_set FLAG_ROUTE_9_AERIAL_ACE, Route9_Old_Man_Given
	msgbox Route9_Text_Old_Man, MSGBOX_DEFAULT
	giveitem ITEM_TM40, 1
	setflag FLAG_ROUTE_9_AERIAL_ACE
	goto Route9_Old_Man_Given

Route9_Old_Man_Given::
	msgbox Route9_Text_Old_Man_Given, MSGBOX_DEFAULT
	releaseall
	end

Route9_EventScript_Cristin::
	trainerbattle_single TRAINER_CRISTIN, Route9_Text_CristinIntro, Route9_Text_CristinDefeated
	msgbox Route9_Text_CristinPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route9_Text_CoraIntro, Route9_Text_CoraDefeated
	msgbox Route9_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_StarterDome::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement 0
	applymovement LOCALID_DAZ_1, Common_Movement_FaceRight
	waitmovement 0
	emote LOCALID_DAZ_1, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_DAZ_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox Route9_Text_HeyNoWay, MSGBOX_AUTOCLOSE
	hideface 1
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 55
	goto_if_eq Route9_StarterDome_Top
	goto Route9_StarterDome_Bottom
	end

Route9_StarterDome_Top::
	applymovement LOCALID_DAZ_1, WR2U
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto Route9_StarterDome_DazIntro
	end

Route9_StarterDome_Bottom::
	applymovement LOCALID_DAZ_1, WR2FU
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto Route9_StarterDome_DazIntro
	end

Route9_StarterDome_DazIntro::
	applymovement LOCALID_PROF, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_DAZ_1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox Route9_Text_YoureTheOne, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_DAZ_1, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox Route9_Text_TheyreDoingAGiveaway, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_Text_TrainersAndTrainers, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_DAZ_1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox Route9_Text_YouAndProf, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_DAZ_1, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox Route9_Text_ComeOnEveryone, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_PROF, Common_Movement_WalkUp
	waitmovement 0
	opendoor 28, 53
	waitdooranim
	applymovement LOCALID_PROF, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_PROF
	closedoor 28, 53
	waitdooranim
	applymovement LOCALID_LITTLE_GIRL, WU3WIPSD
	waitmovement 0
	speakername CommonName_Text_LittleGirl
	msgbox Route9_Text_MommyMommy, MSGBOX_AUTOCLOSE
	applymovement LOCALID_MOTHER, WRU2
	applymovement LOCALID_GIRL, WLU2
	applymovement LOCALID_YOUNGSTER, FRD5WRU
	waitmovement 0
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceUp
	waitmovement 0
	opendoor 28, 53
	waitdooranim
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_WalkUp
	applymovement LOCALID_MOTHER, Common_Movement_WalkUp
	applymovement LOCALID_GIRL, Common_Movement_WalkUp
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_LITTLE_GIRL
	applymovement LOCALID_MOTHER, Common_Movement_WalkUp
	applymovement LOCALID_GIRL, Common_Movement_WalkUp
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_MOTHER
	applymovement LOCALID_GIRL, Common_Movement_WalkUp
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_GIRL
	applymovement LOCALID_YOUNGSTER, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_YOUNGSTER
	delay 10
	closedoor 28, 53
	waitdooranim
	applymovement LOCALID_DAZ_1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox Route9_Text_LetsGoPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_DAZ_1, WLU
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	compare VAR_TEMP_1, 55
	goto_if_eq Route9_StarterDome_EnterTop
	goto Route9_StarterDome_EnterBottom
	end

Route9_StarterDome_EnterTop::
	applymovement LOCALID_DAZ_1, WL2U
	applymovement OBJ_EVENT_ID_PLAYER, WL3FU
	applymovement OBJ_EVENT_ID_FOLLOWER, WL3
	waitmovement 0
	opendoor 28, 53
	waitdooranim
	applymovement LOCALID_DAZ_1, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceUp
	goto Route9_StarterDome_End
	end

Route9_StarterDome_EnterBottom::
	applymovement LOCALID_DAZ_1, WL2U2
	applymovement OBJ_EVENT_ID_PLAYER, WL3U
	applymovement OBJ_EVENT_ID_FOLLOWER, WL4FU
	waitmovement 0
	opendoor 28, 53
	waitdooranim
	applymovement LOCALID_DAZ_1, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	goto Route9_StarterDome_End
	end

Route9_StarterDome_End::
	waitmovement 0
	removeobject LOCALID_DAZ_1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_SetInvisible
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	setvar VAR_STORYLINE_STATE, 17
	warp MAP_ROUTE9_STARTER_DOME, 18, 36
	waitstate
	release
	end

Route9_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route9_Text_JosephIntro, Route9_Text_JosephDefeated
	msgbox Route9_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Snorlax::
	lock
	checkitem ITEM_POKE_FLUTE, 1
	compare VAR_RESULT, 1
	goto_if_eq Route9_Snorlax_WakeUp
	msgbox Route9_Text_ASleepingPokemonBlocksTheWay, MSGBOX_AUTOCLOSE
	release
	end

Route9_Snorlax_WakeUp:
	msgbox Route9_Text_FluteASleepingPokemonBlocksTheWay, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq Route9_Snorlax_WakeUp_Yes
	msgbox Route9_Text_YouLeftThePokemonSleep, MSGBOX_AUTOCLOSE
	release
	end

Route9_Snorlax_WakeUp_Yes::
	msgbox Route9_Text_PlayerPlayedThePokeFlute, MSGBOX_DEFAULT
	playfanfare MUS_RG_POKE_FLUTE
	waitfanfare
	closemessage
	delay 10
	playmoncry SPECIES_SNORLAX, 0
	waitmoncry
	delay 10
	msgbox Route9_Text_ThePokemonWokeUp, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_SNORLAX, 20, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_SNORLAX, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_SNORLAX
	removeobject 26
	removeobject 27
	setflag FLAG_ROUTE_9_SNORLAX
	fadescreen 0
	release
	end

Route9_DazBattle::
	lock
	setvar VAR_STORYLINE_STATE, 21
	clearflag FLAG_HIDE_DAZ_2_MUDKIP
	addobject LOCALID_DAZ_2
	addobject LOCALID_MUDKIP
	applymovement LOCALID_DAZ_2, WU5
	applymovement LOCALID_MUDKIP, WU5
	waitmovement 0
	applymovement LOCALID_DAZ_2, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox Route9_Text_PlayerIWasWaitingForYou, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_DAZ_2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox Route9_Text_LookWhatIGot, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_MUDKIP, Common_Movement_JumpInPlaceUp
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement LOCALID_MUDKIP, Common_Movement_JumpInPlaceUp
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_MUDKIP, 0
	speakername CommonName_Text_Mudkip
	msgbox Route9_Text_Mudkip, MSGBOX_AUTOCLOSE
	delay 20
	emote LOCALID_MUDKIP, 6
	playse SE_PIN
	waitse
	delay 60
	applymovement LOCALID_DAZ_2, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox Route9_Text_HahaILoveItAlready, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_DAZ_1, Daz1_Text_Defeated
	removeobject LOCALID_MUDKIP
	setflag FLAG_HIDE_DAZ_2_MUDKIP
	applymovement LOCALID_DAZ_2, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox Route9_Text_ILostButIllRememberThat, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_DAZ_2, WD5
	waitmovement 0
	removeobject LOCALID_DAZ_2
	setvar VAR_STORYLINE_STATE, 22
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

Route9_DazLost::
	removeobject LOCALID_MUDKIP
	removeobject LOCALID_DAZ_2
	setflag FLAG_HIDE_DAZ_2_MUDKIP
	setvar VAR_STORYLINE_STATE, 22
	end
	
WR2U:
	walk_right
	walk_right
	walk_up
	step_end

WR2FU:
	walk_right
	walk_right
	face_up
	step_end

WU3WIPSD:
	walk_up
	walk_up
	walk_up
	walk_in_place_slow_down
	step_end

WRU2:
	walk_right
	walk_up
	walk_up
	step_end

WLU2:
	walk_left
	walk_up
	walk_up
	step_end

FRD5WRU:
	face_right
	delay_16
	delay_16
	delay_8
	walk_right
	walk_up
	step_end

WLU:
	walk_left
	walk_up
	step_end

WL2U:
	walk_left
	walk_left
	walk_up
	step_end

WL3FU:
	walk_left
	walk_left
	walk_left
	face_up
	step_end

WL3:
	walk_left
	walk_left
	walk_left
	step_end

WL2U2:
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

WL3U:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

WL4FU:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

Route9_Text_Sign:
	.string "Route 9\n"
	.string "Starter Dome, Route 10 {DOWN_ARROW}$"

Route9_Text_Sign_Dome:
	.string "Starter Dome\n"
	.string "{FONT_SMALL}Get your starter Pokémon here!$"

Route9_Text_Boy:
	.string "{COLOR}{BLUE}Elemental Stones form throughout the\n"
	.string "region - they evolve certain Pokémon!\p"
	.string "For example, Ice Stone is found in icy\n"
	.string "places, and Fire Stone in hot places.\p"
	.string "They are rare, though, so you'll have\n"
	.string "to look carefully, if you want one!$"

Route9_Text_Old_Man:
	.string "And there a brave Charizard stood…\p"
	.string "He looked weak after being hit with a\n"
	.string "powerful Hydro Pump attack.\p"
	.string "Suddenly, Charizard flew towards his\n"
	.string "opponent at great speed!\p"
	.string "Yes, yes, he turned into a blur, with\n"
	.string "white streaks surrounding his body!\p"
	.string "With one swift slash… One quick dash…\p"
	.string "Clash!\p"
	.string "His opponent faints!\p"
	.string "And that, my friend, is the story of\n"
	.string "Aerial Ace.\l"
	.string "Take it - I insist!$"

Route9_Text_Old_Man_Given:
	.string "TM40 contains Aerial Ace!\n"
	.string "It's a fast move that can't be evaded.$"

Route9_Text_HeyNoWay:
	.string "{COLOR}{BLUE}Hey!\n"
	.string "… No way!$"

Route9_Text_YoureTheOne:
	.string "{COLOR}{BLUE}You're the one who beat Greendale\n"
	.string "Village's Champion!\p"
	.string "It's an honor to meet you,\n"
	.string "{PLAYER}!\p"
	.string "My name is Daz.\p"
	.string "I'm here to get my first Pokémon!$"

Route9_Text_TheyreDoingAGiveaway:
	.string "{COLOR}{BLUE}They're doing a giveaway! Look!$"

Route9_Text_TrainersAndTrainers:
	.string "Trainers and Trainers-to-be!\n"
	.string "Thank you for coming!\p"
	.string "I am Prof. Hawthorne.\p"
	.string "My aides and I will be giving every\n"
	.string "single one of you a Pokémon as part\l"
	.string "of a grand giveaway!\p"
	.string "Your new Pokémon shall be your\n"
	.string "companion and a boon to the start\l"
	.string "of your journey as a Pokémon Trainer.$"

Route9_Text_YouAndProf:
	.string "{COLOR}{BLUE}You and Prof. Hawthorne are from the\n"
	.string "same village, aren't you?\p"
	.string "He must've already given you a Pokémon\n"
	.string "if you got this far.\p"
	.string "But that's all right - the giveaway\n"
	.string "isn't only for new Trainers!$"

Route9_Text_ComeOnEveryone:
	.string "Come on, everyone!\n"
	.string "Follow me inside the Dome Laboratory!$"

Route9_Text_MommyMommy:
	.string "{COLOR}{RED}Mommy, Mommy, let's go inside!$"

Route9_Text_LetsGoPlayer:
	.string "{COLOR}{BLUE}Let's go, {PLAYER}!$"

Route9_Text_ASleepingPokemonBlocksTheWay:
	.string "A sleeping Pokémon blocks the way…$"

Route9_Text_FluteASleepingPokemonBlocksTheWay:
	.string "A sleeping Pokémon blocks the way…\n"
	.string "Would you like to use the Poké Flute?$"

Route9_Text_PlayerPlayedThePokeFlute:
	.string "{PLAYER} played the Poké Flute…$"

Route9_Text_ThePokemonWokeUp:
	.string "The Pokémon woke up!\n"
	.string "It attacked in a grumpy rage!$"

Route9_Text_YouLeftThePokemonSleep:
	.string "You left the Pokémon sleep in peace.$"

Route9_Text_PlayerIWasWaitingForYou:
	.string "{COLOR}{BLUE}{PLAYER}!\p"
	.string "I was waiting for you!\p"
	.string "You done catching that Pokémon?\n"
	.string "Sweet!$"

Route9_Text_LookWhatIGot:
	.string "{COLOR}{BLUE}Look what I got!\n"
	.string "A Mudkip!$"

Route9_Text_Mudkip:
	.string "Muddd-kiiipp!!$"

Route9_Text_HahaILoveItAlready:
	.string "{COLOR}{BLUE}Haha!\n"
	.string "I love it already!\p"
	.string "Alright, {PLAYER}!\n"
	.string "You know what time it is!\p"
	.string "Let's put our Pokémon to the test!$"

Route9_Text_ILostButIllRememberThat:
	.string "{COLOR}{BLUE}I lost, but I'll remember that.\p"
	.string "We'll meet again, {PLAYER}.\n"
	.string "You better be ready!$"
