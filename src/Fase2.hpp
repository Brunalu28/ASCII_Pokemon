#ifndef FASE2_HPP
#define FASE2_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include <list>
using std::list;

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/Sound.hpp"
#include <string>
#include <list>

#include "Pokemon.hpp"
#include "Jogador.hpp"

class Fase2 : public Fase
{
public:
    Fase2(string name, const Sprite &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    Fase2(string name, const SpriteAnimado &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    virtual ~Fase2() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    bool colideComBloco() const;

private:
    Jogador *const jogador;
    ObjetoDeJogo *pontilhado;
    ObjetoDeJogo *onda;
    ObjetoDeJogo *PokeCard;

    list<ObjetoDeJogo *> colisoes;
};

#endif
