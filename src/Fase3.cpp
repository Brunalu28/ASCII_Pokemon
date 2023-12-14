#include "Fase3.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"
#include "Mapa.hpp"

#include <iostream>

void Fase3::init()
{
    objs.push_back(jogador);

    PokeCard = new ObjetoDeJogo("Card 3", Sprite("../rsc/infoPikachu"), 43, 72);
    objs.push_back(PokeCard);
    colisoes.push_back(PokeCard);
    PokeCard->desativarObj();

    banco = new ObjetoDeJogo("Banco", Sprite("../rsc/banco"), 43, 161);
    objs.push_back(banco);
    
}

unsigned Fase3::run(SpriteBuffer &screen)
{
    std::string ent, batallhar;

    // padrão
    draw(screen);
    system("clear");
    show(screen);

    while (true)
    {
        // lendo entrada
        getline(std::cin, ent);

        // processando entradas
        int posL = jogador->getPosL(), posC = jogador->getPosC();

        if (ent == "w" && jogador->getPosL() > 8)
            jogador->moveUp(5);
        else if (ent == "s" && jogador->getPosL() < screen.getAltura() - 8)
            jogador->moveDown(5);
        else if (ent == "a" && jogador->getPosC() > 5)
            jogador->moveLeft(5);
        else if (ent == "d" && jogador->getPosC() < screen.getLargura() - jogador->getSprite()->getLargura() - 5)
            jogador->moveRight(5);
        else if (ent == "q")
            return Fase::END_GAME;
        if (jogador->colideCom(*banco)) {
            PokeCard->ativarObj();
            getline(std::cin, batallhar);
            if(batallhar == "x"){
                return Fase::OP_PIKACHU;
            }
        } else {
            PokeCard->desativarObj();
        }

        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME;
}

bool Fase3::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
        if (jogador->colideCom(**it))
        {
            return true;
        }
    return false;
}