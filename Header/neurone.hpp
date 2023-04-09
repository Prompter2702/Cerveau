#ifndef NEURONE_HPP
#define NEURONE_HPP

#include <vector>

class Neurone
{
    public:
        Neurone(int NbEntree);
        double calcul_sortie(const std::vector<double> & entrees);

        //Accesseurs et modificateurs
        int get_nbEntree() const;
        void set_nbEntree(int);

        //Surcharge operateurs
        double & operator[] (int num_coeff);
        double operator()(int num_coeff) const;
        Neurone & operator=(const Neurone& neur);

        void retirage(int num_coeff);

    private:
        int m_nbEntree;
        std::vector<double> m_coeff;

};

#endif