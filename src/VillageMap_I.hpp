#ifndef __VILLAGE_MAP_I__
#define __VILLAGE_MAP_I__
#include "Map.hpp"

class VillageMap_I : public Map
{

    public:

        VillageMap_I(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_I(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_I() {}

        virtual void init();

        virtual unsigned run();


    private:

        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *west_entrance;

};

#endif 