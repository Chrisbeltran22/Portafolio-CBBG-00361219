#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[] = {1, 3, 4, 5, 17, 18, 31, 33};
	int inf,sup,mitad,dato;
	char band='F';
	 
	cout << "Ingrese numero a buscar: "; cin >> dato;
	 
	//Algoritmo de la Busqueda Binaria
	inf = 0;
	sup = 5;
	
	for (int i = 0; i < sup; i++){
	  
		mitad = (inf + sup)/2;
		if(numeros[mitad] == dato){
			band = 'V';
			break;
		}
		if(numeros[mitad] > dato){
			sup = mitad;
			mitad = (inf + sup) / 2;
		}
		if(numeros[mitad] < dato){
			inf = mitad;
			mitad = (inf + sup) / 2;
		} 
	}
	 
	if(band == 'V'){
		cout<<"El numero se encontro en la pos: "<<mitad<<endl;
	}
	else{
		cout<<"El numero NO se encontro";
	}
	 
	return 0;
}
