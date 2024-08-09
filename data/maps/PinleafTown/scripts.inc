.set LOCALID_TYLER, 2

PinleafTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PinleafTown_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, PinleafTown_OnTransition
	.byte 0

PinleafTown_OnFrame:
	map_script_2 VAR_STORYLINE_STATE, 40, PinleafTown_TylerBattle
	.2byte 0

PinleafTown_OnTransition:
	setrespawn HEAL_LOCATION_PINLEAF_TOWN
	compare VAR_STORYLINE_STATE, 39
	goto_if_le PinleafTown_HideTyler
	compare VAR_STORYLINE_STATE, 40
	goto_if_eq PinleafTown_ShowTyler
	goto_if_set FLAG_HIDE_PINLEAF_TOWN_SUDOWOODO_1, PinleafTown_HideSubo
	goto_if_set FLAG_HIDE_PINLEAF_TOWN_SUDOWOODO_2, PinleafTown_HideSubo
	end

PinleafTown_HideTyler::
	removeobject LOCALID_TYLER
	setflag FLAG_HIDE_PINLEAF_TOWN_TYLER
	end

PinleafTown_ShowTyler::
	clearflag FLAG_HIDE_PINLEAF_TOWN_TYLER
	addobject LOCALID_TYLER
	return

PinleafTown_HideSubo::
	removeobject 20
	removeobject 21
	setflag FLAG_HIDE_PINLEAF_TOWN_SUBO
	end

PinleafTown_TylerBattle::
	lock
	applymovement LOCALID_TYLER, Common_Movement_FaceRight
	waitmovement 0
	emote LOCALID_TYLER, 7
	playse SE_PIN
	waitse
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_SHOCKED, 1, 1
	msgbox PinleafTown_Text_WoahHeyNoWayPlayer, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_TYLER, WR3
	waitmovement 0
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_NORMAL, 1, 1
	msgbox PinleafTown_Text_WellWellLookWhoItIs, MSGBOX_AUTOCLOSE
	hideface 1
	goto_if_set FLAG_TAKEN_PIKACHU, PinleafTown_TylerBattle_Eevee
	trainerbattle_no_intro TRAINER_TYLER_6, Tyler3_Text_Defeated
	goto PinleafTown_TylerBattle_End
	end

PinleafTown_TylerBattle_Eevee::
	trainerbattle_no_intro TRAINER_TYLER_5, Tyler3_Text_Defeated
	goto PinleafTown_TylerBattle_End
	end

PinleafTown_TylerBattle_End::
	applymovement LOCALID_TYLER, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	speakername CommonName_Text_Tyler
	showface FS_TYLER, FSE_HAPPY, 1, 1
	msgbox PinleafTown_Text_WellPlayerYouCertainly, MSGBOX_AUTOCLOSE
	hideface 1
	applymovement LOCALID_TYLER, WR4D5
	waitmovement 0
	removeobject LOCALID_TYLER
	setflag FLAG_HIDE_PINLEAF_TOWN_TYLER
	setvar VAR_STORYLINE_STATE, 41
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

PinleafTown_Sign::
	msgbox PinleafTown_Text_Sign, MSGBOX_SIGN
	end

PinleafTown_Sign_Inn::
	msgbox PinleafTown_Text_Sign_Inn, MSGBOX_SIGN
	end

PinleafTown_Sign_Letterbox::
	msgbox PinleafTown_Text_Sign_Letterbox, MSGBOX_SIGN
	end

PinleafTown_Vendor::
	msgbox PinleafTown_Text_Vendor, MSGBOX_NPC
	end

PinleafTown_Woman::
	msgbox PinleafTown_Text_Woman, MSGBOX_NPC
	end

PinleafTown_Man_1::
	msgbox PinleafTown_Text_Man_1, MSGBOX_NPC
	end

PinleafTown_Little_Girl::
	msgbox PinleafTown_Text_Little_Girl, MSGBOX_NPC
	end

PinleafTown_Little_Ace_Trainer::
	msgbox PinleafTown_Text_Little_Ace_Trainer, MSGBOX_NPC
	end

PinleafTown_Guitarist::
	msgbox PinleafTown_Text_Guitarist, MSGBOX_NPC
	end

PinleafTown_Man_2::
	msgbox PinleafTown_Text_Man_2, MSGBOX_NPC
	end

PinleafTown_Old_Man::
	msgbox PinleafTown_Text_Old_Man, MSGBOX_NPC
	end

