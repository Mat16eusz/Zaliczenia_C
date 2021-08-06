/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Liczby_zespolone.h"
#include <iostream>
#include <cmath>

using namespace std;

Liczby_zespolone::Liczby_zespolone()
{
	this->czesc_rzeczywista = 0.0;
	this->czesc_urojona = 0.0;
	
	przypisanie_funkcji_pod_wskaznik();
}

Liczby_zespolone::Liczby_zespolone(double czesc_rzeczywista)
{
	this->czesc_rzeczywista = czesc_rzeczywista;
	this->czesc_urojona = 0.0;

	przypisanie_funkcji_pod_wskaznik();
}

Liczby_zespolone::Liczby_zespolone(double czesc_rzeczywista, double czesc_urojona)
{
	this->czesc_rzeczywista = czesc_rzeczywista;
	this->czesc_urojona = czesc_urojona;

	przypisanie_funkcji_pod_wskaznik();
}

double Liczby_zespolone::wartosc_czesci_rzeczywistej()
{
	return czesc_rzeczywista;
}

double Liczby_zespolone::wartosc_czesci_urojonej()
{
	return czesc_urojona;
}

double Liczby_zespolone::suma_kwadratu()
{
	return (czesc_rzeczywista * czesc_rzeczywista) + (czesc_urojona * czesc_urojona);
}

double Liczby_zespolone::pierwiastek_z_sumy_kwadratu()
{
	return sqrt((czesc_rzeczywista * czesc_rzeczywista) + (czesc_urojona * czesc_urojona));
}

void Liczby_zespolone::przypisanie_funkcji_pod_wskaznik()
{
	tablica_do_funkcji[0] = &Liczby_zespolone::wartosc_czesci_rzeczywistej;
	tablica_do_funkcji[1] = &Liczby_zespolone::wartosc_czesci_urojonej;
	tablica_do_funkcji[2] = &Liczby_zespolone::suma_kwadratu;
	tablica_do_funkcji[3] = &Liczby_zespolone::pierwiastek_z_sumy_kwadratu;
}

Tablica_liczb_zespolonych::Tablica_liczb_zespolonych()
{
	for (int i = 0; i < 10; i++)
	{
		tab_c[i] = Liczby_zespolone(i, i);
	}
}

ostream& operator << (ostream& wyjscie, Tablica_liczb_zespolonych& Obiekt)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			wyjscie << (Obiekt.tab_c[i].*(Obiekt.tab_c[i].tablica_do_funkcji[j]))() << endl;
		}
	}

	return wyjscie;
}