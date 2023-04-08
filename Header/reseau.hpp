#ifndef RESEAU_HPP
#define RESEAU_HPP

#include "neurone.hpp"
#include <vector>

class Reseau
{
    public:
        Reseau(int NbCouche, int NbParCouche, int NbEntree);
        double calcul_sortie(std::vector<double> entree);

    private:
        int m_nbCouche;
        int m_nbParCouche;
        int m_nbEntrees;
        std::vector<Neurone> m_neurones;
};


void premiere_generation(std::vector<Reseau> &generation, int NbIndividu, int NbCouche, int NbParCouche, int NbEntree);
void calcul_sorties(const std::vector<Reseau> &generation, const std::vector<double> & entree, std::vector<double> & sortie );

#endif