Route5_House1_MapScripts::
	.byte 0

Route5_House1_Man::
	lock
	faceplayer
	msgbox Route5_House1_Text_ATiredTrainerNoWorries, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq Route5_House1_Man_HealParty
	msgbox Route5_House1_Text_NoThatsFine, MSGBOX_AUTOCLOSE
	release
	end

Route5_House1_Man_HealParty::
	msgbox Route5_House1_Text_VeryWell, MSGBOX_AUTOCLOSE
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route5_House1_Text_ThereWeAre, MSGBOX_AUTOCLOSE
	release
	end

Route5_House1_Girl::
	msgbox Route5_House1_Text_Girl, MSGBOX_NPC
	end

Route5_House1_Pidgey::
	lockall
	faceplayer
	playmoncry SPECIES_PIDGEY, 0
	speakername CommonName_Text_Pidgey
	msgbox Route5_House1_Text_Pidgey, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	releaseall
	end

Route5_House1_Text_ATiredTrainerNoWorries:
	.string "{COLOR}{BLUE}A tired Trainer? No worries!\n"
	.string "How about a quick rest?$"

Route5_House1_Text_NoThatsFine:
	.string "{COLOR}{BLUE}No? That's fine.\n"
	.string "Good luck out there!$"

Route5_House1_Text_VeryWell:
	.string "{COLOR}{BLUE}Very well.\n"
	.string "Make yourself comfortable!$"

Route5_House1_Text_ThereWeAre:
	.string "{COLOR}{BLUE}There we are!\p"
	.string "You and your Pokémon are looking\n"
	.string "refreshed.\p"
	.string "Feel free to stay as long as you like!$"

Route5_House1_Text_Girl:
	.string "{COLOR}{RED}My Pidgey and I came here for a rest\n"
	.string "after climbing Route 5 together.\p"
	.string "The Trainers looked more interested in\n"
	.string "looking at the stone tablets rather\l"
	.string "than battling us! Hehehe!$"

Route5_House1_Text_Pidgey:
	.string "Pidgeyy!$"
