SunriseTown_House1_MapScripts::
	.byte 0

SunriseTown_House1_Man::
	lockall
	faceplayer
	msgbox SunriseTown_House1_Text_Man, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end

SunriseTown_House1_Little_Girl::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, SunriseTown_House1_Little_Girl_Two
	bufferleadmonspeciesname 0
	msgbox SunriseTown_House1_Text_Little_Girl, MSGBOX_AUTOCLOSE
	setflag FLAG_TEMP_1
	release
	end

SunriseTown_House1_Little_Girl_Two::
	lock
	faceplayer
	bufferleadmonspeciesname 0
	msgbox SunriseTown_House1_Text_Little_Girl_Two, MSGBOX_AUTOCLOSE
	release
	end

SunriseTown_House1_TV::
	msgbox SunriseTown_House1_TV_Text, MSGBOX_SIGN
	end

SunriseTown_House1_Text_Man:
	.string "{COLOR}{BLUE}Have you seen the news? Have you?\n"
	.string "Just disastrous!\p"
	.string "Underground battling? Hurting Pokémon?\n"
	.string "Just terrible!$"

SunriseTown_House1_Text_Little_Girl:
	.string "{COLOR}{RED}Aww!\n"
	.string "Your {STR_VAR_1} is so cute!\p"
	.string "Sniff…\n"
	.string "I wish I had my own Pokémon…$"

SunriseTown_House1_Text_Little_Girl_Two:
	.string "{COLOR}{RED}Your {STR_VAR_1} is adorable!$"

SunriseTown_House1_TV_Text:
	.string "There is a TV reporter describing the\n"
	.string "current state of public affairs.\p"
	.string "“The SUBO, or Secret Underground\n"
	.string "Battling Organization are to be taken\l"
	.string "very seriously.\p"
	.string "Not only are they terrorizing Tenjo\n"
	.string "by stealing Pokémon, but they are also\l"
	.string "threatening the people and government.\p"
	.string "Back over to you at the TEN Studio.”$"
