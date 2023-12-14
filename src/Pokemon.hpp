#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include <array>
using std::array;

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Pokemon : public ObjetoDeJogo
{
public:
    enum Tipo { FOGO, AGUA, GRAMA, ELETRICO };
    Pokemon(const ObjetoDeJogo &obj, int vida = 50, Tipo tipo = FOGO) : ObjetoDeJogo(obj), vida(vida), tipo(tipo) {}
    virtual ~Pokemon() {};

    string getNome() const { return this->getName(); }
    int getVida() const { return vida; }
    Tipo getTipo() const { return tipo; }

    static const std::array<int, 4> ataquesFogo;
    static const std::array<int, 4> ataquesAgua;
    static const std::array<int, 4> ataquesGrama;
    static const std::array<int, 4> ataquesEletrico;

    void sofrerAtaque(int ataque) { vida = (vida - ataque >= 0) ? (vida - ataque) : 0; }
    void atacar(int ataque, Pokemon *adversario);

private:
    string nome;
    Tipo tipo;
    int vida;
    string ataques[4];
    int qtdAtaques;
};

#endif
