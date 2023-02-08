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

int main() 
{
	unsigned long height = 0;
	unsigned long nCats = 0;
	unsigned long catsNotWorking = 0;
	unsigned long stackOfCats = 0;

	while ( scanf ("%i %i", &height, &nCats) != EOF ) 
	{
		if((height == 0) && (nCats == 0)) break;

		//// Print
		cout << catsNotWorking << " " << stackOfCats << "\n";
	}
  	return(0);
}
