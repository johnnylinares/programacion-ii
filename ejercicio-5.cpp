#include <conio.h>
#include <stdio.h>
#include <iostream>

#define max 15

using namespace std;

/*
EJERCICIO 5: Dados dos arreglos de N y M elementos respectivamente (máximo 15 y N < M) determine si
A está contenido en B, indicando a partir de cual posición.

Ejemplo:
6 12 13        -4 6 6 12 13

A está contenido en B desde la posición 2
*/

int main(void) {
	int n = 0, m = 0, i = 0, j = 0;
	
	do {
		printf("Introduzca el tamano de su primer arreglo (maximo 15): "); scanf("%i", &n);
		if (n < 1 || n > 15) printf("ERROR: Ingrese un valor valido");
	} while (n < 1 || n > 15);
	
	do {
		printf("Introduzca el tamano de su segundo arreglo (maximo 15 y mayor al primero): "); scanf("%i", &m);
		if (m < 1 || m > 15 || m < n) printf("ERROR: Ingrese un valor valido");
	} while (m < 1 || m > 15 || m < n);
	
	int num1[max], num2[max];
	
	printf("\n--- Ingrese los elementos del arreglo A ---\n");
	for (i = 0; i < n; i++) {
		printf("A[%i] = ", i); scanf("%i", &num1[i]);
	}
	
	printf("\n--- Ingrese los elementos del arreglo B ---\n");
	for (i = 0; i < m; i++) {
		printf("B[%i]: ", i); scanf("%i", &num2[i]);
	}
	
	bool encontrado = false, coincide;
	int posicion = -1;
	
	for (i = 0; i <= m - n; i++) {
		coincide = true;
		
		for (j = 0; j < n; j++) {
			if (num2[i+j] != num1[j]) {
				coincide = false;
				break;
			}
		}
		
		if (coincide) {
			encontrado = true;
			posicion = i;
			break;
		}
	}
	
	if (encontrado) {
		printf("\nA esta contenido en B desde la posicion %i\n", posicion);
	} else {
		printf("\nA NO esta contenido en B\n");
	}
	
	return 0;
}