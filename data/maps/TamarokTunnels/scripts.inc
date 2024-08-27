.set LOCALID_SUBO_F, 6
.set LOCALID_SUBO_M, 7
.set LOCALID_SUBO_L, 8

TamarokTunnels_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TamarokTunnels_OnLoad
	.byte 0

TamarokTunnels_OnLoad:
	call_if_set FLAG_TAMAROK_TUNNELS_SUBO, TamarokTunnels_BlockExit
	end

TamarokTunnels_BlockExit::
	setmetatile 7, 9, 546, 1
	setmetatile 8, 9, 546, 1
	setmetatile 9, 9, 546, 1
	setmetatile 7, 10, 563, 0
	setmetatile 8, 10, 630, 1
	setmetatile 9, 10, 630, 1
	return

TamarokTunnels_EventScript_Eli::
	trainerbattle_single TRAINER_ELI, TamarokTunnels_Text_EliIntro, TamarokTunnels_Text_EliDefeated
	msgbox TamarokTunnels_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

TamarokTunnels_SUBO::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeft
	waitmovement 0
	delay 10
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WSL3
	waitmovement 0
	applymovement LOCALID_SUBO_F, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0
	msgbox TamarokTunnels_Text_HahahaGoodWork, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_TellMeAboutIt, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_F, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0
	msgbox TamarokTunnels_Text_WellWeCanTest, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement LOCALID_SUBO_F, Common_Movement_FaceLeft
	applymovement LOCALID_SUBO_M, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_SUBO_L, WUR
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_FunsOver, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_SUBO_L, Common_Movement_FaceUp
	waitmovement 0
	delay 10
	speakername SpeakerName_Text_QuestionMark
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_ThisExitHere, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_SUBO_L, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_NowAnotherScout, MSGBOX_AUTOCLOSE
	hideface 1
	emote LOCALID_SUBO_F, 8
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO_F, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername2 SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0
	msgbox TamarokTunnels_Text_PlayerTheScrawnyKid, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_SUBO_M, Common_Movement_FaceUp
	waitmovement 0
	emote LOCALID_SUBO_M, 3
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO_F, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_NoIdiot, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement LOCALID_SUBO_F, Common_Movement_FaceLeft
	applymovement LOCALID_SUBO_M, Common_Movement_FaceLeft
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_RAKAZ, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_WellWhatever, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_F, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername2 SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0
	msgbox TamarokTunnels_Text_RogerThat, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_F, WLDL2
	waitmovement 0
	applymovement LOCALID_SUBO_F, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	playse SE_CLICK
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_M, Common_Movement_FaceRight
	waitmovement 0
	emote LOCALID_SUBO_M, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO_F, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_PlayerWhatASurprise, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_M, WR2WIPSR
	applymovement OBJ_EVENT_ID_CAMERA, WSR3
	waitmovement 0
	playbgm MUS_SUBO_THEME, TRUE
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_WellItLooksLike, MSGBOX_AUTOCLOSE
	hideface 1
	trainerbattle_no_intro TRAINER_SUBO_THUG_JAMES, SuboThugJames_Text_Defeated
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_HahaSoNaive, MSGBOX_AUTOCLOSE
	hideface 1
	emote OBJ_EVENT_ID_PLAYER, 8
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox TamarokTunnels_Text_StandBackNow, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_L, WFLU
	waitmovement 0
	removeobject LOCALID_SUBO_L
	playse SE_EXIT
	applymovement LOCALID_SUBO_F, WFU2
	waitmovement 0
	removeobject LOCALID_SUBO_F
	playse SE_EXIT
	setflag FLAG_TAMAROK_TUNNELS_SUBO
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowRight
	applymovement OBJ_EVENT_ID_PLAYER, FRJSRFL
	applymovement OBJ_EVENT_ID_FOLLOWER, LFDWFR
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_M, WFL5U2FD
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, RL5FL
	applymovement OBJ_EVENT_ID_FOLLOWER, WFL5
	waitmovement 0
	applymovement LOCALID_SUBO_M, Common_Movement_FaceUp
	waitmovement 0
	removeobject LOCALID_SUBO_M
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitse
	waitmovement 0
	setmetatile 8, 9, 700, 1
	setmetatile 8, 10, 716, 1
	special DrawWholeMapView
	delay 5
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	setmetatile 7, 9, 731, 1 @ x, y, metatile id (decimal), collision
	setmetatile 8, 9, 732, 1
	setmetatile 9, 9, 733, 1
	setmetatile 7, 10, 747, 0
	setmetatile 8, 10, 748, 1
	setmetatile 9, 10, 749, 1
	setmetatile 6, 10, 630, 1
	setmetatile 8, 11, 630, 1
	setmetatile 9, 12, 630, 1
	playse SE_M_EXPLOSION
	special DrawWholeMapView
	delay 5
	setmetatile 7, 9, 763, 1
	setmetatile 8, 9, 764, 1
	setmetatile 9, 9, 765, 1
	setmetatile 7, 10, 779, 0
	setmetatile 8, 10, 780, 1
	setmetatile 9, 10, 781, 1
	special DrawWholeMapView
	delay 5
	setmetatile 7, 9, 795, 1
	setmetatile 8, 9, 796, 1
	setmetatile 9, 9, 797, 1
	setmetatile 7, 10, 811, 0
	setmetatile 8, 10, 812, 1
	setmetatile 9, 10, 813, 1
	special DrawWholeMapView
	delay 5
	setmetatile 7, 9, 546, 1
	setmetatile 8, 9, 546, 1
	setmetatile 9, 9, 546, 1
	setmetatile 7, 10, 563, 0
	setmetatile 8, 10, 630, 1
	setmetatile 9, 10, 630, 1
	special DrawWholeMapView
	setvar VAR_STORYLINE_STATE, 24
	savebgm MUS_DUMMY
	special RemoveCameraObject
	fadedefaultbgm
	release
	end

