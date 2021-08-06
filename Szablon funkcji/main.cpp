/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Sortowanie_szybkie.h"
#include "Sortowanie_przez_wybieranie.h"

using namespace std;

class Complex
{
    
public:
    float czesc_rzeczywista;
    float czesc_urojona;

    Complex(double czesc_rzeczywista = 0, double czesc_urojona = 0);
    
    friend bool operator < (Complex& Obiekt_0, Complex& Obiekt_1);
};

Complex::Complex(double czesc_rzeczywista, double czesc_urojona)
{
    this->czesc_rzeczywista = czesc_rzeczywista;
    this->czesc_urojona = czesc_urojona;
}

bool operator < (Complex& Obiekt_0, Complex& Obiekt_1)
{
    if (sqrt(pow(Obiekt_0.czesc_rzeczywista, 2) + pow(Obiekt_0.czesc_urojona, 2)) < sqrt(pow(Obiekt_1.czesc_rzeczywista, 2) + pow(Obiekt_1.czesc_urojona, 2)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(NULL));

    const int maly_rozmiar = 10;
    int rozmiar;
    
    int tablica_statyczna_0[maly_rozmiar] = { 0, 9, 4, 2, 3, 6, 8, -5, -100, 100 };
    int tablica_statyczna_1[maly_rozmiar] = { 0, 9, 4, 2, 3, 6, 8, -5, -100, 100 };
    int* tablica_int_0 = NULL;
    int* tablica_int_1 = NULL;
    double* tablica_double_0 = NULL;
    double* tablica_double_1 = NULL;
    Complex* tablica_Complex_0 = NULL;
    Complex* tablica_Complex_1 = NULL;

    cout << "Podaj rozmiar tablicy: ";
    cin  >> rozmiar;

    tablica_int_0 = new int[rozmiar];
    tablica_int_1 = new int[rozmiar];
    tablica_double_0 = new double[rozmiar];
    tablica_double_1 = new double[rozmiar];
    tablica_Complex_0 = new Complex[rozmiar];
    tablica_Complex_1 = new Complex[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        int losowa = rand() % 1001;
        tablica_int_0[i] = losowa;
        tablica_int_1[i] = losowa;
    }
    for (int i = 0; i < rozmiar; i++)
    {
        double losowa = (rand() % 1001) / 1000.0;
        tablica_double_0[i] = losowa;
        tablica_double_1[i] = losowa;
    }
    for (int i = 0; i < rozmiar; i++)
    {
        tablica_Complex_0[i].czesc_rzeczywista = rand();
        tablica_Complex_0[i].czesc_urojona = rand();
        tablica_Complex_1[i].czesc_rzeczywista = tablica_Complex_0[i].czesc_rzeczywista;
        tablica_Complex_1[i].czesc_urojona = tablica_Complex_0[i].czesc_urojona;
    }
    

    auto start = chrono::steady_clock::now();
    sortowanie_szybkie(tablica_statyczna_0, 0, maly_rozmiar - 1);
    auto stop = chrono::steady_clock::now();
    chrono::duration<double> uplynelo_sekund = stop - start;
    cout << "Czas sortowania szybkiego tablicy statycznej int o rozmiarze " << maly_rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;

    start = chrono::steady_clock::now();
    sortowanie_przez_wybieranie(tablica_statyczna_1, maly_rozmiar);
    stop = chrono::steady_clock::now();
    uplynelo_sekund = stop - start;
    cout << "Czas sortowania przez wybieranie tablicy statycznej int o rozmiarze " << maly_rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;


    start = chrono::steady_clock::now();
    sortowanie_szybkie(tablica_int_0, 0, rozmiar - 1);
    stop = chrono::steady_clock::now();
    uplynelo_sekund = stop - start;
    cout << "Czas sortowania szybkiego tablicy dynamicznej int o rozmiarze " << rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;

    start = chrono::steady_clock::now();
    sortowanie_przez_wybieranie(tablica_int_1, rozmiar);
    stop = chrono::steady_clock::now();
    uplynelo_sekund = stop - start;
    cout << "Czas sortowania przez wybieranie tablicy dynamicznej int o rozmiarze " << rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;


    start = chrono::steady_clock::now();
    sortowanie_szybkie(tablica_double_0, 0, rozmiar - 1);
    stop = chrono::steady_clock::now();
    uplynelo_sekund = stop - start;
    cout << "Czas sortowania szybkiego tablicy dynamicznej double o rozmiarze " << rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;

    start = chrono::steady_clock::now();
    sortowanie_przez_wybieranie(tablica_double_1, rozmiar);
    stop = chrono::steady_clock::now();
    uplynelo_sekund = stop - start;
    cout << "Czas sortowania przez wybieranie tablicy dynamicznej double o rozmiarze " << rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;


    start = chrono::steady_clock::now();
    sortowanie_szybkie(tablica_Complex_0, 0, rozmiar - 1);
    stop = chrono::steady_clock::now();
    uplynelo_sekund = stop - start;
    cout << "Czas sortowania przez wybieranie tablicy dynamicznej Complex o rozmiarze " << rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;

    start = chrono::steady_clock::now();
    sortowanie_przez_wybieranie(tablica_Complex_1, rozmiar);
    stop = chrono::steady_clock::now();
    uplynelo_sekund = stop - start;
    cout << "Czas sortowania przez wybieranie tablicy dynamicznej Complex o rozmiarze " << rozmiar << " wynosi: " << uplynelo_sekund.count() / 0.001 << "ms." << endl;


    delete[] tablica_int_0;
    tablica_int_0 = NULL;
    delete[] tablica_int_1;
    tablica_int_1 = NULL;
    delete[] tablica_double_0;
    tablica_double_0 = NULL;
    delete[] tablica_double_1;
    tablica_double_1 = NULL;
    delete[] tablica_Complex_0;
    tablica_Complex_0 = NULL;
    delete[] tablica_Complex_1;
    tablica_Complex_1 = NULL;

    return 0;
}
