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
#include "FaseCaptura.hpp"
#include "FaseFim.hpp"


class Game
{
public:
    Game() {}
    ~Game() {} 

    static void run()
    {
        Jogador *jogador = new Jogador(ObjetoDeJogo("Jogador", SpriteAnimado("../rsc/Personagem.anm", 5), 20, 65), "Ash");
        Pokemon *pikachu = new Pokemon(ObjetoDeJogo("Pikachu", Sprite("../rsc/Pikachu"), 5,180), 50, Pokemon::ELETRICO);
        Pokemon *Charmander = new Pokemon(ObjetoDeJogo("Charmander", Sprite("../rsc/Charmander"), 5,180), 50, Pokemon::FOGO);
        Pokemon *Bulbassauro = new Pokemon(ObjetoDeJogo("Bulbassauro", Sprite("../rsc/Bulbassaur"),10,180), 50,Pokemon::GRAMA);
        Pokemon *Squirtle = new Pokemon(ObjetoDeJogo("Squirtle", Sprite("../rsc/Squirtle"), 10,150), 50, Pokemon::AGUA);
        SpriteBuffer buffer(350, 52);
        SpriteBuffer bufferStart(170, 38);

        unsigned mapaAtual;

        Fase *start = new Start("Fase inicial", Sprite("../rsc/coverStart"), jogador);
        Fase *fase1 = new Fase1("Mapa 1", Sprite("../rsc/mapa3"), jogador);
        Fase *fase2 = new Fase2("Mapa 2", Sprite("../rsc/mapa5"), jogador);
        Fase *fase3 = new Fase3("Mapa 3", Sprite("../rsc/mapa6"), jogador);
        Batalha *batalha = new Batalha("Mapa 4", Sprite("../rsc/mapaBatalha"), jogador);
        batalha->init();
        FaseCaptura *captura = new FaseCaptura("Captura Pokemon", Sprite("../rsc/mapaBatalha"));
        FaseFim *fim = new FaseFim("Fim do Jogo", Sprite("../rsc/mapaBatalha"));


        start->init();
        mapaAtual = start->run(buffer);
        if (mapaAtual == Fase::END_GAME)
        {
            fase1->init();
            mapaAtual = fase1->run(buffer);

            if(mapaAtual == Fase::FASE_2){
                fase2->init();
                mapaAtual = fase2->run(buffer);
            } else if (mapaAtual == Fase::OP_BULBASSAURO){
                batalha->setPokemon(*(jogador->buscaPokemon()));
                batalha->setAdversario(*(Bulbassauro));
                mapaAtual = batalha->run(buffer);
                if(mapaAtual == Fase::CAPTURA_POKEMON){
                    captura->init();
                    mapaAtual = captura->run(buffer);
                } else if(mapaAtual == Fase::GAME_OVER){
                    fim->init();
                    mapaAtual = fim->run(buffer);
                }
            } else if (mapaAtual == Fase::OP_CHARMANDER){
                batalha->setPokemon(*(jogador->buscaPokemon()));
                batalha->setAdversario(*(Charmander));
                mapaAtual = batalha->run(buffer);
                if(mapaAtual == Fase::CAPTURA_POKEMON){
                    captura->init();
                    mapaAtual = captura->run(buffer);
                } else if(mapaAtual == Fase::GAME_OVER){
                    fim->init();
                    mapaAtual = fim->run(buffer);
                }
            }
            if(mapaAtual == Fase::FASE_3){
                fase3->init();
                mapaAtual = fase3->run(buffer);
                if (mapaAtual == Fase::OP_PIKACHU){
                    batalha->setPokemon(*(jogador->buscaPokemon()));
                    batalha->setAdversario(*(pikachu));
                    mapaAtual = batalha->run(buffer);
                    if(mapaAtual == Fase::CAPTURA_POKEMON){
                        captura->init();
                        mapaAtual = captura->run(buffer);
                    } else if(mapaAtual == Fase::GAME_OVER){
                        fim->init();
                        mapaAtual = fim->run(buffer);
                }
                }
            } else if (mapaAtual == Fase::OP_SQUIRTLE){
                batalha->setPokemon(*(jogador->buscaPokemon()));
                batalha->setAdversario(*(Squirtle));
                mapaAtual = batalha->run(buffer);
                if(mapaAtual == Fase::CAPTURA_POKEMON){
                    captura->init();
                    mapaAtual = captura->run(buffer);
                } else if(mapaAtual == Fase::GAME_OVER){
                    fim->init();
                    mapaAtual = fim->run(buffer);
                }
            }
        }
    }
};
#endif
