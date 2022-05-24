LaveriaCity_Mart_MapScripts::
	.byte 0

LaveriaCity_Mart_Aroma_Lady::
	msgbox LaveriaCity_Mart_Text_Aroma_Lady, MSGBOX_NPC
	end

LaveriaCity_Mart_Guitarist::
	msgbox LaveriaCity_Mart_Text_Guitarlist, MSGBOX_NPC
	end

LaveriaCity_Mart_Boy::
	msgbox LaveriaCity_Mart_Text_Boy, MSGBOX_NPC
	end

LaveriaCity_Mart_Text_Aroma_Lady:
	.string "{COLOR}{RED}Even if a Pokémon is weak now,\n"
	.string "it will grow stronger.\p"
	.string "The most important thing is love for\n"
	.string "your Pokémon!$"

LaveriaCity_Mart_Text_Guitarlist:
	.string "{COLOR}{BLUE}I'm gonna stock up on Poké Balls.\p"
	.string "Some dude told me there are some rare\n"
	.string "Pokémon to find in Route 7.$"

LaveriaCity_Mart_Text_Boy:
	.string "{COLOR}{BLUE}Do you use Repels?\p"
	.string "It keeps wild Pokémon away when you're\n"
	.string "in a hurry.$"
