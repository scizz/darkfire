NorthstarCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NorthstarCity_House3_OnTransition
	.byte 0

NorthstarCity_House3_OnTransition:
	setvar VAR_TEMP_B, 6
	end

NorthstarCity_House3_Sailor::
	msgbox NorthstarCity_House3_Text_Sailor, MSGBOX_NPC
	end

NorthstarCity_House3_Text_Sailor:
	.string "{COLOR}{BLUE}Visualize this.\p"
	.string "You are standing at the stern of the\n"
	.string "ship with your arms wide open.\p"
	.string "You are trying to clasp the wind to\n"
	.string "your breast and hug it.\p"
	.string "You are blinded with bright luminance\n"
	.string "of the glistening waters.\p"
	.string "For your eyes know, never on land will\n"
	.string "they experience such a visual feast!\p"
	.string "Ha!\p"
	.string "Being able to sail the seas is a\n"
	.string "huge blessing, indeed.$"
