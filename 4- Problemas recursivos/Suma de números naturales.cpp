#include <iostream>
using namespace std;

int suma(int valor){
	int total = 0;
	if (valor == 0){
		total = 0;
	}
	else{
		int x = valor - 1;
		total = valor + suma(x);
		cout << "Valor =" << valor << " x =" << x << endl;
		
	} 
	return total;
}


int main(void){
	int numero;
	int respuesta;
	
	cout << "Ingrese un numero: " << endl;
	cin >> numero;
	respuesta = suma(numero);
	cout << "Respuesta: " << respuesta << endl;
}
