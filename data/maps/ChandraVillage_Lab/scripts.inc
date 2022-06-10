ChandraVillage_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChandraVillage_Lab_OnFrame
	.byte 0

ChandraVillage_Lab_OnFrame::
	map_script_2 VAR_STORYLINE_STATE, 5, ChandraVillage_Lab_PickPokemon
	.2byte 0

ChandraVillage_Lab_PickPokemon::
	lock
	removeobject 3
	removeobject 4
	removeobject 5
	setflag FLAG_HIDE_CHANDRA_VILLAGE_LAB_PROF
	setflag FLAG_HIDE_CHANDRA_VILLAGE_POKE_BALL_1
	setflag FLAG_HIDE_CHANDRA_VILLAGE_POKE_BALL_2
	goto_if_set FLAG_SYS_POKEMON_GET, ChandraVillage_Lab_TryAgain
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox ChandraVillage_Lab_Text_ListenUp, MSGBOX_AUTOCLOSE
	applymovement 1, WU6
	applymovement OBJ_EVENT_ID_PLAYER, WU6
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowUp
	waitmovement 0
	msgbox ChandraVillage_Lab_Text_Hmm, MSGBOX_AUTOCLOSE
	applymovement 1, WL2
	waitmovement 0
	delay 30
	applymovement 1, WR4
	waitmovement 0
	delay 30
	applymovement 1, WL2
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox ChandraVillage_Lab_Text_DoYouThink, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 0
	msgbox ChandraVillage_Lab_Text_DontHoldInHand, MSGBOX_DEFAULT
	setvar VAR_STORYLINE_STATE, 6
	release
	end

ChandraVillage_Lab_TryAgain::
	lock
	msgbox ChandraVillage_Lab_Text_TryAgain, MSGBOX_AUTOCLOSE
	applymovement 1, WU6
	applymovement OBJ_EVENT_ID_PLAYER, WU6
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceSlowDown
	waitmovement 0
	msgbox ChandraVillage_Lab_Text_BattleThePokemon, MSGBOX_DEFAULT
	setvar VAR_STORYLINE_STATE, 6
	release
	end

ChandraVillage_Lab_Aide::
	goto_if_set FLAG_SYS_POKEDEX_GET, ChandraVillage_Lab_Aide_Dex
	msgbox ChandraVillage_Lab_Text_Aide, MSGBOX_NPC
	end

ChandraVillage_Lab_Aide_Dex::
	msgbox ChandraVillage_Lab_Text_Aide_Dex, MSGBOX_NPC
	end

WU6:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WL2:
	walk_left
	walk_left
	step_end

WR4:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ChandraVillage_Lab_Text_ListenUp:
	.string "{COLOR}{BLUE}Okay, {PLAYER}, listen up!\p"
	.string "Professor Hawthorne left a couple of\n"
	.string "Pokémon at the back of the Lab.\p"
	.string "They look pretty tame to me.\n"
	.string "Let's go check them out!$"

ChandraVillage_Lab_Text_Hmm:
	.string "{COLOR}{BLUE}Hmm…$"

ChandraVillage_Lab_Text_DoYouThink:
	.string "{COLOR}{BLUE}Do you think these Pokémon want to sit\n"
	.string "around an old man all day, watching\l"
	.string "him while he writes boring lab-notes?\p"
	.string "Tch… Mom once made me spend time\n"
	.string "with Professor Hawthorne.\l"
	.string "I'd rather watch paint dry!\p"
	.string "The old man does nothing all day\n"
	.string "except fiddle with his Pokédex.\p"
	.string "A Pokédex won't save you from Rattata,\n"
	.string "{PLAYER}, a Pokemon will!\p"
	.string "Here, take one of these Poké Balls…$"

ChandraVillage_Lab_Text_DontHoldInHand:
	.string "{COLOR}{BLUE}No! Don't put it in your bag!\n"
	.string "Take it out and hold it in your hand.\p"
	.string "We're going to catch these Pokémon\n"
	.string "and help get rid of this infestation!\p"
	.string "Be careful, though, {PLAYER}…\n"
	.string "I only have two Poké Balls left…\l"
	.string "We can't be careless with this.\p"
	.string "What's more is this is the only\n"
	.string "chance the Professor will give us to\l"
	.string "prove we can be Pokémon Trainers!\p"
	.string "My advice is to creep up slowly and\n"
	.string "not spook them.\p"
	.string "Pick a Pokémon, {PLAYER}!$"

ChandraVillage_Lab_Text_TryAgain:
	.string "{COLOR}{BLUE}It's okay, {PLAYER}…\n"
	.string "Let's try this again!$"

ChandraVillage_Lab_Text_BattleThePokemon:
	.string "{COLOR}{BLUE}Battle the Pokémon and show me what\n"
	.string "you're made of!$"

ChandraVillage_Lab_Text_Aide:
	.string "Pfft… The Professor is such a wimp.\n"
	.string "These Rattata won't distract me!$"

ChandraVillage_Lab_Text_Aide_Dex:
	.string "You saved the Professor from Rattata?\n"
	.string "You want a medal? He's a wimp.$"
