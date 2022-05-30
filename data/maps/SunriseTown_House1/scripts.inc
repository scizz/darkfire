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
	lockall
	faceplayer
	goto_if_set FLAG_TEMP_1, SunriseTown_House1_Little_Girl_Two
	bufferleadmonspeciesname 0
	msgbox SunriseTown_House1_Text_Little_Girl, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	releaseall
	end

SunriseTown_House1_Little_Girl_Two::
	bufferleadmonspeciesname 0
	msgbox SunriseTown_House1_Text_Little_Girl_Two, MSGBOX_DEFAULT
	releaseall
	end

SunriseTown_House1_Text_Man:
	.string "{COLOR}{BLUE}Have you seen the news today? Have you?\n"
	.string "Just disastrous!\p"
	.string "Underground battling? Hurting Pokémon?\n"
	.string "Just terrible!$"

SunriseTown_House1_Text_Little_Girl:
	.string "{COLOR}{RED}Aww!\n"
	.string "Your {STR_VAR_1} is so cute!\p"
	.string "Sniff…\n"
	.string "I wish I had my own Pokémon…$"

SunriseTown_House1_Text_Little_Girl_Two:
	.string "{COLOR}{RED}Aww!\n"
	.string "Your {STR_VAR_1} is so cute!$"
