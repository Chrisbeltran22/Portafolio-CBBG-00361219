#include <iostream>
#include <string>
#include <queue>
using namespace std;

//variables structs
struct actividades{
	string titulo;
	string hora;
	int duracionEnMinutos;
	string descripcion;
	string tipo;
	
};
typedef struct actividades Actividad;

struct agenda{
	queue <Actividad> historial;
	int actividadesRealizadas;
};
typedef struct agenda Agenda;

Agenda registro;

//prototipos
void insertar(), verActividades();
void borrar(), borrarTodo();

int main(void){
	registro.actividadesRealizadas = 0;
	int opcion = 0;
	
	bool proceso = true;
	
	do{
		cout << "1- Insertar una actividad\n"; 
		cout << "2- Borrar una actividad\n";
		cout << "3- Borrar todas las actividades\n";
		cout << "4- Ver todas las actividades del dia\n";
		cout << "5- Salir\n";
		cout << "Su eleccion: "; cin >> opcion; cin.ignore();
		
		switch(opcion){
			case 1: insertar(); break;
			case 2: borrar(); break;
			case 3: borrarTodo(); break;
 			case 4: verActividades(); break;
			case 5: proceso = false; break;
			default: cout << "Entrada no valida" << endl;
		}
	}
	while(proceso);
	
	return 0;
}

void insertar(){
	actividades unaActividad;
	cout << "\nTitulo de la actividad: "; getline (cin, unaActividad.titulo);
	cout << "Hora: ";  getline (cin, unaActividad.hora);
	cout << "Duracion en minutos: "; cin >> unaActividad.duracionEnMinutos; cin.ignore();
	cout << "Descripcion "; getline (cin, unaActividad.descripcion);	
	cout << "Tipo:\n E- Estudio\tR- Recreacion\tO- Ocio\tN- Ninguna de las anteriores\n "; getline (cin, unaActividad.tipo);
	
	registro.historial.push(unaActividad);
	registro.actividadesRealizadas++;
}

void borrar(){
	
}

void borrarTodo(){
	
}

void verActividades(){
	
	while(!registro.historial.empty()){
		Actividad mostrando = registro.historial.front();
		cout << "\nActividades ingresadas: " << registro.historial.size() << endl;
		cout << "Total de actividades ingresadas: " << registro.actividadesRealizadas << endl;
		cout << "Titulo: " << mostrando.titulo << endl;
		cout << "Hora realizada: " << mostrando.hora << endl;
		cout << "Duracion en minutos: " << mostrando.duracionEnMinutos << endl;
		cout << "Descripcion: " << mostrando.descripcion << endl;
		cout << "Tipo: " << mostrando.tipo << endl;
		
		cout << endl;
		return;
	}
	cout << "\nNo hay actividades para mostrar" << endl;
}

