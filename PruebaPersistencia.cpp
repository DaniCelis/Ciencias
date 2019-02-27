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


// Funcion para recuperar la fecha del sistema 
string fecha(){
	time_t t;
  	struct tm *tm;
  	char fechayhora[100];

	t=time(NULL);
	tm=localtime(&t);
	strftime(fechayhora, 100, "%d/%m/%Y", tm);
	return fechayhora;
}

// Funcion para imprimir los datos de un archivo 

void print(FILE *fp){
	char ch;
	
	while((ch = fgetc(fp)) != EOF ){
		cout<<ch;
	}
}
//void editar(string datos);

// Funcion con la cual se hara los operaciones,practicamente es el menu donde seleccionar las opciones
void funcionPrincipal(int opcionPrincipal){
	
//	cout<<"--------------------------------------------------------------Cargar Personas-------------------------------------------------------"<<endl;
	
	char line[MAX];    // Tamaño del archivos persona.txt?
	char id[3];     // Id de la persona
    char nombre[10];    // Nombre de la persona
  	char apellido[20];  // Apellido de la persona
    char tipoid[2];    // Tipo de id( Tarjeta de identidad, Cedula de ciudadania o Cedula extranjera
    char cedula[10];   // Numero de identificacion de la persona
    char genero[2];    // Genero de la persona (M o F)
    char fijo[10];    //  Numero de fijo de la persona
    char celular[10];  //Numero de celular de la persona
    char email[30];   // Email de la persona
    char fechaNac[10];  // Fecha de nacimiento de la persona
    char edad[2];     // Edad de la persona
    char ciudadNac[15];  // Ciudad de nacimiento de la persona
    char paisNac[15];   // Pais de nacimiento de la persona
    char ciudadRes[15];  // Ciudad de residencia de la persona
    char direccion[30];   // Direccion de la persona
    char barrio[15];   // Bario de la persona
    char actividad[15];  // Actividad laboral de la persona
    char hijos[2];    // Tiene o no hijos? (S o N)
    char numhijos[2]; // Si tiene hijos cuantos hijos tiene 
    char sucursal[15];  // Nombre de la sucrusal
    
    //Persona de tipo de dato string
    persona<string> Persona;
    
    //Abre el archivo denominado Personas.txt
    FILE *archivo=fopen("Personas.txt","rt");
    
    if(!archivo)            // Comprueba que el archivo existe o no
        cout<<"No existe"<<endl;   
    else
    	cout<<"Existe"<<endl;
    //Contador que ayuda para saber cuantas lineas hay en el archivo
    int i=0;
    // Lee el archivo
    fgets(line,MAX,archivo);
    cout<<"| Id | Nombre | Apellido | Tipo ID | Cedula | Genero | Fijo | Celular | Email | Fecha Nacimiento |"<<endl;
    cout<<"| Edad | Ciud Naci | Pais Naci | Ciud Resid | Direccion | Barrio | Actividad | Hijos | Num Hijos | Sucursal |"<<endl;
	// Mientras exista otro linea se repetira el ciclo
    while(!feof(archivo)) {
        i++; // Aumento de i
	 // Lee los datos de los archivos y toma una cadena por cada : que encuentra
        sscanf(line,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^\n]", id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, actividad, hijos, numhijos, sucursal); //%[^:]:
    	fflush(stdin);
    	
    	cout<<"| "<<id<<" | "<<nombre<<" | "<<apellido<<" | "<<tipoid<<" | "<<cedula<<" | "<<genero<<" | "<<fijo<<" | "<<celular<<" | "<<email<<" | "<<fechaNac<<" | "<<endl;
   	    cout<<"| "<<edad<<" | "<<ciudadNac<<" | "<<paisNac<<" | "<<ciudadRes<<" | "<<direccion<<" | "<<barrio<<" | "<<actividad<<" | "<<hijos<<" | "<<numhijos<<" | "<<sucursal<<endl;
		// Inserta los datos de los archivos a la clase persona
		Persona.insertarPersona(id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, actividad, hijos, numhijos, sucursal);
		//Toma la siguiente linea
		fgets(line,MAX,archivo);
    }
	//Muestra cuantas lineas posee el archivo
    cout<<"Line: "<<i<<endl;
    
    //	cout<<"--------------------------------------------------------------Cargar Sucursales-------------------------------------------------------"<<endl;
    	
	char line2[MAX2];  //Tamaño del archivo Sucursales.txt?
	char nombreSuc[20];  //Nombre de la sucursal
    char direccionSuc[30];  // Direccion de la sucursal
    char barrioSuc[15];    //Barrio donde se encuentra la sucursal
    char agenteSuc[20];    // Nombre del gerente encargado de la sucursal
	
	// Sucursal de tipo de dato string
	Sucursal<string> Sucursal;
	
	//Abre el archivo sucursales.txt
	FILE *sucursales=fopen("Sucursales.txt","rt");
    //Comprueba si existe sucursales
    if(!sucursales)      
        cout<<"No existe"<<endl;   
    //Auxiliar para ayudarnos a saber cuantos datos se encuentran en el archivo
    int j=0;
	// Toma la primera linea
    fgets(line2,MAX2,sucursales);
    	// Ayuda con la impresion de los datos
    	cout<<"| Nombre Sucursal | Direccion Sucursal | Barrio Sucursal | Agente Sucursal | "<<endl;
    //While que se ejutara mientras exista otro salto de linea
    while(!feof(sucursales)) {
        j++; // Incremento de j
	   //Escanea la linea y toma cada dato y los separa por :
        sscanf(line2,"%[^:]:%[^:]:%[^:]:%[^\n]", nombreSuc, direccionSuc, barrioSuc, agenteSuc); //%[^:]:
    	fflush(stdin);
		
    	cout<<" | "<<nombreSuc<<" | "<<direccionSuc<<" | "<<barrioSuc<<" | "<<agenteSuc<<" | "<<endl;
    	        // Inserta los datos de la sucursal
		Sucursal.insertarSucursal(nombreSuc, direccionSuc, barrioSuc, agenteSuc);
    		// lee la siguiente linea
		fgets(line2,MAX2,sucursales); 
	}
	// Cout para saber cuantas lineas posee
	cout<<"Line: "<<j<<endl;
	
	//	cout<<"--------------------------------------------------------------Cargar Hijos-------------------------------------------------------"<<endl;
    
	char line3[MAX3];     //Tamaño maximo del archivo Hijos.txt
	char idPadre[2];   // id del padre 
	char nombreHijo[25]; // Nombre del hijo
    char fechaNacHijo[10];   // Fecha de nacimiento del hijo
    char edadHijo[2];     // Edad del hijo
    
	//Abre el archivo Hijos.txt
	FILE *hijosArch=fopen("Hijos.txt","rt");
    //Comprueba si el archivo existe
    if(!hijosArch)      
        cout<<"No existe"<<endl;   
     //Auxiliar que nos ayuda a saber cuantas lineas tiene
    int k=0;
	//obtiene los datos de la primera linea
    fgets(line3,MAX3,hijosArch);
    	// nos ayuda a diferenciar los datos del archvio
    	cout<<"| idPadre | Nombre Hijo | Fecha Naci Hijo | Edad Hijo | "<<endl;
    // Mientras tenga otra linea con datos
    while(!feof(hijosArch)) {
        k++; // aumenta k
	    //Lee la linea en la que esta y separa los datos por :
        sscanf(line3,"%[^:]:%[^:]:%[^:]:%[^\n]", idPadre, nombreHijo, fechaNacHijo, edadHijo); //%[^:]:
    	fflush(stdin);
    	cout<<" | "<<idPadre<<" | "<<nombreHijo<<" | "<<fechaNacHijo<<" | "<<edadHijo<<" | "<<endl;
    	
	    // Inserta los hijos en la persona que corresponda
    	Persona.insertarHijo(idPadre, nombreHijo, fechaNacHijo, edadHijo);
    		//Lee la siguiente linea
		fgets(line3,MAX3,hijosArch); 
	}
	//saber cuantas lineas tiene el archivo
	cout<<"Line: "<<k<<endl;
	
	//	cout<<"--------------------------------------------------------------Cargar Paises y Ciudades-------------------------------------------------------"<<endl;
    
	char line4[MAX4];   //Maximo para el archivo de Paises.txt
	char ciudad[15];   // Ciudad 
	char pais[15];	   // Pais 
	
	//Crea una Ciudad de tipo de datos string
	Ciudad<string> Ciudad;
	
	//Lee el archivo paises.txt
	FILE *paises=fopen("Paises.txt","rt");
    //Comprueba si el archivo existe
    if(!paises)      
        cout<<"No existe"<<endl;   
     // auxiliar para saber cuantas lineas estan en el archivo
    int m=0;
	//lee la primera linea del archivo
    fgets(line4,MAX4,paises);
    	// ayuda para saber cuales son los datos
    	cout<<"| Ciudad | Pais |"<<endl;
    //Mientras tenga lineas para leer
    while(!feof(paises)) {
        m++; //aumenta m
	 //escanea la linea y separa los datos por : 
        sscanf(line4,"%[^:]:%[^\n]", ciudad, pais); //%[^:]:
    	fflush(stdin);
    	
    	cout<<" | "<<ciudad<<" | "<<pais<<" | "<<endl;
    	//Inserta las ciudades y el pais en el cual estan ubicadas
    	Ciudad.insertarCiudad(ciudad, pais);
		    //lee la siguiente linea	
		fgets(line4,MAX4,paises); 
	}
	//cout para saber cuantas lineas posee el archivo
	cout<<"Line: "<<m<<endl;
	
	//	cout<<"--------------------------------------------------------------Realizar Operaciones -------------------------------------------------------"<<endl;
	// Menu principal en donde se realizaran todas las operaciones basicas 
	switch(opcionPrincipal){
			// El primer caso es agregar un nuevo empleado
		case 1:{
			
		//	cout<<"--------------------------------------------------------------AGREGAR EMPLEADO -------------------------------------------------------"<<endl;	
			lista<string> Fem;   // Lista con todos los que tienen genero femenino
			lista<string> Mas;   // Lista con todos los que tienen genero masculino
			
			char ingid[3];    // Id del nuevo empleado
		    char ingnombre[10];   // Nombre del nuevo empleado
		    char ingapellido[20];  // Apellido del nuevo empleado
		    int ingtipoid;      // Opcion para elegir el tipo de id
		    char settipoid[2];   // Tipo de id del nuevo empleado
		    char ingdocumento[15];  // Numero de identificacion del nuevo empleado
		    int inggenero;   // Opcion para elegir el genero de la nueva persona
		    char aggenero[2]; // Genero de la Persona
		    char ingfijo[10];  // Numero fijo del nuevo empleado
		    char ingcelular[10]; // Numero del celular del nuevo empleado
		    char ingemail[30];  // Correo electronico del nuevo empleado
		    char ingfechaNac[10];  // Fecha de nacimiento del nuevo empleado
		    char ingedad[2]; // Edad del nuevo empleado
		    int intciudad;  // Opcion para la ciudad del nuevo empleado
		    char ingciudadNac[15];  // Ciudad de nacimiento del nuevo empleado
		    char ingpaisNac[15];  // Pais de nacimiento del nuevo empleado
		    int intresid;       // Opcion para saber la residencia del nuevo empleado
		    char ingciudadRes[15];  // Ciudad de residencia del nuevo empleado
		    char ingdireccion[30];  // Direccion del nuevo empleado
		    char ingbarrio[15];  // Barrio del nuevo empleado
		    char ingactividad[25]; // Actividad a la que se dedicara el nuevo empleado 
		    char aghijos; 
		    char inghijos[2];    // Tiene o no hijos S o N
		    char ingnumhijos[2];  // Numero de hijos del nuevo empleado
		    int ingsucursal;    // Opcion de sucursal del nuevo empleado
		    int edadPersona;   // Edad del nuevo empleado
		    char agsucursal[15];  // 
		    
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
