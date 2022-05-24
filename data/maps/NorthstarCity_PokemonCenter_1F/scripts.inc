NorthstarCity_PokemonCenter_1F_MapScripts::
	.byte 0

NorthstarCity_PokemonCenter_1F_Maniac::
	msgbox NorthstarCity_PokemonCenter_1F_Text_Maniac, MSGBOX_NPC
	end

NorthstarCity_PokemonCenter_1F_Boy_Dig_TM::
	lockall
	goto_if_set FLAG_RECEIVED_DIG_TM, NorthstarCity_PokemonCenter_1F_Boy_Dig_TM_Given
	msgbox Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_1, MSGBOX_DEFAULT
	delay 10
	faceplayer
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NorthstarCity_PokemonCenter_1F_Boy_Dig_TM_Yes
	msgbox Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_3, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

NorthstarCity_PokemonCenter_1F_Boy_Dig_TM_Yes::
	goto_if_set FLAG_RECEIVED_DIG_TM, NorthstarCity_PokemonCenter_1F_Boy_Dig_TM_Given
	msgbox Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_4, MSGBOX_DEFAULT
	giveitem ITEM_TM28, 1
	setflag FLAG_RECEIVED_DIG_TM
	closemessage
	goto NorthstarCity_PokemonCenter_1F_Boy_Dig_TM_Given

NorthstarCity_PokemonCenter_1F_Boy_Dig_TM_Given::
	msgbox Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_Given, MSGBOX_DEFAULT
	releaseall
	end

Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_1:
	.string "{COLOR}{BLUE}Yo!\p"
	.string "'Cause I'm harder than brass!\n"
	.string "Yeah! I run through the grass!\p"
	.string "I'll find that Geodude and I'll\n"
	.string "Stomp on its a--$"

Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_2:
	.string "{COLOR}{BLUE}Yo, dude!\n"
	.string "You just caught me freestylin'\p"
	.string "Tell me!\n"
	.string "Do ya dig it?!$"

Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_3:
	.string "{COLOR}{BLUE}No?\n"
	.string "Haters gonna hate…$"

Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_4:
	.string "{COLOR}{BLUE}That's what I'm talkin' about!\n"
	.string "Take this!$"

Northstar_PokemonCenter_1F_Text_Boy_Dig_TM_Given:
	.string "{COLOR}{BLUE}I dig ya, too, my dude.\n"
	.string "Keep hustlin' out there!$"

NorthstarCity_PokemonCenter_1F_Text_Maniac:
	.string "I've been hearing about some rotten\n"
	.string "scoundrels who steal Pokémon…\p"
	.string "There's no way I'm letting them near\n"
	.string "my Pokémon…$"
