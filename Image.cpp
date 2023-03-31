#include"Image.hpp"

void Image ::  afficheImage()
{
    for (int i=0; i<ligne; i++)
    {
        for (int j=0;j<colonne; j++)
        {
            std:: cout<< " (";
            for (int k=0; k<3; k++)
            {
                if (k!= 2)
                std :: cout << image[i][j][k]<<", ";
                else
                std :: cout << image[i][j][k]<< ") ";
            }
        }
        std::cout << std :: endl;
    }
}