/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Klasa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Macierz::Macierz()
{
    cout << "Konstruktor domyslny" << endl;
}

Macierz::Macierz(int M, int N)
{
    this->tablica = new float* [M];

    for (int i = 0; i < M; i++)
    {
        this->tablica[i] = new float[N];
    }

    this->M = M;
    this->N = N;
}

Macierz::Macierz(float** tablica, int M, int N)
{
    this->tablica = new float* [M];

    for (int i = 0; i < M; i++)
    {
        this->tablica[i] = new float[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            this->tablica[i][j] = tablica[i][j];
        }
    }

    this->M = M;
    this->N = N;
}

Macierz::Macierz(const Macierz& Obiekt)
{
    M = Obiekt.M;
    N = Obiekt.N;
    /*Kopia p³ytka*/
    /*tablica = Obiekt.tablica;*/

    /*Kopia g³êboka*/
    this->tablica = new float* [M];

    for (int i = 0; i < M; i++)
    {
        this->tablica[i] = new float[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            this->tablica[i][j] = Obiekt.tablica[i][j];
        }
    }
}

Macierz::~Macierz()
{
    for (int i = 0; i < M; i++)
    {
        delete[] this->tablica[i];
    }
    delete[] this->tablica;
    this->tablica = NULL;
}

void Macierz::zmiana_rozmiaru_macierzy(int M, int N)
{
    for (int i = 0; i < this->M; i++)
    {
        delete[] this->tablica[i];
    }
    delete[] this->tablica;
    this->tablica = NULL;

    this->tablica = new float* [M];

    for (int i = 0; i < M; i++)
    {
        this->tablica[i] = new float[N];
    }

    this->M = M;
    this->N = N;
}

int Macierz::ilosc_kolumn()
{
    return this->N;
}

int Macierz::ilosc_wierszy()
{
    return this->M;
}

void Macierz::losowe_wartosci()
{
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            this->tablica[i][j] = (rand() % 11) / 10.0;
        }
    }
}

void Macierz::drukuj_macierz()
{
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            cout.precision(3);
            cout.width(4);
            cout << this->tablica[i][j];
        }
        cout << endl;
    }
}

Macierz& Macierz::operator = (const Macierz& Obiekt)
{
    if (this != &Obiekt)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                tablica[i][j] = Obiekt.tablica[i][j];
            }
        }
    }

    return *this;
}

Macierz Macierz::operator + ()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tablica[i][j] = tablica[i][j] + 5;
        }
    }

    return *this;
}

Macierz Macierz::operator - ()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tablica[i][j] = -tablica[i][j];
        }
    }

    return *this;
}

Macierz Macierz::operator + (Macierz& Obiekt)
{
    Macierz Suma(M, N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Suma.tablica[i][j] = tablica[i][j] + Obiekt.tablica[i][j];
        }
    }

    return Suma;
}

Macierz Macierz::operator - (Macierz& Obiekt)
{
    Macierz Roznica(M, N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Roznica.tablica[i][j] = tablica[i][j] - Obiekt.tablica[i][j];
        }
    }

    return Roznica;
}

Macierz Macierz::operator * (const float liczba)
{
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            tablica[i][j] = tablica[i][j] * liczba;
        }
    }

    return *this;
}

Macierz Macierz::operator * (Macierz& Obiekt)
{
    Macierz Iloczyn(M, N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Iloczyn.tablica[i][j] = tablica[i][j] * Obiekt.tablica[i][j];
        }
    }

    return Iloczyn;
}

Macierz& Macierz::operator += (const Macierz& Obiekt)
{
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            tablica[i][j] += Obiekt.tablica[i][j];
        }
    }

    return *this;
}

Macierz& Macierz::operator -= (const Macierz& Obiekt)
{
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            tablica[i][j] -= Obiekt.tablica[i][j];
        }
    }

    return *this;
}

Macierz& Macierz::operator *= (const float liczba)
{
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            tablica[i][j] *= liczba;
        }
    }

    return *this;
}

Macierz& Macierz::operator *= (const Macierz& Obiekt)
{
    for (int i = 0; i < this->M; i++)
    {
        for (int j = 0; j < this->N; j++)
        {
            tablica[i][j] *= Obiekt.tablica[i][j];
        }
    }

    return *this;
}

bool Macierz::operator == (const Macierz& Obiekt)
{
    unsigned licznik = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tablica[i][j] == Obiekt.tablica[i][j])
            {
                licznik++;
            }
        }
    }

    if (licznik == Obiekt.M * Obiekt.N)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Macierz::operator != (const Macierz& Obiekt)
{
    unsigned licznik = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tablica[i][j] != Obiekt.tablica[i][j])
            {
                licznik++;
            }
        }
    }

    if (licznik != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

istream& operator >> (istream& wejscie, Macierz& Obiekt)
{
    for (int i = 0; i < Obiekt.M; i++)
    {
        for (int j = 0; j < Obiekt.N; j++)
        {
            wejscie >> Obiekt.tablica[i][j];
        }
    }

    return wejscie;
}

ostream& operator << (ostream& wyjscie, Macierz& Obiekt)
{
    for (int i = 0; i < Obiekt.M; i++)
    {
        for (int j = 0; j < Obiekt.N; j++)
        {
            wyjscie << Obiekt.tablica[i][j];
        }
    }

    return wyjscie;
}

float* Macierz::operator [] (int indeks)
{
    return tablica[indeks];
}

Macierz& Macierz::operator () (Macierz& Obiekt_1, Macierz& Obiekt_2)
{
    cout << "Obiekt pierwszy:" << endl;
    Obiekt_1.drukuj_macierz();
    cout << "Obiekt drugi:" << endl;
    Obiekt_2.drukuj_macierz();

    return *this;
}
