/**
 * @file avlagaci.cpp
 * @description  avl ağacıyla ilgili fonksiyonları yazdım
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

AVLagaci::AVLagaci()
{
    kok = 0;
}

AVLagaci::~AVLagaci()
{
    delete kok;
}

AVLDugum *AVLagaci::ekleAgac(int veri, AVLDugum *aktifDugum)
{

    if (aktifDugum == 0)
    {
        return new AVLDugum(veri);
    }

    if (aktifDugum->veri > veri)
    {

        aktifDugum->sol = ekleAgac(veri, aktifDugum->sol);

        if (yukseklik(aktifDugum->sol) - yukseklik(aktifDugum->sag) > 1)
        {
            if (veri < aktifDugum->sol->veri)
            {
                aktifDugum = sagaDondur(aktifDugum);
            }
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum = sagaDondur(aktifDugum);
            }
        }
    }

    else if (aktifDugum->veri < veri)
    {
        aktifDugum->sag = ekleAgac(veri, aktifDugum->sag);

        if (yukseklik(aktifDugum->sag) - yukseklik(aktifDugum->sol) > 1)
        {
            if (veri > aktifDugum->sag->veri)
            {
                aktifDugum = solaDondur(aktifDugum);
            }

            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum = solaDondur(aktifDugum);
            }
        }
    }

    return aktifDugum;
}

AVLDugum *AVLagaci::sagaDondur(AVLDugum *buyukEbeveyn)
{
    AVLDugum *solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}

AVLDugum *AVLagaci::solaDondur(AVLDugum *buyukEbeveyn)
{
    AVLDugum *sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}

int AVLagaci::minDeger(AVLDugum *aktif)
{
    if (aktif->sol)
    {
        return minDeger(aktif->sol);
    }

    return aktif->veri;
}

int AVLagaci::maxDeger(AVLDugum *aktif)
{
    if (aktif->sag)
    {
        return maxDeger(aktif->sag);
    }

    return aktif->veri;
}

int AVLagaci::dengesizlikYonu(AVLDugum *aktif)
{
    if (aktif == 0)
    {
        return 0;
    }

    return yukseklik(aktif->sol) - yukseklik(aktif->sag);
}

int AVLagaci::yukseklik(AVLDugum *aktifDugum)
{
    if (aktifDugum)
    {
        return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
    }
    return -1;
}

int AVLagaci::yukseklik()
{
    return yukseklik(kok);
}

void AVLagaci::ekleAgac(int eklenecek)
{
    kok = ekleAgac(eklenecek, kok);
}

void AVLagaci::postorder(Yigin *yigin)
{
    postorder(kok, yigin);
}

void AVLagaci::postorder(AVLDugum *aktifDugum, Yigin *yigin)
{
    if (aktifDugum == 0)
    {
        return;
    }

    if (aktifDugum->sol != 0 || aktifDugum->sag != 0)
    {
        toplam += aktifDugum->veri;
    }

    postorder(aktifDugum->sol, yigin);
    postorder(aktifDugum->sag, yigin);

    if (aktifDugum->sol == 0 && aktifDugum->sag == 0)
    {
        yigin->ekle(aktifDugum->veri);
    }
}

void AVLagaci::yiginyazdir(Yigin *yigin)
{
    yigin->yazdir();
}
