/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Wektor.h"
#include <iostream>
#include <cstring>

using namespace std;

Wektor::Wektor()
{
    cout << "Konstruktor domyslny" << endl;
}

Wektor::Wektor(unsigned rozmiar)
{
    this->tablica = new double[rozmiar];

    this->rozmiar = rozmiar;
}

Wektor::Wektor(unsigned rozmiar, double* tablica)
{
    this->tablica = new double[rozmiar];

    memcpy(&this->tablica[0], &tablica[0], rozmiar * sizeof(double));

    this->rozmiar = rozmiar;
}

Wektor::Wektor(const Wektor& Obiekt)
{
    this->rozmiar = Obiekt.rozmiar;

    this->tablica = new double[rozmiar];

    memcpy(&this->tablica[0], &Obiekt.tablica[0], rozmiar * sizeof(double));
}

Wektor::~Wektor()
{
    delete[] this->tablica;
    this->tablica = NULL;
}

Wektor& Wektor::operator = (const Wektor& Obiekt)
{
    if (this != &Obiekt)
    {
        delete[] this->tablica;

        this->tablica = new double[Obiekt.rozmiar];

        memcpy(&this->tablica[0], &Obiekt.tablica[0], Obiekt.rozmiar * sizeof(double));

        this->rozmiar = Obiekt.rozmiar;
    }

    return *this;
}

double& Wektor::operator [] (unsigned indeks)
{
    return this->tablica[indeks];
}

bool operator == (const Wektor& Obiekt_1, const Wektor& Obiekt_2)
{
    if (Obiekt_1.rozmiar != Obiekt_2.rozmiar)
    {
        return false;
    }

    for (int i = 0; i < Obiekt_1.rozmiar; i++)
    {
        if (Obiekt_1.tablica[i] == Obiekt_2.tablica[i])
        {
            if (i == Obiekt_1.rozmiar - 1)
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
}

bool operator != (const Wektor& Obiekt_1, const Wektor& Obiekt_2)
{
    if (Obiekt_1.rozmiar != Obiekt_2.rozmiar)
    {
        return true;
    }

    for (int i = 0; i < Obiekt_1.rozmiar; i++)
    {
        if (Obiekt_1.tablica[i] != Obiekt_2.tablica[i])
        {
            return true;
        }
        else
        {
            if (i == Obiekt_1.rozmiar - 1)
            {
                return false;
            }
        }
    }
}

ostream& operator << (ostream& wyjscie, Wektor& Obiekt)
{
    wyjscie << "[" << Obiekt.rozmiar;
    for (int i = 0; i < Obiekt.rozmiar; i++)
    {
        wyjscie << " " << Obiekt.tablica[i];
    }
    wyjscie << "]";

    return wyjscie;
}

istream& operator >> (istream& wejscie, Wektor& Obiekt)
{
    char nawias_kwadratowy[3];

    wejscie >> nawias_kwadratowy[0];
    wejscie >> Obiekt.rozmiar;

    delete[] Obiekt.tablica;

    Obiekt.tablica = new double[Obiekt.rozmiar];

    for (int i = 0; i < Obiekt.rozmiar; i++)
    {
        wejscie >> Obiekt.tablica[i];
    }
    wejscie >> nawias_kwadratowy[1];

    return wejscie;
}

unsigned Wektor::pobierz_rozmiar()
{
    return this->rozmiar;
}

void Wektor::ustaw_rozmiar(unsigned rozmiar)
{
    double* tablica_tymczasowa = new double[this->rozmiar];
    memcpy(&tablica_tymczasowa[0], &this->tablica[0], this->rozmiar * sizeof(double));

    delete[] this->tablica;
    this->tablica = new double[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        this->tablica[i] = 0;
    }

    if (this->rozmiar > rozmiar)
    {
        memcpy(&this->tablica[0], &tablica_tymczasowa[0], rozmiar * sizeof(double));
    }
    else
    {
        memcpy(&this->tablica[0], &tablica_tymczasowa[0], this->rozmiar * sizeof(double));
    }

    this->rozmiar = rozmiar;

    delete[] tablica_tymczasowa;
    tablica_tymczasowa = NULL;
}

void Wektor::dodaj(double nowa_wartosc)
{
    double* tablica_tymczasowa = new double[this->rozmiar];
    memcpy(&tablica_tymczasowa[0], &this->tablica[0], this->rozmiar * sizeof(double));

    delete[] this->tablica;
    this->tablica = new double[this->rozmiar + 1];

    memcpy(&this->tablica[0], &tablica_tymczasowa[0], this->rozmiar * sizeof(double));
    this->tablica[this->rozmiar] = nowa_wartosc;

    this->rozmiar = this->rozmiar + 1;

    delete[] tablica_tymczasowa;
    tablica_tymczasowa = NULL;
}
