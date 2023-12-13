#include "Fase1.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"

#include <iostream>

void Fase1::init()
{
    objs.push_back(jogador);

    porta = new ObjetoDeJogo("Porta casa 1", Sprite("../rsc/portaMapa1.img"), 43, 149);
    objs.push_back(porta);
    colisoes.push_back(porta);

    flor = new ObjetoDeJogo("Flor", Sprite("../rsc/Flor1"), 11, 135);
    objs.push_back(flor);

    degrau = new ObjetoDeJogo("Degrau", Sprite("../rsc/degrau"), 15, 20);
    objs.push_back(degrau);

    PokeCards[0] = new ObjetoDeJogo("Card 1", Sprite("../rsc/infoBubassaur"), 43, 72);
    objs.push_back(PokeCards[0]);
    colisoes.push_back(PokeCards[0]);
    PokeCards[0]->desativarObj();

    PokeCards[1] = new ObjetoDeJogo("Card 2", Sprite("../rsc/infoCharmander"), 43, 72);
    objs.push_back(PokeCards[1]);
    colisoes.push_back(PokeCards[1]);
    PokeCards[1]->desativarObj();
    
}

unsigned Fase1::run(SpriteBuffer &screen)
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
        int posL = jogador->getPosL(), posC = jogador->getPosC();

        if (ent == "w" && jogador->getPosL() > 8)
            jogador->moveUp(3);
        else if (ent == "s" && jogador->getPosL() < screen.getAltura() - 12)
            jogador->moveDown(3);
        else if (ent == "a" && jogador->getPosC() > 12)
            jogador->moveLeft(3);
        else if (ent == "d" && jogador->getPosC() < screen.getLargura() - jogador->getSprite()->getLargura() - 12)
            jogador->moveRight(3);
        else if (ent == "q")
            return Fase::END_GAME;
        if (colideComBloco()){
            jogador->moveTo(posL, posC);
        }
        if (posL != jogador->getPosL() || posC != jogador->getPosC()) {
            if (jogador->colideCom(*flor)) {
                PokeCards[0]->ativarObj();
            } else {
                PokeCards[0]->desativarObj();
            }
        } 
        if (posL != jogador->getPosL() || posC != jogador->getPosC()) {
            if (jogador->colideCom(*degrau)) {
                PokeCards[1]->ativarObj();
            } else {
                PokeCards[1]->desativarObj();
            }
        }
        if(jogador->colideCom(*porta)){
            return FASE_2;
        }

        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME; 
}

bool Fase1::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
        if (jogador->colideCom(**it))
        {
            return true;
        }
    return false;
}