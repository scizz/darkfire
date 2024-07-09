.set LOCALID_SUBO, 4
.set LOCALID_JIGGLYPUFF, 1
.set LOCALID_ROSE, 2

NorthstarCity_Tournament_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NorthstarCity_Tournament_1F_OnTransition
	.byte 0

NorthstarCity_Tournament_1F_OnTransition:
	call_if_unset FLAG_NORTHSTAR_SUBO_TAKEOVER, NorthstarCity_Tournament_1F_HideSUBO
	call_if_set FLAG_NORTHSTAR_SUBO_TAKEOVER, NorthstarCity_Tournament_1F_CheckVar
	end

NorthstarCity_Tournament_1F_HideSUBO::
	call_if_le VAR_STORYLINE_STATE, 35, NorthstarCity_Tournament_1F_ResetTournament
	setflag FLAG_NORTHSTAR_TOURNAMENT_SUBO
	setflag FLAG_NORTHSTAR_TOURNAMENT_SUBO_1F
	setflag FLAG_NORTHSTAR_TOURNAMENT_SUBO_2F
	setflag FLAG_NORTHSTAR_TOURNAMENT_ROSE
	setflag FLAG_ITEM_NORTHSTAR_CITY_TOXIC
	end

NorthstarCity_Tournament_1F_CheckVar::
	call_if_le VAR_STORYLINE_STATE, 36, NorthstarCity_Tournament_1F_SetVar
	return

NorthstarCity_Tournament_1F_SetVar::
	setvar VAR_STORYLINE_STATE, 37
	return

NorthstarCity_Tournament_1F_ResetTournament::
	clearflag FLAG_NORTHSTAR_TOURNAMENT_PSYCHIC
	clearflag FLAG_NORTHSTAR_TOURNAMENT_RANGER
	setvar VAR_STORYLINE_STATE, 28
	return

NorthstarCity_Tournament_1F_SUBOEnd::
	lock
	special HealPlayerParty
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	clearflag FLAG_NORTHSTAR_TOURNAMENT_SUBO_1F
	addobject LOCALID_SUBO
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 14
	goto_if_eq NorthstarCity_Tournament_1F_Left
	goto NorthstarCity_Tournament_1F_Down
	end

NorthstarCity_Tournament_1F_Left::
	applymovement LOCALID_SUBO, WLU6
	waitmovement 0
	goto NorthstarCity_Tournament_1F_SUBOEndDialogue
	end

NorthstarCity_Tournament_1F_Down::
	applymovement LOCALID_SUBO, WU5
	waitmovement 0
	goto NorthstarCity_Tournament_1F_SUBOEndDialogue
	end

NorthstarCity_Tournament_1F_SUBOEndDialogue::
	playbgm MUS_SUBO_THEME, TRUE
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_1F_Text_HeyYouYouveCausedUs, MSGBOX_AUTOCLOSE
	hideface 1
	emote LOCALID_SUBO, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_1F_Text_GruntAreYouUpstairs, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	speakername SpeakerName_Text_QuestionMark
	msgbox NorthstarCity_Tournament_1F_Text_YeahImStillUpHere, MSGBOX_AUTOCLOSE
	delay 30
	applymovement LOCALID_SUBO, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_1F_Text_BossSaidItsTime, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	speakername SpeakerName_Text_QuestionMark
	msgbox NorthstarCity_Tournament_1F_Text_Roger, MSGBOX_AUTOCLOSE
	playse SE_BALL_THROW
	waitse
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 14
	goto_if_eq NorthstarCity_Tournament_1F_JigglypuffLeft
	goto NorthstarCity_Tournament_1F_JigglypuffDown
	end

NorthstarCity_Tournament_1F_JigglypuffLeft::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkDownFaster
	addobject LOCALID_JIGGLYPUFF
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceUp
	applymovement LOCALID_JIGGLYPUFF, Common_Movement_JumpInPlaceDown
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto NorthstarCity_Tournament_1F_JigglypuffSleep
	end

NorthstarCity_Tournament_1F_JigglypuffDown::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkLeftFaster
	addobject LOCALID_JIGGLYPUFF
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceRight
	applymovement LOCALID_JIGGLYPUFF, Common_Movement_JumpInPlaceDown
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto NorthstarCity_Tournament_1F_JigglypuffSleep
	end

NorthstarCity_Tournament_1F_JigglypuffSleep::
	emote OBJ_EVENT_ID_PLAYER, 8
	playse SE_PIN
	waitse
	emote LOCALID_SUBO, 0
	playse SE_PIN
	waitse
	applymovement LOCALID_SUBO, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_1F_Text_HahaLater, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_SUBO, WD6
	waitmovement 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 14
	goto_if_eq NorthstarCity_Tournament_1F_JigglypuffLeftTwo
	goto NorthstarCity_Tournament_1F_JigglypuffDownTwo
	end

