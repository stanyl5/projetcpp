#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>
#include<string>

std :: vector<std :: vector<std ::vector<int>>> lirefichier ()
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
                else
                {if (compteur == 1)
                    {
                        int position = monfichier.tellg();
                        std :: cout<< ligne << std :: endl ;
                    
                        monfichier >> resolution[0];
                        std :: cout<< resolution[0]<< std ::endl;
                        monfichier >> resolution[1] ;
                        std :: cout<< resolution[1]<< std ::endl;


                        std :: cout << "Ligne 2 ok" << std ::endl ;

                    }
                else
                {if (compteur==2)
                {
                    
                    std :: cout << "Ligne 3 ok" << std ::endl ;
                }
                else 
                {
                    std :: vector<int>  vecteur  (3,0);
                    std :: vector<std :: vector<int> > intermediaire (resolution[1], vecteur)  ;
                    std :: vector<std :: vector< std:: vector<int>>> image (resolution[0],intermediaire) ;
                    
                    
                                   
                    for (int i = 0;i<resolution[0];i++)
                    { 
                        std :: cout<< "ligne "<< i<< std ::endl;
                        for (int j =0; j< resolution[1]; j++)
                        {
                            std :: cout<< "colonne "<< j<< std ::endl;

                            for (int k=0; k<3;k++) 
                            {
                            std :: cout<< "couleur "<< k<< std ::endl;
                            getline(monfichier,ligne);
                            monfichier >> image[i][j][k] ;
                                
                            }
                        }
                    }
                    std :: cout<< image[0][0][0] << " 0,1,1"<< std :: endl ;

                    std :: cout<< image[0][0][1] << " 1,1,1"<< std :: endl ;
                    std :: cout << image[0][0][2] << " 2,2,0"<< std :: endl;

                    return image;
                
                }
                }
            }
            compteur ++;

            }

        }
   }
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