.set LOCALID_LITTLE_GIRL, 3

AnheimTown_MapScripts::
	.byte 0

AnheimTown_Sign::
	msgbox AnheimTown_Sign_Text, MSGBOX_SIGN
	end

AnheimTown_Sign_Church::
	msgbox AnheimTown_Sign_Church_Text, MSGBOX_SIGN
	end

AnheimTown_Sign_Protector::
	msgbox AnheimTown_Sign_Protector_Text, MSGBOX_SIGN
	end

AnheimTown_Girl::
	msgbox AnheimTown_Text_Girl, MSGBOX_NPC
	end

AnheimTown_Little_Girl::
	msgbox AnheimTown_Text_Little_Girl, MSGBOX_NPC
	end

AnheimTown_Mother::
	msgbox AnheimTown_Text_Mother, MSGBOX_NPC
	end

AnheimTown_Gentleman::
	msgbox AnheimTown_Text_Gentleman, MSGBOX_NPC
	end

AnheimTown_Boy::
	msgbox AnheimTown_Text_Boy, MSGBOX_NPC
	end

AnheimTown_Girl_2::
	msgbox AnheimTown_Text_Girl_2, MSGBOX_NPC
	end

AnheimTown_Man::
	lock
	faceplayer
	msgbox AnheimTown_Text_Man, MSGBOX_AUTOCLOSE
	applymovement 15, Common_Movement_FaceDown
	waitmovement 0
	release
	end

AnheimTown_Story_Time::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceUp
	waitmovement 0
	end

AnheimTown_Story_Time2::
	lock
	faceplayer
	msgbox AnheimTown_Text_Little_Girl_Story, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq AnheimTown_Little_Girl_Yes
	msgbox AnheimTown_Text_Little_Girl_No, MSGBOX_AUTOCLOSE
	release
	end

AnheimTown_Little_Girl_Yes::
	closemessage
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 41
	goto_if_eq AnheimTown_Little_Girl_Bottom
	compare VAR_TEMP_0, 39
	goto_if_eq AnheimTown_Little_Girl_Left
	compare VAR_TEMP_0, 41
	goto_if_eq AnheimTown_Little_Girl_Right
	goto AnheimTown_Little_Girl_Top
	end

AnheimTown_Little_Girl_Bottom::
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	goto AnheimTown_Little_Girl_Main
	end

AnheimTown_Little_Girl_Left::
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	goto AnheimTown_Little_Girl_Main
	end

AnheimTown_Little_Girl_Right::
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	goto AnheimTown_Little_Girl_Main
	end

AnheimTown_Little_Girl_Top::
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	goto AnheimTown_Little_Girl_Main
	end

AnheimTown_Little_Girl_Main::
	msgbox AnheimTown_Text_Little_Girl_Story_Yes, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceUp
	waitmovement 0
	call Common_EventScript_GetPlayerPos
	compare VAR_TEMP_1, 41
	goto_if_eq AnheimTown_Little_Girl_MainBottom
	compare VAR_TEMP_0, 39
	goto_if_eq AnheimTown_Little_Girl_MainLeft
	compare VAR_TEMP_0, 41
	goto_if_eq AnheimTown_Little_Girl_MainRight
	goto AnheimTown_Little_Girl_MainTop
	end

AnheimTown_Little_Girl_MainTop::
	applymovement OBJ_EVENT_ID_PLAYER, WLFR
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER, WLFFR
	waitmovement 0
	goto Little_Girl_MainStep
	end

AnheimTown_Little_Girl_MainBottom::
	applymovement OBJ_EVENT_ID_PLAYER, WLFR
	applymovement OBJ_EVENT_ID_FOLLOWER, WLFFR
	waitmovement 0
	goto Little_Girl_MainStep
	end

AnheimTown_Little_Girl_MainLeft::
	applymovement OBJ_EVENT_ID_PLAYER, WLFR
	applymovement OBJ_EVENT_ID_FOLLOWER, WLFFR
	waitmovement 0
	goto Little_Girl_MainStep
	end

AnheimTown_Little_Girl_MainRight::
	applymovement OBJ_EVENT_ID_PLAYER, WLFR
	applymovement OBJ_EVENT_ID_FOLLOWER, WLFFR
	waitmovement 0
	goto Little_Girl_MainStep
	end

Little_Girl_MainStep::
	applymovement 3, GirlPhaseOne
	waitmovement 0
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceSlowRight
	waitmovement 0
	msgbox AnheimTown_Text_Little_Girl_Story_One, MSGBOX_AUTOCLOSE
	applymovement 3, GirlPhaseTwo
	waitmovement 0
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox AnheimTown_Text_Little_Girl_Story_Two, MSGBOX_AUTOCLOSE
	applymovement 3, GirlPhaseThree
	applymovement OBJ_EVENT_ID_PLAYER, FollowGirl
	waitmovement 0
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceSlowLeft
	waitmovement 0
	msgbox AnheimTown_Text_Little_Girl_Story_Three, MSGBOX_AUTOCLOSE
	applymovement 3, GirlFirstRock
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox AnheimTown_Text_Little_Girl_First_Rock, MSGBOX_AUTOCLOSE
	applymovement 3, GirlSecondRock
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox AnheimTown_Text_Little_Girl_Second_Rock, MSGBOX_AUTOCLOSE
	applymovement 3, GirlToPlayer
	waitmovement 0
	msgbox AnheimTown_Text_Little_Girl_To_Player, MSGBOX_AUTOCLOSE
	applymovement 3, GirlToPosition
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	release
	end

AnheimTown_Old_Man::
	msgbox AnheimTown_Text_Old_Man, MSGBOX_NPC
	end

