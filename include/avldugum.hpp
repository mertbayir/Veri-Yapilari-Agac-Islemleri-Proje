/** 
* @file avldugum.hpp
* @description  avldugum.cpp nin başlık dosyası
* @course 1-C
* @assignment 2
* @date 23.12.2023
* @author Mert BAYIR mert.bayir1@ogr.sakarya.edu.tr
*/

#ifndef avldugum_hpp
#define avldugum_hpp

#include "avlagaci.hpp"
#include "avldugum.hpp"
#include "yigin.hpp"
using namespace std;

class AVLDugum
{
public:
    AVLDugum(int veri);

    ~AVLDugum();

    int veri;
    int yukseklik;
    AVLDugum *sol;
    AVLDugum *sag;
};


#endif