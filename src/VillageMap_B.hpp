#ifndef __VILLAGE_MAP_B__
#define __VILLAGE_MAP_B__
#include "Map.hpp"

class VillageMap_B : public Map
{

    public:

        VillageMap_B(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_B(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_B() {}

        virtual void init();

        virtual unsigned run();

    private:

        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *south_entrance;
        ObjetoDeJogo *east_entrance;
        
};

#endif 