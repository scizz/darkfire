ChandraVillage_Lab_MapScripts::
	.byte 0

ChandraVillage_Lab_Aide::
	goto_if_set FLAG_SYS_POKEDEX_GET, ChandraVillage_Lab_Aide_Dex
	msgbox ChandraVillage_Lab_Text_Aide, MSGBOX_NPC
	end

ChandraVillage_Lab_Aide_Dex::
	msgbox ChandraVillage_Lab_Text_Aide_Dex, MSGBOX_NPC
	end

ChandraVillage_Lab_Text_Aide:
	.string "Pfft… The Professor is such a wimp.\n"
	.string "These Rattata won't distract me!$"

ChandraVillage_Lab_Text_Aide_Dex:
	.string "You saved the Professor from Rattata?\n"
	.string "You want a medal? He's a wimp.$"
