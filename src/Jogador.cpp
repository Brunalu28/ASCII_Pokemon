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
    // Verifica se há espaço na pokebola
    if (qtdPokemon < 4)
    {
        pokebola[qtdPokemon] = Pokemon;
        qtdPokemon++;
        return true;
    }

    // Não há espaço na pokebola
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

string Jogador::buscaPokemon(const string &tipo) const
{
    for (int i = 0; i < qtdPokemon; i++)
    {
        if (pokebola[i]->getTipo() == tipo)
        {
            return pokebola[i]->getTipo();
        }
    }
    return 0;
}
