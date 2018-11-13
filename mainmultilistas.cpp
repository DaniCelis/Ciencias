#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
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
/*	lista<string> Nom;
	lista<string> Ape;
	lista<string> CC;
	lista<string> CE;
	lista<string> TI;
	lista<int> Numid;
	lista<char> Fem;
	lista<char> Mas;
	lista<int> Cel;
	lista<int> Fijo;
	lista<char> Email;
	lista<char> FecNacim;
	lista<string> CiudNacim;
	lista<string> PaisNacim;
	lista<string> CiudResid;
	lista<char> Direccion;
	lista<string> Barrio;
*/	
	Hijos<string> Hijos;
	
	
	
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
	int ingnumid=0;
	int ingsexo=0;
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

	string NombreHijo;
	string FechaNaciHijo;
	int edad;
		
	do{
		
		cout<<"Menu: \n1. Ingrese Datos \n2. Consulte Datos\n3. Eliminar Datos\n4. Terminar"<<endl;
		cin>>opcionmenu;
		if(opcionmenu>4){
			cout<<"Numero Invalido"<<endl;
		}else{
			switch(opcionmenu){
				case 1: 
					ingid++;
					cout<<"id"<<ingid<<endl;

/*					cout<<"Ingrese Nombre"<<endl;
					cin>>ingnombre;
					Nom.insertarLista(ingnombre);
					
					cout<<"Ingrese Apellido"<<endl;
					cin>>ingapellido;
					Ape.insertarLista(ingapellido);
					
					cout<<"Ingrese Tipo de ID\n"
						"1. Cedula Ciudadania\n"
						"2. Cedula Extranjeria\n"
						"3. Tarjeta Identidad"<<endl;
					cin>>ingtipoid;
					
					switch(ingtipoid){
							case 1:
								CC.insertarLista("CC");
								break;
							case 2:
								CE.insertarLista("CE");
								break;
							case 3:
						    	TI.insertarLista("TI");
						    	break;
							default:
								cout<<"Dato incorrecto"<<endl;
								break;
						}
					
					cout<<"Ingrese Numero de ID"<<endl;
					cin>>ingnumid;
					Numid.insertarLista(ingnumid);
					
					cout<<"Ingrese Sexo\n"
						"1. Femenino\n"
						"2. Masculino"<<endl;
					cin>>ingsexo;
					
					switch(ingsexo){
							case 1:
								Fem.insertarLista("F");
								break;
							case 2:
								Mas.insertarLista("M");
								break;
							default:
								cout<<"Dato incorrecto"<<endl;
								break;
					}
					
					cout<<"Ingrese Numero Telefono Celular"<<endl;
					cin>>ingcelular;
					Cel.insertarLista(ingid);
					
					cout<<"Ingrese Numero Telefono Fijo"<<endl;
					cin>>ingfijo;
					Fijo.insertarLista(ingid);
					
					cout<<"Ingrese Email"<<endl;
					cin>>ingemail;
					Email.insertarLista(ingid);
					
					cout<<"Ingrese Fecha de Nacimiento"<<endl;
					cin>>ingfechanacimiento;
					FecNacim.insertarLista(ingid);
					
					cout<<"Ingrese Ciudad de Nacimiento"<<endl;
					cin>>ingciudadnacimiento;
					CiudNacim.insertarLista(ingid);
					
					cout<<"Ingrese Pais de Nacimiento"<<endl;
					cin>>ingpaisnacimiento;
					PaisNacim.insertarLista(ingid);
					
					cout<<"Ingrese Ciudad de Residencia"<<endl;
					cin>>ingciudadresidencia;
					CiudResid.insertarLista(ingid);
					
					cout<<"Ingrese Direccion"<<endl;
					cin>>ingdireccion;
					Direccion.insertarLista(ingid);
					
					cout<<"Ingrese Barrio"<<endl;
					cin>>ingbarrio;
					Barrio.insertarLista(ingid);
*/					
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
									
									cout<<"Nacio"<<dia1<<" Actual"<<dia2<<endl;
									string mes1=FechaNaciHijo.substr(3,2);
									string mes2=actual.substr(3,2);
									cout<<"Nacio"<<mes1<<" Actual"<<mes2<<endl;
									edad=atoi(cad2.c_str())- atoi(cad1.c_str());
									
									if(mes1>=mes2){
										if(dia1>dia2){
											edad=edad-1;
										}
									}

 									cout<<edad;
									Hijos.insertarHijo(NombreHijo, FechaNaciHijo, edad);
								}
								break;
							case 'N':
								ingnumhijos=0;
								break;
							default:
								cout<<"Dato incorrecto"<<endl;
								break;
					}
					break;	
					
				case 2 : 
					cout<<"Consulte Datos"<<endl;
					//Aqui falta hacer la estructura de la consulta, pero ya estan bien
					cout<<Hijos.retornarHijo(1)<<endl;
				//	cout<<Nom.retornarLista(2)<<endl;
					break;
				case 3:
					cout<<"Eliminar Datos"<<endl;
					//No he implementado ninguno de eliminar porque no super como jeje
					//cout<<Sis.eliminarCarrera(1);
					break;
			}
		}
		
	}while(opcionmenu!=4);

}
