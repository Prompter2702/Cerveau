#ifndef RESEAU_HPP
#define RESEAU_HPP

#include "neurone.hpp"
#include <vector>

class Reseau
{
    public:
        Reseau(int NbCouche, int NbParCouche, int NbEntree);
        double calcul_sortie(std::vector<double> entree);

        Reseau& operator !(); //Reproduction assexuée
        Reseau& operator %(const Reseau & res); //Reproduction sexuée

        //Accesseurs et modificateurs
        int get_tauxMutation() const;
        void set_tauxMutation(int);

        Neurone & operator[](int num_neur);
        Neurone operator()(int num_neur) const;

    private:
        int m_nbCouche;
        int m_nbParCouche;
        int m_nbEntrees;
        int m_tauxMutation; //Une chance sur ...
        std::vector<Neurone> m_neurones;
};

#endif