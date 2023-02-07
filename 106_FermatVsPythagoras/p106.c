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

//// https://es.wikipedia.org/wiki/Terna_pitag%C3%B3rica
//// https://en.wikipedia.org/wiki/Pythagorean_triple

#define DEBUG

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
		//char numberUsed[N+1];
		bool *numberUsed = new bool[N+1];
		unsigned long p = N;
		unsigned long nTripletaGood = 0;
		unsigned long c, b, a, m, n;
		memset(numberUsed, false, sizeof(numberUsed));
		m = 1;
		n = 1;

		while (1)
		{
			m = n + 1;
			c = m*m + n*n;

			if (c > N) break;

			while (c <= N)
			{
				a = m*m - n*n;
				b = 2*m*n;

				if (*(numberUsed+a) == false) p--;
				if (*(numberUsed+b) == false) p--;
				if (*(numberUsed+c) == false) p--;

				*(numberUsed+a) = true;
				*(numberUsed+b) = true;
				*(numberUsed+c) = true;

				if((maximo_comun_divisor(a,b) == 1) &&
				(maximo_comun_divisor(b,c) == 1) &&
				(maximo_comun_divisor(a,c) == 1))
				{
//					cout << "	Tripleta primitiva: " << a << " " << b << " " << c << "\n";
					nTripletaGood++;
					unsigned long k = 2;
					unsigned long temp_c = k*c;
					
					while (temp_c <= N) 
					{
						if (*(numberUsed+a*k) == false) p--;
						if (*(numberUsed+b*k) == false) p--;
						if (*(numberUsed+c*k) == false) p--;

						*(numberUsed+a*k) = true;
						*(numberUsed+b*k) = true;
						*(numberUsed+c*k) = true;

						k++;
						temp_c = k*c;
//						cout << "	Tripleta no primitiva: " << a*k << " " << b*k << " " << c*k << "\n";
					}
				}
				m++;
				c = m*m + n*n;
			}
			n++;
		}
		
		//// Print
		cout << nTripletaGood << " " << p << "\n";
	}
  	return(0);
}
