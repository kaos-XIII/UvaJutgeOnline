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
//#include <stdlib.h>     //for using the function sleep
#include <unistd.h>
using namespace std;

#define DEBUG

int main()
{
	unsigned long heightInitialCat = 0;
	unsigned long nCatsWorking = 0;


	while ( scanf ("%i %i", &heightInitialCat, &nCatsWorking) != EOF )
	{
		if((heightInitialCat == 0) && (nCatsWorking == 0)) break;

        unsigned long nCatsNotWorking = 0;
        unsigned long stackOfCats = nCatsWorking;

        bool resultOk = false;
        unsigned long N = 2;

        unsigned long actualHeight = 1;

        unsigned long copy_nCatsWorking = nCatsWorking;

        /*
        Caso especial en que nCatsWorking == 1
        */
        if (nCatsWorking == 1)
        {
            unsigned long actualHeight = heightInitialCat;
            N = 1;

            while (actualHeight != 1)
            {
                //cout << "actualHeight: " << actualHeight << "\n";
                stackOfCats = stackOfCats + actualHeight;
                actualHeight = ( actualHeight / (N+1) );
                //if ( actualHeight != 1 )
                nCatsNotWorking++;
                //sleep(1);
            }
            resultOk = true;
        }
        /*
        Resto de casos
        */
        while (!resultOk)
        {
            if( ( (copy_nCatsWorking % N) == 0) && ( (copy_nCatsWorking / N) != 1) )
            {
                copy_nCatsWorking = copy_nCatsWorking / N;
                nCatsNotWorking = nCatsNotWorking + copy_nCatsWorking;
                actualHeight = actualHeight * (N + 1);
                stackOfCats = stackOfCats + (actualHeight * copy_nCatsWorking);
                //cout << "actualHeight: " << actualHeight << "\n";
                //cout << "stackOfCats: " << actualHeight << "\n";

            }
            else if ( ( (copy_nCatsWorking % N) == 0 ) && ( (copy_nCatsWorking / N) == 1) && ((actualHeight * (N + 1)) == heightInitialCat) )
            {
                stackOfCats = stackOfCats + heightInitialCat;
                ++nCatsNotWorking;
                resultOk = true;
            }
            else
            {
                N++;
                nCatsNotWorking = 0;
                stackOfCats = nCatsWorking;
                actualHeight = 1;
                copy_nCatsWorking = nCatsWorking;
            }
        }
        //cout << "N encontrada: " << N << ", Para heightInitialCat: " << heightInitialCat << " y nCatsWorking: " << nCatsWorking << "\n";
		//// Print
		cout << nCatsNotWorking << " " << stackOfCats << "\n";
	}
  	return(0);
}
