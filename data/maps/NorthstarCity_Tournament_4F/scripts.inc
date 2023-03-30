.set LOCALID_SUBO_CROWD, 1
.set LOCALID_ROSE, 2
.set LOCALID_FAT_MAN, 3
.set LOCALID_POKEFAN_F, 4
.set LOCALID_ANNOUNCER, 5
.set LOCALID_CAMERA_LEFT, 6
.set LOCALID_CAMERA_RIGHT, 7
.set LOCALID_ITEM_BALL, 8
.set LOCALID_CAMERA_BOTTOM, 9
.set LOCALID_BLACKBELT_ARENA, 10
.set LOCALID_RANGER_ARENA, 11
.set LOCALID_PSYCHIC_ARENA, 12
.set LOCALID_ACE_TRAINER_ARENA, 13
.set LOCALID_GENTLEMAN_ARENA, 14
.set LOCALID_SAILOR_ARENA, 15
.set LOCALID_RECEPTIONIST, 16
.set LOCALID_ACE_TRAINER_DOOR, 17
.set LOCALID_BLACKBELT_DOOR, 18
.set LOCALID_GENTLEMAN_DOOR, 19
.set LOCALID_RAKAZ, 20
.set LOCALID_SUBO_DOOR, 21
.set LOCALID_SAILOR_DOOR, 22

NorthstarCity_Tournament_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NorthstarCity_Tournament_4F_OnFrame
	.byte 0

NorthstarCity_Tournament_4F_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 1, NorthstarCity_Tournament_4F_EventStart
	.2byte 0

NorthstarCity_Tournament_4F_EventStart::
	applymovement LOCALID_RECEPTIONIST, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, WU2L
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto_if_set FLAG_NORTHSTAR_TOURNAMENT_STARTED, NorthstarCity_Tournament_WelcomeBack
	msgbox NorthstarCity_Tournament_4F_Text_GreetingsIfYouveCome, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq NorthstarCity_Tournament_PartyCheck
	goto NorthstarCity_Tournament_NotReady
	end

NorthstarCity_Tournament_PartyCheck::
	getpartysize
	compare VAR_RESULT, 2
	goto_if_ge NorthstarCity_Tournament_Started
	goto NorthstarCity_Tournament_NotReady
	end

NorthstarCity_Tournament_NotReady::
	msgbox NorthstarCity_Tournament_4F_Text_PleaseComeBack, MSGBOX_AUTOCLOSE
	setflag FLAG_NORTHSTAR_TOURNAMENT_STARTED
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	warp MAP_NORTHSTAR_CITY_TOURNAMENT_3F, 15, 1
	waitstate
	end

NorthstarCity_Tournament_WelcomeBack::
	msgbox NorthstarCity_Tournament_4F_Text_WelcomeBackPlayer, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq NorthstarCity_Tournament_RandCheck
	goto NorthstarCity_Tournament_NotReady
	end

NorthstarCity_Tournament_RandCheck::
	random 2
	switch VAR_RESULT
	case 0, NorthstarCity_Tournament_HidePsychic
	case 1, NorthstarCity_Tournament_HideRanger
	end

NorthstarCity_Tournament_HidePsychic::
	removeobject LOCALID_PSYCHIC_ARENA
	setflag FLAG_NORTHSTAR_TOURNAMENT_PSYCHIC
	goto NorthstarCity_Tournament_Started
	end

NorthstarCity_Tournament_HideRanger::
	removeobject LOCALID_RANGER_ARENA
	setflag FLAG_NORTHSTAR_TOURNAMENT_RANGER
	goto NorthstarCity_Tournament_Started
	end

NorthstarCity_Tournament_Started::
	setflag FLAG_NORTHSTAR_TOURNAMENT_STARTED
	applymovement LOCALID_RECEPTIONIST, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox NorthstarCity_Tournament_4F_Text_GreatFollowMe, MSGBOX_AUTOCLOSE
	showfollower
	applymovement LOCALID_RECEPTIONIST, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, WD5
	applymovement OBJ_EVENT_ID_PLAYER, WRD4
	applymovement OBJ_EVENT_ID_FOLLOWER WR2D3
	waitmovement 0
	applymovement LOCALID_RECEPTIONIST, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox NorthstarCity_Tournament_4F_Text_YourOpponentAwaits, MSGBOX_AUTOCLOSE
	applymovement LOCALID_RECEPTIONIST, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, WL5DL2
	applymovement OBJ_EVENT_ID_FOLLOWER, WDL5DL
	waitmovement 0
	clearflag FLAG_FOLLOWER_IN_BUILDING
	setvar VAR_STORYLINE_STATE, 2
	end

WU2L:
	walk_up
	walk_up
	walk_left
	step_end

