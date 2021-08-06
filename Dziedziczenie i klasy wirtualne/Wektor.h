/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef WEKTOR_H
#define WEKTOR_H

#include <iostream>

class Wektor
{
protected:
    unsigned rozmiar;
    double* tablica;

public:
    Wektor();
    Wektor(unsigned rozmiar);
    Wektor(unsigned rozmiar, double* tablica);
    Wektor(const Wektor& Obiekt);
    ~Wektor();

    Wektor& operator = (const Wektor& Obiekt);
    double& operator [] (unsigned indeks);
    friend bool operator == (const Wektor& Obiekt_1, const Wektor& Obiekt_2);
    friend bool operator != (const Wektor& Obiekt_1, const Wektor& Obiekt_2);
    friend std::ostream& operator << (std::ostream& wyjscie, Wektor& Obiekt);
    friend std::istream& operator >> (std::istream& wejscie, Wektor& Obiekt);

    unsigned pobierz_rozmiar();
    void ustaw_rozmiar(unsigned rozmiar);
    void dodaj(double nowa_wartosc);
};

bool operator == (const Wektor& Obiekt_1, const Wektor& Obiekt_2);
bool operator != (const Wektor& Obiekt_1, const Wektor& Obiekt_2);

#endif
