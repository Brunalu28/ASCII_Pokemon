#include "Batalha.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"

#include <iostream>

void Batalha::init()
{
    // objs.push_back(jogador);
    // objs.push_back(pokemon);
    // objs.push_back(adversario);

    ataques[0] = new ObjetoDeJogo("Card 0", Sprite("../rsc/AtaquesBulbassaur"), 43, 72);
    objs.push_back(ataques[0]);
    ataques[0]->desativarObj();

    ataques[1] = new ObjetoDeJogo("Card 1", Sprite("../rsc/AtaquesCharmander"), 43, 72);
    objs.push_back(ataques[1]);
    ataques[1]->desativarObj();

    ataques[2] = new ObjetoDeJogo("Card 2", Sprite("../rsc/AtaquesPikachu"), 43, 72);
    objs.push_back(ataques[2]);
    ataques[2]->desativarObj();

    ataques[3] = new ObjetoDeJogo("Card 3", Sprite("../rsc/AtaquesSquirtle"), 43, 72);
    objs.push_back(ataques[3]);
    ataques[3]->desativarObj();
}

unsigned Batalha::run(SpriteBuffer &screen)
{
    std::string ent;

    // padrão
    draw(screen);
    system("clear");
    show(screen);

    while (true)
    {
        if(pokemon->getTipo() == Pokemon::GRAMA){
            ataques[0]->ativarObj();
        } else if(pokemon->getTipo() == Pokemon::GRAMA){
            ataques[1]->ativarObj();
        } else if(pokemon->getTipo() == Pokemon::GRAMA){
            ataques[2]->ativarObj();
        } else if(pokemon->getTipo() == Pokemon::GRAMA){
            ataques[3]->ativarObj();
        }

        // lendo entrada
        getline(std::cin, ent);

        // Jogador escolhe ataque do pokemon
        if (ent == "0")
        {
            pokemon->atacar(0, adversario);
        } else if (ent == "1")
        {
            pokemon->atacar(1, adversario);
        } else if (ent == "2")
        {
            pokemon->atacar(2, adversario);
        } else if (ent == "3")
        {
            pokemon->atacar(3, adversario);
        } 

        // Adversário realiza ataque aleatório
        int escolhaAdversario = rand() % 4; 
        adversario->atacar(escolhaAdversario, pokemon);

        if (pokemon->getVida() <= 0)
        {
            return Fase::GAME_OVER;
        }

        if (adversario->getVida() <= 0)
        {
            return Fase::LEVEL_COMPLETE;
        }

        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME; 
}

