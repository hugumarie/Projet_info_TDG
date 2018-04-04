#include "Graphe.h"


///Constructeur, Destructeur
Graphe::Graphe() : m_nbSommet(0), m_matAdjacente(NULL)
{
    //ctor
}

Graphe::Graphe(std::string nomFichier):  m_nbSommet(0), m_matAdjacente(NULL), m_nomFichier(nomFichier)
{
    //Lancer initialisation
}

Graphe::~Graphe()
{
    if(m_matAdjacente != NULL){
        liberationMatriceAdjacent();
    }

    for(auto temp : m_vecSommet){
        delete temp;
    }

    for(auto temp : m_vecArete){
        delete temp;
    }
}


///Methodes

bool Graphe::allocationMatriceAdjacent(){

    if(m_nbSommet == 0){
        return printMessageErreur("Le nombre de sommet est 0 lors de l allocation de la matrice\n\tPas chargement donnee / Mauvaise donnee");
    }

    m_matAdjacente = new int*[m_nbSommet];
    for(int i = 0; i < m_nbSommet; i++){
        m_matAdjacente[i] = new int[m_nbSommet];
    }

return true;
}

bool Graphe::liberationMatriceAdjacent(){

    if(m_matAdjacente == NULL){
        return printMessageErreur("Pas de matrice a liberer");
    }

    for(int i = 0; i < m_nbSommet; i++){
        delete m_matAdjacente[i];
    }
    delete m_matAdjacente;

    return true;
}

void Graphe::ajouterSommet(std::string nomSommet){
    m_vecSommet.push_back(new Sommet(nomSommet));
}

bool Graphe::recuperationInformation(){

    if(m_nomFichier == "")
        {
        return printMessageErreur("Pas de nom de fichier a charger");
    }

    std::ifstream fichierEntreprise(m_nomFichier, std::ios::in);

   // if(fichierEntreprise== NULL){
     //   return printMessageErreur("Le fichier de sauvegarde ne correspond pas au nom donnee ou n existe pas");
    //}

    try{
        fichierEntreprise >> m_nbSommet;

        //Si echec allocation matrice
        if(!allocationMatriceAdjacent()){
            return false;
        }

        std::string nomTempo;

        for(int i = 0; i < m_nbSommet; i++)
            {
            fichierEntreprise >> nomTempo;
            ajouterSommet(nomTempo);
            }

        for(int i = 0 ; i < m_nbSommet; i ++){
            for(int j = 0; j < m_nbSommet; j ++){
                fichierEntreprise >> m_matAdjacente[i][j];

            }
        }

    }
    catch(...){
        fichierEntreprise.close();
        return printMessageErreur("Le format du fichier ne correspond pas au mode de lecture du code");
    }

    fichierEntreprise.close();

    return true;

 }

void Graphe::afficherMatriceAdjacente(){

    std::cout << "Voici le tableau de la matrice adjacente\n\n";

    for(int i = 0 ; i < m_nbSommet; i ++){
        std::cout << m_vecSommet[i]->Getname() << " ";
        for(int j = 0; j < m_nbSommet; j ++){
            std::cout << m_matAdjacente[i][j] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

void Graphe::affichageRelation(){

    std::cout << "Voici toutes les relations dans le graphe : \n\n";

    for(const auto quentin : m_vecArete){
        std::cout << "\t";
        quentin->affichageArete();
    }

    std::cout << "\n\nFin\n\n";
}

void Graphe::creationArete(int x, int y){
    m_vecArete.push_back(new Arete(m_vecSommet[x], m_vecSommet[y]));
}

void Graphe::creationAretes(){

    for(int i = 0; i < m_nbSommet; i++){
        for(int j = 0 ; j < m_nbSommet; j++){
            if(m_matAdjacente[i][j] == 1){
                creationArete(i,j);
            }
        }
    }

    std::cout << "\nToutes les aretes ont ete cree\n\n";
}


