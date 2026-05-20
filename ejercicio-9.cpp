#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

/*
EJERCICIO 9: Dado un arreglo de N elementos (máximo 15), determine 
la moda(valor que mas se repite) y su frecuencia. 

Ejemplo:

Con N = 10:
6 8 10 15 8 2 6 8 10 8

La moda es 8 y su frecuencia es 4.
*/

int main() {
    int N;
    int arr[15];
    int moda = 0;
    int maxFrecuencia = 0;

    // Pedir y validar el tamaño del arreglo (máximo 15)
    do {
        cout << "Ingrese la cantidad de elementos (maximo 15): ";
        cin >> N;
        if (N <= 0 || N > 15) {
            cout << "Error. El numero debe estar entre 1 y 15." << endl;
        }
    } while (N <= 0 || N > 15);

    // Leer los datos del arreglo
    cout << "Ingrese los " << N << " elementos:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Calcular la moda y la frecuencia
    for (int i = 0; i < N; i++) {
        int frecuencia_actual = 0;
        
        // Contar cuantas veces aparece el elemento arr[i]
        for (int j = 0; j < N; j++) {
            if (arr[i] == arr[j]) {
                frecuencia_actual++;
            }
        }

        // Si la frecuencia que acabamos de contar es mayor a la maxima registrada,
        // actualizamos la moda y la frecuencia maxima.
        if (frecuencia_actual > maxFrecuencia) {
            maxFrecuencia = frecuencia_actual;
            moda = arr[i];
        }
    }

    // Imprimir el resultado
    cout << "\nLa moda es " << moda << " y su frecuencia es " << maxFrecuencia << "." << endl;

    cout << "\nPresione cualquier tecla para salir...";
    getch(); // Funcion de conio.h para pausar la pantalla

    return 0;
}