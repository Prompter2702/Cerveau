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
            if(s==reponses[i]){
                m_score[j]++;
            }
        }
    }
}

void Generation::selection()
{
    std::vector<int> indices(m_nbIndividu);
    for(int i=0; i<m_nbIndividu; i++)
    {
        indices[i] = i;
    }
    // create a vector of pairs from the two input vectors
    std::vector<std::pair<int, double>> pairs;
    for (int i = 0; i < indices.size(); i++) {
        pairs.push_back( std::make_pair(indices[i], m_score[i]) );
    }
    // sort the vector of pairs using the custom comparator
    std::sort(pairs.begin(), pairs.end(), comparator);

    //REPRODUCTION :
    std::vector<Reseau> nv_gen;
    //Il faut que le nombre d'individu soit divisible par 20
    for(int tranche = 0; tranche<5; tranche ++)
    {
        int taille_tranche(m_nbIndividu/20);
        for(int ind = 2*tranche*taille_tranche; ind<(2*tranche+1)*taille_tranche; ind++)
        {
            for(int enf = 0; enf<6-tranche; enf++)
            {
                nv_gen.push_back(m_reseaux[ pairs[ind].first ]%m_reseaux[ pairs[ind + taille_tranche].first ]);
            }
        }
    }
}

double Generation::get_score_moyen(int nbtests)
{
    double res = 0.0;
    for(int i=0; i<m_nbIndividu; i++){
        res += m_score[i];
    }

    return res/( (double) m_nbIndividu*nbtests);
}

bool comparator(const std::pair<int, double>& a, const std::pair<int, double>& b)
{
    return a.second < b.second; // sort by value in descending order
}
