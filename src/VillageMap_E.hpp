#ifndef __VILLAGE_MAP_E__
#define __VILLAGE_MAP_E__
#include "Map.hpp"

class VillageMap_E : public Map
{

    public:

        VillageMap_E(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_E(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_E() {}

        virtual void init();

        virtual unsigned run();

    private:
        Map *rest_house;
        ObjetoDeJogo *house;
        ObjetoDeJogo *house_entrance;
        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *north_entrance;
        ObjetoDeJogo *south_entrance;

};

#endif 