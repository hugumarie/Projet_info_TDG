#include <iostream>

#include "fonctiongraph.h"
#include "Graphe.h"

int main()
{

    /*std::string name;

    std::cout << "Veillez rentrez le nom du fichier : ";
    std::cin >> name;

    Graphe g1(name);



    if((&g1)->recuperationInformation()){
        (&g1)->afficherMatriceAdjacente();
        (&g1)->creationAretes();
        (&g1)->affichageRelation();
    }*/

     /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("images");

    /// Un exemple de graphe
    Graph g;
    g.make_example();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();



    return 0;
}
