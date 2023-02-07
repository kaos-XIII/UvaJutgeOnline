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
		unsigned long x = 3, y = 4, z = 5;
		memset(numberUsed, false, sizeof(numberUsed));
		
		//// Print
		cout << nTripletaGood << " " << p << "\n";
	}
  	return(0);
}
