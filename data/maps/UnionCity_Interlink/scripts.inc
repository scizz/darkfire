UnionCity_Interlink_MapScripts::
	.byte 0

UnionCity_Interlink_Little_Girl::
	msgbox UnionCity_Interlink_Text_Little_Girl, MSGBOX_NPC
	end

UnionCity_Interlink_Boy::
	msgbox UnionCity_Interlink_Text_Boy, MSGBOX_NPC
	end

UnionCity_Interlink_Psychic::
	msgbox UnionCity_Interlink_Text_Psychic, MSGBOX_NPC
	end

UnionCity_Interlink_Grandma::
	msgbox UnionCity_Interlink_Text_Grandma, MSGBOX_NPC
	end

UnionCity_Interlink_Aide::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox UnionCity_Interlink_Text_Aide_HelloImProfessor, MSGBOX_AUTOCLOSE
	hideface 1
	compare VAR_0x8009, 10
	goto_if_ge UnionCity_Interlink_AideGiveEverstone
	emote 5, 2
	playse SE_PIN
	waitse
	delay 60
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox UnionCity_Interlink_Text_Aide_CatchMoreMons, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

UnionCity_Interlink_AideGiveEverstone::
	emote 5, 1
	playse SE_PIN
	waitse
	delay 60
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox UnionCity_Interlink_Text_Aide_CongratulationsHeresYourReward, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_EVERSTONE, 1
	speakername CommonName_Text_Aide
	showface FS_SCIENTIST, FSE_NORMAL, 1, 1
	msgbox UnionCity_Interlink_Text_Aide_TheEverstonePrevents, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

UnionCity_Interlink_Text_Little_Girl:
	.string "{COLOR}{RED}I'm tired of playing in Union City, but\n"
	.string "this is as far as Mom lets me go…\p"
	.string "She says Route 2 is full of dangerous\n"
	.string "Pokémon.$"

UnionCity_Interlink_Text_Boy:
	.string "{COLOR}{BLUE}You seen those Berries that you can\n"
	.string "pick from trees?\p"
	.string "Well, different Berries have different\n"
	.string "effects on your Pokémon.\p"
	.string "Try using one on your Pokémon!$"

UnionCity_Interlink_Text_Psychic:
	.string "{COLOR}{BLUE}Wait, no, don't tell me.\n"
	.string "I can tell just by looking at you.\p"
	.string "You're gonna find many hardships along\n"
	.string "this road, but it'll all be worthwhile.$"

UnionCity_Interlink_Text_Grandma:
	.string "You're telling me you're a Trainer?\n"
	.string "Good grief!\p"
	.string "It seems like you're all starting your\n"
	.string "journeys at a younger age nowadays!\l"
	.string "Be careful out there!$"

UnionCity_Interlink_Text_Aide_HelloImProfessor:
	.string "Hello, there.\n"
	.string "I'm Professor Hawthorne's Aide.\p"
	.string "I am here to reward Trainers who are\n"
	.string "working on their Pokédex.\p"
	.string "If you have caught 10 or more Pokémon,\n"
	.string "you will win a fabulous prize!\p"
	.string "Here, let me take a look at your\n"
	.string "Pokédex…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Hmhm…\p"
	.string "So, you've seen {STR_VAR_1} Pokémon,\n"
	.string "and you've caught {STR_VAR_2} Pokémon…$"

UnionCity_Interlink_Text_Aide_CongratulationsHeresYourReward:
	.string "Congratulations!\p"
	.string "Here's your reward!$"

UnionCity_Interlink_Text_Aide_TheEverstonePrevents:
	.string "The Everstone is a held item that\n"
	.string "prevents a Pokémon from evolving.\p"
	.string "I hope it helps you in your journey!$"

UnionCity_Interlink_Text_Aide_CatchMoreMons:
	.string "I'm sorry…\n"
	.string "That's not quite 10 Pokémon…\p"
	.string "Come back when you have caught more.$"
