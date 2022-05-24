HighwindVillage_RangersLodge_MapScripts::
	.byte 0

HighwindVillage_RangersLodge_Ranger_1::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_1, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Ranger_2::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_2, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Ranger_3::
	goto_if_set FLAG_TEMP_1, HighwindVillage_RangersLodge_Ranger_3_Sung
	msgbox HighwindVillage_RangersLodge_Text_Ranger_3_1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

HighwindVillage_RangersLodge_Ranger_3_Sung::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_3_2, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Ranger_4::
	msgbox HighwindVillage_RangersLodge_Text_Ranger_4, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Receptionist::
	msgbox HighwindVillage_RangersLodge_Text_Receptionist, MSGBOX_NPC
	end

HighwindVillage_RangersLodge_Text_Ranger_1:
	.string "{COLOR}{BLUE}Whew!\p"
	.string "Nothing like a good meal after a\n"
	.string "hard day's work.\p"
	.string "The Groundskeeper here always takes\n"
	.string "care of us!$"

HighwindVillage_RangersLodge_Text_Ranger_2:
	.string "{COLOR}{RED}I enjoy sitting by the fire here and\n"
	.string "relaxing.\p"
	.string "It's a good change of pace from the\n"
	.string "back-breaking work in the unyielding\l"
	.string "cold and snow outside.$"

HighwindVillage_RangersLodge_Text_Ranger_3_1:
	.string "{COLOR}{BLUE}I am a cider drinker…\n"
	.string "I drinks it all of the day…\p"
	.string "I am a cider drinker…\n"
	.string "It soothes all me troubles away!\p"
	.string "Ooh aah ooh aah ay, ooh aah ooh ay!\n"
	.string "Hick…$"

HighwindVillage_RangersLodge_Text_Ranger_3_2:
	.string "{COLOR}{BLUE}It's so coooozy! Iiin the kitchen!\n"
	.string "With the smell of rabbit stew!\p"
	.string "When the breeze blows 'cross the farm\n"
	.string "yard-- hick!$"

HighwindVillage_RangersLodge_Text_Ranger_4:
	.string "{COLOR}{BLUE}We just got back from a dangerous\n"
	.string "mission in the Tamarok Tunnels.\p"
	.string "Our task was to remove the debris of\n"
	.string "the recent explosion in the caves and\l"
	.string "clear the path that used to be there.\p"
	.string "Sad to say, but we had no luck…\n"
	.string "I'm afraid the way is blocked forever.$"

HighwindVillage_RangersLodge_Text_Receptionist:
	.string "{COLOR}{RED}It's always, always busy in the\n"
	.string "Rangers' Lodge.\p"
	.string "Some Rangers work night shifts, others\n"
	.string "work during the day.\p"
	.string "It doesn't matter what hour it is -\n"
	.string "there's bound to be one or two Rangers\l"
	.string "hanging around here.\p"
	.string "For this reason, the fires of the\n"
	.string "hearth must be kept up at all times.$"
