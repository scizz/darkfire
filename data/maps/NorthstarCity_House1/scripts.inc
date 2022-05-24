NorthstarCity_House1_MapScripts::
	.byte 0

@:NorthstarCity_House1_Bulbasaur::

NorthstarCity_House1_Boy::
	msgbox NorthstarCity_House1_Text_Boy, MSGBOX_NPC
	end

NorthstarCity_House1_Woman::
	msgbox NorthstarCity_House1_Text_Woman, MSGBOX_NPC
	end

NorthstarCity_House1_Text_Boy:
	.string "{COLOR}{BLUE}My older brother is a bully.\p"
	.string "He always hangs around outside with\n"
	.string "his stupid buddies, causing havoc.\p"
	.string "He's not cool and he's not a gangster\n"
	.string "- no matter what he thinks!\p"
	.string "One day, someone will stand up to him\n"
	.string "and teach him a lesson!$"

NorthstarCity_House1_Text_Woman:
	.string "{COLOR}{RED}Northstar City is overpopulated, busy,\n"
	.string "and full of noise.\p"
	.string "That's why I love the yearly tournament\n"
	.string "because everybody flocks there.\p"
	.string "Now I can hear my thoughts in peace!$"
