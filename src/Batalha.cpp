#include "Batalha.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"
#include "ASCII_Engine/Sound.hpp"


#include <iostream>

void Batalha::init()
{

    pokemon = new Pokemon(ObjetoDeJogo("Bulbassauro", Sprite("../rsc/Bulbassaur"), 5,20), 50,Pokemon::GRAMA);
    adversario = new Pokemon(ObjetoDeJogo("Squirtle", Sprite("../rsc/Squirtle"), 5,60), 50, Pokemon::AGUA);

    objs.push_back(pokemon);
    objs.push_back(adversario);

    ataques[0] = new ObjetoDeJogo("Card 0", Sprite("../rsc/AtaquesBulbassaur"), 39, 50);
    objs.push_back(ataques[0]);
    ataques[0]->desativarObj();

    ataques[1] = new ObjetoDeJogo("Card 1", Sprite("../rsc/AtaquesCharmander"), 39, 50);
    objs.push_back(ataques[1]);
    ataques[1]->desativarObj();

    ataques[2] = new ObjetoDeJogo("Card 2", Sprite("../rsc/AtaquesPikachu"), 39, 50);
    objs.push_back(ataques[2]);
    ataques[2]->desativarObj();

    ataques[3] = new ObjetoDeJogo("Card 3", Sprite("../rsc/AtaquesSquirtle"), 39, 50);
    objs.push_back(ataques[3]);
    ataques[3]->desativarObj();
    
    vida[0] = new ObjetoDeJogo("Life Value", TextSprite("VIDA: "), 2, 14);
    objs.push_back(vida[0]);

    vida[1] = new ObjetoDeJogo("Life Value", TextSprite("VIDA: "), 2, 120);
    objs.push_back(vida[1]);

}

unsigned Batalha::run(SpriteBuffer &screen)
{
    std::string ent;

        if(pokemon->getTipo() == Pokemon::GRAMA){
            ataques[0]->ativarObj();
        } else if(pokemon->getTipo() == Pokemon::FOGO){
            ataques[1]->ativarObj();
        } else if(pokemon->getTipo() == Pokemon::ELETRICO){
            ataques[2]->ativarObj();
        } else if(pokemon->getTipo() == Pokemon::AGUA){
            ataques[3]->ativarObj();
        }


    // padrão
    draw(screen);
    system("clear");
    show(screen);

    *vida[0] = ObjetoDeJogo("Life Value", TextSprite("VIDA: " + std::to_string(pokemon->getVida())), 2, 14);
    *vida[1] = ObjetoDeJogo("Life Value", TextSprite("VIDA: " + std::to_string(adversario->getVida())), 2, 120);

    while (true)
    {
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

        *vida[0] = ObjetoDeJogo("Life Value", TextSprite("VIDA: " + std::to_string(pokemon->getVida())), 2, 14);
        *vida[1] = ObjetoDeJogo("Life Value", TextSprite("VIDA: " + std::to_string(adversario->getVida())), 2, 120);


        if (pokemon->getVida() <= 0)
        {
            return Fase::GAME_OVER;
        }

        if (adversario->getVida() <= 0)
        {
            return Fase::CAPTURA_POKEMON;
        }

        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    trilhaSonora->stop();
    return Fase::END_GAME; 
}

