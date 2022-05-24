Route8_MapScripts::
	.byte 0

Route8_Sign::
	msgbox Route8_Text_Sign, MSGBOX_SIGN
	end

Route8_Fisherman::
	msgbox Route8_Text_Fisherman, MSGBOX_NPC
	end

Route8_Seel::
	lock
	faceplayer
	playmoncry SPECIES_SEEL, 0
	msgbox Route8_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Route8_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE, Route8_Text_CatherineIntro, Route8_Text_CatherineDefeated
	msgbox Route8_Text_CatherinePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Hassan::
	trainerbattle_single TRAINER_HASSAN, Route8_Text_HassanIntro, Route8_Text_HassanDefeated
	msgbox Route8_Text_HassanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Darcy::
	trainerbattle_single TRAINER_DARCY, Route8_Text_DarcyIntro, Route8_Text_DarcyDefeated
	msgbox Route8_Text_DarcyPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Gerald::
	trainerbattle_single TRAINER_GERALD, Route8_Text_GeraldIntro, Route8_Text_GeraldDefeated
	msgbox Route8_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Marcus::
	trainerbattle_single TRAINER_MARCUS, Route8_Text_MarcusIntro, Route8_Text_MarcusDefeated
	msgbox Route8_Text_MarcusPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route8_Text_RhettIntro, Route8_Text_RhettDefeated
	msgbox Route8_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN, Route8_Text_NathanIntro, Route8_Text_NathanDefeated
	msgbox Route8_Text_NathanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_Sign:
	.string "Route 8\n"
	.string "Northstar City {UP_ARROW}$"

Route8_Text_Fisherman:
	.string "{COLOR}{BLUE}I'm so irked…\p"
	.string "I can only catch Magikarp with this\n"
	.string "darned Old Rod.\p"
	.string "Where are the Ice-type Pokémon at?!$"

Route8_Text_Seel:
	.string "Seel: Quee quee!$"
