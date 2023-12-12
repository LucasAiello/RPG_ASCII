#ifndef __VILLAGE_MAP_C__
#define __VILLAGE_MAP_C__
#include "Map.hpp"

class VillageMap_C : public Map
{

    public:

        VillageMap_C(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_C(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_C() {}

        virtual void init();

        virtual unsigned run();

    private:

        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *south_entrance;
        ObjetoDeJogo *west_entrance;
        
};

#endif 