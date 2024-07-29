.set LOCALID_FEMALE_RANGER, 7
.set LOCALID_MALE_RANGER, 8

HighwindVillage_RangersLodge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HighwindVillage_RangersLodge_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HighwindVillage_RangersLodge_OnFrame
	.byte 0

HighwindVillage_RangersLodge_OnTransition:
	setvar VAR_TEMP_B, 5
	end

HighwindVillage_RangersLodge_OnFrame::
	map_script_2 VAR_RANGER_LODGE_STATE, 0, HighwindVillage_RangersLodge_RangerIntro
	.2byte 0

HighwindVillage_RangersLodge_SignCalendar::
	msgbox HighwindVillage_RangersLodge_Text_SignCalendar, MSGBOX_SIGN
	end

HighwindVillage_RangersLodge_RangerIntro::
	lockall
	applymovement LOCALID_MALE_RANGER, Common_Movement_FaceDown
	waitmovement 0
	emote LOCALID_MALE_RANGER, 7
	playse SE_PIN
	waitse
	applymovement LOCALID_FEMALE_RANGER, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_MALE_RANGER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MALE_RANGER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_Ranger
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox HighwindVillage_RangersLodge_Text_HeyThereYouMustBePlayer, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_MALE_RANGER, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername2 CommonName_Text_RangerAlex
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox HighwindVillage_RangersLodge_Text_OhAndThisHereIsRangerMia, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_FEMALE_RANGER, WD2FR
	waitmovement 0
	applymovement LOCALID_FEMALE_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement LOCALID_MALE_RANGER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername CommonName_Text_RangerMia
	showface FS_FEMALE_RANGER, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_RangersLodge_Text_HiPlayerWeveBeenKeeping, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_MALE_RANGER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	speakername2 CommonName_Text_RangerAlex
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox HighwindVillage_RangersLodge_Text_WeveBeenThinking, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_FEMALE_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername CommonName_Text_RangerMia
	showface FS_FEMALE_RANGER, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_RangersLodge_Text_AbsolutelyWeveSeenALot, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_MALE_RANGER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto HighwindVillage_RangersLodge_Intro_Question
	end

HighwindVillage_RangersLodge_Intro_Question::
	speakername2 CommonName_Text_RangerAlex
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox HighwindVillage_RangersLodge_Text_SoWhatDoYouThink, MSGBOX_YESNO
	hideface 0
	closemessage
	compare VAR_RESULT, TRUE
	goto_if_eq HighwindVillage_RangersLodge_Intro_Yes
	speakername2 CommonName_Text_RangerAlex
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox HighwindVillage_RangersLodge_Text_AwComeOn, MSGBOX_AUTOCLOSE
	hideface 0
	goto HighwindVillage_RangersLodge_Intro_Question
	end

HighwindVillage_RangersLodge_Intro_Yes::
	applymovement LOCALID_MALE_RANGER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername2 CommonName_Text_RangerAlex
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox HighwindVillage_RangersLodge_Text_ExcellentWereHonored, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_FEMALE_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername CommonName_Text_RangerMia
	showface FS_FEMALE_RANGER, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_RangersLodge_Text_ThisHereIsYourVeryOwn, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_QUEST_BOOK, 1
	closemessage
	applymovement LOCALID_MALE_RANGER, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	speakername2 CommonName_Text_RangerAlex
	showface FS_MALE_RANGER, FSE_NORMAL, 0, 0
	msgbox HighwindVillage_RangersLodge_Text_WellWedLoveToStayAndChat, MSGBOX_AUTOCLOSE
	hideface 0
	applymovement LOCALID_FEMALE_RANGER, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speakername CommonName_Text_RangerMia
	showface FS_FEMALE_RANGER, FSE_NORMAL, 1, 1
	msgbox HighwindVillage_RangersLodge_Text_SeeYouAroundPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_FEMALE_RANGER, Common_Movement_FaceDown
	waitmovement 0
	removeobject LOCALID_FEMALE_RANGER
	playse SE_EXIT
	waitse
	applymovement LOCALID_MALE_RANGER, WLD
	waitmovement 0
	removeobject LOCALID_MALE_RANGER
	playse SE_EXIT
	waitse
	setflag FLAG_HIDE_RANGER_LODGE_RANGERS
	setvar VAR_RANGER_LODGE_STATE, 1
	releaseall
	end