PinleafTown_SUBO_1::
	lock
	faceplayer
	speakername CommonName_Text_SuboGrunt
	showface FS_FEMALE_SUBO, FSE_NORMAL, 1, 1
	msgbox PinleafTown_Text_SUBO_1, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

PinleafTown_SUBO_2::
	lock
	faceplayer
	speakername CommonName_Text_SuboGrunt
	showface FS_MALE_SUBO, FSE_NORMAL, 1, 1
	msgbox PinleafTown_Text_SUBO_2, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

PinleafTown_SUBO_3::
	msgbox PinleafTown_Text_SUBO_3, MSGBOX_NPC
	end

PinleafTown_Maniac::
	msgbox PinleafTown_Text_Maniac, MSGBOX_NPC
	end

PinleafTown_Flower_Girl::
	msgbox PinleafTown_Text_Flower_Girl, MSGBOX_NPC
	end

PinleafTown_Fat_Guy::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_PINLEAF_PP_UP, PinleafTown_Fat_Guy_Given
	msgbox PinleafTown_Text_Fat_Guy MSGBOX_NPC
	giveitem ITEM_PP_UP, 1
	setflag FLAG_RECEIVED_PINLEAF_PP_UP
	goto PinleafTown_Fat_Guy_Given

PinleafTown_Fat_Guy_Given::
	msgbox PinleafTown_Text_Fat_Guy_Given, MSGBOX_DEFAULT
	releaseall
	end

PinleafTown_Old_Lady::
	msgbox PinleafTown_Text_Old_Lady, MSGBOX_NPC
	end

PinleafTown_Son::
	msgbox PinleafTown_Text_Son, MSGBOX_NPC
	end

PinleafTown_Natu::
	lock
	playmoncry SPECIES_NATU, 0
	speakername CommonName_Text_Natu
	msgbox PinleafTown_Text_Natu, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

PinleafTown_Sudowoodo1::
	lock
	playmoncry SPECIES_SUDOWOODO, 0
	speakername CommonName_Text_Sudowoodo
	msgbox PinleafTown_Text_Sudowoodo, MSGBOX_AUTOCLOSE
	waitmoncry
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, TRUE, PinleafTown_SudowoodoWater1
	release
	end

PinleafTown_SudowoodoWater1::
	msgbox UseTheWailmerPailOnSudowoodo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PinleafTown_SudowoodoWaterNo
	closemessage
	special DoWateringBerryTreeAnim
	waitstate
	message SudowoodoDislikesBeingSprayed
	waitmessage
	waitbuttonpress
	setwildbattle SPECIES_SUDOWOODO, 20, ITEM_RAZZ_BERRY
	dowildbattle
	playmoncry SPECIES_SUDOWOODO, 1
	waitmoncry
	fadescreenswapbuffers FADE_TO_BLACK
	delay 60
	removeobject 22
	setflag FLAG_HIDE_PINLEAF_TOWN_SUDOWOODO_1
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

PinleafTown_Sudowoodo2::
	lock
	playmoncry SPECIES_SUDOWOODO, 0
	speakername CommonName_Text_Sudowoodo
	msgbox PinleafTown_Text_Sudowoodo, MSGBOX_AUTOCLOSE
	waitmoncry
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, TRUE, PinleafTown_SudowoodoWater2
	release
	end

PinleafTown_SudowoodoWater2::
	msgbox UseTheWailmerPailOnSudowoodo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PinleafTown_SudowoodoWaterNo
	closemessage
	special DoWateringBerryTreeAnim
	waitstate
	message SudowoodoDislikesBeingSprayed
	waitmessage
	waitbuttonpress
	setwildbattle SPECIES_SUDOWOODO, 21, ITEM_ORAN_BERRY
	dowildbattle
	playmoncry SPECIES_SUDOWOODO, 1
	waitmoncry
	fadescreenswapbuffers FADE_TO_BLACK
	delay 60
	removeobject 23
	setflag FLAG_HIDE_PINLEAF_TOWN_SUDOWOODO_1
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

PinleafTown_Sudowoodo3::
	lock
	playmoncry SPECIES_SUDOWOODO, 0
	speakername CommonName_Text_Sudowoodo
	msgbox PinleafTown_Text_Sudowoodo, MSGBOX_AUTOCLOSE
	waitmoncry
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, TRUE, PinleafTown_SudowoodoWater3
	release
	end

