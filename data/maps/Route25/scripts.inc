Route25_MapScripts::
	.byte 0

Route25_Man::
	msgbox Route25_Text_Man, MSGBOX_NPC
	end

Route25_Sign::
	msgbox Route25_Text_Sign, MSGBOX_SIGN
	end

Route25_Text_Sign:
	.string "Route 25\n"
	.string "Chandra Village {RIGHT_ARROW}$"

Route25_Text_Man:
	.string "{COLOR}{BLUE}As you can see, a devastating rock\n"
	.string "slide has caused this mess…\p"
	.string "It's going to have to get cleaned up\n"
	.string "before we can proceed.$"
