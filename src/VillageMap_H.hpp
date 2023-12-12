#ifndef __VILLAGE_MAP_H__
#define __VILLAGE_MAP_H__
#include "Map.hpp"


class VillageMap_H : public Map
{

    public:

        VillageMap_H(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_H(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_H() {}

        virtual void init();

        virtual unsigned run();

    private:

        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *north_entrance;
        ObjetoDeJogo *east_entrance;
        ObjetoDeJogo *west_entrance;
        
};

#endif 