TamarokTunnels_Magby::
	lockall
	goto_if_set FLAG_RECEIVED_TAMAROK_TUNNELS_MAGBY, TamarokTunnels_Bag
	showmonpic SPECIES_MAGBY, 10, 3
	playmoncry SPECIES_MAGBY, 0
	waitmoncry
	msgbox TamarokTunnels_Text_PickMagby, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TamarokTunnels_PickMagby
	goto TamarokTunnels_HideMonPic
	end

TamarokTunnels_PickMagby::
	hidemonpic
	setvar VAR_TEMP_1, SPECIES_MAGBY
	givemon SPECIES_MAGBY, 14, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq TamarokTunnels_SendMagbyParty
	compare VAR_RESULT, 1
	goto_if_eq TamarokTunnels_SendMagbyPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

TamarokTunnels_SendMagbyParty::
	call TamarokTunnels_ReceivedMagbyFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TamarokTunnels_ReceivedMagby
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto TamarokTunnels_ReceivedMagby
	end

TamarokTunnels_SendMagbyPC::
	call TamarokTunnels_ReceivedMagbyFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TamarokTunnels_MagbyTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto TamarokTunnels_MagbyTransferredToPC
	end

TamarokTunnels_MagbyTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto TamarokTunnels_ReceivedMagby
	end

TamarokTunnels_ReceivedMagbyFanfare::
	bufferspeciesname 1, SPECIES_MAGBY
	playfanfare MUS_OBTAIN_ITEM
	message TamarokTunnels_Text_ObtainedMagby
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MAGBY
	return

TamarokTunnels_ReceivedMagby::
	setflag FLAG_RECEIVED_TAMAROK_TUNNELS_MAGBY
	releaseall
	end

TamarokTunnels_HideMonPic::
	hidemonpic
	releaseall
	end

TamarokTunnels_Bag::
	msgbox TamarokTunnels_Text_Bag, MSGBOX_AUTOCLOSE
	releaseall
	end

WUR:
	walk_up
	walk_right
	step_end

WLDL2:
	walk_left
	walk_down
	walk_left
	walk_left
	step_end

WR2WIPSR:
	walk_right
	walk_right
	walk_in_place_slow_right
	step_end

WFLU:
	walk_fast_left
	walk_fast_up
	step_end

WFU2:
	walk_fast_up
	walk_fast_up
	step_end

