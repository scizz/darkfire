.set LOCALID_SUBO_PUSH, 10
.set LOCALID_SUBO_F, 11
.set LOCALID_SUBO_L, 12
.set LOCALID_SUBO_M, 13
.set LOCALID_NERD, 14
.set LOCALID_PRESIDENT, 15
.set LOCALID_RATTATA, 16
.set LOCALID_POKE_BALL, 17

UnionCity_AbandonedMuseum_MapScripts::
	.byte 0

UnionCity_SUBO_Event::
	lock
	removeobject LOCALID_POKE_BALL
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 33
	goto_if_eq UnionCity_SUBO_Event_Left
	goto UnionCity_SUBO_Event_Right
	end

UnionCity_SUBO_Event_Left::
	applymovement LOCALID_NERD, WFU5
	waitmovement 0
	speakername SpeakerName_Text_RandomNerd
	msgbox UnionCity_AbandonedMuseum_Text_GetOut, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, WFRFL
	applymovement OBJ_EVENT_ID_FOLLOWER, WFRFFL
	waitmovement 0
	goto UnionCity_SUBO_QuestionMark
	end

UnionCity_SUBO_Event_Right::
	applymovement LOCALID_NERD, WFU6
	waitmovement 0
	applymovement LOCALID_NERD, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement 0
	msgbox UnionCity_AbandonedMuseum_Text_GetOut, MSGBOX_AUTOCLOSE
	goto UnionCity_SUBO_QuestionMark
	end

UnionCity_SUBO_QuestionMark::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	applymovement LOCALID_NERD, WFU4L7
	waitse
	waitmovement 0
	goto UnionCity_SUBO_Event_Push
	end

UnionCity_SUBO_Event_Push::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_FOLLOWER, WLD
	waitmovement 0
	applymovement LOCALID_SUBO_PUSH, WFD3R3D2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PushBack
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, FFRX
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, WFRFU
	waitmovement 0
	applymovement LOCALID_SUBO_PUSH, Common_Movement_FaceDown
	waitmovement 0
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox UnionCity_AbandonedMuseum_Text_WellWellWell, MSGBOX_AUTOCLOSE
	hideface 1
	goto UnionCity_SUBO_Event_Main
	end

UnionCity_SUBO_Event_Main::
	applymovement OBJ_EVENT_ID_PLAYER, WDLD
	applymovement OBJ_EVENT_ID_FOLLOWER, WDDLFFD
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WD3
	waitmovement 0
	special RemoveCameraObject
	delay 30
	applymovement LOCALID_SUBO_L, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_RattataUseTackle, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	playmoncry SPECIES_RATTATA, 0
	speakername SpeakerName_Text_Rattata
	msgbox UnionCity_AbandonedMuseum_Text_Grrat, MSGBOX_AUTOCLOSE
	waitmoncry
	applymovement LOCALID_RATTATA, JumpRightLeft
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 1, 1
	msgbox UnionCity_AbandonedMuseum_Text_Waahhh, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_SUBO_M, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_IllTellYouWhat, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 1, 1
	msgbox UnionCity_AbandonedMuseum_Text_IReallyCant, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_TchRattata, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	playmoncry SPECIES_RATTATA, 0
	speakername SpeakerName_Text_Rattata
	msgbox UnionCity_AbandonedMuseum_Text_Grratata, MSGBOX_AUTOCLOSE
	waitmoncry
	applymovement LOCALID_RATTATA, JumpRightLeft
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 1, 1
	msgbox UnionCity_AbandonedMuseum_Text_WaahhhOkay, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_ThereWasntSoHard, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	delay 10
	playse SE_PIN
	waitse
	delay 10
	removeobject LOCALID_RATTATA
	clearflag FLAG_HIDE_ABANDONED_MUSEUM_POKE_BALL
	addobject LOCALID_POKE_BALL
	applymovement LOCALID_POKE_BALL, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_POKE_BALL, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_POKE_BALL, JumpInPlace
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	playse SE_PIN
	removeobject LOCALID_POKE_BALL
	waitse
	waitmovement 0
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_SpitItOut, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 1, 1
	msgbox UnionCity_AbandonedMuseum_Text_UhHmh, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_PRESIDENT, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_HmmNorthOfAnheim, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_FaceUp
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_OhItSeemsWeHave, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_SUBO_F, Common_Movement_FaceUp
	applymovement LOCALID_PRESIDENT, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_SUBO_M, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_PlayerRight, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_HehDontFeelAlarmed, MSGBOX_AUTOCLOSE
	hideface 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WU3
	applymovement LOCALID_SUBO_L, WU3
	waitmovement 0
	special RemoveCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	playbgm MUS_SUBO_THEME, TRUE
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_InFactIveBeenWatching, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_DotDotDot, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	speakername SpeakerName_Text_QuestionMark
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_AnywayHereWeAre, MSGBOX_AUTOCLOSE
	hideface 0
	delay 10
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	speakername SpeakerName_Text_SuboLeader
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_AndMrPresident, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_SUBO_L, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername SpeakerName_Text_SuboLeader
	showface FS_ZAGAN, FSE_NORMAL, 0, 0
	msgbox UnionCity_AbandonedMuseum_Text_KeepItUp, MSGBOX_AUTOCLOSE
	hideface 0
	fadescreen 1
	removeobject LOCALID_SUBO_F
	removeobject LOCALID_SUBO_M
	removeobject LOCALID_SUBO_L
	removeobject LOCALID_SUBO_PUSH
	removeobject 9
	removeobject 18
	removeobject 8
	removeobject 7
	removeobject 6
	removeobject 5
	removeobject 4
	delay 60
	fadescreen 0
	delay 30
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement LOCALID_PRESIDENT, WU2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	speakername CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 1, 1
	msgbox UnionCity_AbandonedMuseum_Text_WhatWasThat, MSGBOX_AUTOCLOSE
	hideface 1
	setvar VAR_STORYLINE_STATE, 14
	warpsilent MAP_UNION_CITY_GOV_OFFICE_3F, 2, 2
	end

