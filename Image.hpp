#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include <array>



struct Image
{
    std ::string qualite;
    int ligne;
    int colonne;
    int valmax;
    std :: vector<std :: vector< std:: array<int,3>>> image;
    
    void afficheImage();
    
};