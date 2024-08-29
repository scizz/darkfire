MuddyUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MuddyUnderpass_OnFrame
	.byte 0

MuddyUnderpass_OnFrame:
	map_script_2 VAR_ABANDONED_MUSEUM_STATE, 1, MuddyUnderpass_SetVar
	.2byte 0

MuddyUnderpass_SetVar::
	setvar VAR_ABANDONED_MUSEUM_STATE, 0
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	special ShowMapNamePopup
	end

WarpToMuseum2::
	setfollowerwarppos DIR_NORTH
	warpsilent MAP_UNION_CITY_ABANDONED_MUSEUM, 15, 13
	waitstate
	end
