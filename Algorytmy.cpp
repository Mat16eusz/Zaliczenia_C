/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */
 
#include <iostream>
#include <time.h>   // Funkcje obslugi czasu
#include <stdlib.h> // Podstawowe funkcje np. rand() - liczby losowe
#include <vector>   // Vektory
#include <math.h>   // Funkcje matematyczne np. sqrt() - pierwiastek

using namespace std;

// Wyszukiwanie elementu min/max w zbiorze
// Ocena 2
void Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_2()
{
    int a, b, c, d, e;
    cout << "Podaj piec liczb: " << endl;
    cin  >> a >> b >> c >> d >> e;

    //-------------------Najwieksza------------------------------
    if( a >= b && a >= c && a >= d && a >= e )
    {
        cout << "Najwieksza liczba to: " << a << endl;
    }
    else if( b >= a && b >= c && b >= d && b >= e )
    {
        cout << "Najwieksza liczba to: " << b << endl;
    }
    else if( c >= b && c >= a && c >= d && c >= e )
    {
        cout << "Najwieksza liczba to: " << c << endl;
    }
    else if( d >= b && d >= c && d >= a && d >= e )
    {
        cout << "Najwieksza liczba to: " << d << endl;;
    }
    else if( e >= b && e >= c && e >= d && e >= a )
    {
        cout << "Najwieksza liczba to: " << e << endl;
    }
    //-------------------Najmniejsza-----------------------------
    if( a <= b && a <= c && a <= d && a <= e )
    {
        cout << "Najmniejsza liczba to: " << a << endl;
    }
    else if( b <= a && b <= c && b <= d && b <= e )
    {
        cout << "Najmniejsza liczba to: " << b << endl;
    }
    else if( c <= b && c <= a && c <= d && c <= e )
    {
        cout << "Najmniejsza liczba to: " << c << endl;
    }
    else if( d <= b && d <= c && d <= a && d <= e )
    {
        cout << "Najmniejsza liczba to: " << d << endl;;
    }
    else if( e <= b && e <= c && e <= d && e <= a )
    {
        cout << "Najmniejsza liczba to: " << e << endl;
    }
}

// Ocena 3
void Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_3()
{
    srand( time( NULL ) );
    int s_tab_0[ 100 ];
    for( int i = 0; i < 100; i++ )
    {
        s_tab_0[ i ] = rand() % 1000 + 1;
    }

    cout << "Wszystkie liczby w tablicy to: " << endl;
    for( int i = 0; i < 100; i++ )
    {
        cout.width( 4 );
        cout << s_tab_0[ i ] << " ";
    }
    cout << endl;

    for( int x = 1; x < 100; x++ )
	{
		for( int i = x; 0 < i; i-- )
		{
			// Zamiana miejscami, jesli lewa wiêksza od prawej
			if( s_tab_0[ i + 0 ] < s_tab_0[ i - 1 ] )
			{
				int pomocnicza = s_tab_0[ i + 0 ];
				s_tab_0[ i + 0 ] = s_tab_0[ i - 1 ];
				s_tab_0[ i - 1 ] = pomocnicza;
			}
			else
			{
				break;
			}
		}
	}
	cout << "Wartosc min to: " << s_tab_0[ 0 ] << endl << "Wartosc max to: " << s_tab_0[ 99 ] << endl;
}

// Ocena 4
void Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_4()
{
    unsigned N;
    cout << "Podaj liczbe calkowita dodatnia: ";
    cin  >> N;
    int *d_tab_0 = new int [ N ];

    srand( time( NULL ) );
    for( int i = 0; i < N; i++ )
    {
        d_tab_0[ i ] = rand() % 2001 - 1000;
    }

    cout << "Wszystkie liczby w tablicy to: " << endl;
    for( int i = 0; i < N; i++ )
    {
        cout.width( 4 );
        cout << d_tab_0[ i ] << " ";
    }
    cout << endl;

    for( int x = 1; x < N; x++ )
	{
		for( int i = x; 0 < i; i-- )
		{
			// Zamiana miejscami, jesli lewa wiêksza od prawej
			if( d_tab_0[ i + 0 ] < d_tab_0[ i - 1 ] )
			{
				int pomocnicza = d_tab_0[ i + 0 ];
				d_tab_0[ i + 0 ] = d_tab_0[ i - 1 ];
				d_tab_0[ i - 1 ] = pomocnicza;
			}
			else
			{
				break;
			}
		}
	}
	cout << "Wartosc min to: " << d_tab_0[ 0 ] << endl << "Wartosc max to: " << d_tab_0[ N - 1 ] << endl;

	int min_4, max_4;
	int licznik_min_4 = 0;
	int licznik_max_4 = 0;
	min_4 = d_tab_0[ 0 ];
	max_4 = d_tab_0[ N -1 ];

	for( int i = 0; i < N; i++ )
    {
        if( min_4 == d_tab_0[ i ] )
        {
            licznik_min_4++;
        }

        if( max_4 == d_tab_0[ i ] )
        {
            licznik_max_4++;
        }
    }
    cout << "Wartosc min powtorzyla sie " << licznik_min_4 << " razy, a wartosc max " << licznik_max_4 << " razy." << endl;

    delete [] d_tab_0;
    d_tab_0 = NULL;
}

