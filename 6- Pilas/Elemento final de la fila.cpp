#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct libros{
    string nombre;
    string genero;
    string color;
};
typedef struct libros libreria;

int main(){

    stack<libreria> registro;
    

    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de libros ingresados: " << registro.size();
        cout << "\nDesea ingresar otro libro? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            libreria libro;
            cout << "Nombre: ";   getline(cin, libro.nombre);
            cout << "Genero: ";   getline(cin, libro.genero);
            cout << "Color: ";       getline(cin, libro.color);
            registro.push(libro); 
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    
    cout << "\nLibros en el sistema " << endl;
    while(!registro.empty()){
        // Obtener el plato de encima (sin sacarlo de la pila)
        libreria librosinicio = registro.top();
        cout << "Libro [" << librosinicio.nombre;
        cout << ", " << librosinicio.genero;
        cout << ", " << librosinicio.color << "]\n";
        
        // Sacando plato de la pila
        registro.pop();
    }
    cout << "Registro de libros vacio." << endl;

    return 0;
}

