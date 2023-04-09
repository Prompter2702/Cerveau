#include <random>

#include "../Header/reseau.hpp"


Reseau::Reseau(int NbCouche, int NbParCouche, int NbEntree)
:m_nbCouche(NbCouche), m_nbParCouche(NbParCouche), m_nbEntrees(NbEntree)
{
    m_neurones.clear();
    for(int i=0; i<m_nbParCouche; i++)
    {
        m_neurones.push_back(Neurone(m_nbEntrees));
    }
    for(int j=1; j<m_nbCouche; j++)
    {
        for(int i=0; i<m_nbParCouche; i++)
        {
            m_neurones.push_back(Neurone(m_nbParCouche));
        }       
    }
}


double Reseau::calcul_sortie(std::vector<double> entree)
{
    std::vector<double> entree_bis;
    for(int num_couche=0; num_couche<m_nbCouche; num_couche++)
    {
        if(num_couche%2==0)
        {
            entree_bis.resize(m_nbParCouche);
            for(int num_neur=0; num_neur<m_nbParCouche; num_neur++)
            {
                entree_bis[num_neur] = m_neurones[num_couche*m_nbParCouche + num_neur].calcul_sortie(entree);
            }
        }else{
            entree.resize(m_nbParCouche);
            for(int num_neur=0; num_neur<m_nbParCouche; num_neur++)
            {
                entree[num_neur] = m_neurones[num_couche*m_nbParCouche + num_neur].calcul_sortie(entree_bis);
            }
        }
    }

    double res(0);
    if( (m_nbCouche-1)%2 == 0 )
    {
        for(int i=0; i<m_nbParCouche; i++)
        {
            res += entree_bis[i];
        }
    }else{
        for(int i=0; i<m_nbParCouche; i++)
        {
            res += entree[i];
        }
    }

    return res;
}

///////Accesseurs et modificateurs////////

int Reseau::get_tauxMutation() const
{
    return m_tauxMutation;
}

void Reseau::set_tauxMutation(int taux)
{
    m_tauxMutation = taux;
}

Neurone & Reseau::operator[](int num_neur)
{
    return m_neurones[num_neur];
}

Neurone Reseau::operator()(int num_neur) const
{
    return m_neurones[num_neur];
}

//////////SURCHARGE OPERATEURS///////////

Reseau& Reseau::operator !() //Reproduction assexuée
{
    for(int neur=0; neur<m_nbCouche*m_nbParCouche; neur++)
    {
        for(int synapse =0; synapse< m_neurones[neur].get_nbEntree(); synapse++)
        {
            int tirage = std::rand() % (m_tauxMutation + 1);
            if(tirage==0)
            {
                m_neurones[neur].retirage(synapse);
            }
        }
    }
    return *this;
}

Reseau& Reseau::operator %(const Reseau & res) //Reproduction sexuée
{
    //On mélange les neurones puis on fait une reproduction assexuée
    for(int neur=0; neur<m_nbCouche*m_nbParCouche; neur++)
    {
        int tirage = std::rand()%2;
        if(tirage==0) //On prend le neurone du nouveau
        {
            m_neurones[neur] = res(neur);
        }
    }

    !(*this);

    return *this;
}
