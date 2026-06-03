#include <stdio.h>
#define max 2

using namespace std;

/*
--- est[i]RUCTURAS ---
Se tiene la información de 5 alumnos que incluye:
cedula, edad y notas de los 3 cortes.

Dada una cedula busque la nota del primer corte de ese alumno.

PROYECTO FINAL: 23 DE JUNIO.
*/

// int ID[5], edad[5], N1[5], N2[5], N3[5]; // Manera ineficiente, ya que al ordenar por notas o cualquier variable
// necesario cambiar el orden de las cedulas para que no se pierda el orden.
	
// USANDO ESTRUCTURAS
	struct alumno {
		int ID, edad, cortes[3];
	};

int main (void) {
	// Para usar los campos, se debe usar en este caso variable.campo, ej: maria.ID.
	struct alumno est[max];
	int IDsearch;
	
	for (int i = 0; i < max; i++) {
		printf("\nIngrese su cedula: "); scanf("%d", &est[i].ID);
		printf("Ingrese su edad: "); scanf("%d", &est[i].edad);
		
		for (int j = 0; j < 3; j++) {
			do {
				printf("Ingrese la nota del corte %d: ", j+1); scanf("%d", &est[i].cortes[j]);
				if (est[i].cortes[j] > 20 || est[i].cortes[j] < 0) printf("ERROR: Ingrese una nota valjda del 0 al 20\n");
			} while (est[i].cortes[j] > 20 || est[i].cortes[j] < 0);
		}
		
		printf("\n--- RESULTADOS ALUMNO #%d---\n", i);
		
		printf("Cedula: %d\n", est[i].ID);
		printf("Edad: %d\n", est[i].edad);
		
		for (int h = 0; h < 3; h++) {
			printf("Corte #%d: %d\n", h+1, est[i].cortes[h]);
		}
	}
	
	// BUSQUEDA DE PRIMER CORTE CON LA CEDULA
	printf("\nn--- BUSQUEDA DE CEDULA ---\n");
	printf("Cedula a buscar: "); scanf("%d", &IDsearch);
	for (int l = 0; l < max; l++) {
		if (est[l].ID == IDsearch) {
			printf("Saco: %d", est[l].cortes[0]);
		}
	}
}
