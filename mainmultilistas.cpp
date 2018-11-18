#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include "multilistas2.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string fecha(){
	time_t t;
  	struct tm *tm;
  	char fechayhora[100];

	t=time(NULL);
	tm=localtime(&t);
	strftime(fechayhora, 100, "%d/%m/%Y", tm);
//	printf ("Hoy es: %s\n", fechayhora);
	return fechayhora;
	
	
}


int main(int argc, char** argv) {
	int opcionmenu=0;

	Hijos<string> Hijos;
	Sucursal<string> Sucursal;
	persona<string> Persona;
	
	lista<string> Fem;
	lista<string> Mas;
	
/*	hobbie<int> Dan;
	hobbie<int> Nat;
	hobbie<int> Bei;
	hobbie<int> Bas;
	
	edad<int> Edad;
*/	
	
	int ingid=0;
	string ingnombre="";
	string ingapellido="";
	int ingtipoid=0;
	string tipoid="";
	int ingnumid=0;
	int ingsexo=0;
	char sexo=0;
	int ingcelular=0;
	int ingfijo=0;
	string ingemail="";
	string ingfechanacimiento="";
	string ingciudadnacimiento="";
	string ingpaisnacimiento="";
	string ingciudadresidencia="";
	string ingdireccion="";
	string ingbarrio="";
	char inghijos=0;	
	int ingnumhijos=0;
	int ingsucursal=0;

	string NombreHijo;
	string FechaNaciHijo;
	int edadHijo;
	int edadPersona;
	string nomsucursal;
	string direcsucursal;
	string barriosucursal;
	string gerensucursal;
	string sucursal;
	string sucursal2;
	int consultasucursal;
	string per1,dia3,dia4,mes3,mes4,actual,cad2;
	int cont =1;
	
	
	//carga del archivo
	
	
	string texto;
	ifstream archivo;
	
	archivo.open("Datos.txt", ios::in);

	while(!archivo.eof()) {
      getline(archivo,texto);
      
      cout<<texto<<endl;
	}
		
	do{
		
		cout<<"Menu: \n1. Ingrese Datos \n2. Consulte Datos\n3. Eliminar Datos\n4. Manejo de Sucursales\n"<<endl;
		cin>>opcionmenu;
		if(opcionmenu>5){
			cout<<"Numero Invalido"<<endl;
		}else{
			switch(opcionmenu){
				case 1: 
					ingid++;
					cout<<"id"<<ingid<<endl;

					cout<<"Ingrese Nombre"<<endl;
					cin>>ingnombre;
					
					cout<<"Ingrese Apellido"<<endl;
					cin>>ingapellido;
					
					cout<<"Ingrese Tipo de ID\n"
						"1. Cedula Ciudadania\n"
						"2. Cedula Extranjeria\n"
						"3. Tarjeta Identidad"<<endl;
					cin>>ingtipoid;
					
					switch(ingtipoid){
							case 1:
								tipoid="CC";
								break;
							case 2:
								tipoid="CE";
								break;
							case 3:
						    	tipoid="TI";
						    	break;
							default:
								cout<<"Dato incorrecto"<<endl;
								break;
						}
					
					cout<<"Ingrese Numero de ID"<<endl;
					cin>>ingnumid;
					
					
					cout<<"Ingrese Sexo\n"
						"1. Femenino\n"
						"2. Masculino"<<endl;
					cin>>ingsexo;
					
					switch(ingsexo){
							case 1:
								Fem.insertarLista("F");
								sexo='F';
								break;
							case 2:
								Mas.insertarLista("M");
								sexo='M';
								break;
							default:
								cout<<"Dato incorrecto"<<endl;
								break;
					}
					
					cout<<"Ingrese Numero Telefono Celular"<<endl;
					cin>>ingcelular;
					
					
					cout<<"Ingrese Numero Telefono Fijo"<<endl;
					cin>>ingfijo;
					
					
					cout<<"Ingrese Email"<<endl;
					cin>>ingemail;
					
					
					cout<<"Ingrese Fecha de Nacimiento Formato: DD/MM/AAAA"<<endl;
					cin>>ingfechanacimiento;
					
					per1 = ingfechanacimiento.substr (6);
					actual = fecha();
					cad2 = actual.substr (6);	
					dia3= ingfechanacimiento.substr(0,2);
					dia4=actual.substr(0,2);
							
				//	cout<<"Nacio"<<dia3<<" Actual"<<dia4<<endl;
					mes3=ingfechanacimiento.substr(3,2);
					mes4=actual.substr(3,2);
				//	cout<<"Nacio"<<mes3<<" Actual"<<mes4<<endl;
					edadPersona=atoi(cad2.c_str())- atoi(per1.c_str());
									
					if(mes3>=mes4){
						if(dia3>dia4){
							edadPersona=edadPersona-1;
							}
					}

					
					cout<<"Ingrese Ciudad de Nacimiento"<<endl;
					cin>>ingciudadnacimiento;
					
					
					cout<<"Ingrese Pais de Nacimiento"<<endl;
					cin>>ingpaisnacimiento;
					
					
					cout<<"Ingrese Ciudad de Residencia"<<endl;
					cin>>ingciudadresidencia;
					
					
					cout<<"Ingrese Direccion"<<endl;
					cin>>ingdireccion;
					
					
					cout<<"Ingrese Barrio"<<endl;
					cin>>ingbarrio;
					
								
					cout<<"¿Tiene hijos?"<<endl;
					cin>>inghijos;
					
					switch(inghijos){
							case 'S':
								cout<<"Ingrese el numero de hijos"<<endl;
								cin>>ingnumhijos;
								
								for(int i=0; i<ingnumhijos; i++){
									cout<<"Ingrese el nombre del hij@"<<endl;
									cin>>NombreHijo;
									cout<<"Ingrese el fecha de nacimiento del hij@  FORMATO: DD/MM/AAAA"<<endl;
									cin>>FechaNaciHijo;
									string cad1 = FechaNaciHijo.substr (6);
									string actual = fecha();
									string cad2 = actual.substr (6);	
									string dia1=FechaNaciHijo.substr(0,2);
									string dia2=actual.substr(0,2);
									
									//cout<<"Nacio"<<dia1<<" Actual"<<dia2<<endl;
									string mes1=FechaNaciHijo.substr(3,2);
									string mes2=actual.substr(3,2);
									//cout<<"Nacio"<<mes1<<" Actual"<<mes2<<endl;
									edadHijo=atoi(cad2.c_str())- atoi(cad1.c_str());
									
									if(mes1>=mes2){
										if(dia1>dia2){
											edadHijo=edadHijo-1;
										}
									}
 									cout<<edadHijo;
									Persona.insertarHijo(ingid, NombreHijo, FechaNaciHijo, edadHijo);
								}
								break;
							case 'N':
								ingnumhijos=0;
								break;
							default:
								cout<<"Dato incorrecto"<<endl;
								break;
					}
					
					cout<<"Ingrese la sucursal en la que trabaja"<<endl;
					Persona.sucu();
					cin>>ingsucursal;		
					sucursal = Persona.retornarSucursal(ingsucursal);
					
					Persona.insertarPersona(ingid, ingnombre, ingapellido, tipoid, ingnumid, sexo, ingfijo, ingcelular, ingemail, ingfechanacimiento, edadPersona, ingciudadnacimiento,
					ingpaisnacimiento, ingciudadresidencia, ingdireccion, ingbarrio, ingnumhijos, sucursal);
					
					
					
					break;	
					
				case 2 : 
					cout<<"Consulte Datos\n1. Consultar personas por sucursal\n Ingrese el numero de la sucursal "<<endl;
					Persona	.sucu();
					cin>>consultasucursal;
					sucursal2 = Persona.retornarSucursal(consultasucursal);
					cout<<sucursal2<<endl;
					Persona.buscarSucursal(sucursal2);
					cout<<endl;
					//Aqui falta hacer la estructura de la consulta, pero ya estan bien
					
					
					
				//	for(int j=1; j<=ingnumhijos; j++){
				//		cout<<"Hijo "<<Persona.retornarHijo(j)<<endl;
				//	}
					
					

				//	cout<<Nom.retornarLista(2)<<endl;
					break;
				case 3:
					cout<<"Eliminar Datos"<<endl;
					//No he implementado ninguno de eliminar porque no super como jeje
					//cout<<Sis.eliminarCarrera(1);
					break;
				case 4:
					cout<<"Agregar Sucursal"<<endl;
					cout<<"Nombre de la sucursal"<<endl;
					cin>>nomsucursal;
					cout<<"Direccion de la sucursal"<<endl;
					cin>>direcsucursal;
					cout<<"Barrio de la sucursal"<<endl;
					cin>>barriosucursal;
					cout<<"Gerente de la sucursal"<<endl;
					cin>>gerensucursal;
					Persona.insertarSucursal(nomsucursal, direcsucursal, barriosucursal, gerensucursal);
					break;
			}
			
		}
		
	}while(opcionmenu!=5);

}
