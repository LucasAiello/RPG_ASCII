#ifndef __MAP__
#define __MAP__
#include <windows.h>
#include <mmsystem.h>
#include <random>
#include <chrono>
#include <stdlib.h>
#include "ASCII_Engine/Fase.hpp"
#include "Player.hpp"
#include "Texts.hpp"
#include "Battle.hpp"

#define VEL_Y 3
#define VEL_X 9

class Map : public Fase
{
    public:
        Map(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *battle) : Fase(name,bkg), screen(screen), player(player), battle(battle) {}
	    Map(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Fase(name,bkg), screen(screen), player(player), battle(battle){}
	    virtual ~Map() {}

        virtual void init() = 0;

        virtual unsigned run() = 0;

        bool colideComBloco() const;

        void showText(unsigned l, unsigned c);

        Character& getEnemy(int i);


    protected:

        Player *const player;
        ObjetoDeJogo *text;
        ObjetoDeJogo *dialogue_box;
        SpriteBuffer screen;
        Battle *const battle;
        std::list<Character> enemies;

        std::list<ObjetoDeJogo*> colisons;
        std::list<Texts*> texts;
};


#endif 