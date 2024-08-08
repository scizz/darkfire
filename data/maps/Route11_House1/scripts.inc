.set LOCALID_ERNIE, 1
.set LOCALID_PIKATRON, 2

Route11_House1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route11_House1_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_House1_OnTransition
	.byte 0

Route11_House1_OnFrame:
	map_script_2 VAR_ERNIE_STATE, 1, Route11_House1_ErnieEvent
	.2byte 0

Route11_House1_OnTransition:
	goto_if_set FLAG_SYS_DEXNAV_GET, Route11_House1_MoveObjects
	end

Route11_House1_MoveObjects::
	setobjectxyperm LOCALID_ERNIE, 8, 8
	setobjectxyperm LOCALID_PIKATRON, 3, 4
	setobjectmovementtype LOCALID_ERNIE, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_PIKATRON, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	end

Route11_House1_SignEmail::
	msgbox YouCheckOutWhatAppears, MSGBOX_SIGN
	end

Route11_House1_SignTheseAppear::
	msgbox TheseAppearToBeSchematics, MSGBOX_SIGN
	end

Route11_House1_ATreatise::
	msgbox ATreatiseToParallelUniverses, MSGBOX_SIGN
	end

Route11_House1_Chapter6::
	msgbox Chapter6QuantumMechanics, MSGBOX_SIGN
	end

Route11_House1_Plaque::
	msgbox PlaqueErnieLumeriaCity, MSGBOX_SIGN
	end

Route11_House1_Certificate::
	msgbox CertificateErnieLumeriaCity, MSGBOX_SIGN
	end

Route11_House1_ComplicatedBooks::
	msgbox Text_ComplicatedBooks, MSGBOX_SIGN
	end	

Route11_House1_ErnieEvent::
	lock
	applymovement LOCALID_ERNIE, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	emote LOCALID_ERNIE, 8
	waitse
	applymovement LOCALID_ERNIE, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername SpeakerName_Text_QuestionMark
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieOhMyGoodnessAVisitor, MSGBOX_AUTOCLOSE
	hideface 1
	setvar VAR_ERNIE_STATE, 2
	release
	end

Route11_House1_ErnieObject::
	lock
	faceplayer
	goto_if_set FLAG_SYS_DEXNAV_GET, Route11_House1_ErnieObjectGiven
	speakername SpeakerName_Text_QuestionMark
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieItsBeenAgesSinceAnyoneHasCome, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_ERNIE, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_PIKATRON, Common_Movement_FaceDown
	waitmovement 0
	delay 10
	speakername CommonName_Text_Ernie
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieAndThisIsPikatron, MSGBOX_AUTOCLOSE
	hideface 1
	playse SE_PIN
	emote LOCALID_PIKATRON, 5
	waitse
	speakername2 CommonName_Text_Pikatron
	showface FS_PIKATRON, FSE_NORMAL, 0, 0
	playse SE_PIN
	msgbox PikatronHiWelcome, MSGBOX_AUTOCLOSE
	waitse
	hideface 0
	playse SE_CARD
	emote LOCALID_ERNIE, 1
	waitse
	applymovement LOCALID_ERNIE, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Ernie
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieHeheMaybeLater, MSGBOX_AUTOCLOSE
	hideface 1
	delay 10
	applymovement LOCALID_ERNIE, Common_Movement_FaceUp
	waitmovement 0
	delay 10
	speakername CommonName_Text_Ernie
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieOhThisDontMindThat, MSGBOX_AUTOCLOSE
	hideface 1
	playse SE_PIN
	applymovement LOCALID_PIKATRON, Common_Movement_WalkInPlaceLeft
	speakername2 CommonName_Text_Pikatron
	showface FS_PIKATRON, FSE_NORMAL, 0, 0
	msgbox PikatronSuccessMyMiniRocket, MSGBOX_AUTOCLOSE
	hideface 0
	waitmovement 0
	applymovement LOCALID_ERNIE, Common_Movement_FaceRight
	waitmovement 0
	playse SE_PIN
	emote LOCALID_ERNIE, 8
	waitse
	applymovement LOCALID_ERNIE, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	speakername CommonName_Text_Ernie
	showface FS_ERNIE, FSE_SHOCKED, 1, 1
	msgbox ErnieOkayPikatron, MSGBOX_AUTOCLOSE
	hideface 1
	playse SE_CARD
	waitse 
	applymovement LOCALID_PIKATRON, WR3U4L5D
	waitmovement 0
	setobjectnewmovementtype LOCALID_PIKATRON, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	release
	applymovement LOCALID_ERNIE, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	emote LOCALID_ERNIE, 7
	waitse
	applymovement LOCALID_ERNIE, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	speakername CommonName_Text_Ernie
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieWaitAMinuteYourePlayer, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_DEXNAV, 1
	speakername CommonName_Text_Ernie
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieICouldntForTheLifeOfMe, MSGBOX_AUTOCLOSE
	hideface 1
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_SYS_PC_LANETTE
	setvar VAR_ERNIE_STATE, 2
	end

