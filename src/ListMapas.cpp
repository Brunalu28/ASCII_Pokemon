#include "ListMapas.hpp"
#include "Mapa.hpp"

ListMapas::ListMapas(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){}; 

void ListMapas::init()
{
    mapas[0] = new Mapa(ObjetoDeJogo("Mapa 1", Sprite("../rsc/Mapa_1")));
    objs.push_back(mapas[0]);

mapas[1] = new Mapa(Sprite("../rsc/Mapa_1"));
    objs.push_back(mapas[1]);

    mapas[2] = new Mapa(Sprite("../rsc/Mapa_1"));
    objs.push_back(mapas[2]);

    mapas[3] = new Mapa(Sprite("../rsc/Mapa_1"));
    objs.push_back(mapas[3]);
}

unsigned ListMapas::run(SpriteBuffer &screen)
{


    return Fase::END_GAME;
}
