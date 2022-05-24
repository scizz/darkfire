Route7_MapScripts::
	.byte

Route7_Sign::
	msgbox Route7_Text_Sign, MSGBOX_SIGN
	end

Route7_Sign_Tamarok::
	msgbox Route7_Text_Sign_Tamarok, MSGBOX_SIGN
	end

Route7_Sign_Door::
	msgbox Route7_Text_Sign_Door, MSGBOX_SIGN
	end
	
Route7_Man::
	msgbox Route7_Text_Man, MSGBOX_NPC
	end

Route7_Hiker::
	lock
	faceplayer
	msgbox Route7_Text_Hiker_Question, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route7_Hiker_Yes
	msgbox Route7_Text_Hiker_No, MSGBOX_DEFAULT
	release
	end

Route7_Hiker_Yes::
	msgbox Route7_Text_Hiker_Heal, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	delay 10
	msgbox Route7_Text_Hiker_Yes, MSGBOX_DEFAULT
	release
	end

Route7_EventScript_Dillion::
	trainerbattle_single TRAINER_DILLION, Route7_Text_DillionIntro, Route7_Text_DillionDefeated
	msgbox Route7_Text_DillionPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Tori::
	trainerbattle_double TRAINER_TORI_AND_TIA, Route7_Text_ToriIntro, Route7_Text_ToriDefeat, Route7_Text_ToriNotEnoughMons
	msgbox Route7_Text_ToriPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Tia::
	trainerbattle_double TRAINER_TORI_AND_TIA, Route7_Text_TiaIntro, Route7_Text_TiaDefeat, Route7_Text_TiaNotEnoughMons
	msgbox Route7_Text_TiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE, Route7_Text_IreneIntro, Route7_Text_IreneDefeated
	msgbox Route7_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Marta::
	trainerbattle_single TRAINER_MARTA, Route7_Text_MartaIntro, Route7_Text_MartaDefeated
	msgbox Route7_Text_MartaPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON, Route7_Text_JacksonIntro, Route7_Text_JacksonDefeated
	msgbox Route7_Text_JacksonPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY, Route7_Text_CyndyIntro, Route7_Text_CyndyDefeated
	msgbox Route7_Text_CyndyPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Lawrence::
	trainerbattle_single TRAINER_LAWRENCE, Route7_Text_LawrenceIntro, Route7_Text_LawrenceDefeated
	msgbox Route7_Text_LawrencePostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, Route7_Text_EdgarIntro, Route7_Text_EdgarDefeated
	msgbox Route7_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_Text_Sign:
	.string "Route 7\n"
	.string "{LEFT_ARROW} Mt. Tamarok$"

Route7_Text_Sign_Tamarok:
	.string "Tamarok Tunnels {UP_ARROW}$"

Route7_Text_Sign_Door:
	.string "The door is locked.\n"
	.string "Must be no one at home…$"

Route7_Text_Man:
	.string "{COLOR}{BLUE}This is it.\n"
	.string "The foot of Mt. Tamarok.\p"
	.string "There's no better training for your\n"
	.string "Pokémon than this rough climb through\l"
	.string "the ice and snow.\p"
	.string "Many fail.\p"
	.string "The ones who succeed may have a chance\n"
	.string "at the tournaments at Northstar City.\p"
	.string "I hope you're ready for the ride…\n"
	.string "I know I am.$"

Route7_Text_Hiker_Question:
	.string "Oy lad, you must'a been climbing for a\n"
	.string "while.\p"
	.string "Why don't you rest here by the fire\n"
	.string "for a wee bit and listen to a story?$"

Route7_Text_Hiker_No:
	.string "No?\p"
	.string "Oh…\n"
	.string "Another time then, kind friend.$"

Route7_Text_Hiker_Heal:
	.string "Let's ‘ave a quick rest first before\n"
	.string "I begin with my story…$"

Route7_Text_Hiker_Yes:
	.string "Okay!\n"
	.string "Listen up, kid.\p"
	.string "Somewhere past this point, the tunnels\n"
	.string "of Tamarok lead to its peak.\p"
	.string "I've been there only once, as it\n"
	.string "requires a lot of strength to only get\l"
	.string "as far as where we currently are.\p"
	.string "But I can tell you, the peak is not\n"
	.string "barren, as you'd expect.\p"
	.string "There's a temple of ice up there, an\n"
	.string "amazing, ancient edifice, elaborate as\l"
	.string "if built by a God.\p"
	.string "…\n"
	.string "…\p"
	.string "Ha!\n"
	.string "You think I'm joking!\p"
	.string "Well, brave through the cold and\n"
	.string "you'll see for yourself!$"