Route11_House1_ErnieObjectGiven::
	speakername CommonName_Text_Ernie
	showface FS_ERNIE, FSE_NORMAL, 1, 1
	msgbox ErnieHeyPlayerIfYouNeedFurtherInstructions, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

Route11_House1_Pikatron::
	lock
	faceplayer
	playse SE_CARD
	speakername CommonName_Text_Pikatron
	showface FS_PIKATRON, FSE_NORMAL, 1, 1
	msgbox PikatronHelloTrainer, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

WR3U4L5D:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

YouCheckOutWhatAppears:
	.string "You check out what appears to be an\n"
	.string "email Ernie has been writing…\p"
	.string "“Hi, Sis. I hope you're well.\n"
	.string "Has your condition worsened?\p"
	.string "Is there anything you need?\n"
	.string "Say the word and I'll drop by!”$"

TheseAppearToBeSchematics:
	.string "These appear to be schematics for a\n"
	.string "robotic companion Ernie is building.\p"
	.string "“B9 Archetype” is written on top.$"

ATreatiseToParallelUniverses:
	.string "A treatise to parallel universes…\n"
	.string "Five quick ways to easily alter the\l"
	.string "world timeline!\p"
	.string "Disclaimer: Author is not liable if\n"
	.string "you completely shatter the timeline.$"

Chapter6QuantumMechanics:
	.string "Chapter 6, Quantum Mechanics Observer\n"
	.string "Effect: Observing quantum phenomena\l"
	.string "changes the result of measurements!$"

PlaqueErnieLumeriaCity:
	.string "It's a plaque addressed to Ernie.\p"
	.string "It's a computer science degree from\n"
	.string "Lumeria City's university!$"

CertificateErnieLumeriaCity:
	.string "Certificate for Math Brilliance\p"
	.string "{FONT_SMALL}Presented to Our Most Remarkable Mathlete,\n"
	.string "Ernest Ware, Lumeria Junior High School$"

Text_ComplicatedBooks:
	.string "Complicated books are arranged neatly\n"
	.string "and in alphabetical order…$"

ErnieOhMyGoodnessAVisitor:
	.string "{COLOR}{BLUE}Oh, my goodness!\n"
	.string "A visitor!\p"
	.string "Please, come on in!$"

HowToUseDexNavPlusPlus:
	.string "DexNav++ User Manual\n"
	.string "{FONT_SMALL}Table of Contents$"

DexNavManualHowToUse:
	.string "DexNav++ is a tool created to make\n"
	.string "finding specific Pokémon easier.\p"
	.string "The device comes with two modes:\n"
	.string "Search Mode and Detector Mode.\p"
	.string "Simply open your DexNav++ to view the\n"
	.string "available Pokémon in your area.\p"
	.string "Only Pokémon that you've already seen\n"
	.string "will be available in Search Mode.$"

DexNavManualSearchMode:
	.string "In Search Mode, simply highlight the\n"
	.string "Pokémon you want to search, and press\l"
	.string "the A Button to start a search for it.\p"
	.sting "If you want to search for the same\n"
	.string "Pokémon quickly, you can register them\l"
	.string "as a quick-search by highlighting the\l"
	.string "Pokémon and pressing the R Button.\p"
	.string "Once registered, you can close your\n"
	.string "DexNav++ and press the R Button again\l"
	.string "to quick-search that Pokémon.\p"
	.string "Remember, once your DexNav++ finds a\n"
	.string "Pokémon that is hiding, you must hold\l"
	.string "the A Button to creep, or it'll flee!$"

DexNavManualDetectorMode:
	.string "Detector Mode is currently disabled.\p"
	.string "The mode can only be unlocked manually\n"
	.string "by Ernie.\p"
	.string "It is reserved only for the most elite\n"
	.string "Trainers.$"

