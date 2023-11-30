#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/Fase.hpp"
#include "Fase1.hpp"

class Game
{
public:
    Game() {}
    ~Game() {}

    static void run()
    {
        SpriteBuffer buffer(250, 57);
        Fase1 fase1("Fase 1", Sprite("rsc/mapa1.img"));

        fase1.init();
        int ret1 = fase1.run(buffer);
        if (ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME)
        {

            std::cout << "Testando..." << std::endl;
        }
        else
            std::cout << "GAME OVER" << std::endl;
    }
};
#endif
