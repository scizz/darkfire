.set LOCALID_MOM, 1

ChandraVillage_PlayerHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChandraVillage_PlayerHouse_2F_OnFrame
	.byte 0

ChandraVillage_PlayerHouse_2F_Sign_TV::
	msgbox ChandraVillage_PlayerHouse_2F_Text_Sign_TV, MSGBOX_SIGN
	end

ChandraVillage_PlayerHouse_2F_Sign_Flowers::
	msgbox ChandraVillage_PlayerHouse_2F_Text_Sign_Flowers, MSGBOX_SIGN
	end

ChandraVillage_PlayerHouse_2F_Sign_Guitar::
	msgbox ChandraVillage_PlayerHouse_2F_Text_Sign_Guitar, MSGBOX_SIGN
	end

ChandraVillage_PlayerHouse_2F_Sign_Amp::
	msgbox ChandraVillage_PlayerHouse_2F_Text_Sign_Amp, MSGBOX_SIGN
	end

ChandraVillage_PlayerHouse_2F_Sign_Switch::
	msgbox ChandraVillage_PlayerHouse_2F_Text_Sign_Switch, MSGBOX_SIGN
	end

ChandraVillage_PlayerHouse_2F_Sign_Trash::
	msgbox ChandraVillage_PlayerHouse_2F_Text_Sign_Trash, MSGBOX_SIGN
	end

ChandraVillage_PlayerHouse_2F_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 0, ChandraVillage_PlayerHouse_2F_Intro
	.2byte 0

ChandraVillage_PlayerHouse_2F_Intro::
	lockall
	delay 30
	playse SE_UNLOCK
	waitse
	playse SE_UNLOCK
	waitse
	delay 30
	speakername CommonName_Text_Mom
	msgbox ChandraVillage_PlayerHouse_2F_Text_WakeUp, MSGBOX_AUTOCLOSE
	setvar VAR_STORYLINE_STATE, 1
	clearflag FLAG_SYS_TELESCOPE_USE
	releaseall
	end

ChandraVillage_PlayerHouse_2F_NinjaBoy::
	lock
	goto_if_set FLAG_HIDDEN_ITEM_CHANDRA_VILLAGE_PLAYERS_HOUSE_2F_POTION, ChandraVillage_PlayerHouse_2F_NinjaBoyGiven
	delay 10
	giveitem ITEM_POTION, 1
	setflag FLAG_HIDDEN_ITEM_CHANDRA_VILLAGE_PLAYERS_HOUSE_2F_POTION
	release
	end

ChandraVillage_PlayerHouse_2F_NinjaBoyGiven::
	msgbox ChandraVillage_PlayerHouse_2F_Text_Sign_Trash, MSGBOX_AUTOCLOSE
	release
	end

ChandraVillage_PlayerHouse_2F_Storyline_State_1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	playse SE_UNLOCK
	waitse
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, WalkUpLocked
	waitmovement 0
	clearflag FLAG_HIDE_CHANDRA_VILLAGE_PLAYERS_BEDROOM_MOM
	addobject LOCALID_MOM, MAP_CHANDRA_VILLAGE_PLAYER_HOUSE_2F
	playse SE_EXIT
	waitse
	emote LOCALID_MOM, 8
	playse SE_PIN
	waitse
	speakername CommonName_Text_Mom
	showface FS_MOM, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_PlayerHouse_2F_Text_KnockingOnDoor, MSGBOX_DEFAULT
	closemessage
	hideface 1
	delay 30
	emote LOCALID_MOM, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Mom
	showface FS_MOM, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_PlayerHouse_2F_Text_YouLookFlustered, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement LOCALID_MOM, Common_Movement_FaceLeft
	waitmovement 0
	delay 20
	applymovement LOCALID_MOM, Common_Movement_FaceRight
	waitmovement 0
	delay 20
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	delay 20
	speakername CommonName_Text_Mom
	showface FS_MOM, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_PlayerHouse_2F_Text_TylerLooking, MSGBOX_DEFAULT
	hideface 1
	closemessage
	delay 10
	applymovement LOCALID_MOM, Common_Movement_FaceDown
	waitmovement 0
	removeobject LOCALID_MOM, MAP_CHANDRA_VILLAGE_PLAYER_HOUSE_2F
	playse SE_EXIT
	waitse
	setflag FLAG_HIDE_CHANDRA_VILLAGE_PLAYERS_BEDROOM_MOM
	setvar VAR_STORYLINE_STATE, 2
	releaseall
	end

ChandraVillage_PlayerHouse_2F_Storyline_State_2::
	lockall
	speakername CommonName_Text_Mom
	msgbox ChandraVillage_PlayerHouse_2F_Text_ComeDownstairs, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	releaseall
	end

WalkUpLocked:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

ChandraVillage_PlayerHouse_2F_Text_Sign_TV:
	.string "Not a speck of dust on the TV!$"

ChandraVillage_PlayerHouse_2F_Text_Sign_Flowers:
	.string "Flowers are arranged neatly in an\n"
	.string "orange vase.$"

ChandraVillage_PlayerHouse_2F_Text_Sign_Guitar:
	.string "It's a shiny Yamaha guitar.$"

ChandraVillage_PlayerHouse_2F_Text_Sign_Amp:
	.string "It's an amp for your guitar.$"

ChandraVillage_PlayerHouse_2F_Text_Sign_Switch:
	.string "It's a Nintendo Switch.\n"
	.string "Where's your Game Boy Advance?$"

ChandraVillage_PlayerHouse_2F_Text_Sign_Trash:
	.string "There's nothing but trash in here…$"

ChandraVillage_PlayerHouse_2F_Text_WakeUp:
	.string "{COLOR}{RED}{PLAYER}!\n"
	.string "Rise and shine!$"

ChandraVillage_PlayerHouse_2F_Text_KnockingOnDoor:
	.string "{COLOR}{RED}{PLAYER}?\p"
	.string "I've been knocking on your door all\n"
	.string "morning!\p"
	.string "… … …\n"
	.string "… … …$"

ChandraVillage_PlayerHouse_2F_Text_YouLookFlustered:
	.string "{COLOR}{RED}Oh, {PLAYER}, you look flustered…\n"
	.string "Were you having a bad dream?\p"
	.string "…\n"
	.string "You poor thing.$"

ChandraVillage_PlayerHouse_2F_Text_TylerLooking:
	.string "{COLOR}{RED}Oh… I forgot to mention that Tyler\n"
	.string "has been calling for you this morning.\p"
	.string "The village has been a lot louder ever\n"
	.string "since he moved in next door…\p"
	.string "{PLAYER}, I suggest you wake yourself\n"
	.string "up and go and see him!$"

ChandraVillage_PlayerHouse_2F_Text_ComeDownstairs:
	.string "{COLOR}{RED}{PLAYER}!\n"
	.string "Come downstairs, honey!$"
