/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef SORTOWANIE_PRZEZ_WYBIERANIE_H
#define SORTOWANIE_PRZEZ_WYBIERANIE_H

template <typename Typ_0, typename Typ_1> Typ_0 sortowanie_przez_wybieranie(Typ_0* tablica, Typ_1 rozmiar)
{
    for (int i = 0; i < rozmiar - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < rozmiar; j++)
        {
            if (tablica[j] < tablica[min])
            {
                min = j;
            }
        }
        Typ_0 pomocnik = tablica[i];
        tablica[i] = tablica[min];
        tablica[min] = pomocnik;
    }

    return *tablica;
}

#endif
