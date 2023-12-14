#ifndef __GLOBAL_MAP__
#define __GLOBAL_MAP__
#include "ASCII_Engine/Fase.hpp"
#include "Title.hpp"
#include "GameOver.hpp"
#include "OpeningMap.hpp"
#include "VillageMap_B.hpp"
#include "VillageMap_C.hpp"
#include "VillageMap_D.hpp"
#include "VillageMap_E.hpp"
#include "VillageMap_F.hpp"
#include "VillageMap_G.hpp"
#include "VillageMap_H.hpp"
#include "Battle.hpp"


class GlobalMap : public Fase
{
    public:

        GlobalMap(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player) : Fase(name,bkg), screen(screen), player(player){}
	    GlobalMap(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player) : Fase(name,bkg), screen(screen), player(player){}
	    virtual ~GlobalMap() {}

        virtual void init();

        virtual unsigned run();

    private:
        SpriteBuffer screen;
        Player *const player;
        Fase* maps[10];
        Battle *battle;
};

#endif