UnionCity_GovOffice_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UnionCity_GovOffice_3F_OnTransition
	.byte 0

UnionCity_GovOffice_3F_OnTransition:
	goto_if_unset FLAG_HIDE_ABANDONED_MUSEUM_SUBO, UnionCity_GovOffice_3F_HidePresident
	clearflag FLAG_HIDE_UNION_CITY_GOV_OFFICE_3F_PRESIDENT
	addobject 3
	end

UnionCity_GovOffice_3F_HidePresident::
	removeobject 3
	setflag FLAG_HIDE_UNION_CITY_GOV_OFFICE_3F_PRESIDENT
	end

UnionCity_GovOffice_3F_PresidentDesk::
	lock
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, UnionCity_GovOffice_3F_PostSUBOMuseum
	msgbox UnionCity_GovOffice_3F_Text_ThereIsNotASpeckOfDust, MSGBOX_AUTOCLOSE
	release
	end

UnionCity_GovOffice_3F_PostSUBOMuseum::
	goto_if_set FLAG_TEMP_1, UnionCity_GovOffice_3F_Generic
	setflag FLAG_TEMP_1
	speakername2 CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 0, 0
	msgbox UnionCity_GovOffice_3F_Text_PlayerAsTheSUBOSaid, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq UnionCity_GovOffice_3F_Generic
	speakername2 CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 0, 0
	msgbox UnionCity_GovOffice_3F_Text_TenjoWillBeDoomed, MSGBOX_AUTOCLOSE
	hideface 0
	release
	end

UnionCity_GovOffice_3F_Generic::
	speakername2 CommonName_Text_President
	showface FS_PRESIDENT, FSE_NORMAL, 0, 0
	msgbox UnionCity_GovOffice_3F_Text_IAmCountingOnYou, MSGBOX_AUTOCLOSE
	hideface 0
	release
	end

UnionCity_GovOffice_3F_Employee::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, UnionCity_GovOffice_3F_Employee_AfterSUBO
	msgbox UnionCity_GovOffice_3F_Text_ThePresidentHasSteppedOut, MSGBOX_AUTOCLOSE
	release
	end

UnionCity_GovOffice_3F_Employee_AfterSUBO::
	msgbox UnionCity_GovOffice_3F_Text_ItIsQuiteChilling, MSGBOX_AUTOCLOSE
	release
	end

UnionCity_GovOffice_3F_Text_PlayerAsTheSUBOSaid:
	.string "{PLAYER}!\p"
	.string "As the SUBO said, they have gone north\n"
	.string "of Anheim Forest.\p"
	.string "I need you to give chase to them and\n"
	.string "stop them from stealing my notes!\p"
	.string "Will you do it for me?$"

UnionCity_GovOffice_3F_Text_TenjoWillBeDoomed:
	.string "Tenjo will be doomed otherwise!\n"
	.string "I will send support whenever I can.$"

UnionCity_GovOffice_3F_Text_IAmCountingOnYou:
	.string "I am counting on you to thwart the\n"
	.string "SUBO and bring peace back to Tenjo!$"

UnionCity_GovOffice_3F_Text_ThereIsNotASpeckOfDust:
	.string "There is not a speck of dust on the\n"
	.string "President's desk.$"

UnionCity_GovOffice_3F_Text_ThePresidentHasSteppedOut:
	.string "The President has stepped out of the\n"
	.string "office to run a quick errand.\p"
	.string "If you want his autograph, like most\n"
	.string "people, please check back later.$"

UnionCity_GovOffice_3F_Text_ItIsQuiteChilling:
	.string "It is quite chilling that thugs were\n"
	.string "running an operation under the city!$"
