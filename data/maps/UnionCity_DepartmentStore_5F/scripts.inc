UnionCity_DepartmentStore_5F_MapScripts::
	.byte 0

UnionCity_DepartmentStore_5F_Aroma_Lady::
	msgbox UnionCity_DepartmentStore_5F_Text_Aroma_Lady, MSGBOX_NPC
	end

UnionCity_DepartmentStore_5F_Woman::
	msgbox UnionCity_DepartmentStore_5F_Text_Woman, MSGBOX_NPC
	end

UnionCity_DepartmentStore_5F_Little_Girl::
	msgbox UnionCity_DepartmentStore_5F_Text_Little_Girl, MSGBOX_NPC
	end

UnionCity_DepartmentStore_5F_Text_Aroma_Lady:
	.string "{COLOR}{RED}They sell many cute Mats here.\p"
	.string "I wonder which one I should get?$"

UnionCity_DepartmentStore_5F_Text_Woman:
	.string "{COLOR}{RED}This place is full of cute Dolls.\p"
	.string "I should buy some for me, instead of\n"
	.string "just for my children.$"

UnionCity_DepartmentStore_5F_Text_Little_Girl:
	.string "{COLOR}{RED}I'm too young to raise Pokémon, so I'm\n"
	.string "getting a Doll instead.$"
