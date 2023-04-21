NorthstarCity_Tournament_3F_MapScripts::
	.byte 0
	end

NorthstarCity_Tournament_3F_Psychic::
	msgbox NorthstarCity_Tournament_3F_Text_Psychic, MSGBOX_NPC
	end

NorthstarCity_Tournament_3F_Fat_Guy::
	msgbox NorthstarCity_Tournament_3F_Text_Fat_Guy, MSGBOX_NPC
	end

NorthstarCity_Tournament_3F_SUBO_Door::
	msgbox NorthstarCity_Tournament_3F_Text_SUBO_Door, MSGBOX_NPC
	end

NorthstarCity_Tournament_3F_Hide4FObjects::
	lock
	setflag FLAG_NORTHSTAR_TOURNAMENT_ENTRANCE
	setflag FLAG_NORTHSTAR_TOURNAMENT_OLD_MAN
	setflag FLAG_NORTHSTAR_TOURNAMENT_BLACK_BELT
	setflag FLAG_NORTHSTAR_TOURNAMENT_ACE_TRAINER
	setflag FLAG_NORTHSTAR_TOURNAMENT_SAILOR
	setflag FLAG_NORTHSTAR_TOURNAMENT_POKE_BALL
	setvar VAR_STORYLINE_STATE, 1
	release
	end

NorthstarCity_Tournament_3F_Text_Psychic:
	.string "Something very sinister is brewing in\n"
	.string "the horizon of the Tenjo region…\p"
	.string "You don't believe me?\p"
	.string "I suppose you do not sense it, like I\n"
	.string "do.$"

NorthstarCity_Tournament_3F_Text_Fat_Guy:
	.string "{COLOR}{BLUE}I work for the station's camera crew -\n"
	.string "couldn't find a better job even if I\l"
	.string "was the almighty President.\p"
	.string "I get paid to see hot Pokémon battles\n"
	.string "first-hand - how cool is that?!$"

NorthstarCity_Tournament_3F_Text_SUBO_Door:
	.string "{COLOR}{RED}Forget it, kid! I ain't movin'!\n"
	.string "Nope!\p"
	.string "You ain't getting out of this one!$"
