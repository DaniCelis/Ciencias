#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include "multilistas2.h"

#define MAX 208
#define MAX2 85

string fecha(){
	time_t t;
  	struct tm *tm;
  	char fechayhora[100];

	t=time(NULL);
	tm=localtime(&t);
	strftime(fechayhora, 100, "%d/%m/%Y", tm);
	return fechayhora;
}

string Convertir(char c){
    return string(0,c);
}

void agregarEmpleado(){
	
	lista<string> Fem;
	lista<string> Mas;
	persona<int> Persona;
	
	char ingid[3];
    char ingnombre[10];
    char ingapellido[20];
    int ingtipoid; 
    char settipoid[2]; 
    char ingdocumento[15];
    int inggenero;
    char genero[2];
    char ingfijo[10];
    char ingcelular[10];
    char ingemail[30];
    char ingfechaNac[10];
    char ingedad[2];
    char ingciudadNac[15];
    char ingpaisNac[15];
    char ingciudadRes[15];
    char ingdireccion[30];
    char ingbarrio[15];
    char inghijos[2];
    char ingnumhijos;
    char ingsucursal;
    int edadPersona;
    char sucursal;

	ofstream personas;
	
    personas.open("Personas.txt",ios::app);
    
    if(!personas)            // If the file was not found, then file is 0, i.e. !file=1 or true.
        cout<<"No existe"<<endl;
	
//	cout<<"id"<<endl;															//Bien
//	cin>>ingid;
//
//	cout<<"Ingrese Nombre"<<endl;
//	cin>>ingnombre;
//					
//	cout<<"Ingrese Apellido"<<endl;
//	cin>>ingapellido;
//	
//	cout<<"Ingrese Tipo de ID\n"
//		"1. Cedula Ciudadania\n"
//		"2. Cedula Extranjeria\n"
//		"3. Tarjeta Identidad"<<endl;
//	cin>>ingtipoid;
//	
//	switch(ingtipoid){
//			case 1:
//				settipoid[0] = 'C';
//				settipoid[1] = 'C';
//				break;
//			case 2:
//				settipoid[0] = 'C';
//				settipoid[1] = 'E';
//				break;
//			case 3:
//		    	settipoid[0] = 'T';
//				settipoid[1] = 'I';
//		    	break;
//			default:
//				cout<<"Dato incorrecto"<<endl;
//				break;
//		}
//	
//	cout<<"Ingrese Numero de ID"<<endl;
//	cin>>ingdocumento;
//	
//	
//	cout<<"Ingrese Sexo\n"
//		"1. Femenino\n"
//		"2. Masculino"<<endl;
//	cin>>inggenero;
//	
//	switch(inggenero){
//			case 1:
//				Fem.insertarLista("F");
//				genero[0] ='F';
//				break;
//			case 2:
//				Mas.insertarLista("M");
//				genero[0] ='M';
//				break;
//			default:
//				cout<<"Dato incorrecto"<<endl;
//				break;
//	}
//	
//	cout<<"Ingrese Numero Telefono Fijo"<<endl;
//	cin>>ingfijo;
//	
//	cout<<"Ingrese Numero Telefono Celular"<<endl;
//	cin>>ingcelular;
//
//	cout<<"Ingrese Email"<<endl;
//	cin>>ingemail;																//Bien
	
	
	cout<<"Ingrese Fecha de Nacimiento Formato: DD/MM/AAAA"<<endl;
	cin>>ingfechaNac;
	
	string per1,dia3,dia4,mes3,mes4,actual,cad2;
	cout<<ingfechaNac<<endl;

//	fechaN =	Convertir(ingfechaNac);
	string fechaN(ingfechaNac);
	cout<<fechaN<<endl;

//	fecha = (new StringBuffer().append(ingfechaNac)).toString();
	
	per1 = fechaN.substr (6);
	actual = fecha();
	cad2 = actual.substr (6);	
	dia3= fechaN.substr(0,2);
	dia4=actual.substr(0,2);
			
	cout<<"Nacio"<<dia3<<" Actual"<<dia4<<endl;
	mes3=fechaN.substr(3,2);
	mes4=actual.substr(3,2);
	cout<<"Nacio"<<mes3<<" Actual"<<mes4<<endl;
	
	edadPersona=atoi(cad2.c_str())- atoi(per1.c_str());
	
	if(mes3>mes4){
		edadPersona= edadPersona-1;
	}else if(mes3==mes4 && dia3>dia4){
		edadPersona= edadPersona-1;
	}	
	itoa(edadPersona, ingedad, 10);

	cout<<"Ingrese Ciudad de Nacimiento"<<endl;
	cin>>ingciudadNac;
	
	cout<<"Ingrese Pais de Nacimiento"<<endl;
	cin>>ingpaisNac;
	
	cout<<"Ingrese Ciudad de Residencia"<<endl;
	cin>>ingciudadRes;
	
	cout<<"Ingrese Direccion"<<endl;
	cin>>ingdireccion;
	
	cout<<"Ingrese Barrio"<<endl;
	cin>>ingbarrio;
				
	cout<<"¿Tiene hijos?"<<endl;
	cin>>inghijos;
	
	switch('inghijos'){
			case 'S':
			case 's':
				cout<<"Ingrese el numero de hijos"<<endl;
				cin>>ingnumhijos;
				
//				for(int i=0; i<ingnumhijos; i++){
//					cout<<"Ingrese el nombre del hij@"<<endl;
//					cin>>NombreHijo;
//					cout<<"Ingrese el fecha de nacimiento del hij@  FORMATO: DD/MM/AAAA"<<endl;
//					cin>>FechaNaciHijo;
//					string cad1 = FechaNaciHijo.substr (6);
//					string actual = fecha();
//					string cad2 = actual.substr (6);	
//					string dia1=FechaNaciHijo.substr(0,2);
//					string dia2=actual.substr(0,2);
//					
//					//cout<<"Nacio"<<dia1<<" Actual"<<dia2<<endl;
//					string mes1=FechaNaciHijo.substr(3,2);
//					string mes2=actual.substr(3,2);
//					//cout<<"Nacio"<<mes1<<" Actual"<<mes2<<endl;
//					edadHijo=atoi(cad2.c_str())- atoi(cad1.c_str());
//					
//					if(mes1>=mes2){
//						if(dia1>dia2){
//							edadHijo=edadHijo-1;
//						}
//					}
//					cout<<edadHijo;
//					Persona.insertarHijo(ingid, NombreHijo, FechaNaciHijo, edadHijo);
//				}
				break;
			case 'N':
			case 'n':
				ingnumhijos=0;
				break;
			default:
				cout<<"Dato incorrecto"<<endl;
				break;
	}
	
	cout<<"Ingrese la sucursal en la que trabaja"<<endl;
	Persona.sucu();
	cin>>ingsucursal;		
//	sucursal = Persona.retornarSucursal(ingsucursal);
	    
//	Persona.insertarPersona(ingid, ingnombre, ingapellido, settipoid, ingdocumento, genero, ingfijo, ingcelular, ingemail, ingfechaNac, edadPersona, 
//		ingciudadNac, ingpaisNac, ingciudadRes, ingdireccion, ingbarrio, ingnumhijos, sucursal);
					
	
	
	//nodoEmpleado<char> empleado;

	
	
	personas.close();
		
}

