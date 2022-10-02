.set LOCALID_SUBO, 24
.set LOCALID_TYLER, 19

AnheimForest_MapScripts::
	.byte 0

AnheimForest_SUBO::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	opendoor 31, 45
	waitdooranim
	clearflag FLAG_HIDE_ANHEIM_FOREST_SUBO
	addobject LOCALID_SUBO
	applymovement LOCALID_SUBO, Common_Movement_WalkDown
	waitmovement 0
	closedoor 31, 45
	waitdooranim
	msgbox AnheimForest_Text_SUBO_Dots, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_SUBO, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox AnheimForest_Text_WhereDidThatBeedrill, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_SUBO, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_SUBO, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO, Common_Movement_FaceUp
	waitmovement 0
	opendoor 31, 45
	waitdooranim
	applymovement LOCALID_SUBO, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_SUBO
	setflag FLAG_HIDE_ANHEIM_FOREST_SUBO
	closedoor 31, 45
	waitdooranim
	setvar VAR_STORYLINE_STATE, 13
	release
	end

AnheimForest_Sign::
	msgbox AnheimForest_Text_Sign, MSGBOX_SIGN
	end

AnheimForest_Sign_Town::
	msgbox AnheimForest_Text_Sign_Town, MSGBOX_SIGN
	end

AnheimForest_EventScript_Matthew::
	trainerbattle_single TRAINER_MATTHEW, AnheimForest_Text_MatthewIntro, AnheimForest_Text_MatthewDefeated
	msgbox AnheimForest_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_LARRY::
	trainerbattle_single TRAINER_LARRY, AnheimForest_Text_LarryIntro, AnheimForest_Text_LarryDefeated
	msgbox AnheimForest_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_ROBIN::
	trainerbattle_single TRAINER_ROBIN, AnheimForest_Text_RobinIntro, AnheimForest_Text_RobinDefeated
	msgbox AnheimForest_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_DAVIS::
	trainerbattle_single TRAINER_DAVIS, AnheimForest_Text_DavisIntro, AnheimForest_Text_DavisDefeated
	msgbox AnheimForest_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_EventScript_DOUG::
	trainerbattle_single TRAINER_DOUG, AnheimForest_Text_DougIntro, AnheimForest_Text_DougDefeated
	msgbox AnheimForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

AnheimForest_LucysMother::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_ANHEIM_FOREST_LUCY, AnheimForest_LucysMotherSaved
	goto_if_eq VAR_TEMP_2, 1, AnheimForest_LucysMotherRecap
	setvar VAR_TEMP_2, 1
	msgbox AnheimForest_Text_MotherIntro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq AnheimForest_LucysMotherYes
	goto AnheimForest_LucysMotherRecap
	end

AnheimForest_LucysMotherYes::
	msgbox AnheimForest_Text_MotherAnswerYes, MSGBOX_DEFAULT
	release
	end

AnheimForest_LucysMotherRecap::
	msgbox AnheimForest_Text_MotherRecap, MSGBOX_DEFAULT
	release
	end

AnheimForest_LucysFather::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_ANHEIM_FOREST_LUCY, AnheimForest_LucysFatherSaved
	goto_if_eq VAR_TEMP_2, 1, AnheimForest_LucysFatherRecap
	setvar VAR_TEMP_2, 1
	msgbox AnheimForest_Text_FatherIntro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq AnheimForest_LucysFatherYes
	goto AnheimForest_LucysFatherRecap
	end

AnheimForest_LucysFatherYes::
	msgbox AnheimForest_Text_FatherAnswerYes, MSGBOX_DEFAULT
	release
	end

AnheimForest_LucysFatherRecap::
	msgbox AnheimForest_Text_FatherRecap, MSGBOX_DEFAULT
	release
	end

AnheimForest_LucysMotherSaved::
	msgbox AnheimForest_Text_MotherLucySaved, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox AnheimForest_Text_MotherRareCandy, MSGBOX_DEFAULT
	closemessage
	goto AnheimForest_LucyEventEnd
	end

AnheimForest_LucysFatherSaved::
	msgbox AnheimForest_Text_FatherLucySaved, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox AnheimForest_Text_FatherRareCandy, MSGBOX_DEFAULT
	closemessage
	goto AnheimForest_LucyEventEnd
	end

AnheimForest_LucyEventEnd::
	applymovement 33, Common_Movement_WalkUp
	applymovement 34, Common_Movement_WalkUp
	waitmovement 0
	playse SE_EXIT
	removeobject 33
	removeobject 34
	setflag FLAG_HIDE_ANHEIM_FOREST_LUCYS_PARENTS
	waitse
	release
	end

AnheimForest_Beedrill::
	lock
	faceplayer
	playmoncry SPECIES_BEEDRILL, 0
	msgbox AnheimForest_Text_Beedrill, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_BEEDRILL, 7, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_BEEDRILL, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject 27
	setflag FLAG_HIDE_ANHEIM_FOREST_BEEDRILL
	setobjectmovementtype 26, MOVEMENT_TYPE_FACE_LEFT
	fadescreen 0
	release
	end

