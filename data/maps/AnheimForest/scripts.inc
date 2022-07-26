AnheimForest_MapScripts::
	.byte 0

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
