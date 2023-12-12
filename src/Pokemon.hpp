#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Pokemon : public ObjetoDeJogo
{
public:
    Pokemon(const ObjetoDeJogo &obj, int vida = 50, string tipo = "Pokemon") : ObjetoDeJogo(obj), vida(vida), tipo(tipo) {}
    // Pokemon(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){};
    virtual ~Pokemon() {};

    int getVida() const { return vida; }
    void sofrerAtaque(int ataque) { vida = (vida - ataque >= 0) ? (vida - ataque) : 0; }

private:
    string nome;
    string tipo;
    int vida;
    string ataques[4];
    int qtdAtaques;
};

#endif
