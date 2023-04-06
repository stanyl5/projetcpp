#include"Image.hpp"

double Norme(double x, double y) 
{
    return sqrt(abs(x- y));
}

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


void Image :: dessiner_ligne(Point point, Point bornesup, Point borneinf)
// point.x est le coefficient directeur de la droite 
// point.y est l'ordonée à l'origine
{
    float m =point.x;
    float p = point.y;
    int xA = - bornesup.x;
    int yA = bornesup.y;
    int xB = - borneinf.x;
    int yB = -borneinf.y;


    if (abs(m)<=1)
    {
        for(int j = yA ; j < yB ; j++) 
        {
            if (((int)(m*j+p)<=xB-1)&&((int)(m*j+p)>=xA)) // pour eviter que la droite "depasse" l'image
            {
                //std::cout<< (int)(m*j+p) << " "<< m*j+p<< " " << Norme((int)(m*j+p),m*j+p)*255<< " ";
                //std::cout << int(m*j+p)/(m*j+p)<< " "; 
                for (int k=0;k<3;k++)
                {
                    image[(int)(m*j+p)][j][k] = Norme((int)(m*j+p),m*j+p)*255;                     
                }
            }
            if (((int)(m*j+p)+1<=xB-1)&&((int)(m*j+p)+1>=xA)) // pour eviter que la droite "depasse" l'image
            { 
                for (int k=0;k<3;k++)
                {
                    image[(int)(m*j+p)+1][j][k] = (1-Norme((int)(m*j+p),m*j+p))*255;      // Colorisation du pixel en dessous         
                }
            }
        }
    }
    if (abs(m)>1)
    {
        for(int i = xA; i < xB; i++) 
        {
            if (((int)((i-p)/m)<=yB-1)&&((int)((i-p)/m)>=yA)) // pour eviter que la droite "depasse" l'image
            {
                //std::cout<< (int)((i-p)/m) << " "<< ((i-p)/m)<< " " << Norme((int)((i-p)/m),((i-p)/m))*255<< " "<< (1-Norme((int)((i-p)/m),((i-p)/m)))*255<< " ";
                for (int k=0;k<3;k ++)
                {
                    image[i][(int)((i-p)/m)][k] = Norme((int)((i-p)/m),((i-p)/m))*255;
                }
            }
            if (((int)((i-p)/m)+1<=yB-1)&&((int)((i-p)/m)+1>=yA)) // pour eviter que la droite "depasse" l'image
            { 
                for (int k=0;k<3;k ++)
                {
                    image[i][(int)((i-p)/m)+1][k] = (1-Norme((int)((i-p)/m),((i-p)/m)))*255;                    
                }
            }
        }
    }
    
} 

