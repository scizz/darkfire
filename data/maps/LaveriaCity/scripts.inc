.set LOCALID_SAILOR_1, 6
.set LOCALID_SAILOR_2, 3
.set LOCALID_SAILOR_3, 19
.set LOCALID_BOAT_1, 5
.set LOCALID_BOAT_2, 4
.set LOCALID_KOJIRO, 2

LaveriaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LaveriaCity_OnTransition
	.byte 0

LaveriaCity_OnTransition:
	removeobject LOCALID_SAILOR_3
	setflag FLAG_HIDE_LAVERIA_CITY_SAILOR_3
	call_if_unset FLAG_TEMP_4, LaveriaCity_ResetSailorEvent
	call_if_unset FLAG_HIDE_LAVERIA_CITY_SAILOR_1, LaveriaCity_ResetSailorEvent
	end

LaveriaCity_ResetSailorEvent::
	removeobject LOCALID_SAILOR_2
	removeobject LOCALID_BOAT_2
	setflag FLAG_HIDE_LAVERIA_CITY_SAILOR_BOAT_ISLAND
	addobject LOCALID_SAILOR_1
	addobject LOCALID_BOAT_1
	clearflag FLAG_HIDE_LAVERIA_CITY_BOAT_1
	clearflag FLAG_HIDE_LAVERIA_CITY_SAILOR_1
	end

LaveriaCity_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, LaveriaCity_Sailor_SailMultiChoice
	goto_if_set FLAG_LAVERIA_CITY_AWAKENING_GIVEN, LaveriaCity_Sailor_SailToIsland
	goto_if_set FLAG_LAVERIA_CITY_AWAKENING_QUEST_STARTED, LaveriaCity_Sailor_CheckAwakening
	msgbox LaveriaCity_Text_WhatYouWantToUse, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq LaveriaCity_Sailor_QuestStarted
	msgbox LaveriaCity_Text_NoSuitYourself, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceDown
	waitmovement 0
	release
	end

LaveriaCity_Sailor_SailToIsland::
	msgbox LaveriaCity_Text_HelloTrainer, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq LaveriaCity_ChooseLaveriaIsland
	goto LaveriaCity_CancelSailSelect
	end

LaveriaCity_Sailor_QuestStarted::
	setflag FLAG_LAVERIA_CITY_AWAKENING_QUEST_STARTED
	msgbox LaveriaCity_Text_FantasticYouCanGetOne, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceDown
	waitmovement 0
	release
	end

LaveriaCity_Sailor_CheckAwakening::
	msgbox LaveriaCity_Text_HelloTrainerDidYouManage, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq LaveriaCity_Sailor_FindAwakening
	msgbox LaveriaCity_Text_WellGoGetIt, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceDown
	waitmovement 0
	release
	end

LaveriaCity_Sailor_FindAwakening::
	msgbox LaveriaCity_Text_GreatPleaseHandItOver, MSGBOX_AUTOCLOSE
	chooseitem ITEMS_POCKET
	goto_if_eq VAR_ITEM_ID, ITEM_AWAKENING, LaveriaCity_Sailor_GiveAwakening
	msgbox LaveriaCity_Text_HuhThisIsntAnAwakening, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceDown
	waitmovement 0
	release
	end

LaveriaCity_Sailor_GiveAwakening::
	removeitem ITEM_AWAKENING, 1
	msgbox LaveriaCity_Text_YouHandedOver, MSGBOX_AUTOCLOSE
	delay 30
	msgbox LaveriaCity_Text_AnAwakening, MSGBOX_AUTOCLOSE
	setflag FLAG_LAVERIA_CITY_AWAKENING_GIVEN
	setvar VAR_STORYLINE_STATE, 22
	goto LaveriaCity_SailToLaveriaIsland
	end

