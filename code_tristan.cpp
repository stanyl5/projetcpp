#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <string.h>

struct Matrice
{
  int ligne;
  int colonne;
  std::vector<std::vector<int>> mat;

  Matrice(int lig = 0, int col = 0)
  {
    ligne = lig;
    colonne = col;
    mat = std::vector<std::vector<int>>(ligne, std::vector<int>(colonne, 0));
  }

  void AfficheMatrice()
  {
    std::string s = std::to_string(mat[1][1]);
    std::cout << strlen(s) << std::endl;
    for (int x = 0; x < ligne; ++x)
    {
      for (int y = 0; y < colonne; ++y)
      {
        //std::cout<<(char)mat[x][y];
        //std::cout << mat[x][y]<< "   " ;
      }

      std::cout << std::endl;
    }
  }
};

double Norme(double x, double y) {
    return sqrt(abs(x- y));
}

Matrice dessiner_ligne(Matrice mat, float m, float p){
    int lignes = mat.ligne;
    int colonnes = mat.colonne;
    if (abs(m)<=1){
            for(int j = 0; j < colonnes; j++) {
                if (((int)(m*j+p)<=lignes-1)&&((int)(m*j+p)>=0)){ // pour eviter que la droite "depasse" l'image
                    //std::cout<< (int)(m*j+p) << " "<< m*j+p<< " " << Norme((int)(m*j+p),m*j+p)*255<< " ";
                    //std::cout << int(m*j+p)/(m*j+p)<< " "; 
                    
                    mat.mat[(int)(m*j+p)][j] = Norme((int)(m*j+p),m*j+p)*255;                    
                }
                if (((int)(m*j+p)+1<=lignes-1)&&((int)(m*j+p)+1>=0)){ // pour eviter que la droite "depasse" l'image
                    mat.mat[(int)(m*j+p)+1][j] = (1-Norme((int)(m*j+p),m*j+p))*255;                    
                }
            }
    }
    if (abs(m)>1){
        for(int i = 0; i < lignes; i++) {
            if (((int)((i-p)/m)<=colonnes-1)&&((int)((i-p)/m)>=0)){ // pour eviter que la droite "depasse" l'image
                //std::cout<< (int)((i-p)/m) << " "<< ((i-p)/m)<< " " << Norme((int)((i-p)/m),((i-p)/m))*255<< " "<< (1-Norme((int)((i-p)/m),((i-p)/m)))*255<< " ";

                mat.mat[i][(int)((i-p)/m)] = Norme((int)((i-p)/m),((i-p)/m))*255;
            }
            if (((int)((i-p)/m)+1<=colonnes-1)&&((int)((i-p)/m)+1>=0)){ // pour eviter que la droite "depasse" l'image
                    mat.mat[i][(int)((i-p)/m)+1] = (1-Norme((int)((i-p)/m),((i-p)/m)))*255;                    
                }
        }
    }
    return mat;
}

int main(void)
{
  
  int width = 10;
  int height = 10;
  Matrice mat(width, height);
  //mat.AfficheMatrice();
  Matrice mat2(width, height);
  mat2 = dessiner_ligne(mat, -0.25, 3);
  std::cout<<"\n";
  std::cout<<"\n";
  mat2.AfficheMatrice();
 

  return 0;
}
