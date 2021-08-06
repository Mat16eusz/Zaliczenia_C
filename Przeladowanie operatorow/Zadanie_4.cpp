/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>
#include "Klasa.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int M, N, indeks_M, indeks_N;
   
    /*Zadanie bazowe*/
    cout << "Zadanie bazowe" << endl;
    cout << "Podaj dwie liczby calkowite dodatnie:" << endl;
    cin >> N >> M;

    float** tablica = new float* [M];
    for (int i = 0; i < M; i++)
    {
        tablica[i] = new float[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tablica[i][j] = i * j;
        }
    }

    Macierz Przyklad_1;
    Macierz Przyklad_2(M, N);
    Macierz Przyklad_3(tablica, M, N);
    Przyklad_3.losowe_wartosci();
    Przyklad_3.drukuj_macierz();
    cout << "Konstruktor kopiujacy" << endl;
    Macierz Przyklad_4(Przyklad_3); /*Konstruktor kopiujacy. Zapis Macierz Przyklad_4 = Przyklad_3; a Macierz Przyklad_4(Przyklad_3); jest równoważny*/
    Przyklad_4.drukuj_macierz();

    for (int i = 0; i < M; i++)
    {
        delete[] tablica[i];
    }
    delete[] tablica;

    cout << "Podaj dwie liczby calkowite dodatnie:" << endl;
    cin >> N >> M;

    tablica = new float* [M];
    for (int i = 0; i < M; i++)
    {
        tablica[i] = new float[N];
    }

    Przyklad_3.zmiana_rozmiaru_macierzy(M, N);
    Przyklad_3.losowe_wartosci();
    Przyklad_3.drukuj_macierz();
    cout << "Ilosc kolumn wynosi " << Przyklad_3.ilosc_kolumn() << endl;
    cout << "Ilosc wierszy wynosi " << Przyklad_3.ilosc_wierszy() << endl;

    /*Przykłady przeciążania operatorów*/
    for (int i = 0; i < M; i++)
    {
        delete[] tablica[i];
    }
    delete[] tablica;

    cout << endl << "Przyklady przeciazania operatorow" << endl;
    cout << "Podaj dwie liczby calkowite dodatnie:" << endl;
    cin >> N >> M;

    tablica = new float* [M];
    for (int i = 0; i < M; i++)
    {
        tablica[i] = new float[N];
    }

    cout << "Macierz, ktora zostanie wykorzystana do wszystkich prezentowanych operacji" << endl;
    Macierz Przyklad_5(tablica, M, N);
    Przyklad_5.losowe_wartosci();
    Przyklad_5.drukuj_macierz();
    Macierz Przyklad_6(M, N);
    Przyklad_6 = Przyklad_5;
    cout << "Macierz po przypisaniu wartosci:" << endl;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz przeciazony jednoargumentowym plusem (dodana wartosc 5 do kazdej liczby w macierzy):" << endl;
    +Przyklad_6;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz przeciazony jednoargumentowym minusem:" << endl;
    -Przyklad_6;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz przeciazony jednoargumentowym minusem:" << endl;
    -Przyklad_6;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po dodaniu drugiej macierzy:" << endl;
    Przyklad_6 = Przyklad_6 + Przyklad_5;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po odjeciu drugiej macierzy:" << endl;
    Przyklad_6 = Przyklad_6 - Przyklad_5;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po pomnozeniu przez liczbe:" << endl;
    Przyklad_6 * 10;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po pomnozeniu przez druga macierz:" << endl;
    Przyklad_6 = Przyklad_6 * Przyklad_5;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po dodaniu drugiej macierzy:" << endl;
    Przyklad_6 += Przyklad_5;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po odjeciu drugiej macierzy:" << endl;
    Przyklad_6 -= Przyklad_5;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po pomnozeniu przez liczbe:" << endl;
    Przyklad_6 *= 2;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po pomnozeniu przez druga macierz:" << endl;
    Przyklad_6 *= Przyklad_5;
    Przyklad_6.drukuj_macierz();
    cout << "Macierz po porownaniu dwoch macierzy(porownanie tej samej macierzy):" << endl;
    if (Przyklad_6 == Przyklad_6)
    {
        cout << "Macierze sa identyczne" << endl;
    }
    else
    {
        cout << "Macierze roznia sie od siebie" << endl;
    }
    cout << "Macierz po porownaniu dwoch macierzy:" << endl;
    if (Przyklad_6 != Przyklad_5)
    {
        cout << "Macierze roznia sie od siebie" << endl;
    }
    else
    {
        cout << "Macierze sa identyczne" << endl;
    }
    cout << "Wprowadz wartosci macierzy:" << endl;
    cin >> Przyklad_6;
    cout << "Macierz po wprowadzeniu wartosci:" << endl;
    cout << Przyklad_6 << endl;;
    cout << "Macierz po wyswietleniu konkretnego indeksu:" << endl;
    cout << "Podaj indeks M: ";
    cin  >> indeks_M;
    cout << "Podaj indeks N: ";
    cin >> indeks_N;
    if (indeks_M >= M || indeks_N >= N)
    {
        cout << "Podany indeks nie istnieje!" << endl;
    }
    else
    {
        cout << "Wartosc spod indeksu wynosi: " << Przyklad_6[indeks_M][indeks_N] << endl;
    }
    cout << "Operator wywolania:" << endl;
    Przyklad_6(Przyklad_6, Przyklad_5);

    for (int i = 0; i < M; i++)
    {
        delete[] tablica[i];
    }
    delete[] tablica;
    tablica = NULL;

    return 0;
}
