#include "VillageMap_F.hpp"

void VillageMap_F::init()
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

	cemetery_house = new ObjetoDeJogo("Cemetery House", Sprite("../rsc/sprite_cemetery_house.spr"), 20, 125);
	objs.push_back(cemetery_house);
    colisons.push_back(cemetery_house);

	tombstones[0] = new ObjetoDeJogo("Tombstone 1", Sprite("../rsc/sprite_tombstone.spr"), 14, 18);
	objs.push_back(tombstones[0]);
    colisons.push_back(tombstones[0]);

	tombstones[1] = new ObjetoDeJogo("Tombstone 2", Sprite("../rsc/sprite_tombstone.spr"), 14, 35);
	objs.push_back(tombstones[1]);
    colisons.push_back(tombstones[1]);

	tombstones[2] = new ObjetoDeJogo("Tombstone 3", Sprite("../rsc/sprite_tombstone.spr"), 14, 52);
	objs.push_back(tombstones[2]);
    colisons.push_back(tombstones[2]);

	tombstones[3] = new ObjetoDeJogo("Tombstone 4", Sprite("../rsc/sprite_tombstone.spr"), 14, 69);
	objs.push_back(tombstones[3]);
    colisons.push_back(tombstones[3]);

	tombstones[4] = new ObjetoDeJogo("Tombstone 5", Sprite("../rsc/sprite_tombstone.spr"), 29, 18);
	objs.push_back(tombstones[4]);
    colisons.push_back(tombstones[4]);

	tombstones[5] = new ObjetoDeJogo("Tombstone 6", Sprite("../rsc/sprite_tombstone.spr"), 29, 35);
	objs.push_back(tombstones[5]);
    colisons.push_back(tombstones[5]);

	tombstones[6] = new ObjetoDeJogo("Tombstone 7", Sprite("../rsc/sprite_tombstone.spr"), 29, 52);
	objs.push_back(tombstones[6]);
    colisons.push_back(tombstones[6]);

	tombstones[7] = new ObjetoDeJogo("Tombstone 8", Sprite("../rsc/sprite_tombstone.spr"), 29, 69);
	objs.push_back(tombstones[7]);
    colisons.push_back(tombstones[7]);

    objs.push_back(player);
	
	// Second Layer -----------------------------------------------------------------------------------

	tombstones_top[0] = new ObjetoDeJogo("Tombstone Top 1", Sprite("../rsc/sprite_tombstone_top.spr"), 9, 18);
	objs.push_back(tombstones_top[0]);

	tombstones_top[1] = new ObjetoDeJogo("Tombstone Top 2", Sprite("../rsc/sprite_tombstone_top.spr"), 9, 35);
	objs.push_back(tombstones_top[1]);

	tombstones_top[2] = new ObjetoDeJogo("Tombstone Top 3", Sprite("../rsc/sprite_tombstone_top.spr"), 9, 52);
	objs.push_back(tombstones_top[2]);

	tombstones_top[3] = new ObjetoDeJogo("Tombstone Top 4", Sprite("../rsc/sprite_tombstone_top.spr"), 9, 69);
	objs.push_back(tombstones_top[3]);

	tombstones_top[4] = new ObjetoDeJogo("Tombstone Top 5", Sprite("../rsc/sprite_tombstone_top.spr"), 24, 18);
	objs.push_back(tombstones_top[4]);

	tombstones_top[5] = new ObjetoDeJogo("Tombstone Top 6", Sprite("../rsc/sprite_tombstone_top.spr"), 24, 35);
	objs.push_back(tombstones_top[5]);

	tombstones_top[6] = new ObjetoDeJogo("Tombstone Top 7", Sprite("../rsc/sprite_tombstone_top.spr"), 24, 52);
	objs.push_back(tombstones_top[6]);

	tombstones_top[7] = new ObjetoDeJogo("Tombstone Top 8", Sprite("../rsc/sprite_tombstone_top.spr"), 24, 69);
	objs.push_back(tombstones_top[7]);

	cemetery_house_top = new ObjetoDeJogo("Cemetery House Top", Sprite("../rsc/sprite_cemetery_house_top.spr"), 10, 125);
	objs.push_back(cemetery_house_top);

	wall_trees[4] = new ObjetoDeJogo("Wall4 Top", Sprite("../rsc/sprite_horizontal_wall_tree2_top.spr"), 42, 0);
	objs.push_back(wall_trees[4]);

    north_entrance = new ObjetoDeJogo("South Entrance", Sprite("../rsc/sprite_horizontal_entrance2.spr"), 0, 93);
	objs.push_back(north_entrance);
    colisons.push_back(north_entrance);

	// Third Layer (HUD) -----------------------------------------------------------------------------------

	dialogue_box = new ObjetoDeJogo("Dialogue Box", Sprite("../rsc/sprite_dialogue_box.spr"), 41, 20);
	objs.push_back(dialogue_box);
	dialogue_box->desativarObj();

	text = new ObjetoDeJogo("Text", TextSprite(""), 45, 92);
	objs.push_back(text);
	text->desativarObj();
	
}

unsigned VillageMap_F::run()
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

		if(player->colideCom(*north_entrance))
        {
			player->moveTo(34, 100);
			return VILLAGE_C;
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