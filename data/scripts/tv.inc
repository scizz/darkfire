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

TV_SelectAChannel::
	message PleaseSelectAChannel
	waitmessage
	multichoice 0, 0, MULTI_TV_SELECT_CHANNEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_TryTenNews
	case 1, EventScript_TV_TryPokeTalk
	case 2, EventScript_TV_TryCliffShow
	case 3, EventScript_TV_TryDrowzeePodcast
	msgbox PlayerPutDownTheTvRemote, MSGBOX_AUTOCLOSE
	end

EventScript_TV_TryTenNews::
	@goto_if_set FLAG_BADGE03_GET, EventScript_TV_TenNewsEp3
	@goto_if_set FLAG_BADGE02_GET, EventScript_TV_TenNewsEp2
	goto_if_set FLAG_BADGE01_GET, EventScript_TV_TenNewsEp1
	goto EventScript_TV_TenNewsEp1
	end

EventScript_TV_TryPokeTalk::
	@goto_if_set FLAG_BADGE03_GET, EventScript_TV_PokeTalkEp3
	@goto_if_set FLAG_BADGE02_GET, EventScript_TV_PokeTalkEp2
	goto_if_set FLAG_BADGE01_GET, EventScript_TV_PokeTalkEp1
	goto EventScript_TV_PokeTalkEp1
	end

EventScript_TV_TryCliffShow::
	@goto_if_set FLAG_BADGE03_GET, EventScript_TV_CliffShowEp3
	@goto_if_set FLAG_BADGE02_GET, EventScript_TV_CliffShowEp2
	goto_if_set FLAG_BADGE01_GET, EventScript_TV_CliffShowEp1
	goto EventScript_TV_CliffShowEp1
	end

EventScript_TV_TryDrowzeePodcast::
	@goto_if_set FLAG_BADGE03_GET, EventScript_TV_DrowzeePodcastEp3
	@goto_if_set FLAG_BADGE02_GET, EventScript_TV_DrowzeePodcastEp2
	goto_if_set FLAG_BADGE01_GET, EventScript_TV_DrowzeePodcastEp1
	goto EventScript_TV_DrowzeePodcastEp1
	end

EventScript_TV_TenNewsEp1::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownTN
	special DrawWholeMapView
	msgbox TodayOnTenNewsShouldChildren, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_PokeTalkEp1::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownPT
	special DrawWholeMapView
	msgbox ThanksForTuningInToPokeTalk1, MSGBOX_AUTOCLOSE
	msgbox LetsDiveRightInLydia, MSGBOX_AUTOCLOSE
	msgbox HelloPokeTalkLydia, MSGBOX_AUTOCLOSE
	message ThankYouLydia
	waitmessage
	multichoice 0, 0, MULTI_TV_GUIDE, FALSE
	switch VAR_RESULT
	case 0, EventScript_TV_PokeTalkEp1Pt2
	case 1, TV_SelectAChannel
	case 2, PlayerPutDownTheTvRemote
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

EventScript_TV_CliffShowEp1::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownCS
	special DrawWholeMapView
	msgbox TodayOnTenNewsShouldChildren, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannel
	end

EventScript_TV_DrowzeePodcastEp1::
	call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownDP
	special DrawWholeMapView
	msgbox YoureListeningToTheDrowzeePodcast1, MSGBOX_AUTOCLOSE
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
	case 2, PlayerPutDownTheTvRemote
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

EventScript_TV_SunriseTownTN::
	setmetatile 4, 1, 406, 0
	setmetatile 5, 1, 407, 0
	return

EventScript_TV_SunriseTownPT::
	setmetatile 4, 1, 422, 0
	setmetatile 5, 1, 423, 0
	return

EventScript_TV_SunriseTownCS::
	setmetatile 4, 1, 454, 0
	setmetatile 5, 1, 455, 0
	return

EventScript_TV_SunriseTownDP::
	setmetatile 4, 1, 438, 0
	setmetatile 5, 1, 439, 0
	return
