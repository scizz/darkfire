Route10_MapScripts::
	.byte 0

Route10_Man::
	msgbox Route10_Text_Man, MSGBOX_NPC
	end

Route10_Boy::
	msgbox Route10_Text_Boy, MSGBOX_NPC
	end

Route10_Girl::
	msgbox Route10_Text_Girl, MSGBOX_NPC
	end

Route10_Little_Girl::
	lockall
	msgbox Route10_Text_Little_Girl, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement 11, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox Route10_Text_Mother_To_Girl, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_FaceDown
	waitmovement 0
	releaseall
	end

Route10_Little_Boy::
	msgbox Route10_Text_Little_Boy, MSGBOX_NPC
	end

Route10_Mother::
	msgbox Route10_Text_Mother, MSGBOX_NPC
	end

Route10_Father::
	msgbox Route10_Text_Father, MSGBOX_NPC
	end

Route10_SUBO_1::
	msgbox Route10_Text_SUBO_1, MSGBOX_NPC
	end

Route10_SUBO_2::
	lockall
	faceplayer
	msgbox Route10_Text_SUBO_2, MSGBOX_DEFAULT
	closemessage
	applymovement 16, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 16, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 15, Common_Movement_FaceRight
	applymovement 16, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox Route10_Text_SUBO_2_2, MSGBOX_DEFAULT
	closemessage
	applymovement 15, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox Route10_Text_SUBO_2_3, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement 15, Common_Movement_FaceUp
	applymovement 16, Common_Movement_FaceUp
	waitmovement 0
	applymovement 15, Common_Movement_ExclamationMark
	applymovement 16, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	applymovement 15, Common_Movement_WalkInPlaceSlowUp
	applymovement 16, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox Route10_Text_SUBO_2_4, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route10_SUBO_3::
	msgbox Route10_Text_SUBO_3, MSGBOX_NPC
	end

Route10_SUBO_4::
	msgbox Route10_Text_SUBO_4, MSGBOX_NPC
	end

Route10_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER, Route10_Text_CarterIntro, Route10_Text_CarterDefeated
	msgbox Route10_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route10_Text_SarahIntro, Route10_Text_SarahDefeated
	msgbox Route10_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Anny::
	trainerbattle_single TRAINER_ANNY, Route10_Text_AnnyIntro, Route10_Text_AnnyDefeated
	msgbox Route10_Text_AnnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL, Route10_Text_MichaelIntro, Route10_Text_MichaelDefeated
	msgbox Route10_Text_MichaelPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Emily::
	trainerbattle_single TRAINER_EMILY, Route10_Text_EmilyIntro, Route10_Text_EmilyDefeated
	msgbox Route10_Text_EmilyPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route10_Text_KalebIntro, Route10_Text_KalebDefeated
	msgbox Route10_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Sign::
	msgbox Route10_Text_Sign, MSGBOX_SIGN
	end

Route10_Sign_Farmond::
	msgbox Route10_Text_Sign_Farmond, MSGBOX_SIGN
	end

Route10_Text_Sign:
	.string "Route 10\n"
	.string "{LEFT_ARROW} Pinleaf Town$"

Route10_Text_Sign_Farmond:
	.string "The original text of this signpost\n"
	.string "appears to have read “Farmond City”…\p"
	.string "Someone has now written “{COLOR}{RED}Mayhem City{COLOR}{DARK_GRAY}”\n"
	.string "over it with blood-red graffiti.$"

Route10_Text_Man:
	.string "{COLOR}{BLUE}Some people think this is a river, but\n"
	.string "it's not - it's the sea!\p"
	.string "Either way, it looks like I'll need\n"
	.string "Surf to get across.$"

Route10_Text_Boy:
	.string "{COLOR}{BLUE}I heard you can scale down these grass\n"
	.string "mounds.\p"
	.string "I'm too afraid to even try, mind you.\n"
	.string "They do look pretty steep.$"

Route10_Text_Girl:
	.string "{COLOR}{RED}Ever since SUBO took over Farmond\n"
	.string "City, we're seeing more people here.\p"
	.string "They're all fleeing to Pinleaf Town.\n"
	.string "It's heartbreaking to see…$"

Route10_Text_Little_Girl:
	.string "{COLOR}{RED}Where will we go now, Mom?$"

Route10_Text_Mother_To_Girl:
	.string "{COLOR}{RED}We'll stay here and try to get past\n"
	.string "the thugs, sweetie.$"

Route10_Text_Little_Boy:
	.string "{COLOR}{BLUE}I left my toys at home when they\n"
	.string "forced everyone out of Farmond City…\p"
	.string "And now I'm hungry…$"

Route10_Text_Mother:
	.string "{COLOR}{RED}Our home is gone.\p"
	.string "These thugs destroyed our neighborhood\n"
	.string "and forced us out of the city.\p"
	.string "Where will we go now…?$"

Route10_Text_Father:
	.string "{COLOR}{BLUE}Ever since the SUBO took over, they've\n"
	.string "made Farmond City their playground.\p"
	.string "Trainer!\n"
	.string "Could you find a way to help us?$"

Route10_Text_SUBO_1:
	.string "{COLOR}{BLUE}Oi, oi, oi.\p"
	.string "You better stay away from here, unless\n"
	.string "you're in for some Grade-A pummelling!$"

Route10_Text_SUBO_2:
	.string "{COLOR}{BLUE}Farmond City is ours!$"

Route10_Text_SUBO_2_2:
	.string "{COLOR}{BLUE}Hey!\p"
	.string "We don't call it Farmond City anymore!\n"
	.string "The name's now Mayhem City!$"

Route10_Text_SUBO_2_3:
	.string "{COLOR}{BLUE}Oh, right…$"

Route10_Text_SUBO_2_4:
	.string "Both Grunts: {COLOR}{BLUE}Mayhem City is ours!!$"

Route10_Text_SUBO_3:
	.string "{COLOR}{BLUE}Keep your distance, punk.\p"
	.string "Only Trainers who mean business may\n"
	.string "pass through here!$"

Route10_Text_SUBO_4:
	.string "{COLOR}{BLUE}Guard duty is sooo boring…\p"
	.string "I wish I could be in Mayhem City right\n"
	.string "now, smashing some stuff up!$"
