.set LOCALID_SHINY_NOCTOWL, 12
.set LOCALID_HOOTHOOT, 13
.set LOCALID_NOCTOWL, 14

SnowdriftForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SnowdriftForest_OnTransition
	.byte

SnowdriftForest_OnTransition:
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	call SnowdriftForest_HideOwls
	end

SnowdriftForest_HideOwls::
	removeobject LOCALID_HOOTHOOT
	removeobject LOCALID_NOCTOWL
	removeobject LOCALID_SHINY_NOCTOWL
	return

SnowdriftForest_Sign::
	msgbox SnowdriftForest_Text_Sign, MSGBOX_SIGN
	end

SnowdriftForest_Hiker::
	msgbox SnowdriftForest_Text_Hiker, MSGBOX_NPC
	end

SnowdriftForest_Bug_Catcher::
	msgbox SnowdriftForest_Text_Bug_Catcher, MSGBOX_NPC
	end

SnowdriftForest_Old_Lady::
	msgbox SnowdriftForest_Text_Old_Lady, MSGBOX_NPC
	end

SnowdriftForest_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, SnowdriftForest_Text_PaulaIntro, SnowdriftForest_Text_PaulaDefeated
	msgbox SnowdriftForest_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

SnowdriftForest_EventScript_Angelina::
	trainerbattle_single TRAINER_ANGELINA, SnowdriftForest_Text_AngelinaIntro, SnowdriftForest_Text_AngelinaDefeated
	msgbox SnowdriftForest_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
	end

SnowdriftForest_EventScript_Nob::
	trainerbattle_single TRAINER_NOB, SnowdriftForest_Text_NobIntro, SnowdriftForest_Text_NobDefeated
	msgbox SnowdriftForest_Text_NobPostBattle, MSGBOX_AUTOCLOSE
	end

SnowdriftForest_IceNest::
	lock
	questmenu QUEST_MENU_CHECK_ACTIVE QUEST_2
	goto_if_eq VAR_RESULT, FALSE, SnowdriftForest_IceNest_QuestNotStarted
	msgbox SnowdriftForest_Text_ItsAnEmpty, MSGBOX_AUTOCLOSE
	checkitem ITEM_SHEENY_SEED, 1
	compare VAR_RESULT, 1
	goto_if_ge SnowdriftForest_IceNest_PlantSeed
	checkitem ITEM_GLEAMING_SEED, 1
	compare VAR_RESULT, 1
	goto_if_ge SnowdriftForest_IceNest_PlantSeed
	release
	end

SnowdriftForest_IceNest_QuestNotStarted::
	msgbox SnowdriftForest_Text_ItsAnEmpty, MSGBOX_AUTOCLOSE
	release
	end

SnowdriftForest_IceNest_PlantSeed::
	msgbox SnowdriftForest_Text_PlantASeed, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq SnowdriftForest_IceNest_OpenBag
	release
	end

SnowdriftForest_IceNest_OpenBag::
	chooseitem ITEMS_POCKET
	goto_if_eq VAR_ITEM_ID, ITEM_SHEENY_SEED, SnowdriftForest_IceNest_PlantedSheenySeed
	goto_if_eq VAR_ITEM_ID, ITEM_GLEAMING_SEED, SnowdriftForest_IceNest_PlantedGleamingSeed
	msgbox SnowdriftForest_Text_YouCantPlantThisItem, MSGBOX_AUTOCLOSE
	release
	end

