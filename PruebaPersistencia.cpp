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
#define MAX3 39
#define MAX4 40

string fecha(){
	time_t t;
  	struct tm *tm;
  	char fechayhora[100];

	t=time(NULL);
	tm=localtime(&t);
	strftime(fechayhora, 100, "%d/%m/%Y", tm);
	return fechayhora;
}

void print(FILE *fp){
	char ch;
	
	while((ch = fgetc(fp)) != EOF ){
		cout<<ch;
	}
}
//void editar(string datos);

void funcionPrincipal(int opcionPrincipal){
	
//	cout<<"--------------------------------------------------------------Cargar Personas-------------------------------------------------------"<<endl;
	
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
    char actividad[15];
    char hijos[2];
    char numhijos[2];
    char sucursal[15];
    
    persona<string> Persona;
    
    FILE *archivo=fopen("Personas.txt","rt");
    
    if(!archivo)            // If the file was not found, then file is 0, i.e. !file=1 or true.
        cout<<"No existe"<<endl;    // The file was not found.
    else
    	cout<<"Existe"<<endl;

    int i=0;
    fgets(line,MAX,archivo);
    cout<<"| Id | Nombre | Apellido | Tipo ID | Cedula | Genero | Fijo | Celular | Email | Fecha Nacimiento |"<<endl;
    cout<<"| Edad | Ciud Naci | Pais Naci | Ciud Resid | Direccion | Barrio | Actividad | Hijos | Num Hijos | Sucursal |"<<endl;
    while(!feof(archivo)) {
        i++;
        sscanf(line,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]", id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, actividad, hijos, numhijos, sucursal); //%[^:]:
    	fflush(stdin);
    
    	cout<<"| "<<id<<" | "<<nombre<<" | "<<apellido<<" | "<<tipoid<<" | "<<cedula<<" | "<<genero<<" | "<<fijo<<" | "<<celular<<" | "<<email<<" | "<<fechaNac<<" | "<<endl;
   	    cout<<"| "<<edad<<" | "<<ciudadNac<<" | "<<paisNac<<" | "<<ciudadRes<<" | "<<direccion<<" | "<<barrio<<" | "<<actividad<<" | "<<hijos<<" | "<<numhijos<<" | "<<sucursal<<endl;
		
		Persona.insertarPersona(id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, actividad, hijos, numhijos, sucursal);
		
		fgets(line,MAX,archivo);
    }
    cout<<"Line: "<<i<<endl;
    
    //	cout<<"--------------------------------------------------------------Cargar Sucursales-------------------------------------------------------"<<endl;
    
	char line2[MAX2];
	char nombreSuc[20];
    char direccionSuc[30];
    char barrioSuc[15];
    char agenteSuc[20];
	
	Sucursal<string> Sucursal;
	
	FILE *sucursales=fopen("Sucursales.txt","rt");
    
    if(!sucursales)      
        cout<<"No existe"<<endl;   

    int j=0;
    fgets(line2,MAX2,sucursales);
    
    	cout<<"| Nombre Sucursal | Direccion Sucursal | Barrio Sucursal | Agente Sucursal | "<<endl;
    
    while(!feof(sucursales)) {
        j++;
        sscanf(line2,"%[^:]:%[^:]:%[^:]:%[^\n]", nombreSuc, direccionSuc, barrioSuc, agenteSuc); //%[^:]:
    	fflush(stdin);
		
    	cout<<" | "<<nombreSuc<<" | "<<direccionSuc<<" | "<<barrioSuc<<" | "<<agenteSuc<<" | "<<endl;
    	
		Sucursal.insertarSucursal(nombreSuc, direccionSuc, barrioSuc, agenteSuc);
    	
		fgets(line2,MAX2,sucursales); 
	}
	cout<<"Line: "<<j<<endl;
	
	//	cout<<"--------------------------------------------------------------Cargar Hijos-------------------------------------------------------"<<endl;
    
	char line3[MAX3];
	char idPadre[2];
	char nombreHijo[25];
    char fechaNacHijo[10];
    char edadHijo[2];
    
	
	FILE *hijosArch=fopen("Hijos.txt","rt");
    
    if(!hijosArch)      
        cout<<"No existe"<<endl;   

    int k=0;
    fgets(line3,MAX3,hijosArch);
    
    	cout<<"| idPadre | Nombre Hijo | Fecha Naci Hijo | Edad Hijo | "<<endl;
    
    while(!feof(hijosArch)) {
        k++;
        sscanf(line3,"%[^:]:%[^:]:%[^:]:%[^\n]", idPadre, nombreHijo, fechaNacHijo, edadHijo); //%[^:]:
    	fflush(stdin);
    	cout<<" | "<<idPadre<<" | "<<nombreHijo<<" | "<<fechaNacHijo<<" | "<<edadHijo<<" | "<<endl;
    	
    	Persona.insertarHijo(idPadre, nombreHijo, fechaNacHijo, edadHijo);
    	
		fgets(line3,MAX3,hijosArch); 
	}
	cout<<"Line: "<<k<<endl;
	
	//	cout<<"--------------------------------------------------------------Cargar Hijos-------------------------------------------------------"<<endl;
    
	char line4[MAX4];
	char ciudad[15];
	char pais[15];
	
	Ciudad<string> Ciudad;
	
	FILE *paises=fopen("Paises.txt","rt");
    
    if(!paises)      
        cout<<"No existe"<<endl;   

    int m=0;
    fgets(line4,MAX4,paises);
    
    	cout<<"| Ciudad | Pais |"<<endl;
    
    while(!feof(paises)) {
        m++;
        sscanf(line4,"%[^:]:%[^\n]", ciudad, pais); //%[^:]:
    	fflush(stdin);
    
    	cout<<" | "<<ciudad<<" | "<<pais<<" | "<<endl;
    	
    	Ciudad.insertarCiudad(ciudad, pais);
		    	
		fgets(line4,MAX4,paises); 
	}
	cout<<"Line: "<<m<<endl;
	
	//	cout<<"--------------------------------------------------------------Realizar Operaciones -------------------------------------------------------"<<endl;

	switch(opcionPrincipal){
		case 1:{
			
		//	cout<<"--------------------------------------------------------------AGREGAR EMPLEADO -------------------------------------------------------"<<endl;	
			lista<string> Fem;
			lista<string> Mas;
			
			char ingid[3];
		    char ingnombre[10];
		    char ingapellido[20];
		    int ingtipoid; 
		    char settipoid[2]; 
		    char ingdocumento[15];
		    int inggenero;
		    char aggenero[2];
		    char ingfijo[10];
		    char ingcelular[10];
		    char ingemail[30];
		    char ingfechaNac[10];
		    char ingedad[2];
		    int intciudad;
		    char ingciudadNac[15];
		    char ingpaisNac[15];
		    int intresid;
		    char ingciudadRes[15];
		    char ingdireccion[30];
		    char ingbarrio[15];
		    char ingactividad[25];
		    char aghijos;
		    char inghijos[2];
		    char ingnumhijos[2];
		    int ingsucursal;
		    int edadPersona;
		    char agsucursal[15];
		    
		    char NombreHijo[25];
		    char FechaNaciHijo[10];
		    int edadHijo;
		    char agedadHijo[2];
		
			ofstream personas;			
		    personas.open("Personas.txt",ios::app);
		    
		    ofstream hijosArch2;			
		    hijosArch2.open("Hijos.txt",ios::app);
		    
		    if(!personas)           
		        cout<<"No existe"<<endl;
		    
		    if(!hijosArch2)           
		        cout<<"No existe"<<endl;
		        
		    int valorID = atoi(id);
		    
			if(valorID>i){
		    	valorID++;
			}   

			cout<<"El id es: "<<endl;
			itoa(valorID, ingid, 10);
			cout<<ingid;													
		
			cout<<endl<<"Ingrese Nombre"<<endl;
			cin>>ingnombre;
							
			cout<<"Ingrese Apellido"<<endl;
			cin>>ingapellido;
			do{
			cout<<"Ingrese Tipo de ID\n"
				"1. Cedula Ciudadania\n"
				"2. Cedula Extranjeria\n"
				"3. Tarjeta Identidad"<<endl;
			cin>>ingtipoid;
			switch(ingtipoid){
					case 1:
						settipoid[0] = 'C';
						settipoid[1] = 'C';
						break;
					case 2:
						settipoid[0] = 'C';
						settipoid[1] = 'E';
						break;
					case 3:
				    	settipoid[0] = 'T';
						settipoid[1] = 'I';
				    	break;
					default:
						cout<<"Dato incorrecto,intenta de nuevo"<<endl;
						break;
				}
				
			}while(ingtipoid>3 || ingtipoid<1);
			cout<<"Ingrese Numero de ID"<<endl;
			cin>>ingdocumento;
			
			do{
			cout<<"Ingrese Sexo\n"
				"1. Femenino\n"
				"2. Masculino"<<endl;
			cin>>inggenero;
			
				switch(inggenero){
					case 1:
						Fem.insertarLista("F");
						aggenero[0] ='F';
						break;
					case 2:
						Mas.insertarLista("M");
						aggenero[0] ='M';
						break;
					default:
						cout<<"Dato incorrecto,Ingresalo de nuevo"<<endl;
						break;
				}	
			}while(inggenero>2 || inggenero<1 );
			
			cout<<"Ingrese Numero Telefono Fijo"<<endl;
			cin>>ingfijo;
			
			cout<<"Ingrese Numero Telefono Celular"<<endl;
			cin>>ingcelular;
		
			cout<<"Ingrese Email"<<endl;
			cin>>ingemail;																
			
			cout<<"Ingrese Fecha de Nacimiento Formato: DD/MM/AAAA"<<endl;
			cin>>ingfechaNac;
			
			string per1,dia3,dia4,mes3,mes4,actual,cad2;
			string fechaN(ingfechaNac);
			
			per1 = fechaN.substr (6);
			actual = fecha();
			cad2 = actual.substr (6);	
			dia3= fechaN.substr(0,2);
			dia4=actual.substr(0,2);
					
			mes3=fechaN.substr(3,2);
			mes4=actual.substr(3,2);
			
			edadPersona=atoi(cad2.c_str())- atoi(per1.c_str());
			
			if(mes3>mes4){
				edadPersona= edadPersona-1;
			}else if(mes3==mes4 && dia3>dia4){
				edadPersona= edadPersona-1;
			}	
			itoa(edadPersona, ingedad, 10);
			
			cin.ignore();

			do{
				cout<<"Ingrese Ciudad de Nacimiento"<<endl;
				Ciudad.ciud();
				cin>>intciudad;
				if(intciudad>m){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intciudad>m);
			strcpy(ingciudadNac,Ciudad.retornarCiudad(intciudad).c_str());
			cout<<ingciudadNac<<endl;
			
			cout<<"Pais de Nacimiento"<<endl;
			strcpy(ingpaisNac,Ciudad.retornarPais(intciudad).c_str());	
			cout<<ingpaisNac<<endl;
						
			do{
				cout<<"Ingrese Ciudad de Residencia"<<endl;
				Ciudad.ciud();
				cin>>intresid;
				if(intresid>m){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intresid>m);
			strcpy(ingciudadRes,Ciudad.retornarCiudad(intresid).c_str());	
			cout<<ingciudadRes<<endl;		

			cout<<"Ingrese Direccion"<<endl;
			cin.getline(ingdireccion,30);
			
			cout<<"Ingrese Barrio"<<endl;
			cin.getline(ingbarrio,15);
			
			int opc;
			
			do{
			cout<<"Ingrese Actividad Laboral"<<endl;
			cout<<"1. Artes\n2. Ingenieria\n3. Ciencias Sociales\n4. Areas de la salud\n5. Otros "<<endl;
			
			cin>>opc;
			switch(opc){
				case 1:
					ingactividad[0] = 'A';
					ingactividad[1] = 'r';
					ingactividad[2] = 't';
					ingactividad[3] = 'e';
					ingactividad[4] = 's';
					break;
				case 2:
					ingactividad[0] = 'I';
					ingactividad[1] = 'n';
					ingactividad[2] = 'g';
					ingactividad[3] = 'e';
					ingactividad[4] = 'n';
					ingactividad[5] = 'i';
					ingactividad[6] = 'e';
					ingactividad[7] = 'r';
					ingactividad[8] = 'i';
					ingactividad[9] = 'a';
					break;
				case 3:
				//	ingactividad='Ciencias Sociales';
					ingactividad[0] = 'C';
					ingactividad[1] = 'i';
					ingactividad[2] = 'e';
					ingactividad[3] = 'n';
					ingactividad[4] = 'c';
					ingactividad[5] = 'i';
					ingactividad[6] = 'a';
					ingactividad[7] = 's';
					ingactividad[8] = ' ';
					ingactividad[9] = 'S';
					ingactividad[10] = 'o';
					ingactividad[11] = 'c';
					ingactividad[12] = 'i';
					ingactividad[13] = 'a';
					ingactividad[14] = 'l';
					ingactividad[15] = 'e';
					ingactividad[16] = 's';
					break;
				case 4:
					ingactividad[0] = 'A';
					ingactividad[1] = 'r';
					ingactividad[2] = 'e';
					ingactividad[3] = 'a';
					ingactividad[4] = 's';
					ingactividad[5] = ' ';
					ingactividad[6] = 'd';
					ingactividad[7] = 'e';
					ingactividad[8] = ' ';
					ingactividad[9] = 'l';
					ingactividad[10] = 'a';
					ingactividad[11] = ' ';
					ingactividad[12] = 's';
					ingactividad[13] = 'a';
					ingactividad[14] = 'l';
					ingactividad[15] = 'u';
					ingactividad[16] = 'd';			
					break;
				case 5:
					ingactividad[0] = 'O';
					ingactividad[1] = 't';
					ingactividad[2] = 'r';
					ingactividad[3] = 'o';
					ingactividad[4] = 's';
					break;
				default:
					cout<<"Dato incorrecto, ingresalo de nuevo"<<endl;
					break;
				}
			}while(opc>5 || opc<1);	
			
			bool cond = false;
			do{
	
				cout<<"Tiene hijos? S o N"<<endl;
				cin>>aghijos;
			
				if(aghijos == 'S' || aghijos == 'N'){
					cond=true;
				}
				switch(aghijos){
					case 'S':
						cout<<"Ingrese el numero de hijos"<<endl;
						int numero;
						cin>>numero;
						inghijos[0] = 'S';
						
						itoa(numero,ingnumhijos,10);
						cout<<ingnumhijos<<endl;						
						for(int w=0; w<numero; w++){
							cout<<"Ingrese el nombre del hij@"<<endl;
							cin>>NombreHijo;
							cout<<"Ingrese el fecha de nacimiento del hij@  FORMATO: DD/MM/AAAA"<<endl;
							cin>>FechaNaciHijo;
							
							
							string fechaNH(FechaNaciHijo);
							
							string cad1 = fechaNH.substr (6);
							string actual = fecha();
							string cad2 = actual.substr (6);	
							string dia1=fechaNH.substr(0,2);
							string dia2=actual.substr(0,2);

							string mes1=fechaNH.substr(3,2);
							string mes2=actual.substr(3,2);

							edadHijo=atoi(cad2.c_str())- atoi(cad1.c_str());
							
							if(mes1>mes2){
								edadHijo= edadHijo-1;
							}else if(mes1==mes2 && dia1>dia2){
								edadHijo= edadHijo-1;
							}	
							
							itoa(edadHijo, agedadHijo, 10);
							cout<<agedadHijo<<endl;
							
							hijosArch2<<ingid<<":"<<NombreHijo<<":"<<FechaNaciHijo<<":"<<agedadHijo<<endl;							
							Persona.insertarHijo(ingid, NombreHijo, FechaNaciHijo, agedadHijo);
							
							hijosArch2.close();
						}
						break;
					case 'N':
						ingnumhijos[0]='0';
						ingnumhijos[1]=' ';
						inghijos[0]='N';
						break;
					default:
						cout<<"Dato incorrecto,ingresa de nuevo"<<endl;
						break;
				}
			}while(cond == false);
			
			do{
				cout<<"Ingrese el numero de la sucursal en la que trabaja"<<endl;
				Sucursal.sucu();
				cin>>ingsucursal;
				if(ingsucursal>j){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(ingsucursal>j);
			strcpy(agsucursal,Sucursal.retornarSucursal(ingsucursal).c_str());	 
			    
			Persona.insertarPersona(ingid, ingnombre, ingapellido, settipoid, ingdocumento, aggenero, ingfijo, ingcelular, ingemail, ingfechaNac, ingedad, 
				ingciudadNac, ingpaisNac, ingciudadRes, ingdireccion, ingbarrio, ingactividad, inghijos, ingnumhijos, agsucursal);
					
			personas<<ingid<<":"<<ingnombre<<":"<<ingapellido<<":"<<settipoid<<":"<<ingdocumento<<":"<<aggenero<<":"<<ingfijo<<":"<<ingcelular<<":"<<ingemail<<":"<<ingfechaNac<<":"<<ingedad<<":"
				<<ingciudadNac<<":"<<ingpaisNac<<":"<<ingciudadRes<<":"<<ingdireccion<<":"<<ingbarrio<<":"<<ingactividad<<":"<<inghijos<<":"<<ingnumhijos<<":"<<agsucursal<<endl;		
			
			personas.close();
			break;
		}
		case 2:{
			//	cout<<"--------------------------------------------------------------AGREGAR SUCURSAL -------------------------------------------------------"<<endl;	
			
		//	Sucursal<string> Sucursal;
			
			char nombreSuc[20];
		    char direccionSuc[30];
		    char barrioSuc[15];
		    char agenteSuc[20];
		    
		    cin.ignore();
		
			ofstream sucursales2;
		    sucursales2.open("Sucursales.txt",ios::app);
		    
			cout<<"Ingrese nombre de la sucursal"<<endl;
			cin.getline(nombreSuc,20);
			
			cout<<"Ingrese direccion de la sucursal"<<endl;
			cin.getline(direccionSuc,30);
			
			cout<<"Ingrese barrio de la sucursal"<<endl;
			cin.getline(barrioSuc,15);
			
			cout<<"Ingrese agente de la sucursal"<<endl;
			cin.getline(agenteSuc,20);
			
			Sucursal.insertarSucursal(nombreSuc, direccionSuc, barrioSuc, agenteSuc); 
			sucursales2<<nombreSuc<<":"<<direccionSuc<<":"<<barrioSuc<<":"<<agenteSuc<<endl;
			
			sucursales2.close();
		
		break;
		}
		case 3:{
			//	cout<<"-------------------------------------------------------------- CONSULTAR DATOS -------------------------------------------------------"<<endl;
			
			Sucursal.sucu();
			Persona.retornarPersona(3);
			cout<<Persona.retornarHijo(1)<<endl;
			cout<<Persona.retornarHijo(2)<<endl;
			cout<<Persona.retornarHijo(3)<<endl;
			break;
		}	
		
		case 4:{
			//	cout<<"-------------------------------------------------------------- EDITAR DATOS -------------------------------------------------------"<<endl;
			int intid,sel;
			int aux = atoi(id);
		    
			if(aux>i){
		    	aux++;
			}   
			do{
				cout<<"Que persona deseas editar"<<endl;
				Persona.rePe();
				cin>>intid;
				if(intid>aux){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intid>aux);
			
			string  auxNom="",auxApe="",auxFij="",auxCel="",auxCor="",auxDir="",auxBar="",auxhij="",auxnumHij="";
			
			auxNom=Persona.retornarNo(intid);
			auxApe=Persona.retornarAp(intid);
			auxFij=Persona.retornarFi(intid);
			auxCel=Persona.retornarCe(intid);
			auxCor=Persona.retornarEm(intid);
			auxDir=Persona.retornarDi(intid);
			auxBar=Persona.retornarBa(intid);
			auxhij=Persona.retornarHi(intid);
			auxnumHij=Persona.retornarNumHij(intid);
			
			
			do{
				cout<<"Seleciona el dato que deseas editar:\n1.Nombre\n2.Apellido"
				"\n3.Telefono Fijo\n4.Telefono Celular\n5.Correo"
				"\n6.Direccion\n7.Barrio\n8.actualizar info hijos\n9.Salir\n";
				cin>>sel;
				switch(sel){
					case 1:
						cout<<"Seleccionaste nombre\nEl actual es: "<<auxNom<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxNom;
						cout<<"El nuevo nombre es: "<<auxNom<<endl;
						break;
						
					case 2:
						cout<<"Seleccionaste apellido\nEl actual es: "<<auxApe<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxApe;
						cout<<"El nuevo apellido  es: "<<auxApe<<endl;
						break;
					case 3:
						cout<<"Seleccionaste telefono fijo\nEl actual es: "<<auxFij<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxFij;
						cout<<"El nuevo fijo es: "<<auxFij<<endl;
						break;
						
					case 4:
						cout<<"Seleccionaste telefono celular\nEl actual es: "<<auxCel<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxCel;
						cout<<"El nuevo celular es: "<<auxCel<<endl;
						break;
						
					case 5:
						cout<<"Seleccionaste telefono Email\nEl actual es: "<<auxCor<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxCor;
						cout<<"El nuevo Email es: "<<auxCor<<endl;
						break;
						
					case 6:
						cout<<"Seleccionaste Direccion\nEl actual es: "<<auxDir<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxDir;
						cout<<"El nuevo dato es: "<<auxDir<<endl;
						break;
						
					case 7:
						cout<<"Seleccionaste Barrio\nEl actual es: "<<auxBar<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxBar;
						cout<<"El nuevo barrio es: "<<auxDir<<endl;
						break;
					
					case 8:
						if(auxhij=="N"){
							cout<<"Ya tienes hijos? S o N"<<endl;
							cout<<"\nEl actual es: "<<auxhij<<endl;
							cout<<"Ingresa el nuevo dato: "<<endl;
							cin>>auxhij;
							
						}else{
							cout<<"Cuantos hijos mas tuviste?"<<endl;
						}
						cout<<"\nEl actual es: "<<auxnumHij<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxnumHij;
						cout<<"El nuevo Hijo es: "<<auxnumHij<<endl;
						break;
					
					default:
						break;
				}			
			}while(sel!=9);
			
			string dato;
			dato = auxNom+":"+auxApe+":"+Persona.retornarTi(intid)+":"+Persona.retornarNumId(intid)+":"+Persona.retornarGe(intid)+":"+auxFij+":"+auxCel+":"+auxCor+":"+Persona.retornarFn(intid)+
				":"+Persona.retornarEd(intid)+":"+Persona.retornarCn(intid)+":"+Persona.retornarPn(intid)+":"+Persona.retornarCr(intid)+":"+auxDir+":"+auxBar+":"+Persona.retornarAc(intid)+
				":"+auxhij+":"+auxnumHij+":"+Persona.retornarSu(intid);
				
			cout<<"Datos "<<dato<<endl;
			//convertir intid a entero
			editar(dato, intid);
			break;
		
		}		

	}

	fclose(hijosArch);
	fclose(archivo);
	fclose(sucursales);
	
}

void eliminar();

int main(int argc, char** argv) {

	
	persona<string> Persona;
	Sucursal<string> Sucursal;
	
	cout<<"Ingrese el numero de la operacion que desee realizar.\n"
		  "1. Agregar Empleado.\n"
		  "2. Agregar Sucursal\n"
		  "3. Consultar Datos.\n"
		  "4. Editar Datos."<<endl;
	
	int opcion, dato;	
	do{
		cin>>opcion;
		switch(opcion){
			case 1:
				funcionPrincipal(1);
				//agregarEmpleado();
				break;
			case 2:
				funcionPrincipal(2);
				//agregarSucursal();
				break;
			case 3:	
				funcionPrincipal(3);
				//ConsultarDatos();
				break;
			case 4:	
				funcionPrincipal(4);
				//eliminar();
				break;
			case 5:
				cout<<"Consulte Datos"<<endl;
			//	cin>>dato;
				//Persona.retornarPersona(dato);
				//buscar();
				
		}
	}while(opcion!=0);

}

void eliminar(){
	FILE *archOrig, *archAux;
	int del_line_num;
	int line_num = 0;
	char str[200];
	string contenido;
	string reemplazar;
	
	archOrig = fopen("Personas.txt","r");
	cout<<"antes de la modificacion"<<endl;
	print(archOrig);
	rewind(archOrig);
	
	cout<<"Ingrese el numero de linea que desea eliminar"<<endl;
	cin>>del_line_num;
		
	archAux = fopen("replica.txt", "w");
				
	while(fgets(str, 199, archOrig) != NULL){
		line_num++;
		
		if(line_num != del_line_num){
			fputs(str, archAux);
		}
	}
	
	cout<<"SI se realizo el proceso"<<endl;
	fclose(archOrig);
	fclose(archAux);
	remove("Personas.txt");
	rename("replica.txt","Personas.txt");
	cout<<"Cambio de nombre"<<endl;
}

void editar(string dato, int pos){
	
		char linea[200];
		strcpy(linea,Ciudad.dato.c_str());
	
		FILE *archOrig, *archAux;
		int del_line_num;
		int line_num = 0;
		char str[200];
		string contenido;
		string reemplazar;
		
		archOrig = fopen("Personas.txt","r");
		cout<<"antes de la modificacion"<<endl;
		print(archOrig);
		rewind(archOrig);
			
		archAux = fopen("replica.txt", "w");
					
		while(fgets(str, 199, archOrig) != NULL){
			line_num++;
			
			if(line_num != pos){
				fputs(str, archAux);
			}else{
				fputs(dato, archAux);
			}
		}
		
		cout<<"SI se realizo el proceso"<<endl;
		fclose(archOrig);
		fclose(archAux);
		remove("Personas.txt");
		rename("replica.txt","Personas.txt");
		cout<<"Cambio de nombre"<<endl;
}
