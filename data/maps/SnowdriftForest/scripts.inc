SnowdriftForest_MapScripts::
	.byte 0

SnowdriftForest_Sign::
	msgbox SnowdriftForest_Text_Sign, MSGBOX_SIGN
	end

SnowdriftForest_Hiker::
	msgbox SnowdriftForest_Text_Hiker, MSGBOX_NPC
	end

SnowdriftForest_Bug_Catcher::
	msgbox SnowdriftForest_Text_Bug_Catcher, MSGBOX_NPC
	end

SnowdriftForest_Old_Lady::
	msgbox SnowdriftForest_Text_Old_Lady, MSGBOX_NPC
	end

SnowdriftForest_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, SnowdriftForest_Text_PaulaIntro, SnowdriftForest_Text_PaulaDefeated
	msgbox SnowdriftForest_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

SnowdriftForest_EventScript_Angelina::
	trainerbattle_single TRAINER_ANGELINA, SnowdriftForest_Text_AngelinaIntro, SnowdriftForest_Text_AngelinaDefeated
	msgbox SnowdriftForest_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
	end

SnowdriftForest_EventScript_Nob::
	trainerbattle_single TRAINER_NOB, SnowdriftForest_Text_NobIntro, SnowdriftForest_Text_NobDefeated
	msgbox SnowdriftForest_Text_NobPostBattle, MSGBOX_AUTOCLOSE
	end

SnowdriftForest_Text_Sign:
	.string "Snowdrift Forest\n"
	.string "{UP_ARROW} Route 8$"

SnowdriftForest_Text_Hiker:
	.string "I live in Highwind Village, but every\n"
	.string "morning I come to this spot to look\l"
	.string "over the expanse of Snowdrift Forest.\p"
	.string "The snow-covered firs and the calmness\n"
	.string "of it all always soothes my soul…$"

SnowdriftForest_Text_Bug_Catcher:
	.string "{COLOR}{BLUE}I-I d-don't know why I c-came here\n"
	.string "d-dressed like th-this…\p"
	.string "I can't f-find a-any bugs here!\n"
	.string "Worst t-trip ever…$"

SnowdriftForest_Text_Old_Lady:
	.string "I'm trying to catch a glimpse of a\n"
	.string "wild Stantler.\p"
	.string "It's difficult to see one because\n"
	.string "they're fairly timid creatures.\p"
	.string "The secret is to tread lightly,\n"
	.string "otherwise they'll hide in the grass!$"
