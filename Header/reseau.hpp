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

#endif