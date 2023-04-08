#ifndef GENERATION_HPP
#define GENERATION_HPP

#include <vector>
#include "reseau.hpp"


class Generation
{
    public :
        Generation(int NbIndividu, int NbCouche, int NbParCouche, int NbEntree);
        void calcul_sorties(const std::vector<double> & entree);
        void calcul_scores(const std::vector< std::vector<double> > & listeEntrees, const std::vector<bool> reponses);

    private :
        int m_nbIndividu;
        int m_nbCouche;
        int m_nbParCouche;
        int m_nbEntree;

        std::vector<Reseau> m_reseaux;
        std::vector<double> m_sortie;
        std::vector<int> m_score;
};


#endif