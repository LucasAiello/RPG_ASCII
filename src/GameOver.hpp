#ifndef __GAME_OVER__
#define __GAME_OVER__
#include "ASCII_Engine/Fase.hpp"
class GameOver : public Fase
{
    public:
        GameOver(std::string name, const Sprite &bkg, SpriteBuffer &screen) : Fase(name, bkg), screen(screen){}
        GameOver(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen) : Fase(name, bkg), screen(screen){}
        virtual ~GameOver() {}

        virtual void init(){
            int key = 0;
        };

        virtual unsigned run()
        {
            draw(screen);
	        system("cls");
	        show(screen);
            int key = 0;
            std::cin >> key;
            exit (0);
        };
    private:
        SpriteBuffer screen;
};

#endif 