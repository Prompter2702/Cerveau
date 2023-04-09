#include <random>
#include <iostream>
#include <vector>
#include <ctime>

#include "Header/neurone.hpp"
#include "Header/reseau.hpp"
#include "Header/image.hpp"
#include "Header/generation.hpp"

int main()
{
    std::srand(std::time(nullptr));

    int NbImages = 50;
    //Reponses true si cercle false si carre 
    std::vector<bool> reponses(NbImages);
    std::vector< std::vector<double> > entrees(NbImages);
    for(int i=0; i<NbImages; i++)
    {
        reponses[i] = generate_image("Images/image" + std::to_string(i) + ".ppm");
        entrees[i] = read_ppm("Images/image" + std::to_string(i) + ".ppm");
    }

    //Initialisation génération :
    Generation gen(100, 2 , 2, 10000);

    double score_moyen = 0;
    int nb_iter = 0;
    int nb_MaxIter = 1000;
    while (score_moyen<0.8 && nb_iter<nb_MaxIter)
    {
        gen.calcul_scores(entrees, reponses);
        gen.selection();
        score_moyen = gen.get_score_moyen(NbImages);
        nb_iter++;
    }

    std::cout<<"Nombre itération : "<<nb_iter<<std::endl;
    std::cout<<"Score_moyen : "<<score_moyen<<std::endl;

    return 0;
}