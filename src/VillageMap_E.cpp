#include "VillageMap_E.hpp"
#include "RestHouse.hpp"
unsigned seed_e = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator_e(seed_e);
std::uniform_int_distribution<int> var_e(0,100);
std::uniform_int_distribution<int> random_enemy_e(0,1);

void VillageMap_E::init()
{
	rest_house = new RestHouse("Rest House", Sprite("../rsc/Sprites/bg2.spr"), screen, player, battle);
	rest_house->init();
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

	house = new ObjetoDeJogo("House", Sprite("../rsc/Sprites/sprite_big_house.spr"), 1, 15);
    objs.push_back(house);
    colisons.push_back(house);

	house_entrance = new ObjetoDeJogo("House Entrance", Sprite("../rsc/Sprites/sprite_action.spr"), 20, 38);
	objs.push_back(house_entrance);

    objs.push_back(player);
	
	// Second Layer -----------------------------------------------------------------------------------

	wall_trees[4] = new ObjetoDeJogo("Wall4 Top", Sprite("../rsc/Sprites/sprite_horizontal_wall_tree2_top.spr"), 42, 0);
	objs.push_back(wall_trees[4]);

    north_entrance = new ObjetoDeJogo("South Entrance", Sprite("../rsc/Sprites/sprite_horizontal_entrance2.spr"), 0, 93);
	objs.push_back(north_entrance);
    colisons.push_back(north_entrance);

    south_entrance = new ObjetoDeJogo("South Entrance", Sprite("../rsc/Sprites/sprite_horizontal_entrance.spr"), 42, 93);
	objs.push_back(south_entrance);
    colisons.push_back(south_entrance);

	// Third Layer (HUD) -----------------------------------------------------------------------------------

	dialogue_box = new ObjetoDeJogo("Dialogue Box", Sprite("../rsc/Sprites/sprite_dialogue_box.spr"), 41, 20);
	objs.push_back(dialogue_box);
	dialogue_box->desativarObj();

	text = new ObjetoDeJogo("Text", TextSprite(""), 45, 92);
	objs.push_back(text);
	text->desativarObj();

	enemies.push_back(Character(ObjetoDeJogo("Caveira de Oculos Escuros", SpriteAnimado("../rsc/Sprites/sprite_skull.anm", 2), 20, 100), 200, 20, 20, 70, 70));

	enemies.push_back(Character(ObjetoDeJogo("Brinquedo Possuido", SpriteAnimado("../rsc/Sprites/sprite_toy.anm", 2), 20, 100), 150, 20, 60, 30, 70));
	
}

unsigned VillageMap_E::run()
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

		if(player->colideCom(*south_entrance)){
			player->moveTo(7, 100);
			return VILLAGE_H;
		}
		if(player->colideCom(*north_entrance)){
			player->moveTo(34, 100);
			return VILLAGE_B;
		}

		if(player->colideCom(*house_entrance)){
			player->moveTo(27, 50);
			rest_house->run();
		}

        if (colideComBloco()) 
			player->moveTo(posL,posC);
		
		if (var_e(generator_e) < 4){
			PlaySound(TEXT("../rsc/Sounds/sound_enemy.wav"), NULL, SND_SYNC);
			battle->setEnemy(getEnemy(random_enemy_e(generator_e)), getEnemy(random_enemy_e(generator_e)));
			//PlaySound(TEXT("../rsc/bg_sound.wav"), NULL, SND_LOOP | SND_ASYNC);
			if(battle->run() == GAME_OVER) return GAME_OVER;
			PlaySound(TEXT("../rsc/Sounds/bg_music.wav"), NULL, SND_LOOP | SND_ASYNC);
		}

        //padrão
		update();
		draw(screen);
		system("cls");
		show(screen);
	}

    return 1;
}