#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <map>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

#include "grman/grman.h"

/***************************************************
                    sommet
****************************************************/

class sommetInterface
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class sommet;
    friend class areteInterface;
    friend class Graph;


    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de déclarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le paramétrer ( voir l'implémentation du constructeur dans le .cpp )

        // La boite qui contient toute l'interface d'un sommet
        grman::WidgetBox m_top_box;

        // Un slider de visualisation/modification de la valeur du sommet
        grman::WidgetVSlider m_slider_value;

        // Un label de visualisation de la valeur du sommet
        grman::WidgetText m_label_value;

        // Une image de "remplissage"
        grman::WidgetImage m_img;

        // Un label indiquant l'index du sommet
        grman::WidgetText m_label_idx;

        // Une boite pour le label précédent
        grman::WidgetText m_box_label_idx;

    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        sommetInterface(int x, int y, std::string pic_name=""); /// mettre le nom
};


class sommet
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Graph;
    friend class sommetInterface;
    friend class arete;
    friend class areteInterface;
    friend class Graphe;

    private :

        /// un exemple de donnée associée à l'arc, on peut en ajouter d'autres...
        double m_value;

        /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<sommetInterface> m_interface = nullptr;

        std::string m_name;


    public:

        /// Les constructeurs sont à compléter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        sommet(std::string name,double value=0, sommetInterface *interface=nullptr) :
        m_name(name),m_value(value), m_interface(interface) {  }



        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }

        void pre_update();
        void post_update();
};



/***************************************************
                    arete
****************************************************/

class areteInterface
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class arete;
    friend class Graph;
    friend class Graphe;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de déclarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le paramétrer ( voir l'implémentation du constructeur dans le .cpp )

        // Le Widgetarete qui "contient" toute l'interface d'un arc
        grman::Widgetarete m_top_arete;

        // Une boite pour englober les widgets de réglage associés
        grman::WidgetBox m_box_arete;

        // Un slider de visualisation/modification du poids valeur de l'arc
        grman::WidgetVSlider m_slider_weight;

        // Un label de visualisation du poids de l'arc
        grman::WidgetText m_label_weight;

    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        areteInterface(sommet& dep, sommet& arr);
};


class arete
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Graph;
    friend class areteInterface;


    private :

        sommet* m_sommetD;

        sommet* m_sommetA;

        /// un exemple de donnée associée à l'arc, on peut en ajouter d'autres...
        double m_weight;

        /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<areteInterface> m_interface = nullptr;


    public:

        /// Les constructeurs sont à compléter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        arete();

        arete (sommet* somd, sommet* soma,double weight=0, areteInterface *interface=nullptr) :
                m_sommetD(somd), m_sommetA(soma),m_weight(weight), m_interface(interface)  { }

     /*   arete(sommet* somd, sommet* soma):
            m_sommetD(somd), m_sommetA(soma){}*/



        sommet* getsommetD(){return m_sommetD;}
        void setsommetD(sommet* val){m_sommetD = val;}

        sommet* getsommetA(){return m_sommetA;}
        void setsommetA(sommet* val){m_sommetA = val;}

        void affichageArete_csl();
        void pre_update();
        void post_update();
};




/***************************************************
                    GRAPH
****************************************************/

class GraphInterface
{
    friend class Graph;
    friend class Graphe;

    private :

        /// La boite qui contient toute l'interface d'un graphe
        grman::WidgetBox m_top_box;

        /// Dans cette boite seront ajoutés les (interfaces des) sommets et des arcs...
        grman::WidgetBox m_main_box;

        /// Dans cette boite seront ajoutés des boutons de contrôle etc...
        grman::WidgetBox m_tool_box;

        // A compléter éventuellement par des widgets de décoration ou
        // d'édition (boutons ajouter/enlever ...)

    public :
        GraphInterface(int x, int y, int w, int h);
};


class Graph
{

    private :
        /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<GraphInterface> m_interface = nullptr;
        int m_nbSommet;
        int** m_matAdjacente;
        std::vector<sommet*> m_vecsommet;
        std::vector<arete*> m_vecarete;
        std::string m_nomFichier;

    public:

        /// Les constructeurs sont à compléter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        Graph (std::string nomFichier,GraphInterface *interface=nullptr) :
               m_nomFichier(nomFichier),m_interface(interface),m_nbSommet(0), m_matAdjacente(NULL)  {  }

        virtual ~Graph();

    ///Getter, Setter
        std::vector<sommet*> Getvecsommet() { return m_vecsommet; }
        void SetvecSommet(std::vector<sommet*> val) { m_vecsommet = val; }

        std::vector<arete*> Getvecarete() { return m_vecarete; }
        void Setvecarete(std::vector<arete*> val) { m_vecarete = val; }

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
        void ajouterSommet(std::string nomsommet);
        void afficherMatriceAdjacente();
        void affichageRelation();

        void creationArete(int dep, int arr, double weight);
        void creationAretes();
        ///coucou
        void make_example();
        /// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
        void update();

};


#endif // GRAPH_H_INCLUDED
