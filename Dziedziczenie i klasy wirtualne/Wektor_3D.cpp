/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Wektor_3d.h"
#include <iostream>
#include "cmath"

using namespace std;

void Wektor_3D::normalizacja_wektora()
{
	double dlugosc_wektora;

	this->rozmiar_wektora_jednostkowego = 3;
	this->tablica_wektor_jednostkowy = new double[this->rozmiar_wektora_jednostkowego];

	dlugosc_wektora = sqrt(pow(tablica[0], 2) + pow(tablica[1], 2) + pow(tablica[2], 2));

	if (dlugosc_wektora <= 0)
	{
		cout << "Wektor nie istnieje bo jego dlugosc jest ujemna lub zerowa" << endl;
		
		for (int i = 0; i < this->rozmiar_wektora_jednostkowego; i++)
		{
			this->tablica_wektor_jednostkowy[i] = 0;
		}
	}
	else
	{
		for (int i = 0; i < this->rozmiar_wektora_jednostkowego; i++)
		{
			this->tablica_wektor_jednostkowy[i] = this->tablica[i] / dlugosc_wektora;
		}

		/*double sprawdzenie = sqrt(pow(this->tablica_wektor_jednostkowy[0], 2) + pow(this->tablica_wektor_jednostkowy[1], 2) + pow(this->tablica_wektor_jednostkowy[2], 2));
		cout << sprawdzenie << endl;*/
	}
}

Wektor_3D::~Wektor_3D()
{
	delete[] this->tablica_wektor_jednostkowy;
	this->tablica_wektor_jednostkowy = NULL;
}

Wektor_3D& Wektor_3D::operator = (const Wektor_3D& Obiekt)
{
	if (this != &Obiekt)
	{
		Wektor::operator = (Obiekt);
	}

	return *this;
}

Wektor_3D_pomocniczy Wektor_3D::operator [] (unsigned indeks)
{
	return Wektor_3D_pomocniczy(this, this->tablica[indeks]);
}

ostream& operator << (ostream& wyjscie, Wektor_3D& Obiekt)
{
	wyjscie << "[" << Obiekt.rozmiar_wektora_jednostkowego;
	for (int i = 0; i < Obiekt.rozmiar_wektora_jednostkowego; i++)
	{
		wyjscie << " " << Obiekt.tablica_wektor_jednostkowy[i];
	}
	wyjscie << "]";

	return wyjscie;
}

istream& operator >> (istream& wejscie, Wektor_3D& Obiekt)
{
	wejscie >> (Wektor&)Obiekt;

	Obiekt.normalizacja_wektora();

	return wejscie;
}

void Wektor_3D::ustaw_rozmiar(unsigned rozmiar)
{
	if (rozmiar > 3)
	{
		cout << "Podany rozmiar jest za duzy bo wektor jednostkowy 3D musi miec rozmiar 3!" << endl << "Rozmiar zostanie ustawiony na 3!" << endl;
		rozmiar = 3;
	}
	Wektor::ustaw_rozmiar(rozmiar);

	normalizacja_wektora();
}

void Wektor_3D::dodaj(double nowa_wartosc)
{
	if (this->rozmiar >= 3)
	{
		cout << "Podany rozmiar jest odpowiedni i dodawana wartosc nie bedzie uwzgledniona!" << endl << "Wektor jednostkowy 3D musi miec rozmiar 3!" << endl;

		normalizacja_wektora();
	}
	else
	{
		Wektor::dodaj(nowa_wartosc);

		normalizacja_wektora();
	}
}

Wektor_3D_pomocniczy::operator double()
{
	return this->wartosc_spod_indeksu;
}

Wektor_3D_pomocniczy& Wektor_3D_pomocniczy::operator = (double wartosc_spod_indeksu)
{
	this->referencja_wartosci_spod_indeksu = wartosc_spod_indeksu;
	this->wartosc_spod_indeksu = wartosc_spod_indeksu;
	wskaznik_na_obiekt->normalizacja_wektora();

	return *this;
}

Wektor_3D_pomocniczy& Wektor_3D_pomocniczy::operator = (Wektor_3D_pomocniczy wartosc_spod_indeksu)
{
	this->referencja_wartosci_spod_indeksu = wartosc_spod_indeksu.wartosc_spod_indeksu;
	this->wartosc_spod_indeksu = wartosc_spod_indeksu.wartosc_spod_indeksu;
	wskaznik_na_obiekt->normalizacja_wektora();

	return *this;
}
