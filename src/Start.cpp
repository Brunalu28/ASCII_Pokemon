#include "Start.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"

#include <iostream>

void Start::init()
{
    tituloCover = new ObjetoDeJogo("tituloCover", Sprite("../rsc/tituloCover"), 8, 37);
    objs.push_back(tituloCover);

    instrucoes = new ObjetoDeJogo("instrucoes", Sprite("../rsc/instrucoes"), 10, 35);
    objs.push_back(instrucoes);
    instrucoes->desativarObj();
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
            jogador->adicionaPokemon(new Pokemon(ObjetoDeJogo("Pikachu", Sprite("../rsc/Pikachu"), 5,20), 50, Pokemon::ELETRICO));
                tituloCover->desativarObj();
                instrucoes->ativarObj();

        }
        else if (ent == "2")
        {
            jogador->adicionaPokemon(new Pokemon(ObjetoDeJogo("Charmander", Sprite("../rsc/Charmander"), 5,20), 50, Pokemon::FOGO));
                tituloCover->desativarObj();
                instrucoes->ativarObj();

        }
        else if (ent == "3")
        {
            jogador->adicionaPokemon(new Pokemon(ObjetoDeJogo("Bulbassauro", Sprite("../rsc/Bulbassaur"), 5,20), 50,Pokemon::GRAMA));
                tituloCover->desativarObj();
                instrucoes->ativarObj();

        }
        else if (ent == "4")
        {
            jogador->adicionaPokemon(new Pokemon(ObjetoDeJogo("Squirtle", Sprite("../rsc/Squirtle"), 5,20), 50, Pokemon::AGUA));
                tituloCover->desativarObj();
                instrucoes->ativarObj();

        }
        if (ent == "i"){
            return Fase::END_GAME;
        }
        
        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }
}