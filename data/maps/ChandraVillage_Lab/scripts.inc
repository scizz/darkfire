.set LOCALID_TYLER_LAB, 1
.set LOCALID_PROF, 3
.set LOCALID_BALL_EEVEE, 4
.set LOCALID_BALL_PIKACHU, 5
.set LOCALID_EEVEE, 6
.set LOCALID_PIKACHU, 7
.set LOCALID_RATTATA_ONE, 9
.set LOCALID_RATTATA_TWO, 8

ChandraVillage_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ChandraVillage_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChandraVillage_Lab_OnFrame
	.byte 0

ChandraVillage_Lab_OnTransition:
	call_if_set FLAG_SYS_POKEDEX_GET, ChandraVillage_Lab_ShowProf
	end

ChandraVillage_Lab_ShowProf::
	clearflag FLAG_HIDE_CHANDRA_VILLAGE_LAB_PROF
	addobject LOCALID_PROF
	return

ChandraVillage_Lab_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 5, ChandraVillage_Lab_PickPokemon
	.2byte 0

ChandraVillage_Lab_PickPokemon::
	lock
	removeobject 3
	removeobject 4
	removeobject 5
	setflag FLAG_HIDE_CHANDRA_VILLAGE_LAB_PROF
	setflag FLAG_HIDE_CHANDRA_VILLAGE_POKE_BALL_1
	setflag FLAG_HIDE_CHANDRA_VILLAGE_POKE_BALL_2
	goto_if_set FLAG_SYS_POKEMON_GET, ChandraVillage_Lab_TryAgain
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Text_ListenUp, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement 1, WU6
	applymovement OBJ_EVENT_ID_PLAYER, WU6
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_ANGRY, 1, 1
	msgbox ChandraVillage_Lab_Text_Hmm, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement 1, WL2
	waitmovement 0
	delay 30
	applymovement 1, WR4
	waitmovement 0
	delay 30
	applymovement 1, WL2
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_ANGRY, 1, 1
	msgbox ChandraVillage_Lab_Text_DoYouThink, MSGBOX_DEFAULT
	hideface 1
	giveitem ITEM_POKE_BALL, 1
	removeitem ITEM_POKE_BALL, 1
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY 1, 1
	msgbox ChandraVillage_Lab_Text_DontHoldInHand, MSGBOX_DEFAULT
	hideface 1
	setvar VAR_STORYLINE_STATE, 6
	release
	end

ChandraVillage_Lab_TryAgain::
	lock
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Lab_Text_TryAgain, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement 1, WU6
	applymovement OBJ_EVENT_ID_PLAYER, WU6
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Text_BattleThePokemon, MSGBOX_DEFAULT
	hideface 1
	setvar VAR_STORYLINE_STATE, 6
	release
	end

ChandraVillage_Lab_Pikachu::
	lockall
	showmonpic SPECIES_PIKACHU, 10, 3
	playmoncry SPECIES_PIKACHU, 0
	waitmoncry
	msgbox ChandraVillage_Lab_Pikachu_Text_PickPikachu, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_Lab_Pikachu_Yes
	hidemonpic
	msgbox ChandraVillage_Lab_Text_ChooseCarefully, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Lab_Pikachu_Yes::
	hidemonpic
	setflag FLAG_TAKEN_PIKACHU
	msgbox ChandraVillage_Lab_Pikachu_Yes_Text_ThrowPokeBall, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceSlowUp
	call ChandraVillage_Lab_Catch_Pikachu
	givemon SPECIES_PIKACHU, 5, ITEM_ORAN_BERRY
	playfanfare MUS_OBTAIN_ITEM
	msgbox ChandraVillage_Lab_Pikachu_Yes_Text_ReceivedPikachu, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	msgbox ChandraVillage_Lab_Pikachu_Yes_Text_NicknamePikachu, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_Lab_Nickname_Pikachu
	closemessage
	goto ChandraVillage_Lab_Pikachu_Caught
	end