LFDWFR:
	follower_face_right
	walk_fast_right
	follower_face_left
	step_end

WFL5U2FD:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	face_down
	step_end

RL5FL:
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	face_left
	step_end	

WFL5:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

TamarokTunnels_Text_PickMagby:
	.string "Huh? It's a Magby!\n"
	.string "It gently whimpers in the cold.\p"
	.string "Adopt the Magby?$"

TamarokTunnels_Text_ObtainedMagby:
	.string "{PLAYER} received a Magby!$"

TamarokTunnels_Text_Bag:
	.string "The Bag is empty.$"

TamarokTunnels_Text_HahahaGoodWork:
	.string "{COLOR}{BLUE}Hahaha!\nGood work, man!\p"
	.string "We sure showed that Youngster exactly\n"
	.string "why the mighty SUBO will prevail!$"

TamarokTunnels_Text_TellMeAboutIt:
	.string "{COLOR}{BLUE}Tell me about it!\n"
	.string "Heh heh…\p"
	.string "What should we even do with the\n"
	.string "Pokémon we stole from him, anyway?$"

TamarokTunnels_Text_WellWeCanTest:
	.string "{COLOR}{BLUE}Well, we can test on it once we get a\n"
	.string "hold of the President's secret notes.\p"
	.string "I think that we will be able to make\n"
	.string "it insanely evil and powerful!$"

TamarokTunnels_Text_HmmOkay:
	.string "Hmm…\n"
	.string "Okay.$"

TamarokTunnels_Text_FunsOver:
	.string "Fun's over, fellas.\p"
	.string "It's time to get serious.\n"
	.string "Listen up, both of you.\p"
	.string "We've had two reports from our SUBO\n"
	.string "Scouts.\p"
	.string "One has reported that our prized\n"
	.string "Government Official was last seen in\l"
	.string "Northstar City.$"

TamarokTunnels_Text_ThisExitHere:
	.string "This exit here is a shortcut to the\n"
	.string "city.$"

TamarokTunnels_Text_NowAnotherScout:
	.string "Now, another Scout has confirmed that\n"
	.string "{PLAYER} is following us.$"

TamarokTunnels_Text_PlayerTheScrawnyKid:
	.string "{COLOR}{BLUE}{PLAYER}?\n"
	.string "The scrawny kid from the museum base?\p"
	.string "{PLAYER} wants to join us?$"

TamarokTunnels_Text_NoIdiot:
	.string "{COLOR}{BLUE}No, idiot! One of our guys saw the kid\n"
	.string "coming out of the Government Offices.\l"
	.string "{PLAYER} is clearly meddling!$"

TamarokTunnels_Text_WellWhatever:
	.string "Well, whatever…\p"
	.string "So we'll have to cover our tracks.\n"
	.string "No big deal!\p"
	.string "Grunt, get the goods ready.$"

TamarokTunnels_Text_RogerThat:
	.string "{COLOR}{BLUE}Roger that!$"

TamarokTunnels_Text_PlayerWhatASurprise:
	.string "{COLOR}{BLUE}{PLAYER}?\n"
	.string "What a surprise!$"

TamarokTunnels_Text_WellItLooksLike:
	.string "{COLOR}{BLUE}Well, it looks like you're pretty\n"
	.string "quick, after all…\p"
	.string "Anyway, what exactly is it with you and\n"
	.string "your obsession with us?\p"
	.string "And, by the way, we knew you were\n"
	.string "following us! You're no threat!\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Whatever, dude.\p"
	.string "If you ain't here to join us then I'll\n"
	.string "take pleasure in sending you home!$"

TamarokTunnels_Text_HahahaIGuessYou:
	.string "Hahaha! I guess you can't cope with\n"
	.string "being slowed down!$"

TamarokTunnels_Text_HahaSoNaive:
	.string "{COLOR}{BLUE}Haha…\n"
	.string "So naive…\p"
	.string "I only battled you to distract you\n"
	.string "so my pal could set the explosives!$"

TamarokTunnels_Text_StandBackNow:
	.string "{COLOR}{BLUE}Stand back, now!\n"
	.string "Or don't, if you wanna get hurt! Haha!$"
