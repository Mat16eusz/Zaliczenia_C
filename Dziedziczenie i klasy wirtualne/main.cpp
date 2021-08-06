/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>

#include "Wektor.h"
#include "Wektor_posortowany.h"
#include "Wektor_3D.h"
#include "Wektor_3D_posortowany.h"

using namespace std;

int main()
{
    /**Test klasy Wektor*/
    Wektor Wektor_1(10);
    for (int i = 0; i < Wektor_1.pobierz_rozmiar(); i++)
    {
        Wektor_1[i] = i;
    }
    Wektor Wektor_2(Wektor_1), Wektor_3;
    Wektor_3 = Wektor_2;
    Wektor_3[2] = 5.5;
    cout << "Wektor_1 = " << Wektor_1 << endl << "Wektor_2 = " << Wektor_2 << endl << "Wektor_3 = " << Wektor_3 << endl;
    if (Wektor_1 == Wektor_2)
    {
        cout << "Wektor_1 == Wektor_2" << endl;
    }
    if (Wektor_1 != Wektor_3)
    {
        cout << "Wektor_1 != Wektor_3" << endl;
    }
    Wektor_1.ustaw_rozmiar(15);
    Wektor_1.dodaj(34.56);
    cout << "Podaj Wektor_2 = ";
    cin  >> Wektor_2;
    cout << "Wektor_1 = " << Wektor_1 << endl << "Wektor_2 = " << Wektor_2 << endl;
    
    /**Test klasy Wektor_posortowany*/
    Wektor_posortowany Wektor_posortowany_1(10);
    for (int i = 0; i < Wektor_posortowany_1.pobierz_rozmiar(); i++)
    {
        Wektor_posortowany_1[0] = i;
    }
    Wektor_posortowany Wektor_posortowany_2(Wektor_posortowany_1);
    Wektor_posortowany Wektor_posortowany_3(Wektor_1);
    cout << "Wektor_posortowany_1 = " << Wektor_posortowany_1 << endl << "Wektor_posortowany_2 = " << Wektor_posortowany_2
         << endl << "Wektor_posortowany_3 = " << Wektor_posortowany_3 << endl;
    if (Wektor_posortowany_1 == Wektor_posortowany_2)
    {
        cout << "Wektor_posortowany_1 == Wektor_posortowany_2" << endl;
    }
    if (Wektor_posortowany_1 != Wektor_posortowany_3)
    {
        cout << "Wektor_posortowany_1 != Wektor_posortowany_3" << endl;
    }
    Wektor_1[0] = Wektor_posortowany_1[7] = Wektor_posortowany_2[3] = Wektor_posortowany_3[4] = 4.5;
    cout << "Wektor_1 = " << Wektor_1 << endl << "Wektor_posortowany_1 = " << Wektor_posortowany_1
         << endl << "Wektor_posortowany_2 = " << Wektor_posortowany_2 << endl << "Wektor_posortowany_3 = " << Wektor_posortowany_3 << endl;
    Wektor_posortowany_3 = Wektor_2;
    Wektor_posortowany_1.ustaw_rozmiar(20);
    Wektor_posortowany_1.dodaj(-12.45);
    cout << "Podaj Wektor_posortowany_2 = ";
    cin  >> Wektor_posortowany_2;
    cout << "Wektor_posortowany_1 = " << Wektor_posortowany_1 << endl << "Wektor_posortowany_2 = " << Wektor_posortowany_2
         << endl << "Wektor_posortowany_3 = " << Wektor_posortowany_3 << endl;
    
    /**Test klasy Wektor_3D*/
    Wektor_3D Wektor_3D_1(3);
    for (int i = 0; i < Wektor_3D_1.pobierz_rozmiar(); i++)
    {
        Wektor_3D_1[i] = i;
    }
    Wektor_3D Wektor_3D_2(Wektor_3D_1);
    Wektor_3D Wektor_3D_3(Wektor_3D_1);
    cout << "Wektor_3D_1 = " << Wektor_3D_1 << endl << "Wektor_3D_2 = " << Wektor_3D_2 << endl << "Wektor_3D_3 = " << Wektor_3D_3 << endl;
    if (Wektor_3D_1 == Wektor_3D_2)
    {
        cout << "Wektor_3D_1 == Wektor_3D_2" << endl;
    }
    if (Wektor_3D_1 != Wektor_3D_3)
    {
        cout << "Wektor_3D_1 != Wektor_3D_3" << endl;
    }
    Wektor_3D_1[0] = Wektor_3D_1[1] = Wektor_3D_2[1] = Wektor_3D_3[0] = 4.5;
    cout << "Wektor_3D_1 = " << Wektor_3D_1 << endl << "Wektor_3D_1 = " << Wektor_3D_1 << endl << "Wektor_3D_2 = " << Wektor_3D_2
         << endl << "Wektor_3D_3 = " << Wektor_3D_3 << endl;
    Wektor_3D_3 = Wektor_3D_2;
    Wektor_3D_1.ustaw_rozmiar(2);
    Wektor_3D_1.dodaj(12.45);
    cout << "Podaj Wektor_3D_2 = ";
    cin  >> Wektor_3D_2;
    cout << "Wektor_3D_1 = " << Wektor_3D_1 << endl << "Wektor_3D_2 = " << Wektor_3D_2 << endl << "Wektor_3D_3 = " << Wektor_3D_3 << endl;
    
    /**Test klasy Wektor_3D_posortowany*/
    Wektor_3D_posortowany Wektor_3D_posortowany_1(3);
    for (int i = 0; i < Wektor_3D_posortowany_1.pobierz_rozmiar(); i++)
    {
        Wektor_3D_posortowany_1[i] = i;
    }
    Wektor_3D_posortowany Wektor_3D_posortowany_2(Wektor_3D_posortowany_1);
    Wektor_3D_posortowany Wektor_3D_posortowany_3(Wektor_3D_posortowany_1);
    cout << "Wektor_3D_posortowany_1 = " << Wektor_3D_posortowany_1 << endl << "Wektor_3D_posortowany_2 = " << Wektor_3D_posortowany_2
         << endl << "Wektor_3D_posortowany_3 = " << Wektor_3D_posortowany_3 << endl;
    if (Wektor_3D_posortowany_1 == Wektor_3D_posortowany_2)
    {
        cout << "Wektor_3D_posortowany_1 == Wektor_3D_posortowany_2" << endl;
    }
    if (Wektor_3D_posortowany_1 != Wektor_3D_posortowany_3)
    {
        cout << "Wektor_3D_posortowany_1 != Wektor_3D_posortowany_3" << endl;
    }
    Wektor_3D_posortowany_1[0] = Wektor_3D_posortowany_1[1] = Wektor_3D_posortowany_2[1] = Wektor_3D_posortowany_3[0] = 4.5;
    cout << "Wektor_3D_posortowany_1 = " << Wektor_3D_posortowany_1 << endl << "Wektor_3D_posortowany_1 = " << Wektor_3D_posortowany_1
         << endl << "Wektor_3D_posortowany_2 = " << Wektor_3D_posortowany_2 << endl << "Wektor_3D_posortowany_3 = " << Wektor_3D_posortowany_3 << endl;
    Wektor_3D_posortowany_3 = Wektor_3D_posortowany_2;
    Wektor_3D_posortowany_1.ustaw_rozmiar(2);
    Wektor_3D_posortowany_1.dodaj(12.45);
    cout << "Podaj Wektor_3D_posortowany_2 = ";
    cin  >> Wektor_3D_posortowany_2;
    cout << "Wektor_3D_posortowany_1 = " << Wektor_3D_posortowany_1 << endl << "Wektor_3D_posortowany_2 = " << Wektor_3D_posortowany_2
         << endl << "Wektor_3D_posortowany_3 = " << Wektor_3D_posortowany_3 << endl;

    return 0;
}
