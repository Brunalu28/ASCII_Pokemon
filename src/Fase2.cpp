#include "Fase2.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"
#include "Mapa.hpp"

#include <iostream>

void Fase2::init()
{
    objs.push_back(jogador);

    // cactos[0] = new ObjetoDeJogo("Cacto 1", Sprite("../rsc/cacto1.img"), 2, 10);
    // objs.push_back(cactos[0]);
    // colisoes.push_back(cactos[0]);

    // cactos[1] = new ObjetoDeJogo("Cacto 1", Sprite("../rsc/cacto1.img"), 5, 35);
    // objs.push_back(cactos[1]);
    // colisoes.push_back(cactos[1]);
}

unsigned Fase2::run(SpriteBuffer &screen)
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
        else if (ent == "a" && jogador->getPosC() > 5)
            jogador->moveLeft(3);
        else if (ent == "d" && jogador->getPosC() < screen.getLargura() - jogador->getSprite()->getLargura() - 5)
            jogador->moveRight(3);
        else if (ent == "q")
            return Fase::END_GAME;
        if (colideComBloco())
            jogador->moveTo(posL, posC);

        // padrão
        update();
        draw(screen);
        system("clear");
        show(screen);
    }

    return Fase::END_GAME; // não necessário
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