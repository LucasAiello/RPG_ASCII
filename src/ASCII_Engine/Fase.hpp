#ifndef FASE_HPP
#define FASE_HPP

#include <conio.h>
#include "SpriteBase.hpp"
#include "SpriteBuffer.hpp"
#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"
#include "SpriteAnimado.hpp"
#include <list>
#include <string>
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_Q 113

//Abstrata
class Fase : public RenderBase
{
public:

	enum {
		OPENING, VILLAGE_A, VILLAGE_B, VILLAGE_C, VILLAGE_D, VILLAGE_E, VILLAGE_F, VILLAGE_G, VILLAGE_H, VILLAGE_I,
		BATTLE, GAME_OVER
	};


	Fase(std::string name, const Sprite &bkg) : name(name),background(new Sprite(bkg)) {}
	Fase(std::string name, const SpriteAnimado &bkg) : name(name),background(new SpriteAnimado(bkg)) {}
	virtual ~Fase();
	
	Fase(const Fase &f);
	
	const Fase &operator=(const Fase &);
	
	std::string getName() { return name;}
	
	virtual unsigned run() = 0; //cada derivada tem de implementar sua lógica nesse método
	void show(SpriteBuffer &screen) const {std::cout << screen << std::endl;};
	
	//RenderBase
	virtual void init() = 0;
	virtual void update();
	virtual void draw(SpriteBase &screen, unsigned x = 0, unsigned y = 0);

protected:
	std::string name;
	SpriteBase *background;
	std::list<ObjetoDeJogo*> objs;
};

#endif // FASE_HPP
