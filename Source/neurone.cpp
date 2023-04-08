#include "../Header/neurone.hpp"
#include <random>

Neurone::Neurone(int NbEntree)
: m_nbEntree(NbEntree)
{
    m_coeff.resize(m_nbEntree);
    for(int i=0; i<m_nbEntree; i++)
    {
        m_coeff[i] = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX) * 2 - 1;
    }
}

double Neurone::calcul_sortie(const std::vector<double> & entrees)
{
    double res(0);
    //Vérification des tailles ?
    for(int i=0; i<m_nbEntree; i++)
    {
        res += entrees[i]*m_coeff[i];
    }

    return res;
}