/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>

using namespace std;

/**
 * Tworzenie trójkąta Pascala
 * 
 * @param int rozmiar_tablicy: rozmiar tablicy
 * @return int: zwraca utworzoną tablicę
 */
int** trojkat_Pascala(int rozmiar_tablicy)
{
    /*Deklaracja tablicy dynamicznej dwuwymiarowej*/
    int** tablica = new int*[rozmiar_tablicy];
    
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        tablica[i] = new int[rozmiar_tablicy];
    }

    /*Zerowanie tablicy dynamicznej dwuwymiarowej*/
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        for (int j = 0; j < rozmiar_tablicy; j++)
        {
            tablica[i][j] = 0;
        }
    }

    /*Obliczanie wartości trójkąta Pascala*/
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        tablica[i][0] = tablica[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            tablica[i][j] = tablica[i - 1][j - 1] + tablica[i - 1][j];
        }
    }

    /*Wyświetlanie trójkąta Pascala*/
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        cout.width(3 * (rozmiar_tablicy - i));
        cout << "";
        for (int j = 0; j < rozmiar_tablicy; j++)
        {
            cout.width(6);
            if (tablica[i][j] == 0)
            {
                cout << "";
            }
            else
            {
                cout << tablica[i][j];
            }
        }
        cout << endl;
    }

    /*Zwalnianie tablicy dynamicznej dwuwymiarowej*/
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        delete [] tablica[i];
    }
    delete [] tablica;
    tablica = NULL;

    return tablica;
}

int main()
{
    int rozmiar_tablicy;

    cout << "Podaj rozmiar tablicy: ";
    cin  >> rozmiar_tablicy;

    trojkat_Pascala(rozmiar_tablicy);

    return 0;
}
