PalaceOfIce_Entrance_MapScripts::
	.byte 0

PalaceOfIce_Entrance_EntranceLeftSide::
	lockall
	braillemessage PalaceOfIce_Entrance_Braille_HereLiesThe
	waitbuttonpress
	closebraillemessage
	releaseall
	end

PalaceOfIce_Entrance_EntranceMiddle::
	lockall
	braillemessage PalaceOfIce_Entrance_Braille_IcyHeartOf
	waitbuttonpress
	closebraillemessage
	releaseall
	end

PalaceOfIce_Entrance_EntranceRightSide::
	lockall
	braillemessage PalaceOfIce_Entrance_Braille_TheMountain
	waitbuttonpress
	closebraillemessage
	releaseall
	end

PalaceOfIce_Entrance_RegigigasStone::
	msgbox PalaceOfIce_Entrance_Text_RegigigasStone, MSGBOX_SIGN
	end

PalaceOfIce_Entrance_Text_RegigigasStone:
	.string "A mysterious statue blocks the way…$"
