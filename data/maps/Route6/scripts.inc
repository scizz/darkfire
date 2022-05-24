Route6_MapScripts::
	.byte 0

Route6_Sign::
	msgbox Route6_Text_Sign, MSGBOX_SIGN
	end

Route6_Sign_West::
	msgbox Route6_Text_Sign_West, MSGBOX_SIGN
	end

Route6_Ranger_Female::
	msgbox Route6_Text_Ranger_Female, MSGBOX_NPC
	end

Route6_Ranger_Male::
	msgbox Route6_Text_Ranger_Male, MSGBOX_NPC
	end

Route6_Man::
	msgbox Route6_Text_Man, MSGBOX_NPC
	end

Route6_Old_Lady::
	msgbox Route6_Text_Old_Lady, MSGBOX_NPC
	end

Route6_EventScript_Steve::
	trainerbattle_single TRAINER_STEVE, Route6_Text_SteveIntro, Route6_Text_SteveDefeated
	msgbox Route6_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route6_Text_AndrewIntro, Route6_Text_AndrewDefeated
	msgbox Route6_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, Route6_Text_VirgilIntro, Route6_Text_VirgilDefeated
	msgbox Route6_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Jenny::
	trainerbattle_single TRAINER_JENNY, Route6_Text_JennyIntro, Route6_Text_JennyDefeated
	goto_if_set FLAG_ROUTE_6_FRESH_WATER, Route6_Given
	msgbox Route6_Text_Jenny_Gift, MSGBOX_DEFAULT
	giveitem ITEM_FRESH_WATER, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_6_FRESH_WATER
	closemessage
	end

Route6_Given::
	msgbox Route6_Text_Given, MSGBOX_DEFAULT
	closemessage
	end

Route6_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route6_Text_KoichiIntro, Route6_Text_KoichiDefeated
	msgbox Route6_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Camron::
	trainerbattle_single TRAINER_CAMRON, Route6_Text_CamronIntro, Route6_Text_CamronDefeated
	msgbox Route6_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Lucas::
	trainerbattle_single TRAINER_LUCAS, Route6_Text_LucasIntro, Route6_Text_LucasDefeated
	msgbox Route6_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_Sign:
	.string "Route 6\n"
	.string "Not for inexperienced Hikers!$"

Route6_Text_Sign_West:
	.string "Route 6\n"
	.string "{LEFT_ARROW} Laveria City$"

Route6_Text_Ranger_Female:
	.string "{COLOR}{RED}Halt, trainer!\p"
	.string "We've been sent here from the Rangers'\n"
	.string "Federation to guard this unsafe spot!$"

Route6_Text_Ranger_Male:
	.string "{COLOR}{BLUE}Dangerous Pokémon have been spotted\n"
	.string "past this point.\p"
	.string "We can't allow anyone to pass before\n"
	.string "we fully investigate.$"

Route6_Text_Man:
	.string "{COLOR}{BLUE}This route is a hotspot for Hikers.\n"
	.string "There is so much to do!$"

Route6_Text_Old_Lady:
	.string "Oh, young one…\n"
	.string "You have a twinkle in your eye…\p"
	.string "You will amass great fortunes, indeed.$"

Route6_Text_Jenny_Gift:
	.string "{COLOR}{RED}Battling in this mountain is hard work!\n"
	.string "It's important to stay hydrated.\p"
	.string "I know! I'll share some of my Fresh\n"
	.string "Water with you!$"

Route6_Text_Given:
	.string "{COLOR}{RED}You should check out the Steep Ravine\n"
	.string "sometime.\p"
	.string "You can find some rare Pokémon down\n"
	.string "there!$"