LaveriaCity_Sailor_SailMultiChoice::
	message LaveriaCity_Text_AhoyTrainer
	waitmessage
	multichoicedefault 21, 6, MULTI_LAVERIA_NORTHSTAR_SAIL, 2, FALSE
	switch VAR_RESULT
	case 0, LaveriaCity_ChooseNorthstarCity
	case 1, LaveriaCity_ChooseLaveriaIsland
	case 2, LaveriaCity_CancelSailSelect
	case MULTI_B_PRESSED, LaveriaCity_CancelSailSelect
	end

LaveriaCity_ChooseNorthstarCity::
	msgbox LaveriaCity_Text_RighteoThisWay, MSGBOX_AUTOCLOSE
	goto LaveriaCity_SailToNorthstarCity
	end

LaveriaCity_ChooseLaveriaIsland::
	msgbox LaveriaCity_Text_RighteoThisWay, MSGBOX_AUTOCLOSE
	goto LaveriaCity_SailToLaveriaIsland
	end

LaveriaCity_CancelSailSelect::
	msgbox LaveriaCity_Text_JustLetMeKnow, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceDown
	waitmovement 0
	release
	end

LaveriaCity_SailToNorthstarCity::
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceRight
	waitmovement 0
	removeobject LOCALID_SAILOR_1
	playse SE_EXIT
	waitse
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 42
	call_if_eq LaveriaCity_NorthstarPlayerTop
	goto LaveriaCity_NorthstarPlayerLeft
	end

LaveriaCity_NorthstarPlayerTop::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay144
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ShrinkPokemon
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto LaveriaCity_WarpToNorthstar
	end

LaveriaCity_NorthstarPlayerLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay144
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ShrinkPokemon
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto LaveriaCity_WarpToNorthstar
	end

LaveriaCity_WarpToNorthstar::
	warp MAP_NORTHSTAR_CITY, 92, 36
	waitstate
	end

LaveriaCity_SailToLaveriaIsland::
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceRight
	waitmovement 0
	removeobject LOCALID_SAILOR_1
	setflag FLAG_HIDE_LAVERIA_CITY_SAILOR_1
	playse SE_EXIT
	waitse
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 42
	call_if_eq LaveriaCity_IslandPlayerTop
	goto LaveriaCity_IslandPlayerLeft
	end

LaveriaCity_IslandPlayerTop::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay144
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ShrinkPokemon
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto LaveriaCity_SailToIsland
	end

LaveriaCity_IslandPlayerLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay144
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ShrinkPokemon
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto LaveriaCity_SailToIsland
	end

LaveriaCity_SailToIsland::
	playse SE_EXIT
	hidefollower
	applymovement OBJ_EVENT_ID_PLAYER, SetInvisible
	delay 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	waitse
	delay 30
	release
	playbgm MUS_SURFING, TRUE
	applymovement LOCALID_BOAT_1, SailToIsland
	applymovement OBJ_EVENT_ID_PLAYER, SailToIsland
	waitmovement 0
	playse SE_RG_SS_ANNE_HORN
	waitse
	clearflag FLAG_HIDE_LAVERIA_CITY_SAILOR_BOAT_ISLAND
	addobject LOCALID_BOAT_2
	removeobject LOCALID_BOAT_1
	setflag FLAG_HIDE_LAVERIA_CITY_BOAT_1
	clearflag FLAG_HIDE_LAVERIA_CITY_SAILOR_3
	playse SE_EXIT
	addobject LOCALID_SAILOR_3
	applymovement LOCALID_SAILOR_3, WUL
	waitmovement 0
	waitse
	applymovement LOCALID_SAILOR_3, Common_Movement_FaceRight
	waitmovement 0
	addobject LOCALID_SAILOR_2
	removeobject LOCALID_SAILOR_3
	setflag FLAG_HIDE_LAVERIA_CITY_SAILOR_3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, SetVisible
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	waitse
	applymovement LOCALID_SAILOR_2, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox LaveriaCity_Text_HereWeAreFeastYourEyes, MSGBOX_AUTOCLOSE
	setflag FLAG_TEMP_4
	end

