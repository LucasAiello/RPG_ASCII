#include "GravediggerMap.hpp"

void GravediggerHouse::init()
{
	// First Layer -----------------------------------------------------------------------------------
    table = new ObjetoDeJogo("Table", Sprite("../rsc/Sprites/sprite_table.spr"), 7, 20);
    objs.push_back(table);
    colisons.push_back(table);
    objs.push_back(player);
	
	// Second Layer -----------------------------------------------------------------------------------

    south_entrance = new ObjetoDeJogo("South Entrance", Sprite("../rsc/Sprites/sprite_house_entrance.spr"), 35, 55);
	objs.push_back(south_entrance);
    colisons.push_back(south_entrance);

	// Third Layer (HUD) -----------------------------------------------------------------------------------

	npc = new ObjetoDeJogo("Npc", SpriteAnimado("../rsc/Sprites/sprite_npc.anm", 2), 5, 90);
    objs.push_back(npc);
    colisons.push_back(npc);

	npc_texts = new Texts(ObjetoDeJogo("Npc1 Text", Sprite("../rsc/Sprites/sprite_action.spr"), 14, 91));
	objs.push_back(npc_texts);
	texts.push_back(npc_texts);
	npc_texts->readfile("../rsc/Texts/GDH_M_Graverdigger.txt");

	text_battle = new Texts(ObjetoDeJogo("Text Battle", Sprite("../rsc/Sprites/sprite_action.spr"), 14, 91));
	objs.push_back(text_battle);
	texts.push_back(text_battle);
	text_battle->readfile("../rsc/Texts/GDH_M_Battle.txt");
	text_battle->desativarObj();

	dialogue_box = new ObjetoDeJogo("Dialogue Box", Sprite("../rsc/Sprites/sprite_dialogue_box.spr"), 41, 20);
	objs.push_back(dialogue_box);
	dialogue_box->desativarObj();

	text = new ObjetoDeJogo("Text", TextSprite(""), 45, 92);
	objs.push_back(text);
	text->desativarObj();

	enemies.push_back(Character(ObjetoDeJogo("COVEIRO", SpriteAnimado("../rsc/Sprites/sprite_gravedigger.anm", 2), 20, 45), 200, 65, 65, 60, 20));
	
}

unsigned GravediggerHouse::run()
{
	int key = 0;
	int posL = player->getPosL(), posC = player->getPosC();
	player->moveTo(posL,posC);

    std::string ent;
	
	//padrão
	draw(screen);
	system("cls");
	show(screen);

    while (true)
	{
		//lendo entrada
		key = getch();
		//processando entradas
		int posL = player->getPosL(), posC = player->getPosC();
		
		if (key == KEY_UP && posL >= 8)
			player->moveUp(VEL_Y);
		else if (key == KEY_DOWN && posL < 28)
			player->moveDown(VEL_Y);
		else if (key == KEY_LEFT && posC > 20)
			player->moveLeft(VEL_X);
		else if (key == KEY_RIGHT && posC < 94)
			player->moveRight(VEL_X);
		else if (key == KEY_Q) 
			exit(0);
		else if (key == KEY_X) 
		{
			if(player->colideCom(*npc_texts))
			{
				showText(posL, posC);
				PlaySound(TEXT("../rsc/Sounds/sound_gravedigger.wav"), NULL, SND_SYNC);
				battle->setEnemy(getEnemy(0), getEnemy(0));
				//PlaySound(TEXT("../rsc/bg_sound.wav"), NULL, SND_LOOP | SND_ASYNC);
				if(battle->run() == 1){
					npc->desativarObj();
					npc_texts->desativarObj();
					text_battle->ativarObj();
					showText(posL, posC);
					text_battle->desativarObj();
					player->setBigKey();
				}
			}
			
		}

		if(player->colideCom(*south_entrance))
		{
			player->moveTo(27, 43);
			return VILLAGE_G;
		}

        if (colideComBloco()) 
			player->moveTo(posL,posC);

        //padrão
		update();
		draw(screen);
		system("cls");
		show(screen);
	}

    return 1;
}