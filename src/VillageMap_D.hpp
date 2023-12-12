#ifndef __VILLAGE_MAP_D__
#define __VILLAGE_MAP_D__
#include "Map.hpp"

class VillageMap_D : public Map
{

    public:

        VillageMap_D(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_D(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_D() {}

        virtual void init();

        virtual unsigned run();

    private:

        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *houses[2];
        ObjetoDeJogo *south_entrance;
        ObjetoDeJogo *west_entrance;
        ObjetoDeJogo *sign;

};

#endif 