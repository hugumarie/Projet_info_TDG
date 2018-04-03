#include <iostream>
#include <string>
#include <fstream>
#include "fichiers.h"
#include <allegro.h>
#include <vector>

using namespace std;



void lecture_fichier_chaine(std::string nom_fichier)
{
        int sommet;
        std::string nom_image;
        int population;
        std::string nom_animal;
        int ordre;
        std::vector<BITMAP*> vecteur_image;


        ifstream fichier(nom_fichier.c_str(), ios::in);

        if(fichier)
        {
            fichier >> ordre;
            for(int i=0; i<ordre; i++)
            {
                // lecture du fichier
                fichier >> nom_animal >> sommet >> population;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */
                nom_image= nom_animal+ ".bmp";

                // attribution des photos a son animal
                vecteur_image[i]= load_bitmap(nom_image.c_str(), NULL);



            }

        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;



}
