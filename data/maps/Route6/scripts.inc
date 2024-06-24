.set LOCALID_RANGER, 17

Route6_MapScripts::
	.byte 0

Route6_Sign::
	msgbox Route6_Text_Sign, MSGBOX_SIGN
	end

Route6_LeftSign::
	msgbox Route6_Text_LeftSign, MSGBOX_SIGN
	end

Route6_Sign_West::
	msgbox Route6_Text_Sign_West, MSGBOX_SIGN
	end

Route6_Ranger_Female::
	lock
	faceplayer
	speakername CommonName_Text_Ranger
	showface FS_FEMALE_RANGER, FSE_NORMAL, 1, 1
	msgbox Route6_Text_Ranger_Female, MSGBOX_AUTOCLOSE
	hideface 1
	end

Route6_Ranger_Male::
	lock
	faceplayer
	speakername CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 1, 1
	msgbox Route6_Text_Ranger_Male, MSGBOX_AUTOCLOSE
	hideface 1
	end

Route6_Man::
	msgbox Route6_Text_Man, MSGBOX_NPC
	end

Route6_Old_Lady::
	msgbox Route6_Text_Old_Lady, MSGBOX_NPC
	end

Route6_EventScript_Steve::
	trainerbattle_single TRAINER_STEVE, Route6_Text_SteveIntro, Route6_Text_SteveDefeated
	msgbox Route6_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route6_Text_AndrewIntro, Route6_Text_AndrewDefeated
	msgbox Route6_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, Route6_Text_VirgilIntro, Route6_Text_VirgilDefeated
	msgbox Route6_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY, Route6_Text_JennyIntro, Route6_Text_JennyDefeated
	goto_if_set FLAG_ROUTE_6_FRESH_WATER, Route6_Given
	msgbox Route6_Text_Jenny_Gift, MSGBOX_DEFAULT
	giveitem ITEM_FRESH_WATER, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_6_FRESH_WATER
	closemessage
	end

Route6_Given::
	msgbox Route6_Text_Given, MSGBOX_DEFAULT
	closemessage
	end

Route6_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route6_Text_KoichiIntro, Route6_Text_KoichiDefeated
	msgbox Route6_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Camron::
	trainerbattle_single TRAINER_CAMRON, Route6_Text_CamronIntro, Route6_Text_CamronDefeated
	msgbox Route6_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Lucas::
	trainerbattle_single TRAINER_LUCAS, Route6_Text_LucasIntro, Route6_Text_LucasDefeated
	msgbox Route6_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Ranger::
	lock
	goto_if_set FLAG_ROUTE_6_STEEP_RAVINE_CLEARED, Route6_Ranger_Cleared
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox Route6_Text_OkayOneTwoThree, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox Route6_Text_ItsUseless, MSGBOX_AUTOCLOSE
	hideface 0
	delay 30
	faceplayer
	emote LOCALID_RANGER, 1
	playse SE_PIN
	waitse
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox Route6_Text_OhATrainer, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq Route6_Ranger_Yes
	goto Route6_Ranger_No
	end

Route6_Ranger_Cleared::
	faceplayer
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox Route6_Text_HeyoTrainerYoureBack, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq Route6_Ranger_Yes
	msgbox Route6_Text_IfYouEverWantToGetDown, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_RANGER, Common_Movement_FaceRight
	waitmovement 0
	release
	end

Route6_Ranger_Yes::
	msgbox Route6_Text_AllRIghtNow, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_RANGER, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ShrinkPokemon
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, WR2D
	waitmovement 0
	applymovement LOCALID_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox Route6_Text_AreYouReadyFasten, MSGBOX_AUTOCLOSE
	hideface 0
	playse SE_PIN
	waitse
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LFDD
	playse SE_PIN
	waitse
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	playse SE_PIN
	waitse
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	playse SE_PIN
	waitse
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	playse SE_PIN
	waitse
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	playse SE_PIN
	waitse
	waitmovement 0
	setflag FLAG_ROUTE_6_STEEP_RAVINE_CLEARED
	warp MAP_STEEP_RAVINE, 45, 13
	waitstate
	end