NorthstarCity_Tournament_1F_JigglypuffLeftTwo::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto NorthstarCity_Tournament_1F_JigglypuffSleepNow
	end

NorthstarCity_Tournament_1F_JigglypuffDownTwo::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto NorthstarCity_Tournament_1F_JigglypuffSleepNow
	end

NorthstarCity_Tournament_1F_JigglypuffSleepNow::
	speakername CommonName_Text_Jigglypuff
	playmoncry SPECIES_JIGGLYPUFF, 1
	msgbox NorthstarCity_Tournament_1F_Text_Jiggly, MSGBOX_AUTOCLOSE
	waitmoncry
	playse SE_M_SING
	waitse
	fadescreen 1
	fadeoutbgm 1
	removeobject LOCALID_JIGGLYPUFF
	playse SE_M_PERISH_SONG
	delay 30
	waitse
	playse SE_M_SNORE
	waitse
	delay 90
	playse SE_M_SNORE
	waitse
	delay 90
	addobject LOCALID_ROSE
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_0, 14
	goto_if_eq NorthstarCity_Tournament_1F_RoseLookUp
	goto NorthstarCity_Tournament_1F_RoseLookRight
	end

NorthstarCity_Tournament_1F_RoseLookUp::
	applymovement LOCALID_ROSE, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkUpFaster
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement 0
	goto NorthstarCity_Tournament_1F_SUBOEndRose
	end

NorthstarCity_Tournament_1F_RoseLookRight::
	applymovement LOCALID_ROSE, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkRightFaster
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceDown
	waitmovement 0
	goto NorthstarCity_Tournament_1F_SUBOEndRose
	end

NorthstarCity_Tournament_1F_SUBOEndRose::
	fadescreen 0
	playbgm MUS_NORTHSTAR_TOURNAMENT, TRUE
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_1F_Text_PlayerIFoundAJigglypuff, MSGBOX_AUTOCLOSE
	hideface 1
	delay 30
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_1F_Text_AlsoIManaged, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_POKE_FLUTE, 1
	speakername CommonName_Text_Rose
	showface FS_ROSE, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Tournament_1F_Text_TakeItEasy, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_ROSE, WD6
	waitmovement 0
	removeobject LOCALID_ROSE
	removeobject LOCALID_SUBO
	setflag FLAG_NORTHSTAR_TOURNAMENT_SUBO
	setflag FLAG_NORTHSTAR_TOURNAMENT_SUBO_1F
	setflag FLAG_NORTHSTAR_TOURNAMENT_SUBO_2F
	setflag FLAG_NORTHSTAR_TOURNAMENT_ROSE
	setflag FLAG_NORTHSTAR_TOURNAMENT_ROSE_1F
	setflag FLAG_NORTHSTAR_TOURNAMENT_COMPLETE
	clearflag FLAG_HIDE_NORTHSTAR_CITY_SAILOR_NEW
	setvar VAR_STORYLINE_STATE, 38
	end

NorthstarCity_Tournament_1F_Woman::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Woman_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Woman, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Woman_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Woman_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Nerd::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Nerd_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Nerd, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Nerd_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Nerd_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Old_Man::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Old_Man_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Old_Man, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Old_Man_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Old_Man_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Receptionist_1::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Receptionist_1_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Receptionist_1, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Receptionist_1_Badge::
	msgbox NorthstarCity_Tournament_1F_Text_Receptionist_1_Badge, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Receptionist_2::
	goto_if_set FLAG_BADGE03_GET, NorthstarCity_Tournament_1F_Receptionist_1_Badge
	msgbox NorthstarCity_Tournament_1F_Text_Receptionist_2, MSGBOX_NPC
	end

NorthstarCity_Tournament_1F_Man::
	lock
	msgbox NorthstarCity_Tournament_1F_Text_Man, MSGBOX_AUTOCLOSE
	release
	end

NorthstarCity_Tournament_1F_Little_Girl::
	lock
	msgbox NorthstarCity_Tournament_1F_Text_Little_Girl, MSGBOX_AUTOCLOSE
	release
	end

WLU6:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NorthstarCity_Tournament_1F_Text_HeyYouYouveCausedUs:
	.string "{COLOR}{BLUE}Hey, you!\p"
	.string "You've caused us nothing but problems\n"
	.string "since we took over this tower!\p"
	.string "You're really annoying, you know that?\n"
	.string "Your meddling ends here!$"

NorthstarCity_Tournament_1F_Text_GruntAreYouUpstairs:
	.string "{COLOR}{BLUE}Grunt!\n"
	.string "Are you still upstairs?!$"

NorthstarCity_Tournament_1F_Text_YeahImStillUpHere:
	.string "Yeah. I'm still up here.\n"
	.string "Whaddya want?$"