UnionCity_AbandonedMuseum_Old_Man::
	msgbox UnionCity_AbandonedMuseum_Text_Old_Man, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Girl::
	goto_if_set FLAG_ABANDONED_MUSEUM_COMPLETE, UnionCity_AbandonedMuseum_Girl_Complete
	msgbox UnionCity_AbandonedMuseum_Text_Girl, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Girl_Complete::
	msgbox UnionCity_AbandonedMuseum_Text_Girl_Complete, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Little_Girl::
	goto_if_set FLAG_ABANDONED_MUSEUM_COMPLETE, UnionCity_AbandonedMuseum_Little_Girl_Complete
	msgbox UnionCity_AbandonedMuseum_Text_Little_Girl, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Little_Girl_Complete::
	msgbox UnionCity_AbandonedMuseum_Text_Little_Girl_Complete, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_RelicanthFossil::
	msgbox UnionCity_AbandonedMuseum_Text_RelicanthFossil, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_GoldenMagikarpScales::
	msgbox UnionCity_AbandonedMuseum_Text_GoldenMagikarpScales, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientPokeBallShard::
	msgbox UnionCity_AbandonedMuseum_Text_AncientPokeBallShard, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_EeveeEvolutionStones::
	msgbox UnionCity_AbandonedMuseum_Text_EeveeEvolutionStones, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_PikachusElectricRod::
	msgbox UnionCity_AbandonedMuseum_Text_PikachusElectricRod, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientUnownTablet::
	msgbox UnionCity_AbandonedMuseum_Text_AncientUnownTablet, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_DragonitesWeatheredMailBag::
	msgbox UnionCity_AbandonedMuseum_Text_DragonitesWeatheredMailBag, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_RegirocksEnigmaticKeystone::
	msgbox UnionCity_AbandonedMuseum_Text_RegirocksEnigmaticKeystone, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientSpindaPatternedPottery::
	msgbox UnionCity_AbandonedMuseum_Text_AncientSpindaPatternedPottery, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_LatiasLatiosTwinFeathers::
	msgbox UnionCity_AbandonedMuseum_Text_LatiasLatiosTwinFeathers, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientIcyRockRegice::
	msgbox UnionCity_AbandonedMuseum_Text_AncientIcyRockRegice, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientGengarShadowRelic::
	msgbox UnionCity_AbandonedMuseum_Text_AncientGengarShadowRelic, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientSkyPillarScroll::
	msgbox UnionCity_AbandonedMuseum_Text_AncientSkyPillarScroll, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientArmaldoFossilizedClaw::
	msgbox UnionCity_AbandonedMuseum_Text_AncientArmaldoFossilizedClaw, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_FossilizedLileepBlossom::
	msgbox UnionCity_AbandonedMuseum_Text_FossilizedLileepBlossom, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_ReconstructedAerodactylExhibit::
	msgbox UnionCity_AbandonedMuseum_Text_ReconstructedAerodactylExhibit, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_TheUnidentifiedPokemon::
	msgbox UnionCity_AbandonedMuseum_Text_TheUnidentifiedPokemon, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_MetagrossCoreCrystal::
	msgbox UnionCity_AbandonedMuseum_Text_MetagrossCoreCrystal, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_AncientOmanyteShell::
	msgbox UnionCity_AbandonedMuseum_Text_AncientOmanyteShell, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_KabutoFossil::
	msgbox UnionCity_AbandonedMuseum_Text_KabutoFossil, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_HoOhRainbowFeather::
	msgbox UnionCity_AbandonedMuseum_Text_HoOhRainbowFeather, MSGBOX_NPC
	end


