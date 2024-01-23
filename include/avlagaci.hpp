/** 
* @file avlagaci.hpp
* @description  avlagaci.cpp nin başlık dosyası
* @course 1-C
* @assignment 2
* @date 23.12.2023
* @author Mert BAYIR mert.bayir1@ogr.sakarya.edu.tr
*/

#ifndef avlagaci_hpp
#define avlagaci_hpp

#include "avlagaci.hpp"
#include "avldugum.hpp"
#include "yigin.hpp"
#include <iostream>
using namespace std;

class AVLagaci
{
public:
    AVLDugum *kok;

    AVLagaci *agac;

    int toplam = 0;

    AVLagaci();

    ~AVLagaci();

    AVLDugum *ekleAgac(int veri, AVLDugum *aktifDugum);
   
    AVLDugum *sagaDondur(AVLDugum *buyukEbeveyn);
 

    AVLDugum *solaDondur(AVLDugum *buyukEbeveyn);

    int minDeger(AVLDugum *aktif);


    int maxDeger(AVLDugum *aktif);


    int dengesizlikYonu(AVLDugum *aktif);
 

    int yukseklik(AVLDugum *aktifDugum);
 

    int yukseklik();
  
    void ekleAgac(int eklenecek);
  
    void postorder(Yigin *yigin);


    void postorder(AVLDugum *aktifDugum, Yigin *yigin);
    

    void yiginyazdir(Yigin *yigin);

};


#endif