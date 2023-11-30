#ifndef FASE1_HPP
#define FASE1_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include <list>
using std::list;

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Pokemon.hpp"
#include "Jogador.hpp"
#include "Mapa.hpp"

class Fase1 : public Fase
{
public:
    Fase1(string name, const Sprite &bkg) : Fase(name, bkg) {}
    Fase1(string name, const SpriteAnimado &bkg) : Fase(name, bkg) {}
    virtual ~Fase1() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    bool colideComBloco() const;

private:
    Mapa *mapa1;
    Jogador *jogador;
    Pokemon *pokemon;
    ObjetoDeJogo *cactos[2];

    list<ObjetoDeJogo *> colisoes;
};

#endif
