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

unsigned long maximo_comun_divisor(unsigned long a, unsigned long b) {
    if (b == 0) return a;
    return maximo_comun_divisor_recursivo(b, a % b);
}

int main() 
{
	unsigned long N = 0;

	while ( scanf ("%i %i %i", &N) != EOF ) 
	{

	}
	
	//// Print

  	return(0);
}
