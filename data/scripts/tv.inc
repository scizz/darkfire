EventScript_TV::
	lockall
	incrementgamestat GAME_STAT_WATCHED_TV
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForPlayersHouseNews
	goto_if_eq VAR_RESULT, PLAYERS_HOUSE_TV_MOVIE, EventScript_PlayersHouseMovie
	goto_if_eq VAR_RESULT, PLAYERS_HOUSE_TV_LATI, EventScript_PlayersHouseLatiNewsFlash
	goto_if_unset FLAG_SYS_TV_START, EventScript_MomDadMightLikeThis1
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_MomDadMightLikeThis1
	specialvar VAR_RESULT, IsGabbyAndTyShowOnTheAir
	goto_if_eq VAR_RESULT, TRUE, EventScript_DoInSearchOfTrainers
	goto EventScript_TryDoPokeNews
	end

EventScript_TryDoTVShow::
	specialvar VAR_0x8004, GetRandomActiveShowIdx
	goto_if_eq VAR_0x8004, 255, EventScript_MomDadMightLikeThis2
	specialvar VAR_RESULT, GetNextActiveShowIfMassOutbreak
	goto_if_eq VAR_RESULT, 255, EventScript_MomDadMightLikeThis2
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, GetSelectedTVShow
	goto_if_ne VAR_RESULT, 0, EventScript_DoTVShow
	end

EventScript_MomDadMightLikeThis1::
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_PlayersHouseMovie::
	msgbox PlayersHouse_1F_Text_TheresAMovieOnTV, MSGBOX_DEFAULT
	releaseall
	end

@ special InitRoamer is a junk call. Its input var (VAR_0x8004) hasn't been set, and
@ It's called again when Mom actually asks for the color, overwriting
@ whatever it does here.
EventScript_PlayersHouseLatiNewsFlash::
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	special InitRoamer
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	releaseall
	end

@ The following is a loop for the TV show messages
@ VAR_RESULT is set to TRUE when the show has printed its final message
EventScript_DoTVShow::
	special DoTVShow
	waitmessage
	waitbuttonpress
	goto_if_ne VAR_RESULT, TRUE, EventScript_DoTVShow
	goto EventScript_TurnOffTV
	end

EventScript_TurnOffTV::
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_MomDadMightLikeThis2::
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	goto EventScript_TurnOffTV
	end

EventScript_TryDoPokeNews::
	special DoPokeNews
	goto_if_eq VAR_RESULT, FALSE, EventScript_TryDoTVShow
	waitmessage
	waitbuttonpress
	goto EventScript_TurnOffTV
	end

EventScript_DoInSearchOfTrainers::
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	goto_if_eq VAR_RESULT, 0, EventScript_DoInSearchOfTrainers
	goto EventScript_TurnOffTV
	end

TV::
	msgbox PlayerPickedUpTheTVRemote, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

TV_Off::
	msgbox TheTVIsSwitchedOff, MSGBOX_SIGN
	end

TV_SelectAChannel::
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, TV_SelectAChannelExpanded
	message PleaseSelectAChannel
	waitmessage
	multichoice 0, 0, MULTI_TV_SELECT_CHANNEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TryTenNews
	case 1, EventScript_TV_TryPokeTalk
	case 2, EventScript_TV_TryDrowzeePodcast
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

TV_SelectAChannelExpanded::
	message PleaseSelectAChannel
	waitmessage
	multichoice 0, 0, MULTI_TV_SELECT_CHANNEL_EXPANDED, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TryTenNews
	case 1, EventScript_TV_TryPokeTalk
	case 2, EventScript_TV_TryTrainerWatch
	case 3, EventScript_TV_TryDrowzeePodcast
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

TV_PlayerPutDownTheTvRemote::
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TryTenNews::
	call EventScript_TV_TenNewsSetScreen
	special DrawWholeMapView
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_TenNewsEp4
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_TenNewsEp3
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, EventScript_TV_TenNewsEp2
	goto EventScript_TV_TenNewsEp1
	end

