MagmaHideout_1F_MapScripts:: @ 8239880
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition: @ 8239886
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end
