#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

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
        std :: cout << compteur<<std :: endl;   
        if (ligne[0] != '#') 
        {
            if (compteur == 0)
            {
                std :: string qualite ;
                qualite = ligne;

                std :: cout << "Ligne 1 ok " << qualite << std ::endl ;
            }
            else
            {if (compteur == 1)
                {                     
                    std::string parseNum;
                    std::stringstream streamLigne(ligne);
                    int res=0;
                    while(std::getline(streamLigne,parseNum,' '))
                    {
                        resolution[res] = std::stoi(parseNum);
                        res++;
                    } 


                    std :: cout << "Ligne 2 ok" << std ::endl ;

                }
            else
            {if (compteur==2)
            {
                int valmax = std :: stoi(ligne);
                std :: cout << "Ligne 3 ok " << valmax << std ::endl ;
            }
            else 
            {if(compteur == 3)
                {
                    std :: vector<int>  vecteur  (3,0);
                    std :: vector<std :: vector<int> > intermediaire (resolution[1], vecteur)  ;
                    std :: vector<std :: vector< std:: vector<int>>> image (resolution[0],intermediaire) ;
                    
                    
                                
                    for (int i = 0;i<resolution[0];i++)
                    { 
                        //std :: cout<< "ligne "<< i<< std ::endl;
                        for (int j =0; j< resolution[1]; j++)
                        {
                            //std :: cout<< "colonne "<< j<< std ::endl;

                            for (int k=0; k<3;k++) 
                            {
                            //std :: cout<< "couleur "<< k<< std ::endl;
                            monfichier >> image[i][j][k] ;
                            getline(monfichier,ligne);

                            
                            
                                
                            }
                        }

                    }
                    std :: cout<< image[0][0][0] << " 0,1,1"<< std :: endl ;
                    
                    std :: cout<< image[29][29][1] << " 1,1,1"<< std :: endl ;
                    std :: cout << image[29][29][2] << " 2,2,0"<< std :: endl;

                    return image;
                
                }
                else
                {
                    std :: vector<int>  vecteur  (0,0);
                    std :: vector<std :: vector<int> > intermediaire (0, vecteur)  ;
                    std :: vector<std :: vector< std:: vector<int>>> image (0,intermediaire) ;
                    return image ; 
                }
            }
            }
        }
        compteur ++;

        }

    }
   }
}


int main ()
{
    lirefichier();
    return 0;
}