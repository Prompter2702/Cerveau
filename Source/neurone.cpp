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




//////////Accesseurs et modificateurs////////////

int Neurone::get_nbEntree() const
{
    return m_nbEntree;
}

void Neurone::set_nbEntree(int nb)
{
    m_nbEntree = nb;
}

void Neurone::retirage(int num_coeff)
{
    m_coeff[num_coeff] = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX) * 2 - 1;
}


///////Surcharge operateurs////////////////

double & Neurone::operator[] (int num_coeff)
{
    return m_coeff[num_coeff];
}

double Neurone::operator() (int num_coeff) const
{
    return m_coeff[num_coeff];
}

Neurone & Neurone::operator=(const Neurone& neur)
{
    m_nbEntree = neur.get_nbEntree();
    for(int i=0; i<m_nbEntree; i++)
    {
        m_coeff[i] = neur(i);
    }
    return *this;
}
