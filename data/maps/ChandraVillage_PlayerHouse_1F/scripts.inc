ChandraVillage_PlayerHouse_1F_MapScripts::
	.byte 0

ChandraVillage_PlayerHouse_1F_Mother::
	goto_if_set FLAG_SYS_POKEDEX_GET, ChandraVillage_PlayerHouse_1F_Mother_PKMN_Menu
	goto_if_set FLAG_BADGE01_GET, ChandraVillage_PlayerHouse_1F_Mother_Badge_One
	msgbox ChandraVillage_PlayerHouse_1F_Text_Mother, MSGBOX_NPC
	end

ChandraVillage_PlayerHouse_1F_Mother_PKMN_Menu::
	lockall
	msgbox ChandraVillage_PlayerHouse_Text_1F_Mother_PKMN_Menu, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_PlayerHouse_1F_Mother_Rest
	goto ChandraVillage_Playerhouse_1F_Mother_No

ChandraVillage_PlayerHouse_1F_Mother_Badge_One::
	lockall
	msgbox ChandraVillage_PlayerHouse_Text_1F_Mother_Badge_One, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChandraVillage_PlayerHouse_1F_Mother_Rest
	goto ChandraVillage_Playerhouse_1F_Mother_No

ChandraVillage_PlayerHouse_1F_Mother_Rest::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox ChandraVillage_PlayerHouse_1F_Text_Mother_Healed, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_Playerhouse_1F_Mother_No::
	msgbox ChandraVillage_PlayerHouse_1F_Text_Mother_No, MSGBOX_DEFAULT
	releaseall
	end

ChandraVillage_PlayerHouse_1F_Text_Mother:
	.string "{COLOR}{RED}Be sure to say hello to Tyler's mom\n"
	.string "for me, {PLAYER}.$"

ChandraVillage_PlayerHouse_Text_1F_Mother_PKMN_Menu:
	.string "{COLOR}{RED}Welcome home, {PLAYER}!\p"
	.string "…\n"
	.string "…\p"
	.string "Wow, Professor Hawthorne gave you a\n"
	.string "Pokémon? That's great, darling!\p"
	.string "How about a quick rest?$"

ChandraVillage_PlayerHouse_Text_1F_Mother_Badge_One:
	.string "{COLOR}{RED}Welcome home, {PLAYER}.\n"
	.string "How is your adventure going?\p"
	.string "Would you like to take a quick rest?$"

ChandraVillage_PlayerHouse_1F_Text_Mother_Healed:
	.string "{COLOR}{RED}Take care, honey!\n"
	.string "Mom is proud of you!$"

ChandraVillage_PlayerHouse_1F_Text_Mother_No:
	.string "{COLOR}{RED}Mom is proud of you, honey!$"
