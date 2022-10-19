Route11_MapScripts::
	.byte 0

Route11_Man::
	lock
	faceplayer
	msgbox Route11_Text_HereYaGo, MSGBOX_DEFAULT
	setflag FLAG_SYS_DEXNAV_GET
	release
	end

Route11_Text_HereYaGo:
	.string "Here's a DexNav.$"
