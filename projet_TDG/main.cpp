#include <iostream>
#include "graphefer.h"
#include "fonctiongraph.h"

#include "grman/grman.h"


int main()
{

     /*std::string name;

   std::cout << "Veillez rentrez le nom du fichier : ";
    std::cin >> name;*/

    Graph g1("matrice_chaine_afrique.txt");

    Graph g2("matrice_chaine_afrique.txt");

    if((&g1)->recuperationInformation())
    {
        (&g1)->afficherMatriceAdjacente();
        (&g1)->creationAretes();
        (&g1)->affichageRelation();
    }

     /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("images");

    /// Un exemple de graphe
    /*Graph g;

    g.make_example();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }*/

    grman::fermer_allegro();



    return 0;
}
END_OF_MAIN();