WFU5:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WFRFL:
	walk_fast_right
	face_left
	step_end

WFRFFL:
	walk_fast_right
	follower_face_left
	step_end

WFU6:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

WFU4L7:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

WLD:
	walk_left
	walk_down
	step_end

WFD3R3D2:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	step_end

PushBack:
	jump_special_down
	step_end

FFRX:
	follower_face_right
	emote_exclamation_mark
	step_end

WFRFU:
	walk_fast_right
	follower_face_up
	step_end

WDLD:
	walk_down
	walk_left
	walk_down
	step_end

WDDLFFD:
	walk_down
	walk_down
	walk_left
	follower_face_down
	step_end

WD3:
	walk_down
	walk_down
	walk_down
	step_end

JumpRightLeft:
	jump_special_right
	lock_facing_direction
	jump_special_left
	unlock_facing_direction
	step_end

JumpInPlace:
	jump_in_place_left
	step_end

WU3:
	walk_up
	walk_up
	walk_up
	step_end

SpeakerName_Text_SuboGrunt:
	.string "SUBO Grunt$"

SpeakerName_Text_SuboLeader:
	.string "SUBO Leader$"

SpeakerName_Text_QuestionMark:
	.string "???$"

SpeakerName_Text_RandomNerd:
	.string "Random Nerd$"

SpeakerName_Text_Rattata:
	.string "Rattata$"

UnionCity_AbandonedMuseum_Text_Old_Man:
	.string "This museum was recently abandoned.\p"
	.string "It seems like nobody is interested in\n"
	.string "history anymore…\p"
	.string "At least the statues have not yet been\n"
	.string "destroyed so I can still examine them\l"
	.string "from time to time.$"

UnionCity_AbandonedMuseum_Text_Girl:
	.string "{COLOR}{RED}The old floor creaks and the shattered\n"
	.string "glass submits beneath my boots.\p"
	.string "There is nothing quite like the eerie\n"
	.string "feeling of an abandoned building.\p"
	.string "Not only that, but I often hear noises\n"
	.string "coming from the basement.\p"
	.string "If only I could find a way down there\n"
	.string "so I could investigate…$"

UnionCity_AbandonedMuseum_Text_Girl_Complete:
	.string "{COLOR}{RED}I heard somebody found their way down\n"
	.string "into the basement of this museum.\p"
	.string "I'm not too sure what unfolded down\n"
	.string "there, but I heard it was ugly.$"

UnionCity_AbandonedMuseum_Text_Little_Girl:
	.string "{COLOR}{RED}I don't know why my grandpa brought me\n"
	.string "to this place - it's scary!\p"
	.string "I heard strange noises coming from\n"
	.string "underground!$"

UnionCity_AbandonedMuseum_Text_Little_Girl_Complete:
	.string "{COLOR}{RED}My grandpa saw some bad guys fleeing\n"
	.string "from the city.\p"
	.string "I heard they were doing mean things in\n"
	.string "the basement of this museum!$"

