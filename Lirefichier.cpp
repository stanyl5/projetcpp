#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

std :: vector<std :: vector<std ::vector<int>>> lirefichier ()
{
   std :: ifstream monfichier ("m1projetcpp2.ppm"); // Ouverture du fichier
    
   if (monfichier) // On s'assure que le fichier est bien ouvert
   {
        int compteur=0; // Le compteur ne tient pas compte des commentaires, et permet d'évoluer dans le code au rythme prédéfini.
        std :: vector<int> resolution = {0,0};

        std :: string ligne; 
        while(getline(monfichier, ligne)) 
            {
                if (ligne[0] != '#')  // On ignore les commentaire du fichier ppm
                {
                    if (compteur == 0)
                    {
                        // Récupération du numéro de variante
                        std :: string qualite ; 
                        qualite = ligne; 

                    }
                    else
                    {
                        if (compteur == 1)
                        {           
                            // Récupération de format de l'image :
                            // Resolution[0] = largeur,
                            // Resolution[1] = hauteur  

                            std::string parseNum;
                            std::stringstream streamLigne(ligne);
                            int res=0;
                            while(std::getline(streamLigne,parseNum,' '))
                            {
                                resolution[res] = std::stoi(parseNum);
                                res++;
                            } 
                        }
                    else
                    {
                        if (compteur==2)
                        {
                            // Récupération de la valeur maximale
                            int valmax = std :: stoi(ligne);
                        }
                        else  // Si le compteur vaut 3
                        {  
                            // On initialise une matrice 3D avec la valeur 0
                            std :: vector<int>  vecteur  (3,0);
                            std :: vector<std :: vector<int> > intermediaire (resolution[1], vecteur)  ;
                            std :: vector<std :: vector< std:: vector<int>>> image (resolution[0],intermediaire) ;

                            // On boucle sur la largeur de l'image, sa hauteur, et pour chaque composante de la couleur    
                            for (int i = 0;i<resolution[0];i++)
                            { 
                                for (int j =0; j< resolution[1]; j++)
                                {
                                    for (int k=0; k<3;k++) 
                                    {
                                        // On affecte la valeur récupérée dans l'image
                                        image[i][j][k] = stoi (ligne);  // Cette ligne est en premier, car la première valeur a été récupérée dans la condition du while
                                        getline(monfichier,ligne); 
                                    }
                                }

                            }
                            return image; // On retourne l'image sous forme de matrice
                        }
                    }
                }
                compteur ++;

            }

        }
    }
    // On retourne une image vide, en 3D, quand le fichier ne s'est pas lu ou dans le cas d'une quelconque erreur
    std :: cout << "Attention, il y a eu une erreur." 
    std :: vector<int>  vecteur  (0,0);
    std :: vector<std :: vector<int> > intermediaire (0, vecteur)  ;
    std :: vector<std :: vector< std:: vector<int>>> image (0,intermediaire) ;
    return image ; 
}


int main ()
{
    lirefichier();
    return 0;
}