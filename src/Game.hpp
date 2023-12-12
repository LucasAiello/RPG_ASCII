#ifndef __GAME__
#define __GAME__

#include "GlobalMap.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		
		Player *player = new Player(Character(ObjetoDeJogo("Player", SpriteAnimado("../rsc/sprite_player.anm", 3), 24, 24), 500, 50, 30 , 30, 50));

		SpriteBuffer buffer(200,50);
	
		GlobalMap global ("Global", Sprite("../rsc/bg1.spr"), buffer, player);
        
		
		global.init();
		global.run();
		
	}

};

#endif // GAME_HPP