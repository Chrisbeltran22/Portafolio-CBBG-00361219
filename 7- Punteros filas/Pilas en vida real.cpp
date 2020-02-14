#include <iostream>
#include <string>
using namespace std;

struct churros{
    string churro;
    string marca;
    string sabor;
};
typedef struct churros churros;

struct nodo{
    churros elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, churros e);
churros pop(Pila *s);
churros top(Pila *s);

int main(){
    Pila pilaDechurross;
    initialize(&pilaDechurross);
    
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\n¿Desea ingresar un producto (churro)? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            churros unchurros;
            cout << "churro: ";      getline(cin, unchurros.churro);
            cout << "marca: ";   getline(cin, unchurros.marca);
            cout << "sabor: ";       getline(cin, unchurros.sabor);
            push(&pilaDechurross, unchurros);
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    cout << "\nDesapilando churross..." << endl;
    while(!empty(&pilaDechurross)){
        churros churrosDeEncima = top(&pilaDechurross);
        cout << "churros [" << churrosDeEncima.churro;
        cout << ", " << churrosDeEncima.marca;
        cout << ", " << churrosDeEncima.sabor << "]\n";
        
        pop(&pilaDechurross);
    }
    cout << "No hay churros." << endl;

    return 0;
}

void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, churros e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

churros pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        churros e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else 
        return {{" "},{" "},{" "}};
}

churros top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else 
        return {{" "},{" "},{" "}};
}