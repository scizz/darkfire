.set LOCALID_TYLER, 8
.set LOCALID_TYLER_LAB, 9
.set LOCALID_PROF, 10

ChandraVillage_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChandraVillage_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, ChandraVillage_OnTransition
	.byte 0

ChandraVillage_OnTransition:
	call_if_eq VAR_STORYLINE_STATE, 3, ChandraVillage_SetFlag
	end

ChandraVillage_SetFlag::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

ChandraVillage_OnFrame:
	map_script_2 VAR_STORYLINE_STATE, 3, ChandraVillage_Intro
	map_script_2 VAR_STORYLINE_STATE, 7, ChandraVillage_LabDone
	.2byte 0

ChandraVillage_WhiteOut::
	setvar VAR_STORYLINE_STATE, 5
	end

ChandraVillage_ExitNorth::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 11, Common_Movement_FaceUp
	waitmovement 0
	applymovement 11, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement 11, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	goto_if_set FLAG_SYS_POKEMON_GET, ChandraVillage_ExitNorthPokemon
	msgbox ChandraVillage_Text_ExitNorth, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement 11, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

ChandraVillage_ExitNorthPokemon:: 
	msgbox ChandraVillage_Text_ExitNorthPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUp
	waitmovement 0
	applymovement 11, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

ChandraVillage_Intro::
	lockall
	applymovement LOCALID_TYLER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Text_TylerIntro_Player, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_TYLER, WalkL3
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Text_TylerIntro_HeySnorlax, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement LOCALID_TYLER, RunR3D5R3D
	waitmovement 0
	removeobject LOCALID_TYLER
	setflag FLAG_HIDE_CHANDRA_VILLAGE_TYLER_1
	setvar VAR_STORYLINE_STATE, 4
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	special ShowMapNamePopup
	releaseall
	end

ChandraVillage_LabDone::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Prof
	showface FS_PROF, FSE_WORRIED, 1, 1
	msgbox ChandraVillage_Text_HowDidYouGetOn, MSGBOX_DEFAULT
	closemessage
	hideface 1
	delay 60
	applymovement LOCALID_PROF, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Prof
	showface FS_PROF, FSE_LAUGHING, 1, 1
	msgbox ChandraVillage_Text_WowPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	call_if_set FLAG_TAKEN_PIKACHU, ChandraVillage_GivePikachu
	call_if_unset FLAG_TAKEN_PIKACHU, ChandraVillage_GiveEevee
	speakername CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Text_GivePokedex, MSGBOX_AUTOCLOSE
	hideface 1
	playfanfare SE_DEX_SEARCH
	msgbox ChandraVillage_Text_ReceivePokedex, MSGBOX_AUTOCLOSE
	waitfanfare
	speakername CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Text_PokedexDesc, MSGBOX_DEFAULT
	closemessage
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, WRFL
	applymovement LOCALID_PROF, WRFU
	waitmovement 0
	opendoor 37, 6
	waitdooranim
	applymovement LOCALID_PROF, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_PROF
	closedoor 37, 6
	waitdooranim
	setflag FLAG_HIDE_CHANDRA_VILLAGE_LAB_PROF
	setflag FLAG_SYS_POKEDEX_GET
	setvar VAR_STORYLINE_STATE, 8
	releaseall
	end

ChandraVillage_GivePikachu::
	playfanfare MUS_EVOLVED
	msgbox ChandraVillage_Text_ReceivedPikachu, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	return

ChandraVillage_GiveEevee::
	playfanfare MUS_EVOLVED
	msgbox ChandraVillage_Text_ReceivedEevee, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	return

ChandraVillage_Tyler_Debug::
	lockall
	givemon SPECIES_UMBREON, 35, ITEM_NONE
	givemon SPECIES_ESPEON, 35, ITEM_NONE
	givemon SPECIES_VAPOREON, 35, ITEM_NONE
	givemon SPECIES_WAILORD, 35, ITEM_NONE
	givemon SPECIES_RALTS, 35, ITEM_NONE
	givemon SPECIES_DRAGONITE, 35, ITEM_NONE
	giveitem ITEM_MACH_BIKE, 1
	setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_RECEIVED_RUNNING_SHOES
	addobject 24
	setfollower 24, 0x7E
	updatefollowerpokemongraphic
	showfollower
	releaseall
	end

