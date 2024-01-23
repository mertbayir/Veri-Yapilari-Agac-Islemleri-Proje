/**
 * @file avldugum.cpp
 * @description  dugumle ilgili fonksiyonları yazdım
 * @course 1-C
 * @assignment 2
 * @date 23.12.2023
 * @author Mert BAYIR mert.bayir1@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include "avlagaci.hpp"
#include "avldugum.hpp"
#include "yigin.hpp"
using namespace std;

AVLDugum::AVLDugum(int veri)
{
    this->veri = veri;
    sol = 0;
    sag = 0;
}

AVLDugum::~AVLDugum()
{
    delete sol;
    delete sag;
}
