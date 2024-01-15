UnionCity_House1_3F_MapScripts::
	.byte 0

UnionCity_House1_3F_Husband::
	msgbox UnionCity_House1_3F_Text_MyWifeLovesMe, MSGBOX_NPC
	end

UnionCity_House1_3F_Wife::
	msgbox UnionCity_House1_3F_Text_MarriageIsARelationship, MSGBOX_NPC
	end

UnionCity_House1_3F_Text_MyWifeLovesMe:
	.string "{COLOR}{BLUE}My wife loves me so much, she tries her\n"
	.string "best to attract me to her.\p"
	.string "The other day she put on a perfume\n"
	.string "that smells like a computer!$"

UnionCity_House1_3F_Text_MarriageIsARelationship:
	.string "{COLOR}{RED}Marriage is a relationship in which\n"
	.string "one person is always right and the\l"
	.string "other is the husband, tehehe.$"