ChandraVillage_Hoenn_Girl::
	msgbox ChandraVillage_Hoenn, MSGBOX_NPC
	end

ChandraVillage_Young_Girl::
	msgbox ChandraVillage_Flowers, MSGBOX_NPC
	end

ChandraVillage_Fat_Guy::
	msgbox ChandraVillage_Technology, MSGBOX_NPC
	end

ChandraVillage_Old_Man::
	lockall
	faceplayer
	msgbox ChandraVillage_Structure, MSGBOX_AUTOCLOSE
	applymovement 6, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement 6, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox ChandraVillage_Dusclops, MSGBOX_AUTOCLOSE
	applymovement 6, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

ChandraVillage_Truck_Boy::
	msgbox ChandraVillage_Slow, MSGBOX_NPC
	end

ChandraVillage_Idle_Truck::
	msgbox ChandraVillage_Truck, MSGBOX_NPC
	end

ChandraVillage_Jokers_Wife::
	msgbox ChandraVillage_Wife, MSGBOX_NPC
	end

ChandraVillage_Letterbox::
	msgbox ChandraVillage_Text_Mail, MSGBOX_SIGN
	end

ChandraVillage_PlayersHouse::
	msgbox ChandraVillage_Text_PlayersHouse, MSGBOX_SIGN
	end

ChandraVillage_TylersHouse::
	msgbox ChandraVillage_Text_TylersHouse, MSGBOX_SIGN
	end

ChandraVillage_Town_Sign::
	msgbox ChandraVillage_Text_Town_Sign, MSGBOX_SIGN
	end

ChandraVillage_Prof::
	lock
	faceplayer
	speakername CommonName_Text_Prof
	showface FS_PROF, FSE_WORRIED, 1, 1
	msgbox ChandraVillage_Text_Prof, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

ChandraVillage_Joker::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_BALL_CHANDRA, ChandraVillage_Joker_Received
	msgbox ChandraVillage_Joker_Question, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_Joker_Yes
	msgbox ChandraVillage_Joker_No, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Joker_Yes::
	msgbox ChandraVillage_Joker_Joke, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_POKE_BALL_CHANDRA
	msgbox ChandraVillage_Joker_Gift, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Joker_Received::
	msgbox ChandraVillage_Joker_End, MSGBOX_DEFAULT
	release
	end

ChandraVillage_Facility_Sign::
	msgbox ChandraVillage_Text_Facility, MSGBOX_SIGN
	end

ChandraVillage_Storyline_State_4::
	lockall
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 42
	goto_if_eq ChandraVillage_Storyline_State_4_Right
	applymovement OBJ_EVENT_ID_PLAYER, WU2FL
	waitmovement 0
	goto ChandraVillage_Storyline_State_4_Next
	end

ChandraVillage_Storyline_State_4_Right::
	applymovement OBJ_EVENT_ID_PLAYER, WLU2FL
	waitmovement 0
	goto ChandraVillage_Storyline_State_4_Next
	end
	
ChandraVillage_Storyline_State_4_Next::
	applymovement LOCALID_TYLER_LAB, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_ANGRY, 1, 1
	msgbox ChandraVillage_Storyline_State_4_ButProf, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_WORRIED, 0, 0
	msgbox ChandraVillage_Storyline_State_4_TylerWithout, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	applymovement LOCALID_TYLER_LAB, Common_Movement_FaceRight
	delay 10
	applymovement LOCALID_TYLER_LAB, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox ChandraVillage_Storyline_State_4_Player, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Storyline_State_4_WontBeAlone, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_PROF, WDFR
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox ChandraVillage_Storyline_State_4_WillYouHelp, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq ChandraVillage_Storyline_State_4_Yes
	goto ChandraVillage_Storyline_State_4_No
	end