EventScript_TV_TryPokeTalk::
	call EventScript_TV_PokeTalkSetScreen
	special DrawWholeMapView
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_PokeTalkEp4
	goto_if_set FLAG_BADGE02_GET, EventScript_TV_PokeTalkEp3
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_PokeTalkEp2
	goto EventScript_TV_PokeTalkEp1
	end

EventScript_TV_TryTrainerWatch::
	call EventScript_TV_TrainerWatchSetScreen
	special DrawWholeMapView
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_TrainerWatchEp3
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_TrainerWatchEp2
	goto EventScript_TV_TrainerWatchEp1
	end

EventScript_TV_TryCliffShow::
	call EventScript_TV_CliffShowSetScreen
	special DrawWholeMapView
	@goto_if_set FLAG_BADGE03_GET, EventScript_TV_CliffShowEp3
	@goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_CliffShowEp2
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, EventScript_TV_CliffShowEp1
	goto EventScript_TV_CliffShowEp1
	end

EventScript_TV_TryDrowzeePodcast::
	call EventScript_TV_DrowzeePodcastSetScreen
	special DrawWholeMapView
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_DrowzeePodcastEp3
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_DrowzeePodcastEp2
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, EventScript_TV_DrowzeePodcastEp1
	goto EventScript_TV_DrowzeePodcastEp1
	end

@ TEN News

EventScript_TV_TenNewsEp1::
	message TodayOnTenNewsShouldChildren
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp1Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp1Pt1::
	message OurCorrespondentWillBeLive
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp1Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp1Pt2::
	msgbox NextUpPokemonTheft, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_TenNewsEp2::
	message TodayOnTenNewsBreakingNews
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp2Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp2Pt1::
	message OfAllPlacesItWasAnAbandonedMuseum
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp2Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp2Pt2::
	msgbox InOtherNewsGlobalWarming, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_TenNewsEp3::
	message TodayOnTenNewsALoudExplosion
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp3Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp3Pt1::
	message OurReporterWillBeLiveInLaveriaCity
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp3Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp3Pt2::
	msgbox NextUpAPokemonTheftEpidemic, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_TenNewsEp4::
	message TodayOnTenNewsTheSubo
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp4Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp4Pt1::
	message TheSameGroupOfSuboThugs
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TenNewsEp4Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TenNewsEp4Pt2::
	msgbox InOtherNewsFarmondCity, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

@ Poké Talk

