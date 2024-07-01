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
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_TenNewsEp4
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_TenNewsEp3
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, EventScript_TV_TenNewsEp2
	goto EventScript_TV_TenNewsEp1
	end

EventScript_TV_TryPokeTalk::
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_PokeTalkEp4
	goto_if_set FLAG_BADGE02_GET, EventScript_TV_PokeTalkEp3
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_PokeTalkEp2
	goto EventScript_TV_PokeTalkEp1
	end

EventScript_TV_TryTrainerWatch::
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_PokeTalkEp3
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_PokeTalkEp2
	goto EventScript_TV_TrainerWatchEp1
	end

EventScript_TV_TryCliffShow::
	@goto_if_set FLAG_BADGE03_GET, EventScript_TV_CliffShowEp3
	@goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_CliffShowEp2
	@goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, EventScript_TV_CliffShowEp1
	@goto EventScript_TV_CliffShowEp1
	end

EventScript_TV_TryDrowzeePodcast::
	goto_if_set FLAG_BADGE03_GET, EventScript_TV_DrowzeePodcastEp3
	goto_if_set FLAG_TAMAROK_TUNNELS_SUBO, EventScript_TV_DrowzeePodcastEp2
	goto_if_set FLAG_HIDE_ABANDONED_MUSEUM_SUBO, EventScript_TV_DrowzeePodcastEp1
	goto EventScript_TV_DrowzeePodcastEp1
	end

EventScript_TV_TenNewsEp1::
	call EventScript_TV_TenNewsSetScreen
	special DrawWholeMapView
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

EventScript_TV_PokeTalkEp1::
	call EventScript_TV_PokeTalkSetScreen
	special DrawWholeMapView
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

EventScript_TV_TrainerWatchEp1::
	call EventScript_TV_TrainerWatchSetScreen
	special DrawWholeMapView
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
	msgbox AlthoughThereAreFewGenerationalPhenomenons, MSGBOX_AUTOCLOSE
	goto TV_SelectAChannelExpanded
	end

EventScript_TV_CliffShowEp1::
	call EventScript_TV_CliffShowSetScreen
	special DrawWholeMapView
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

EventScript_TV_DrowzeePodcastEp1::
	call EventScript_TV_DrowzeePodcastSetScreen
	special DrawWholeMapView
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
	@call_if_eq VAR_TEMP_B, 1, EventScript_TV_SunriseTownTW
	@call_if_eq VAR_TEMP_B, 2, EventScript_TV_UnionCityTW
	@call_if_eq VAR_TEMP_B, 3, EventScript_TV_AnheimTownTW
	@call_if_eq VAR_TEMP_B, 4, EventScript_TV_LaveriaCityTW
	@call_if_eq VAR_TEMP_B, 5, EventScript_TV_HighwindVillageTW
	@call_if_eq VAR_TEMP_B, 6, EventScript_TV_NorthstarCityTW
	@call_if_eq VAR_TEMP_B, 7, EventScript_TV_PinleafTownTW
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

EventScript_TV_PinleafTownCS::
	setmetatile 4, 1, 460, 1
	setmetatile 5, 1, 461, 1
	return

EventScript_TV_PinleafTownDP::
	setmetatile 4, 1, 444, 1
	setmetatile 5, 1, 445, 1
	return
