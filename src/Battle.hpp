#ifndef __BATTLE__
#define __BATTLE__
#include "ASCII_Engine/Fase.hpp"
#include "Player.hpp"
#include "Texts.hpp"

class Battle : public Fase
{

    public:
        Battle(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player) : Fase(name, bkg), player(player), screen(screen), enemies_cont(0) {}
	    Battle(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player) : Fase(name, bkg), player(player), screen(screen), enemies_cont(0) {}
	    virtual ~Battle() {}

        virtual void init();

        virtual unsigned run();

        void showText(std::string text);

        void setEnemy(const Character &enemy1, const Character &enemy2);

        void clearScreen()
        {
            update();
		    draw(screen);
		    system("cls");
		    show(screen);
        }

        void resolveAttack(Character *const target, int type);


    private:
        Character *enemies[2];
        ObjetoDeJogo *menu;
        Player *const player; 
        ObjetoDeJogo *option_menu;
        ObjetoDeJogo *option_enemy;
        SpriteBuffer screen;
        ObjetoDeJogo *text;
        ObjetoDeJogo *dialogue_box;
        ObjetoDeJogo *life_hud;
        ObjetoDeJogo *life_value;
        int option;
        int value_option_enemy;
        int enemies_cont;
};


#endif 