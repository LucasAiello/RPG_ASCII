#include "Final.hpp"

void Final::init(){
    objs.push_back(player);
    npc_texts = new Texts(ObjetoDeJogo("Npc1 Text", Sprite("../rsc/Sprites/sprite_action.spr"), 14, 91));
	objs.push_back(npc_texts);
	texts.push_back(npc_texts);
	npc_texts->readfile("../rsc/Texts/F_M_D.txt");
    empty = new ObjetoDeJogo("Vazio", Sprite("../rsc/Sprites/Empty.spr"), 12, 90);
    objs.push_back(empty);
}

unsigned Final::run()
{
    int key = 0;
	int posL = player->getPosL(), posC = player->getPosC();
	player->moveTo(posL,posC);

    std::string ent;
	while(true){
        //padrão
	    draw(screen);
	    system("cls");
	    show(screen);
        key = getch();
        showText(posL, posC);
    }
	

    return 1;
}