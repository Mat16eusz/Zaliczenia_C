/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef STOS_H
#define STOS_H

#include <iostream>
#include <cstring>

using namespace std;

template <typename Typ> class Stos
{
private:
	unsigned rozmiar;
	Typ* tablica;

public:
	Stos();
	Stos(const Stos& Obiekt);
	~Stos();

	void poloz_na_stos(Typ na_stos);
	Typ zdejmij_z_wierzchu();
	void oproznij();
	bool czy_pusty();
	unsigned pobierz_rozmiar();
};

template <typename Typ> Stos<Typ>::Stos()
{
	this->tablica = NULL;
	this->rozmiar = 0;
}

template <typename Typ> Stos<Typ>::Stos(const Stos& Obiekt)
{
	this->rozmiar = Obiekt.rozmiar;

	this->tablica = new Typ[rozmiar];

	memcpy(&this->tablica[0], &Obiekt.tablica[0], Obiekt.rozmiar * sizeof(Typ));
}

template <typename Typ> Stos<Typ>::~Stos()
{
	delete[] this->tablica;
	this->tablica = NULL;
}

template <typename Typ> void Stos<Typ>::poloz_na_stos(Typ na_stos)
{
	Typ* tablica_tymczasowa = new Typ[this->rozmiar];

	memcpy(&tablica_tymczasowa[0], &this->tablica[0], this->rozmiar * sizeof(Typ));

	delete[] this->tablica;
	this->rozmiar++;
	this->tablica = new Typ[this->rozmiar];

	memcpy(&this->tablica[0], &tablica_tymczasowa[0], this->rozmiar * sizeof(Typ));
	this->tablica[this->rozmiar - 1] = na_stos;

	delete[] tablica_tymczasowa;
	tablica_tymczasowa = NULL;
}

template <typename Typ> Typ Stos<Typ>::zdejmij_z_wierzchu()
{
	if (czy_pusty())
	{
		throw this->rozmiar;
	}
	else
	{
		this->rozmiar--;

		Typ ostatni = this->tablica[this->rozmiar];
		
		Typ* tablica_tymczasowa = new Typ[this->rozmiar];

		memcpy(&tablica_tymczasowa[0], &this->tablica[0], this->rozmiar * sizeof(Typ));

		delete[] this->tablica;
		this->tablica = new Typ[this->rozmiar];

		memcpy(&this->tablica[0], &tablica_tymczasowa[0], this->rozmiar * sizeof(Typ));

		delete[] tablica_tymczasowa;
		tablica_tymczasowa = NULL;

		return ostatni;
	}
}

template <typename Typ> void Stos<Typ>::oproznij()
{
	while (this->rozmiar != 0)
	{
		zdejmij_z_wierzchu();
	}
}

template <typename Typ> bool Stos<Typ>::czy_pusty()
{
	if (this->rozmiar == 0)
	{
		return true;
	}

	return false;
}

template <typename Typ> unsigned Stos<Typ>::pobierz_rozmiar()
{
	return this->rozmiar;
}

#endif
