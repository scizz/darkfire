.set LOCALID_DAYCARE_MAN, 18

Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	.byte 0

Route4_OnTransition:
	call Route4_EventScript_TryMoveDayCareMan
	end

Route4_EventScript_TryMoveDayCareMan::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route4_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 50, 19
Route4_EventScript_StopMoveDayCareMan::
	return

Route4_Sign::
	msgbox Route4_Sign_Text, MSGBOX_SIGN
	end

Route4_Sign_Daycare::
	msgbox Route4_Sign_Daycare_Text, MSGBOX_SIGN
	end

Route4_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_1, Route4_Text_DouglasIntro, Route4_Text_DouglasDefeated
	msgbox Route4_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Fred::
	trainerbattle_single TRAINER_FRED, Route4_Text_FredIntro, Route4_Text_FredDefeated
	msgbox Route4_Text_FredPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Henry::
	trainerbattle_single TRAINER_HENRY_1, Route4_Text_HenryIntro, Route4_Text_HenryDefeated
	msgbox Route4_Text_HenryPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Lydia::
	trainerbattle_single TRAINER_LYDIA, Route4_Text_LydiaIntro, Route4_Text_LydiaDefeated
	msgbox Route4_Text_LydiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA_1, Route4_Text_LauraIntro, Route4_Text_LauraDefeated
	msgbox Route4_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA_1, Route4_Text_JoshuaIntro, Route4_Text_JoshuaDefeated
	goto_if_set FLAG_ROUTE_4_MOOMOO_MILK, Route4_Given
	msgbox Route4_Text_Joshua_Gift, MSGBOX_DEFAULT
	giveitem ITEM_MOOMOO_MILK, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_4_MOOMOO_MILK
	closemessage
	end

Route4_Given::
	msgbox Route4_Text_Given, MSGBOX_DEFAULT
	closemessage
	end

Route4_Sign_Text:
	.string "Welcome to the Route 4 Farmlands!\n"
	.string "{LEFT_ARROW} Greendale Village$"

Route4_Sign_Daycare_Text:
	.string "Route 4\n"
	.string "Day Care Center$"

Route4_Text_Joshua_Gift:
	.string "{COLOR}{BLUE}I thought my Pokémon was the strongest\n"
	.string "around here, but you proved me wrong!\p"
	.string "Here, take this!$"

Route4_Text_Given:
	.string "{COLOR}{BLUE}Moomoo Milk heals a Pokémon by 100 HP.\n"
	.string "Though, once it's gone, it's gone!$"