Route6_Ranger_No::
	msgbox Route6_Text_NoWellIGuess, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_RANGER, Common_Movement_FaceRight
	waitmovement 0
	release
	end

LFDD:
	lock_facing_direction
	walk_down
	step_end

WR2D:
	walk_right
	walk_right
	walk_down
	step_end

Route6_Text_LeftSign:
	.string "Route 6\n"
	.string "{LEFT_ARROW} Laveria City$"

Route6_Text_OkayOneTwoThree:
	.string "{COLOR}{BLUE}Okay…\n"
	.string "One… Two… Three…$"

Route6_Text_ItsUseless:
	.string "{COLOR}{BLUE}It's useless.\p"
	.string "I'm too scared of heights to even\n"
	.string "attempt to climb down this rope.\p"
	.string "Why did I become a Ranger in the\n"
	.string "first place…?$"

Route6_Text_OhATrainer:
	.string "{COLOR}{BLUE}Oh, a Trainer!\n"
	.string "Greetings, Trainer.\p"
	.string "I've been sent here to investigate the\n"
	.string "Steep Ravine you see down below.\p"
	.string "By whom, you ask?\n"
	.string "The Rangers' Federation of course!\p"
	.string "But I've… Uh. I've sprained my ankle!\n"
	.string "So I can't climb down there!\p"
	.string "Can you climb down this rope and see if\n"
	.string "there are any dangerous Pokémon below?$"

Route6_Text_NoWellIGuess:
	.string "{COLOR}{BLUE}N-no?\p"
	.string "W-well, I guess I'll have to d-do it\n"
	.string "myself…$"

Route6_Text_HeyoTrainerYoureBack:
	.string "{COLOR}{BLUE}Heyo, Trainer, you're back!\n"
	.string "How was it down in the Steep Ravine?\p"
	.string "Are you looking to go back down there?\n$"

Route6_Text_IfYouEverWantToGetDown:
	.string "{COLOR}{BLUE}If you ever want to get down in the\n"
	.string "Steep Ravine, just let me know and I'll\l"
	.string "lower you right in!$"

Route6_Text_AllRIghtNow:
	.string "{COLOR}{BLUE}All right!\p"
	.string "Now, grab the rope and I'll lower you\n"
	.string "in!$"

Route6_Text_AreYouReadyFasten:
	.string "{COLOR}{BLUE}Are you ready?\n"
	.string "Fasten your harness and here we go!$"

Route6_Text_Sign:
	.string "Route 6\n"
	.string "Not for inexperienced Hikers!$"

Route6_Text_Sign_West:
	.string "Route 6\n"
	.string "{LEFT_ARROW} Laveria City$"

Route6_Text_Ranger_Female:
	.string "{COLOR}{RED}Halt, trainer!\p"
	.string "We've been sent here from the Rangers'\n"
	.string "Federation to guard this unsafe spot!$"

Route6_Text_Ranger_Male:
	.string "{COLOR}{BLUE}Dangerous Pokémon have been spotted\n"
	.string "past this point.\p"
	.string "We can't allow anyone to pass before\n"
	.string "we fully investigate.$"

Route6_Text_Man:
	.string "{COLOR}{BLUE}This route is a hotspot for Hikers.\n"
	.string "There is so much to do!$"

Route6_Text_Old_Lady:
	.string "Oh, young one…\n"
	.string "You have a twinkle in your eye…\p"
	.string "You will amass great fortunes, indeed.$"

Route6_Text_Jenny_Gift:
	.string "{COLOR}{RED}Battling in this mountain is hard work!\n"
	.string "It's important to stay hydrated.\p"
	.string "I know! I'll share some of my Fresh\n"
	.string "Water with you!$"

Route6_Text_Given:
	.string "{COLOR}{RED}You should check out the Steep Ravine\n"
	.string "sometime.\p"
	.string "You can find some rare Pokémon down\n"
	.string "there!$"