HighwindVillage_RangersLodge_Ranger_1::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_1, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Ranger_2::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_2, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Ranger_3::
	goto_if_set FLAG_TEMP_1, HighwindVillage_RangersLodge_Ranger_3_Sung
	msgbox HighwindVillage_RangersLodge_Text_Ranger_3_1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

HighwindVillage_RangersLodge_Ranger_3_Sung::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_3_2, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Ranger_4::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_4, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Receptionist::
	msgbox HighwindVillage_RangersLodge_Text_Receptionist, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Ranger_5::
	msgbox HighwindVillage_RangersLodge_Text_HeyThereTrainer, MSGBOX_NPC
	end

QuestBoardScript::
	msgbox HighwindVillage_RangersLodge_Text_PlayerTookALook, MSGBOX_DEFAULT
	openquestmenu
	end
	
QuestBookScript::
	openquestmenu
	end

HighwindVillage_RangersLodge_Text_SignCalendar:
	.string "The calendar is heavily marked with\n"
	.string "various Ranger operations.$"

HighwindVillage_RangersLodge_Text_HeyThereYouMustBePlayer:
	.string "{COLOR}{BLUE}Hey there!\n"
	.string "You must be {PLAYER}, right?\p"
	.string "I heard about your tournament wins on\l"
	.string "TV - seriously impressive stuff!\p"
	.string "I'm Ranger Alex.$"

HighwindVillage_RangersLodge_Text_OhAndThisHereIsRangerMia:
	.string "{COLOR}{BLUE}Oh, and this here is Ranger Mia.$"

HighwindVillage_RangersLodge_Text_HiPlayerWeveBeenKeeping:
	.string "{COLOR}{RED}Hi, {PLAYER}!\n"
	.string "We've been keeping a close eye on you.\p"
	.string "Especially after hearing about how you\n"
	.string "tackled the SUBO in Union City…\l"
	.string "Outstanding work!$"

HighwindVillage_RangersLodge_Text_WeveBeenThinking:
	.string "{COLOR}{BLUE}We've been thinking…\p"
	.string "We believe you've got what it takes to\n"
	.string "join us as a Ranger.\p"
	.string "Your prowess in battles and your\n"
	.string "commitment to Pokémon welfare have\l"
	.string "not gone unnoticed!$"

HighwindVillage_RangersLodge_Text_AbsolutelyWeveSeenALot:
	.string "{COLOR}{RED}Absolutely!\p"
	.string "We've seen a lot of Trainers, but\n"
	.string "your approach is unique.\p"
	.string "Pokémon seem to respond to you in a\n"
	.string "special way.\p"
	.string "Joining the Rangers is about more than\n"
	.string "just battling…\p"
	.string "It's about forging bonds and making a\n"
	.string "real impact.\p"
	.string "We'd be honored to have you.$"

HighwindVillage_RangersLodge_Text_SoWhatDoYouThink:
	.string "{COLOR}{BLUE}So, what do you think, {PLAYER}?\p"
	.string "Ready to take on this new journey as\n"
	.string "a Ranger?$"

HighwindVillage_RangersLodge_Text_AwComeOn:
	.string "{COLOR}{BLUE}Aw. Come on…\n"
	.string "The region depends on you!$"

HighwindVillage_RangersLodge_Text_ExcellentWereHonored:
	.string "{COLOR}{BLUE}Excellent!\n"
	.string "We're honored to have you!$"

HighwindVillage_RangersLodge_Text_ThisHereIsYourVeryOwn:
	.string "{COLOR}{RED}This here is your very own Ranger\n"
	.string "Quest Book.\l"
	.string "It's not just a fancy accessory…\p"
	.string "It records, tracks, and updates all\n"
	.string "the quests that Rangers embark on\l"
	.string "throughout the region.\p"
	.string "Your victories and dedication have set\n"
	.string "you apart.\p"
	.string "We genuinely think you've got the\n"
	.string "potential to be an exceptional Ranger!$"

