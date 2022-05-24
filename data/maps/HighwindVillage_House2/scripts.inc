HighwindVillage_House2_MapScripts::
	.byte 0

HighwindVillage_House2_Woman::
	msgbox HighwindVillage_House2_Text_Woman, MSGBOX_NPC
	end

HighwindVillage_House2_Old_Man::
	msgbox HighwindVillage_House2_Text_Old_Man, MSGBOX_NPC
	end

HighwindVillage_House2_Text_Woman:
	.string "{COLOR}{RED}I take care of Grandpa these days,\n"
	.string "since my brother is out in the field\l"
	.string "doing Ranger work.\p"
	.string "I only wish it would stop snowing!$"

HighwindVillage_House2_Text_Old_Man:
	.string "Fweh! It's too cold up here.\p"
	.string "My nose is running, and my feet are\n"
	.string "freezing.\p"
	.string "I should've retired to a warmer place!$"
