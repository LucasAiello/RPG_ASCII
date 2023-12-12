#include "GlobalMap.hpp"
#include <windows.h>
#include <mmsystem.h>

void GlobalMap::init(){
    Battle* battle = new Battle("Battle", Sprite("../rsc/bg1.spr"), screen, player);
    battle->init();

    maps[OPENING] = new OpeningMap("Begin", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[OPENING]->init();
    maps[VILLAGE_A] = new VillageMap_A("Village A", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_A]->init();

    maps[VILLAGE_B] = new VillageMap_B("Village B", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_B]->init();

    maps[VILLAGE_C] = new VillageMap_C("Village C", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_C]->init();

    maps[VILLAGE_D] = new VillageMap_D("Village D", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_D]->init();

    maps[VILLAGE_E] = new VillageMap_E("Village E", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_E]->init();

    maps[VILLAGE_F] = new VillageMap_F("Village F", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_F]->init();

    maps[VILLAGE_G] = new VillageMap_G("Village G", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_G]->init();

    maps[VILLAGE_H] = new VillageMap_H("Village H", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_H]->init();

    maps[VILLAGE_I] = new VillageMap_I("Village I", Sprite("../rsc/bg1.spr"), screen, player, battle);
    maps[VILLAGE_I]->init();
}

unsigned  GlobalMap::run()
{   
    unsigned map = OPENING;

    while (map != GAME_OVER)
    {
        map = maps[map]->run();
        //PlaySound(TEXT("../rsc/beep.wav"), NULL, SND_FILENAME);
    }

    return 1;
}