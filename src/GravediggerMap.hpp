#ifndef __GRAVEDIGGER_HOUSE__
#define __GRAVEDIGGER_HOUSE__
#include "Map.hpp"

class GravediggerHouse : public Map
{

    public:

        GravediggerHouse(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    GravediggerHouse(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~GravediggerHouse() {}

        virtual void init();

        virtual unsigned run();

    private:
        ObjetoDeJogo *npc;
        Texts *npc_texts;
        Texts *text_battle;
        ObjetoDeJogo *table;
        ObjetoDeJogo *south_entrance;

};

#endif 