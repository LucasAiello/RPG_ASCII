#ifndef __VILLAGE_MAP_G__
#define __VILLAGE_MAP_G__
#include "Map.hpp"
#include "GravediggerMap.hpp"

class VillageMap_G : public Map
{

    public:

        VillageMap_G(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_G(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_G() {}

        virtual void init();

        virtual unsigned run();

    private:
        Map *gravediggerHouse;
        ObjetoDeJogo *npcs[2];
        Texts *npcs_texts[2];
        ObjetoDeJogo *wall;
        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *houses[2];
        ObjetoDeJogo *north_entrance;
        ObjetoDeJogo *east_entrance;

};

#endif 