PinleafTown_SudowoodoWater3::
	msgbox UseTheWailmerPailOnSudowoodo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PinleafTown_SudowoodoWaterNo
	closemessage
	special DoWateringBerryTreeAnim
	waitstate
	message SudowoodoDislikesBeingSprayed
	waitmessage
	waitbuttonpress
	setwildbattle SPECIES_SUDOWOODO, 19, ITEM_SITRUS_BERRY
	dowildbattle
	playmoncry SPECIES_SUDOWOODO, 1
	waitmoncry
	fadescreenswapbuffers FADE_TO_BLACK
	delay 60
	removeobject 19
	setflag FLAG_HIDE_PINLEAF_TOWN_SUDOWOODO_1
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

PinleafTown_SudowoodoWaterNo::
	closemessage
	release
	end

PinleafTown_EventScript_Bambi::
	trainerbattle_single TRAINER_DAPHNE, PinleafTown_Text_CowgirlIntro, PinleafTown_Text_CowgirlDefeated
	msgbox PinleafTown_Text_CowgirlPostBattle, MSGBOX_AUTOCLOSE
	end

PinleafTown_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, PinleafTown_Text_RancherIntro, PinleafTown_Text_RancherDefeated
	msgbox PinleafTown_Text_RancherPostBattle, MSGBOX_AUTOCLOSE
	end

PinleafTown_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PinleafTown_Text_BugCatcherIntro, PinleafTown_Text_BugCatcherDefeated
	msgbox PinleafTown_Text_BugCatcherPostBattle, MSGBOX_AUTOCLOSE
	end

WR3:
	walk_right
	walk_right
	walk_right
	step_end
	
WR4D5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PinleafTown_Text_Sign:
	.string "Pinleaf Town\n"
	.string "{FONT_SMALL}“Where Crops Sprout and Adventures Bloom!”$"

PinleafTown_Text_Sign_Inn:
	.string "Pinleaf Inn\n"
	.string "{FONT_SMALL}“Where Tranquility Meets Recovery”$"

PinleafTown_Text_Sign_Letterbox:
	.string "It's empty.$"

PinleafTown_Text_Vendor:
	.string "{COLOR}{BLUE}Hi, Trainer!\p"
	.string "The owner of this house recently moved\n"
	.string "out.\p"
	.string "I am just here with my team getting\n"
	.string "it cleaned up and ready to be sold!\p"
	.string "If you're interested in purchasing the\n"
	.string "house, please check back later.$"

PinleafTown_Text_Woman:
	.string "{COLOR}{RED}There used to be a bus station here,\n"
	.string "but there's been some trouble over in\l"
	.string "Mayhem City with the SUBO.\p"
	.string "For that reason, I suppose the bus\n"
	.string "won't be coming around here anymore…$"

PinleafTown_Text_Man_1:
	.string "{COLOR}{BLUE}Word of advice, Trainer.\p"
	.string "Stay on guard in Pinleaf Town, because\n"
	.string "there are Trainers looking to battle.$"

PinleafTown_Text_Little_Girl:
	.string "{COLOR}{RED}The countryside's pretty, but I really\n"
	.string "wanna move to the city when I grow up!$"

PinleafTown_Text_Little_Ace_Trainer:
	.string "{COLOR}{BLUE}I'm just passing through here, but\n"
	.string "here's a quick heads up.\p"
	.string "There are Trainers in this town looking\n"
	.string "to battle, so be on your guard.$"

PinleafTown_Text_Guitarist:
	.string "{COLOR}{BLUE}This town doesn't have a PokéCenter\n"
	.string "or PokéMart.\p"
	.string "Instead, we got this shop over here\n"
	.string "and there's an Inn just north.$"

PinleafTown_Text_Man_2:
	.string "{COLOR}{BLUE}This here's Mowell Farm, and I'm Mr.\n"
	.string "Mowell.\p"
	.string "We ain't the largest farm in Pinleaf,\n"
	.string "but we're sure the proudest one!\p"
	.string "We don't tolerate intruders, though.\n"
	.string "Especially with all the crop theft\l"
	.string "going on around recently!$"

PinleafTown_Text_Old_Man:
	.string "Used to be real quiet around here…\p"
	.string "Now with all those SUBO running around\n"
	.string "and Pokémon invading our crops, things\l"
	.string "have changed too much!$"

PinleafTown_Text_SUBO_1:
	.string "{COLOR}{RED}Hey! Can't you see we're busy here?!\n"
	.string "Leave us alone, you bully!$"

PinleafTown_Text_SUBO_2:
	.string "{COLOR}{BLUE}What are you lookin' at, kiddo?\p"
	.string "We ain't goin' anywhere, so you might\n"
	.string "wanna turn ‘round and leave!$"