EventScript_TV_PokeTalkEp1::
	message ThanksForTuningInToPokeTalk1
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp1Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_PokeTalkEp1Pt1::
	msgbox LetsDiveRightInLydia, MSGBOX_AUTOCLOSE
	msgbox HelloPokeTalkLydia, MSGBOX_AUTOCLOSE
	message ThankYouLydia
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp1Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_PokeTalkEp1Pt2::
	msgbox NextUpIHaveMarcus, MSGBOX_AUTOCLOSE
	msgbox ThankYouGeraldHelloPokeTalkViewers, MSGBOX_AUTOCLOSE
	msgbox ThankYouMarcus, MSGBOX_AUTOCLOSE
	msgbox ISawASeviperSlitheringAround, MSGBOX_AUTOCLOSE
	msgbox HahaVeryWiseIndeedThankYou, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_PokeTalkEp2::
	message YoureWatchingPokeTalkTamarokTunnels
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp2Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_PokeTalkEp2Pt1::
	msgbox HugoYoureOnPokeTalk, MSGBOX_AUTOCLOSE
	msgbox LoudAnClearGerald, MSGBOX_AUTOCLOSE
	msgbox WeveReceivedSomeReports, MSGBOX_AUTOCLOSE
	msgbox WelpImSittinHere, MSGBOX_AUTOCLOSE
	msgbox ThatsTheCaveComplex, MSGBOX_AUTOCLOSE
	msgbox HugoYeaYea, MSGBOX_AUTOCLOSE
	msgbox WhatDoYouThinkCausedTheExplosion, MSGBOX_AUTOCLOSE
	msgbox WelpTheresLotsOfStories, MSGBOX_AUTOCLOSE
	message ThankYouHugo
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp2Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_PokeTalkEp2Pt2::
	msgbox NextUpRangerErin, MSGBOX_AUTOCLOSE
	msgbox HelloTenjoRangerErinHere, MSGBOX_AUTOCLOSE
	msgbox WhatExactlyIsTheRangersFederation, MSGBOX_AUTOCLOSE
	msgbox WeAreAGroupOfLikeminded, MSGBOX_AUTOCLOSE
	msgbox ButDontWeHaveThatKindOfThing, MSGBOX_AUTOCLOSE
	msgbox TheTenjoGovernmentAreSlowInTheirActions, MSGBOX_AUTOCLOSE
	msgbox VeryGoodWhereCanPeopleFindYou, MSGBOX_AUTOCLOSE
	msgbox YouCanFindUsAllAroundTheRegion, MSGBOX_AUTOCLOSE
	msgbox ThankYouForYourServiceErin, MSGBOX_AUTOCLOSE
	msgbox ThankYouGeraldGoodbyePokeTalk, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_PokeTalkEp3::
	message YoureWatchingPokeTalkAWildSnorlax
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp3Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_PokeTalkEp3Pt1::
	msgbox LetsDiveRightInRoute9, MSGBOX_AUTOCLOSE
	msgbox DavidCrystalClearGerald, MSGBOX_AUTOCLOSE
	msgbox WonderfulStuffDavid, MSGBOX_AUTOCLOSE
	msgbox EarlierTodayAWildSnorlax, MSGBOX_AUTOCLOSE
	msgbox HahaWellThatIsCertainlyNotThePlace, MSGBOX_AUTOCLOSE
	msgbox VeryMuchSoGeraldIHaveSeen, MSGBOX_AUTOCLOSE
	msgbox APokeFluteWellIfAnyTrainer, MSGBOX_AUTOCLOSE
	message SureThingGerald
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp3Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_PokeTalkEp3Pt2::
	msgbox NextUpWeHaveRangerTed, MSGBOX_AUTOCLOSE
	msgbox TedBreakingUp1, MSGBOX_AUTOCLOSE
	msgbox HelloTed, MSGBOX_AUTOCLOSE
	msgbox TedBreakingUp2, MSGBOX_AUTOCLOSE
	msgbox TedWeCantHearYou, MSGBOX_AUTOCLOSE
	msgbox TedBreakingUp3, MSGBOX_AUTOCLOSE
	msgbox AndWeveLostHimWellTrainersAndShinyHunters, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_PokeTalkEp4::
	message YoureWatchingPokeTalkASudowoodoEpidemic
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp4Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_PokeTalkEp4Pt1::
	msgbox ICurrentlyHaveOldManJackson, MSGBOX_AUTOCLOSE
	msgbox HelloGeraldYesIBloodyWellCan, MSGBOX_AUTOCLOSE
	msgbox HowTragicWhereDidTheyComeFrom, MSGBOX_AUTOCLOSE
	msgbox WhoKnowsItMustBeMatingSeasonOrSomething, MSGBOX_AUTOCLOSE
	msgbox WellGetYourLemondadeJackson, MSGBOX_AUTOCLOSE
	msgbox GrrhhHmphIllBeInThePinleafTownInn, MSGBOX_AUTOCLOSE
	msgbox YouHeardThatEverybodyLetsGetJackson, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

@ Trainer Watch

EventScript_TV_TrainerWatchEp1::
	message WelcomeToTrainerWatch1
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TrainerWatchEp1Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TrainerWatchEp1Pt1::
	message AlthoughThereAreFewGenerationalPhenomenons
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TrainerWatchEp1Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TrainerWatchEp1Pt2::
	msgbox ButJennyIsntTheOnlyTrainer, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_TrainerWatchEp2::
	message WelcomeBackToTrainerWatch
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TrainerWatchEp2Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TrainerWatchEp2Pt1::
	message FancyATreacherousHikeThrough
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TrainerWatchEp2Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TrainerWatchEp2Pt2::
	msgbox OhTheClassicEnduranceBattle, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_TrainerWatchEp3::
	message WelcomeBackToTrainerWatchRakazRosePlayer
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TrainerWatchEp3Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TrainerWatchEp3Pt1::
	message NorthstarCityItIsThePlaceOfTheGrandTournament
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TrainerWatchEp3Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TrainerWatchEp3Pt2::
	msgbox InLighterNewsPlayer, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

@ Cliff Show

