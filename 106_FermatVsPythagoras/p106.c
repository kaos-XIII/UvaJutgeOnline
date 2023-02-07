#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

//#define DEBUG

unsigned long maximo_comun_divisor(unsigned long a, unsigned long b) 
{
    if (b == 0) return a;
    return maximo_comun_divisor(b, a % b);
}

int main() 
{
	unsigned long N = 0;

	while ( scanf ("%i", &N) != EOF ) 
	{
		char numberUsed[N+1];
		unsigned long p = N;
		unsigned long nTripletaGood = 0;
		unsigned long x = 3, y = 4, z = 5;
		memset(numberUsed, 0, sizeof(numberUsed));
		
		for (x = 3; (x*x) < ( (N*N)-( (x+1)*(x+1) ) ); x++)
		{
			for (y = x+1; (y*y) < ( (N*N)-( (3)*(3) ) ) ; y++)
			{	
				z = sqrt( (x*x)+(y*y) );

				if ( (z <= N) && ( (x*x) + (y*y) == (z*z) ) )
				{
					if ( ((x+1 == y) || (maximo_comun_divisor(x, y) == 1)) && 
					(maximo_comun_divisor(x, z) == 1) && 
					((y+1 == z) || (maximo_comun_divisor(y, z) == 1)) )
					{
						++nTripletaGood;
#ifdef DEBUG			
						cout << "	Para N("<<N<<")->Tripleta valida(Prima): " << x << " " << y << " " << z << "\n";
					}
					else cout << "	Para N("<<N<<")->Tripleta valida:        " << x << " " << y << " " << z << "\n";
#else
					}
#endif
					if (numberUsed[x] == 0) p = --p;
					if (numberUsed[y] == 0) p = --p;
					if (numberUsed[z] == 0) p = --p;
					
					numberUsed[x] = 1;	
					numberUsed[y] = 1;
					numberUsed[z] = 1;
				}
			}
		}		
		//// Print
		cout << nTripletaGood << " " << p << "\n";
	}
  	return(0);
}
