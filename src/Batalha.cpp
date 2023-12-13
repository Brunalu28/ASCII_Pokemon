#include "Fase2.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"

#include <iostream>

void Fase2::init()
{
    objs.push_back(jogador);
    Pokemon *pokemon = jogador->buscaPokemon();
    objs.push_back(pokemon);
    
}

unsigned Fase2::run(SpriteBuffer &screen)
{
    std::string ent;

    // padrão
    draw(screen);
    system("clear");
    show(screen);

    while (true)
    {
        // lendo entrada
        getline(std::cin, ent);

        // loop de funcionamento da batalha a fazer

        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME; 
}

