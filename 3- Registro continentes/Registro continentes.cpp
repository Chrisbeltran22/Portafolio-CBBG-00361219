#include <iostream>
#include <string>

using namespace std;

struct continente{
	string nombre;
	string capital;
	int capitalmayor;
	string ubicacion;
	int habitantes;
	int habitantestotal;
	int edad;
	int edadpromedio;
};

struct continente total[5];
int cantcontinentes = 0;

void capitalmayor(){
	string capital;
	
	for (int i = 0; i < cantcontinentes; i++){
		if (total[i].capital > total[i].capital){
			cout<<"La capital con mas poblacion es: "<<total[i].capital<<endl;
			cout<<"Con la cantidad de habitantes de: "<<total[i].habitantes<<endl;
		}
		else cout<<"La capital con mas poblacion es: "<<total[i].capital<<endl;
			cout<<"Con la cantidad de habitantes de: "<<total[i].habitantes<<endl;
	}
}

void edadpromedio(){
	string ubicacion;
	int acum = 0;
	int acum1 = 0;
	cout<<"Ingrese el continente: ";
	getline (cin, ubicacion);
	
	for (int i = 0; i < cantcontinentes; i++){
		if (ubicacion.compare(total[i].ubicacion) == 0){
			cout<<"Paises dentro de este continente: ";
			cout<<endl<<"Pais: "<<total[i].nombre;
			cout<<endl<<"Capital: "<<total[i].capital;
			cout<<endl<<"Habitantes: "<<total[i].habitantes;
			cout<<endl<<"Edad promedio: "<<total[i].edad;	
			cout<<endl;
			
			acum = total[i].edad + acum;
			acum1 = acum / cantcontinentes;

			cout<<"Edad promedio en el continente: "<<acum1<<endl;	
		}
		else cout<<"No se ha encontrado informacion en este continente"<<endl;
	}
}

void habitantestotal(){
	string ubicacion;
	int acum = 0;
	cout<<"Ingrese el continente: ";
	getline (cin, ubicacion);
	
	for (int i = 0; i < cantcontinentes; i++){
		if (ubicacion.compare(total[i].ubicacion) == 0){
			cout<<"Paises dentro de este continente: ";
			cout<<endl<<"Pais: "<<total[i].nombre;
			cout<<endl<<"Capital: "<<total[i].capital;
			cout<<endl<<"Habitantes: "<<total[i].habitantes;
			cout<<endl<<"Edad promedio: "<<total[i].edad;	
			cout<<endl;
			
			acum = total[i].habitantes + acum;
			cout<<"Total de habitantes en el continente: "<<acum<<endl;	
		}
		else cout<<"No se ha encontrado informacion en este continente"<<endl;
	}
}

void nombre(){
	if (cantcontinentes < 5){
		cout<<"Ingrese el nombre del pais: ";
		getline (cin, total[cantcontinentes].nombre);
		cout<<"Capital: ";
		getline (cin, total[cantcontinentes].capital);
		cout<<"Ingrese a que continente pertenece dicho pais: ";
		getline (cin, total[cantcontinentes].ubicacion);
		cout<<"Numero de habitantes: ";
		cin>>total[cantcontinentes].habitantes;
		cin.ignore();
		cout<<"Edad promedio en dicho pais: ";
		cin>>total[cantcontinentes].edad;
		cin.ignore();
		
		cantcontinentes++;
	}
	else cout<<"Lo sentimos, espacio lleno"<<endl;
}

int main(){
	int opcion = 0;
	while(opcion!=5){
		cout << "\n1. Informacion sobre el pais \n";
    	cout << "2. Numero de habitantes total del continente\n";
    	cout << "3. Edad promedio\n";
    	cout << "4. Capital con mayor cantidad de habitantes\n";
		cout << "5. Salir\n";
	    cout << "Opcion: ";
    	cin >> opcion;
    	cin.ignore();
    	
    	switch (opcion){
    		case 1: nombre(); break;
    		case 2: habitantestotal(); break ;
    		case 3: edadpromedio(); break;
    		case 4: capitalmayor(); break;
    	}
	}
	return 0;
}