ChandraVillage_Storyline_State_4_Yes::
	closemessage
	hideface 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_WINK, 1, 1
	msgbox ChandraVillage_Storyline_State_4_ThatsTheSpirit, MSGBOX_AUTOCLOSE
	hideface 1
	goto ChandraVillage_Storyline_State_4_Part_2
	end

ChandraVillage_Storyline_State_4_No::
	closemessage
	hideface 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_WINK, 1, 1
	msgbox ChandraVillage_Storyline_State_4_VeryFunny, MSGBOX_AUTOCLOSE
	hideface 1
	goto ChandraVillage_Storyline_State_4_Part_2
	end

ChandraVillage_Storyline_State_4_Part_2::
	delay 30
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowLeft
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_ANGRY, 1, 1
	msgbox ChandraVillage_Storyline_State_4_WeWillHelp, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_PROF, WUFR
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox ChandraVillage_Storyline_State_4_VeryWell, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox ChandraVillage_Storyline_State_4_WontLetYouDown, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_ANGRY, 1, 1
	msgbox ChandraVillage_Storyline_State_4_PlayerLetsShow, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_PROF, WDFR
	waitmovement 0
	speakername2 CommonName_Text_Prof
	showface FS_PROF, FSE_NORMAL, 0, 0
	msgbox ChandraVillage_Storyline_State_4_FollowTyler, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_TYLER_LAB, WLFU
	waitmovement 0
	opendoor 37, 6
	waitdooranim
	applymovement LOCALID_TYLER_LAB, Common_Movement_WalkUp
	waitmovement 0
	removeobject LOCALID_TYLER_LAB
	closedoor 37, 6
	waitdooranim
	setflag FLAG_HIDE_CHANDRA_VILLAGE_TYLER_2
	setvar VAR_STORYLINE_STATE, 5
	releaseall
	end

WRFL:
	walk_right
	face_left
	step_end

WRFU:
	walk_right
	face_up
	step_end

WalkL3:
	walk_left
	walk_left
	walk_left
	step_end

RunR3D5R3D:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	step_end

WU2FL:
	walk_up
	walk_up
	face_left
	step_end

WDFR:
	walk_down
	face_right
	step_end

WUFR:
	walk_up
	face_right
	step_end

WLFU:
	walk_left
	face_up
	step_end

WLU2FL:
	walk_up
	walk_left
	walk_up
	face_left
	step_end

ChandraVillage_Text_ExitNorth:
	.string "{COLOR}{BLUE}Hey, kid!\p"
	.string "What do you get when you mix a Pikachu\n"
	.string "and a Haunter?\p"
	.string "…\p"
	.string "A Pikaboo!\n"
	.string "HAHA.\p"
	.string "…\p"
	.string "What's that?\n"
	.string "Haunter doesn't scare you?\p"
	.string "OK, but leaving the village without\n"
	.string "a Pokémon should!\l"
	.string "It's dangerous out there!$"

ChandraVillage_Text_ExitNorthPokemon:
	.string "{COLOR}{BLUE}Hey, kid!\p"
	.string "Why did the Miltank cross the road?\p"
	.string "…\p"
	.string "To get to the udder side!\n"
	.string "HAHA.\p"
	.string "…\p"
	.string "No, but seriously, you should find\n"
	.string "Tyler before leaving the village.$"
	
ChandraVillage_Text_HowDidYouGetOn:
	.string "How did you get on with the Rattata,\n"
	.string "{PLAYER}?\p"
	.string "…$"

ChandraVillage_Text_WowPlayer:
	.string "Wow, {PLAYER}, I…\n"
	.string "You… You tamed my Pokémon?\p"
	.string "…\p"
	.string "You even beat the pests using the\n"
	.string "Pokémon?! I can't believe it!\p"
	.string "Well, {PLAYER}, you have proved yourself\n"
	.string "as a real Pokémon Trainer!\p"
	.string "Keep the Pokémon you caught.\n"
	.string "Take it as a token of my thanks.$"