UnionCity_AbandonedMuseum_Text_GetOut:
	.string "{COLOR}{BLUE}Get out! Get out!\n"
	.string "They're evil! They're monsters!$"

UnionCity_AbandonedMuseum_Text_WellWellWell:
	.string "{COLOR}{RED}Well, well, well…\n"
	.string "What do you think you're doing, punk?\p"
	.string "I think it's best for you to go and\n"
	.string "tell the boss exactly why you're here!$"

UnionCity_AbandonedMuseum_Text_RattataUseTackle:
	.string "{COLOR}{BLUE}Rattata!\n"
	.string "Use Tackle, now!$"

UnionCity_AbandonedMuseum_Text_Grrat:
	.string "{COLOR}{RED}Rattata: Grrat!$"

UnionCity_AbandonedMuseum_Text_Waahhh:
	.string "President: Waahhh!\n"
	.string "Please, make it stop!$"

UnionCity_AbandonedMuseum_Text_IllTellYouWhat:
	.string "{COLOR}{BLUE}I'll tell you what, Mr. President…\p"
	.string "I'll make it stop when you give us\n"
	.string "your classified research notes!$"

UnionCity_AbandonedMuseum_Text_IReallyCant:
	.string "President: I-I can't!\n"
	.string "I really can't!\p"
	.string "If these notes get into the wrong\n"
	.string "hands, Pokémon could enslave us all!$"

UnionCity_AbandonedMuseum_Text_TchRattata:
	.string "{COLOR}{BLUE}Tch…\n"
	.string "Rattata, use Super Fang!$"

UnionCity_AbandonedMuseum_Text_Grratata:
	.string "{COLOR}{RED}Rattata: Grratata!!$"

UnionCity_AbandonedMuseum_Text_WaahhhOkay:
	.string "President: WAAHHH!\n"
	.string "Okay! Okay! Just make it stop!$"

UnionCity_AbandonedMuseum_Text_ThereWasntSoHard:
	.string "{COLOR}{BLUE}There… Wasn't so hard now, was it?\n"
	.string "Rattata! Return!$"

UnionCity_AbandonedMuseum_Text_SpitItOut:
	.string "{COLOR}{BLUE}Spit it out, idiot!$"

UnionCity_AbandonedMuseum_Text_UhHmh:
	.string "President: …\n"
	.string "Uh… Hmh…\p"
	.string "There is a Government Official north\n"
	.string "of Anheim Forest.\p"
	.string "He has all the documents you are\n"
	.string "looking for…$"

UnionCity_AbandonedMuseum_Text_HmmNorthOfAnheim:
	.string "{COLOR}{BLUE}Hmm… North of Anheim Forest…\p"
	.string "In that case we will clear the bridge\n"
	.string "of Spinirak that are blocking the way.$"

UnionCity_AbandonedMuseum_Text_OhItSeemsWeHave:
	.string "{COLOR}{BLUE}Oh…\n"
	.string "It seems we have a spectator…$"

UnionCity_AbandonedMuseum_Text_PlayerRight:
	.string "{COLOR}{BLUE}{PLAYER}, right?$"

UnionCity_AbandonedMuseum_Text_HehDontFeelAlarmed:
	.string "{COLOR}{BLUE}Hah, don't feel alarmed, I have eyes\n"
	.string "in every dark corner of this region.$"

UnionCity_AbandonedMuseum_Text_InFactIveBeenWatching:
	.string "{COLOR}{BLUE}In fact, I've been watching you battle\n"
	.string "for a while, {PLAYER}.\p"
	.string "Do you really think you managed to get\n"
	.string "here without alerting any of my men?\p"
	.string "Wrong.\pI purposely told my colleague here to\n"
	.string "alert you in Anheim Forest so you\l"
	.string "could find us in here.$"

UnionCity_AbandonedMuseum_Text_DotDotDot:
	.string "{COLOR}{BLUE}…\n"
	.string "…$"

