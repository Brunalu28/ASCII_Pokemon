#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/Fase.hpp"

#include "Pokemon.hpp"
#include "Start.hpp"
#include "Fase1.hpp"
#include "Fase2.hpp"
#include "Fase3.hpp"
#include "Batalha.hpp"


class Game
{
public:
    Game() {}
    ~Game() {} 

    static void run()
    {
        Jogador *jogador = new Jogador(ObjetoDeJogo("Jogador", SpriteAnimado("../rsc/Personagem.anm", 5), 20, 65), "Ash");
        Pokemon *pikachu = new Pokemon(ObjetoDeJogo("Pikachu", Sprite("../rsc/Pikachu"), 20,15), 50, Pokemon::ELETRICO);
        Pokemon *Charmander = new Pokemon(ObjetoDeJogo("Charmander", Sprite("../rsc/Charmander"), 40,40), 50, Pokemon::FOGO);
        Pokemon *Bulbassauro = new Pokemon(ObjetoDeJogo("Bulbassauro", Sprite("../rsc/Bulbassaur"), 50,60), 50,Pokemon::GRAMA);
        Pokemon *Squirtle = new Pokemon(ObjetoDeJogo("Squirtle", Sprite("../rsc/Squirtle"), 70,75), 50, Pokemon::AGUA);
        SpriteBuffer buffer(193, 52);
        SpriteBuffer bufferStart(154, 38);

        unsigned mapaAtual;

        Fase *start = new Start("Fase inicial", Sprite("../rsc/coverStart"), jogador);
        Fase *fase1 = new Fase1("Mapa 1", Sprite("../rsc/mapa3"), jogador);
        Fase *fase2 = new Fase2("Mapa 2", Sprite("../rsc/mapa5"), jogador);
        Fase *fase3 = new Fase3("Mapa 3", Sprite("../rsc/mapa6"), jogador);
        Fase *batalha = new Batalha("Mapa 3", Sprite("../rsc/mapaBatalha"), jogador, pikachu, Bulbassauro);



        start->init();
        mapaAtual = start->run(bufferStart);
        if (mapaAtual == Fase::END_GAME)
        {
            fase1->init();
            mapaAtual = fase1->run(buffer);
            if(mapaAtual == Fase::FASE_2){
                fase2->init();
                mapaAtual = fase2->run(buffer);
            } else if (mapaAtual == Fase::OP_BULBASSAURO){
                static_cast<Batalha*>(batalha)->setPokemon(jogador->buscaPokemon());
                static_cast<Batalha*>(batalha)->setAdversario(Bulbassauro);
                batalha->init();
                mapaAtual = batalha->run(buffer);
            } else if (mapaAtual == Fase::OP_CHARMANDER){
                static_cast<Batalha*>(batalha)->setPokemon(jogador->buscaPokemon());
                static_cast<Batalha*>(batalha)->setAdversario(Charmander);
                batalha->init();
                mapaAtual = batalha->run(buffer);
            }

            if(mapaAtual == Fase::FASE_3){
                fase3->init();
                mapaAtual = fase3->run(buffer);
                if (mapaAtual == Fase::OP_PIKACHU){
                static_cast<Batalha*>(batalha)->setPokemon(jogador->buscaPokemon());
                static_cast<Batalha*>(batalha)->setAdversario(pikachu);
                batalha->init();
                mapaAtual = batalha->run(buffer);
                }
            }   else if (mapaAtual == Fase::OP_SQUIRTLE){
                static_cast<Batalha*>(batalha)->setPokemon(jogador->buscaPokemon());
                static_cast<Batalha*>(batalha)->setAdversario(Squirtle);
                batalha->init();
                mapaAtual = batalha->run(buffer);
            }
        }
    }
};
#endif
