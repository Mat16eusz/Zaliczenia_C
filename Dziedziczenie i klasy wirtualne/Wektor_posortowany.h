/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef WEKTOR_POSORTOWANY_H
#define WEKTOR_POSORTOWANY_H

#include <iostream>
#include "Wektor.h"

class Wektor_pomocniczy;

class Wektor_posortowany : public virtual Wektor
{
private:
    void sortuj();

public:
    friend class Wektor_pomocniczy;

    Wektor_posortowany() : Wektor() { sortuj(); }
    Wektor_posortowany(unsigned rozmiar) : Wektor(rozmiar) { sortuj(); }
    Wektor_posortowany(unsigned rozmiar, double* tablica) : Wektor(rozmiar, tablica) { sortuj(); }
    Wektor_posortowany(const Wektor& Obiekt) : Wektor(Obiekt) { sortuj(); }
    ~Wektor_posortowany();

    Wektor_posortowany& operator = (const Wektor_posortowany& Obiekt);
    Wektor_pomocniczy operator [] (unsigned indeks);
    friend std::istream& operator >> (std::istream& wejscie, Wektor_posortowany& Obiekt);

    void ustaw_rozmiar(unsigned rozmiar);
    void dodaj(double nowa_wartosc);
};

class Wektor_pomocniczy
{
private:
    double& referencja_wartosci_spod_indeksu;
    double wartosc_spod_indeksu;
    Wektor_posortowany* wskaznik_na_obiekt;

public:
    Wektor_pomocniczy(Wektor_posortowany* Obiekt, double& wartosc_spod_indeksu) :
        referencja_wartosci_spod_indeksu(wartosc_spod_indeksu), wartosc_spod_indeksu(this->referencja_wartosci_spod_indeksu),
        wskaznik_na_obiekt(Obiekt) {}

    operator double();
    Wektor_pomocniczy& operator = (double wartosc_spod_indeksu);
    Wektor_pomocniczy& operator = (Wektor_pomocniczy wartosc_spod_indeksu);
};

#endif