//void cargarSucursales(){
//	
//	persona<string> Persona;
//	
//	char line[MAX2];
//	char nombreSuc[20];
//    char direccionSuc[30];
//    char barrioSuc[15];
//    char agenteSuc[20];
//	
//	FILE *sucursales=fopen("Sucursales.txt","rt");
//    
//    if(!sucursales)            // If the file was not found, then file is 0, i.e. !file=1 or true.
//        cout<<"No existe"<<endl;    // The file was not found.
//
//    int i=0;
//    fgets(line,MAX2,sucursales);
//    
//    while(!feof(sucursales)) {
//        i++;
//        sscanf(line,"[^:]:%[^:]:%[^:]:%[^\n]", nombreSuc, direccionSuc, barrioSuc, agenteSuc); //%[^:]:
//    	fflush(stdin);
//    	cout<<"Nombre Sucursal: "<<nombreSuc<<endl;
//    	cout<<"Direccion Sucursal: "<<direccionSuc<<endl;
//    	cout<<"Barrio Sucursal: "<<barrioSuc<<endl;
//    	cout<<"Agente Sucursal: "<<agenteSuc<<endl;
//    	
//		Persona.insertarSucursal(nombreSuc, direccionSuc, barrioSuc, agenteSuc);
//		
//		fgets(line,MAX2,sucursales); 
//	}
//	fclose(sucursales);
//	
//}

