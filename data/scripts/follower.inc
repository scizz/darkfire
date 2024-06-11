gText_FollowerLovesYou::
  .string "{STR_VAR_1} is regarding you with\nadoration!$"

gText_FollowerLostInThought::
	.string "{STR_VAR_1} seems lost in thought.$"

gText_FollowerDefault::
	.string "ERROR 404: Script not found.$"

gText_WantsToFly::
	.string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"

.macro playfirstmoncry
callfunc ScrFunc_playfirstmoncry
.endm

.macro bufferlivemonnickname out:req
callfunc ScrFunc_bufferlivemonnickname
.byte \out
.endm

.macro emote obj:req id:req
callfunc ScrFunc_emote
.byte \obj
.byte \id
.endm

EventScript_Follower::
	lockall
	@compare VAR_FACING, DIR_NORTH
	call FollowerFaceSouth @_if_eq FollowerFaceSouth
	delay 60
	@compare VAR_FACING, DIR_SOUTH
	call FollowerFaceNorth @_if_eq FollowerFaceNorth
	delay 60
	@compare VAR_FACING, DIR_WEST
	call FollowerFaceEast @_if_eq FollowerFaceEast
	delay 60
	@compare VAR_FACING, DIR_EAST
	call FollowerFaceWest @_if_eq FollowerFaceWest
	@applymovement OBJ_EVENT_ID_FOLLOWER, FollowerDance
	@waitmovement 0
	@bufferlivemonnickname 0
	@playfirstmoncry
	@callfunc ScrFunc_getfolloweraction
	releaseall @remove after test
	end @remove after test
EventScript_FollowerEnd::
	@waitfieldeffect FLDEFF_EMOTE
	releaseall
	end

FollowerFaceNorth::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceUp
	waitmovement 0
	return

FollowerFaceSouth::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceDown
	waitmovement 0
	return

FollowerFaceEast::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceRight
	waitmovement 0
	return

FollowerFaceWest::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement 0
	return

EventScript_FollowerLovesYou::
	applymovement OBJ_EVENT_ID_FOLLOWER, ContestHall_Movement_Heart
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmoncry
	showborderlesspic 20, 8
	msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
	hidemonpic
	return

@ Message address must be loaded into bank 0
EventScript_FollowerGeneric:: @ similar to Std_MsgboxDefault
	pokemonfaceplayer
	releaseall
EventScript_FollowerGenericSkipFace:
	waitfieldeffect FLDEFF_EMOTE
	showborderlesspic 20, 8
	message 0x0
	waitmessage
	waitbuttonpress
	hidemonpic
	pokemonfaceplayer
	releaseall
	return

EventScript_FollowerJump::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSplashMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitfieldeffect FLDEFF_EMOTE
	showborderlesspic 20, 8
	message 0x0
	waitmessage
	waitbuttonpress
	hidemonpic
	pokemonfaceplayer
	releaseall
	return

EnterPokeballMovement:
	follower_shrink
	step_end

@ Movement scripts below, movements are defined in movement.inc

FollowerSplashMovement:
	follower_face_down
	jump_in_place_down
	delay_4
	jump_in_place_down
	step_end

FollowerShiverVerticalMovement:
	lock_facing_direction
	follower_face_down
	jump_in_place_down
	unlock_facing_direction
	step_end

FollowerShiverHorizontalMovement:
	lock_facing_direction
	follower_face_down
	jump_in_place_down
	unlock_facing_direction
	step_end

FollowerNostalgiaMovement:
	follower_face_right
	lock_facing_direction
	follower_face_down
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	unlock_facing_direction
	pokemonfaceplayer
	follower_face_down
	lock_facing_direction
	jump_in_place_down
	unlock_facing_direction
	step_end

FollowerSkippingMovement:
	follower_face_down
	lock_facing_direction
	jump_in_place_down
	delay_4
	jump_in_place_down
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerNorth:
	follower_face_up
	jump_up
	delay_4
	follower_face_down
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerSouth:
	follower_face_down
	jump_down
	delay_4
	follower_face_up
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerEast:
	follower_face_right
	jump_right
	delay_4
	follower_face_left
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	step_end