AnheimTown_Sign_Text:
	.string "Anheim Town\n"
	.string "{FONT_SMALL}“Windswept Trees With Fragrance of Unity”$"

AnheimTown_Sign_Church_Text:
	.string "Anheim Church$"

AnheimTown_Sign_Protector_Text:
	.string "R.I.P\n"
	.string "Protector of The Forest.$"

AnheimTown_Text_Girl:
	.string "{COLOR}{RED}Have you seen our church?\n"
	.string "It's magnificent!\p"
	.string "I don't know why, but it isn't open all\n"
	.string "the time…$"

AnheimTown_Text_Little_Girl:
	.string "{COLOR}{RED}I wanted to play with Diane next door,\n"
	.string "but my mom won't let me.\p"
	.string "I can't wait until I'm older so I can\n"
	.string "sneak out more easily!$"

AnheimTown_Text_Mother:
	.string "{COLOR}{RED}I saw some shady men walk by earlier…\p"
	.string "They were headed for Tenjo Highroad in\n"
	.string "Route 5.\p"
	.string "I can't let my child out of my sight\n"
	.string "with characters like those around!$"

AnheimTown_Text_Gentleman:
	.string "I once spent a short vacation in the\n"
	.string "Tenjo Mountains.\p"
	.string "I met a wise man along my travels and\n"
	.string "I'll never forget what he told me.\p"
	.string "He said: “If an egg is broken by an\n"
	.string "outside force, life ends.\p"
	.string "If however an egg is broken by an\n"
	.string "inside force, life begins.”\p"
	.string "Great things always begin from the\n"
	.string "inside.$"

AnheimTown_Text_Boy:
	.string "{COLOR}{BLUE}There used to be a train station here,\n"
	.string "but as you can probably see, it has\l"
	.string "been abandoned.\p"
	.string "There isn't much use for trains\n"
	.string "nowadays since you can just fly around\l"
	.string "on your Pokémon, provided you have one.$"

AnheimTown_Text_Girl_2:
	.string "{COLOR}{RED}Rumors say there exists a Mythical\n"
	.string "Pokémon that resembles an onion.\p"
	.string "The Pokémon can time-travel, visiting\n"
	.string "various undisturbed forests during\l"
	.string "peaceful times.\p"
	.string "Wherever it visits, it leaves behind\n"
	.string "flourishing grass and trees.$"

AnheimTown_Text_Little_Girl_Story:
	.string "{COLOR}{RED}Hello!\n"
	.string "My name's Diane.\p"
	.string "My dad once told me the story of the\n"
	.string "Wise Pathfinder…\l"
	.string "You wanna hear it?$"

AnheimTown_Text_Little_Girl_No:
	.string "{COLOR}{RED}Awww, I really wanted to tell it…\n"
	.string "I'll be here if you change your mind!$"

AnheimTown_Text_Little_Girl_Story_Yes:
	.string "{COLOR}{RED}All right!\p"
	.string "The Wise Pathfinder was a legendary\n"
	.string "Hiker, and one of the first people\l"
	.string "to climb the Tenjo Highroad.$"

AnheimTown_Text_Little_Girl_Story_One:
	.string "{COLOR}{RED}In his journey, he found a rock. But\n"
	.string "he walked past it, because he was wise.$"

AnheimTown_Text_Little_Girl_Story_Two:
	.string "{COLOR}{RED}Then, he came upon a second rock. But\n"
	.string "he didn't look at it, or even think of\l"
	.string "it, because he was wise.$"

AnheimTown_Text_Little_Girl_Story_Three:
	.string "{COLOR}{RED}And finally, he found a third rock.\p"
	.string "He had the great idea that touching the\n"
	.string "rock would help him find enlightenment.$"

AnheimTown_Text_Little_Girl_First_Rock:
	.string "{COLOR}{RED}He figured that, after that, if he went\n"
	.string "back and touched the first rock…$"

AnheimTown_Text_Little_Girl_Second_Rock:
	.string "{COLOR}{RED}And after that go touch the second\n"
	.string "rock…$"

AnheimTown_Text_Little_Girl_To_Player:
	.string "{COLOR}{RED}Then his soul would find enlightenment.\p"
	.string "That's the story.\p"
	.string "I'm not sure what the meaning of it is.\n"
	.string "I ignore rocks all the time!$"

AnheimTown_Text_Old_Man:
	.string "Here lies The Protector of The Forest.\p"
	.string "He was once a famed Pokémon Trainer who\n"
	.string "rose to defend the people of this town\l"
	.string "from those who sought to exploit them.\p"
	.string "Just as he succeeded in his efforts,\n"
	.string "his life was lost…\p"
	.string "We have dedicated this place to him as\n"
	.string "our thanks.$"

AnheimTown_Text_Man:
	.string "{COLOR}{BLUE}The bond between people and Pokémon\n"
	.string "is like the ripples of this pond…\l"
	.string "Ever-expanding and connecting us all.\p"
	.string "Meditate here with your Pokémon, and\n"
	.string "you too may discover hidden strengths.$"

GirlPhaseOne:
	walk_up
	face_right
	step_end

GirlPhaseTwo:
	walk_up
	walk_right
	walk_up
	face_left
	step_end

GirlPhaseThree:
	walk_up
	walk_fast_left
	walk_up
	face_left
	step_end

FollowGirl:
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

GirlFirstRock:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_right
	face_up
	step_end

GirlSecondRock:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	face_left
	step_end

GirlToPlayer:
	walk_down
	walk_left
	step_end

GirlToPosition:
	walk_down
	walk_down
	step_end

WLFFR:
	walk_left
	follower_face_right
	step_end
