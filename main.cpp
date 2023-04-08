#include <random>
#include <iostream>
#include <vector>
#include <ctime>

#include "Header/neurone.hpp"
#include "Header/reseau.hpp"

int main()
{
    std::srand(std::time(nullptr));

    Reseau cerv(4, 10, 100);
    std::vector<double> entree(100);
    for(int i=0; i<100; i++)
    {
        entree[i] = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX) * 2 - 1;
    }

    double sortie( cerv.calcul_sortie(entree) );
    std::cout<<"Resultat : "<<sortie<<std::endl;

    return 0;
}