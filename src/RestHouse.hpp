#ifndef __REST_HOUSE__
#define __REST_HOUSE__
#include "Map.hpp"

class RestHouse : public Map
{

    public:

        RestHouse(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    RestHouse(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~RestHouse() {}

        virtual void init();

        virtual unsigned run();

    private:
        ObjetoDeJogo *npc;
        Texts *npc_texts;
        ObjetoDeJogo *table;
        ObjetoDeJogo *south_entrance;

};

#endif 