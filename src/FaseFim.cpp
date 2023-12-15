#include "FaseFim.hpp"

void FaseFim::init()
{
    fim = new ObjetoDeJogo("FIM", Sprite("../rsc/fimJogo"), 15, 35);
    objs.push_back(fim);

}

unsigned FaseFim::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	
	
	return Fase::END_GAME;
}