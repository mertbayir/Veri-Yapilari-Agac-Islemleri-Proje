/**
 * @file yigin.cpp
 * @description  yiginla ilgili fonksiyonları yazdım.
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

Yigin::Yigin()
{
    tepe = -1;
}

void Yigin::ekle(int veri)
{
    if (tepe < MAX - 1)
    {
        tepe++;
        veriler[tepe] = veri;
    }
}

void Yigin::cikar()
{
    if (tepe != -1)
    {
        tepe--;
    }
}

int Yigin::getir()
{
    if (tepe != -1)
    {
        return veriler[tepe];
    }
    return -1;
}

void Yigin::yazdir()
{
    for (int i = tepe; i >= 0; i--)
    {
        cout << veriler[i] << " ";
    }
}

bool Yigin::bosmu()
{
    if (tepe == -1)
        return true;
    return false;
}

bool Yigin::dolumu()
{
    if (tepe == MAX - 1)
        return true;
    return false;
}
