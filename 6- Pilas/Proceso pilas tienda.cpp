#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct churros{
    string churro;
    string marca;
    string sabor;
};
typedef struct churros churros;

int main(){

    stack<churros> pilaDechurross;
    
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\n¿Desea ingresar un producto (churro)? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            churros unchurros;
            cout << "churro: ";   getline(cin, unchurros.churro);
            cout << "marca: ";   getline(cin, unchurros.marca);
            cout << "sabor: ";       getline(cin, unchurros.sabor);
            pilaDechurross.push(unchurros); 
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    cout << "\nDesapilando churross..." << endl;
    while(!pilaDechurross.empty()){
        churros churrosDeEncima = pilaDechurross.top();
        cout << "churros [" << churrosDeEncima.churro;
        cout << ", " << churrosDeEncima.marca;
        cout << ", " << churrosDeEncima.sabor << "]\n";
        
        pilaDechurross.pop();
    }
    cout << "Sin churros en la bodega" << endl;

    return 0;
}