FollowerJumpOnPlayerWest:
	follower_face_left
	jump_left
	delay_4
	follower_face_right
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

FollowerCuddlingNorth:
	follower_face_left
	follower_face_up
	lock_facing_direction
	walk_up
	follower_face_left
	walk_in_place_left
	walk_in_place_left
	unlock_facing_direction
	follower_face_down
	walk_down
	step_end

FollowerCuddlingSouth:
	follower_face_right
	follower_face_down
	lock_facing_direction
	walk_down
	follower_face_right
	walk_in_place_right
	walk_in_place_right
	unlock_facing_direction
	follower_face_up
	walk_up
	step_end

FollowerCuddlingEast:
	follower_face_down
	follower_face_right
	lock_facing_direction
	walk_right
	follower_face_down
	walk_in_place_down
	walk_in_place_down
	unlock_facing_direction
	follower_face_left
	walk_left
	step_end

FollowerCuddlingWest:
	follower_face_down
	follower_face_left
	lock_facing_direction
	walk_left
	follower_face_down
	walk_in_place_down
	walk_in_place_down
	unlock_facing_direction
	follower_face_right
	walk_right
	step_end

FollowerGetCloserNorth:
	follower_face_up
	walk_up
	delay_16
	follower_face_down
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

FollowerGetCloserSouth:
	follower_face_down
	walk_down
	delay_16
	follower_face_up
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

FollowerGetCloserEast:
	follower_face_right
	walk_right
	delay_16
	follower_face_left
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

FollowerGetCloserWest:
	follower_face_left
	walk_left
	delay_16
	follower_face_right
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

FollowerPokeNorth:
	follower_face_up
	walk_faster_up
	delay_8
	follower_face_down
	walk_faster_down
	delay_4
	follower_face_up
	walk_faster_up
	delay_4
	follower_face_down
	walk_faster_down
	step_end

FollowerPokeSouth:
	walk_faster_down
	delay_8
	follower_face_up
	walk_faster_up
	delay_4
	follower_face_down
	walk_faster_down
	delay_4
	follower_face_up
	walk_faster_up
	step_end

FollowerPokeEast:
	follower_face_right
	walk_faster_right
	delay_8
	follower_face_left
	walk_faster_left
	delay_4
	follower_face_right
	walk_faster_right
	delay_4
	follower_face_left
	walk_faster_left
	step_end

FollowerPokeWest:
	follower_face_left
	walk_faster_left
	delay_8
	follower_face_right
	walk_faster_right
	delay_4
	follower_face_left
	walk_faster_left
	delay_4
	follower_face_right
	walk_faster_right
	step_end

FollowerLookAround:
	follower_face_up
	delay_16
	delay_16
	follower_face_left
	delay_16
	delay_16
	follower_face_up
	delay_16
	delay_16
	follower_face_down
	delay_16
	delay_16
	step_end

FollowerLookAway:
	follower_face_up
	delay_16
	delay_16
	step_end

FollowerLookAwayBark:
	follower_face_up
	follower_face_down
	jump_in_place_down
	jump_in_place_down
	step_end

FollowerLookAwayPokeG:
	follower_face_up
	follower_face_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

FollowerPokeGround:
	follower_face_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

FollowerStartled:
	follower_face_up
	follower_face_down
	jump_in_place_down
	step_end

FollowerHopFast:
	follower_face_up
	jump_in_place_up
	follower_face_down
	jump_in_place_down
	follower_face_left
	jump_in_place_left
	follower_face_right
	jump_in_place_right
	step_end

FollowerDizzy:
	follower_face_left
	walk_in_place_left
	follower_face_right
	walk_in_place_fast_right
	follower_face_up
	walk_in_place_slow_up
	follower_face_down
	walk_in_place_fast_down
	delay_4
	follower_face_up
	step_end

FollowerLookAroundScared:
	follower_face_up
	delay_16
	follower_face_down
	delay_16
	follower_face_left
	delay_16
	follower_face_right
	delay_16
	follower_face_up
	delay_16
	follower_face_down
	delay_16
	follower_face_left
	delay_16
	follower_face_right
	delay_16
	step_end

