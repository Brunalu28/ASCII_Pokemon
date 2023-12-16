#ifndef START_HPP
#define START_HPP

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

class Start : public Fase
{
public:
    Start(string name, const Sprite &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    Start(string name, const SpriteAnimado &bkg, Jogador *const jogador) : Fase(name, bkg), jogador(jogador) {}
    virtual ~Start() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    Jogador *jogador;
    ObjetoDeJogo *tituloCover;
    ObjetoDeJogo *instrucoes;
    Sound *trilhaSonora;

};

#endif
