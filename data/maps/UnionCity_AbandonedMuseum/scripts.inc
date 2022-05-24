UnionCity_AbandonedMuseum_MapScripts::
	.byte 0

UnionCity_AbandonedMuseum_Old_Man::
	msgbox UnionCity_AbandonedMuseum_Text_Old_Man, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Girl::
	goto_if_set FLAG_ABANDONED_MUSEUM_COMPLETE, UnionCity_AbandonedMuseum_Girl_Complete
	msgbox UnionCity_AbandonedMuseum_Text_Girl, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Girl_Complete::
	msgbox UnionCity_AbandonedMuseum_Text_Girl_Complete, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Little_Girl::
	goto_if_set FLAG_ABANDONED_MUSEUM_COMPLETE, UnionCity_AbandonedMuseum_Little_Girl_Complete
	msgbox UnionCity_AbandonedMuseum_Text_Little_Girl, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Little_Girl_Complete::
	msgbox UnionCity_AbandonedMuseum_Text_Little_Girl_Complete, MSGBOX_NPC
	end

UnionCity_AbandonedMuseum_Text_Old_Man:
	.string "This museum was recently abandoned.\p"
	.string "It seems like nobody is interested in\n"
	.string "history anymore…\p"
	.string "At least the statues have not yet been\n"
	.string "destroyed so I can still examine them\l"
	.string "from time to time.$"

UnionCity_AbandonedMuseum_Text_Girl:
	.string "{COLOR}{RED}The old floor creaks and the shattered\n"
	.string "glass submits beneath my boots.\p"
	.string "There is nothing quite like the eerie\n"
	.string "feeling of an abandoned building.\p"
	.string "Not only that, but I often hear noises\n"
	.string "coming from the basement.\p"
	.string "If only I could find a way down there\n"
	.string "so I could investigate…$"

UnionCity_AbandonedMuseum_Text_Girl_Complete:
	.string "{COLOR}{RED}I heard somebody found their way down\n"
	.string "into the basement of this museum.\p"
	.string "I'm not too sure what unfolded down\n"
	.string "there, but I heard it was ugly.$"

UnionCity_AbandonedMuseum_Text_Little_Girl:
	.string "{COLOR}{RED}I don't know why my grandpa brought me\n"
	.string "to this place - it's scary!\p"
	.string "I heard strange noises coming from\n"
	.string "underground!$"

UnionCity_AbandonedMuseum_Text_Little_Girl_Complete:
	.string "{COLOR}{RED}My grandpa saw some bad guys fleeing\n"
	.string "from the city.\p"
	.string "I heard they were doing mean things in\n"
	.string "the basement of this museum!$"
