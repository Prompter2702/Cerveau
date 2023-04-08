#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <vector>

class Neurone
{
    public:
        Neurone(int NbEntree);
        double calcul_sortie(const std::vector<double> & entrees);

    private:
        int m_nbEntree;
        std::vector<double> m_coeff;

};

#endif