#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>
#include<string>

std :: vector<std :: vector<std ::vector<string>>> lirefichier ()
{
   std :: ifstream monfichier ("m1projetcpp2.ppm");
    
   if (monfichier)
   {
    int compteur=0;
    std :: vector<int> resolution = {0,0};

    std :: string ligne; 
    while(getline(monfichier, ligne)) 
        {
            if (ligne[0] != '#') 
            {
                if (compteur == 0)
                {
                    std :: cout << "Ligne 1 ok" << std ::endl ;
                }
                if (compteur == 1)
                {
                    
                     resolution[0] = ligne[0];
                     resolution[1]  = ligne[1];
                    std :: cout << "Ligne 2 ok" << std ::endl ;

                }
                if (compteur==2)
                {
                    
                    std :: cout << "Ligne 3 ok" << std ::endl ;
                }
                else 
                {
                    std :: vector<int>  vecteur  (resolution[1],10);
                    std :: vector<std :: vector<int> > intermediaire (resolution[0], vecteur)  ;
                    std :: vector<std :: vector< std:: vector<string>>> image (3,intermediaire) ;
                    for (int i = 0;i<resolution[0];i++)
                    {
                        for (int j =0; j< resolution[1]; j++)
                        {
                            for (int k=0; k<3;k++)
                            {
                                image[i][j][k] = getline(monfichier,ligne);
                            }
                        }
                    }
                    

                }
                compteur ++;

            }

        }
   }
   return image;

}


int main ()
{
    lirefichier();
    return 0;
}