LaveriaCity_SailorTwo::
	lock
	faceplayer
	msgbox LaveriaCity_Text_HeyoTrainer, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq LaveriaCity_SailorTwo_Yes
	goto LaveriaCity_SailorTwo_No
	end

LaveriaCity_SailorTwo_Yes::
	msgbox LaveriaCity_Text_VeryWellBackIntoTheCabin, MSGBOX_AUTOCLOSE
	goto LaveriaCity_SailorTwo_CheckPlayerPos
	end

LaveriaCity_SailorTwo_No::
	msgbox LaveriaCity_Text_JustLetMeKnow, MSGBOX_AUTOCLOSE
	release
	end

LaveriaCity_SailorTwo_CheckPlayerPos::
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 14
	call_if_eq LaveriaCity_SailorTwo_IslandPlayerRight
	goto LaveriaCity_SailorTwo_IslandPlayerBottom
	end

LaveriaCity_SailorTwo_IslandPlayerRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay144
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ShrinkPokemon
	waitmovement 0
	delay 30
	applymovement LOCALID_SAILOR_2, WDR
	waitmovement 0
	applymovement LOCALID_SAILOR_2, Common_Movement_FaceDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SAILOR_2
	setflag FLAG_HIDE_LAVERIA_CITY_SAILOR_BOAT_ISLAND
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	goto LaveriaCity_SailorTwo_SailBackToLaveria
	end

LaveriaCity_SailorTwo_IslandPlayerBottom::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay144
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ShrinkPokemon
	waitmovement 0
	delay 30
	applymovement LOCALID_SAILOR_2, WRD
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SAILOR_2
	setflag FLAG_HIDE_LAVERIA_CITY_SAILOR_BOAT_ISLAND
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	goto LaveriaCity_SailorTwo_SailBackToLaveria
	end

LaveriaCity_SailorTwo_SailBackToLaveria::
	playse SE_EXIT
	hidefollower
	applymovement OBJ_EVENT_ID_PLAYER, SetInvisible
	delay 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	waitse
	delay 30
	release
	playbgm MUS_SURFING, TRUE
	applymovement LOCALID_BOAT_2, SailToCity
	applymovement OBJ_EVENT_ID_PLAYER, SailToCity
	waitmovement 0
	playse SE_RG_SS_ANNE_HORN
	waitse
	clearflag FLAG_HIDE_LAVERIA_CITY_BOAT_1
	addobject LOCALID_BOAT_1
	removeobject LOCALID_BOAT_2
	clearflag FLAG_HIDE_LAVERIA_CITY_SAILOR_1
	playse SE_EXIT
	addobject LOCALID_SAILOR_1
	applymovement LOCALID_SAILOR_1, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceRight
	waitmovement 0
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, SetVisible
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	waitse
	applymovement LOCALID_SAILOR_1, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox LaveriaCity_Text_WellHereWeAreJustLetMeKnow, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement LOCALID_SAILOR_1, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_SAILOR_1, Common_Movement_FaceDown
	waitmovement 0
	end

LaveriaCity_Sign::
	msgbox LaveriaCity_Text_Sign, MSGBOX_SIGN
	end

LaveriaCity_Sign_Route::
	msgbox LaveriaCity_Text_Sign_Route, MSGBOX_SIGN
	end

LaveriaCity_Sign_Locked::
	msgbox LaveriaCity_Text_Sign_Locked, MSGBOX_SIGN
	end

LaveriaCity_Little_Boy::
	msgbox LaveriaCity_Text_Little_Boy, MSGBOX_NPC
	end

LaveriaCity_Big_Sister::
	msgbox LaveriaCity_Text_Big_Sister, MSGBOX_NPC
	end

LaveriaCity_Boy_1::
	msgbox LaveriaCity_Text_Boy_1, MSGBOX_NPC
	end

LaveriaCity_Man::
	msgbox LaveriaCity_Text_Man, MSGBOX_NPC
	end

