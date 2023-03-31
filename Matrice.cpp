#include"Matrice.hpp"

double Norme(double x, double y) 
{
    return sqrt(abs(x- y));
}

 
Matrice :: Matrice(int lig, int col)
{
    ligne = lig;
    colonne = col;
    mat = std::vector<std::vector<int>> (ligne, std::vector<int>(colonne, 0));
}

void Matrice :: AfficheMatrice()
{
    std::string s = std::to_string(mat[1][1]);
    std::cout << s.size() << std::endl;
    for (int x = 0; x < ligne; ++x)
    {
      for (int y = 0; y < colonne; ++y)
      {
        std::cout<<(char)mat[x][y];
        std::cout << mat[x][y]<< "   " ;
      }

      std::cout << std::endl;
    }
}



void Matrice :: dessiner_ligne(Point point)
// point.x est le coefficient directeur de la droite 
// point.y est l'ordonée à l'origine
{
    
    int lignes = ligne;
    int colonnes = colonne;
    float m =point.x;
    float p = point.y;

    if (abs(m)<=1){
            for(int j = 0; j < colonnes; j++) {
                if (((int)(m*j+p)<=lignes-1)&&((int)(m*j+p)>=0)){ // pour eviter que la droite "depasse" l'image
                    //std::cout<< (int)(m*j+p) << " "<< m*j+p<< " " << Norme((int)(m*j+p),m*j+p)*255<< " ";
                    //std::cout << int(m*j+p)/(m*j+p)<< " "; 
                    
                    mat[(int)(m*j+p)][j] = Norme((int)(m*j+p),m*j+p)*255;                     
                }
                if (((int)(m*j+p)+1<=lignes-1)&&((int)(m*j+p)+1>=0)){ // pour eviter que la droite "depasse" l'image
                    mat[(int)(m*j+p)+1][j] = (1-Norme((int)(m*j+p),m*j+p))*255;      // Colorisation du pixel en dessous         
                }
            }
    }
    if (abs(m)>1){
        for(int i = 0; i < lignes; i++) {
            if (((int)((i-p)/m)<=colonnes-1)&&((int)((i-p)/m)>=0)){ // pour eviter que la droite "depasse" l'image
                //std::cout<< (int)((i-p)/m) << " "<< ((i-p)/m)<< " " << Norme((int)((i-p)/m),((i-p)/m))*255<< " "<< (1-Norme((int)((i-p)/m),((i-p)/m)))*255<< " ";

                mat[i][(int)((i-p)/m)] = Norme((int)((i-p)/m),((i-p)/m))*255;
            }
            if (((int)((i-p)/m)+1<=colonnes-1)&&((int)((i-p)/m)+1>=0)){ // pour eviter que la droite "depasse" l'image
                    mat[i][(int)((i-p)/m)+1] = (1-Norme((int)((i-p)/m),((i-p)/m)))*255;                    
                }
        }
    }
    
}