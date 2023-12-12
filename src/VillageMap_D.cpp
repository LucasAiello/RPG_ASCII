#include "VillageMap_D.hpp"
#include <random>
#include <chrono>
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_int_distribution<int> var(0,100);
std::uniform_int_distribution<int> random_enemy(0,3);

void VillageMap_D::init()
{
	// First Layer -----------------------------------------------------------------------------------

    wall_trees[0] = new ObjetoDeJogo("Wall1", Sprite("../rsc/sprite_horizontal_wall_tree.spr"), 0, 0);
    objs.push_back(wall_trees[0]);
    colisons.push_back(wall_trees[0]);

    wall_trees[1] = new ObjetoDeJogo("Wall2", Sprite("../rsc/sprite_vertical_wall_tree.spr"), 5, 0);
	objs.push_back(wall_trees[1]);
    colisons.push_back(wall_trees[1]);

	wall_trees[2] = new ObjetoDeJogo("Wall3", Sprite("../rsc/sprite_vertical_wall_tree.spr"), 5, 184);
	objs.push_back(wall_trees[2]);
    colisons.push_back(wall_trees[2]);

	wall_trees[3] = new ObjetoDeJogo("Wall4", Sprite("../rsc/sprite_horizontal_wall_tree2.spr"), 47, 0);
	objs.push_back(wall_trees[3]);
    colisons.push_back(wall_trees[3]);

    houses[0] = new ObjetoDeJogo("House", Sprite("../rsc/sprite_big_house.spr"), 1, 137);
    objs.push_back(houses[0]);
    colisons.push_back(houses[0]);

	houses[1] = new ObjetoDeJogo("House", Sprite("../rsc/sprite_big_house.spr"), 1, 20);
    objs.push_back(houses[1]);
    colisons.push_back(houses[1]);
	
	sign = new ObjetoDeJogo("Sign", Sprite("../rsc/sprite_sign.spr"), 15, 110);
	objs.push_back(sign);
    colisons.push_back(sign);
    
    objs.push_back(player);
	
	// Second Layer -----------------------------------------------------------------------------------

	wall_trees[4] = new ObjetoDeJogo("Wall4 Top", Sprite("../rsc/sprite_horizontal_wall_tree2_top.spr"), 42, 0);
	objs.push_back(wall_trees[4]);

	west_entrance = new ObjetoDeJogo("West Entrance", Sprite("../rsc/sprite_vertical_entrance.spr"), 24, 0);
	objs.push_back(west_entrance);
    colisons.push_back(west_entrance);

    south_entrance = new ObjetoDeJogo("South Entrance", Sprite("../rsc/sprite_horizontal_entrance.spr"), 42, 93);
	objs.push_back(south_entrance);
    colisons.push_back(south_entrance);

	// Third Layer (HUD) -----------------------------------------------------------------------------------

	dialogue_box = new ObjetoDeJogo("Dialogue Box", Sprite("../rsc/sprite_dialogue_box.spr"), 41, 20);
	objs.push_back(dialogue_box);
	dialogue_box->desativarObj();

	text = new ObjetoDeJogo("Text", TextSprite(""), 45, 92);
	objs.push_back(text);
	text->desativarObj();

	// Init enemies

	enemies.push_back(Character(ObjetoDeJogo("Gato Possuido", SpriteAnimado("../rsc/sprite_cat.anm", 2), 20, 45), 50, 60, 20, 60, 20));

	enemies.push_back(Character(ObjetoDeJogo("Cachorro Infectado", SpriteAnimado("../rsc/sprite_dog.anm", 2), 20, 100), 70, 50, 20, 20, 60));

	enemies.push_back(Character(ObjetoDeJogo("Caveira de Oculos Escuros", SpriteAnimado("../rsc/sprite_skull.anm", 2), 20, 100), 200, 20, 20, 70, 70));

	enemies.push_back(Character(ObjetoDeJogo("Brinquedo Possuido", SpriteAnimado("../rsc/sprite_toy.anm", 2), 20, 100), 150, 20, 60, 30, 70));
	
}

unsigned VillageMap_D::run()
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
		
		showText(posL, posC);

		if(player->colideCom(*west_entrance)){
			player->moveTo(24, 170);
			return OPENING;
		}

		if(player->colideCom(*south_entrance)){
			player->moveTo(7, 100);
			return VILLAGE_G;
		}
		

        if (colideComBloco()) 
			player->moveTo(posL,posC);

		if (var(generator) <= 4){
			battle->setEnemy(getEnemy(random_enemy(generator)), getEnemy(random_enemy(generator)));
			//PlaySound(TEXT("../rsc/bg_sound.wav"), NULL, SND_LOOP | SND_ASYNC);
			battle->run();
		}

        //padrão
		update();
		draw(screen);
		system("cls");
		show(screen);
	}

    return 1;
}