LaveriaCity_Man2::
	msgbox LaveriaCity_Text_Man2, MSGBOX_NPC
	end

LaveriaCity_Boy_2::
	msgbox LaveriaCity_Text_Boy_2, MSGBOX_NPC
	end

LaveriaCity_PokeFan::
	msgbox LaveriaCity_Text_PokeFan, MSGBOX_NPC
	end

LaveriaCity_Old_Man::
	msgbox LaveriaCity_Text_Old_Man, MSGBOX_NPC
	end

LaveriaCity_Kojiro::
	lock
	playbgm MUS_NONE, TRUE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WSR3
	waitmovement 0
	getpartysize
	compare VAR_RESULT, 2
	goto_if_ge LaveriaCity_Kojiro_Battle
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_NoIHaveNoTime, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_CAMERA, WSL3
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeft
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LaveriaCity_Kojiro_Battle::
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_IfYouAreHere, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_NORMAL, 1, 1
	msgbox LaveriaCity_Text_WhatsThat, MSGBOX_AUTOCLOSE
	hideface 1
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 12
	goto_if_eq LaveriaCity_Kojiro_Top
	goto LaveriaCity_Kojiro_Bottom
	end

LaveriaCity_Kojiro_Battle_2::
	special RemoveCameraObject
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_DotDotNo, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_KOJIRO_1, Kojiro1_Text_Defeated
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_NORMAL, 1, 1
	msgbox LaveriaCity_Text_DotDotYou, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_KOJIRO_2, Kojiro2_Text_Defeated
	playfanfare MUS_OBTAIN_SYMBOL
	special DoDomeConfetti
	savebgm MUS_DUMMY
	fadedefaultbgm
	msgbox LaveriaCity_Text_PlayerDefeatedKojiro, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_YouDidGood, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_HM04, 1
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_YouWillNeedThis, MSGBOX_AUTOCLOSE
	hideface 1
	fadescreen 1
	delay 30
	removeobject LOCALID_KOJIRO
	setflag FLAG_BADGE02_GET
	setvar VAR_ROUTE_7_STATE, 1
	setvar VAR_STORYLINE_STATE, 23
	fadescreen 0
	release
	end

LaveriaCity_Kojiro_Top::
	applymovement OBJ_EVENT_ID_CAMERA, WL3
	applymovement LOCALID_KOJIRO, WL4
	waitmovement 0
	goto LaveriaCity_Kojiro_Battle_2
	end

LaveriaCity_Kojiro_Bottom::
	applymovement OBJ_EVENT_ID_CAMERA, WL3
	applymovement LOCALID_KOJIRO, WL2DL2
	waitmovement 0
	goto LaveriaCity_Kojiro_Battle_2
	end

SailToIsland:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

SailToCity:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_down
	step_end

WUL:
	walk_up
	walk_left
	step_end

WRD:
	walk_right
	walk_down
	step_end

WSR3:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

WSL3:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

WL4:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WL2DL2:
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	step_end

SetVisible:
	set_visible
	step_end

LaveriaCity_Text_WhatYouWantToUse:
	.string "{COLOR}{BLUE}What? You want to use my boat to get\n"
	.string "to the island nearby?\p"
	.string "Well, I'm busy fishing as you can see.\p"
	.string "But, perhaps there is something you\n"
	.string "could do for me…\p"
	.string "My son is lazy and won't get up early\n"
	.string "in the morning! It's driving me mad!\p"
	.string "I need an Awakening to get him to wake\n"
	.string "up on time.\p"
	.string "Find one for me and we can talk about\n"
	.string "getting you across the water. Deal?$\p"

LaveriaCity_Text_NoSuitYourself:
	.string "{COLOR}{BLUE}No?\p"
	.string "Suit yourself!$"

LaveriaCity_Text_FantasticYouCanGetOne:
	.string "{COLOR}{BLUE}Fantastic!\p"
	.string "You can get an Awakening from a buddy\n"
	.string "of mine in Route 9.$"