UnionCity_AbandonedMuseum_Text_AnywayHereWeAre:
	.string "{COLOR}{BLUE}Anyway, here we are.\n"
	.string "Welcome to the SUBO territory.\p"
	.string "Your battling talents are quite\n"
	.string "extraordinary, {PLAYER}.\p"
	.string "In all honesty, with those skills you\n"
	.string "could fit right in with the SUBO.\p"
	.string "What is it that you desire most?\n"
	.string "Power? Fame? Riches?\p"
	.string "I can provide all of that to you.\p"
	.string "… Oh?\n"
	.string "Who am I?\p"
	.string "The Leader.\p"
	.string "The Grand Chief of the infamous and\n"
	.string "everlasting SUBO.\p"
	.string "The SUBO part? Secret Underground\n"
	.string "Battling Organization.\l"
	.string "We're the talk of the town right now.\p"
	.string "Sounds scary?\n"
	.string "It's not supposed to.\p"
	.string "We're just a group of like-minded\n"
	.string "people whose activities do not fit\l"
	.string "into the cynical, man-made paradigm\l"
	.string "of modern morals and empathy.\p"
	.string "Why? Because morals and empathy are\n"
	.string "signs of the weak.\p"
	.string "All throughout history, the weak have\n"
	.string "always perished, and only the strong\l"
	.string "have survived.\p"
	.string "The lion eats the deer.\p"
	.string "The deer eats the bird.\p"
	.string "The bird eats the worm.\p"
	.string "Tenjo politicians like to refer to\n"
	.string "themselves as “roaring lions”,\l"
	.string "yet we devour lions.\p"
	.string "We will control the minds of the people\n"
	.string "and use them all as our tools!$"

UnionCity_AbandonedMuseum_Text_AndMrPresident:
	.string "{COLOR}{BLUE}…and Mr. President here will help us\n"
	.string "do just that.$"

UnionCity_AbandonedMuseum_Text_KeepItUp:
	.string "{COLOR}{BLUE}Keep it up, {PLAYER}.\n"
	.string "We'll be watching you.$"

UnionCity_AbandonedMuseum_Text_WhatWasThat:
	.string "President: W-what was that?\n"
	.string "Oh, no, the region is in turmoil!\p"
	.string "How will I ever show my face to the\n"
	.string "innocent people of Tenjo again?\p"
	.string "What's worse, the group are on their\n"
	.string "way to steal my classified notes!\p"
	.string "Once they get a hold of those, hell\n"
	.string "itself will manifest before our eyes!\p"
	.string "Quickly, please come with me back to\n"
	.string "my office.$"

UnionCity_AbandonedMuseum_Text_RelicanthFossil:
	.string "“Ancient Relicanth Fossil”\p"
	.string "Preserved within a sturdy glass case,\n"
	.string "this relic hails from the distant past\l"
	.string "of the Pokémon world, encapsulating\l"
	.string "the soul of an early aquatic Pokémon.$"

UnionCity_AbandonedMuseum_Text_GoldenMagikarpScales:
	.string "“Golden Margikarp Scales”\p"
	.string "Encased in a shimmering display, these\n"
	.string "golden scales are rumored to have\l"
	.string "belonged to a legendary Magikarp that\l"
	.string "achieved greatness by transforming\l"
	.string "into the majestic Gyarados.\p"
	.string "The scales gleam with a lustrous\n"
	.string "sheen, symbolizing the potential for\l"
	.string "greatness hidden within seemingly\l"
	.string "ordinary Pokémon.$"

UnionCity_AbandonedMuseum_Text_AncientPokeBallShard:
	.string "“Ancient Poké Ball Shard”\p"
	.string "This weathered fragment of a Poké Ball\n"
	.string "dates back to the earliest days of\l"
	.string "Pokémon training.\p"
	.string "The faded red and white coloration hint\n"
	.string "at its age, and it serves as a\l"
	.string "testament to the ingenuity of early\l"
	.string "Trainers who developed these iconic\l"
	.string "devices to catch and befriend Pokémon.$"

UnionCity_AbandonedMuseum_Text_EeveeEvolutionStones:
	.string "“Eevee Evolution Stones”\p"
	.string "A set of shimmering Evolution Stones,\n"
	.string "each associated with a specific Eevee\l"
	.string "evolution.\p"
	.string "From the fiery glow of the Fire Stone\n"
	.string "to the calm aura of the Water Stone,\l"
	.string "these artifacts showcase the diverse\l"
	.string "paths Eevee can take on its journey.$"