HighwindVillage_RangersLodge_Text_WellWedLoveToStayAndChat:
	.string "{COLOR}{BLUE}Well, we'd love to stay and chat, but\n"
	.string "we're off to investigate a recent\l"
	.string "explosion in Tamarok Tunnels.\p"
	.string "Hopefully we can clear that up.\p"
	.string "Those SUBO guys will get what's coming\n"
	.string "to them, sooner or later…$"

HighwindVillage_RangersLodge_Text_SeeYouAroundPlayer:
	.string "{COLOR}{RED}See you around, {PLAYER}.\p"
	.string "Feel free to introduce yourself to the\n"
	.string "Rangers up in the Lodge.$"

HighwindVillage_RangersLodge_Text_Ranger_1:
	.string "{COLOR}{BLUE}Whew!\p"
	.string "Nothing like a good meal after a\n"
	.string "hard day's work.\p"
	.string "The Groundskeeper here always takes\n"
	.string "care of us!$"

HighwindVillage_RangersLodge_Text_Ranger_2:
	.string "{COLOR}{RED}I enjoy sitting by the fire here and\n"
	.string "relaxing.\p"
	.string "It's a good change of pace from the\n"
	.string "back-breaking work in the unyielding\l"
	.string "cold and snow outside.$"

HighwindVillage_RangersLodge_Text_Ranger_3_1:
	.string "{COLOR}{BLUE}I am a cider drinker…\n"
	.string "I drinks it all of the day…\p"
	.string "I am a cider drinker…\n"
	.string "It soothes all me troubles away!\p"
	.string "Ooh aah ooh aah ay, ooh aah ooh ay!\n"
	.string "Hick…$"

HighwindVillage_RangersLodge_Text_Ranger_3_2:
	.string "{COLOR}{BLUE}It's so coooozy! Iiin the kitchen!\n"
	.string "With the smell of rabbit stew!\p"
	.string "When the breeze blows 'cross the farm\n"
	.string "yard-- hick!$"

HighwindVillage_RangersLodge_Text_Ranger_4:
	.string "{COLOR}{BLUE}We just got back from a dangerous\n"
	.string "mission in the Tamarok Tunnels.\p"
	.string "Our task was to remove the debris of\n"
	.string "the recent explosion in the caves and\l"
	.string "clear the path that used to be there.\p"
	.string "Sad to say, but we had no luck…\n"
	.string "I'm afraid the way is blocked forever.$"

HighwindVillage_RangersLodge_Text_Receptionist:
	.string "{COLOR}{RED}It's always, always busy in the\n"
	.string "Rangers' Lodge.\p"
	.string "Some Rangers work night shifts, others\n"
	.string "work during the day.\p"
	.string "It doesn't matter what hour it is -\n"
	.string "there's bound to be one or two Rangers\l"
	.string "hanging around here.\p"
	.string "For this reason, the fires of the\n"
	.string "hearth must be kept up at all times.$"

HighwindVillage_RangersLodge_Text_HeyThereTrainer:
	.string "{COLOR}{RED}Hey there, Trainer!\n"
	.string "Welcome to the Ranger's Lodge!\p"
	.string "Did you notice the grand Noctowl\n"
	.string "statue at the entrance?\p"
	.string "Noctowl is our guardian here, known\n"
	.string "for its keen senses and wisdom.\p"
	.string "It's known to collect Gleaming Seeds,\n"
	.string "rare treasures found in the wild.\p"
	.string "Noctowl appear where Gleaming Seeds\n"
	.string "can be found, and their presence is a\l"
	.string "sign of the seeds' magical properties.\p"
	.string "If you're on the lookout for Noctowl,\n"
	.string "follow the trail of Gleaming Seeds.\p"
	.string "That's some free Ranger knowledge!\n"
	.string "Hehehe.$"

HighwindVillage_RangersLodge_Text_PlayerTookALook:
	.string "{PLAYER} took a closer look at the\n"
	.string "Quest board.$"
