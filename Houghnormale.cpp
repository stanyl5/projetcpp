#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

#include "Image.hpp"
#include "Matrice.hpp"

#include "Point.hpp"

Point Houghnormale(std ::vector<Point> vecpoints)
{
    Matrice buffer(30,30);
    for (int i= 0; i< vecpoints.size(); i++)
    {
        if (vecpoints[i].x * i + vecpoints[i].y>0 && vecpoints[i].x * i + vecpoints[i].y<30)
        buffer.mat[i][vecpoints[i].x * i + vecpoints[i].y] ++;
    }
    int max =0;
    Point coormax{0,0};
    for (int i=0 ; i<30; i++)
    {
        for (int j=0;i<30;i++)
        {
            if (max<buffer.mat[i][j])
            {
                max = buffer.mat[i][j];
                coormax.x = i;
                coormax.y = j;
            }
        }
    }
    return coormax;
}

int main ()
{
    Point P {1,2};
    Point Q {2,3};
    Point R {4,5};
    std :: vector<Point> v;
    v.push_back (P);
    v.push_back (Q);
    v.push_back (R);
    Point S= Houghnormale(v);
    S.AffichePoint();
}