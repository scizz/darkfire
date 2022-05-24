UnionCity_DepartmentStore_3F_MapScripts::
	.byte 0

UnionCity_DepartmentStore_3F_Girl::
	msgbox UnionCity_DepartmentStore_3F_Text_Girl, MSGBOX_NPC
	end

UnionCity_DepartmentStore_3F_Boy::
	msgbox UnionCity_DepartmentStore_3F_Text_Boy, MSGBOX_NPC
	end

UnionCity_DepartmentStore_3F_Text_Girl:
	.string "{COLOR}{RED}I gave a Carbos to my Pokémon,\n"
	.string "and its Speed went up.\p"
	.string "Then I gave an HP-Up to my Pokémon,"
	.string "and, well, it's self-explanatory…$"

UnionCity_DepartmentStore_3F_Text_Boy:
	.string "{COLOR}{BLUE}For quickly toughening up Pokémon,\n"
	.string "Protein and Calcium are the best.\p"
	.string "They raise the Attack and Sp. Attack\n"
	.string "stats of a Pokémon, respectively.$"