ChandraVillage_Lab_Pikachu_Caught::
	delay 10
	applymovement LOCALID_TYLER_LAB, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, WR5
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Lab_Pikachu_Yes_Congratulations, MSGBOX_DEFAULT
	hideface 1
	closemessage
	goto ChandraVillage_Lab_Tyler_Pick_Eevee
	end

ChandraVillage_Lab_Eevee::
	lockall
	showmonpic SPECIES_EEVEE, 10, 3
	playmoncry SPECIES_EEVEE, 0
	waitmoncry
	msgbox ChandraVillage_Lab_Eevee_Text_PickEevee, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_Lab_Eevee_Yes
	hidemonpic
	msgbox ChandraVillage_Lab_Text_ChooseCarefully, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Lab_Eevee_Yes::
	hidemonpic
	msgbox ChandraVillage_Lab_Eevee_Yes_Text_ThrowPokeBall, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceSlowUp
	call ChandraVillage_Lab_Catch_Eevee
	givemon SPECIES_EEVEE, 5, ITEM_ORAN_BERRY
	playfanfare MUS_OBTAIN_ITEM
	msgbox ChandraVillage_Lab_Eevee_Yes_Text_ReceivedEevee, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	msgbox ChandraVillage_Lab_Eevee_Yes_Text_NicknameEevee, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_Lab_Nickname_Eevee
	closemessage
	goto ChandraVillage_Lab_Eevee_Caught
	end

ChandraVillage_Lab_Eevee_Caught::
	delay 10
	applymovement LOCALID_TYLER_LAB, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, WL2UL2
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Lab_Eevee_Yes_Congratulations, MSGBOX_DEFAULT
	hideface 1
	closemessage
	goto ChandraVillage_Lab_Tyler_Pick_Pikachu
	end

ChandraVillage_Lab_Nickname_Eevee::
	call Common_EventScript_NameReceivedPartyMon
	goto ChandraVillage_Lab_Eevee_Caught
	end

ChandraVillage_Lab_Nickname_Pikachu::
	call Common_EventScript_NameReceivedPartyMon
	goto ChandraVillage_Lab_Pikachu_Caught
	end

ChandraVillage_Lab_Tyler_Pick_Eevee::
	applymovement LOCALID_TYLER_LAB, WL6UL4
	applymovement OBJ_EVENT_ID_PLAYER, WDL6UL3
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	delay 30
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Tyler_Text_GoPokeBall, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowUp
	call ChandraVillage_Lab_Catch_Eevee
	playfanfare MUS_OBTAIN_ITEM
	msgbox ChandraVillage_Lab_Eevee_Yes_Text_TylerReceivedEevee, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Lab_Text_Tyler_YayCaughtEevee, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, WR2DR3
	applymovement LOCALID_TYLER_LAB, WR3DR2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	goto ChandraVillage_Lab_Tyler_End
	end

ChandraVillage_Lab_Tyler_Pick_Pikachu::
	applymovement LOCALID_TYLER_LAB, WR6DR3U
	applymovement OBJ_EVENT_ID_PLAYER, WR7DR3FU
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	delay 30
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Tyler_Text_GoPokeBall, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowUp
	call ChandraVillage_Lab_Catch_Pikachu
	playfanfare MUS_OBTAIN_ITEM
	msgbox ChandraVillage_Lab_Eevee_Yes_Text_TylerReceivedPikachu, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Lab_Text_Tyler_YayCaughtPikachu, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, WL6
	applymovement LOCALID_TYLER_LAB, WDWL5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	goto ChandraVillage_Lab_Tyler_End
	end

ChandraVillage_Lab_Tyler_End::
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Text_FightRattata, MSGBOX_DEFAULT
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_TYLER_LAB, Common_Movement_FaceDown
	waitmovement 0
	release
	end