WR2D3:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

WDL5DL:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	step_end

WL5DL2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	step_end

NorthstarCity_Tournament_4F_Text_GreetingsIfYouveCome:
	.string "{COLOR}{RED}Greetings!\p"
	.string "If you've come to watch the tournament,\n"
	.string "then too bad…\l"
	.string "The tickets have all sold out!\p"
	.string "… Oh? You're here to participate?\n"
	.string "What are your qualifications?\p"
	.string "…\n"
	.string "…\p"
	.string "It appears you are the victor of the\n"
	.string "Laveria Tournament.\l"
	.string "{PLAYER}, right?\p"
	.string "In this case, you do qualify for the\n"
	.string "Northstar TV Station Tournament!\p"
	.string "You're one of the last contestants to\n"
	.string "sign up.\p"
	.string "You ought to bring your best possible\n"
	.string "Pokémon and stock up lots of items\l"
	.string "to prepare for the challenge ahead.\p"
	.string "Seriously - this is going to be tough.\n"
	.string "Are you ready, {PLAYER}?$"

NorthstarCity_Tournament_4F_Text_PleaseComeBack:
	.string "{COLOR}{RED}Please come back when you are ready.$"

NorthstarCity_Tournament_4F_Text_WelcomeBackPlayer:
	.string "{COLOR}{RED}Welcome back, {PLAYER}!\p"
	.string "Are you ready for the tournament?$"

NorthstarCity_Tournament_4F_Text_UnbelievableTheFirstBattle:
	.string "{COLOR}{RED}Unbelievable! The first battle\n"
	.string "concludes explosively!\p"
	.string "Oh, I haven't seen such fire in a\n"
	.string "young Trainer in a long time.\p"
	.string "Hotshot {PLAYER} qualifies\n"
	.string "for the second round! Let's go!$"

NorthstarCity_Tournament_4F_Text_AwhThisIsEmbarrassing:
	.string "{COLOR}{RED}Awh…\p"
	.string "This is embarrassing, losing on live\n"
	.string "TV…\p"
	.string "Anyway, good luck.$"

NorthstarCity_Tournament_4F_Text_HmphICouldntForesee:
	.string "{COLOR}{BLUE}Hmph… I couldn't foresee anything\n"
	.string "like that happening…\p"
	.string "Good luck, {PLAYER}…$"

NorthstarCity_Tournament_4F_Text_OurSecondMatchIsBlackBelt:
	.string "{COLOR}{RED}Our second match is Black Belt Dawson\n"
	.string "against the victor of the first match,\l"
	.string "{PLAYER}!\p"
	.string "I can feel the tension in the air!\n"
	.string "Who will prevail this time?\l"
	.string "Let's find out!\p"
	.string "Camera crew\n"
	.string "Get the lights!$"

NorthstarCity_Tournament_4F_Text_OoohAnOutstandingPerformance:
	.string "{COLOR}{RED}Oooh!\p"
	.string "An outstanding performance in a double\n"
	.string "battle from {PLAYER}!\p"
	.string "I'm beginning to think we have the\n"
	.string "next superstar on our hands…\p"
	.string "Now!\n"
	.string "On to the next round!$"

NorthstarCity_Tournament_4F_Text_WellFought:
	.string "Well fought.\p"
	.string "Your technique is something to be\n"
	.string "admired.\p"
	.string "Keep up the climb…$"

NorthstarCity_Tournament_4F_Text_TheWayYouBattle:
	.string "The way you battle…\p"
	.string "I can now retire happily after battling\n"
	.string "such a skilled Trainer…\p"
	.string "Good luck, young one.$"

NorthstarCity_Tournament_4F_Text_OurSecondMatchOldMan:
	.string "{COLOR}{RED}Our second match is Old Man Alfred\n"
	.string "against the victor of the first match,\l"
	.string "{PLAYER}!\p"
	.string "I can feel the tension in the air!\n"
	.string "Who will prevail this time?\l"
	.string "Let's find out!\p"
	.string "Camera crew!\n"
	.string "Get the lights!$"

NorthstarCity_Tournament_4F_Text_GreatFollowMe:
	.string "{COLOR}{RED}Great!\n"
	.string "Follow me to your position…$"

NorthstarCity_Tournament_4F_Text_YourOpponentAwaits:
	.string "{COLOR}{RED}Your opponent awaits ahead.\n"
	.string "Good luck!$"

NorthstarCity_Tournament_4F_Text_AreWeLiveYet:
	.string "{COLOR}{RED}…\n"
	.string "Are we live yet?\p"
	.string "…\n"
	.string "…\p"
	.string "…\n"
	.string "Oh, we're live?!$"

