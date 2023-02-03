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

int main() 
{
	int skyLine[10000];
	memset(skyLine, 0, sizeof(skyLine));

	int xInicial=0, altura=0, xFinal=0, xFinalMax=0, xInicialMin=0;
	
	while ( scanf ("%i %i %i", &xInicial, &altura, &xFinal) != EOF ) 
	{
		if (xInicialMin > xInicial) xInicialMin = xInicial; ///////////

		if (xFinalMax < xFinal) xFinalMax = xFinal;

		for (int i = xInicial; i < xFinal; i++)
		{
			if (skyLine[i] < altura) skyLine[i] = altura;
		}

	}
	
	//// Print
	for (int i = xInicialMin+1; i <= xFinalMax; i++)
	{
		if (skyLine[i] != skyLine[i-1])
		{
			cout << i << " " << skyLine[i];

			if (i < xFinalMax)
				cout << " ";
		}
	}
	cout << "\n";

  	return(0);
}
