#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

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
    for (int x = 0; x < ligne; ++x)
    {
      for (int y = 0; y < colonne; ++y)
      {
        std::cout << mat[x][y]<< "   " ;
      }

      std::cout << std::endl;
    }
  }
};

Matrice dessiner_ligne(Matrice mat, float m, float p){
    int lignes = mat.ligne;
    int colonnes = mat.colonne;
    if (abs(m)<=1){
            for(int j = 0; j < colonnes; j++) {
                if ((int)m*j+p<=lignes-1){ // pour eviter que la droite "depasse" l'image
                    mat.mat[(int)(m*j+p)][j] = 255; 
                }
            }
    }
    if (abs(m)>1){
        for(int i = 0; i < lignes; i++) {
            if ((int)((i-p)/m)<=colonnes-1){ // pour eviter que la droite "depasse" l'image
                
                mat.mat[i][(int)((i-p)/m)] = 255;
            }
        }
    }
    return mat;
}


int main(void)
{
  Matrice mat(10, 10);
  //mat.AfficheMatrice();
  Matrice mat2(10, 10);
  mat2 = dessiner_ligne(mat, 1, 1);
  mat2.AfficheMatrice();
  int width = 300;
  int height = 300;
  FILE *fp;

  fp = fopen("image.ppm", "wb"); // ouvrir le fichier en mode binaire

  fprintf(fp, "P6\n%d %d\n255\n", width, height); // écrire l'en-tête PPM

  unsigned char red[] = {255, 0, 0}; // définir la couleur rouge

  for (int i = 0; i < width*height; i++) {
      fwrite(red, 1, 3, fp); // écrire la couleur rouge pour chaque pixel
  }

  fclose(fp); // fermer le fichier
  return 0;
}
