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

SunriseTown_House1_Text_Man:
	.string "{COLOR}{BLUE}Have you seen the news today? Have you?\n"
	.string "Just disastrous!\p"
	.string "Underground battling? Hurting Pokémon?\n"
	.string "Just terrible!$"
