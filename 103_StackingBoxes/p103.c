#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <vector>
#define long long LL
using namespace std;

/*
	Estructura de un cubo.
*/
struct CUBO {

    int dimension[10];
    int posicion;

};
CUBO cubo[30];

struct NODO_GRAFO {

	int padre;
	int n_hijos;
	int hijos[30];
	int visitado;

};
NODO_GRAFO grafo[30];

int n_cubos = 0;
int n_dimensiones = 0;

int maximo_camino = 0;
int solucion_maxima[30];

int maximo_actual = 0;
int solucion_actual[30];

void printar_cubos() {

	for (int x = 0; x < n_cubos; x++) {

		if (cubo[x].posicion < 10) cout << "Cubo nº 0" << cubo[x].posicion << ": ";
		else cout << "Cubo nº " << cubo[x].posicion << ": ";

		for (int y = 0; y < n_dimensiones; y++) cout << cubo[x].dimension[y] << " ";

		cout << "\n";

	}

	cout << "\n";

}

void printar_grafo() {

	for(int x = 0; x < n_cubos; x++) {

		if (x < 10)	cout << "Grafo: 0" << x;
		else cout << "Grafo: " << x;

		cout << "/";

		if (cubo[x].posicion < 10)	cout << "0" << cubo[x].posicion;
		else cout << cubo[x].posicion;		

		if (grafo[x].n_hijos < 10) cout << " tiene 0" << grafo[x].n_hijos << " hijos (";
		else cout << " tiene " << grafo[x].n_hijos << " hijos (";
		
		for (int y = 0; y < grafo[x].n_hijos; y++) {

			if (grafo[x].hijos[y] < 10) cout << " 0" << grafo[x].hijos[y];
			else cout << " " << grafo[x].hijos[y];

		}
		
		cout << " )\n";
	
	}

	cout << "\n";

}

void visitar_grafo(int x, int max) {


	for (int i = 0; i < grafo[x].n_hijos; i++) {

		grafo[grafo[x].hijos[i]].padre = x;
		visitar_grafo(grafo[x].hijos[i], 0);

	}

	//SABER POR DONDE HAS VENIDO
	if (grafo[x].n_hijos == 0) {
		
		int puntero = x;
//		cout << puntero << " ";
		solucion_actual[0] = cubo[puntero].posicion;
		maximo_actual = 1;

		while (grafo[puntero].padre != -1) {
		
//			cout << grafo[puntero].padre << " ";
			puntero = grafo[puntero].padre;
			solucion_actual[maximo_actual] = cubo[puntero].posicion;
			maximo_actual++;

		}

//		cout << "( "<< maximo_actual << " )\n";

		if (maximo_actual > maximo_camino) {
			
/*			cout << "HE ENCONTRADO MAXIMO NUEVO --> " << maximo_camino << " por " <<  maximo_actual << " \n";
			cout << "SOLUCION ANTERIOR: \n\t";
			for (int i = 0; i < maximo_camino; i++) {
				cout << solucion_maxima[i] << " ";
			}
			cout << "\nSOLUCION NUEVA: \n\t";
			for (int i = 0; i < maximo_actual; i++) {
				cout << solucion_actual[i] << " ";
			}
			cout << "\n"; 
*/			maximo_camino = maximo_actual;
			//std::swap(solucion_actual, solucion_maxima); 
			memcpy(solucion_maxima, solucion_actual, maximo_camino*sizeof(int));

		}

		maximo_actual = 0;
	
	}

}

int main() {

	while ( scanf ("%i %i", &n_cubos, &n_dimensiones) != EOF ) {

		// INTRODUCCION DE LOS n_cubos DE n_dimensiones Y ORDENARLOS POR DIMENSIONES
		for (int x = 0; x < n_cubos; x++) {

			cubo[x].posicion = x + 1;

			for (int i = 0; i < n_dimensiones; i++) {

				cin >> cubo[x].dimension[i];

				// ORDENAR DIMENSIONES EN EL CUBO.
				for (int j = 0; j < i; j++) {

					if ( cubo[x].dimension[i] > cubo[x].dimension[j] ) {
						
						std::swap(cubo[x].dimension[i], cubo[x].dimension[j]);						

					}

				}

			}

			// ORDENAR CUBO POR DIMENSIONES
			for (int j = 0; j < x; j++) {

				for (int dim = 0; dim < n_dimensiones; dim++) {

					if ( cubo[x].dimension[dim] > cubo[j].dimension[dim] ) {

						std::swap(cubo[x], cubo[j]);

						break;

					}
					else if ( cubo[x].dimension[dim] < cubo[j].dimension[dim] ) {

						break;
					
					}

				}

			}

		}
		// PRINTAR CUBOS ORDENADOS
//		printar_cubos();
		// BUSCAR EL CAMINO MAS LARGO
		// RELLENAR GRAFO
		for (int x = 0; x < n_cubos; x++) {

			grafo[x].padre = 0;
			grafo[x].n_hijos = 0;

			for (int x1 = x+1; x1 < n_cubos; x1++) {
				
				char entra = 1;

				for (int dim = 0; dim < n_dimensiones; dim++) {

					if 	(cubo[x].dimension[dim] <= cubo[x1].dimension[dim]) {
						
						entra = 0;	
						break;

					}

				}

				if (entra) {

					grafo[x].hijos[grafo[x].n_hijos] = x1;
					grafo[x].n_hijos++;
					grafo[x].padre = 0;

				}

			}
		
		}
		// PRINTAR GRAFO
//		printar_grafo();
		// VISITAR EL GRAFO
		for (int x = 0; x < n_cubos; x++) {

//			cout << "\nINICIO DEL GRAFO: "<< x <<"\n";
			grafo[x].padre = -1;
			visitar_grafo(x, 0);
//			cout << "\nFIN DEL GRAFO: "<< x <<"\n";

		}
		// PRINTAR EL RESULTADO
		cout << maximo_camino << "\n";
		for (int i = 0;i < maximo_camino; i++) cout << solucion_maxima[i] << " ";
		cout << "\n";

		maximo_camino = 0;	
	
	}

  	return(0);

}

/*

5 2
3 7
8 10
5 2
9 11
21 18

8 6
5 2 20 1 30 10
23 15 7 9 11 3
40 50 34 24 14 4
9 10 11 12 13 14
31 4 18 8 27 17
44 32 13 19 41 19
1 2 3 4 5 6
80 37 47 18 21 9

10 10 
1 2 3 4 5 6 7 8 9 10 
4 5 2 3 3 5 6 7 9 10 
20 30 2 1 3 4 5 6 9 10 
1 2 3 4 5 6 7 8 9 10 
5 2 3 4 5 6 9 10 22 30 
2 3 4 5 6 7 8 9 10 11 
2 3 4 5 6 7 8 9 10 11 
3 4 5 6 7 8 9 10 11 12 
98 23 43 53 23 43 53 10 4 90 
1 1 1 2 3 4 5 9 10 11 

1 7
1 2 3 0 0 0 0

4 7
3 2 1 1 2 3 4
0 0 0 5 6 7 9
9 3 2 2 35 8 9
-1 -1 -1 -20 2 5 6

5 2
3 7
8 10
5 2
9 11
21 18

5 1
1
3
2
5
4

10 10
1 2 3 4 5 6 7 8 9 10
4 5 2 3 3 5 6 7 9 10
20 30 2 1 3 4 5 6 9 10
1 2 3 4 5 6 7 8 9 10
5 2 3 4 5 6 9 10 22 30
2 3 4 5 6 7 8 9 10 11
2 3 4 5 6 7 8 9 10 11
3 4 5 6 7 8 9 10 11 12
98 23 43 53 23 43 53 10 4 90
1 1 1 2 3 4 5 9 10 11

17 4
859 397 577 913
757 501 912 171
836 991 761 899
647 446 709 426
295 211 586 775
750 619 733 153
192 999 205 89
264 552 958 328
309 705 412 596
94 569 98 520
529 849 162 453
299 3 766 227
748 539 511 820
778 562 725 523
497 200 103 880
903 737 701 423
813 788 691 857

 */
