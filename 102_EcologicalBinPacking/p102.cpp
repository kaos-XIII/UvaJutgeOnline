#include <cstdio>
#include <algorithm>
#include <string.h>
 #include <iostream> 
#define long long LL

using namespace std;

/*

Sample Input

1 2 3 4 5 6 7 8 9
5 10 5 20 10 5 10 20 10

Sample Output

BCG 30
CBG 50

n < 2^31

Orden de entrada: brown, green, and clear bottles

*/

int main() 
{
	int b1, b2, b3;
	int g1, g2, g3;
	int c1, c2, c3;

	string orden;
	orden[0] = ' ';
	orden[1] = ' ';
	orden[2] = ' ';

	int op[6];

	while ( scanf ("%i %i %i %i %i %i %i %i %i", &b1, &g1, &c1, 
												 &b2, &g2, &c2, 
												 &b3, &g3, &c3) != EOF ) 
	{
		int min = 0;
		orden = "BCG";

		op[0] = b2 + b3 + c1 + c3 + g1 + g2;
		op[1] = b2 + b3 + g1 + g3 + c1 + c2;
		
		if ( op[0] > op[1] ) 
		{
			min = 1;
			orden = "BGC";		
		}

		op[2] = c2 + c3 + b1 + b3 + g1 + g2;
		
		if ( op[min] > op[2] ) 
		{
			min = 2;
			orden = "CBG";
		}

		op[3] = c2 + c3 + g1 + g3 + b1 + b2;
		
		if ( op[min] > op[3] ) 
		{
			min = 3;
			orden = "CGB";
		}

		op[4] = g2 + g3 + b1 + b3 + c1 + c2;

		if ( op[min] > op[4] )
		{
			min = 4;
			orden = "GBC";
		}

		op[5] = g2 + g3 + c1 + c3 + b1 + b2;

		if ( op[min] > op[5] ) 
		{
			min = 5;
			orden = "GCB";
		}
/*
		switch(min){

			case 0:
				orden[0] = 'B';
				orden[1] = 'C';
				orden[2] = 'G';
				break;
			case 1:
				orden[0] = 'B';
				orden[1] = 'G';
				orden[2] = 'C';
				break;
			case 2:
				orden[0] = 'C';
				orden[1] = 'B';
				orden[2] = 'G';
				break;
			case 3:
				orden[0] = 'C';
				orden[1] = 'G';
				orden[2] = 'B';
				break;
			case 4:
				orden[0] = 'G';
				orden[1] = 'B';
				orden[2] = 'C';
				break;
			case 5:
				orden[0] = 'G';
				orden[1] = 'C';
				orden[2] = 'B';
				break;
			default:
				orden[0] = 'G';
				orden[1] = 'C';
				orden[2] = 'B';
				break;

		}
*/
		// IMPRIMIR RESULTADO.
		//cout << orden[0] << orden[1] << orden[2] << " " << cantidad_mov << "\n";
		cout << orden << " " << op[min] << "\n";
	}
  	return(0);
}
