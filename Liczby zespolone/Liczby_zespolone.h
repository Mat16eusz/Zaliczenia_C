/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef LICZBY_ZESPOLONE_H
#define LICZBY_ZESPOLONE_H

#include <iostream>

using namespace std;

class Liczby_zespolone
{
private:
    double czesc_rzeczywista;
    double czesc_urojona;

public:
    Liczby_zespolone();
    Liczby_zespolone(double czesc_rzeczywista);
    Liczby_zespolone(double czesc_rzeczywista, double czesc_urojona);

    double wartosc_czesci_rzeczywistej();
    double wartosc_czesci_urojonej();
    double suma_kwadratu();
    double pierwiastek_z_sumy_kwadratu();
    void przypisanie_funkcji_pod_wskaznik();
    double (Liczby_zespolone::* tablica_do_funkcji[4])();
};

class Tablica_liczb_zespolonych
{
private:
    Liczby_zespolone tab_c[10];

public:
    Tablica_liczb_zespolonych();
    friend ostream& operator << (ostream& wyjscie, Tablica_liczb_zespolonych& Obiekt);
};

#endif
