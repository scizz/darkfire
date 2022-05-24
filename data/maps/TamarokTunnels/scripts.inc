TamarokTunnels_MapScripts::
	.byte 0

TamarokTunnels_EventScript_Eli::
	trainerbattle_single TRAINER_ELI, TamarokTunnels_Text_EliIntro, TamarokTunnels_Text_EliDefeated
	msgbox TamarokTunnels_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end