PinleafTown_Text_SUBO_3:
	.string "{COLOR}{BLUE}What is going on here?\p"
	.string "How am I supposed to sneak around with\n"
	.string "these weird things blocking the way?!$"

PinleafTown_Text_Maniac:
	.string "Say…\n"
	.string "Is that the Northstar City Badge?\p"
	.string "You ought to go visit the Rangers'\n"
	.string "Federation Lodge in Highwind Village.\p"
	.string "I'm certain they will let a Trainer\n"
	.string "of your calibre inside.$"

PinleafTown_Text_Flower_Girl:
	.string "{COLOR}{RED}The flowers are so beautiful around\n"
	.string "here!\p"
	.string "I chose to work at the Flower &\n"
	.string "Berry Shop for this reason.$"

PinleafTown_Text_Fat_Guy:
	.string "{COLOR}{BLUE}I am so glad the Sudowoodo have been\n"
	.string "dealt with…\p"
	.string "I was trying to get to the Inn for\n"
	.string "some food and a quick nap, but I could\l"
	.string "not find a way past the darned things.\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Wait, it was you who dealt with them?!\n"
	.string "Incredible!\p"
	.string "Take this as a token of my thanks!$"

PinleafTown_Text_Fat_Guy_Given:
	.string "{COLOR}{BLUE}PP Up, as the name suggests, raises\n"
	.string "the base PP of your Pokémon's move.\p"
	.string "It also increases the Pokémon's\n"
	.string "happiness a little!$"

PinleafTown_Text_Old_Lady:
	.string "Welcome to Longfield Farm, child.\p"
	.string "I heard folk all around Pinleaf are\n"
	.string "having problems, but not this farm.\p"
	.string "My Grandson is looking out for us,\n"
	.string "and he is pretty strong.$"

PinleafTown_Text_Son:
	.string "{COLOR}{BLUE}My grandparents' farm, Longfield Farm,\n"
	.string "has been around for generations.\p"
	.string "This is where I learned to care for\n"
	.string "Pokémon with the same love they showed\l"
	.string "for their crops…$"

PinleafTown_Text_WoahHeyNoWayPlayer:
	.string "{COLOR}{BLUE}Woah! Hey! No way!\n"
	.string "{PLAYER}!$"

PinleafTown_Text_WellWellLookWhoItIs:
	.string "{COLOR}{BLUE}Well, well - look who it is!\n"
	.string "It's been a long time, {PLAYER}!\p"
	.string "I saw you on the TV earlier!\p"
	.string "You're really the Northstar City\n"
	.string "Champion? That's pretty neat!\p"
	.string "While you've been getting all the\n"
	.string "attention, I've been stalking these\l"
	.string "SUBO guys.\p"
	.string "They followed a Goverment Official up\n"
	.string "north and then set sail with him!\p"
	.string "How can people not see that the\n"
	.string "Government and the SUBO are allies?!\p"
	.string "Anyway, {PLAYER}, I followed the\n"
	.string "SUBO into Mayhem City.\p"
	.string "I gotta say, there's some terrible\n"
	.string "things happening there!\p"
	.string "They seem to have some blueprint of\n"
	.string "some sort…\l"
	.string "I couldn't quite see from afar…\p"
	.string "But, there was a Scientist-looking guy\n"
	.string "engineering a weird machine…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "…\n"
	.string "I'm blabbing on, aren't I?\l"
	.string "I always do that! Ha!\p"
	.string "Well, I will continue to do my bit.\n"
	.string "I'll get to the bottom of this!\p"
	.string "In the meantime, you know what time\n"
	.string "it is, {PLAYER}!\l"
	.string "Prepare to battle!$"

PinleafTown_Text_WellPlayerYouCertainly:
	.string "{COLOR}{BLUE}Well, {PLAYER}!\n"
	.string "You certainly know how to battle.\p"
	.string "I will continue to get stronger…\p"
	.string "I'm gonna need it if I'm going to\n"
	.string "take down the SUBO!\p"
	.string "Oh, also…\p"
	.string "Go see the Flower Shop here, they'll\n"
	.string "be sure to give you something good!\p"
	.string "Take care and watch your back.\n"
	.string "We will cross paths again soon!$"

PinleafTown_Text_Natu:
	.string "Natuu!$"

PinleafTown_Text_Sudowoodo:
	.string "Sudo, sudoo!$"

UseTheWailmerPailOnSudowoodo:
	.string "Use the Wailmer Pail on Sudowoodo?$"

SudowoodoDislikesBeingSprayed:
	.string "Sudowoodo dislikes being sprayed!\p"
	.string "Sudowoodo attacked!$"