EventScript_TV_CliffShowEp1::
	message WelcomeOneWelcomeAll
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_CliffShowEp1Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_CliffShowEp1Pt1::
	msgbox IfYouTakeALookAround, MSGBOX_AUTOCLOSE
	playse SE_M_ROCK_THROW
	msgbox Crash, MSGBOX_DEFAULT
	waitse
	closemessage
	msgbox OopsItBrokeCutCutThat, MSGBOX_AUTOCLOSE
	msgbox AndThatWasItForTheFieldSegment, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

@ Drowzee Podcast

EventScript_TV_DrowzeePodcastEp1::
	message YoureListeningToTheDrowzeePodcast1
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_DrowzeePodcastEp1Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_DrowzeePodcastEp1Pt1::
	msgbox EricHeyJohn, MSGBOX_AUTOCLOSE
	msgbox JohnHuh, MSGBOX_AUTOCLOSE
	msgbox EricYouEverThink, MSGBOX_AUTOCLOSE
	msgbox JohnDotHuh, MSGBOX_AUTOCLOSE
	msgbox EricThinkAboutIt, MSGBOX_AUTOCLOSE
	msgbox JohnGoOn, MSGBOX_AUTOCLOSE
	msgbox EricYeahItsPrettyRare, MSGBOX_AUTOCLOSE
	msgbox JohnDotDotDot, MSGBOX_AUTOCLOSE
	msgbox EricSpindasCoolMan, MSGBOX_AUTOCLOSE
	message JohnYeah
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_DrowzeePodcastEp1Pt2
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_DrowzeePodcastEp1Pt2::
	msgbox EricDoYouThinkIceTypeIsBad, MSGBOX_AUTOCLOSE
	msgbox JohnHuh3, MSGBOX_AUTOCLOSE
	msgbox EricThinkAboutItIceOnlyResistsIce, MSGBOX_AUTOCLOSE
	msgbox JohnYeahYouCouldBeRight, MSGBOX_AUTOCLOSE
	msgbox EricYeahDoWeHaveAnyListenersRightNow, MSGBOX_AUTOCLOSE
	msgbox JohnLetsGoForLunch, MSGBOX_AUTOCLOSE
	msgbox EricNextUpIsGastly, MSGBOX_AUTOCLOSE
	msgbox YoureListeningToTheDrowzeePodcast4, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_DrowzeePodcastEp2::
	message YoureListeningToTheDrowzeePodcast2
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_DrowzeePodcastEp2Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_DrowzeePodcastEp2Pt1::
	msgbox EricHeyJohn2, MSGBOX_AUTOCLOSE
	msgbox JohnHuh2, MSGBOX_AUTOCLOSE
	msgbox EricIHadABadDream, MSGBOX_AUTOCLOSE
	msgbox JohnOhDotDot, MSGBOX_AUTOCLOSE
	msgbox EricYeahIFoundAMasterBall, MSGBOX_AUTOCLOSE
	msgbox JohnHuhDoesntSoundLikeABadDream, MSGBOX_AUTOCLOSE
	msgbox EricItGetsWorse, MSGBOX_AUTOCLOSE
	msgbox JohnHuh5, MSGBOX_AUTOCLOSE
	msgbox EricIGaveItToMyShuckle, MSGBOX_AUTOCLOSE
	msgbox JohnYeahDotDot, MSGBOX_AUTOCLOSE
	msgbox EricYeahThenIGotIntoABattleWithAWildAbra, MSGBOX_AUTOCLOSE
	msgbox JohnNice, MSGBOX_AUTOCLOSE
	msgbox EricNotNiceJohn, MSGBOX_AUTOCLOSE
	msgbox JohnOhNo, MSGBOX_AUTOCLOSE
	msgbox EricItSwappedMyMasterBall, MSGBOX_AUTOCLOSE
	msgbox JohnIThinkItWasTryingToTellYou, MSGBOX_AUTOCLOSE
	msgbox ButJohnWhatMoveFollowed, MSGBOX_AUTOCLOSE
	msgbox JohnHa, MSGBOX_AUTOCLOSE
	msgbox EricYeahItWasPrettyWild, MSGBOX_AUTOCLOSE
	msgbox JohnSeemsLikeIt, MSGBOX_AUTOCLOSE
	msgbox EricDidYouHaveAnyWildDreams, MSGBOX_AUTOCLOSE
	msgbox JohnIDreamtAboutKickingAPsyduck, MSGBOX_AUTOCLOSE
	msgbox YoureListeningToTheDrowzeePodcast3, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_DrowzeePodcastEp3::
	message YoureListeningToTheDrowzeePodcast5
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_DrowzeePodcastEp3Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_DrowzeePodcastEp3Pt1::
	msgbox EricHeyJohn3, MSGBOX_AUTOCLOSE
	msgbox JohnHuh4, MSGBOX_AUTOCLOSE
	msgbox EricItWasQuiteTheJourney, MSGBOX_AUTOCLOSE
	msgbox JohnWhy, MSGBOX_AUTOCLOSE
	msgbox EricISawAYoungGirl, MSGBOX_AUTOCLOSE
	msgbox JohnHuh7, MSGBOX_AUTOCLOSE
	msgbox EricYeahILeftMyHouse, MSGBOX_AUTOCLOSE
	msgbox JohnWow, MSGBOX_AUTOCLOSE
	msgbox EricYeahAPoorYoungGirlScurriedPastMe, MSGBOX_AUTOCLOSE
	msgbox JohnOhNo2, MSGBOX_AUTOCLOSE
	msgbox EricYeahRightAfterThat, MSGBOX_AUTOCLOSE
	msgbox JohnTerrible, MSGBOX_AUTOCLOSE
	msgbox EricYeahItWasWild, MSGBOX_AUTOCLOSE
	msgbox JohnYeahSoWhatWasHeYelling, MSGBOX_AUTOCLOSE
	msgbox EricTheresNoRunning, MSGBOX_AUTOCLOSE
	msgbox YoureListeningToTheDrowzeePodcast4
	goto TV_SelectAChannel
	end

