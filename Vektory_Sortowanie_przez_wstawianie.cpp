/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>
#include <vector>

using namespace std;

void Wypelnij_vektor_poczatkowo( vector<int> *vTab )
{
    cout << "Podaj dwie liczby ( int ): " << endl;
	for( int i = 0; i < 2; i++ )
	{
	    /*
		int x;
		cin >> x;
		vTab->push_back( x );
		*/
		cin >> (*vTab)[ i ];
	}
}

void Sortuj_wstawianie( vector<int> *vTab )
{
	for( int x = 1; x < vTab->size(); x++ )
	{
		for( int i = x; 0 < i; i-- )
		{
			/** Zamiana miejscami, jesli lewa większa od prawej */
			if( (*vTab)[ i + 0 ] < (*vTab)[ i - 1 ] )
			{
				int pomocnicza = (*vTab)[ i + 0 ];
				(*vTab)[ i + 0 ] = (*vTab)[ i - 1 ];
				(*vTab)[ i - 1 ] = pomocnicza;
			}
			else
			{
				break;
			}
		}
	}
}

void Wczytaj_kolejna_liczbe( vector<int> *vTab )
{
    int x;
    cout << "Podaj kolejna liczbe ( int ): ";
    cin  >> x;
    vTab->push_back( x );
}

void Drukowanie_vektora( const vector<int> *vTab )
{
	for( int i = 0; i < vTab->size(); i++ )
	{
        cout.width( 8 );
		cout << (*vTab)[ i ] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vTab( 2 );
	// Dwie liczby ( poczatkowe wartosci )
	Wypelnij_vektor_poczatkowo( &vTab );
	Sortuj_wstawianie( &vTab );
	Drukowanie_vektora( &vTab );
	// Kolejna ( trzy liczby )
	Wczytaj_kolejna_liczbe( &vTab );
	Sortuj_wstawianie( &vTab );
	Drukowanie_vektora( &vTab );
	// Kolejna ( cztery liczby )
	Wczytaj_kolejna_liczbe( &vTab );
	Sortuj_wstawianie( &vTab );
	Drukowanie_vektora( &vTab );

	return 0;
}
