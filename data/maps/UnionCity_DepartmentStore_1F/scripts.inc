UnionCity_DepartmentStore_1F_MapScripts::
	.byte 0

UnionCity_DepartmentStore_1F_Sign::
	msgbox UnionCity_DepartmentStore_1F_Text_Sign, MSGBOX_SIGN
	end

UnionCity_DepartmentStore_1F_Pokefan_M::
	msgbox UnionCity_DepartmentStore_1F_Text_Pokefan_M, MSGBOX_NPC
	end

UnionCity_DepartmentStore_1F_Receptionist::
	msgbox UnionCity_DepartmentStore_1F_Text_Receptionist, MSGBOX_NPC
	end

UnionCity_DepartmentStore_1F_Little_Girl::
	msgbox UnionCity_DepartmentStore_1F_Text_Little_Girl, MSGBOX_NPC
	end

UnionCity_DepartmentStore_1F_Woman::
	msgbox UnionCity_DepartmentStore_1F_Text_Woman, MSGBOX_NPC
	end

UnionCity_DepartmentStore_1F_Text_Sign:
	.string "1F: Service Counter\n"
	.string "Lottery Corner\p"
	.string "2F: Trainer's Zone\p"
	.string "3F: Battle Collection\p"
	.string "4F: TM Corner\p"
	.string "5F: Poké Doll Floor$"

UnionCity_DepartmentStore_1F_Text_Pokefan_M:
	.string "{COLOR}{BLUE}I'm buying something for my Azumarill\n"
	.string "today!$"

UnionCity_DepartmentStore_1F_Text_Receptionist:
	.string "{COLOR}{RED}Welcome to the Union City Mall!\n"
	.string "We have all a new Trainer needs!$"

UnionCity_DepartmentStore_1F_Text_Little_Girl:
	.string "{COLOR}{RED}Today my mom is going to buy me some\n"
	.string "nice furniture!$"

UnionCity_DepartmentStore_1F_Text_Woman:
	.string "{COLOR}{RED}Whenever I come to this mall, I always\n"
	.string "end up buying all sorts of random\l"
	.string "stuff because it's always so fun!$"
