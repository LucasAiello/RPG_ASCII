#ifndef __VILLAGE_MAP_A__
#define __VILLAGE_MAP_A__
#include "Map.hpp"

class VillageMap_A : public Map
{

    public:

        VillageMap_A(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_A(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_A() {}

        virtual void init();

        virtual unsigned run();

    private:

        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *east_entrance;

};

#endif 