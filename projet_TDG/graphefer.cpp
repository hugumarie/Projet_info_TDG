#include "graphefer.h"
#include "fonctiongraph.h"


Graph::~Graph()
{
    if(m_matAdjacente != NULL){
        liberationMatriceAdjacent();
    }

    for(auto temp : m_vecsommet){
        delete temp;
    }

    for(auto temp : m_vecarete){
        delete temp;
    }
}


///Methodes
bool Graph::allocationMatriceAdjacent(){

    if(m_nbSommet == 0){
        return printMessageErreur("Le nombre de sommet est 0 lors de l allocation de la matrice\n\tPas chargement donnee / Mauvaise donnee");
    }

    m_matAdjacente = new int*[m_nbSommet];
    for(int i = 0; i < m_nbSommet; i++){
        m_matAdjacente[i] = new int[m_nbSommet];
    }

    return true;
}

bool Graph::liberationMatriceAdjacent(){

    if(m_matAdjacente == NULL){
        return printMessageErreur("Pas de matrice a liberer");
    }

    for(int i = 0; i < m_nbSommet; i++){
        delete m_matAdjacente[i];
    }
    delete m_matAdjacente;

    return true;
}

void Graph::ajouterSommet(std::string nomSommet){
    m_vecsommet.push_back(new sommet(nomSommet));
}

bool Graph::recuperationInformation(){

    if(m_nomFichier == "")
        {
        return printMessageErreur("Pas de nom de fichier a charger");
    }

    std::ifstream fichier(m_nomFichier, std::ios::in);

   /* if(fichierEntreprise== NULL){
        return printMessageErreur("Le fichier de sauvegarde ne correspond pas au nom donnee ou n existe pas");
    }*/

    try{
        fichier >> m_nbSommet;

        //Si echec allocation matrice
        if(!allocationMatriceAdjacent()){
            return false;
        }

        std::string nomTempo;

        for(int i = 0; i < m_nbSommet; i++)
            {
            fichier >> nomTempo;
            ajouterSommet(nomTempo);
            }

        for(int i = 0 ; i < m_nbSommet; i ++){
            for(int j = 0; j < m_nbSommet; j ++){
                fichier >> m_matAdjacente[i][j];

            }
        }

    }
    catch(...){
        fichier.close();
        return printMessageErreur("Le format du fichier ne correspond pas au mode de lecture du code");
    }

    fichier.close();

    return true;

 }

void Graph::afficherMatriceAdjacente(){

    std::cout << "Voici le tableau de la matrice adjacente\n\n";

    for(int i = 0 ; i < m_nbSommet; i ++){
        std::cout << m_vecsommet[i]->Getname() << " ";
        for(int j = 0; j < m_nbSommet; j ++){
            std::cout << m_matAdjacente[i][j] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

void arete::affichageArete_csl()
{

    std::cout << m_sommetD->Getname() << " influe sur " << m_sommetA->Getname() << "\n";
}


void Graph::affichageRelation(){

    std::cout << "Voici toutes les relations dans le Graph : \n\n";

    for(const auto quentin : m_vecarete){
        std::cout << "\t";
        quentin->affichageArete_csl();
    }

    std::cout << "\n\nFin\n\n";
}

void Graph::creationArete(int dep, int arr, double weight)
{
    m_vecarete.push_back(new arete(m_vecsommet[dep], m_vecsommet[arr],weight));
}

void Graph::creationAretes(){

    for(int i = 0; i < m_nbSommet; i++){
        for(int j = 0 ; j < m_nbSommet; j++){
            if(m_matAdjacente[i][j] == 1){
                creationArete(i,j,0);
            }
        }
    }

    std::cout << "\nToutes les aretes ont ete cree\n\n";
}
