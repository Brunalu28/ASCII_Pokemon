#include "FaseCaptura.hpp"

void FaseCaptura::init()
{
    Capturado = new ObjetoDeJogo("Pokebola", Sprite("../rsc/PokemonCapturado"), 10, 10);
    objs.push_back(Capturado);

}

unsigned FaseCaptura::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	while(true){
        getline(std::cin, ent);

		if (ent == "q"){
			return Fase::LEVEL_COMPLETE;
		}
	}
	
}