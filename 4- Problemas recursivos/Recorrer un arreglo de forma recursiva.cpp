#include <iostream>
using namespace std;

int arrayt[10];
int numero, num = 10;

void iniciar_arreglo(int tam){
    if(tam == 10)
        return;
    else{
        
        cout << "Ingrese un numero al arreglo\nNumeros por insertar: " << num-- << endl;
        cin >> numero;
        arrayt[tam] = numero;
        iniciar_arreglo(tam+1);
    }
}

int main(){
    iniciar_arreglo(0);
    for(int i = 0; i <= 9; i++){
        cout << arrayt[i] << ' ';
    }
    
    return 0;
}