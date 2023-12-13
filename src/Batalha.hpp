#ifndef BATALHA_HPP
#define BATALHA_HPP

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

class Batalha : public Fase
{
public:
    Batalha(string name, const Sprite &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    Batalha(string name, const SpriteAnimado &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    virtual ~Batalha() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    bool colideComBloco() const;

private:
    Jogador *const jogador;
    Pokemon *pokemon;
    Pokemon *adversario;
    ObjetoDeJogo *ataques[2];
};

#endif
