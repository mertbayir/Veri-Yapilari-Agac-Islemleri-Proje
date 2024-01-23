/** 
* @file ornek.cpp
* @description  ağaç,yığın ve yedek diziler oluşturuldu.Silme işlemleri yapıldı.
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

int main()
{
    string satir;
    int agacSay = 0;
    AVLagaci *tumAgac[500];
    AVLagaci *tumAgacYedek[500];
    Yigin *tumYigin[500];
    Yigin *tumYedek[500];
    ifstream dosyaOku("Veri1.txt");
    if (dosyaOku.is_open())
    {
        while (std::getline(dosyaOku, satir))
        {
            Yigin *yigin = new Yigin();
            Yigin *yedek = new Yigin();
            AVLagaci *yedekAgac = new AVLagaci();
            stringstream sayiOku(satir);
            int siradaki;
            AVLagaci *agaclar = new AVLagaci();
            while (sayiOku >> siradaki)
            {
                agaclar->ekleAgac(siradaki);
            }
            tumAgac[agacSay] = agaclar;
            tumYigin[agacSay] = yigin;
            tumYedek[agacSay] = yedek;
            tumAgacYedek[agacSay] = yedekAgac;
            agacSay++;
            agaclar->postorder(yigin);
        }

        for (int i = 0; i < agacSay; i++)
        {
            *tumYedek[i] = *tumYigin[i];
        }
        for (int i = 0; i < agacSay; i++)
        {
            tumAgacYedek[i] = tumAgac[i];
        }

        while (agacSay > 1)
        {
            int minIndex = -1;
            for (int i = 0; i < agacSay; i++)
            {
                int tepeDeger = tumYigin[i]->getir();
                if (minIndex == -1 || tepeDeger < tumYigin[minIndex]->getir())
                {
                    minIndex = i;
                }
            }

            tumYigin[minIndex]->cikar();

            if (tumYigin[minIndex]->bosmu())
            {
                for (int i = 0; i < agacSay; i++)
                {
                    *tumYigin[i] = *tumYedek[i];
                }

                delete tumAgac[minIndex];
                delete tumYigin[minIndex];
                delete tumYedek[minIndex];

                for (int i = minIndex; i < agacSay - 1; i++)
                {
                    tumAgac[i] = tumAgac[i + 1];
                    tumYigin[i] = tumYigin[i + 1];
                    tumYedek[i] = tumYedek[i + 1];
                }
                agacSay--;
                int minIndex = -1;
                for (int i = 0; i < agacSay; i++)
                {
                    int tepeDeger = tumYigin[i]->getir();
                    if (minIndex == -1 || tepeDeger < tumYigin[minIndex]->getir())
                    {
                        minIndex = i;
                    }
                }

                tumYigin[minIndex]->cikar();
                 for(int i = 0; i < agacSay; i++)
                {
                   int ascii = tumAgac[i]->toplam % (90 - 65 + 1) + 65;
                   cout << (char)ascii;
                }
                system("cls");
            }

            cout << endl;
            int maxIndex = -1;
            for (int i = 0; i < agacSay; i++)
            {
                int tepeDeger = tumYigin[i]->getir();
                if (maxIndex == -1 || tepeDeger > tumYigin[maxIndex]->getir())
                {
                    maxIndex = i;
                }
            }

            tumYigin[maxIndex]->cikar();

            if (tumYigin[maxIndex]->bosmu())
            {
                for (int i = 0; i < agacSay; i++)
                {
                    *tumYigin[i] = *tumYedek[i];
                }

                delete tumAgac[maxIndex];
                delete tumYigin[maxIndex];
                delete tumYedek[maxIndex];
                for (int i = maxIndex; i < agacSay - 1; i++)
                {
                    tumAgac[i] = tumAgac[i + 1];
                    tumYigin[i] = tumYigin[i + 1];
                    tumYedek[i] = tumYedek[i + 1];
                }
                agacSay--;

                for(int i = 0; i < agacSay; i++)
                {
                   int ascii = tumAgac[i]->toplam % (90 - 65 + 1) + 65;
                   cout << (char)ascii;
                }
                system("cls");

            }
        }

        int ilkIndeks;
        for (int i = 0; i < 500; i++)
        {
            if (tumAgac[0] == tumAgacYedek[i])
            {
                ilkIndeks = (i + 1); // tumAgacYedek[i] ifadesi, (i+1). elemanı tutar.
                break;
            }
        }

        int ascii = tumAgac[0]->toplam % (90 - 65 + 1) + 65;

        cout << endl;
        cout << "------------------------------" << endl;
        cout << "|                             |" << endl;
        cout << "|                             |" << endl;
        cout << "|  "
             << "Son Karakter : " << (char)ascii << "           |" << endl;
        cout << "|  "
             << "AVL No : "
             << ilkIndeks << "               |" << endl;
        cout << "|                             |" << endl;
        cout << "|                             |" << endl;
        cout << "------------------------------" << endl;

        dosyaOku.close();
    }
}
