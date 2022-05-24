HighwindVillage_Mart_MapScripts::
	.byte 0

HighwindVillage_Mart_Hiker::
	lock
	msgbox HighwindVillage_Mart_Text_Hiker, MSGBOX_DEFAULT
	delay 30
	faceplayer
	msgbox HighwindVillage_Mart_Text_Hiker_2, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceUp
	waitmovement 0
	release
	end

HighwindVillage_Mart_Text_Hiker:
	.string "Ow! OK, OK!\n"
	.string "I'll get you that sweet!$"

HighwindVillage_Mart_Text_Hiker_2:
	.string "My Pokémon's a glutton…\p"
	.string "But I can't blame him, I'm hungry too\n"
	.string "after that trek through the snow.$"