ChandraVillage_Text_ReceivedPikachu:
	.string "Professor Hawthorne gave you the\n"
	.string "Pikachu!$"

ChandraVillage_Text_ReceivedEevee:
	.string "Professor Hawthorne gave you the\n"
	.string "Eevee!$"

ChandraVillage_Text_GivePokedex:
	.string "Also, please take this Pokédex…$"

ChandraVillage_Text_ReceivePokedex:
	.string "You received a Pokédex!$"

ChandraVillage_Text_PokedexDesc:
	.string "The Pokédex stores data on Pokémon\n"
	.string "you've seen or caught.\p"
	.string "It's a vital tool if you're serious\n"
	.string "about becoming a good Trainer.\p"
	.string "…\n"
	.string "Oh, yes…\p"
	.string "Tyler ran off somewhere in a hurry.\n"
	.string "I think he's excited to have his first\l"
	.string "official Pokémon.\p"
	.string "You should find him and try battling\n"
	.string "in the real world!\l"
	.string "There is a lot to learn out there.\p"
	.string "Well, I must return to the Lab and get\n"
	.string "back to work.\p"
	.string "Thanks again, {PLAYER}!$"

ChandraVillage_Text_TylerIntro_Player:
	.string "{COLOR}{BLUE}{PLAYER}!$"

ChandraVillage_Text_TylerIntro_HeySnorlax:
	.string "{COLOR}{BLUE}Hey, Snorlax!\p"
	.string "I was beginning to think I would need\n"
	.string "a Poké Flute to wake you up!\p"
	.string "Anyway… Listen, {PLAYER}.\p"
	.string "There's an infestation of Pokémon in\n"
	.string "the Professor's Lab.\l"
	.string "We need to go and sort the problem!\p"
	.string "If we don't show the Professor what we\n"
	.string "are capable of, I fear he will never\l"
	.string "give us a Pokémon of our own…\p"
	.string "Let's go there and show him how real\n"
	.string "Pokémon Trainers fight!\p"
	.string "Haha!\n"
	.string "Meet me by the Professor's Lab!$"

ChandraVillage_Hoenn:
	.string "{COLOR}{RED}My family and I moved to Tenjo from\n"
	.string "the Hoenn region.\p"
	.string "The weather in Hoenn was too\n"
	.string "unpredictable at times…$"

ChandraVillage_Flowers:
	.string "{COLOR}{RED}Chandra Village is best known for its\n"
	.string "magical scent from the flowers.\p"
	.string "In the summertime, we often receive\n"
	.string "visits from Sunflora and Skiploom!$"

ChandraVillage_Technology:
	.string "{COLOR}{BLUE}Technology is incredible!\p"	
	.string "There are communities online who\n"
	.string "reverse-engineer games and remake\l"
	.string "them as their own.\p"
	.string "I think it's called ROM Hacking…$"

ChandraVillage_Slow:
	.string "{COLOR}{BLUE}Slow down there!\n"
	.string "This truck won't be moving for a while.\p"
	.string "The driver is dropping off a large\n"
	.string "box of Poké Balls to the Professor.$"

ChandraVillage_Structure:
	.string "This structure has stood for over\n"
	.string "200 years…$"

ChandraVillage_Dusclops:
	.string "It seems that its design was inspired\n"
	.string "the Ghost-type Pokémon, Dusclops.\p"
	.string "Some people even say they have\n"
	.string "heard strange noises inside.$"

ChandraVillage_Truck:
	.string "A truck blocks the way…\n"
	.string "Maybe you should come back later.$"

ChandraVillage_Text_PlayersHouse:
	.string "{PLAYER}'s House$"

ChandraVillage_Text_TylersHouse:
	.string "Tyler's House$"

ChandraVillage_Text_Mail:
	.string "There's mail in here!\n"
	.string "Better leave it alone…$"

ChandraVillage_Text_Town_Sign:
	.string "Chandra Village\n"
	.string "{FONT_SMALL}“A Place to Call Home”$"

