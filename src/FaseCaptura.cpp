#include "FaseCaptura.hpp"

void FaseCaptura::init()
{
    Capturado = new ObjetoDeJogo("Pokebola", Sprite("../rsc/PokemonCapturado"), 2, 15);
    objs.push_back(Capturado);

    pokebola = new ObjetoDeJogo("Pokebola", Sprite("../rsc/PokebolaAnimada"), 20, 70);
    objs.push_back(pokebola);
}

unsigned FaseCaptura::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	
	
	return Fase::END_GAME;
}