UnionCity_AbandonedMuseum_Text_PikachusElectricRod:
	.string "“Pikachu's First Electric Rod”\p"
	.string "A relic from Pikachu's early days,\n"
	.string "the weathered electric rod is believed\l"
	.string "to be one of the first tools used by\l"
	.string "Pikachu to harness its electric powers.\p"
	.string "The scorch marks and worn grip tell\n"
	.string "the story of Pikachu's determination\l"
	.string "and growth as an Electric-type Pokémon.$"

UnionCity_AbandonedMuseum_Text_AncientUnownTablet:
	.string "“Ancient Unown Tablet”\p"
	.string "A tablet adorned with Unown script,\n"
	.string "this artifact is believed to have been\l"
	.string "part of an ancient Pokémon temple.\p"
	.string "The mystical inscriptions spark\n"
	.string "curiosity among researchers, hinting\l"
	.string "at a connection between Unown and the\l"
	.string "spiritual beliefs of civilization.$"

UnionCity_AbandonedMuseum_Text_DragonitesWeatheredMailBag:
	.string "“Dragonite's Weathered Mail Bag”\p"
	.string "This tattered mail bag is believed to\n"
	.string "have been carried by a loyal Dragonite\l"
	.string "on long-distance delivery routes.\p"
	.string "The faded patches and worn straps tell\n"
	.string "the story of a Pokémon committed to\l"
	.string "delivering messages across the vast\l"
	.string "Pokémon world.$"

UnionCity_AbandonedMuseum_Text_RegirocksEnigmaticKeystone:
	.string "“Regirock's Enigmatic Keystone”\p"
	.string "Encased in a protective barrier, this\n"
	.string "engraved stone is thought to belong\l"
	.string "to the Legendary Pokémon Regirock\l"
	.string "to unlock its formidable power.\p"
	.string "The inscriptions suggest a connection\n"
	.string "to ancient rituals of the archaic trio.$"

UnionCity_AbandonedMuseum_Text_AncientSpindaPatternedPottery:
	.string "“Ancient Spinda Patterned Pottery”\p"
	.string "A colorful pottery piece adorned with\n"
	.string "intricate patterns reminiscent of\l"
	.string "Spinda's unique spot formations.\p"
	.string "This artifact is believed to have\n"
	.string "been used in ancient Spinda-inspired\l"
	.string "celebrations, where the chaotic beauty\l"
	.string "of each pot was celebrated.$"

UnionCity_AbandonedMuseum_Text_LatiasLatiosTwinFeathers:
	.string "“Latias and Latios' Twin Feathers”\p"
	.string "Twin feathers, one red and one blue,\n"
	.string "understood to have belonged to the\l"
	.string "Eon Duo, Latias and Latios.\p"
	.string "The feathers are carefully displayed\n"
	.string "to symbolize the harmonious balance\l"
	.string "between these Legendary Pokémon as\l"
	.string "they soared across the skies.$"

UnionCity_AbandonedMuseum_Text_AncientIcyRockRegice:
	.string "“Ancient Icy Rock of Regice”\p"
	.string "A frost-covered rock believed to belong\n"
	.string "to the Legendary Pokémon Regice.\p"
	.string "The perpetual chill emanating from the\n"
	.string "rock tells of the ice age when Regice\l"
	.string "roamed the frozen landscapes, shaping\l"
	.string "the very glaciers it called home.$"

UnionCity_AbandonedMuseum_Text_AncientGengarShadowRelic:
	.string "“Ancient Gengar Shadow Relic”\p"
	.string "Preserved in a dimly lit case, this\n"
	.string "eerie relic is believed to contain the\l"
	.string "essence of a Gengar's shadow.\p"
	.string "The shifting darkness within hints at\n"
	.string "the bitter nature of the Ghost-type\l"
	.string "Pokémon from ancient times.$"

UnionCity_AbandonedMuseum_Text_AncientSkyPillarScroll:
	.string "“Ancient Sky Pillar Scroll”\p"
	.string "Unfurled carefully, the scroll depicts\n"
	.string "the legendary Sky Pillar, a structure\l"
	.string "associated with the Hoenn region.\p"
	.string "The scroll's detailed illustrations\n"
	.string "reveal the challenges Trainers faced\l"
	.string "as they rose to face the Legendary\l"
	.string "Pokémon Rayquaza.$"