NorthstarCity_Tournament_4F_Text_GoodEvening:
	.string "{COLOR}{RED}Good evening, ladies and gentlemen!\p"
	.string "Thanks for tuning in to the Northstar\n"
	.string "TV Station Tournament!\l"
	.string "The event you've all been waiting for!\p"
	.string "Strong Trainers from across Tenjo have\n"
	.string "shown up to pit their Pokémon in an\l"
	.string "intense contest of strength and\l"
	.string "stamina, but also intelligence.\p"
	.string "All battles are to be double battles!\n"
	.string "Double battles, double the excitement!\l"
	.string "Am I right?\p"
	.string "Rangers and Aces, Black Belts and\n"
	.string "Battle Girls - who will prove the\l"
	.string "strongest?\p"
	.string "Who will come out on top?\p"
	.string "We're about to find out!$"

NorthstarCity_Tournament_4F_Text_LadiesAndGentlemen:
	.string "{COLOR}{RED}Ladies and gentlemen! I'll bet ¥1000\n"
	.string "that these are the hottest battles\l"
	.string "you've seen in a looong time!\p"
	.string "{PLAYER} earns victory once again!$"

NorthstarCity_Tournament_4F_Text_ISteeredThatBattle:
	.string "{COLOR}{BLUE}I steered that battle right into an\n"
	.string "iceberg.\p"
	.string "Congratulations, {PLAYER}…$"

NorthstarCity_Tournament_4F_Text_ItWasThePressure:
	.string "{COLOR}{BLUE}It was the pressure from being live on\n"
	.string "TV that made me lose. Don't get cocky.$"

NorthstarCity_Tournament_4F_Text_OurThirdMatchAceTrainer:
	.string "{COLOR}{RED}Our third match is Ace Trainer Falter\n"
	.string "against the rising star,\l"
	.string "{PLAYER}!\p"
	.string "Both our contestants have excellent\n"
	.string "winning streaks, so hold onto your\l"
	.string "seats - this getting really serious.\p"
	.string "Begin!$"

NorthstarCity_Tournament_4F_Text_OurThirdMatchSailor:
	.string "{COLOR}{RED}Our third match is Sailor Miguel\n"
	.string "against the rising star,\l"
	.string "{PLAYER}!\p"
	.string "Both our contestants have excellent\n"
	.string "winning streaks, so hold on to your\l"
	.string "seats - this getting really serious.\p"
	.string "Begin!$"

NorthstarCity_Tournament_4F_Text_OurFirstMatchPsychic:
	.string "{COLOR}{RED}Our first match is Psychic Steve\n"
	.string "versus a new hotshot Trainer by the\l"
	.string "name of {PLAYER}!\p"
	.string "Trainers!\n"
	.string "Are you ready?!$"

NorthstarCity_Tournament_4F_Text_DirectorWorkYourMagic:
	.string "{COLOR}{RED}Director! Work your magic!\n"
	.string "Turn on the visual effects!$"

NorthstarCity_Tournament_4F_Text_OurFirstMatchRanger:
	.string "{COLOR}{RED}Our first match is Ranger Marta versus\n"
	.string "a new hotshot Trainer by the name of\l"
	.string "{PLAYER}!\p"
	.string "Trainers!\n"
	.string "Are you ready?!$"

NorthstarCity_Tournament_4F_Text_PlayerWins:
	.string "{COLOR}{RED}{PLAYER} wins the Northstar\n"
	.string "City Tournament!$"

NorthstarCity_Tournament_4F_Text_AndNowThatsOut:
	.string "{COLOR}{RED}And now that that's out of the way,\n"
	.string "we can proceed!$"

NorthstarCity_Tournament_4F_Text_What:
	.string "{COLOR}{RED}…\n"
	.string "W-what?$"

NorthstarCity_Tournament_4F_Text_ComeAgainCentral:
	.string "{COLOR}{RED}Come again, central? A group of --\n"
	.string "…\p"
	.string "…\n"
	.string "…\p"
	.string "Oh, my…\n"
	.string "Put on a commercial break!\p"
	.string "What?! Not happening?!\n"
	.string "What do you mean?$"

NorthstarCity_Tournament_4F_Text_HandOverThatMicrophone:
	.string "Hand over that microphone and step\n"
	.string "aside, lady…$"

NorthstarCity_Tournament_4F_Text_HuhOkayThen:
	.string "Huh…\n"
	.string "Okay, then.\p"
	.string "That microphone of yours is just a\n"
	.string "useless prop, anyway…$"

