#include <iostream>
#include <string>
using namespace std;

int buscarElemento(int arreglo[], int tamano, int find) {
  for (int i = 0; i < tamano; i++) {
    int elementoActual = arreglo[i];
    if (elementoActual == find) return i;
  }

  return -1;
}

int main() {
    int continuar;
    bool bucle = true;
    do{
        string autos[] = {
            "Volvo", "Mazda", "Audi", "Mercedez", "Renaut", "Porsche"
        };
        string find, car;
        cout << "Marca de auto: "; getline(cin, car);
        find = car;
    
        int indice = -1;
        for (int i = 0; i < sizeof(autos) / sizeof(autos[0]); i++) {
            string nombreActual = autos[i];
            if (nombreActual == find) {
                indice = i;
                break;
            }
        }
    
        if(indice == -1){
            cout << "No encontrado\n";
        }
        else{
            cout << "Encontrado en el indice " << indice << std::endl;
        }
        
        cout << "¿Buscar otro auto? (1-si/2-no)"; cin >> continuar; cin.ignore();
        if(continuar == 1){
            cout << "Retornando..." << endl << endl;
        }
        else{
            bucle = false;
        }
        
    }while(bucle);
}