// Ocena 5
void Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_5()
{
    unsigned K;
    cout << "Podaj liczbe calkowita dodatnia: ";
    cin  >> K;
    vector <float> v_tab_0( K );

    srand( time( NULL ) );
    for( int i = 0; i < K; i++ )
    {
        v_tab_0[ i ] = ( rand() % 2001 - 1000 ) / 1000.0;
    }

    cout << "Wszystkie liczby w tablicy to: " << endl;
    for( int i = 0; i < K; i++ )
    {
        cout.width( 6 );
        cout << v_tab_0[ i ] << " ";
    }
    cout << endl;

    for( int x = 0; x < K; x++ )
	{
		for( int i = x; 0 < i; i-- )
		{
			// Zamiana miejscami, jesli lewa wiêksza od prawej
			if( v_tab_0[ i + 0 ] < v_tab_0[ i - 1 ] )
			{
				float pomocnicza = v_tab_0[ i + 0 ];
				v_tab_0[ i + 0 ] = v_tab_0[ i - 1 ];
				v_tab_0[ i - 1 ] = pomocnicza;
			}
			else
			{
				break;
			}
		}
	}
	cout << "Wartosc min to: " << v_tab_0[ 0 ] << endl << "Wartosc max to: " << v_tab_0[ K - 1 ] << endl;

	int min_5, max_5;
	int licznik_min_5 = 0;
	int licznik_max_5 = 0;
	min_5 = v_tab_0[ 0 ];
	max_5 = v_tab_0[ K -1 ];

	for( int i = 0; i < K; i++ )
    {
        if( min_5 == v_tab_0[ i ] )
        {
            licznik_min_5++;
        }

        if( max_5 == v_tab_0[ i ] )
        {
            licznik_max_5++;
        }
    }
    cout << "Wartosc min powtorzyla sie " << licznik_min_5 << " razy, a wartosc max " << licznik_max_5 << " razy." << endl;
}

