#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define long long LL

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

int n_dimensiones = 0;
double matriz[20][20];

double productos[20][20][20];
double caminos[20][20][20];
int camino[20];

void printar_matriz() {

	for (int x = 0; x < n_dimensiones; x++) {

		for (int y = 0; y < n_dimensiones; y++) {
		
			cout << matriz[x][y] << " ";

		}

		cout << "\n";
	
	}

	cout << "\n";

}

int floyd() {

    for (int step = 1; step <= n_dimensiones; step++) {
        
        for (int k = 0; k <= n_dimensiones; k++) {
            
            for (int i = 0; i <= n_dimensiones; i++) {
                
                for (int j = 0; j <= n_dimensiones; j++) {

                    if (productos[i][j][step] < productos[i][k][step - 1] * productos[k][j][0]) {

                        productos[i][j][step] = productos[i][k][step - 1] * productos[k][j][0];
                        caminos[i][j][step] = k;
                        
                        if (productos[i][j][step] > 1.01 && i == j) {

                            camino[0] = step;
                            camino[step + 1] = i;
                            
                            while (step > 0) {

                                camino[step] = caminos[i][j][step];
                                j = caminos[i][j][step];
                                step--;

                            }

                            return 1;

                        }

                    }

                }
    
            }
    
        }
    
    }

    return 0;

}

int main() {

	while ( scanf ("%i", &n_dimensiones) != EOF ) {

		int principio = 0;
		int final = 0;

		memset(matriz, 0.0, sizeof(matriz));
        memset(productos, 0.0, sizeof(productos));
        memset(caminos, 0.0, sizeof(caminos));

		for (int x = 0; x < n_dimensiones; x++) {

			for (int y = 0; y < n_dimensiones; y++) {

				if (x != y) cin >> matriz[x][y];
				else matriz[x][y] = 1.0;

				productos[x][y][0] = matriz[x][y];
				caminos[x][y][0] = y;

			}
		
		}

		// PRINTAR MATRIZ
//		printar_matriz();

		// ALGORITMO
		bool encontrado = false;
		principio = 0;
		final = 0;

		for (int nx = 1; nx < n_dimensiones && !encontrado; nx++) {
			
			for (int i = 0; i < n_dimensiones && !encontrado; i++) {
			
				for (int j = 0; j < n_dimensiones && !encontrado; j++) {
			
					//productos[i][j][nx] = std::numeric_limits<double>::min();					
			
					for (int k = 0; k < n_dimensiones && !encontrado; k++) {
					
						double p = productos[i][k][0] * productos[k][j][nx - 1];

//						cout << "Multiplicando: " << productos[i][k][0] << " * " <<  productos[k][j][nx - 1] << " = " << p << " --> posiciones: " << i << " " << k << " // " << k << " " << j << "\n";

						if (p > productos[i][j][nx]) {

							productos[i][j][nx] = p;
							caminos[i][j][nx] = k;

							if ( (i == j) && (p >= 1.01) ) {

								encontrado = true;
								principio = i;
								caminos[i][j][nx + 1] = i;
								final = nx + 1;
									
							}

						}

					}

//					cout << "FINAL DEL PRIMER FOR.\n";

				}

			}

		}

		// PRINTAR RESULTADO
		if (encontrado) {

			for (int i = final; i >= 0; i--) {
				
				cout << caminos[principio][principio][i] + 1 << " ";
			
			}

			cout << "\n";

		}
		else cout << "no arbitrage sequence exists\n";

		// if( floyd() ) {

		// 	for (int i = 1; i <= camino[0] + 1; i++) {

  //               printf("%d", camino[i]);
  //               if (i != camino[0] + 1) printf(" ");
  //               else printf("\n");
            
  //           }
  //       }
  //       else printf("no arbitrage sequence exists\n");

	}

  	return(0);

}

/*

The maximum dimension is 20; the minimum dimension is 2.

3
1.2 .89
.88 5.1
1.1 0.15

4
3.1    0.0023    0.35
0.21   0.00353   8.13 
200    180.559   10.339
2.11   0.089     0.06111

2
2.0
0.45

 */
