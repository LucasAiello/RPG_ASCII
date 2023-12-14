#ifndef __VILLAGE_MAP_F__
#define __VILLAGE_MAP_F__
#include "Map.hpp"


class VillageMap_F : public Map
{

    public:

        VillageMap_F(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    VillageMap_F(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~VillageMap_F() {}

        virtual void init();

        virtual unsigned run();

    private:
        Texts *npc_texts;
        ObjetoDeJogo *wall_trees[4];
        ObjetoDeJogo *tombstones[8];
        ObjetoDeJogo *tombstones_top[8];
        ObjetoDeJogo *cemetery_house;
        ObjetoDeJogo *cemetery_house_top;
        ObjetoDeJogo *north_entrance;

};

#endif 