LaveriaCity_Text_HelloTrainer:
	.string "{COLOR}{BLUE}Hello, Trainer!\n"
	.string "Do you want to sail to Laveria Island?$"

LaveriaCity_Text_JustLetMeKnow:
	.string "{COLOR}{BLUE}Just let me know when you wanna sail!$"

LaveriaCity_Text_HelloTrainerDidYouManage:
	.string "{COLOR}{BLUE}Hello, Trainer!\p"
	.string "Did you manage to fetch that Awakening\n"
	.string "from my buddy in Route 9?$"

LaveriaCity_Text_GreatPleaseHandItOver:
	.string "{COLOR}{BLUE}Great!\n"
	.string "Please hand it over…$"

LaveriaCity_Text_HuhThisIsntAnAwakening:
	.string "{COLOR}{BLUE}Huh?\n"
	.string "This isn't an Awakening…\p"
	.string "Find one for me and we can talk about\n"
	.string "getting you across the water. Deal?$\p"

LaveriaCity_Text_WellGoGetIt:
	.string "{COLOR}{BLUE}Well, go get it and we can talk about\n"
	.string "getting you across the water. Deal?$"

LaveriaCity_Text_YouHandedOver:
	.string "You handed over an Awakening to the\n"
	.string "Sailor.$"

LaveriaCity_Text_AnAwakening:
	.string "{COLOR}{BLUE}An Awakening!\n"
	.string "My thanks!\p"
	.string "Fine, let's go.\n"
	.string "I was done fishing anyway…$"

LaveriaCity_Text_AhoyTrainer:
	.string "{COLOR}{BLUE}Ahoy, Trainer!\n"
	.string "Where would you like to sail to?$"

LaveriaCity_Text_RighteoThisWay:
	.string "{COLOR}{BLUE}Righteo!\n"
	.string "This way into the cabin!$"

LaveriaCity_Text_HereWeAreFeastYourEyes:
	.string "{COLOR}{BLUE}Here we are!\n"
	.string "Feast your eyes on Laveria Island!\p"
	.string "Just let me know when you want to sail\n"
	.string "back to the city, okay?$"

LaveriaCity_Text_HeyoTrainer:
	.string "{COLOR}{BLUE}Heyo, Trainer!\p"
	.string "Do you want to sail back to Laveria\n"
	.string "City?$"

LaveriaCity_Text_VeryWellBackIntoTheCabin:
	.string "{COLOR}{BLUE}Very well!\n"
	.string "Back into the cabin, partner!$"

LaveriaCity_Text_WellHereWeAreJustLetMeKnow:
	.string "{COLOR}{BLUE}Well, here we are!\p"
	.string "Just let me know when you want to\n"
	.string "sail across again, 'kay?$"

LaveriaCity_Text_Sign:
	.string "Welcome to Laveria City\n"
	.string "{FONT_SMALL}“Where Pokémon Warmth Meets Snowy Comfort”$"

LaveriaCity_Text_Sign_Route:
	.string "{LEFT_ARROW} Route 7$"

LaveriaCity_Text_Sign_Locked:
	.string "The door is locked…$"

LaveriaCity_Text_Little_Boy:
	.string "{COLOR}{BLUE}My big sister says someone with Surf\n"
	.string "can get to that island off the coast.\p"
	.string "I wish I had a Pokémon that knew Surf…$"

LaveriaCity_Text_Big_Sister:
	.string "{COLOR}{RED}During the night, I saw something\n"
	.string "glitter in the ocean.\p"
	.string "It was coming from the direction of\n"
	.string "that island off the coast of the city.\p"
	.string "What could it have been?$"

LaveriaCity_Text_Boy_1:
	.string "{COLOR}{BLUE}See that item across the fence?\n"
	.string "I've been trying to get it forever.\p"
	.string "The fence is too high and there's no\n"
	.string "way to get there by the frozen pond.\p"
	.string "Won't the pond ever defrost?\n"
	.string "Is it always winter in this city?$"

