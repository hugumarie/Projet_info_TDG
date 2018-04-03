#ifndef ARETE_H
#define ARETE_H

#include "Sommet.h"

class Arete
{
    private:


        //Sommet de departd
        Sommet* m_sommetD;
        //Sommet d arriver
        Sommet* m_sommetA;

    public:

        Arete();
        Arete(Sommet* somd, Sommet* soma);

        virtual ~Arete();

        Sommet* getSommetD(){return m_sommetD;}
        void setSommetD(Sommet* val){m_sommetD = val;}

        Sommet* getSommetA(){return m_sommetA;}
        void setSommetA(Sommet* val){m_sommetA = val;}

        void affichageArete();

};

#endif // ARETE_H
