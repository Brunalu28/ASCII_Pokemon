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
    Batalha(string name, const Sprite &bkg, Jogador *const jogador, Pokemon *const pokemon, Pokemon *const adversario) : Fase(name, bkg), jogador(jogador), pokemon(pokemon), adversario(adversario) {}
    Batalha(string name, const SpriteAnimado &bkg, Jogador *const jogador, Pokemon *const pokemon, Pokemon *const adversario) : Fase(name, bkg), jogador(jogador), pokemon(pokemon), adversario(adversario) {}
    virtual ~Batalha() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    bool colideComBloco() const;

private:
    Jogador *const jogador;
    Pokemon *pokemon;
    Pokemon *adversario;
    ObjetoDeJogo *ataques[4];
};

#endif
