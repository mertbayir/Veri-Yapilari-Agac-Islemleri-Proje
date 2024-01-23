/** 
* @file yigin.hpp
* @description  yigin.cpp nin başlık dosyası
* @course 1-C
* @assignment 2
* @date 23.12.2023
* @author Mert BAYIR mert.bayir1@ogr.sakarya.edu.tr
*/

#ifndef yigin_hpp
#define yigin_hpp

#include "avlagaci.hpp"
#include "avldugum.hpp"
#include "yigin.hpp"
using namespace std;

const int MAX = 500;
class Yigin
{
public:
    int tepe;
    int veriler[MAX];
    Yigin();

    void ekle(int veri);

    void cikar();

    int getir();

    void yazdir();

    bool bosmu();

    bool dolumu();
};




#endif