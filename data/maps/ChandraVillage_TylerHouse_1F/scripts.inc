ChandraVillage_TylerHouse_1F_MapScripts::
	.byte 0

ChandraVillage_TylerHouse_1F_Mother::
	goto_if_set FLAG_SYS_POKEDEX_GET, ChandraVillage_TylerHouse_1F_Mother_PKMN_Menu
	goto_if_set FLAG_BADGE01_GET, ChandraVillage_TylerHouse_1F_Mother_Badge_One
	msgbox ChandraVillage_TylerHouse_Text_1F_Mother, MSGBOX_NPC
	end

ChandraVillage_TylerHouse_1F_Mother_PKMN_Menu:
	msgbox ChandraVillage_TylerHouse_Text_1F_Mother_PKMN_Menu, MSGBOX_NPC
	end

ChandraVillage_TylerHouse_1F_Mother_Badge_One:
	msgbox ChandraVillage_TylerHouse_Text_1F_Mother_Badge_One, MSGBOX_NPC
	end

ChandraVillage_TylerHouse_Text_1F_Mother:
	.string "{COLOR}{RED}Hi, {PLAYER}.\n"
	.string "How are you and your mother doing?\p"
	.string "Tyler has gone to the Professor's Lab.$"

ChandraVillage_TylerHouse_Text_1F_Mother_PKMN_Menu:
	.string "{COLOR}{RED}So… You and Tyler have your first\n"
	.string "Pokémon? How magnificent!\p"
	.string "I was wondering why he was running\n"
	.string "around the place all excited.\p"
	.string "Congratulations to you both!$"

ChandraVillage_TylerHouse_Text_1F_Mother_Badge_One:
	.string "{COLOR}{RED}Hey, {PLAYER}!\n"
	.string "How are you doing?\p"
	.string "Have you heard from Tyler?\n"
	.string "Please tell him to visit more often!$"
