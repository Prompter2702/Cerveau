#include "../Header/generation.hpp"

Generation::Generation(int NbIndividu, int NbCouche, int NbParCouche, int NbEntree)
: m_nbIndividu(NbIndividu), m_nbCouche(NbCouche), m_nbParCouche(NbParCouche), m_nbEntree(NbEntree)
{
    m_reseaux.clear();
    for(int i=0; i<NbIndividu; i++)
    {
        m_reseaux.push_back( Reseau(NbCouche,NbParCouche,NbEntree) );
    }
}

void Generation::calcul_sorties(const std::vector<double> & entree)
{
    m_sortie.resize(m_nbIndividu);
    for(int i=0; i<m_nbIndividu ;i++)
    {
        m_sortie[i] = m_reseaux[i].calcul_sortie(entree);
    }
}


void Generation::calcul_scores(const std::vector< std::vector<double> > & listeEntrees, const std::vector<bool> reponses)
{
    int Nb_tests = listeEntrees.size();
    m_score.resize(m_nbIndividu);
    //Fill the score with zeroes
    std::fill(m_score.begin(), m_score.end(), 0);

    for(int i=0; i<Nb_tests; i++)
    {
        this->calcul_sorties( listeEntrees[i] );
        for(int j=0; j< m_nbIndividu ; j++)
        {
            bool s = (m_sortie[j]>0) ? true : false ;
            if(s==reponses[j]){
                m_score[j]++;
            }
        }
    }
}