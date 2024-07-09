Route11_House1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route11_House1_OnFrame
	.byte 0

Route11_House1_OnFrame:
	map_script_2 VAR_ERNIE_STATE, 1, Route11_House1_ErnieEvent
	.2byte 0

Route11_House1_ErnieEvent::
	end
