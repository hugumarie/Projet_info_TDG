#include "Arete.h"

Arete::Arete()
{
    //ctor
}

Arete::Arete(Sommet* somd, Sommet* soma): m_sommetD(somd), m_sommetA(soma)
{

}

Arete::~Arete()
{
    //dtor
}

void Arete::affichageArete(){

    std::cout << m_sommetD->Getname() << " influe sur " << m_sommetA->Getname() << "\n";
}
