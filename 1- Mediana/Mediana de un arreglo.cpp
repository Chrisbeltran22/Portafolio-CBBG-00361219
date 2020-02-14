#include <iostream>
using namespace std;

void solicitar1(int a[], int tamano){
    for(int i = 0; i < tamano; i++){
		cout << "Digite un numero: ";
		cin >> a[i];
	}
}

float media(int a[], int tamano){
    float suma = 0;
    for (int i = 0; i < tamano; i++)
        suma = a[1] + a[2];
    return suma / 2;
}

void solicitar2(int a[], int tamano){
    for(int i = 0; i < tamano; i++){
		cout << "Digite un numero: ";
		cin >> a[i];
	}
}

float media2(int a[], int tamano){
    float suma = 0;
    for (int i = 0; i < tamano; i++)
        suma = a[2];
    return suma;
}


int main(){
    // Declarando variables
	int elementos = 0; float mediana = 0; float mediana2 = 0;
	cout << "Detemine el tamanio del arreglo (4 o 5)" << endl;
	cin >> elementos;
	
	if(elementos == 4){
		int numeros[elementos];
		// Solicitar valores al usuario
		solicitar1(numeros, elementos);
		mediana = media(numeros, elementos);
		cout << "Mediana: " << mediana << endl;

	}
	else if (elementos == 5){
		int numeros[elementos];
		// Solicitar valores al usuario
		solicitar2(numeros, elementos);
		mediana2 = media2(numeros, elementos);
		cout << "Mediana: " << mediana2 << endl;
	}
	
	/* Calcular el promedio
	mediana = media(numeros, elementos);
	mediana2 = media2(numeros, elementos);
	cout << "Mediana: " << mediana << endl;*/
	
}
