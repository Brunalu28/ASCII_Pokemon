#include "Fase2.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"

#include <iostream>

void Fase2::init()
{
    objs.push_back(jogador);

    pontilhado = new ObjetoDeJogo("Pontilhado", Sprite("../rsc/pontilhado"), 12, 18);
    objs.push_back(pontilhado);
    colisoes.push_back(pontilhado);

    PokeCard = new ObjetoDeJogo("Card 3", Sprite("../rsc/infoSquirtle"), 43, 72);
    objs.push_back(PokeCard);
    colisoes.push_back(PokeCard);
    PokeCard->desativarObj();

    onda = new ObjetoDeJogo("Onda", Sprite("../rsc/onda"), 15, 119);
    objs.push_back(onda);
}

unsigned Fase2::run(SpriteBuffer &screen)
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
        if(jogador->colideCom(*pontilhado)){
            return Fase::FASE_3;
        }
        if (jogador->colideCom(*onda)) {
            PokeCard->ativarObj();
            getline(std::cin, batallhar);
            if(batallhar == "x"){
                return Fase::OP_SQUIRTLE;
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

bool Fase2::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
        if (jogador->colideCom(**it))
        {
            return true;
        }
    return false;
}