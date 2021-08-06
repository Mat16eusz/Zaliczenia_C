/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef KLASA_H
#define KLASA_H

#include <iostream>

class Macierz
{
private:
    int M, N;
    float** tablica;

public:
    Macierz();
    Macierz(int M, int N);
    Macierz(float** tablica, int M, int N);
    Macierz(const Macierz& Obiekt);
    ~Macierz();

    void zmiana_rozmiaru_macierzy(int M, int N);
    int ilosc_kolumn();
    int ilosc_wierszy();
    void losowe_wartosci();
    void drukuj_macierz();

    Macierz& operator = (const Macierz& Obiekt);
    Macierz operator + ();
    Macierz operator - ();
    Macierz operator + (Macierz& Obiekt);
    Macierz operator - (Macierz& Obiekt);
    Macierz operator * (const float liczba);
    Macierz operator * (Macierz& Obiekt);
    Macierz& operator += (const Macierz& Obiekt);
    Macierz& operator -= (const Macierz& Obiekt);
    Macierz& operator *= (const float liczba);
    Macierz& operator *= (const Macierz& Obiekt);
    bool operator == (const Macierz& Obiekt);
    bool operator != (const Macierz& Obiekt);
    friend std::istream& operator >> (std::istream& wejscie, Macierz& Obiekt);
    friend std::ostream& operator << (std::ostream& wyjscie, Macierz& Obiekt);
    float* operator [] (int indeks);
    Macierz& operator () (Macierz& Obiekt_1, Macierz& Obiekt_2);
};

#endif
