.set LOCALID_HIKER, 1

LaveriaCity_Interlink_MapScripts::
	.byte 0

LaveriaCity_Route7_State::
	lock
	applymovement LOCALID_HIKER, Common_Movement_FaceLeft
	waitmovement 0
	emote LOCALID_HIKER, 7
	playse SE_PIN
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCALID_HIKER, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox LaveriaCity_Route7_Text_HeyYou, MSGBOX_AUTOCLOSE
	applymovement LOCALID_HIKER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkRight
	waitmovement 0
	release
	end

LaveriaCity_Interlink_Hiker::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE02_GET, LaveriaCity_Interlink_Hiker_Received
	msgbox LaveriaCity_Interlink_Text_Hiker, MSGBOX_DEFAULT
	releaseall
	end

LaveriaCity_Interlink_Hiker_Received::
	msgbox LaveriaCity_Interlink_Text_Hiker_Received, MSGBOX_DEFAULT
	releaseall
	end

LaveriaCity_Interlink_Woman::
	msgbox LaveriaCity_Text_Interlink_Woman, MSGBOX_NPC
	end

LaveriaCity_Interlink_Little_Boy::
	msgbox LaveriaCity_Text_Interlink_Little_Boy, MSGBOX_NPC
	end

LaveriaCity_Interlink_Girl::
	msgbox LaveriaCity_Text_Interlink_Girl, MSGBOX_NPC
	end

LaveriaCity_Interlink_Aide::
	lock
	faceplayer
	goto_if_set FLAG_PROF_AIDE_LAVERIA_DOWSING_MCHN, LaveriaCity_Interlink_AideGiveDowsingMachine_Given
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox LaveriaCity_Interlink_Text_Aide_HelloImProfessor, MSGBOX_AUTOCLOSE
	hideface 1
	compare VAR_0x8009, 20
	goto_if_ge LaveriaCity_Interlink_AideGiveDowsingMachine
	emote 4, 2
	playse SE_PIN
	waitse
	delay 60
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox LaveriaCity_Interlink_Text_Aide_CatchMoreMons, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

LaveriaCity_Interlink_AideGiveDowsingMachine::
	emote 4, 1
	playse SE_PIN
	waitse
	delay 60
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox UnionCity_Interlink_Text_Aide_CongratulationsHeresYourReward, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_DOWSING_MACHINE, 1
	setflag FLAG_PROF_AIDE_LAVERIA_DOWSING_MCHN
	goto LaveriaCity_Interlink_AideGiveDowsingMachine_Given
	end

LaveriaCity_Interlink_AideGiveDowsingMachine_Given::
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox LaveriaCity_Interlink_Text_Aide_TheDowsingMachine, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

LaveriaCity_Interlink_Text_Hiker:
	.string "I'm on strict orders to deny any\n"
	.string "rookie Trainers passin' by here!\p"
	.string "Beat the Laveria City Champion and I\n"
	.string "will consider lettin' ya through!$"

LaveriaCity_Interlink_Text_Hiker_Received:
	.string "That Badge…\p"
	.string "So ya beat the Laveria City Champion,\n"
	.string "after all?\p"
	.string "Props to ya, kid!\n"
	.string "You can go through to Mt. Tamarok.\p"
	.string "Good luck - you'll need it! Hahaha.$"

LaveriaCity_Text_Interlink_Woman:
	.string "{COLOR}{RED}I dropped some items down into the\n"
	.string "Steep Ravine…\p"
	.string "I would abseil down there to retrieve\n"
	.string "them, but the rope doesn't feel safe.\p"
	.string "Oh, well…\p"
	.string "I'll leave them for someone else to\n"
	.string "discover…$"

LaveriaCity_Text_Interlink_Little_Boy:
	.string "{COLOR}{BLUE}I know everything about Eevee!\p"
	.string "Ice Stone evolves Eevee to Glaceon.\n"
	.string "Fire Stone evolves it to Flareon.\p"
	.string "Leaf Stone turns it into Leafeon,\n"
	.string "and Water Stone makes Vaporeon.\p"
	.string "Thunder Stone? Jolteon!\n"
	.string "And Moon Stone will get you Umbreon.\p"
	.string "But, Sun Stone turns Eevee into my\n"
	.string "favorite Pokémon ever, Espeon!$"

LaveriaCity_Text_Interlink_Girl:
	.string "{COLOR}{RED}The Pokémon in Route 9 aren't all\n"
	.string "too powerful.\p"
	.string "It's no wonder, though, with the\n"
	.string "amount of new Trainers visiting the\l"
	.string "Starter Dome…\p"
	.string "In fact, the Starter Dome is where I\n"
	.string "got my very first Pokémon, hehe.$"

LaveriaCity_Route7_Text_HeyYou:
	.string "Hey, you!\n"
	.string "Wait right there!\p"
	.string "No one is allowed to enter Mt. Tamarok\n"
	.string "without the sufficient credentials -\l"
	.string "it's far too dangerous out there!\p"
	.string "Once you can defeat the Champion of\n"
	.string "Laveria City I will consider letting\l"
	.string "you through…\p"
	.string "If you can get to him, of course!\n"
	.string "Hahaha!$"

LaveriaCity_Interlink_Text_Aide_HelloImProfessor:
	.string "Hello, there.\n"
	.string "I'm Professor Hawthorne's Aide.\p"
	.string "I am here to reward Trainers who are\n"
	.string "working on their Pokédex.\p"
	.string "If you have caught 20 or more Pokémon,\n"
	.string "you will win a fabulous prize!\p"
	.string "Here, let me take a look at your\n"
	.string "Pokédex…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Hmhm…\p"
	.string "So, you've seen {STR_VAR_1} Pokémon,\n"
	.string "and you've caught {STR_VAR_2} Pokémon…$"

LaveriaCity_Interlink_Text_Aide_TheDowsingMachine:
	.string "The Dowsing Machine is used to locate\n"
	.string "hidden or buried items.\p"
	.string "I hope it helps you in your journey!$"

LaveriaCity_Interlink_Text_Aide_CatchMoreMons:
	.string "I'm sorry…\n"
	.string "That's not quite 20 Pokémon…\p"
	.string "Come back when you have caught more.$"
