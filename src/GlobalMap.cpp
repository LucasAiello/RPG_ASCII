#include "GlobalMap.hpp"
#include <windows.h>
#include <mmsystem.h>

void GlobalMap::init(){
    std::string background = "../rsc/Sprites/bg1.spr";
    Battle* battle = new Battle("Battle", Sprite(background), screen, player);
    battle->init();
    
    maps[TITLE] = new Title("Begin", Sprite("../rsc/Sprites/bg0.spr"), screen);
    maps[TITLE]->init();

    maps[GAME_OVER] = new GameOver("Game Over", Sprite("../rsc/Sprites/bg3.spr"), screen);
    maps[GAME_OVER]->init();

    maps[OPENING] = new OpeningMap("Begin", Sprite(background), screen, player, battle);
    maps[OPENING]->init();

    maps[VILLAGE_B] = new VillageMap_B("Village B", Sprite(background), screen, player, battle);
    maps[VILLAGE_B]->init();

    maps[VILLAGE_C] = new VillageMap_C("Village C", Sprite(background), screen, player, battle);
    maps[VILLAGE_C]->init();

    maps[VILLAGE_D] = new VillageMap_D("Village D", Sprite(background), screen, player, battle);
    maps[VILLAGE_D]->init();

    maps[VILLAGE_E] = new VillageMap_E("Village E", Sprite(background), screen, player, battle);
    maps[VILLAGE_E]->init();

    maps[VILLAGE_F] = new VillageMap_F("Village F", Sprite(background), screen, player, battle);
    maps[VILLAGE_F]->init();

    maps[VILLAGE_G] = new VillageMap_G("Village G", Sprite(background), screen, player, battle);
    maps[VILLAGE_G]->init();

    maps[VILLAGE_H] = new VillageMap_H("Village H", Sprite(background), screen, player, battle);
    maps[VILLAGE_H]->init();
}

unsigned  GlobalMap::run()
{   
    unsigned map = TITLE;

    while (map != GAME_OVER)
    {
        map = maps[map]->run();
        //PlaySound(TEXT("../rsc/Sprites/beep.wav"), NULL, SND_FILENAME);
    }

    return 1;
}