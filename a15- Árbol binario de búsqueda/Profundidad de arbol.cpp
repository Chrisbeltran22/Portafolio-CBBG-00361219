#include <iostream>
#include <string>
using namespace std;

struct pokemon{
    string nombre;
    float Ataque;
};

pokemon solicitarDato(){
    pokemon unpokemon;
    cout << "Nombre del pokemon: ";
    getline(cin, unpokemon.nombre);
    cout << "Ataque: ";
    cin >> unpokemon.Ataque; cin.ignore();
    return unpokemon;
}
void mostrarDato(pokemon unpokemon){
    cout << "Nombre del pokemon: " << unpokemon.nombre;
    cout << ". Ataque: " << unpokemon.Ataque;
}

enum comparacion{menorque,mayorque,igualque};

bool comparar(pokemon a, comparacion operador, pokemon b){
    bool resultado = false;
    switch(operador){
        case menorque: resultado = a.Ataque < b.Ataque; break;
        case mayorque: resultado = a.Ataque > b.Ataque; break;
        case igualque: resultado = a.Ataque == b.Ataque; break;
    }
    return resultado;
}

typedef pokemon T;

struct Nodo{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *Arbol;

Arbol crearArbol(T x);

void asignarIzq(Arbol a, T unDato);
void asignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);
int profundidad(Arbol a);

void preorden(Arbol a);
void inorden(Arbol a);
void postorden(Arbol a);
void recorrerArbol(Arbol a);
void crearPersonalizado(Arbol p);

int main(){
    int profArbol = 0;
    cout<<"Inicializando arbol...\nPokemon base:\n";
    Arbol arbol = crearArbol(solicitarDato());
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nMenu: \n";
        cout << "\t1) Agregar\n";
        cout << "\t2) Recorrer y ver profundidad\n";
        cout << "\t3) Salir\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion; cin.ignore();
        switch(opcion){
            case 1: agregarNodo(arbol); break;
            case 2: recorrerArbol(arbol); break;
            case 3: continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);
    
    profArbol = profundidad(arbol);
    cout << "Profundidad del arbol: " << profArbol << endl;
    
    return 0;
}

Arbol crearArbol(T x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

void asignarIzq(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    cout << "Dato a agregar:\n";
    T unDato = solicitarDato();
    
    Arbol p = a;
    
    while(true){
        if(comparar(unDato, igualque, p->info)){
            cout << "Error: dato ya existe!" << endl;
            return;
        }
        else if(comparar(unDato, menorque, p->info)){
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    if(comparar(unDato, menorque, p->info))
        asignarIzq(p, unDato);
    else
        asignarDer(p, unDato);
}

void preorden(Arbol a){
    if(a != NULL){
        cout << "\n"; mostrarDato(a->info);
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << "\n"; mostrarDato(a->info);
        inorden(a->der);
    }
}

void recorrerArbol(Arbol a){
    cout << "\nRecorrido PRE orden:-----"; preorden(a); cout << endl;
    cout << "\nRecorrido IN orden:-----"; inorden(a); cout << endl;
}
//FUNCION PARA CALCULAR LA PROFUNDIDAD DEL ARBOL
int profundidad(Arbol a){
	
    int AlturaIz = 0, AlturaDer = 0;

    if(a == NULL)
        return -1;
    else
    {
        AlturaIz = profundidad(a -> izq);
        AlturaDer = profundidad(a -> der);

        if(AlturaIz > AlturaDer)
            return AlturaIz + 1;
        else
            return AlturaDer + 1;
    }
	
}