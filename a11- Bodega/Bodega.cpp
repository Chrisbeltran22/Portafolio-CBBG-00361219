#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Articulo{
	string nombre, vencimiento;
	int peso, id, ID;
	float precio;
};
vector<Articulo> bodega;

bool compNombre(Articulo a, Articulo b){
	return a.nombre < b.nombre;
}
bool compPeso(Articulo a, Articulo b){
	return a.peso < b.peso;
}
bool compPrecio(Articulo a, Articulo b){
	return a.precio < b.precio;
}

void agregar(), buscar(), eliminar(), mostrar(), ordenar(), vencimiento(), gramos(), dolares();

int main(){
	bool continuar = true;
	do{
		int opcion = 0;
		cout << "\n1) Agregar articulos a la bodega.\n";
		cout << "2) Buscar articulos.\n";
		cout << "3) Eliminar articulos.\n";
		cout << "4) Mostrar todo lo que contenga la bodega.\n";
		cout << "5) Ordenar.\n";
		cout << "6) Mostrar articulos con fecha de vencimiento\n";
		cout << "7) Mostrar articulos con peso mayor a 300 gramos\n";
		cout << "8) Mostrar articulos con valor mayor a $50 dolares\n";
		cout << "9) Salir.\n";
		cout << "Opcion: ";
		cin >> opcion; cin.ignore();

		switch(opcion){
			case 1: agregar(); break;
			case 2: buscar(); break;
			case 3: eliminar(); break;
			case 4: mostrar(); break;
			case 5: ordenar(); break;
			case 6: vencimiento(); break;
			case 7: gramos(); break;
			case 8: dolares(); break;
			case 9: continuar = false;
			default: cout << "Opcion no valida.\n"; break;
		}
	}while(continuar);

	return 0;
}

void agregar(){
	Articulo unArticulo;
	char letra = 's'; int id = 1, ID = 0;
	string no = "Sin caducidad";
	 
	cout << "Nombre: "; getline(cin, unArticulo.nombre);
	cout << "Peso: "; cin >> unArticulo.peso; cin.ignore(); cin.ignore();
	cout << "Precio: "; cin >> unArticulo.precio; cin.ignore();
	cout << "Posee fecha de vencimiento (s/n)"; cin >> letra; cin.ignore();
	if (letra == 's' || letra == 'S'){
	    unArticulo.id = id;
		cout << "Ingrese fecha de vencimiento\n";
		getline (cin, unArticulo.vencimiento);
	}
	else{
	    unArticulo.vencimiento = no;
	    unArticulo.vencimiento = ID;
	}

	bodega.insert(bodega.end(), unArticulo);
	cout << "Articulo ingresado exitosamente!\n";
}
void buscar(){
	string unNombre;
	cout << "Nombre del articulo que buscar: ";
	getline(cin, unNombre);
 
	bool encontrado = false;
	for (int i = 0; i < bodega.size(); i++) {
		if(bodega[i].nombre == unNombre){
			encontrado = true;
			break;
		}
	}

	if(encontrado)
		cout << "Articulo si se encuentra en la bodega.\n";
	else
		cout << "Articulo no se encuentra en la bodega.\n";
}
void eliminar(){
	string unNombre;
	cout << "Nombre del articulo que buscar: ";
	getline(cin, unNombre);
	
	for(auto iter = bodega.begin(); iter != bodega.end(); ++iter){
		if(iter->nombre == unNombre){
			iter = bodega.erase(iter);
			cout << "Articulo eliminado exitosamente.\n";
			break;
		}
	}
}
void mostrar(){
	for (int i = 0; i < bodega.size(); i++) {
		cout << bodega[i].nombre << " pesa " << bodega[i].peso;
		cout << " gramos y vale $" << bodega[i].precio << "\n";
	}
}
void ordenar(){
	int opcion = 0;
	cout << "Criterio de ordenamiento:\n";
	cout << "1) Alfabetico\n";
	cout << "2) Peso\n3)Precio\n";
	cout << "Opcion: ";
	cin >> opcion; cin.ignore();
	
	if(opcion == 1)
		sort(bodega.begin(), bodega.end(), compNombre);
	else if(opcion == 2)
		sort(bodega.begin(), bodega.end(), compPeso);
	else if(opcion == 3)
		sort(bodega.begin(), bodega.end(), compPrecio);
	
	cout << "Bodega ordenada exitosamente\n";
}

void vencimiento(){
    Articulo unArticulo;
    int verificador = 1;
    for (int i = 0; i < bodega.size(); i++) {
        if (unArticulo.id = verificador){
            cout << bodega[i].nombre << " pesa " << bodega[i].peso;
            cout << " gramos\nVale $" << bodega[i].precio;
            cout << "\nY su fecha de vencimiento es: " << bodega[i].vencimiento;
        }
        else{
            cout << "No presenta fecha de caducidad" << endl;
        }
    }
    
}

void gramos(){
	int medida = 300;
	for (int i = 0; i < bodega.size(); i++) {
		if(bodega[i].peso >= medida){
			cout << bodega[i].nombre << " pesa " << bodega[i].peso;
			cout << " gramos\nVale $" << bodega[i].precio;
			cout << "\nY su fecha de vencimiento es: " << bodega[i].vencimiento;
	        cout << endl;
		}
		else
			cout << "No hay elementos a mostrar\n";
	}

	cout << "Elementos mostrados exitosamente\n";
}

void dolares(){
	int limite = 50;
	for (int i = 0; i < bodega.size(); i++) {
		if(bodega[i].peso >= limite){
			cout << bodega[i].nombre << " pesa " << bodega[i].peso;
			cout << " gramos\nVale $" << bodega[i].precio;
			cout << "\nY su fecha de vencimiento es: " << bodega[i].vencimiento;
            cout << endl;
		}
		else
			cout << "No hay elementos a mostrar\n";
	}
 
	cout << "Elementos mostrados exitosamente\n";
}
