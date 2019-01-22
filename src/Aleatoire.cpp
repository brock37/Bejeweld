#include "Aleatoire.h"

Aleatoire::Aleatoire()
{
    srand (time(NULL));
}

Aleatoire::~Aleatoire()
{
    //dtor
}

int  Aleatoire::aleatoire(int mini, int maxi)
{
    int res=0;
    res= rand() % maxi + mini;
    return res;
}
