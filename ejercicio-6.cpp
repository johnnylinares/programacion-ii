#include <conio.h>
#include <stdio.h>
#include <iostream>

#define max 20

using namespace std;

/*
EJERCICIO 6: Dados dos arreglos de N elementos cada uno (Máximo 20) , genere un tercer arreglo
intercalando ambos arreglos, metiendo primero el menor de los 2 elementos. 

Ejemplo
6 12 13 5 1       -4 10 17 19 8

Quedaría:
-4 6 10 12 13 5 1 17 19 8
*/

int main(void) {
	int n = 0, i = 0, k = 0, menor = 0, mayor = 0;
	
	do {
		printf("Introduzca el tamano de los arreglos (maximo 20): "); scanf("%i", &n);
		if (n < 1 || n > 20) printf("ERROR: Ingrese un valor valido");
	} while (n < 1 || n > 20);
	
	int num1[max], num2[max], num3[n*2];
	
	// INGRESO DE DATOS DE LOS ARREGLOS
	printf("\n--- Ingrese los elementos del arreglo A ---\n");
	for (i = 0; i < n; i++) {
		printf("A[%i] = ", i); scanf("%i", &num1[i]);
	}

	printf("\n--- Ingrese los elementos del arreglo B ---\n");
	for (i = 0; i < n; i++) {
		printf("B[%i]: ", i); scanf("%i", &num2[i]);
	}
	
	// BUCLE
	k = 0;
	for (i = 0; i < n; i++) {
		if (num1[i] < num2[i]) {
			menor = num1[i];
			mayor = num2[i];
		}
		else {
			menor = num2[i];
			mayor = num1[i];
		}
		
		num3[k] = menor; k++;
		num3[k] = mayor; k++;
	}
	
	printf("\nArreglo intercalado resultante:\n");
	for (i = 0; i < n * 2; i++) {
		printf("%i ", num3[i]);
	}
	printf("\n");
	
}

