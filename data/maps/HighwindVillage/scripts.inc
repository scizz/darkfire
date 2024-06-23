.set LOCALID_DAZ, 5
.set LOCALID_MUDKIP, 4

HighwindVillage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HighwindVillage_OnTransition
	.byte 0

HighwindVillage_OnTransition:
	setflag FLAG_VISITED_HIGHWIND_VILLAGE
	end

HighwindVillage_Sign::
	msgbox HighwindVillage_Text_Sign, MSGBOX_SIGN
	end

HighwindVillage_Sign_Rangers_Lodge::
	msgbox HighwindVillage_Text_Sign_Rangers_Lodge, MSGBOX_SIGN
	end

HighwindVillage_Grandma::
	msgbox HighwindVillage_Text_Grandma, MSGBOX_NPC
	end

HighwindVillage_Little_Boy::
	msgbox HighwindVillage_Text_Little_Boy, MSGBOX_NPC
	end

HighwindVillage_Daz::
	lock
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 16
	call_if_eq HighwindVillage_Daz_Left
	applymovement LOCALID_DAZ, WD5
	applymovement LOCALID_MUDKIP, WD5
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox HighwindVillage_Text_YoPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_DAZ, Common_Movement_FaceLeft
	delay 20
	applymovement LOCALID_DAZ, Common_Movement_FaceUp
	delay 20
	applymovement LOCALID_DAZ, Common_Movement_FaceRight
	delay 20
	applymovement LOCALID_DAZ, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_Text_DidYouKnow, MSGBOX_AUTOCLOSE
	hideface 1
	delay 20
	applymovement LOCALID_MUDKIP, Common_Movement_WalkDown
	applymovement LOCALID_DAZ, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_DAZ, Common_Movement_FaceDown
	waitmovement 0
	playmoncry SPECIES_MUDKIP, 0
	waitmoncry
	applymovement LOCALID_MUDKIP, Common_Movement_Heart
	playse SE_PIN
	waitse
	waitmovement 0
	delay 10
	applymovement LOCALID_DAZ, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_HAPPY, 1, 1
	msgbox HighwindVillage_Text_HahaMyMudkip, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_MUDKIP, Common_Movement_WalkUp
	applymovement LOCALID_DAZ, Common_Movement_WalkUp
	waitmovement 0
	delay 30
	emote LOCALID_DAZ, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_DAZ, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_Text_OhPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_DAZ, WD2
	applymovement LOCALID_MUDKIP, WUD
	waitmovement 0
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_Text_HereYouGo, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_LIGHT_BALL, 1
	compare VAR_RESULT, FALSE
	call_if_eq HighwindVillage_Daz_AddPCItem
	speakername CommonName_Text_Daz
	showface FS_DAZ, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_Text_MaybeYouCan, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_DAZ, WU5
	applymovement LOCALID_MUDKIP, WDD16U5
	waitmovement 0
	removeobject LOCALID_DAZ
	removeobject LOCALID_MUDKIP
	setflag FLAG_HIDE_HIGHWIND_VILLAGE_DAZ_MUDKIP
	setvar VAR_STORYLINE_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

HighwindVillage_Daz_Left::
	applymovement LOCALID_DAZ, Common_Movement_WalkLeftFaster
	waitmovement 0
	applymovement LOCALID_MUDKIP, Common_Movement_WalkLeftFaster
	waitmovement 0
	return

HighwindVillage_Daz_AddPCItem::
	addpcitem ITEM_LIGHT_BALL, 1
	return

WU5:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WDD16U5:
	walk_down
	delay_16
	delay_16
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WUD:
	walk_up
	walk_down
	step_end

HighwindVillage_Text_Sign:
	.string "Highwind Village\n"
	.string "{FONT_SMALL}“Never Too Cold for Ice Cream!”$"

HighwindVillage_Text_Sign_Rangers_Lodge:
	.string "Rangers' Federation Lodge\n"
	.string "{FONT_SMALL}Members only.$"

HighwindVillage_Text_Grandma:
	.string "This village is the quietest in all of\n"
	.string "Tenjo, I bet you.\p"
	.string "The loudest thing is the whirring of\n"
	.string "the icy wind.$"

HighwindVillage_Text_Little_Boy:
	.string "{COLOR}{BLUE}Wee! Look what I built! A snowman!\n"
	.string "He'll never melt, there's no way.$"

HighwindVillage_Text_YoPlayer:
	.string "{COLOR}{BLUE}Yo!\n"
	.string "{PLAYER}!\p"
	.string "You made it through the Tamarok\n"
	.string "Mountains?\l"
	.string "Well, we did too!$"

HighwindVillage_Text_DidYouKnow:
	.string "{COLOR}{BLUE}Did you know? This town is a\n"
	.string "stronghold of the Rangers.\p"
	.string "I was gonna visit the Rangers Lodge,\n"
	.string "but they ain't letting anybody in!\p"
	.string "But, anyway, we're not here to take in\n"
	.string "the sights. Gotta go train some more!\l"
	.string "We're not ready for you just yet!\p"
	.string "See ya'round!$"

HighwindVillage_Text_HahaMyMudkip:
	.string "{COLOR}{BLUE}Haha! My Mudkip really likes you,\n"
	.string "{PLAYER}!\p"
	.string "You must train your Pokémon with\n"
	.string "love and care!\p"
	.string "Come on, Mudkip! Let's go!$"

HighwindVillage_Text_OhPlayer:
	.string "{COLOR}{BLUE}Oh, {PLAYER}…\n"
	.string "I almost forgot!$"

HighwindVillage_Text_HereYouGo:
	.string "{COLOR}{BLUE}Here you go!$"

HighwindVillage_Text_MaybeYouCan:
	.string "{COLOR}{BLUE}Maybe you can find a use for it.\p"
	.string "Alright - we're really off!\n"
	.string "See ya!$"
