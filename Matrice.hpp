#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include <array>



struct Matrice
{
  int ligne;
  int colonne;
  std::vector<std::vector<int>> mat;

  Matrice();
  void AfficheMatrice();

};