NorthstarCity_Tournament_4F_Text_HelloHelloTenjo:
	.string "Hello, hello, Tenjo.\n"
	.string "Forgive this brief interruption.\p"
	.string "Not to worry - the battles will go on\n"
	.string "as planned.\p"
	.string "I am Rakaz, and I promise you'll have\n"
	.string "your share of exciting television\l"
	.string "today, ladies and gentlemen.\p"
	.string "We would now just like to spice\n"
	.string "things up a bit… Haha.\p"
	.string "Audience! {PLAYER}.\p"
	.string "You better sit tight and cooperate, as\n"
	.string "we, the SUBO, have the Director of the\l"
	.string "TV Station in our hands.$"

NorthstarCity_Tournament_4F_Text_AsSuchWeAreNow:
	.string "As such, we are now the Directors of\n"
	.string "the show, and this tournament.\p"
	.string "Our tournament, our rules!$"

NorthstarCity_Tournament_4F_Text_YeahItsPaybackTime:
	.string "{COLOR}{BLUE}Yeah!\p"
	.string "It's payback time for what you\n"
	.string "did at the docks!\p"
	.string "I told you we'd be back!$"

NorthstarCity_Tournament_4F_Text_NoThisCantBe:
	.string "{COLOR}{BLUE}No, this can't be happening!\n"
	.string "Sniff…\p"
	.string "We're on live TV, you mindless\n"
	.string "hooligans!$"

NorthstarCity_Tournament_4F_Text_ExactlyAGrandChance:
	.string "Exactly.\p"
	.string "A grand chance to put on a show worthy\n"
	.string "of the Northstar TV Station.\p"
	.string "Now, {PLAYER}.\p"
	.string "Have you ever been a part of a Danger\n"
	.string "Battle before?\l"
	.string "I bet you haven't, but today you will.\p"
	.string "There's one rule that sets a Danger\n"
	.string "Battle apart from a regular battle…\p"
	.string "The loser hands over a Pokémon to the\n"
	.string "winner.\p"
	.string "That's how it is.\p"
	.string "The strong take from the weak.\p"
	.string "Are you a strong one, {PLAYER}?\n"
	.string "Or are you one of the weak?$"

NorthstarCity_Tournament_4F_Text_YouKnowWhyImHere:
	.string "{COLOR}{BLUE}You know why I'm here!\p"
	.string "Boss gave me a second chance to get\n"
	.string "back at you, and I ain't about to\l"
	.string "waste it.\p"
	.string "The rules are clear: The loser hands\n"
	.string "over a Pokémon!\p"
	.string "Come on!$"

NorthstarCity_Tournament_4F_Text_NoNotAgain:
	.string "N-no!\n"
	.string "Not again!$"

NorthstarCity_Tournament_4F_Text_NoILostAgain:
	.string "{COLOR}{BLUE}No!\n"
	.string "I lost again!\p"
	.string "Fine…\n"
	.string "Take the Pokémon.$"

NorthstarCity_Tournament_4F_Text_WeakFool:
	.string "…\n"
	.string "Weak fool.\p"
	.string "You embarrassed yourself, Grunt.\p"
	.string "Even worse, you embarrassed the SUBO\n"
	.string "in front of the whole region…$"

NorthstarCity_Tournament_4F_Text_AndWithThisTrainer:
	.string "…\p"
	.string "And with this Trainer still standing, I\n"
	.string "have no choice but to step in myself--$"

NorthstarCity_Tournament_4F_Text_SirSirTheresTrouble:
	.string "{COLOR}{BLUE}Sir, sir!\n"
	.string "There's trouble downstairs!\p"
	.string "The Director is putting up a fight!\n"
	.string "We need your help!$"

NorthstarCity_Tournament_4F_Text_ItSeemsOurMatch:
	.string "…\p"
	.string "It seems our match will have to\n"
	.string "wait for another time.\p"
	.string "Ladies and gentlemen, the Northstar TV\n"
	.string "Station Tournament concludes!\p"
	.string "The winner is {PLAYER}.\p"
	.string "As much of a disaster as it was for\n"
	.string "The SUBO, it was greatly amusing to\l"
	.string "watch you battle.$"

NorthstarCity_Tournament_4F_Text_ISupposeYouAreLooking:
	.string "I suppose you are looking for a reward\n"
	.string "or something for winning, right?\p"
	.string "Not to worry - you can have this -\n"
	.string "I stole it from someone downstairs.\l"
	.string "It's useless to me, anyway…$"

NorthstarCity_Tournament_4F_Text_UntilWeMeetAgain:
	.string "Until we meet again.$"

NorthstarCity_Tournament_4F_Text_HeyItsMeRose:
	.string "{COLOR}{RED}Hey. It's me.\n"
	.string "Rose, from Greendale.\p"
	.string "The floors downstairs are crawling\n"
	.string "with SUBO filth.\p"
	.string "We'll have to battle our way down.\p"
	.string "Come.$"
