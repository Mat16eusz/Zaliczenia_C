/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Wektor_posortowany.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

inline int porownaj(const void* a, const void* b)
{
    return (*(double*)a > *(double*)b) ? 1 : (*(double*)a < *(double*)b) ? -1 : 0;
}

void Wektor_posortowany::sortuj()
{
    qsort(this->tablica, this->rozmiar, sizeof(double), porownaj);
}

Wektor_posortowany::~Wektor_posortowany()
{
    delete[] this->tablica;
    this->tablica = NULL;
}

Wektor_posortowany& Wektor_posortowany::operator = (const Wektor_posortowany& Obiekt)
{
    if (this != &Obiekt)
    {
        Wektor::operator = (Obiekt);

        sortuj();
    }

    return *this;
}

Wektor_pomocniczy Wektor_posortowany::operator [] (unsigned indeks)
{
    return Wektor_pomocniczy(this, this->tablica[indeks]);
}

istream& operator >> (istream& wejscie, Wektor_posortowany& Obiekt)
{
    wejscie >> (Wektor&)Obiekt;

    Obiekt.sortuj();

    return wejscie;
}

void Wektor_posortowany::ustaw_rozmiar(unsigned rozmiar)
{
    Wektor::ustaw_rozmiar(rozmiar);

    sortuj();
}

void Wektor_posortowany::dodaj(double nowa_wartosc)
{
    Wektor::dodaj(nowa_wartosc);

    sortuj();
}

Wektor_pomocniczy::operator double()
{
    return this->wartosc_spod_indeksu;
}

Wektor_pomocniczy& Wektor_pomocniczy::operator = (double wartosc_spod_indeksu)
{
    this->referencja_wartosci_spod_indeksu = wartosc_spod_indeksu;
    this->wartosc_spod_indeksu = wartosc_spod_indeksu;
    wskaznik_na_obiekt->sortuj();

    return *this;
}

Wektor_pomocniczy& Wektor_pomocniczy::operator = (Wektor_pomocniczy wartosc_spod_indeksu)
{
    this->referencja_wartosci_spod_indeksu = wartosc_spod_indeksu.wartosc_spod_indeksu;
    this->wartosc_spod_indeksu = wartosc_spod_indeksu.wartosc_spod_indeksu;
    wskaznik_na_obiekt->sortuj();

    return *this;
}
