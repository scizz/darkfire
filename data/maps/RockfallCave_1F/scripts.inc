.set LOCALID_RANGER, 1

RockfallCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RockfallCave_B1F_OnFrame
	.byte 0

RockfallCave_1F_OnFrame:
	map_script_2 VAR_RANGER_EVENT_1, 2, RockfallCave_1F_RangerEvent1SetBack
	.2byte 0

RockfallCave_1F_RangerEvent1SetBack::
	setvar VAR_RANGER_EVENT_1, 1
	end

RockfallCave_1F_RangerEvent1Start::
	lockall
	emote LOCALID_RANGER, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox RockfallCave_1F_Text_HaltTrainer, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox RockfallCave_1F_Text_DotDotDot, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox RockfallCave_1F_Text_SayYouLookStrong, MSGBOX_YESNO
	hideface 0
	compare VAR_RESULT, TRUE
	goto_if_eq RockfallCave_1F_RangerEvent1StartYes
	goto RockfallCave_1F_RangerEvent1StartNo
	end

RockfallCave_1F_RangerEvent1StartYes::
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox RockfallCave_1F_Text_ExcellentIllGoAhead, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_RANGER, WD4L2D3
	waitmovement 0
	removeobject 1
	setflag FLAG_HIDE_ROCKFALL_CAVE_RANGER
	setvar VAR_RANGER_EVENT_1, 1
	releaseall
	end

RockfallCave_1F_RangerEvent1StartNo::
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox RockfallCave_1F_Text_WellThenIllStickHere, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

RockfallCave_1F_Maniac::
	msgbox RockfallCave_1F_Text_Maniac, MSGBOX_NPC
	end

RockfallCave_1F_Lass::
	msgbox RockfallCave_1F_Text_Lass, MSGBOX_NPC
	end

RockfallCave_1F_Blackbelt::
	msgbox RockfallCave_1F_Text_Blackbelt, MSGBOX_NPC
	end

RockfallCave_1F_EventScript_Dave::
	trainerbattle_single TRAINER_DAVE, RockfallCave_1F_Text_DaveIntro, RockfallCave_1F_Text_DaveDefeated
	msgbox RockfallCave_1F_Text_DavePostBattle, MSGBOX_AUTOCLOSE
	end

WD4L2D3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

RockfallCave_1F_Text_HaltTrainer:
	.string "{COLOR}{BLUE}Halt! Trainer!\n"
	.string "Danger lies past this point.\p"
	.string "An unidentified Pokémon is causing\n"
	.string "trouble in the depths of the earth.\p"
	.string "I have been sent here by the Rangers'\n"
	.string "Federation to deal with it.$"

RockfallCave_1F_Text_DotDotDot:
	.string "{COLOR}{BLUE}…\n"
	.string "…$"

RockfallCave_1F_Text_SayYouLookStrong:
	.string "{COLOR}{BLUE}Say… You look strong!\n"
	.string "Think you could lend me a hand?$"

RockfallCave_1F_Text_WellThenIllStickHere:
	.string "{COLOR}{BLUE}Well, then…\p"
	.string "I'll stick here for a while and try to\n"
	.string "gather my courage to go down there…\p"
	.string "Talk to me if you change your mind.$"

RockfallCave_1F_Text_ExcellentIllGoAhead:
	.string "{COLOR}{BLUE}Excellent!\n"
	.string "I'll go on ahead - try to catch up.$"

RockfallCave_1F_Text_Maniac:
	.string "I'm in here trying to find some rare\n"
	.string "Pokémon, but I'm having no luck…$"

RockfallCave_1F_Text_Lass:
	.string "{COLOR}{RED}That guy over there calls himself a\n"
	.string "Black Belt, but he looks like a wimp!$"

RockfallCave_1F_Text_Blackbelt:
	.string "Gah…\p"
	.string "I had to come inside this cave to get\n"
	.string "away from the flowers outside…\p"
	.string "I am allergic to pollen so every time\n"
	.string "flowers are nearby, I…\p"
	.string "I…\p"
	.string "ACHOOOO!!\p"
	.string "…\p"
	.string "Sniff.\p"
	.string "Guh…$"
