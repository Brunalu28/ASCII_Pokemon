#ifndef HERO_HPP
#define HERO_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Mapa : public ObjetoDeJogo
{
public:
    Mapa(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj) {}
    virtual ~Mapa() {}

private:
    string nome;
    string tipo;
};

#endif
