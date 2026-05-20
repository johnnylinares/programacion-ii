#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

/*
EJERCICIO 8: Dados un arreglo A de N elementos, (máximo 10 ) leer una posición dentro del arreglo (de
0 a N-1) y muestre el arreglo ordenado ascendentemente desde la posicion N como si fuera un
circulo. 
Ejemplo:
Para N = 6


*/

int main() {
    int N, P;
    int A[10];
    int ordenado[10];
    int resultado[10];

    // 1. Pedir y validar la cantidad de elementos (máximo 10)
    do {
        cout << "Ingrese la cantidad de elementos N (maximo 10): ";
        cin >> N;
        if (N <= 0 || N > 10) {
            cout << "Error. El numero debe estar entre 1 y 10." << endl;
        }
    } while (N <= 0 || N > 10);

    // 2. Leer los datos del arreglo
    cout << "Ingrese los " << N << " elementos:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento posicion " << i << ": ";
        cin >> A[i];
        ordenado[i] = A[i]; // Copiamos los datos para ordenarlos sin perder los originales
    }

    // 3. Pedir y validar la posicion inicial
    do {
        cout << "Ingrese la posicion de inicio (de 0 a " << N - 1 << "): ";
        cin >> P;
        if (P < 0 || P >= N) {
            cout << "Posicion invalida. Intente de nuevo." << endl;
        }
    } while (P < 0 || P >= N);

    // 4. Ordenar el arreglo de menor a mayor (Metodo Burbuja)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (ordenado[j] > ordenado[j + 1]) {
                int temp = ordenado[j];
                ordenado[j] = ordenado[j + 1];
                ordenado[j + 1] = temp;
            }
        }
    }

    // 5. Acomodar circularmente en el arreglo 'resultado'
    // El elemento mas pequeño (ordenado[0]) va en la posicion P.
    for (int i = 0; i < N; i++) {
        // La magia del circulo: el modulo (%) evita que nos salgamos del limite
        int indice_circular = (P + i) % N;
        resultado[indice_circular] = ordenado[i];
    }

    // 6. Mostrar el resultado final
    cout << "\nEl arreglo ordenado circularmente desde la posicion " << P << " es:" << endl;
    for (int i = 0; i < N; i++) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    cout << "\nPresione cualquier tecla para salir...";
    getch();

    return 0;
}