#include "Fase1.hpp"

#include "Pokemon.hpp"
#include "Jogador.hpp"
#include "Mapa.hpp"

#include <iostream>

void Fase1::init()
{
    jogador = new Jogador(ObjetoDeJogo("Jogador", SpriteAnimado("../rsc/Personagem.anm", 2), 20, 20), "Ash");
    objs.push_back(jogador);

    cactos[0] = new ObjetoDeJogo("Cacto 1", Sprite("../rsc/cacto1.img"), 2, 10);
    objs.push_back(cactos[0]);
    colisoes.push_back(cactos[0]);

    cactos[1] = new ObjetoDeJogo("Cacto 1", Sprite("../rsc/cacto1.img"), 5, 35);
    objs.push_back(cactos[1]);
    colisoes.push_back(cactos[1]);
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

        if (ent == "w" && jogador->getPosL() > 10)
            jogador->moveUp(3);
        else if (ent == "s" && jogador->getPosL() < screen.getAltura() - 15)
            jogador->moveDown(3);
        else if (ent == "a" && jogador->getPosC() > 12)
            jogador->moveLeft(3);
        else if (ent == "d" && jogador->getPosC() < screen.getLargura() - jogador->getSprite()->getLargura() - 13)
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

bool Fase1::colideComBloco() const
{
    for (auto it = colisoes.begin(); it != colisoes.end(); ++it)
        if (jogador->colideCom(**it))
        {
            return true;
        }
    // if (jogador->colideCom(*porta) && !porta->isOpen())
    //     return true;

    return false;
}