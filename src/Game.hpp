#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/Fase.hpp"

#include "Pokemon.hpp"
#include "Fase1.hpp"
#include "Fase2.hpp"

class Game
{
public:
    Game() {}
    ~Game() {} 

    static void run()
    {
        Jogador *jogador = new Jogador(ObjetoDeJogo("Jogador", SpriteAnimado("../rsc/Personagem.anm", 2), 20, 20), "Ash");
        Pokemon *pikachu = new Pokemon(ObjetoDeJogo("Pikachu", Sprite("../rsc/Pikachu"), 20,15), 50, "eletrico");
        Pokemon *Charmander = new Pokemon(ObjetoDeJogo("Charmander", Sprite("../rsc/Charmander"), 40,40), 50, "fogo");
        Pokemon *Bubassauro = new Pokemon(ObjetoDeJogo("Bubassauro", Sprite("../rsc/Bubassaur"), 50,60), 50,"grama");
        Pokemon *Squirtle = new Pokemon(ObjetoDeJogo("Squirtle", Sprite("../rsc/Squirtle"), 70,75), 50, "aquatico");
        SpriteBuffer buffer(192, 52);

        unsigned mapaAtual;

        Fase *fase1 = new Fase1("Mapa 1", Sprite("../rsc/mapa3"), jogador);
        Fase *fase2 = new Fase2("Mapa 2", Sprite("../rsc/mapa5"), jogador);

        fase1->init();
        mapaAtual = fase1->run(buffer);
        if (mapaAtual == Fase::FASE_2)
        {
            fase2->init();
            mapaAtual = fase2->run(buffer);
        }
    }
};
#endif