EventScript_TV_DrowzeePodcastEp4::
	message YoureListeningToTheDrowzeePodcast3
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_DrowzeePodcastEp4Pt1
	case 1, TV_SelectAChannel
	case 2, TV_PlayerPutDownTheTvRemote
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_DrowzeePodcastEp4Pt1::
	msgbox EricHeyJohn4, MSGBOX_AUTOCLOSE
	msgbox JohnHuh6, MSGBOX_AUTOCLOSE
	msgbox EricImFeelingPunny, MSGBOX_AUTOCLOSE
	msgbox JohnOhNo3, MSGBOX_AUTOCLOSE
	msgbox EricOhYesPrepare, MSGBOX_AUTOCLOSE
	msgbox JohnNo, MSGBOX_AUTOCLOSE
	msgbox EricWhatPokemonDoesDracula, MSGBOX_AUTOCLOSE
	msgbox JohnHuh8, MSGBOX_AUTOCLOSE
	msgbox EricKoffin, MSGBOX_AUTOCLOSE
	msgbox JohnUgh, MSGBOX_AUTOCLOSE
	msgbox EricWhatDoYouCallALowFatPokemon, MSGBOX_AUTOCLOSE
	msgbox JohnWhatEric, MSGBOX_AUTOCLOSE
	msgbox EricButterfree, MSGBOX_AUTOCLOSE
	msgbox JohnHeh, MSGBOX_AUTOCLOSE
	msgbox EricDoYouBayleaf, MSGBOX_AUTOCLOSE
	msgbox JohnThatWasUnexpected, MSGBOX_AUTOCLOSE
	msgbox EricYouMeanOnixpected, MSGBOX_AUTOCLOSE
	msgbox JohnKeepYourMouthShutPlease, MSGBOX_AUTOCLOSE
	msgbox EricYouMeanMyMeowthShut, MSGBOX_AUTOCLOSE
	msgbox JohnDotDotDot2, MSGBOX_AUTOCLOSE
	msgbox EricIPikachuInTheShower, MSGBOX_AUTOCLOSE
	msgbox JohnBye, MSGBOX_AUTOCLOSE
	msgbox YoureListeningToTheDrowzeePodcast4
	goto TV_SelectAChannel
	end

@ Set Screens

