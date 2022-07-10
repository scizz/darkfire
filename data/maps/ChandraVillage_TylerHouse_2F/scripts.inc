ChandraVillage_TylerHouse_2F_MapScripts::
	.byte 0

ChandraVillage_TylerHouse_2F_ShowHideTyler::
	goto_if_set FLAG_SYS_POKEMON_GET, ChandraVillage_TylerHouse_2F_ShowTyler
	removeobject 1
	removeobject 2
	setflag FLAG_HIDE_TYLERS_HOUSE_TYLER
	setflag FLAG_HIDE_TYLERS_HOUSE_BAG
	release
	end

ChandraVillage_TylerHouse_2F_ShowTyler::
	clearflag FLAG_HIDE_TYLERS_HOUSE_TYLER
	clearflag FLAG_HIDE_TYLERS_HOUSE_BAG
	addobject 1
	addobject 2
	setvar VAR_TYLERS_HOUSE, 1
	release
	end