AnheimForest_Lucy::
	lock
	faceplayer
	msgbox AnheimForest_Text_Lucy, MSGBOX_DEFAULT
	delay 30
	msgbox AnheimForest_Text_Dots, MSGBOX_DEFAULT
	delay 30
	msgbox AnheimForest_Text_PleaseMove, MSGBOX_DEFAULT
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceDown
	waitmovement 0
	applymovement 26, WL5
	waitmovement 0
	applymovement 27, Common_Movement_FaceRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox AnheimForest_Text_Thanks, MSGBOX_DEFAULT
	closemessage
	applymovement 26, WDL4
	waitmovement 0
	removeobject 26
	setflag FLAG_HIDE_ANHEIM_FOREST_LUCY
	release
	end

AnheimForest_Tyler_Encounter::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox AnheimForest_Text_HmmHowDoIGetPast, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_TYLER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	delay 10
	msgbox AnheimForest_Text_Player, MSGBOX_AUTOCLOSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 21
	goto_if_eq AnheimForest_Tyler_Encounter_Up
	applymovement LOCALID_TYLER, WR4UR
	waitmovement 0
	goto AnheimForest_Tyler_Encounter_Main
	end

AnheimForest_Tyler_Encounter_Up::
	applymovement LOCALID_TYLER, WR5
	waitmovement 0
	goto AnheimForest_Tyler_Encounter_Main
	end

AnheimForest_Tyler_Encounter_Main::
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox AnheimForest_Text_HowsItGoing, MSGBOX_AUTOCLOSE
	delay 30
	msgbox AnheimForest_Text_DotDotDot, MSGBOX_AUTOCLOSE
	delay 10
	msgbox AnheimForest_Text_SayPlayer, MSGBOX_AUTOCLOSE
	goto_if_set FLAG_TAKEN_PIKACHU, AnheimForest_Tyler_Encounter_Eevee
	goto AnheimForest_Tyler_Encounter_Pikachu
	end

AnheimForest_Tyler_Encounter_Eevee::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto AnheimForest_Tyler_Encounter_PostMatch
	end

AnheimForest_Tyler_Encounter_Pikachu::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto AnheimForest_Tyler_Encounter_PostMatch
	end

AnheimForest_Tyler_Encounter_PostMatch::
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox AnheimForest_Text_ThatWasSomeBattle, MSGBOX_AUTOCLOSE
	applymovement LOCALID_TYLER, WU3L3U3
	waitmovement 0
	removeobject LOCALID_TYLER
	setvar VAR_STORYLINE_STATE, 15
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

WL5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WDL4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WR4UR:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

WU3L3U3:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

AnheimForest_Text_SUBO_Dots:
	.string "{COLOR}{BLUE}…$"

AnheimForest_Text_WhereDidThatBeedrill:
	.string "{COLOR}{BLUE}Where did that Beedrill go…$"

AnheimForest_Text_Sign:
	.string "Anheim Forest\n"
	.string "Please do not litter!$"

AnheimForest_Text_Sign_Town:
	.string "{UP_ARROW} Anheim Town$"

AnheimForest_Text_MotherIntro:
	.string "{COLOR}{RED}Hey! Uh…\n"
	.string "You're a Trainer, right?\p"
	.string "This is just terrible…\n"
	.string "We need you to help us…\p"
	.string "Our lovely daughter went exploring in\n"
	.string "the forest and hasn't returned…\p"
	.string "We have no Pokémon so we can't go any\n"
	.string "farther to check for ourselves…\p"
	.string "I… I hope she is OK…\p"
	.string "The last time we saw her, she was\n"
	.string "playing on the rocks by the water.\p"
	.string "Please…\n"
	.string "Will you help us find our daughter?$"

AnheimForest_Text_MotherAnswerYes:
	.string "{COLOR}{RED}Thank you so much!\p"
	.string "Please find our daughter and bring\n"
	.string "her back here safely!$"

AnheimForest_Text_MotherRecap:
	.string "{COLOR}{RED}Trainer… Please.\n"
	.string "You're our only hope…\p"
	.string "Our daughter means the world to us.\p"
	.string "She was last seen playing by the\n"
	.string "pond…\p"
	.string "Please find her and bring her back\n"
	.string "here safely!$"

AnheimForest_Text_FatherIntro:
	.string "{COLOR}{BLUE}Hey! Uh…\n"
	.string "You're a Trainer, right?\p"
	.string "This is just terrible…\n"
	.string "We need you to help us…\p"
	.string "Our lovely daughter went exploring in\n"
	.string "the forest and hasn't returned…\p"
	.string "We have no Pokémon so we can't go any\n"
	.string "farther to check for ourselves…\p"
	.string "I… I hope she is OK…\p"
	.string "The last time we saw her she was\n"
	.string "playing on the rocks by the pond.\p"
	.string "Please…\n"
	.string "Will you help us find our daughter?$"

AnheimForest_Text_FatherAnswerYes:
	.string "{COLOR}{BLUE}Thank you so much!\p"
	.string "Please find our daughter and bring\n"
	.string "her back here safely!$"

