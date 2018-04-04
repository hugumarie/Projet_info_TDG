#include <iostream>

#include "fonctiongraph.h"
#include "Graphe.h"

int main()
{

    std::string name;

    std::cout << "Veillez rentrez le nom du fichier : ";
    std::cin >> name;

    Graphe g1(name);



    if((&g1)->recuperationInformation()){
        (&g1)->afficherMatriceAdjacente();
        (&g1)->creationAretes();
        (&g1)->affichageRelation();
    }

    return 0;
}
END_OF_MAIN();
