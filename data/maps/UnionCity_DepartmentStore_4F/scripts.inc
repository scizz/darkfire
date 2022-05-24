UnionCity_DepartmentStore_4F_MapScripts::
	.byte 0

UnionCity_DepartmentStore_4F_Woman::
	msgbox UnionCity_DepartmentStore_4F_Text_Woman, MSGBOX_NPC
	end

UnionCity_DepartmentStore_4F_Old_Man::
	msgbox UnionCity_DepartmentStore_4F_Text_Old_Man, MSGBOX_NPC
	end

UnionCity_DepartmentStore_4F_Bug_Catcher::
	msgbox UnionCity_DepartmentStore_4F_Text_Bug_Catcher, MSGBOX_NPC
	end

UnionCity_DepartmentStore_4F_Text_Woman:
	.string "{COLOR}{RED}A catalog I read said there are fifty\n"
	.string "different kinds of TMs.$"

UnionCity_DepartmentStore_4F_Text_Old_Man:
	.string "Hmm…\p"
	.string "An attacking move…\n"
	.string "Or a defensive move…\p"
	.string "It's no easy matter to decide which TM\n"
	.string "moves should be taught to Pokémon…$"

UnionCity_DepartmentStore_4F_Text_Bug_Catcher:
	.string "{COLOR}{BLUE}The good thing is TMs never run out,\n"
	.string "you can use them as much as you like!$"