AnheimForest_Text_FatherRecap:
	.string "{COLOR}{BLUE}Please, Trainer…\n"
	.string "We are relying on you…\p"
	.string "Our daughter loves playing by the\n"
	.string "water.\p"
	.string "Please find her and offer her a\n"
	.string "stepping stone to safety!$"

AnheimForest_Text_MotherLucySaved:
	.string "{COLOR}{RED}Thank you so much for finding our\n"
	.string "daughter!\p"
	.string "She has rushed to the Pokémon Center to\n"
	.string "have her Pokémon healed…\p"
	.string "That Beedrill seemed to have shook\n"
	.string "her up quite a bit!\p"
	.string "Please take this as a token of our\n"
	.string "gratitude…$"

AnheimForest_Text_MotherRareCandy:
	.string "{COLOR}{RED}Give this to your Pokémon to toughen\n"
	.string "them up!\p"
	.string "…\p"
	.string "What's your name, by the way?\p"
	.string "…\n"
	.string "…\p"
	.string "{PLAYER}?\n"
	.string "That's a nice name!\p"
	.string "Well, {PLAYER},\n"
	.string "thank you for all of your help!\p"
	.string "We wish you the best!$"

AnheimForest_Text_FatherLucySaved:
	.string "{COLOR}{BLUE}Thank you so much for finding our\n"
	.string "daughter!\p"
	.string "She has rushed to the Pokémon Center to\n"
	.string "have her Pokémon healed…\p"
	.string "That Beedrill seemed to have shook\n"
	.string "her up quite a bit!\p"
	.string "Please take this as a token of our\n"
	.string "gratitude…$"

AnheimForest_Text_FatherRareCandy:
	.string "{COLOR}{BLUE}Give this to your Pokémon to toughen\n"
	.string "them up!\p"
	.string "…\p"
	.string "What's your name, by the way?\p"
	.string "…\n"
	.string "…\p"
	.string "{PLAYER}?\n"
	.string "That's a nice name!\p"
	.string "Well, {PLAYER},\n"
	.string "thank you for all of your help!\p"
	.string "We wish you the best!$"

AnheimForest_Text_Beedrill:
	.string "Beedrill: Bzzzr!!$"

AnheimForest_Text_Lucy:
	.string "{COLOR}{RED}Hey…\p"
	.string "…\p"
	.string "I didn't need your help, you know.\n"
	.string "I was handling just fine.$"

AnheimForest_Text_Dots:
	.string "{COLOR}{RED}… … …\n"
	.string "… … …$"

AnheimForest_Text_PleaseMove:
	.string "{COLOR}{RED}…\n"
	.string "Could you please move?$"

AnheimForest_Text_Thanks:
	.string "{COLOR}{RED}Thanks.$"

AnheimForest_Text_HmmHowDoIGetPast:
	.string "{COLOR}{BLUE}Hmm…\n"
	.string "How do I get past that tree…$"

AnheimForest_Text_Player:
	.string "{COLOR}{BLUE}{PLAYER}!$"

AnheimForest_Text_HowsItGoing:
	.string "{COLOR}{BLUE}How's it going, {PLAYER}?\n"
	.string "Long time no see!\p"
	.string "I was getting bored of all the noise in\n"
	.string "Union City and decided to find a more\l"
	.string "relaxing place to hang out and explore.\p"
	.string "I've got to say, {PLAYER},\n"
	.string "Union City seems like a shady place.\p"
	.string "I'm not sure why, but I feel like the\n"
	.string "Government is hiding stuff from us.\p"
	.string "I was even feeling weird vibes inside\n"
	.string "the Government Offices!\p"
	.string "Well, whatever they're hiding is still\n"
	.string "a mystery to me.\l"
	.string "I think, though, it is something huge!\p"
	.string "But I'm onto them, {PLAYER}!\n"
	.string "Nothing will ever stop the truth!\p"
	.string "I, Tyler The Great, will find out\n"
	.string "exactly what is going on, and I will be\l"
	.string "the one who exposes them all!$"

AnheimForest_Text_DotDotDot:
	.string "{COLOR}{BLUE}…$"

AnheimForest_Text_SayPlayer:
	.string "{COLOR}{BLUE}Say, {PLAYER}…\p"
	.string "I wonder how much stronger you have\n"
	.string "become since our last battle…\p"
	.string "Well, I guess there is only one way to\n"
	.string "find out!\l"
	.string "How about it, {PLAYER}?\n"
	.string "Prepare to lose!$"

AnheimForest_Text_ThatWasSomeBattle:
	.string "{COLOR}{BLUE}That was some battle, {PLAYER}!\n"
	.string "I definitely need to become stronger.\p"
	.string "…\p"
	.string "Anyway, I'm off to train in Route 5.\n"
	.string "I'm gonna need a stronger team.\p"
	.string "I heard there are some secrets there\n"
	.string "which people are trying to figure out.\p"
	.string "But I won't let these minor things\n"
	.string "stop me from exposing the truth!\p"
	.string "Keep your eyes peeled, {PLAYER}.\p"
	.string "See ya!$"