SnowdriftForest_IceNest_PlantedSheenySeed::
	msgbox SnowdriftForest_Text_PlayerPlantedTheSheenySeed, MSGBOX_DEFAULT
	playse SE_FU_ZAKU
	waitse
	closemessage
	delay 30
	clearflag FLAG_SNOWDRIFT_FOREST_OWL
	addobject LOCALID_HOOTHOOT
	msgbox SnowdriftForest_Text_TheTreesShookAbove, MSGBOX_AUTOCLOSE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU3
	waitmovement 0
	applymovement LOCALID_HOOTHOOT, WD3
	waitmovement 0
	delay 30
	applymovement LOCALID_HOOTHOOT, WD4
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WD3
	waitmovement 0
	special RemoveCameraObject
	playmoncry SPECIES_HOOTHOOT, 0
	speakername CommonName_Text_HootHoot
	msgbox SnowdriftForest_Text_HooHoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	random 5
	switch VAR_RESULT
	case 0, SnowdriftForest_IceNest_HootHootOne
	case 1, SnowdriftForest_IceNest_HootHootTwo
	case 2, SnowdriftForest_IceNest_HootHootThree
	case 3, SnowdriftForest_IceNest_HootHootFour
	case 4, SnowdriftForest_IceNest_HootHootFive
	end

SnowdriftForest_IceNest_PlantedGleamingSeed::
	msgbox SnowdriftForest_Text_PlayerPlantedTheGleamingSeed, MSGBOX_DEFAULT
	playse SE_FU_ZAKU
	waitse
	closemessage
	delay 30
	playse SE_M_MORNING_SUN
	waitse
	delay 30
	goto_if_set FLAG_SNOWDRIFT_FOREST_SHINY_NOCTOWL, SnowdriftForest_IceNest_SpawnNoctowl
	clearflag FLAG_SNOWDRIFT_FOREST_OWL
	addobject LOCALID_SHINY_NOCTOWL
	msgbox SnowdriftForest_Text_TheTreesGlistenedAbove, MSGBOX_AUTOCLOSE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU3
	waitmovement 0
	applymovement LOCALID_SHINY_NOCTOWL, WD3
	waitmovement 0
	delay 30
	applymovement LOCALID_SHINY_NOCTOWL, WD4
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WD3
	waitmovement 0
	special RemoveCameraObject
	playmoncry SPECIES_NOCTOWL, 0
	speakername CommonName_Text_Noctowl
	msgbox SnowdriftForest_Text_Karr, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_SHINY_CREATION
	setwildbattle SPECIES_NOCTOWL, 20, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_NOCTOWL, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_SHINY_NOCTOWL
	questmenu QUEST_MENU_CHECK_COMPLETE QUEST_2
	call_if_eq VAR_RESULT, FALSE, SnowdriftForest_IceNest_CompleteQuest
	setflag FLAG_SNOWDRIFT_FOREST_SHINY_NOCTOWL
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	clearflag FLAG_SHINY_CREATION
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_CompleteQuest::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_2
	completequest QUEST_2
	return

SnowdriftForest_IceNest_SpawnNoctowl::
	clearflag FLAG_SNOWDRIFT_FOREST_OWL
	addobject LOCALID_NOCTOWL
	msgbox SnowdriftForest_Text_TheTreesShookAbove, MSGBOX_AUTOCLOSE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU3
	waitmovement 0
	applymovement LOCALID_NOCTOWL, WD3
	waitmovement 0
	delay 30
	applymovement LOCALID_NOCTOWL, WD4
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WD3
	waitmovement 0
	special RemoveCameraObject
	playmoncry SPECIES_NOCTOWL, 0
	speakername CommonName_Text_Noctowl
	msgbox SnowdriftForest_Text_Karr, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	random 5
	switch VAR_RESULT
	case 0, SnowdriftForest_IceNest_NoctowlOne
	case 1, SnowdriftForest_IceNest_NoctowlTwo
	case 2, SnowdriftForest_IceNest_NoctowlThree
	case 3, SnowdriftForest_IceNest_NoctowlFour
	case 4, SnowdriftForest_IceNest_NoctowlFive
	end