EventScript_TV_TenNewsSetScreen::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownTN
	call_if_eq VAR_TEMP_B, 2, EventScript_TV_UnionCityTN
	call_if_eq VAR_TEMP_B, 3, EventScript_TV_AnheimTownTN
	call_if_eq VAR_TEMP_B, 4, EventScript_TV_LaveriaCityTN
	call_if_eq VAR_TEMP_B, 5, EventScript_TV_HighwindVillageTN
	call_if_eq VAR_TEMP_B, 6, EventScript_TV_NorthstarCityTN
	call_if_eq VAR_TEMP_B, 7, EventScript_TV_PinleafTownTN
	return

EventScript_TV_PokeTalkSetScreen::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownPT
	call_if_eq VAR_TEMP_B, 2, EventScript_TV_UnionCityPT
	call_if_eq VAR_TEMP_B, 3, EventScript_TV_AnheimTownPT
	call_if_eq VAR_TEMP_B, 4, EventScript_TV_LaveriaCityPT
	call_if_eq VAR_TEMP_B, 5, EventScript_TV_HighwindVillagePT
	call_if_eq VAR_TEMP_B, 6, EventScript_TV_NorthstarCityPT
	call_if_eq VAR_TEMP_B, 7, EventScript_TV_PinleafTownPT
	return

EventScript_TV_TrainerWatchSetScreen::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownTW
	call_if_eq VAR_TEMP_B, 2, EventScript_TV_UnionCityTW
	call_if_eq VAR_TEMP_B, 3, EventScript_TV_AnheimTownTW
	call_if_eq VAR_TEMP_B, 4, EventScript_TV_LaveriaCityTW
	call_if_eq VAR_TEMP_B, 5, EventScript_TV_HighwindVillageTW
	call_if_eq VAR_TEMP_B, 6, EventScript_TV_NorthstarCityTW
	call_if_eq VAR_TEMP_B, 7, EventScript_TV_PinleafTownTW
	return

EventScript_TV_CliffShowSetScreen::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownCS
	call_if_eq VAR_TEMP_B, 2, EventScript_TV_UnionCityCS
	call_if_eq VAR_TEMP_B, 3, EventScript_TV_AnheimTownCS
	call_if_eq VAR_TEMP_B, 4, EventScript_TV_LaveriaCityCS
	call_if_eq VAR_TEMP_B, 5, EventScript_TV_HighwindVillageCS
	call_if_eq VAR_TEMP_B, 6, EventScript_TV_NorthstarCityCS
	call_if_eq VAR_TEMP_B, 7, EventScript_TV_PinleafTownCS
	return

EventScript_TV_DrowzeePodcastSetScreen::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownDP
	call_if_eq VAR_TEMP_B, 2, EventScript_TV_UnionCityDP
	call_if_eq VAR_TEMP_B, 3, EventScript_TV_AnheimTownDP
	call_if_eq VAR_TEMP_B, 4, EventScript_TV_LaveriaCityDP
	call_if_eq VAR_TEMP_B, 5, EventScript_TV_HighwindVillageDP
	call_if_eq VAR_TEMP_B, 6, EventScript_TV_NorthstarCityDP
	call_if_eq VAR_TEMP_B, 7, EventScript_TV_PinleafTownDP
	return

EventScript_TV_SunriseTownTN::
	setmetatile 4, 1, 406, 1
	setmetatile 5, 1, 407, 1
	return

EventScript_TV_SunriseTownPT::
	setmetatile 4, 1, 422, 1
	setmetatile 5, 1, 423, 1
	return

EventScript_TV_SunriseTownTW::
	setmetatile 4, 1, 470, 1
	setmetatile 5, 1, 471, 1
	return

EventScript_TV_SunriseTownCS::
	setmetatile 4, 1, 454, 1
	setmetatile 5, 1, 455, 1
	return

EventScript_TV_SunriseTownDP::
	setmetatile 4, 1, 438, 1
	setmetatile 5, 1, 439, 1
	return

EventScript_TV_UnionCityTN::
	setmetatile 7, 1, 408, 1
	setmetatile 8, 1, 409, 1
	return

