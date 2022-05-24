Route1_MapScripts::
	.byte 0

Route1_Jump_Event::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_1_POND_JUMP, Route1_Jump_Event_Complete
	msgbox Route1_Jump_Text, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 60
	applymovement 2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route1_Jump_Text_2, MSGBOX_NPC
	applymovement 2, WalkRightFaceDown
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox Route1_Jump_Text_3, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement 2, JumpDown
	playse SE_LEDGE
	waitse
	waitmovement 0
	delay 30
	applymovement 2, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	applymovement 2, JumpUpWalkLeft
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox Route1_Jump_Text_4, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, StepLeftFaceRight
	applymovement 2, StepLeftUpFaceDown
	waitmovement 0
	setflag FLAG_ROUTE_1_POND_JUMP
	release
	end

Route1_Jump_Event_Complete::
	msgbox Route1_Jump_Text_5, MSGBOX_NPC
	end

Route1_Old_Man::
	msgbox Route1_Old_Man_Text, MSGBOX_NPC
	end

Route1_Boy::
	msgbox Route1_Boy_Text, MSGBOX_NPC
	end

Route1_Location_Sign::
	msgbox Route1_Location_Sign_Text, MSGBOX_SIGN
	end

Route1_Jump_Text:
	.string "{COLOR}{BLUE}Hey!\n"
	.string "A new Trainer!\p"
	.string "Listen…\p"
	.string "Do you see how close the pond banks are\n"
	.string "to each other right here?$"

Route1_Jump_Text_2:
	.string "{COLOR}{BLUE}…\n"
	.string "I'm gonna try and jump it!\p"
	.string "Haha!\n"
	.string "Watch and learn!$"

Route1_Jump_Text_3:
	.string "{COLOR}{BLUE}Okay!\n"
	.string "Here goes nothing!$"

Route1_Jump_Text_4:
	.string "{COLOR}{BLUE}Haha! Did you see that?!\n"
	.string "That was too easy!\p"
	.string "Now your turn!$"

Route1_Jump_Text_5:
	.string "{COLOR}{BLUE}You can jump over small gaps like this\n"
	.string "anywhere in the Tenjo region.\p"
	.string "Be sure to keep a look out for them.\n"
	.string "Who knows what secrets you'll find!$"

Route1_Old_Man_Text:
	.string "Lots of beginners go through this route,\n"
	.string "and I get to see them all.\p"
	.string "They remind me of when I was a wee lad,\n"
	.string "starting out my journey…\p"
	.string "Great things await ahead!$"

Route1_Boy_Text:
	.string "{COLOR}{BLUE}I managed to get this far without a\n"
	.string "Pokémon, but now I'm afraid to go on!$"

Route1_Location_Sign_Text:
	.string "Route 1\n"
	.string "The Route of New Beginnings!$"

JumpDown:
	jump_2_down
	step_end

JumpUpWalkLeft:
	jump_2_up
	walk_left
	step_end

WalkRightFaceDown:
	walk_right
	face_down
	step_end

StepLeftFaceRight:
	walk_left
	face_right
	step_end

StepLeftUpFaceDown:
	walk_left
	walk_up
	face_down
	step_end