SnowdriftForest_IceNest_NoctowlOne::
	setwildbattle SPECIES_NOCTOWL, 17, ITEM_SITRUS_BERRY
	dowildbattle
	playmoncry SPECIES_NOCTOWL, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_NOCTOWL
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_NoctowlTwo::
	setwildbattle SPECIES_NOCTOWL, 20, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_NOCTOWL, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_NOCTOWL
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_NoctowlThree::
	setwildbattle SPECIES_NOCTOWL, 18, ITEM_ULTRA_BALL
	dowildbattle
	playmoncry SPECIES_NOCTOWL, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_NOCTOWL
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_NoctowlFour::
	setwildbattle SPECIES_NOCTOWL, 19, ITEM_NUGGET
	dowildbattle
	playmoncry SPECIES_NOCTOWL, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_NOCTOWL
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_NoctowlFive::
	setwildbattle SPECIES_NOCTOWL, 21, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_NOCTOWL, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_NOCTOWL
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_HootHootOne::
	setwildbattle SPECIES_HOOTHOOT, 14, ITEM_SHEENY_SEED
	dowildbattle
	playmoncry SPECIES_HOOTHOOT, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_HOOTHOOT
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_HootHootTwo::
	setwildbattle SPECIES_HOOTHOOT, 17, ITEM_POKE_BALL
	dowildbattle
	playmoncry SPECIES_HOOTHOOT, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_HOOTHOOT
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_HootHootThree::
	setwildbattle SPECIES_HOOTHOOT, 15, ITEM_GREAT_BALL
	dowildbattle
	playmoncry SPECIES_HOOTHOOT, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_HOOTHOOT
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_HootHootFour::
	setwildbattle SPECIES_HOOTHOOT, 16, ITEM_SHEENY_SEED
	dowildbattle
	playmoncry SPECIES_HOOTHOOT, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_HOOTHOOT
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_IceNest_HootHootFive::
	setwildbattle SPECIES_HOOTHOOT, 18, ITEM_SHEENY_SEED
	dowildbattle
	playmoncry SPECIES_HOOTHOOT, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_HOOTHOOT
	setflag FLAG_SNOWDRIFT_FOREST_OWL
	fadescreen 0
	release
	end

SnowdriftForest_Text_Sign:
	.string "Snowdrift Forest\n"
	.string "{UP_ARROW} Route 8$"

SnowdriftForest_Text_Hiker:
	.string "I live in Highwind Village, but every\n"
	.string "morning I come to this spot to look\l"
	.string "over the expanse of Snowdrift Forest.\p"
	.string "The snow-covered firs and the calmness\n"
	.string "of it all always soothes my soul…$"

SnowdriftForest_Text_Bug_Catcher:
	.string "{COLOR}{BLUE}I-I d-don't know why I c-came here\n"
	.string "d-dressed like th-this…\p"
	.string "I can't f-find a-any bugs here!\n"
	.string "Worst t-trip ever…$"

SnowdriftForest_Text_Old_Lady:
	.string "I'm trying to catch a glimpse of a\n"
	.string "wild Stantler.\p"
	.string "It's difficult to see one because\n"
	.string "they're fairly timid creatures.\p"
	.string "The secret is to tread lightly,\n"
	.string "otherwise they'll hide in the grass!$"

SnowdriftForest_Text_ItsAnEmpty:
	.string "It's an empty bird nest…\n"
	.string "Maybe a Pokémon can be lured here.$"

SnowdriftForest_Text_PlantASeed:
	.string "Plant a Seed?$"

SnowdriftForest_Text_YouCantPlantThisItem:	
	.string "You can't plant this item here.$"

SnowdriftForest_Text_PlayerPlantedTheSheenySeed:
	.string "{PLAYER} planted the Sheeny Seed…$"

SnowdriftForest_Text_PlayerPlantedTheGleamingSeed:
	.string "{PLAYER} planted the Gleaming\n"
	.string "Seed…$"

SnowdriftForest_Text_TheTreesGlistenedAbove:
	.string "The trees glistened above!$"

SnowdriftForest_Text_TheTreesShookAbove:
	.string "The trees shook above!$"

SnowdriftForest_Text_Karr:
	.string "Karrrr!$"

SnowdriftForest_Text_HooHoo:
	.string "Hoo! Hoo!$"
