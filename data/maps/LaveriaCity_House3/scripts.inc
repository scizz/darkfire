LaveriaCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LaveriaCity_House3_OnTransition
	.byte 0

LaveriaCity_House3_OnTransition:
	setvar VAR_TEMP_B, 4
	end

LaveriaCity_House3_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVERIA_CITY_SNOWBALL, LaveriaCity_House3_Woman_Given
	msgbox LaveriaCity_House3_Woman_Text_Snowball, MSGBOX_AUTOCLOSE
	giveitem ITEM_SNOWBALL, 1
	setflag FLAG_RECEIVED_LAVERIA_CITY_SNOWBALL
	goto LaveriaCity_House3_Woman_Given
	end

LaveriaCity_House3_Woman_Given::
	msgbox LaveriaCity_House3_Woman_Text_Snowball_Given, MSGBOX_AUTOCLOSE
	release
	end

LaveriaCity_House3_Igglybuff::
	lock
	pokemonfaceplayer 2
	playmoncry SPECIES_IGGLYBUFF, 0
	speakername CommonName_Text_Igglybuff
	msgbox LaveriaCity_House3_Text_Igglybuff, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end

LaveriaCity_House3_Woman_Text_Snowball:
	.string "{COLOR}{RED}Life in a snowy city means one thing…\n"
	.string "Epic snowball fights!\p"
	.string "Here, take this!$"
	
LaveriaCity_House3_Woman_Text_Snowball_Given:
	.string "{COLOR}{RED}We're all friends here, whether human\n"
	.string "or Pokémon.\p"
	.string "And playing together only makes our\n"
	.string "bonds stronger!$"

LaveriaCity_House3_Text_Igglybuff:
	.string "Iggly!$"
