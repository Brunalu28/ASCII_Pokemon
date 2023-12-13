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
        {
            if(jogador->adicionaPokemon(pikachu) == false)
            {
            cout << "deu negado" << endl; 
            }
        }
        else if (ent == "2")
        {
            jogador->adicionaPokemon(charmander);
            return Fase::END_GAME;
        }
        else if (ent == "3")
        {
            jogador->adicionaPokemon(bulbassauro);
            return Fase::END_GAME;
        }
        else if (ent == "4")
        {
            jogador->adicionaPokemon(squirtle);
            return Fase::END_GAME;
        }
        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return 0;

}