ChandraVillage_Text_Prof:
	.string "{PLAYER}…\p"
	.string "Enter the Lab and help get rid of the\n"
	.string "Rattata!$"

ChandraVillage_Text_Facility:
	.string "Professor Hawthorne's Lab$"

ChandraVillage_Wife:
	.string "{COLOR}{RED}I'm sorry for my husband's jokes…\n"
	.string "They're so embarrassing!$"

ChandraVillage_Joker_Question:
	.string "{COLOR}{BLUE}Oh, hello there.\n"
	.string "I haven't seen you around here before…\p"
	.string "Wanna hear a joke?$"

ChandraVillage_Joker_No:
	.string "{COLOR}{BLUE}Suit yourself!$"

ChandraVillage_Joker_Joke:
	.string "{COLOR}{BLUE}What did one Geodude say to the\n"
	.string "other Geodude?\p"
	.string "…\n"
	.string "…\p"
	.string "Let's rock!\n"
	.string "HA.\p"
	.string "…\n"
	.string "…\p"
	.string "All right. I'm sorry.\n"
	.string "That was a bad one.\p"
	.string "Please take this as a token of my\n"
	.string "apology…$"

ChandraVillage_Joker_Gift:
	.string "{COLOR}{BLUE}Use this to catch a wild Pokémon!\n"
	.string "It doesn't always work, though.$"

ChandraVillage_Joker_End:
	.string "{COLOR}{BLUE}That's it!\n"
	.string "I'm all outta jokes!$"

ChandraVillage_Storyline_State_4_ButProf:
	.string "{COLOR}{BLUE}But, Professor Hawthorne, if you\n"
	.string "don't let us in there, the Rattata\l"
	.string "will destroy your research notes!$"

ChandraVillage_Storyline_State_4_TylerWithout:
	.string "Tyler, without your own Pokémon I\n"
	.string "have no other choice but to say no…\p"
	.string "It's far too dangerous to let you\n"
	.string "in there on your own.$"

ChandraVillage_Storyline_State_4_Player:
	.string "{COLOR}{BLUE}{PLAYER}!$"

ChandraVillage_Storyline_State_4_WontBeAlone:
	.string "{COLOR}{BLUE}Professor Hawthorne, I won't be alone.\n"
	.string "{PLAYER} is here to help, too!$"

ChandraVillage_Storyline_State_4_WillYouHelp:
	.string "…\p"
	.string "{PLAYER}…\n"
	.string "Will you help Tyler with the Rattata?$"

ChandraVillage_Storyline_State_4_ThatsTheSpirit:
	.string "{COLOR}{BLUE}That's the spirit, {PLAYER}!$"

ChandraVillage_Storyline_State_4_VeryFunny:
	.string "{COLOR}{BLUE}Very funny, {PLAYER}!$"

ChandraVillage_Storyline_State_4_WeWillHelp:
	.string "{COLOR}{BLUE}Professor, we will help.\n"
	.string "We won't let you down!$"

ChandraVillage_Storyline_State_4_VeryWell:
	.string "Very well.\n"
	.string "Both of you be very careful.\p"
	.string "I have left two Pokémon inside the\n"
	.string "facility outside of their Poké Balls.\p"
	.string "If you can find a way to tame them\n"
	.string "and defeat the wild Rattata, I will\l"
	.string "consider both of you Pokémon Trainers.$"

ChandraVillage_Storyline_State_4_WontLetYouDown:
	.string "{COLOR}{BLUE}We won't let you down, Professor!$"

ChandraVillage_Storyline_State_4_PlayerLetsShow:
	.string "{COLOR}{BLUE}{PLAYER}!\p"
	.string "Let's show the Professor what we're\n"
	.string "made of!$"

ChandraVillage_Storyline_State_4_FollowTyler:
	.string "{PLAYER}…\p"
	.string "Follow Tyler and pick a Pokémon to\n"
	.string "fight with.\p"
	.string "Let me know when you're both done.$"
