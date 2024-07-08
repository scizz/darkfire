Route11_MapScripts::
	.byte 0

Route11_Sign::
	msgbox Route11_Text_Sign, MSGBOX_SIGN
	end

Route11_Sign_Ernie::
	msgbox Route11_Text_Sign_Ernie, MSGBOX_SIGN
	end

Route11_Text_Sign:
	.string "Route 11\n"
	.string "{LEFT_ARROW} Pinleaf Town$"

Route11_Text_Sign_Ernie:
	.string "Ernie's House$"
