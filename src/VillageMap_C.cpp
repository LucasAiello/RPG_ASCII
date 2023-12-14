#include "VillageMap_C.hpp"

void VillageMap_C::init()
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
    
	well = new ObjetoDeJogo("Well", Sprite("../rsc/Sprites/sprite_well.spr"), 3, 150);
	objs.push_back(well);
    colisons.push_back(well);

	npc_texts = new Texts(ObjetoDeJogo("Npc1 Text", Sprite("../rsc/Sprites/sprite_action.spr"), 17, 157));
	objs.push_back(npc_texts);
	texts.push_back(npc_texts);
	npc_texts->readfile("../rsc/Texts/VC_M_Well.txt");

    objs.push_back(player);
	
	// Second Layer -----------------------------------------------------------------------------------

	wall_trees[4] = new ObjetoDeJogo("Wall4 Top", Sprite("../rsc/Sprites/sprite_horizontal_wall_tree2_top.spr"), 42, 0);
	objs.push_back(wall_trees[4]);

	west_entrance = new ObjetoDeJogo("West Entrance", Sprite("../rsc/Sprites/sprite_vertical_entrance.spr"), 24, 0);
	objs.push_back(west_entrance);
    colisons.push_back(west_entrance);

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
	
}

unsigned VillageMap_C::run()
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
			if(player->colideCom(*npc_texts))
			{
				showText(posL, posC);
				player->setSmallKey();
				npc_texts->desativarObj();
			}
		}

		if(player->colideCom(*south_entrance)){
			player->moveTo(7, 100);
			return VILLAGE_F;
		}
		if(player->colideCom(*west_entrance)){
			player->moveTo(24, 170);
			return VILLAGE_B;
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