void cargarPersonas(){
	
	cout<<"Cargar Personas"<<endl;
	
	char line[MAX];
	char id[3];
    char nombre[10];
    char apellido[20];
    char tipoid[2]; 
    char cedula[10];
    char genero[2];
    char fijo[10];
    char celular[10];
    char email[30];
    char fechaNac[10];
    char edad[2];
    char ciudadNac[15];
    char paisNac[15];
    char ciudadRes[15];
    char direccion[30];
    char barrio[15];
    char hijos[2];
    char numhijos[2];
    char sucursal[15];
    
    persona<char> Persona;
    
    FILE *archivo=fopen("Personas.txt","rt");
    
    if(!archivo)            // If the file was not found, then file is 0, i.e. !file=1 or true.
        cout<<"No existe"<<endl;    // The file was not found.
    else
    	cout<<"Existe"<<endl;

    int i=0;
    fgets(line,MAX,archivo);
    
    while(!feof(archivo)) {
        i++;
        sscanf(line,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]", id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, hijos, numhijos, sucursal); //%[^:]:
    	fflush(stdin);
    	cout<<"Id: "<<id<<endl;
    	cout<<"Nombre: "<<nombre<<endl;
    	cout<<"Apellido: "<<apellido<<endl;
    	cout<<"TipoId: "<<tipoid<<endl;
    	cout<<"Cedula: "<<cedula<<endl;
    	cout<<"Genero: "<<genero<<endl;
    	cout<<"Fijo: "<<fijo<<endl;
    	cout<<"Celular: "<<celular<<endl;
    	cout<<"Email: "<<email<<endl;
    	cout<<"Fecha Nacimiento: "<<fechaNac<<endl;
    	cout<<"Edad: "<<edad<<endl;
    	cout<<"Ciudad Nacimiento: "<<ciudadNac<<endl;
    	cout<<"Pais Nacimiento: "<<paisNac<<endl;
    	cout<<"Ciudad Residencia: "<<ciudadRes<<endl;
    	cout<<"Direccion: "<<direccion<<endl;
    	cout<<"Barrio: "<<barrio<<endl;
    	cout<<"Hijos: "<<hijos<<endl;
    	cout<<"Numero Hijos: "<<numhijos<<endl;
    	cout<<"Sucursal: "<<sucursal<<endl;
    	
    	Persona.insertarPersona(id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, hijos, numhijos, sucursal);
    	
     //   cout<<"Cedula: "<<idcedula<<endl;
		
		fgets(line,MAX,archivo);
    }
    
    cout<<"Line: "<<i<<endl;
    fclose(archivo);
	
}


int main(int argc, char** argv) {


	persona<char> Persona;
	
	int opcion, dato;	
	do{
		cin>>opcion;
		switch(opcion){
			case 1:
				agregarEmpleado();
				break;
			case 2:	
				cargarPersonas();
				break;
			case 3:
				cout<<"Consulte Datos"<<endl;
				cin>>dato;
				Persona.retornarPersona(dato);
		}
	}while(opcion!=0);
	
}
