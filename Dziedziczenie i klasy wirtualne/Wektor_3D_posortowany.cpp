/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Wektor_3D_posortowany.h"
#include <iostream>
#include <cstdlib>

using namespace std;

inline int porownaj(const void* a, const void* b)
{
	return (*(double*)a > *(double*)b) ? 1 : (*(double*)a < *(double*)b) ? -1 : 0;
}

void Wektor_3D_posortowany::sortuj()
{
	qsort(this->tablica_wektor_jednostkowy, this->rozmiar_wektora_jednostkowego, sizeof(double), porownaj);
}

Wektor_3D_posortowany::~Wektor_3D_posortowany()
{
	delete[] this->tablica;
	this->tablica = NULL;
	delete[] this->tablica_wektor_jednostkowy;
	this->tablica_wektor_jednostkowy = NULL;
}

Wektor_3D_posortowany& Wektor_3D_posortowany::operator = (const Wektor_3D_posortowany& Obiekt)
{
	if (this != &Obiekt)
	{
		Wektor_3D::operator = (Obiekt);

		sortuj();
	}

	return *this;
}

Wektor_3D_posortowany_pomocniczy Wektor_3D_posortowany::operator [] (unsigned indeks)
{
	return Wektor_3D_posortowany_pomocniczy(this, this->tablica[indeks]);
}

istream& operator >> (istream& wejscie, Wektor_3D_posortowany& Obiekt)
{
	wejscie >> (Wektor_3D&)Obiekt;

	Obiekt.normalizacja_wektora();
	Obiekt.sortuj();

	return wejscie;
}

void Wektor_3D_posortowany::ustaw_rozmiar(unsigned rozmiar)
{
	Wektor_3D::ustaw_rozmiar(rozmiar);

	sortuj();
}

void Wektor_3D_posortowany::dodaj(double nowa_wartosc)
{
	Wektor_3D::dodaj(nowa_wartosc);

	sortuj();
}

Wektor_3D_posortowany_pomocniczy::operator double()
{
	return this->wartosc_spod_indeksu;
}

Wektor_3D_posortowany_pomocniczy& Wektor_3D_posortowany_pomocniczy::operator = (double wartosc_spod_indeksu)
{
	this->referencja_wartosci_spod_indeksu = wartosc_spod_indeksu;
	this->wartosc_spod_indeksu = wartosc_spod_indeksu;
	wskaznik_na_obiekt->normalizacja_wektora();
	wskaznik_na_obiekt->sortuj();

	return *this;
}

Wektor_3D_posortowany_pomocniczy& Wektor_3D_posortowany_pomocniczy::operator = (Wektor_3D_posortowany_pomocniczy wartosc_spod_indeksu)
{
	this->referencja_wartosci_spod_indeksu = wartosc_spod_indeksu.wartosc_spod_indeksu;
	this->wartosc_spod_indeksu = wartosc_spod_indeksu.wartosc_spod_indeksu;
	wskaznik_na_obiekt->normalizacja_wektora();
	wskaznik_na_obiekt->sortuj();

	return *this;
}
