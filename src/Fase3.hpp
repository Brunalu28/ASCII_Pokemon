#ifndef FASE3_HPP
#define FASE3_HPP

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

class Fase3 : public Fase
{
public:
    Fase3(string name, const Sprite &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    Fase3(string name, const SpriteAnimado &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    virtual ~Fase3() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    bool colideComBloco() const;

private:
    Jogador *const jogador;
    ObjetoDeJogo *banco;
    ObjetoDeJogo *PokeCard;


    list<ObjetoDeJogo *> colisoes;
};

#endif
