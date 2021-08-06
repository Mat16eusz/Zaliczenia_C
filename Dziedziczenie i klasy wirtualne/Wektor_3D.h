/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef WEKTOR_3D_H
#define WEKTOR_3D_H

#include <iostream>
#include "Wektor.h"

class Wektor_3D_pomocniczy;

class Wektor_3D : public virtual Wektor
{
protected:
	unsigned rozmiar_wektora_jednostkowego;
	double* tablica_wektor_jednostkowy;

	void normalizacja_wektora();

public:
	friend class Wektor_3D_pomocniczy;

	Wektor_3D() : Wektor() { normalizacja_wektora(); }
	Wektor_3D(unsigned rozmiar) : Wektor(rozmiar) { normalizacja_wektora(); }
	Wektor_3D(unsigned rozmiar, double* tablica) : Wektor(rozmiar, tablica) { normalizacja_wektora(); }
	Wektor_3D(const Wektor& Obiekt) : Wektor(Obiekt) { normalizacja_wektora(); }
	~Wektor_3D();

	Wektor_3D& operator = (const Wektor_3D& Obiekt);
	Wektor_3D_pomocniczy operator [] (unsigned indeks);
	friend std::ostream& operator << (std::ostream& wyjscie, Wektor_3D& Obiekt);
	friend std::istream& operator >> (std::istream& wejscie, Wektor_3D& Obiekt);

	void ustaw_rozmiar(unsigned rozmiar);
	void dodaj(double nowa_wartosc);
};

class Wektor_3D_pomocniczy
{
private:
	double& referencja_wartosci_spod_indeksu;
	double wartosc_spod_indeksu;
	Wektor_3D* wskaznik_na_obiekt;

public:
	Wektor_3D_pomocniczy(Wektor_3D* Obiekt, double& wartosc_spod_indeksu) :
		referencja_wartosci_spod_indeksu(wartosc_spod_indeksu), wartosc_spod_indeksu(this->referencja_wartosci_spod_indeksu),
		wskaznik_na_obiekt(Obiekt) {}

	operator double();
	Wektor_3D_pomocniczy& operator = (double wartosc_spod_indeksu);
	Wektor_3D_pomocniczy& operator = (Wektor_3D_pomocniczy wartosc_spod_indeksu);
};

#endif
