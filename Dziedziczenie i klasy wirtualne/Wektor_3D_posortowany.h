/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef WEKTOR_3D_POSORTOWANY_H
#define WEKTOR_3D_POSORTOWANY_H

#include <iostream>
#include "Wektor_posortowany.h"
#include "Wektor_3D.h"

class Wektor_3D_posortowany_pomocniczy;

class Wektor_3D_posortowany : public Wektor_posortowany, public Wektor_3D
{
private:
    void sortuj();

public:
    friend class Wektor_3D_posortowany_pomocniczy;

    Wektor_3D_posortowany() : Wektor() { normalizacja_wektora(); sortuj(); }
    Wektor_3D_posortowany(unsigned rozmiar) : Wektor(rozmiar) { normalizacja_wektora(); sortuj(); }
    Wektor_3D_posortowany(unsigned rozmiar, double* tablica) : Wektor(rozmiar, tablica) { normalizacja_wektora(); sortuj(); }
    Wektor_3D_posortowany(const Wektor& Obiekt) : Wektor(Obiekt) { normalizacja_wektora(); sortuj(); }
    ~Wektor_3D_posortowany();

    Wektor_3D_posortowany& operator = (const Wektor_3D_posortowany& Obiekt);
    Wektor_3D_posortowany_pomocniczy operator [] (unsigned indeks);
    friend std::istream& operator >> (std::istream& wejscie, Wektor_3D_posortowany& Obiekt);

    void ustaw_rozmiar(unsigned rozmiar);
    void dodaj(double nowa_wartosc);
};

class Wektor_3D_posortowany_pomocniczy
{
private:
    double& referencja_wartosci_spod_indeksu;
    double wartosc_spod_indeksu;
    Wektor_3D_posortowany* wskaznik_na_obiekt;

public:
    Wektor_3D_posortowany_pomocniczy(Wektor_3D_posortowany* Obiekt, double& wartosc_spod_indeksu) :
        referencja_wartosci_spod_indeksu(wartosc_spod_indeksu), wartosc_spod_indeksu(this->referencja_wartosci_spod_indeksu),
        wskaznik_na_obiekt(Obiekt) {}

    operator double();
    Wektor_3D_posortowany_pomocniczy& operator = (double wartosc_spod_indeksu);
    Wektor_3D_posortowany_pomocniczy& operator = (Wektor_3D_posortowany_pomocniczy wartosc_spod_indeksu);
};

#endif
