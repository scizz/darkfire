Route110_TrickHousePuzzle4_MapScripts:: @ 826C860
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll:: @ 826C861
	lockall
	compare VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0
	goto_if_eq Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll:: @ 826C873
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Yuji:: @ 826C895
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened: @ 826C8C3
	.string "{PLAYER} wrote down the secret code\n"
	.string "on the door.\p"
	.string "“TRICK MASTER is cool.”\n"
	.string "… … … … … … … …\p"
	.string "The lock clicked open!$"

Route110_TrickHousePuzzle4_Text_YujiIntro: @ 826C9E4
	.string "Heh! Boulders like this, I can brush\n"
	.string "aside with one finger!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat: @ 826CA20
	.string "I can push boulders, but I can't solve\n"
	.string "the puzzle…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle: @ 826CA53
	.string "It's not good enough to be brawny…\n"
	.string "You have to use your head. Be brainy!$"
