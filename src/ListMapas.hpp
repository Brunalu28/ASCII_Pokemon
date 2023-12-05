#ifndef LISTMAPAS_HPP
#define LISTMAPAS_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Fase.hpp"
#include "Mapa.hpp"

class ListMapas : public Fase
{
public:
    ListMapas(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){}
    virtual ~ListMapas() {}

    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    Mapa *mapas[4];
};

#endif
