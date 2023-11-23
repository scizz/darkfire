.set LOCALID_SAILOR_1, 6
.set LOCALID_SAILOR_2, 3
.set LOCALID_BOAT_1, 5
.set LOCALID_BOAT_2, 4
.set LOCALID_KOJIRO, 2

LaveriaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LaveriaCity_OnTransition
	.byte 0

LaveriaCity_OnTransition:
	call_if_set FLAG_HIDE_LAVERIA_CITY_SAILOR_1, LaveriaCity_ResetSailorEvent
	end

LaveriaCity_ResetSailorEvent::
	removeobject LOCALID_SAILOR_2
	removeobject LOCALID_BOAT_2
	addobject LOCALID_SAILOR_1
	addobject LOCALID_BOAT_1
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
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_IfYouAreHere, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	playbgm MUS_CHANDRA_VILLAGE, TRUE
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_NORMAL, 1, 1
	msgbox LaveriaCity_Text_WhatsThat, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_CAMERA, WSL3
	waitmovement 0
	special RemoveCameraObject
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_DotDotNo, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_NORMAL, 1, 1
	msgbox LaveriaCity_Text_DotDotYou, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	playfanfare MUS_OBTAIN_SYMBOL
	special DoDomeConfetti
	msgbox LaveriaCity_Text_PlayerDefeatedKojiro, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_KOJIRO, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_YouDidGood, MSGBOX_AUTOCLOSE
	hideface 1
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 12
	goto_if_eq LaveriaCity_Kojiro_Top
	goto LaveriaCity_Kojiro_Bottom
	end

LaveriaCity_Kojiro_Top::
	applymovement LOCALID_KOJIRO, WL4
	waitmovement 0
	goto LaveriaCity_Kojiro_End

LaveriaCity_Kojiro_Bottom::
	applymovement LOCALID_KOJIRO, WL2DL2
	waitmovement 0
	goto LaveriaCity_Kojiro_End
	end

LaveriaCity_Kojiro_End::
	giveitem ITEM_HM04, 1
	speakername CommonName_Text_Kojiro
	showface FS_KOJIRO, FSE_SAD, 1, 1
	msgbox LaveriaCity_Text_YouWillNeedThis, MSGBOX_AUTOCLOSE
	hideface 1
	fadescreen 1
	delay 30
	removeobject LOCALID_KOJIRO
	setflag FLAG_BADGE02_GET
	setvar VAR_STORYLINE_STATE, 19
	fadescreen 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

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
	.string "The ice will eventually defrost!$"

LaveriaCity_Text_Man2:
	.string "{COLOR}{BLUE}Headed for Route 7?\n"
	.string "It's beautiful, but unforgiving.\p"
	.string "The air is crisp and invigorating, and\n"
	.string "the frozen streams that snake through\l"
	.string "the area glisten in the sunlight.\p"
	.string "Be sure to bundle up, though.\n"
	.string "the temperatures can drop to\l"
	.string "bone-chilling levels.$"

LaveriaCity_Text_Boy_2:
	.string "{COLOR}{BLUE}Jeez! We've been snowed in!\n"
	.string "Again!\p"
	.string "Maybe I should have never moved here\n"
	.string "in the north and sat pretty at Pinleaf\l"
	.string "Town in the warm south…$"

LaveriaCity_Text_PokeFan:
	.string "{COLOR}{RED}I was once a Trainer, like you.\p"
	.string "I even won a couple of tournaments,\n"
	.string "but now I'm retired…\p"
	.string "It's a bit boring here, but at least\n"
	.string "I still have my trusted Pokémon!$"

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
	.string "If you are here for Laveria City's\n"
	.string "Tournament, you're late, Trainer.\p"
	.string "I became the Champion… Again."

LaveriaCity_Text_WhatsThat:
	.string "What's that?\p"
	.string "You really dare challenge me?\n"
	.string "On my home turf?"

LaveriaCity_Text_DotDotNo:
	.string "…\n"
	.string "…\p"
	.string "No, you aren't like the others…\n"
	.string "Power emanates through you.\p"
	.string "Yes, you intrigued me right away when\n"
	.string "I first saw you standing there.\p"
	.string "…\n"
	.string "Very well. I accept your challenge.\p"
	.string "If you can beat me twice, I will\n"
	.string "consider you as a Champion.\pLet's go!"

LaveriaCity_Text_HmhNotToWorry:
	.string "Hmh…\n"
	.string "Not to worry… We press on."

LaveriaCity_Text_DotDotYou:
	.string "…\n"
	.string "…\p"
	.string "You are more than meets the eye.\n"
	.string "A real Trainer, indeed.\p"
	.string "But how will you do in a Single Battle?\n"
	.string "Prepare yourself!"

LaveriaCity_Text_MyInstinctWasCorrect:
	.string "My instinct was correct…\n"
	.string "You are the new Champion."

LaveriaCity_Text_PlayerDefeatedKojiro:
	.string "{PLAYER} defeated Kojiro!"

LaveriaCity_Text_YouDidGood:
	.string "You did good, Trainer.\p"
	.string "I must ask, what is your name?\p"
	.string "…\n"
	.string "…\p"
	.string "{PLAYER}.\p"
	.string "Well, {PLAYER}.\n"
	.string "Please take this for your victory."

LaveriaCity_Text_YouWillNeedThis:
	.string "You will need this if you are to\n"
	.string "take on Mt. Tamarok, ahead.\p"
	.string "Good luck, {PLAYER}…"
