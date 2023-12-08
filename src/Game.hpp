#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/Fase.hpp"
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
        SpriteBuffer buffer(192, 52);

        unsigned mapaAtual;

        Fase *fase1 = new Fase1("Mapa 1", Sprite("../rsc/mapa3"), jogador);
        Fase *fase2 = new Fase2("Mapa 2", Sprite("../rsc/mapa4"), jogador);

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
