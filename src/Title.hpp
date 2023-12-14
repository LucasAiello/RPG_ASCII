#ifndef __TITLE__
#define __TITLE__
#include "ASCII_Engine/Fase.hpp"
class Title : public Fase
{
    public:
        Title(std::string name, const Sprite &bkg, SpriteBuffer &screen) : Fase(name, bkg), screen(screen){}
        Title(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen) : Fase(name, bkg), screen(screen){}
        virtual ~Title() {}

        virtual void init(){};

        virtual unsigned run()
        {
            draw(screen);
	        system("cls");
	        show(screen);
            int key = 0;
            key = getch();

            return OPENING;
        };
    private:
        SpriteBuffer screen;
};

#endif 