// NWD/NWW
// Ocena A1
void NWD_NWW_A1()
{
    unsigned a, b;
	
    cout << "Podaj dwie liczby dodatnie: " << endl;
    cin  >> a >> b;

    cout << "Wszystkie dzielniki liczby " << a << " to: ";
    for( int i = 1; i <= a; i++ )
    {
        if( a % i == 0 )
        {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Wszystkie dzielniki liczby " << b << " to: ";
    for( int i = 1; i <= b; i++ )
    {
        if( b % i == 0 )
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Ocena A2
void NWD_NWW_A2()
{
    unsigned a, b;
    unsigned licznik_0 = 0;
    unsigned licznik_1 = 0;
    unsigned liczba_dzielnikow = 0;
	
    cout << "Podaj dwie liczby dodatnie: " << endl;
    cin  >> a >> b;

    cout << "Wszystkie dzielniki liczby " << a << " to: ";
    for( int i = 1; i <= sqrt( a ); i++ )
    {
        if( a % i == 0 )
        {
            if( i == ( a / i ) )
            {
                cout << i << " ";
                licznik_0++;

            }
            else
            {
                cout << i << " " << a / i << " ";
                licznik_1 += 2;
            }
        }
    }
    liczba_dzielnikow = licznik_0 + licznik_1;
    cout << endl << liczba_dzielnikow << endl;

    licznik_0 = 0;
    licznik_1 = 0;
    liczba_dzielnikow = 0;

    cout << "Wszystkie dzielniki liczby " << b << " to: ";
    for( int i = 1; i <= sqrt( b ); i++ )
    {
        if( b % i == 0 )
        {
            if( i == ( b / i ) )
            {
                cout << i << " ";
                licznik_0++;
            }
            else
            {
                cout << i << " " << b / i << " ";
                licznik_1 += 2;
            }
        }
    }
    liczba_dzielnikow = licznik_0 + licznik_1;
    cout << endl << liczba_dzielnikow << endl;
}

// Ocena B1
void NWD_NWW_B1()
{
    unsigned a, b;
    unsigned licznik_0 = 0;
    unsigned licznik_1 = 0;
    unsigned liczba_dzielnikow = 0;
	
    cout << "Podaj dwie liczby dodatnie: " << endl;
    cin  >> a >> b;

    cout << "Wszystkie dzielniki liczby " << a << " to: ";
    for( int i = 1; i <= sqrt( a ); i++ )
    {
        if( a % i == 0 )
        {
            if( i == ( a / i ) )
            {
                cout << i << " ";
                licznik_0++;

            }
            else
            {
                cout << i << " " << a / i << " ";
                licznik_1 += 2;
            }
        }
    }
    liczba_dzielnikow = licznik_0 + licznik_1;
    cout << endl << liczba_dzielnikow << endl;

    licznik_0 = 0;
    licznik_1 = 0;
    liczba_dzielnikow = 0;

    cout << "Wszystkie dzielniki liczby " << b << " to: ";
    for( int i = 1; i <= sqrt( b ); i++ )
    {
        if( b % i == 0 )
        {
            if( i == ( b / i ) )
            {
                cout << i << " ";
                licznik_0++;
            }
            else
            {
                cout << i << " " << b / i << " ";
                licznik_1 += 2;
            }
        }
    }
    liczba_dzielnikow = licznik_0 + licznik_1;
    cout << endl << liczba_dzielnikow << endl;

    // NWD
    int NWD;
    if( a > b )
    {
        for( int i = 1; i < a + 1; i++ )
        {
            if( a % i == 0 && b % i == 0 )
            {
                NWD = i;
            }
        }
    }
    else
    {
        for( int i = 1; i < b + 1; i++ )
        {
            if( a % i == 0 && b % i == 0 )
            {
                NWD = i;
            }
        }
    }
    cout << "NWD z liczby " << a << " i " << b << " wynosi " << NWD << "." << endl;

    // NWW
    int NWW;
    NWW = ( a / NWD ) * b;
    cout << "NWW z liczby " << a << " i " << b << " wynosi " << NWW << "." << endl;
}

// Ocena B2
void NWD_NWW_B2()
{
    unsigned a, b, c;
    unsigned licznik_0 = 0;
    unsigned licznik_1 = 0;
    unsigned liczba_dzielnikow = 0;
	
    cout << "Podaj trzy liczby dodatnie: " << endl;
    cin  >> a >> b >> c;

    int NWD_ab;

    if( a > b )
    {
        for( int i = 1; i < a + 1; i++ )
        {
            if( a % i == 0 && b % i == 0 )
            {
                NWD_ab = i;
            }
        }
    }
    else
    {
        for( int i = 1; i < b + 1; i++ )
        {
            if( a % i == 0 && b % i == 0 )
            {
                NWD_ab = i;
            }
        }
    }

    // NWD z trzech liczb
    int NWD_z_trzech_liczb;
    if( a >= b && a >= c )
    {
        for( int i = 1; i < a + 1; i++ )
        {
            if( a % i == 0 && b % i == 0 && c % i == 0 )
            {
                NWD_z_trzech_liczb = i;
            }
        }
    }
    else if( b >= a && b >= c )
    {
        for( int i = 1; i < b + 1; i++ )
        {
            if( a % i == 0 && b % i == 0 && c % i == 0 )
            {
                NWD_z_trzech_liczb = i;
            }
        }
    }
    else if( c >= a && c >= b )
    {
        for( int i = 1; i < c + 1; i++ )
        {
            if( a % i == 0 && b % i == 0 && c % i == 0 )
            {
                NWD_z_trzech_liczb = i;
            }
        }
    }
    cout << "NWD z liczby " << a << ", " << b << " i " << c << " wynosi " << NWD_z_trzech_liczb << "." << endl;



    // NWW z trzech liczb
    int NWW_ab;
    int NWD_ab_i_c;
    NWW_ab = ( a / NWD_ab ) * b;

    if( NWW_ab > c )
    {
        for( int i = 1; i < NWW_ab + 1; i++ )
        {
            if( NWW_ab % i == 0 && c % i == 0 )
            {
                NWD_ab_i_c = i;
            }
        }
    }
    else
    {
        for( int i = 1; i < c + 1; i++ )
        {
            if( NWW_ab % i == 0 && c % i == 0 )
            {
                NWD_ab_i_c = i;
            }
        }
    }

    int NWW_3;
    NWW_3 = ( NWW_ab / NWD_ab_i_c ) * c;
    cout << "NWW z liczby " << a << ", " << b << " i " << c << " wynosi " << NWW_3 << "." << endl;

}

// Liczby pierwsze
// Ocena 3
bool Czy_pierwsza( int n )
{
    if( n < 2 )
    {
        return false;
    }
    else
    {
        for( int i = 2;  i < n; i++ )
        {
            if( n % i == 0 )
            {
                return false;
            }
        }
        return true;
    }
}

void Liczby_pierwsze_3()
{
    int n;
    cout << "Podaj jedna liczbe: ";
    cin  >> n;

    if( Czy_pierwsza( n ) )
    {
        cout << "JEST PIERWSZA" << endl;
    }
    else
    {
        cout << "NIE JEST PIERWSZA" << endl;
    }
}

// Ocena 4
void Liczby_pierwsze_4()
{
    int S, K;
    cout << "Podaj dwie liczby: ";
    cin  >> S >> K;

    for( int i = S; i <= K; i++ )
    {
        if( Czy_pierwsza( i ) )
        {
            cout << "JEST PIERWSZA" << endl;
        }
        else
        {
            cout << "NIE JEST PIERWSZA" << endl;
        }
    }
}

// Ocena ^
bool Czy_pierwsza_optymalny( int n )
{
    if( n < 2 )
    {
        return false;
    }
    else
    {
        for( int i = 2; i <= sqrt( n ); i++ )
        {
            if ( n % i == 0 )
            {
                return false;
            }
        }
        return true;
    }
}

void Liczby_pierwsze_wyzej()
{
    int S, K;
    cout << "Podaj dwie liczby: ";
    cin  >> S >> K;

    for( int i = S; i <= K; i++ )
    {
        if( Czy_pierwsza_optymalny( i ) )
        {
            cout << "JEST PIERWSZA" << endl;
        }
        else
        {
            cout << "NIE JEST PIERWSZA" << endl;
        }
    }
}

// Faktoryzacja
// Ocena 3
void Faktoryzacja_3()
{
    int n;
    cout << "Podaj liczbe: ";
    cin  >> n;
    cout << "Czynniki pierwsze liczby " << n << " to: ";

    int k = 2;
    while( n > 1 )
    {
        while( n % k == 0 )
        {
            cout << k << " ";   // Jesli nie ma dzielnikow to nie wyswietla nic
            n /= k;
        }
        ++k;
    }
    cout << endl;
}

// Ocena 4
void Faktoryzacja_4()
{
    int S, K, n;
    cout << "Podaj dwie liczby: ";
    cin  >> S >> K;

    for( int i = S; i <= K; i++ )
    {
        cout << "Czynniki pierwsze liczby " << i << " to: ";
        n = i;
        int k = 2;
        while( n > 1 )
        {
            while( n % k == 0 )
            {
                cout << k << " ";   // Jesli nie ma dzielnikow to nie wyswietla nic
                n /= k;
            }
            ++k;
        }
        cout << endl;
    }
}

// Ocena ^
void Faktoryzacja_wyzej()
{
    int S, K, pierwiastek, n;
    cout << "Podaj dwie liczby: ";
    cin  >> S >> K;

    for( int i = S; i <= K; i++ )
    {
        cout << "Czynniki pierwsze liczby " << i << " to: ";
        pierwiastek = sqrt( i );
        n = i;
        int k = 2;

        while( n > 1 && k <= pierwiastek )
        {
            while( n % k == 0 )
            {
                cout << k << " ";   // Jesli nie ma dzielnikow to nie wyswietla nic
                n /= k;
            }
            ++k;
        }

        if( n > 1 )
        {
            cout << n << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Wyszukiwanie elementu min/max w zbiorze
    // Ocena 2
    Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_2();
    // Ocena 3
    Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_3();
    // Ocena 4
    Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_4();
    // Ocena 5
    Wyszukiwanie_elementu_min_max_w_zbiorze_Ocena_5();

    // NWD/NWW
    // Ocena A1
    NWD_NWW_A1();
    // Ocena A2
    NWD_NWW_A2();
    // Ocena B1
    NWD_NWW_B1();
    // Ocena B2
    NWD_NWW_B2();

    // Liczby pierwsze
    // Ocena 3
    Liczby_pierwsze_3();
    // Ocena 4
    Liczby_pierwsze_4();
    // Ocena ^
    Liczby_pierwsze_wyzej();

    // Faktoryzacja
    // Ocena 3
    Faktoryzacja_3();
    // Ocena 4
    Faktoryzacja_4();
    // Ocena ^
    Faktoryzacja_wyzej();

    return 0;
}
