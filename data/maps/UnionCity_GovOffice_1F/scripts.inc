UnionCity_GovOffice_1F_MapScripts::
	.byte 0

UnionCity_GovOffice_1F_Sign_1::
	msgbox UnionCity_GovOffice_1F_Text_Sign_1, MSGBOX_SIGN
	end

UnionCity_GovOffice_1F_Sign_2::
	msgbox UnionCity_GovOffice_1F_Text_Sign_2, MSGBOX_SIGN
	end

UnionCity_GovOffice_1F_Bug_Catcher::
	msgbox UnionCity_GovOffice_1F_Text_Bug_Catcher, MSGBOX_NPC
	end

UnionCity_GovOffice_1F_Receptionist::
	msgbox UnionCity_GovOffice_1F_Text_Receptionist, MSGBOX_NPC
	end

UnionCity_GovOffice_1F_Text_Sign_1:
	.string "Some historical accolades are on\n"
	.string "display behind the glass panel.\p"
	.string "One medal reads: “All war is a symptom\n"
	.string "of man's failure as a thinking animal.”$"

UnionCity_GovOffice_1F_Text_Sign_2:
	.string "Some historical accolades are on\n"
	.string "display behind the glass panel.\p"
	.string "One pendant reads: “If absolute\n"
	.string "power corrupts absolutely, where does\l"
	.string "that leave God?”$"

UnionCity_GovOffice_1F_Text_Bug_Catcher:
	.string "{COLOR}{BLUE}This place is lame.\p"
	.string "There's nothing interesting here.\n"
	.string "Just a bunch of nerds upstairs."

UnionCity_GovOffice_1F_Text_Receptionist:
	.string "{COLOR}{RED}Hello and welcome to the Union City\n"
	.string "Government Offices.\p"
	.string "Please enjoy your visit.$"