UnionCity_AbandonedMuseum_Text_AncientArmaldoFossilizedClaw:
	.string "“Ancient Armaldo Claw”\p"
	.string "The claw, once razor-sharp and capable\n"
	.string "of rending through the toughest\l"
	.string "exoskeletons, is now frozen in time\l"
	.string "within a protective case.\p"
	.string "The claw provides a rare glimpse into\n"
	.string "the anatomy and predatory adaptations\l"
	.string "that allowed Armaldo to thrive in\l"
	.string "ancient seas.$"

UnionCity_AbandonedMuseum_Text_FossilizedLileepBlossom:
	.string "“Ancient Lileep Blossom”\p"
	.string "The blossom, adorned with delicate\n"
	.string "fronds and petal-like structures,\l"
	.string "tells a tale of Lileep's life in\l"
	.string "ancient seas.\p"
	.string "The rock matrix surrounding the fossil\n"
	.string "hints at the aquatic environments that\l"
	.string "Lileep navigated with its graceful\l"
	.string "appendages, seeking nourishment and\l"
	.string "sunlight.$"

UnionCity_AbandonedMuseum_Text_ReconstructedAerodactylExhibit:
	.string "“Reconstructed Aerodactyl Exhibit”\p"
	.string "Standing proudly in a dynamic pose,\n"
	.string "this life-sized replica of Aerodactyl\l"
	.string "is a marvel of paleontological\l"
	.string "reconstruction, meticulously pieced\l"
	.string "together from the fossilized remains\l"
	.string "of the early Flying/Rock-type Pokémon.\p"
	.string "The skeletal structure, once buried in\n"
	.string "the sands of time, now commands the\l"
	.string "heart of the museum.$"

UnionCity_AbandonedMuseum_Text_TheUnidentifiedPokemon:
	.string "“The Unidentified Pokémon”\p"
	.string "The exhibit showcases few fossilized\n"
	.string "remains that have been discovered,\l"
	.string "leaving much to the imagination.\p"
	.string "Created by a reconstructor's artistic\n"
	.string "interpretation, visualizing what this\l"
	.string "mysterious Pokémon might have looked\l"
	.string "like based on the limited skeletal\l"
	.string "evidence available.$"

UnionCity_AbandonedMuseum_Text_MetagrossCoreCrystal:
	.string "“Metagross' Metallic Core Crystal”\p"
	.string "Encased in a transparent shell, this\n"
	.string "crystal is thought to contain a\l"
	.string "fragment of Metagross' metallic core.\p"
	.string "The hexagonal patterns within the\n"
	.string "crystal reflect the intricate build\l"
	.string "of Metagross, the Iron Leg Pokémon.$"

UnionCity_AbandonedMuseum_Text_AncientOmanyteShell:
	.string "“Ancient Omanyte Shell”\p"
	.string "The shell, adorned with intricate\n"
	.string "spiral patterns and delicate ridges,\l"
	.string "captures the essence of a Pokémon\l"
	.string "that navigated the primeval oceans.\p"
	.string "The fossil provides a glimpse into\n"
	.string "Omanyte's aquatic lifestyle, detailing\l"
	.string "the evolutionary adaptations that\l"
	.string "allowed it to thrive in ancient seas.$"

UnionCity_AbandonedMuseum_Text_KabutoFossil:
	.string "“Ancient Kabuto Shell Fossil”\p"
	.string "Preserved in stone, this fossilized\n"
	.string "Kabuto shell provides insight into the\l"
	.string "evolutionary history of Pokémon.\p"
	.string "The intricate patterns on the shell\n"
	.string "hint at the adaptations that allowed\l"
	.string "Kabuto to thrive in ancient seas.$"

UnionCity_AbandonedMuseum_Text_HoOhRainbowFeather:
	.string "“Ho-Oh's Rainbow Feather”\p"
	.string "A radiant feather that is said to have\n"
	.string "come from the legendary Pokémon Ho-Oh.\p"
	.string "Its iridescent colors shimmer in the\n"
	.string "light, representing the promise of\l"
	.string "eternal happiness to those who witness\l"
	.string "the rainbow created by Ho-Oh's wings.$"
