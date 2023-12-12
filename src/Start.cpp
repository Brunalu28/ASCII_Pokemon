#include "Start.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"

#include <iostream>

void Start::init()
{
}

unsigned Start::run(SpriteBuffer &screen)
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

        // processando entradas

        if (ent == "1")
            jogador->adicionaPokemon(pikachu);
            return Fase::END_GAME;
        if (ent == "2")
            jogador->adicionaPokemon(charmander);
            cout << jogador->buscaPokemon("fogo");
            break;
        if (ent == "3")
            jogador->adicionaPokemon(bulbassauro);
            return Fase::END_GAME;
        if (ent == "4")
            jogador->adicionaPokemon(squirtle);
            return Fase::END_GAME;

        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }
    return Fase::GAME_OVER;

}