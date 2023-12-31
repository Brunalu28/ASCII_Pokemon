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
    Jogador(const ObjetoDeJogo &obj, string nome);
    virtual ~Jogador();

    const string getNome() const { return this->nome; }
    void setNome(const string& novoNome) { this->nome = novoNome; }

    int getQtdPokemon() const { return this->qtdPokemon; }
    void setQtdPokemon(int qtdPokemon) { this->qtdPokemon = qtdPokemon; }

    bool adicionaPokemon(Pokemon *novoPokemon);
    bool removePokemon(const string &nome);
    Pokemon* buscaPokemon() const;


private:
    string nome;
    Pokemon *pokebola[4];
    int qtdPokemon;
};

#endif
