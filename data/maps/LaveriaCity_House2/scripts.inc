LaveriaCity_House2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LaveriaCity_House2_OnTransition
	.byte 0

LaveriaCity_House2_OnTransition:
	setvar VAR_TEMP_B, 4
	end

LaveriaCity_House2_Old_Man::
	msgbox LaveriaCity_House2_Text_Old_Man, MSGBOX_NPC
	end

LaveriaCity_House2_Text_Old_Man:
	.string "Now, now…\n"
	.string "About our elusive Champion…\p"
	.string "The Champion of Laveria City is a\n"
	.string "mysterious figure.\p"
	.string "Rarely seen, like the northern lights,\n"
	.string "legendary and awe-inspiring!\p"
	.string "Some say he trains on the icy island,\n"
	.string "communing with Ice-type Pokémon to\l"
	.string "master the art of frigid battles.$"
