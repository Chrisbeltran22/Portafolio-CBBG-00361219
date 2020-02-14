#include <iostream>
#include <string>
using namespace std;

struct Pedido{
    string lastName;
    int table;
    int tacos;
    int burritos;
    int quesadillas;
    int tiempo;
};

typedef Pedido T;
const T noValido = {{" "},-1,-1,-1,-1,-1};

struct Nodo{
    T elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);

struct taqueria{
    Cola queueOrders;
    int tacosPrepared;
    int burritosPrepared;
    int quesadillasPrepared;
};
taqueria AlChileWey;

void agregar();
void consultar();
void servir();
void vertodos();

int main(){
    initialize(&AlChileWey.queueOrders);
    AlChileWey.tacosPrepared = 0;
    AlChileWey.burritosPrepared = 0;
    AlChileWey.quesadillasPrepared = 0;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar un pedido\n";
        cout << "2) Consultar el estado actual\n";
        cout << "3) Despachar un pedido\n";
        cout << "4) Ver todos los pedidos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: consultar(); break;
            case 3: servir(); break;
            case 4: vertodos(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente==NULL) ? true : false;
}

T front(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(q->final==NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
        
    q->final = unNodo;
}

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if(q->frente==NULL)
        q->final = NULL;
    delete(unNodo);
    return x;
}

int size(Cola *q){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    int contador = 0;

    while(!empty(q)){
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }

    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}

void agregar(){
 
    Pedido foodOrders;
    cout << "\nDigite su apellido: "; getline(cin, foodOrders.lastName);
    cout << "\nNumero de la mesa: "; cin >> foodOrders.table; cin.ignore();
    cout << "\nOrden de tacos: "; cin >> foodOrders.tacos; cin.ignore();
    cout << "\nOrden de burritos: "; cin >> foodOrders.burritos; cin.ignore();
    cout << "\nOrden de quesadillas: "; cin >> foodOrders.quesadillas; cin.ignore();
    foodOrders.tiempo = (foodOrders.tacos+foodOrders.burritos+foodOrders.quesadillas) * 45;
    
    enqueue(&AlChileWey.queueOrders, foodOrders);

    AlChileWey.tacosPrepared += ((foodOrders.tacos * 3) + (foodOrders.burritos) + (foodOrders.quesadillas * 3));
}

void consultar(){
    cout << "\nPedidos en espera: " << size(&AlChileWey.queueOrders) << endl;
    cout << "\nTotal tacos hechos: " << AlChileWey.tacosPrepared << endl;
    cout << "\nTotal burritos hechos: " << AlChileWey.burritosPrepared << endl;
    cout << "\nTotal quesadillas hechas: " << AlChileWey.quesadillasPrepared << endl;
}

void servir(){
    Pedido pedidoDespachado = dequeue(&AlChileWey.queueOrders);
    cout << "\nFamilia " << pedidoDespachado.lastName << " su pedido esta listo\n";
    cout << "Se encuentran en la mesa " << pedidoDespachado.table << endl;
}

void vertodos(){
    Cola colaTemporal;
    initialize(&colaTemporal);
    
    while(!empty(&AlChileWey.queueOrders)){
        Pedido foodOrders = dequeue(&AlChileWey.queueOrders);
        enqueue(&colaTemporal, foodOrders);
        
        cout << "\nInfo del pedido: " << foodOrders.lastName << ", ";
        cout << "\nTacos: " << foodOrders.tacos << ", ";
        cout << "\nBurritos: " << foodOrders.burritos << ", ";
        cout << "\nQuesadillas: " << foodOrders.quesadillas << "\n\n";
    }
    
    while(!empty(&colaTemporal)){
        T elemento = dequeue(&colaTemporal);
        enqueue(&AlChileWey.queueOrders, elemento);
    }
}