ChandraVillage_Lab_Catch_Pikachu::
	playse SE_BALL_THROW
	waitse
	waitmovement 0
	delay 10
	clearflag FLAG_HIDE_CHANDRA_VILLAGE_POKE_BALL_2
	addobject LOCALID_BALL_PIKACHU
	removeobject LOCALID_PIKACHU
	setflag FLAG_HIDE_CHANDRA_VILLAGE_PIKACHU
	applymovement LOCALID_BALL_PIKACHU, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_2
	waitse
	applymovement LOCALID_BALL_PIKACHU, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_3
	waitse
	applymovement LOCALID_BALL_PIKACHU, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_4
	waitse
	delay 60
	removeobject LOCALID_BALL_PIKACHU
	return

ChandraVillage_Lab_Catch_Eevee::
	playse SE_BALL_THROW
	waitse
	waitmovement 0
	delay 10
	clearflag FLAG_HIDE_CHANDRA_VILLAGE_POKE_BALL_1
	addobject LOCALID_BALL_EEVEE
	removeobject LOCALID_EEVEE
	setflag FLAG_HIDE_CHANDRA_VILLAGE_EEVEE
	applymovement LOCALID_BALL_EEVEE, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_2
	waitse
	applymovement LOCALID_BALL_EEVEE, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_3
	waitse
	applymovement LOCALID_BALL_EEVEE, BallBounce
	waitmovement 0
	playse SE_BALL_BOUNCE_4
	waitse
	delay 60
	removeobject LOCALID_BALL_EEVEE
	return

ChandraVillage_Lab_Aide::
	goto_if_set FLAG_SYS_POKEDEX_GET, ChandraVillage_Lab_Aide_Dex
	msgbox ChandraVillage_Lab_Text_Aide, MSGBOX_NPC
	end

ChandraVillage_Lab_Aide_Dex::
	msgbox ChandraVillage_Lab_Text_Aide_Dex, MSGBOX_NPC
	end

ChandraVillage_Lab_Rattata1::
	lock
	faceplayer
	playmoncry SPECIES_RATTATA, 0
	msgbox ChandraVillage_Lab_Text_Rattata, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_RATTATA, 2, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_RATTATA, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_RATTATA_ONE
	setflag FLAG_HIDE_CHANDRA_VILLAGE_LAB_RATTATA_1
	fadescreen 0
	release
	end

ChandraVillage_Lab_Rattata2::
	lock
	faceplayer
	playmoncry SPECIES_RATTATA, 0
	msgbox ChandraVillage_Lab_Text_Rattata, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_RATTATA, 3, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_RATTATA, 1
	waitmoncry
	fadescreen 1
	delay 60
	removeobject LOCALID_RATTATA_TWO
	setflag FLAG_HIDE_CHANDRA_VILLAGE_LAB_RATTATA_2
	fadescreen 0
	release
	end

ChandraVillage_Lab_Tyler::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEMON_GET, ChandraVillage_Lab_PickOne
	goto_if_unset FLAG_HIDE_CHANDRA_VILLAGE_LAB_RATTATA_1, ChandraVillage_Lab_Tyler_NotDone
	goto_if_unset FLAG_HIDE_CHANDRA_VILLAGE_LAB_RATTATA_2, ChandraVillage_Lab_Tyler_NotDone
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Lab_Text_GoodJob, MSGBOX_DEFAULT
	closemessage
	hideface 1
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 6
	call_if_eq ChandraVillage_Standing_Under
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_TYLER_LAB, WD7
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_TYLER_LAB
	setflag FLAG_HIDE_CHANDRA_VILLAGE_LAB_TYLER
	setvar VAR_STORYLINE_STATE, 7
	release
	end

ChandraVillage_Standing_Under::
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkRight
	waitmovement 0
	return

ChandraVillage_Lab_PickOne::
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Text_PickOne, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

ChandraVillage_Lab_Tyler_NotDone::
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Text_NotDone, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_TYLER_LAB, Common_Movement_FaceDown
	waitmovement 0
	release
	end

ChandraVillage_Lab_Exit::
	lock
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_SURPRISED, 1, 1
	msgbox ChandraVillage_Lab_Text_ComeBack, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	end