FollowerDance:
	follower_face_up
	jump_in_place_up
	follower_face_up
	follower_face_left
	follower_face_down
	follower_face_right
	follower_face_up
	follower_face_left
	follower_face_down
	follower_face_right
	follower_face_up
	jump_in_place_up
	follower_face_down
	jump_in_place_down
	follower_face_up
	jump_in_place_up
	step_end

@ Movement scripts

EventScript_FollowerIsShivering::
	compare VAR_FACING, DIR_NORTH
	call_if_eq ShiverVertical
	compare VAR_FACING, DIR_SOUTH
	call_if_eq ShiverVertical
	compare VAR_FACING, DIR_WEST
	call_if_eq ShiverHorizontal
	compare VAR_FACING, DIR_EAST
	call_if_eq ShiverHorizontal
	goto EventScript_FollowerGeneric

ShiverVertical:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverVerticalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShiverHorizontal:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverHorizontalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerNostalgia::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerNostalgiaMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerHopping::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSkippingMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

JumpOnN:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

JumpOnS:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

JumpOnE:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

JumpOnW:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerJumpOnPlayer::
	compare VAR_FACING, DIR_NORTH
	call_if_eq JumpOnS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq JumpOnN
	compare VAR_FACING, DIR_WEST
	call_if_eq JumpOnE
	compare VAR_FACING, DIR_EAST
	call_if_eq JumpOnW
	goto EventScript_FollowerGeneric

CuddleN:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CuddleS:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CuddleE:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CuddleW:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerCuddling:: @ similar to Std_MsgboxDefault
	compare VAR_FACING, DIR_NORTH
	call_if_eq CuddleS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CuddleN
	compare VAR_FACING, DIR_WEST
	call_if_eq CuddleE
	compare VAR_FACING, DIR_EAST
	call_if_eq CuddleW
	goto EventScript_FollowerGeneric

ShCuddleN:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverVerticalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShCuddleS:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverVerticalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShCuddleE:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverHorizontalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShCuddleW:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverHorizontalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerShiverCuddling::
	compare VAR_FACING, DIR_NORTH
	call_if_eq ShCuddleS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq ShCuddleN
	compare VAR_FACING, DIR_WEST
	call_if_eq ShCuddleE
	compare VAR_FACING, DIR_EAST
	call_if_eq ShCuddleW
	goto EventScript_FollowerGeneric

CreepCloserN:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CreepCloserS:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CreepCloserE:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CreepCloserW:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerGetCloser::
	compare VAR_FACING, DIR_NORTH
	call_if_eq CreepCloserS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq CreepCloserN
	compare VAR_FACING, DIR_WEST
	call_if_eq CreepCloserE
	compare VAR_FACING, DIR_EAST
	call_if_eq CreepCloserW
	goto EventScript_FollowerGeneric

PokePlayerN:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

PokePlayerS:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

PokePlayerE:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

PokePlayerW:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerGetCloserWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerPokingPlayer::
	compare VAR_FACING, DIR_NORTH
	call_if_eq PokePlayerS
	compare VAR_FACING, DIR_SOUTH
	call_if_eq PokePlayerN
	compare VAR_FACING, DIR_WEST
	call_if_eq PokePlayerE
	compare VAR_FACING, DIR_EAST
	call_if_eq PokePlayerW
	goto EventScript_FollowerGeneric

EventScript_FollowerLookAround::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerLookAround
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerLookAway::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAwayBark::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerLookAwayBark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAwayPoke::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerLookAwayPokeG
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerPokeGround::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerPokeGround
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerStartled::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerStartled
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFastHopping::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerHopFast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerDizzy::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerDizzy
	waitmovement 0
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAroundScared::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerLookAroundScared
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerDance::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerDance
	waitmovement 0
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceUp::
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceResult:: @ Face towards direction in VAR_RESULT
	switch VAR_RESULT
	case DIR_SOUTH, EventScript_FollowerFaceDown
	case DIR_NORTH, EventScript_FollowerFaceUp
	case DIR_WEST, EventScript_FollowerFaceLeft
	case DIR_EAST, EventScript_FollowerFaceRight
	goto EventScript_FollowerGeneric

EventScript_FollowerFaceDown:
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceDown
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceLeft:
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceRight:
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_FollowerFaceRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace
