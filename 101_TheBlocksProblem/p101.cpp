#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream> 
#define long long LL

using namespace std;

/*
move a onto b

	mover a sobre b

move a over b
	
	mover a encima del todo donde este b

pile a onto b

	mover a (y los q esten encima) donde este b

pile a over b
	
	mover a (y los q esten encima) encima del todo donde este b


////////////////

move "a" onto "b"
movimiento "a" a "b"
donde "a" y "b" son números de bloque, el bloque pone 'a' en bloque 'b' después de regresar todos los bloques que se apilan en la parte superior de los bloques 'a' y 'b' a sus posiciones iniciales.

move "a" over "b"
movimiento 'a' más 'b'
donde "a" y "b" son números de bloque, pone el bloque "A" en la parte superior de la pila de bloque de contención 'b', después de regresar de cualquier bloque que se apilan en la parte superior del bloque de 'A' a sus posiciones iniciales.

pile "a" onto "b"
pila "a" a "b"
donde "a" y "b" son números de bloque, mueve la pila de bloques que consisten en bloque 'a', y todos los bloques que se apilan encima del bloque "A", en el bloque 'b'. 
Todos los bloques en la parte superior del bloque de 'b' se mueven a sus posiciones iniciales previas a la pila que tiene bloque_donde_mover. Los bloques apilados encima del bloque de retener su orden cuando se mueven.

pile "a" over "b"
pila 'a' más 'b'
donde "a" y "b" son números de bloque, pone la pila de bloques que consisten en bloque 'a', y todos los bloques que se apilan encima del bloque "A", en la parte superior de la pila de bloque de contención 'b'.
 Los bloques apilados encima del bloque un mantienen su orden original cuando se mueven.

dejar
termina manipulaciones en el mundo de bloques.

Cualquier comando en el que 'a' = 'b' o en la que "a" y "b" están en la misma pila de bloques es un comando ilegal. Todos los comandos ilegales deben ser ignorados y no deben tener ningún efecto en la configuración de los bloques.


////////////////

Sample Input 

10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit

Sample Output 

 0: 0
 1: 1 9 2 4
 2:
 3: 3
 4:
 5: 5 8 7 6
 6:
 7:
 8:
 9:

//////

10 
move 9 onto 1
move 8 over 1 
move 7 over 1 
move 6 over 1
pile 8 onto 6 
pile 8 over 5 
move 2 over 1 
move 4 over 9 
pile 8 onto 6 
pile 8 onto 5 
move 2 over 3
move 4 onto 4 
pile 8 over 5 
pile 8 onto 6 
move 2 over 2 
move 4 over 9 
quit 


0: 0 
1: 1 9 4 
2: 
3: 3 2 
4: 
5: 5 8 7 6 
6: 
7: 
8: 
9:

/////////////

21
move 2 onto 1
move 3 onto 2
move 4 onto 3
move 5 over 1
pile 1 over 10
move 9 over 8
move 11 over 8
pile 3 over 8
pile 8 over 3
move 20 over 19
pile 19 over 18
pile 18 onto 15
move 15 over 3
pile 20 onto 19
pile 19 onto 18
pile 18 over 17
quit

0: 0
1:
2:
3:
4:
5:
6: 6
7: 7
8: 8 9 11 3 4 5 15
9:
10: 10 1 2
11:
12: 12
13: 13
14: 14
15:
16: 16
17: 17 18 19 20
18:
19:
20:

/////////////

24 
move 9 onto 1 
move 23 onto 22 
pile 21 over 20 
move 16 over 1 
pile 8 over 6 
pile 1 over 5 
move 19 over 1 
move 18 over 19 
move 10 onto 0 
move 7 over 1 
move 17 over 14 
pile 6 over 1 
pile 5 over 6 
pile 4 over 0 
move 3 over 0 
move 2 over 9 
move 15 over 1 
move 13 over 17 
move 12 over 15 
move 11 onto 13 
pile 0 over 6 
pile 14 over 5 
pile 20 over 22 
pile 23 over 9 
move 5 over 9 
move 19 onto 2 
pile 3 onto 2 
pile 0 onto 0 
move 23 onto 14 
move 5 over 22 
quit

0: 0
1: 1
2: 2
3: 3
4: 4
5:
6: 6
7: 7
8: 8
9: 9
10: 10
11: 11
12: 12
13: 13
14: 14
15: 15
16: 16
17: 17
18: 18
19: 19
20: 20
21: 21
22: 22 5
23: 23

*/

#define MAX 25

unsigned int n_bloques = 0;

int bloques[MAX][MAX];

int fila_bloque[MAX]; 		// me dice en que FILA esta el BLOQUE (0 -- MAX-1)
int altura_bloque[MAX];		// me dice a que ALTURA esta el BLOQUE en la FILA (0 -- MAX-1)
int altura_fila[MAX];		// me dice la ALTURA MAX de la FILA (0 -- MAX-1) (-1 = vacia)

