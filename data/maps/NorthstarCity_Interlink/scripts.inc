NorthstarCity_Interlink_MapScripts::
	.byte 0

NorthstarCity_Interlink_Chef::
	msgbox NorthstarCity_Interlink_Text_Chef, MSGBOX_NPC
	end

NorthstarCity_Interlink_Sailor::
	msgbox NorthstarCity_Interlink_Text_Sailor, MSGBOX_NPC
	end

NorthstarCity_Interlink_Aide::
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
	showface FS_OFFICIAL, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Interlink_Text_Aide_HelloImProfessor, MSGBOX_AUTOCLOSE
	hideface 1
	compare VAR_0x8009, 30
	goto_if_ge NorthstarCity_Interlink_AideGiveExpShare
	emote 3, 2
	playse SE_PIN
	waitse
	speakername CommonName_Text_Aide
	showface FS_OFFICIAL, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Interlink_Text_Aide_CatchMoreMons, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

NorthstarCity_Interlink_AideGiveExpShare::
	emote 3, 1
	playse SE_PIN
	waitse
	speakername CommonName_Text_Aide
	showface FS_OFFICIAL, FSE_NORMAL, 1, 1
	msgbox UnionCity_Interlink_Text_Aide_CongratulationsHeresYourReward, MSGBOX_AUTOCLOSE
	hideface 1
	giveitem ITEM_EXP_SHARE, 1
	speakername CommonName_Text_Aide
	showface FS_OFFICIAL, FSE_NORMAL, 1, 1
	msgbox NorthstarCity_Interlink_Text_Aide_TheExpShare, MSGBOX_AUTOCLOSE
	hideface 1
	release
	end

NorthstarCity_Interlink_Text_Chef:
	.string "{COLOR}{BLUE}Hey, good lookin'.\n"
	.string "What you got cookin'?\p"
	.string "What? Not you, kid!\n"
	.string "I'm listening to music!$"

NorthstarCity_Interlink_Text_Sailor:
	.string "{COLOR}{BLUE}Well, hello, Trainer!\n"
	.string "Here's some Sailor advice!\p"
	.string "May your anchor be tight, may your\n"
	.string "cork be loose.\p"
	.string "May your rum be spiced, and your\n"
	.string "compass be true!\p"
	.string "Go get em, kid!$"

NorthstarCity_Interlink_Text_Aide_HelloImProfessor:
	.string "Hello, there.\n"
	.string "I'm Professor Hawthorne's Aide.\p"
	.string "I am here to reward Trainers who are\n"
	.string "working on their Pokédex.\p"
	.string "If you have caught 30 or more Pokémon,\n"
	.string "you will win a fabulous prize!\p"
	.string "Here, let me take a look at your\n"
	.string "Pokédex…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Hmhm…\p"
	.string "So, you've seen {STR_VAR_1} Pokémon,\n"
	.string "and you've caught {STR_VAR_2} Pokémon…$"

NorthstarCity_Interlink_Text_Aide_TheExpShare:
	.string "The Exp. Share awards a Pokémon\n"
	.string "experience from a battle, even if\l"
	.string "they don't directly participate in it.\p"
	.string "I hope it helps you in your journey!$"

NorthstarCity_Interlink_Text_Aide_CatchMoreMons:
	.string "I'm sorry…\n"
	.string "That's not quite 30 Pokémon…\p"
	.string "Come back when you have caught more.$"