ChandraVillage_Lab_Prof::
	speakername CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Lab_Text_Prof, MSGBOX_AUTOCLOSE
	hideface 1
	end

WU6:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WL2:
	walk_left
	walk_left
	step_end

WR4:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WL2UL2:
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	step_end

WR5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WL6UL4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WDL6UL3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

WR6DR3U:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

WR7DR3FU:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

WR2DR3:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

WR3DR2:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	step_end

WL6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WDWL5:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WD7:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ChandraVillage_Lab_Text_ListenUp:
	.string "{COLOR}{BLUE}OK, {PLAYER}, listen up!\p"
	.string "Professor Hawthorne left a couple of\n"
	.string "Pokémon at the back of the Lab.\p"
	.string "They look pretty tame to me.\n"
	.string "Let's go check them out!$"

ChandraVillage_Lab_Text_Hmm:
	.string "{COLOR}{BLUE}Hmm…$"

ChandraVillage_Lab_Text_DoYouThink:
	.string "{COLOR}{BLUE}Do you think these Pokémon want to sit\n"
	.string "around an old man all day, watching\l"
	.string "him while he writes boring lab notes?\p"
	.string "Tch… Mom once made me spend time\n"
	.string "with Professor Hawthorne.\l"
	.string "I'd rather watch paint dry!\p"
	.string "The old man does nothing all day\n"
	.string "except fiddle with his Pokédex.\p"
	.string "A Pokédex won't save you from Rattata,\n"
	.string "{PLAYER}, a Pokemon will!\p"
	.string "Here, take one of these Poké Balls…$"

ChandraVillage_Lab_Text_DontHoldInHand:
	.string "{COLOR}{BLUE}No! Don't put it in your Bag!\n"
	.string "Take it out and hold it in your hand.\p"
	.string "We're going to catch these Pokémon\n"
	.string "and help get rid of this infestation!\p"
	.string "Be careful, though, {PLAYER}…\n"
	.string "I only have two Poké Balls left…\l"
	.string "We can't be careless with this.\p"
	.string "What's more is this is the only\n"
	.string "chance the Professor will give us to\l"
	.string "prove we can be Pokémon Trainers!\p"
	.string "My advice is to creep up slowly and\n"
	.string "try not to spook them.\p"
	.string "Pick a Pokémon, {PLAYER}!$"

ChandraVillage_Lab_Text_TryAgain:
	.string "{COLOR}{BLUE}It's OK, {PLAYER}…\n"
	.string "Let's try this again!$"

ChandraVillage_Lab_Text_BattleThePokemon:
	.string "{COLOR}{BLUE}Battle the Pokémon and show me what\n"
	.string "you're made of!$"

ChandraVillage_Lab_Eevee_Text_PickEevee:
	.string "Do you want the Normal Evolution\n"
	.string "Pokémon, Eevee?$"

ChandraVillage_Lab_Pikachu_Text_PickPikachu:
	.string "Do you want the Electric Mouse\n"
	.string "Pokémon, Pikachu?$"

ChandraVillage_Lab_Text_ChooseCarefully:
	.string "Take your time choosing a Pokémon.\n"
	.string "Your first Pokémon is important.$"

ChandraVillage_Lab_Eevee_Yes_Text_ThrowPokeBall:
	.string "{PLAYER} threw a Poké Ball at Eevee.$"

ChandraVillage_Lab_Pikachu_Yes_Text_ThrowPokeBall:
	.string "{PLAYER} threw a Poké Ball at Pikachu.$"

ChandraVillage_Lab_Eevee_Yes_Text_ReceivedEevee:
	.string "Gotcha!\n"
	.string "{PLAYER} caught Eevee!$"

ChandraVillage_Lab_Pikachu_Yes_Text_ReceivedPikachu:
	.string "Gotcha!\n"
	.string "{PLAYER} caught Pikachu!$"

ChandraVillage_Lab_Eevee_Yes_Text_NicknameEevee:
	.string "Would you like to give a nickname to\n"
	.string "Eevee?$"

