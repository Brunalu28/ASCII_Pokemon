#ifndef FASE_HPP
#define FASE_HPP

#include "SpriteBase.hpp"
#include "SpriteBuffer.hpp"
#include "ObjetoDeJogo.hpp"
#include "Sprite.hpp"
#include "SpriteAnimado.hpp"
#include <list>
#include <string>
#include <iostream>

//Abstrata
class Fase : public RenderBase
{
public:

	enum {
		GAME_OVER,												//jogador nao completou fase
		MENU,													//opcao padrao para indicar fase menu
		OP_BULBASSAURO, OP_CHARMANDER, OP_PIKACHU, OP_SQUIRTLE,	//opcoes para Pokemon
		FASE_1, FASE_2, FASE_3, BATALHA, CAPTURA_POKEMON,     	//fases
		PLAYING, PAUSED,										//opcoes para a fase
		LEVEL_COMPLETE,											//fase completada
		END_GAME												//quando jogador nao quiser mais jogar
	};


	Fase(std::string name, const Sprite &bkg) : name(name),background(new Sprite(bkg)) {}
	Fase(std::string name, const SpriteAnimado &bkg) : name(name),background(new SpriteAnimado(bkg)) {}
	virtual ~Fase();
	
	Fase(const Fase &f);
	
	const Fase &operator=(const Fase &);
	
	std::string getName() { return name;}
	
	virtual unsigned run(SpriteBuffer &screen) = 0; //cada derivada tem de implementar sua lógica nesse método
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
