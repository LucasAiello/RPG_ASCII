#ifndef __OPENING_MAP__
#define __OPENING_MAP__
#include "Map.hpp"

class OpeningMap : public Map
{

    public:

        OpeningMap(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    OpeningMap(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~OpeningMap() {}

        virtual void init();

        virtual unsigned run();
    private:

        ObjetoDeJogo *wall_trees[5];
        ObjetoDeJogo *house;
        ObjetoDeJogo *east_entrance;
        Texts *west_entrance;
        ObjetoDeJogo *fence;
        ObjetoDeJogo *sign;
        Texts *sign_text;
        Texts *house_text;
        
};

#endif 