ChandraVillage_Lab_Pikachu_Yes_Text_NicknamePikachu:
	.string "Would you like to give a nickname to\n"
	.string "Pikachu?$"

ChandraVillage_Lab_Eevee_Yes_Congratulations:
	.string "{COLOR}{BLUE}Good job, {PLAYER}!\n"
	.string "Eevee is a great choice!\p"
	.string "OK… That only leaves Pikachu to catch…\n"
	.string "Come on, {PLAYER}!$"

ChandraVillage_Lab_Pikachu_Yes_Congratulations:
	.string "{COLOR}{BLUE}Good job, {PLAYER}!\n"
	.string "Pikachu is a great choice!\p"
	.string "OK… That only leaves Eevee to catch…\n"
	.string "Come on, {PLAYER}!$"

ChandraVillage_Lab_Tyler_Text_GoPokeBall:
	.string "{COLOR}{BLUE}Go! Poke Ball!\n"
	.string "Do your thing!$"

ChandraVillage_Lab_Eevee_Yes_Text_TylerReceivedPikachu:
	.string "Tyler caught Pikachu!$"

ChandraVillage_Lab_Eevee_Yes_Text_TylerReceivedEevee:
	.string "Tyler caught Eevee!$"

ChandraVillage_Lab_Text_Tyler_YayCaughtEevee:
	.string "{COLOR}{BLUE}We did it, {PLAYER}!\n"
	.string "I caught an Eevee!\p"
	.string "OK, let's go check out the Rattata…\n"
	.string "Lead the way!$"

ChandraVillage_Lab_Text_Tyler_YayCaughtPikachu:
	.string "{COLOR}{BLUE}We did it, {PLAYER}!\n"
	.string "I caught a Pikachu!\p"
	.string "OK, let's go check out the Rattata…\n"
	.string "Lead the way!$"

ChandraVillage_Lab_Text_FightRattata:
	.string "{COLOR}{BLUE}Say, {PLAYER}…\n"
	.string "Let me watch you in battle.\p"
	.string "Now you've got a Pokémon, these\n"
	.string "Rattata shouldn't be a problem!\p"
	.string "…\n"
	.string "OK! Tell ya what!\p"
	.string "If you can get rid of them, I'll\n"
	.string "battle you myself, OK?\p"
	.string "Haha! Show me what you got,\n"
	.string "{PLAYER}!$"

ChandraVillage_Lab_Text_Aide:
	.string "Pfft…\p"
	.string "The Professor is such a wimp.\n"
	.string "These Rattata won't distract me!$"

ChandraVillage_Lab_Text_Aide_Dex:
	.string "You saved the Professor from Rattata?\n"
	.string "OK? You want a medal? He's a wimp.$"

ChandraVillage_Lab_Text_Rattata:
	.string "Grraat!$"

ChandraVillage_Lab_Text_PickOne:
	.string "{COLOR}{BLUE}Come on, {PLAYER}!\n"
	.string "Pick a Pokémon to fight with!$"

ChandraVillage_Lab_Text_NotDone:
	.string "{COLOR}{BLUE}Let's go, {PLAYER}!\n"
	.string "You got this! Defeat the Rattata!$"

ChandraVillage_Lab_Text_GoodJob:
	.string "{COLOR}{BLUE}Good job, {PLAYER}!\n"
	.string "It looks like you know how to battle!\p"
	.string "Let's go and tell Professor Hawthorne\n"
	.string "the infestation has been handled…\p"
	.string "Meet me at my house afterwards and\n"
	.string "we can talk about our battle!$"

ChandraVillage_Lab_Text_ComeBack:
	.string "{COLOR}{BLUE}Come back, {PLAYER}!$"

ChandraVillage_Lab_Text_Prof:
	.string "Hi, {PLAYER}.\n"
	.string "Thanks again for saving the Lab.\p"
	.string "I hope the Pokémon and Pokédex I gave\n"
	.string "you helps you in your journey.$"
