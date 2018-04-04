#ifndef GRAPHE_H
#define GRAPHE_H

#include "fonctiongraph.h"

#include "Arete.h"
#include "Sommet.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "graphefer.h"

class Graphe
{
    private:
        int m_nbSommet;
        int** m_matAdjacente;
        std::vector<Sommet*> m_vecSommet;
        std::vector<Arete*> m_vecArete;
        std::string m_nomFichier;

    public:

    ///Constructeur, destructeur
        Graphe();
        Graphe(std::string nomFichier);
        virtual ~Graphe();

    ///Getter, Setter
        std::vector<Sommet*> GetvecSommet() { return m_vecSommet; }
        void SetvecSommet(std::vector<Sommet*> val) { m_vecSommet = val; }

        std::vector<Arete*> GetvecArete() { return m_vecArete; }
        void SetvecArete(std::vector<Arete*> val) { m_vecArete = val; }

        int** GetmatAdjacente() { return m_matAdjacente; }
        void SetmatAdjacente(int** val) { m_matAdjacente = val; }

        int GetNbSommet() {return m_nbSommet;}
        void SetNbSommet(int val) {m_nbSommet = val;}

        std::string GetNomFichier() {return m_nomFichier;}
        void SetNomFichier(std::string val) {m_nomFichier = val;}

    ///Methodes
        bool allocationMatriceAdjacent();
        bool liberationMatriceAdjacent();
        bool recuperationInformation();

        void ajouterSommet(std::string nomSommet);

        void afficherMatriceAdjacente();

        void affichageRelation();

        void creationArete(int x, int y);

        void creationAretes();
};

#endif // GRAPHE_H
