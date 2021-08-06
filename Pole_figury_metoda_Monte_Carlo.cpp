/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

float F( float x )
{
	//return 0.5 * x + 0.5;
	//return x * x + 1;
	//return ( x * x * x ) - ( 2 * x * x ) + 3;
	return x * x * x * x - x * x * x - x * x + 3;
}

int main()
{
	srand( time( NULL ) );

	unsigned ile_prob = 10000000;
	unsigned ile_trafien = 0;

	for( int i = 0; i < ile_prob; i++ )
	{
		float x = ( rand() % 2001 ) / 1000.0 - 1.0;
		float y = ( rand() % 4001 ) / 1000.0;

		if( y <= F( x ) )
		{
			ile_trafien++;
		}
	}

	float prawdopodobienstwo = ( float )ile_trafien / ile_prob;
	cout << "Prawdopodobienstwo: " << prawdopodobienstwo << endl;

	float pole = ( 2 * 4 ) * prawdopodobienstwo;
	cout << "Pole: " << pole << endl;

	return 0;
}
