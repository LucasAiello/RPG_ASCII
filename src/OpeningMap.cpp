#include "OpeningMap.hpp"

void OpeningMap::init()
{
	// First Layer -----------------------------------------------------------------------------------

    wall_trees[0] = new ObjetoDeJogo("Wall1", Sprite("../rsc/Sprites/sprite_horizontal_wall_tree.spr"), 0, 0);
    objs.push_back(wall_trees[0]);
    colisons.push_back(wall_trees[0]);

    wall_trees[1] = new ObjetoDeJogo("Wall2", Sprite("../rsc/Sprites/sprite_vertical_wall_tree.spr"), 5, 0);
	objs.push_back(wall_trees[1]);
    colisons.push_back(wall_trees[1]);

	wall_trees[2] = new ObjetoDeJogo("Wall3", Sprite("../rsc/Sprites/sprite_vertical_wall_tree.spr"), 5, 184);
	objs.push_back(wall_trees[2]);
    colisons.push_back(wall_trees[2]);

	wall_trees[3] = new ObjetoDeJogo("Wall4", Sprite("../rsc/Sprites/sprite_horizontal_wall_tree2.spr"), 47, 0);
	objs.push_back(wall_trees[3]);
    colisons.push_back(wall_trees[3]);

    house = new ObjetoDeJogo("House", Sprite("../rsc/Sprites/sprite_house.spr"), 7, 20);
    objs.push_back(house);
    colisons.push_back(house);
	
	fence = new ObjetoDeJogo("Fence", SpriteAnimado("../rsc/Sprites/sprite_fence.anm", 3), 7, 74);
	objs.push_back(fence);
    colisons.push_back(fence);
	
	sign = new ObjetoDeJogo("Sign", Sprite("../rsc/Sprites/sprite_sign.spr"), 18, 170);
	objs.push_back(sign);
    colisons.push_back(sign);

	sign_text = new Texts(ObjetoDeJogo("Sign Text", Sprite("../rsc/Sprites/sprite_action.spr"), 23, 172));
	sign_text->readfile("../rsc/Texts/OP_M_Sign.txt");
	objs.push_back(sign_text);
	texts.push_back(sign_text);

	house_text = new Texts(ObjetoDeJogo("House Text", Sprite("../rsc/Sprites/sprite_action.spr"), 20, 43));
	house_text->readfile("../rsc/Texts/OP_M_Door.txt");
	objs.push_back(house_text);
	texts.push_back(house_text);
    
    objs.push_back(player);
	
	// Second Layer -----------------------------------------------------------------------------------

	wall_trees[4] = new ObjetoDeJogo("Wall4 Top", Sprite("../rsc/Sprites/sprite_horizontal_wall_tree2_top.spr"), 42, 0);
	objs.push_back(wall_trees[4]);

	east_entrance = new ObjetoDeJogo("East Entrance", Sprite("../rsc/Sprites/sprite_vertical_entrance.spr"), 24, 184);
	objs.push_back(east_entrance);
    colisons.push_back(east_entrance);

	west_entrance = new Texts(ObjetoDeJogo("West Entrance", Sprite("../rsc/Sprites/sprite_vertical_entrance.spr"), 24, 0), {"PRECISO CURAR A VILA ANTES DE IR EMBORA..."});
	objs.push_back(west_entrance);
    colisons.push_back(west_entrance);
	texts.push_back(west_entrance);

	// Third Layer (HUD) -----------------------------------------------------------------------------------

	dialogue_box = new ObjetoDeJogo("Dialogue Box", Sprite("../rsc/Sprites/sprite_dialogue_box.spr"), 41, 20);
	objs.push_back(dialogue_box);
	dialogue_box->desativarObj();

	text = new ObjetoDeJogo("Text", TextSprite(""), 45, 92);
	objs.push_back(text);
	text->desativarObj();
	
}

unsigned OpeningMap::run()
{	
	int posL = player->getPosL(), posC = player->getPosC();
	player->moveTo(posL,posC);
    std::string ent;
	int key = 0;
	PlaySound(TEXT("../rsc/Sounds/bg_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
		
		if (key == KEY_UP)
			player->moveUp(VEL_Y);
		else if (key == KEY_DOWN)
			player->moveDown(VEL_Y);
		else if (key == KEY_LEFT)
			player->moveLeft(VEL_X);
		else if (key == KEY_RIGHT)
			player->moveRight(VEL_X);
		else if (key == KEY_Q) 
			exit(0);
		else if (key == KEY_X)
		{
			if (player->colideCom(*house_text)){
				PlaySound(TEXT("../rsc/Sounds/knock.wav"), NULL, SND_FILENAME | SND_SYNC);
				PlaySound(TEXT("../rsc/Sounds/bg_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			}
			showText(posL, posC);
		}

		if (player->colideCom(*east_entrance))
		{
			player->moveTo(24,20);
			return VILLAGE_D;
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