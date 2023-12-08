#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Mapa : public ObjetoDeJogo
{
public:
    Mapa(string nome, const ObjetoDeJogo &obj) : ObjetoDeJogo(obj) {}
    virtual ~Mapa() {}

private:
    string nome;
    string tipo;
};

#endif
