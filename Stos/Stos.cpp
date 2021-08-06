/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>

#include "Stos.h"

using namespace std;

int main()
{
    Stos<int> Stos_1;

    if (Stos_1.czy_pusty())
    {
        cout << "Stos jest pusty!" << endl;
    }
    else
    {
        cout << "Stos nie jest pusty!" << endl;
    }

    Stos_1.poloz_na_stos(0);
    Stos_1.poloz_na_stos(1);
    Stos_1.poloz_na_stos(2);
    Stos_1.poloz_na_stos(3);
    Stos_1.poloz_na_stos(4);

    if (Stos_1.czy_pusty())
    {
        cout << "Stos jest pusty!" << endl;
    }
    else
    {
        cout << "Stos nie jest pusty!" << endl;
    }

    try
    {
        cout << "Wartosc zdejmowana ze stosu to " << Stos_1.zdejmij_z_wierzchu() << endl;
    }
    catch (unsigned rozmiar)
    {
        cout << "Stos jest pusty!" << endl;
    }
    try
    {
        cout << "Wartosc zdejmowana ze stosu to " << Stos_1.zdejmij_z_wierzchu() << endl;
    }
    catch (unsigned rozmiar)
    {
        cout << "Stos jest pusty!" << endl;
    }
    
    Stos_1.oproznij();
    
    try
    {
        cout << "Wartosc zdejmowana ze stosu to " << Stos_1.zdejmij_z_wierzchu() << endl;
    }
    catch (unsigned rozmiar)
    {
        cout << "Stos jest pusty!" << endl;
    }
    try
    {
        cout << "Wartosc zdejmowana ze stosu to " << Stos_1.zdejmij_z_wierzchu() << endl;
    }
    catch (unsigned rozmiar)
    {
        cout << "Stos jest pusty!" << endl;
    }
    try
    {
        cout << "Wartosc zdejmowana ze stosu to " << Stos_1.zdejmij_z_wierzchu() << endl;
    }
    catch (unsigned rozmiar)
    {
        cout << "Stos jest pusty!" << endl;
    }

    try
    {
        cout << "Wartosc zdejmowana ze stosu to " << Stos_1.zdejmij_z_wierzchu() << endl;
    }
    catch (unsigned rozmiar)
    {
        cout << "Stos jest pusty!" << endl;
    }

    return 0;
}