LaveriaCity_Text_Man:
	.string "{COLOR}{BLUE}This frozen pond wasn't always frozen…\p"
	.string "No, it completely froze over as a\n"
	.string "result of this harsh weather.\p"
	.string "Oh, well…\n"
	.string "The ice will eventually defrost.$"

LaveriaCity_Text_Man2:
	.string "{COLOR}{BLUE}Headed for Route 7?\n"
	.string "It's beautiful, but unforgiving.\p"
	.string "The air is crisp and invigorating, and\n"
	.string "the frozen streams that snake through\l"
	.string "the area glisten in the sunlight.\p"
	.string "Be sure to bundle up, though.\p"
	.string "The temperatures can drop to\n"
	.string "bone-chilling levels.$"

LaveriaCity_Text_Boy_2:
	.string "{COLOR}{BLUE}Jeez! We've been snowed in!\n"
	.string "Again!\p"
	.string "Maybe I should have never moved here\n"
	.string "in the north and sat pretty at Pinleaf\l"
	.string "Town in the warm south…$"

LaveriaCity_Text_PokeFan:
	.string "{COLOR}{RED}I was once a Trainer, like you.\n"
	.string "I even won a couple of tournaments.\p"
	.string "But now, I'm retired…\p"
	.string "It's a bit boring here, but at least\n"
	.string "I still have my trusted Pokémon.$"

LaveriaCity_Text_Old_Man:
	.string "Ha!\p"
	.string "Little young Trainer, where do you\n"
	.string "think you are going?\p"
	.string "You think you have what it takes to\n"
	.string "brave the snowstorm in Route 7?$"

LaveriaCity_Text_NoIHaveNoTime:
	.string "{COLOR}{BLUE}No… I have no time for you.\n"
	.string "Come back when you are stronger.$"

LaveriaCity_Text_IfYouAreHere:
	.string "{COLOR}{BLUE}If you are here for Laveria City's\n"
	.string "Tournament, you're late, Trainer.\p"
	.string "I, Kojiro, became the Champion…\n"
	.string "Again.$"

LaveriaCity_Text_WhatsThat:
	.string "{COLOR}{BLUE}What's that?\p"
	.string "You really dare challenge me?\n"
	.string "On my home turf?$"

LaveriaCity_Text_DotDotNo:
	.string "{COLOR}{BLUE}… … …\n"
	.string "… … …\p"
	.string "No, you aren't like the others…\n"
	.string "Power emanates through you.\p"
	.string "Yes, you intrigued me right away when\n"
	.string "I first saw you standing there.\p"
	.string "…\n"
	.string "Very well. I accept your challenge.\p"
	.string "If you can beat me twice, I will\n"
	.string "consider you as a Champion.\p"
	.string "Let's go!$"

LaveriaCity_Text_HmhNotToWorry:
	.string "Hmh…\n"
	.string "Not to worry… We press on.$"

LaveriaCity_Text_DotDotYou:
	.string "{COLOR}{BLUE}… … …\n"
	.string "… … …\p"
	.string "You are more than meets the eye.\n"
	.string "A real Trainer, indeed.\p"
	.string "But how will you do in a Single Battle?\n"
	.string "Prepare yourself!$"

LaveriaCity_Text_MyInstinctWasCorrect:
	.string "My instinct was correct…\n"
	.string "You are the new Champion.$"

LaveriaCity_Text_PlayerDefeatedKojiro:
	.string "{PLAYER} defeated Kojiro!$"

LaveriaCity_Text_YouDidGood:
	.string "{COLOR}{BLUE}You did good, Trainer.\p"
	.string "I must ask, what is your name?\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "{PLAYER}.\p"
	.string "Well, {PLAYER}.\n"
	.string "Please take this for your victory.$"

LaveriaCity_Text_YouWillNeedThis:
	.string "{COLOR}{BLUE}You will need this if you are to\n"
	.string "take on Mt. Tamarok, ahead.\p"
	.string "Good luck, {PLAYER}…$"