NorthstarCity_Tournament_1F_Text_BossSaidItsTime:
	.string "{COLOR}{BLUE}Boss said it's time to go!\p"
	.string "I got the kid here!\p"
	.string "Throw that Jigglypuff down and let's\n"
	.string "all get outta here!$"

NorthstarCity_Tournament_1F_Text_Roger:
	.string "Roger.$"

NorthstarCity_Tournament_1F_Text_HahaLater:
	.string "{COLOR}{BLUE}Hahahaha!\n"
	.string "Later, sleepy-head!$"

NorthstarCity_Tournament_1F_Text_Jiggly:
	.string "Jiggly!$"

NorthstarCity_Tournament_1F_Text_PlayerIFoundAJigglypuff:
	.string "{COLOR}{RED}{PLAYER}?\p"
	.string "I found a Jigglypuff upstairs.\n"
	.string "It must have sang you to sleep.\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "The SUBO have escaped.\n"
	.string "Who knows what their next move is…\p"
	.string "I'm getting out of here.\n"
	.string "You should do the same.\p"
	.string "You can get a boat back to Laveria\n"
	.string "City from the Northstar Docks.$"

NorthstarCity_Tournament_1F_Text_AlsoIManaged:
	.string "{COLOR}{RED}Also, I managed to take this from\n"
	.string "one of the SUBO Grunts… Here.$"

NorthstarCity_Tournament_1F_Text_TakeItEasy:
	.string "{COLOR}{RED}You can use that to wake up sleeping\n"
	.string "Pokémon, whether they are in battle,\l"
	.string "or blocking a path, like in Route 9.\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Take it easy, okay?$"

NorthstarCity_Tournament_1F_Text_Woman:
	.string "{COLOR}{RED}I just made it to the city in time for\n"
	.string "the tournament, but my Pokémon are\l"
	.string "battered from the journey through the\l"
	.string "mountains and ice.\p"
	.string "Oh, well. Even if we lose, the battle\n"
	.string "we went through will harden us up.$"

NorthstarCity_Tournament_1F_Text_Woman_Badge:
	.string "{COLOR}{RED}The SUBO hijacking the TV Station\n"
	.string "hardened up my Pokémon and I more than\l"
	.string "the challenge of the tournament…\p"
	.string "Saying that, though - I really\n"
	.string "hope I never cross paths with those\l"
	.string "terrible scoundrels again!$"

NorthstarCity_Tournament_1F_Text_Nerd:
	.string "{COLOR}{BLUE}Here for the tournament.\p"
	.string "What, me, battle?\n"
	.string "No way!\p"
	.string "I'm just here to watch.$"

NorthstarCity_Tournament_1F_Text_Nerd_Badge:
	.string "{COLOR}{BLUE}I'm glad I didn't take part in the\n"
	.string "tournament this year.\p"
	.string "Why, you ask?\p"
	.string "Because you would have wiped the floor\n"
	.string "with me!$"

NorthstarCity_Tournament_1F_Text_Old_Man:
	.string "I used to work here. Now I'm just here\n"
	.string "for the complementary Lemonade I get\l"
	.string "as part of my retirement plan.\l"
	.string "And to watch the tournament, yes…\p"
	.string "But mainly for the Lemonade!$"

NorthstarCity_Tournament_1F_Text_Old_Man_Badge:
	.string "Those SUBO scum that raided this place\n"
	.string "are lucky that I am an Old Man!\p"
	.string "When I was working here in the past, I\n"
	.string "was a lot fitter and stronger.\p"
	.string "I would have quickly taken care of the\n"
	.string "SUBO as soon as they came through the\l"
	.string "doors! Hrrmph!\p"
	.string "Time for a Lemonade break…$"

NorthstarCity_Tournament_1F_Text_Receptionist_1:
	.string "{COLOR}{RED}Welcome to the Northstar TV Station.\p"
	.string "If you bought a subscription for our\n"
	.string "online television program and somehow\l"
	.string "regretted it, we apologize. No refunds!$"

NorthstarCity_Tournament_1F_Text_Receptionist_1_Badge:
	.string "{COLOR}{RED}Welcome to the Northstar TV Station.\p"
	.string "Thank you for saving us from the SUBO!$"

NorthstarCity_Tournament_1F_Text_Receptionist_2:
	.string "{COLOR}{RED}Welcome to the Northstar TV Station.\p"
	.string "You are here for the tournament?\p"
	.string "Please, go to the top floor and\n"
	.string "inquire with our staff there.$"

NorthstarCity_Tournament_1F_Text_Man:
	.string "{COLOR}{BLUE}I'll get you all the Poké Balls you\n"
	.string "want, and help you catch Pokémon, too!$"

NorthstarCity_Tournament_1F_Text_Little_Girl:
	.string "{COLOR}{RED}Papa, will you get me a Poké Ball like\n"
	.string "the one in that cover?$"
