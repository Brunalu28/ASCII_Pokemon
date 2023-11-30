#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Pokemon.hpp"

class Jogador : public ObjetoDeJogo
{
public:
    Jogador(const ObjetoDeJogo &obj, string nome) : ObjetoDeJogo(obj), nome(nome), qtdPokemon(0) {}
    virtual ~Jogador() {}

private:
    string nome;
    Pokemon *pokebola[4];
    int qtdPokemon;
};

#endif
