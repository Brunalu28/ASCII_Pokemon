#include "Pokemon.hpp"

const array<int, 4> Pokemon::ataquesFogo = {10, 8, 5, 12};  
const array<int, 4> Pokemon::ataquesAgua = {9, 7, 6, 11};
const array<int, 4> Pokemon::ataquesGrama = {8, 6, 7, 10};
const array<int, 4> Pokemon::ataquesEletrico = {11, 9, 5, 7};

void Pokemon::atacar(int indiceAtaque, Pokemon *adversario)
{
    const array<int, 4> *ataquesTipo;

    switch (tipo)
    {
    case FOGO:
        ataquesTipo = &ataquesFogo;
        break;
    case AGUA:
        ataquesTipo = &ataquesAgua;
        break;
    case GRAMA:
        ataquesTipo = &ataquesGrama;
        break;
    case ELETRICO:
        ataquesTipo = &ataquesEletrico;
        break;
    }

    if (indiceAtaque >= 0 && indiceAtaque < ataquesTipo->size())
    {
        int dano = (*ataquesTipo)[indiceAtaque];
        adversario->sofrerAtaque(dano);
    }
    
}