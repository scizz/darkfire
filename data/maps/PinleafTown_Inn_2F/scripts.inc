PinleafTown_Inn_2F_MapScripts::
	.byte 0

PinleafTown_Inn_2F_Sign_Door_Locked::
	msgbox PinleafTown_Inn_2F_Text_Sign_Door_Locked, MSGBOX_SIGN
	end

PinleafTown_Inn_2F_Old_Man_TM_Rest::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_REST_PINLEAF, PinleafTown_Inn_2F_Old_Man_TM_Rest_Given
	msgbox PinleafTown_Inn_2F_Text_Old_Man_TM_Rest, MSGBOX_DEFAULT
	checkitem ITEM_LEMONADE, 1
	compare VAR_RESULT, 1
	goto_if_ge PinleafTown_Inn_2F_Old_Man_Got_Lemonade
	releaseall
	end

PinleafTown_Inn_2F_Old_Man_Got_Lemonade::
	msgbox PinleafTown_Inn_2F_Text_Old_Man_Got_Lemonade, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PinleafTown_Inn_2F_Old_Man_Got_Lemonade_Give
	msgbox PinleafTown_Inn_2F_Text_Old_Man_Got_Lemonade_Denied, MSGBOX_DEFAULT
	releaseall
	end

PinleafTown_Inn_2F_Old_Man_Got_Lemonade_Give::
	msgbox PinleafTown_Inn_2F_Text_Old_Man_Got_Lemonade_Give, MSGBOX_DEFAULT
	removeitem ITEM_LEMONADE, 1
	delay 30
	msgbox PinleafTown_Inn_2F_Text_Old_Man_Thanks, MSGBOX_DEFAULT
	giveitem ITEM_TM44, 1
	setflag FLAG_RECEIVED_TM_REST_PINLEAF
	goto PinleafTown_Inn_2F_Old_Man_TM_Rest_Given
	end

PinleafTown_Inn_2F_Old_Man_TM_Rest_Given::
	msgbox PinleafTown_Inn_2F_Text_Old_Man_TM_Rest_Given, MSGBOX_DEFAULT
	releaseall
	end

PinleafTown_Inn_2F_Text_Old_Man_TM_Rest:
	.string "Argh!\n"
	.string "I need Lemonade!\p"
	.string "Those bloody rascals have blocked\n"
	.string "the bridge to the western farm!$"

PinleafTown_Inn_2F_Text_Old_Man_Got_Lemonade:
	.string "…\n"
	.string "…\p"
	.string "What's that? You have some Lemonade?!\n"
	.string "Would you give one to an Old Man?$"

PinleafTown_Inn_2F_Text_Old_Man_Got_Lemonade_Denied:
	.string "I need some of that sweet nectar!\n"
	.string "You don't know the half of it!$"

PinleafTown_Inn_2F_Text_Old_Man_Got_Lemonade_Give:
	.string "You handed the Old Man some\n"
	.string "Lemonade…$"

PinleafTown_Inn_2F_Text_Old_Man_Thanks:
	.string "Thank you so much!\n"
	.string "That has really quenched my thirst.\p"
	.string "I feel much, much better.\n"
	.string "Here, take this for your troubles…$"

PinleafTown_Inn_2F_Text_Old_Man_TM_Rest_Given:
	.string "TM44 is Rest.\n"
	.string "Teach it to a sleepy Pokémon.\p"
	.string "When used in battle, your Pokémon will\n"
	.string "take a snooze and regain their health.\p"
	.string "On that note, I hope you enjoy your\n"
	.string "snooze here in the Pinleaf Town Inn!$"

PinleafTown_Inn_2F_Text_Sign_Door_Locked:
	.string "This room is occupied.\n"
	.string "Better not disturb them!$"
