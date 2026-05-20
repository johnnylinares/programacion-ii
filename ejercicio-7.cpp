#include <conio.h>
#include <stdio.h>
#include <iostream>

#define max 20

using namespace std;

/*
Dados dos arreglos de N elementos cada uno (Máximo 20) , luego leer una posicion del
arreglo A donde insertara el arreglo B, para esto genere un tercer arreglo. 

Ejemplo N=5
6 12 13 5 1     -4 10 17 19 8
Al leer la posición 3 quedaría:
6 12 13 -4 10 17 19 8 5 1
*/

int main(void) {
	int n = 0, i = 0, ins = 0;
	
	do {
		printf("Introduzca el tamano de los arreglos (maximo 20): "); scanf("%i", &n);
		if (n < 1 || n > 20) printf("ERROR: Ingrese un valor valido\n");
	} while (n < 1 || n > 20);
	
	int num1[MAX], num2[MAX], num3[MAX * 2];
	
	printf("\n--- Ingrese los elementos del arreglo A ---\n");
	for (i = 0; i < n; i++) {
		printf("A[%i] = ", i); scanf("%i", &num1[i]);
	}

	printf("\n--- Ingrese los elementos del arreglo B ---\n");
	for (i = 0; i < n; i++) {
		printf("B[%i]: ", i); scanf("%i", &num2[i]);
	}
	
	do {
		printf("\nIngrese la posicion donde insertara el arreglo B en el A: "); scanf("%i", &ins);
		if (ins < 0 || ins > n) printf("ERROR: Ingrese un valor valido\n");
	} while (ins < 0 || ins > n);
	
	int k = 0;
	
	for (i = 0; i < ins; i++) {
		num3[k] = num1[i];
		k++;
	}
	
	for (i = 0; i < n; i++) {
		num3[k] = num2[i];
		k++;
	}
	
	for (i = ins; i < n; i++) {
		num3[k] = num1[i];
		k++;
	}
	
	printf("\n--- Arreglo resultante ---\n");
	for (i = 0; i < n * 2; i++) {
		printf("%i ", num3[i]);
	}
	printf("\n");
	
	return 0;
}