void printar_posiciones() 
{
  	for (int i = 0; i < n_bloques; i++) 
	{
		cout << i << ":"; 

		for (int j = 0; j < altura_fila[i] + 1; j++) 
		{
			cout << " " << bloques[i][j];
		}

		cout << " (Altura: " << altura_fila[i] + 1 << ")";
		cout << "\n";
	}
}

int main() 
{
	// VARIABLES
	char orden[5]; 		// 'move' o 'pile'
	char posicion[5];	// 'onto' o 'over'

	int bloque_a_mover;		// Numero de bloque ha mover
	int bloque_donde_mover;	// Numero del bloque donde mover

	for (int i = 0; i < MAX; i++) 
	{	
		fila_bloque[i] = i;
		altura_bloque[i] = 0;
		altura_fila[i] = 0;

		/*for (int j = 0; j < MAX; j++) {
			bloques[i][j] = i;
		}*/

	}

	cin >> n_bloques;

	//cout << "Numero de Bloques " << n_bloques << "\n";

	while (1) 
	{
		cin >> orden; 
		if(strcmp(orden, "quit") == 0) break; 
		
		cin >> bloque_a_mover >> posicion >> bloque_donde_mover;

		//cout << "Orden: " << orden << ", Bloque a mover: " << bloque_a_mover << ", Posicion: " << posicion << ", bloque_donde_mover: " << bloque_donde_mover << "\n";

		//cout << "Bloque a mover: " << bloque_a_mover << ", esta en la fila " << fila_bloque[bloque_a_mover] << " y altura: " << altura_bloque[bloque_a_mover] + 1 << "\n";
		//cout << "Donde quieres ponerlo: " << bloque_donde_mover << ", que esta en la fila: " << fila_bloque[bloque_donde_mover] << " y altura: " << altura_bloque[bloque_donde_mover] + 1 << "\n";

		// Movimientos, si estan en la misma fila no se hace nada.
		if (fila_bloque[bloque_a_mover] != fila_bloque[bloque_donde_mover]) 
		{
			// MOVER.
			if (strcmp(orden, "move") == 0 ) 
			{
				if (strcmp(posicion, "onto") == 0 || strcmp(posicion, "over") == 0) 
				{
					// ORDENAR BLOQUES SUPERIORES DE ORIGEN
					if (altura_bloque[bloque_a_mover] != altura_fila[fila_bloque[bloque_a_mover]]) 
					{
						for (int i = 0; i < n_bloques; i++) 
						{
							// COLOCAS LOS BLOQUES SUPERIORES EN LA POSICION INICIAL
							if (fila_bloque[i] == fila_bloque[bloque_a_mover] && altura_bloque[i] > altura_bloque[bloque_a_mover]) 
							{
								fila_bloque[i] = i;
								altura_bloque[i] = 0;
								altura_fila[i] = 0;
								altura_fila[fila_bloque[bloque_a_mover]]--;
							}
						}
					}
				}
				// MOVER ONTO
				if (strcmp(posicion, "onto") == 0 )
				 {
					// ORDENAR BLOQUES SUPERIORES DE DESTINO
					if (altura_bloque[bloque_donde_mover] != altura_fila[fila_bloque[bloque_donde_mover]]) 
					{
						// HAY SUPERIORES
						for (int i = 0; i < n_bloques; i++) 
						{
							// COLOCAS LOS BLOQUES SUPERIORES EN LA POSICION INICIAL
							if (fila_bloque[i] == fila_bloque[bloque_donde_mover] && altura_bloque[i] > altura_bloque[bloque_donde_mover])
							{
								fila_bloque[i] = i;
								altura_bloque[i] = 0;
								altura_fila[i] = 0;
								altura_fila[fila_bloque[bloque_donde_mover]]--;
							}
						}
					}
					// REDUCIR ALTURA DE ORIGEN
					altura_fila[fila_bloque[bloque_a_mover]] -= 1;
					// MOVER BLOQUE A FILA
					fila_bloque[bloque_a_mover] = fila_bloque[bloque_donde_mover];
					// MOVER ALTURA DEL BLOQUE
					altura_bloque[bloque_a_mover] = altura_bloque[bloque_donde_mover] + 1;
					// CAMBIAR ALTURA DE LA FILA
					altura_fila[fila_bloque[bloque_donde_mover]] += 1;
				}
				// MOVER OVER
				else if (strcmp(posicion, "over") == 0 ) 
				{
					// REDUCIR ALTURA DE ORIGEN
					altura_fila[fila_bloque[bloque_a_mover]] -= 1;
					// MOVER BLOQUE A FILA
					fila_bloque[bloque_a_mover] = fila_bloque[bloque_donde_mover];
					// MOVER ALTURA DEL BLOQUE
					altura_bloque[bloque_a_mover] = altura_fila[fila_bloque[bloque_donde_mover]] + 1;
					// CAMBIAR ALTURA DE LA FILA
					altura_fila[fila_bloque[bloque_donde_mover]] += 1;
				}
			}
			// PILE
			else if (strcmp(orden, "pile") == 0 ) 
			{
				int altura_origen = altura_bloque[bloque_a_mover];
				
				// PILE OVER
				if (strcmp(posicion, "over") == 0 ) 
				{	
					int altura_destino = altura_fila[fila_bloque[bloque_donde_mover]] + 1;

					// COLOCAR LOS SUPERIORES DE ORIGEN EN DESTINO
					if (altura_origen != altura_fila[fila_bloque[bloque_a_mover]]) 
					{	
						// HAY SUPERIORES
						for (int i = 0; i < n_bloques; i++) 
						{
							if (fila_bloque[i] == fila_bloque[bloque_a_mover] && altura_bloque[i] > altura_origen) 
							{
								// REDUCIR ALTURA DE ORIGEN
								altura_fila[fila_bloque[bloque_a_mover]] -= 1;
								// MOVER BLOQUE A LA FILA
								fila_bloque[i] = fila_bloque[bloque_donde_mover];
								// MOVER ALTURA DEL BLOQUE
								altura_bloque[i] = (altura_bloque[i] - altura_origen) + altura_destino;
								// CAMBIAR ALTURA DE LA FILA
								altura_fila[fila_bloque[bloque_donde_mover]] += 1;							
							}
						}
					}
					// REDUCIR ALTURA DE ORIGEN
					altura_fila[fila_bloque[bloque_a_mover]] -= 1;
					// MOVER BLOQUE A FILA
					fila_bloque[bloque_a_mover] = fila_bloque[bloque_donde_mover];
					// MOVER ALTURA DEL BLOQUE
					altura_bloque[bloque_a_mover] = altura_destino;
					// CAMBIAR ALTURA DE LA FILA
					altura_fila[fila_bloque[bloque_donde_mover]] += 1;
				}
				// PILE ONTO
				else if (strcmp(posicion, "onto") == 0 ) 
				{
					// COLOCAR LOS SUPERIORES DE DESTINO EN POSICIONES INICIALES
					if (altura_bloque[bloque_donde_mover] != altura_fila[fila_bloque[bloque_donde_mover]]) 
					{	
						int cantidad_movidos = 0;

						// HAY SUPERIORES EN EL DESTINO
						for (int i = 0; i < n_bloques; i++) 
						{
							if (fila_bloque[i] == fila_bloque[bloque_donde_mover] && altura_bloque[i] > altura_bloque[bloque_donde_mover]) 
							{
								// REDUCIR ALTURA DE ORIGEN
								altura_fila[i] = 0;
								// MOVER BLOQUE A LA FILA
								fila_bloque[i] = i;
								// MOVER ALTURA DEL BLOQUE
								altura_bloque[i] = 0;
								// CAMBIAR ALTURA DE LA FILA
								//altura_fila[fila_bloque[bloque_donde_mover]] += 1;							
								cantidad_movidos++;
							}
						}
						// CAMBIAR ALTURA DE LA FILA
						altura_fila[fila_bloque[bloque_donde_mover]] -= cantidad_movidos;
					}
					int altura_origen = altura_bloque[bloque_a_mover];

					int altura_destino = altura_fila[fila_bloque[bloque_donde_mover]] + 1;

					// COLOCAR LOS SUPERIORES DE ORIGEN EN DESTINO
					if (altura_origen != altura_fila[fila_bloque[bloque_a_mover]]) 
					{	
						// HAY SUPERIORES
						for (int i = 0; i < n_bloques; i++) 
						{
							if (fila_bloque[i] == fila_bloque[bloque_a_mover] && altura_bloque[i] > altura_origen) 
							{
								// REDUCIR ALTURA DE ORIGEN
								altura_fila[fila_bloque[bloque_a_mover]] -= 1;
								// MOVER BLOQUE A LA FILA
								fila_bloque[i] = fila_bloque[bloque_donde_mover];
								// MOVER ALTURA DEL BLOQUE
								altura_bloque[i] = (altura_bloque[i] - altura_origen) + altura_destino;
								// CAMBIAR ALTURA DE LA FILA
								altura_fila[fila_bloque[bloque_donde_mover]] += 1;							
							}
						}
					}
					// REDUCIR ALTURA DE ORIGEN
					altura_fila[fila_bloque[bloque_a_mover]] -= 1;
					// MOVER BLOQUE A FILA
					fila_bloque[bloque_a_mover] = fila_bloque[bloque_donde_mover];
					// MOVER ALTURA DEL BLOQUE
					altura_bloque[bloque_a_mover] = altura_destino;
					// CAMBIAR ALTURA DE LA FILA
					altura_fila[fila_bloque[bloque_donde_mover]] += 1;
				}
			}
		}
	}
  	// Posicionar BLOQUES segun variables.
	for (int i = 0; i < n_bloques; i++) 
	{
		bloques[fila_bloque[i]][altura_bloque[i]] = i;
		//cout << "Para i: " << i << " la posicion es: "<< fila_bloque[i] << " / " << altura_bloque[i] << "\n";
	}
  	//cout << "///////////////////////////////////////////////////////\n";

  	for (int i = 0; i < n_bloques; i++) 
	{	
  		cout << i << ":"; 

		for (int j = 0; j < altura_fila[i] + 1; j++) 
		{
			cout << " " << bloques[i][j];
		}
		cout << "\n";
	}
  	return(0);
}
