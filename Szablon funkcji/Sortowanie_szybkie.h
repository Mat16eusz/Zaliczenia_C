/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#ifndef SORTOWANIE_SZYBKIE_H
#define SORTOWANIE_SZYBKIE_H

template <typename Typ_0, typename Typ_1> Typ_0 sortowanie_szybkie(Typ_0* tablica, Typ_1 lewy, Typ_1 prawy)
{
    Typ_0 piwot;
    int i, j;
 
    i = (lewy + prawy) / 2;
    piwot = tablica[i];
    tablica[i] = tablica[prawy];
    for (i = j = lewy; i < prawy; i++)
    {
        if (tablica[i] < piwot)
        {
            Typ_0 pomocnik = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = pomocnik;

            j++;
        }
    }
    tablica[prawy] = tablica[j];
    tablica[j] = piwot;
    if (lewy < j - 1)
    {
        sortowanie_szybkie(tablica, lewy, j - 1);
    }
    if (j + 1 < prawy)
    {
        sortowanie_szybkie(tablica, j + 1, prawy);
    }
 
    return *tablica;
}

#endif
