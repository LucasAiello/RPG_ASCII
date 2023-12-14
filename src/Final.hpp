#ifndef __FINAL__
#define __FINAL__
#include "Map.hpp"

class Final : public Map
{

    public:

        Final(std::string name, const Sprite &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    Final(std::string name, const SpriteAnimado &bkg, SpriteBuffer &screen, Player *const player, Battle *const battle) : Map(name, bkg, screen, player, battle){}
	    virtual ~Final() {}

        virtual void init();

        virtual unsigned run();

    private:
        ObjetoDeJogo *empty;
        Texts *npc_texts;
};

#endif 