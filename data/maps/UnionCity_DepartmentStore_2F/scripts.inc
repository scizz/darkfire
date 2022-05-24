UnionCity_DepartmentStore_2F_MapScripts::
	.byte 0

UnionCity_DepartmentStore_2F_Sailor::
	msgbox UnionCity_DepartmentStore_2F_Text_Sailor, MSGBOX_NPC
	end

UnionCity_DepartmentStore_2F_Chef::
	msgbox UnionCity_DepartmentStore_2F_Text_Chef, MSGBOX_NPC
	end

UnionCity_DepartmentStore_2F_Woman::
	msgbox UnionCity_DepartmentStore_2F_Text_Woman, MSGBOX_NPC
	end

UnionCity_DepartmentStore_2F_Text_Sailor:
	.string "{COLOR}{BLUE}I'm stocking up on Antidotes for\n"
	.string "Anheim Forest…\p"
	.string "The forest is full of Bug-type Pokémon\n"
	.string "that love to poison your Pokémon!$"

UnionCity_DepartmentStore_2F_Text_Chef:
	.string "{COLOR}{BLUE}Learn to use items properly.\n"
	.string "That's basic, really.\p"
	.string "If your Pokémon is low on HP, use a\n"
	.string "Potion. Basic stuff…$"

UnionCity_DepartmentStore_2F_Text_Woman:
	.string "{COLOR}{RED}I'm seeking a birthday gift for my\n"
	.string "husband…\p"
	.string "But, what do you a get a man who\n"
	.string "already has everything?\p"
	.string "And by everything, I mean me, of\n"
	.string "course! Hehe.$"
