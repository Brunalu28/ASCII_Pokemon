#ifndef FASE2_HPP
#define FASE2_HPP

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

class Fase2 : public Fase
{
public:
    Fase2(string name, const Sprite &bkg, SpriteBuffer &screen, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    Fase2(string name, const SpriteAnimado &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    virtual ~Fase2() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

    // cactos[0] = new ObjetoDeJogo("Cacto 1", Sprite("../rsc/cacto1.img"), 2, 10);
    // objs.push_back(cactos[0]);
    // colisoes.push_back(cactos[0]);

    // cactos[1] = new ObjetoDeJogo("Cacto 1", Sprite("../rsc/cacto1.img"), 5, 35);
    // objs.push_back(cactos[1]);
    // colisoes.push_back(cactos[1]);

    bool colideComBloco() const;

private:
    Jogador *const jogador;
    Mapa *mapa1;

    list<ObjetoDeJogo *> colisoes;
};

#endif
