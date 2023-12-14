#include "VillageMap_G.hpp"
unsigned seed_g = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator_g(seed_g);
std::uniform_int_distribution<int> var_g(0,100);
std::uniform_int_distribution<int> random_enemy_g(0,1);

void VillageMap_G::init()
{
	gravediggerHouse = new GravediggerHouse("Gravedigger House", Sprite("../rsc/Sprites/bg2.spr"), screen, player, battle);
	gravediggerHouse->init();
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

	wall = new ObjetoDeJogo("Wall", SpriteAnimado("../rsc/Sprites/sprite_wall.anm", 2), 5, 73);
	objs.push_back(wall);
    colisons.push_back(wall);

	houses[0] = new ObjetoDeJogo("House", Sprite("../rsc/Sprites/sprite_house.spr"), 7, 20);
    objs.push_back(houses[0]);
    colisons.push_back(houses[0]);

	houses[1] = new ObjetoDeJogo("House", Sprite("../rsc/Sprites/sprite_big_house.spr"), 2, 135);
    objs.push_back(houses[1]);
    colisons.push_back(houses[1]);

	npcs[0] = new ObjetoDeJogo("Npc", SpriteAnimado("../rsc/Sprites/sprite_npc.anm", 2), 15, 74);
    objs.push_back(npcs[0]);
    colisons.push_back(npcs[0]);

	npcs_texts[0] = new Texts(ObjetoDeJogo("Npc1 Text", Sprite("../rsc/Sprites/sprite_action.spr"), 24, 75));
	objs.push_back(npcs_texts[0]);
	texts.push_back(npcs_texts[0]);
	npcs_texts[0]->readfile("../rsc/Texts/VG_M_Npc1.txt");

	npcs_texts[1] = new Texts(ObjetoDeJogo("Door Text", Sprite("../rsc/Sprites/sprite_action.spr"), 20, 43));
	objs.push_back(npcs_texts[1]);
	texts.push_back(npcs_texts[1]);
	npcs_texts[1]->readfile("../rsc/Texts/VG_M_Door.txt");

    objs.push_back(player);
	
	// Second Layer -----------------------------------------------------------------------------------

	wall_trees[4] = new ObjetoDeJogo("Wall4 Top", Sprite("../rsc/Sprites/sprite_horizontal_wall_tree2_top.spr"), 42, 0);
	objs.push_back(wall_trees[4]);

	east_entrance = new ObjetoDeJogo("West Entrance", Sprite("../rsc/Sprites/sprite_vertical_entrance.spr"), 24, 184);
	objs.push_back(east_entrance);
    colisons.push_back(east_entrance);

    north_entrance = new ObjetoDeJogo("South Entrance", Sprite("../rsc/Sprites/sprite_horizontal_entrance2.spr"), 0, 93);
	objs.push_back(north_entrance);
    colisons.push_back(north_entrance);

	// Third Layer (HUD) -----------------------------------------------------------------------------------

	dialogue_box = new ObjetoDeJogo("Dialogue Box", Sprite("../rsc/Sprites/sprite_dialogue_box.spr"), 41, 20);
	objs.push_back(dialogue_box);
	dialogue_box->desativarObj();

	text = new ObjetoDeJogo("Text", TextSprite(""), 45, 92);
	objs.push_back(text);
	text->desativarObj();

	// Init enemies

	enemies.push_back(Character(ObjetoDeJogo("Gato Possuido", SpriteAnimado("../rsc/Sprites/sprite_cat.anm", 2), 20, 45), 50, 60, 20, 60, 20));

	enemies.push_back(Character(ObjetoDeJogo("Cachorro Infectado", SpriteAnimado("../rsc/Sprites/sprite_dog.anm", 2), 20, 100), 70, 50, 20, 20, 60));
	
}

unsigned VillageMap_G::run()
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
		else if (key == KEY_X)
		{
			if(player->colideCom(*npcs_texts[1])){
				if (player->getSmallKey()){
					player->moveTo(27, 50);
					gravediggerHouse->run();
				}
			}
			showText(posL, posC);
		}
		
		if(player->colideCom(*north_entrance)){
			player->moveTo(34, 100);
			return VILLAGE_D;
		}
		if (player->colideCom(*east_entrance))
		{	
			player->moveTo(24,20);
			return VILLAGE_H;
		}

        if (colideComBloco()) 
			player->moveTo(posL,posC);

		if (var_g(generator_g) < 4){
			PlaySound(TEXT("../rsc/Sounds/sound_enemy.wav"), NULL, SND_SYNC);
			battle->setEnemy(getEnemy(random_enemy_g(generator_g)), getEnemy(random_enemy_g(generator_g)));
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
