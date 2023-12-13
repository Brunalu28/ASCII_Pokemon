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
    Fase1(string name, const Sprite &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    Fase1(string name, const SpriteAnimado &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    virtual ~Fase1() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    bool colideComBloco() const;

private:
    Jogador *const jogador;
    ObjetoDeJogo *porta;
    ObjetoDeJogo *PokeCards[2];
    ObjetoDeJogo *flor;
    ObjetoDeJogo *degrau;

    list<ObjetoDeJogo *> colisoes;
};

#endif