DexNavManualChaining:
	.string "When your DexNav++ searches a Pokémon,\n"
	.string "data on that Pokémon will appear in\l"
	.string "the bottom of the screen.\p"
	.string "The data may also include information\n"
	.string "on its held item, ability, or moves.\p"
	.string "In the bottom right of the screen, you\n"
	.string "will see a number.\p"
	.string "This number is your Chain Value.\p"
	.string "Your Chain Value will increase by 1 if\n"
	.string "you complete a search on a specific\l"
	.string "Pokémon multiple times.\p"
	.string "You can do this by either by capturing\n"
	.string "or fainting the Pokémon.\p"
	.string "Registering a Pokémon in Search Mode\n"
	.string "will make Chaining easier.\p"
	.string "The higher the chain value, the more\n"
	.string "valuable the Pokémon you may discover,\l"
	.string "with increased odds of it being shiny!$"

ErnieItsBeenAgesSinceAnyoneHasCome:
	.string "{COLOR}{BLUE}It's been ages since anyone has come\n"
	.string "this far out.\p"
	.string "I'm Ernie, by the way!\p"
	.string "I'm the one who designed Tenjo's\n"
	.string "Pokémon Storage System!$"

ErnieAndThisIsPikatron:
	.string "{COLOR}{BLUE}And this is P1KATR0N 5000, my\n"
	.string "electronic buddy.\p"
	.string "Say hi, P1KATR0N!$"

PikatronHiWelcome:
	.string "HI! WELCOME.\p"
	.string "I SEE YOU ARE A TRAINER.\p"
	.string "I HAPPEN TO BE A TRAINER, TOO.\p"
	.string "BATTLE ME NOW!$"

ErnieHeheMaybeLater:
	.string "{COLOR}{BLUE}Hehe, maybe later.\p"
	.string "I installed a battling module and now\n"
	.string "he challenges every Trainer he sees.$"

ErnieOhThisDontMindThat:
	.string "{COLOR}{BLUE}Oh, this?\p"
	.string "Don't mind that.\p"
	.string "We just got done with an experiment.\n"
	.string "It was a complete failu--$"

PikatronSuccessMyMiniRocket:
	.string "SUCCESS!\p"
	.string "MY MINI-ROCKET COMPARTMENTS ARE NOW\n"
	.string "LARGE ENOUGH TO LAUNCH INCREDIBLE\l"
	.string "AMOUNTS OF DEVASTATION!$"

ErnieOkayPikatron:
	.string "{COLOR}{BLUE}O-kay, P1KATR0N…\p"
	.string "Go clean up this rubble before you\n"
	.string "scare away our only guest in forever…$"

ErnieWaitAMinuteYourePlayer:
	.string "{COLOR}{BLUE}Wait a minute… You're {PLAYER}!\n"
	.string "Winner of the Northstar Tournament!\p"
	.string "I watched you on TV!\n"
	.string "Your battles were extraordinary!\p"
	.string "To think a celebrity like you would\n"
	.string "end up here…\l"
	.string "This is truly a special day.\p"
	.string "I've been working on something that I\n"
	.string "believe will be incredibly useful to a\l"
	.string "Trainer of your caliber.\p"
	.string "It's called DexNav++.\p"
	.string "It's a re-creation of a piece of\n"
	.string "high-tech hardware from Hoenn.\p"
	.string "This device shares information about\n"
	.string "the wild Pokémon in any current area\l"
	.string "and searches out specific Pokémon.\p"
	.string "It's my greatest work yet, and I can't\n"
	.string "think of anyone more deserving of it.\p"
	.string "Take it - I insist!$"

ErnieICouldntForTheLifeOfMe:
	.string "{COLOR}{BLUE}I could never understand why more\n"
	.string "Trainers aren't using Hoenn's DexNav…\l"
	.string "So I made my own version of it!\p"
	.string "I hope this helps you on your journey.\p"
	.string "Safe travels, {PLAYER}.\p"
	.string "May the DexNav++ serve you well in\n"
	.string "your adventures!$"

ErnieHeyPlayerIfYouNeedFurtherInstructions:
	.string "{COLOR}{BLUE}Hey, {PLAYER}!\p"
	.string "If you need further instructions on\n"
	.string "how to use the DexNav++, check the\l"
	.string "red manual over there on my desk.$"

PikatronHelloTrainer:
	.string "HELLO, TRAINER.\p"
	.string "I MUST BATTLE YOU.\p"
	.string "AFTER I CLEAN UP THIS MESS.$"
