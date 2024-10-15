WaterwayCity_House5_MapScripts::
	.byte 0

WaterwayCity_House5_MrSurf::
	lock
	faceplayer
	checkitem ITEM_HM03_SURF, 1
	compare VAR_RESULT, 1
	goto_if_ge WaterwayCity_House5_MrSurf_Given
	msgbox WaterwayCity_House5_Text_MrSurf, MSGBOX_AUTOCLOSE
	giveitem ITEM_HM03_SURF, 1
	goto WaterwayCity_House5_MrSurf_Given
	end

WaterwayCity_House5_MrSurf_Given::
	msgbox WaterwayCity_House5_Text_MrSurfGiven, MSGBOX_AUTOCLOSE
	release
	end

WaterwayCity_House5_Text_MrSurf:
	.string "{COLOR}{BLUE}Golly gee, a visitor!\p"
	.string "I am Mr. Surf.\p"
	.string "The way you look…\n"
	.string "I see the adventure in your eyes!\p"
	.string "…\n"
	.string "Yes, yes!\p"
	.string "You remind me of myself when I was a\n"
	.string "young Trainer, riding the waves with\l"
	.string "my trusty Lapras by my side.\p"
	.string "We used to Surf across every river,\n"
	.string "exploring places no one could reach.\l"
	.string "Those were the days…\p"
	.string "Now, I'm too old to Surf, but I would\n"
	.string "hate to see that skill go to waste.\p"
	.string "You look like the kind of Trainer who\n"
	.string "could put it to good use.\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "That's it, I've decided.\p"
	.string "I'll give you my HM so you can Surf\n"
	.string "the waves too!$"

WaterwayCity_House5_Text_MrSurfGiven:
	.string "{COLOR}{BLUE}Teach Surf to a strong Water-type\n"
	.string "Pokémon, and you'll be gliding across\l"
	.string "water in no time.\p"
	.string "You can use Surf to cross Route 13 to\n"
	.string "the south.\l"
	.string "Good luck out there!$"