EventScript_TV_UnionCityPT::
	setmetatile 7, 1, 424, 1
	setmetatile 8, 1, 425, 1
	return

EventScript_TV_UnionCityTW::
	setmetatile 7, 1, 472, 1
	setmetatile 8, 1, 473, 1
	return

EventScript_TV_UnionCityCS::
	setmetatile 7, 1, 456, 1
	setmetatile 8, 1, 457, 1
	return

EventScript_TV_UnionCityDP::
	setmetatile 7, 1, 440, 1
	setmetatile 8, 1, 441, 1
	return

EventScript_TV_AnheimTownTN::
	setmetatile 5, 1, 412, 1
	setmetatile 6, 1, 413, 1
	return

EventScript_TV_AnheimTownPT::
	setmetatile 5, 1, 428, 1
	setmetatile 6, 1, 429, 1
	return

EventScript_TV_AnheimTownTW::
	setmetatile 5, 1, 476, 1
	setmetatile 6, 1, 477, 1
	return

EventScript_TV_AnheimTownCS::
	setmetatile 5, 1, 460, 1
	setmetatile 6, 1, 461, 1
	return

EventScript_TV_AnheimTownDP::
	setmetatile 5, 1, 444, 1
	setmetatile 6, 1, 445, 1
	return

EventScript_TV_LaveriaCityTN::
	setmetatile 3, 1, 410, 1
	setmetatile 4, 1, 411, 1
	return

EventScript_TV_LaveriaCityPT::
	setmetatile 3, 1, 426, 1
	setmetatile 4, 1, 427, 1
	return

EventScript_TV_LaveriaCityTW::
	setmetatile 3, 1, 474, 1
	setmetatile 4, 1, 475, 1
	return

EventScript_TV_LaveriaCityCS::
	setmetatile 3, 1, 458, 1
	setmetatile 4, 1, 459, 1
	return

EventScript_TV_LaveriaCityDP::
	setmetatile 3, 1, 442, 1
	setmetatile 4, 1, 443, 1
	return

EventScript_TV_HighwindVillageTN::
	setmetatile 2, 1, 412, 1
	setmetatile 3, 1, 413, 1
	return

EventScript_TV_HighwindVillagePT::
	setmetatile 2, 1, 428, 1
	setmetatile 3, 1, 429, 1
	return

EventScript_TV_HighwindVillageTW::
	setmetatile 2, 1, 476, 1
	setmetatile 3, 1, 477, 1
	return

EventScript_TV_HighwindVillageCS::
	setmetatile 2, 1, 460, 1
	setmetatile 3, 1, 461, 1
	return

EventScript_TV_HighwindVillageDP::
	setmetatile 2, 1, 444, 1
	setmetatile 3, 1, 445, 1
	return

EventScript_TV_NorthstarCityTN::
	setmetatile 3, 1, 408, 1
	setmetatile 4, 1, 409, 1
	return

EventScript_TV_NorthstarCityPT::
	setmetatile 3, 1, 424, 1
	setmetatile 4, 1, 425, 1
	return

EventScript_TV_NorthstarCityTW::
	setmetatile 3, 1, 472, 1
	setmetatile 4, 1, 473, 1
	return

EventScript_TV_NorthstarCityCS::
	setmetatile 3, 1, 456, 1
	setmetatile 4, 1, 457, 1
	return

EventScript_TV_NorthstarCityDP::
	setmetatile 3, 1, 440, 1
	setmetatile 4, 1, 441, 1
	return

EventScript_TV_PinleafTownTN::
	setmetatile 4, 1, 412, 1
	setmetatile 5, 1, 413, 1
	return

EventScript_TV_PinleafTownPT::
	setmetatile 4, 1, 428, 1
	setmetatile 5, 1, 429, 1
	return

EventScript_TV_PinleafTownTW::
	setmetatile 4, 1, 476, 1
	setmetatile 5, 1, 477, 1
	return

EventScript_TV_PinleafTownCS::
	setmetatile 4, 1, 460, 1
	setmetatile 5, 1, 461, 1
	return

EventScript_TV_PinleafTownDP::
	setmetatile 4, 1, 444, 1
	setmetatile 5, 1, 445, 1
	return
