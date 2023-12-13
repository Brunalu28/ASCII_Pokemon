#include "Jogador.hpp"

Jogador::Jogador(const ObjetoDeJogo &obj, string nome) : ObjetoDeJogo(obj), nome(nome), qtdPokemon(0)
{
    for (int i = 0; i < 4; i++)
    {
        pokebola[i] = nullptr;
    }
}

Jogador::~Jogador()
{
    for (int i = 0; i < qtdPokemon; i++)
    {
        delete pokebola[i];
    }
}

bool Jogador::adicionaPokemon(Pokemon *Pokemon)
{
    if (qtdPokemon < 4)
    {
        pokebola[qtdPokemon] = Pokemon;
        qtdPokemon++;
        return true;
    }
    return false;
}

bool Jogador::removePokemon(const string &tipo)
{
    for (int i = 0; i < qtdPokemon; i++)
    {
        if (pokebola[i]->getTipo() == tipo)
        {
            delete pokebola[i];

            for (int j = i; j < qtdPokemon - 1; j++)
            {
                pokebola[j] = pokebola[j + 1];
            }

            qtdPokemon--;
            return true;
        }
    }
    return false;
}
Pokemon* Jogador::buscaPokemon() const
{
    for (int i = qtdPokemon - 1; i >= 0; --i)
    {
        if (pokebola[i] != nullptr)
        {
            return pokebola[i];
        }
    }

    return nullptr;  
}
