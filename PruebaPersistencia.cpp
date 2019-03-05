#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include "multilistas2.h"

#define MAX 208         // Tamaño para personas.txt 
#define MAX2 85 	// Tamaño para sucursales.txt
#define MAX3 39		//Tamaño para hijos.txt
#define MAX4 40 	//Tamaño para paises.txt


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
void editar(string dato, int id);

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
		    char agsucursal[15];  // Sucursal del nuevo empleado
		    
		    char NombreHijo[25];    // Nombre del hijo del nuevo empleado
		    char FechaNaciHijo[10]; 	//Fecha de nacimiento del nuevo empleado
		    int edadHijo;		//Edad del hijo del nuevo empleado
		    char agedadHijo[2];		
			
		//Declara un ofstream personas para abrir el archivo personas
			ofstream personas;	
			//Abre el archivo personas
		    personas.open("Personas.txt",ios::app);
				//Declara un ofstream personas para abrir el hijos
		    ofstream hijosArch2;	
			//Abre
		    hijosArch2.open("Hijos.txt",ios::app);
		    //Si existe el archivo llamado Personas.txt
		    if(!personas)           
		        cout<<"No existe"<<endl;
		    //Si existe el archivo llamado Hijos.txt
		    if(!hijosArch2)           
		        cout<<"No existe"<<endl;
		      
			//Valor del id para ingresar a una nueva persona atoi es para cambiar un char a entero
		    int valorID = atoi(id);
		    	//Si el valor es mayor al numero de lineas del archivo personas aumenta el valor de id
			if(valorID>i){
		    		valorID++;
			}   

			cout<<"El id es: "<<endl;
			//El valor id lo pasamos a un char que seria ingid
			itoa(valorID, ingid, 10);
			//Muestra el id del empleado a ingresar
			cout<<ingid;													
		
			cout<<endl<<"Ingrese Nombre"<<endl;
			//Pide el nombre del empleado a ingresar
			cin>>ingnombre;
							
			cout<<"Ingrese Apellido"<<endl;
			//Pide el apellido del empleado a ingresar
			cin>>ingapellido;
			//Ciclo do while para que seleccione un tipo de id correcto
			do{
			cout<<"Ingrese Tipo de ID\n"
				"1. Cedula Ciudadania\n"
				"2. Cedula Extranjeria\n"
				"3. Tarjeta Identidad"<<endl;
			cin>>ingtipoid;
			switch(ingtipoid){
					case 1:
						// EL tipo de id seria Cedula de ciudadania (CC)
						settipoid[0] = 'C';
						settipoid[1] = 'C';
						break;
					case 2:
						//El tipo de id seria Cedula extranjera (CE)
						settipoid[0] = 'C';
						settipoid[1] = 'E';
						break;
					case 3: //El tipo de id seria Tarjeta de identidad (TI)
				    		settipoid[0] = 'T';
						settipoid[1] = 'I';
				    	break;
					default:
						//Si no selecciona un numero correcto se entra aqui 
						cout<<"Dato incorrecto,intenta de nuevo"<<endl;
						break;
				}
				
			}while(ingtipoid>3 || ingtipoid<1);
			cout<<"Ingrese Numero de ID"<<endl;
			// Numero de identificacion del empleado a ingresar
			cin>>ingdocumento;
			// Ciclo do while para que se seleccione el genero del empleado a ingresar
			do{
			cout<<"Ingrese Sexo\n"
				"1. Femenino\n"
				"2. Masculino"<<endl;
			cin>>inggenero;
			
				switch(inggenero){
					case 1:
						//Si es femenino el genero se expresa como F y se agrega a la lista de Femenino
						aggenero[0] ='F';
						break;
					case 2:
						// Si es Masculino el genero se expresa como M y se agrega a la lista de masculino
						aggenero[0] ='M';
						break;
					default:
						//Si no selecciona un numero correcto se entra aqui 
						cout<<"Dato incorrecto,Ingresalo de nuevo"<<endl;
						break;
				}	
			}while(inggenero>2 || inggenero<1 );
			
			cout<<"Ingrese Numero Telefono Fijo"<<endl;
			//Numero de telefono fijo del empleado a ingresar
			cin>>ingfijo;
			
			cout<<"Ingrese Numero Telefono Celular"<<endl;
			//Numero de celular del empleado a ingresar
			cin>>ingcelular;
		
			cout<<"Ingrese Email"<<endl;
			//Correo del empleado a ingresar
			cin>>ingemail;																
			
			cout<<"Ingrese Fecha de Nacimiento Formato: DD/MM/AAAA"<<endl;
			//Fecha de nacimiento del empleado a ingresar y debe estar en formato DD/MM/AAAA
			cin>>ingfechaNac;
			
			string per1,dia3,dia4,mes3,mes4,actual,cad2;  // String auxiliares para calcular la edad del empleado
			string fechaN(ingfechaNac); // Cambiamos un char a string
			
			per1 = fechaN.substr (6);  // Toma la cadena despues de la posicion 6 que en este caso seria AAAA
			actual = fecha();    // Se toma la fecha del sistema
			cad2 = actual.substr (6); // Esta cad 2 es la fecha actual pero tomando la cadena desde la posicion 6 que seria AAAA
			dia3= fechaN.substr(0,2);  // Dia en que nacio el empleado
			dia4=actual.substr(0,2);  // Dia actual del sistema
					
			mes3=fechaN.substr(3,2);   // Mes en que nacio el empleado
			mes4=actual.substr(3,2);   // Mes actual del sistema
			
			edadPersona=atoi(cad2.c_str())- atoi(per1.c_str());  // La edad de la persona  es la resta del año del sistema con el año de nacimiento
			
			if(mes3>mes4){
				edadPersona= edadPersona-1;  // Si el mes en que nacio el empleado es mayor que el de sistemas se le resta uno a la edad porque aun no los cumplio
			}else if(mes3==mes4 && dia3>dia4){
				edadPersona= edadPersona-1;  // Si estan en el mismo mes pero el dia del empleado es mayor que el del sistema se le resta uno porque aun no cumple 
			}	
			itoa(edadPersona, ingedad, 10);   // Pasamos la edad de entero a char 
			
			cin.ignore();
			// Ciclo do while para que seleccione la ciudad de nacimiento como dato correcto
			do{
				cout<<"Ingrese Ciudad de Nacimiento"<<endl;
				Ciudad.ciud();  // Recorre todas las ciudades y paises las imprime
				cin>>intciudad;  // Ingresamos el numero en la ciudad que corresponde
				if(intciudad>m){  // Si el numero es mayor que el de las lineas del archivo de paises.txt entra como dato incorrecto y se repite el ciclo
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intciudad>m);
			
			strcpy(ingciudadNac,Ciudad.retornarCiudad(intciudad).c_str()); // a la variable ingciudadNac se le copia lo del metodo ciudad.retornarCiudad en la posicion que eligio anteriormente
			cout<<ingciudadNac<<endl;
			
			cout<<"Pais de Nacimiento"<<endl;
			strcpy(ingpaisNac,Ciudad.retornarPais(intciudad).c_str()); // a la variable IngpaisNac se le copia lo del metodo ciudad.retornarpais en la posicion que selecciono anteriormente
			cout<<ingpaisNac<<endl;
			//Ciclo do while para que seleccione la ciudad y pais de residencia			
			do{
				cout<<"Ingrese Ciudad de Residencia"<<endl;
				Ciudad.ciud(); //Metodo que retorna todas las ciudades y paises del archivo paises.txt
				cin>>intresid; 
				if(intresid>m){ // Si la opcion ingresada es mayor que las lineas del archivo paises.txt se repetira el ciclo
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intresid>m);
			strcpy(ingciudadRes,Ciudad.retornarCiudad(intresid).c_str());	// a la variable ingciudadRes se le copiara lo del metodo Ciudad.retornarCiudad en la posicion pedida anteriormente.		
			cout<<ingciudadRes<<endl;		

			cout<<"Ingrese Direccion"<<endl;
			//Se pedira la direccion de residencia actual del empleado a ingresar
			cin.getline(ingdireccion,30);
			
			cout<<"Ingrese Barrio"<<endl;
			// Se pedira el barrio de residencia actual del empleado a ingresar
			cin.getline(ingbarrio,15);
			
			// Auxiliar para seleccionar la actividad en la que se desempeñara el empleado a ingresar
			int opc;
			//Ciclo do while para que seleccione una actividad correctamente
			do{
			cout<<"Ingrese Actividad Laboral"<<endl;
			cout<<"1. Artes\n2. Ingenieria\n3. Ciencias Sociales\n4. Areas de la salud\n5. Otros "<<endl;
			
			cin>>opc;
			switch(opc){
				case 1:
					//Si se selecciono ARTE
					ingactividad[0] = 'A';
					ingactividad[1] = 'r';
					ingactividad[2] = 't';
					ingactividad[3] = 'e';
					ingactividad[4] = 's';
					break;
				case 2:
					//Si se selecciono INGENIERIA
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
					//Si se selecciono CIENCIAS SOCIALES
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
					//Si se selecciono AREAS DE LA SALUD
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
					//Si se selecciono OTROS
					ingactividad[0] = 'O';
					ingactividad[1] = 't';
					ingactividad[2] = 'r';
					ingactividad[3] = 'o';
					ingactividad[4] = 's';
					break;
				default:
					//Entra si no se selecciono un dato correcto
					cout<<"Dato incorrecto, ingresalo de nuevo"<<endl;
					break;
				}
			}while(opc>5 || opc<1);	
			//Auxiliar para saber si se puso bien S o N
			bool cond = false;
			// Ciclo para saber si se respondio bien la pregunta
			do{
		
				cout<<"Tiene hijos? S o N"<<endl;
				//Saber si el empleado a ingresar tiene hijos o no
				cin>>aghijos;
			
				if(aghijos == 'S' || aghijos == 'N'){
					cond=true;  //Si se escribio bien el programa seguira al switch para posteriormente acabar el ciclo
				}
				switch(aghijos){
					case 'S':
						// Si la respuesta fue S se pasara a preguntar el numero de hijos
						cout<<"Ingrese el numero de hijos"<<endl;
						int numero;
						cin>>numero;
						inghijos[0] = 'S';
						
						//Pasa un entero a char
						itoa(numero,ingnumhijos,10);
						
						cout<<ingnumhijos<<endl;
						// Este ciclo es para ingresar los datos de los hijos que tenga el empleado a ingresar
						for(int w=0; w<numero; w++){
							cout<<"Ingrese el nombre del hij@"<<endl;  // Ingresar el nombre del hijo
							cin>>NombreHijo;
							cout<<"Ingrese el fecha de nacimiento del hij@  FORMATO: DD/MM/AAAA"<<endl;
							cin>>FechaNaciHijo; // Ingresar la fecha de nacimiento del hijo
							
							
							string fechaNH(FechaNaciHijo);  // Cambiar char a string y guardarlo en una nueva variable
							
							string cad1 = fechaNH.substr (6);  // Año en el que nacio el hijo
							string actual = fecha();    // Fecha actual del sistema
							string cad2 = actual.substr (6);	//Año del sistema
							string dia1=fechaNH.substr(0,2);   // Dia de nacimiento del hijo
							string dia2=actual.substr(0,2);  // Dia del sistema

							string mes1=fechaNH.substr(3,2);// Mes de nacimiento del hijo
							string mes2=actual.substr(3,2); // Mes del sistema

							edadHijo=atoi(cad2.c_str())- atoi(cad1.c_str());  // La edad es la resta entre el año del sistema y el año de nacimiento del hijo
							
							if(mes1>mes2){
								edadHijo= edadHijo-1;  // SI el mes de nacimiento del hijo es mayor significa que aun no cumple años
							}else if(mes1==mes2 && dia1>dia2){
								edadHijo= edadHijo-1;  // Si el mes es el mismo pero el dia de nacimiento del hijo es mayor que el del sistema significa que aun no cumple años
							}	
							
							itoa(edadHijo, agedadHijo, 10); // Cambiamos un entero a char que seria la edad del hijo
							cout<<agedadHijo<<endl;
							
							hijosArch2<<ingid<<":"<<NombreHijo<<":"<<FechaNaciHijo<<":"<<agedadHijo<<endl;	// Se ingresa al archivo Hijos.txt					
							Persona.insertarHijo(ingid, NombreHijo, FechaNaciHijo, agedadHijo);  // Se le inserta ese hijo a la persona
							
							hijosArch2.close();  // Se cierra el archivo Hijos.txt
						}
						break;
					case 'N':
						// Si la respuesta fue N el numero de hijos sera 0
						ingnumhijos[0]='0';
						ingnumhijos[1]=' ';
						inghijos[0]='N';
						break;
					default:
						// SI no responde S o N
						cout<<"Dato incorrecto,ingresa de nuevo"<<endl;
						break;
				}
			}while(cond == false);
			
			//Ciclo do while para que seleccione la sucursal en la que trabaja
			do{
				cout<<"Ingrese el numero de la sucursal en la que trabaja"<<endl;
				Sucursal.sucu();  // Metodo que retorna todas las sucursales del archivo Sucursales.txt
				cin>>ingsucursal;
				if(ingsucursal>j){ // Si el numero ingresado es mayor que las lineas del archivo no entra 
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(ingsucursal>j);
			strcpy(agsucursal,Sucursal.retornarSucursal(ingsucursal).c_str());// Copia a la variable agsucursal lo que devuelve el metodo Sucursal.retornarSucursal que seria la sucursal elegida 
			//El empleado ya con todos sus parametros seria insertado como una persona mas   
			Persona.insertarPersona(ingid, ingnombre, ingapellido, settipoid, ingdocumento, aggenero, ingfijo, ingcelular, ingemail, ingfechaNac, ingedad, 
				ingciudadNac, ingpaisNac, ingciudadRes, ingdireccion, ingbarrio, ingactividad, inghijos, ingnumhijos, agsucursal);
			// El empleado pasaria a ser ingresado en el archivo Personas.txt	
			personas<<ingid<<":"<<ingnombre<<":"<<ingapellido<<":"<<settipoid<<":"<<ingdocumento<<":"<<aggenero<<":"<<ingfijo<<":"<<ingcelular<<":"<<ingemail<<":"<<ingfechaNac<<":"<<ingedad<<":"
				<<ingciudadNac<<":"<<ingpaisNac<<":"<<ingciudadRes<<":"<<ingdireccion<<":"<<ingbarrio<<":"<<ingactividad<<":"<<inghijos<<":"<<ingnumhijos<<":"<<agsucursal<<endl;		
			if(aggenero[0]=='F'){
				Fem.insertarLista(agsucursal,valorID);
			}else{
				Mas.insertarLista(agsucursal,valorID);
			}
			// Se cierra el archivo Personas.txt
			personas.close();
			break;
		}
		// La segunda opcion del menu seria agregar sucursual
		case 2:{
			
			//	cout<<"--------------------------------------------------------------AGREGAR SUCURSAL -------------------------------------------------------"<<endl;	
			
		//	Sucursal<string> Sucursal;
			
		    char nombreSuc[20];  // Nombre de la sucursal
		    char direccionSuc[30];  // Direccion de la sucursal
		    char barrioSuc[15];  // Barrio de la sucursal
		    char agenteSuc[20];  //gerente encargado de la sucursal
		    
		    cin.ignore();
			// Variable tipo ofstream para controlar los archivos
			ofstream sucursales2;
			// Se abre el archivo Sucursal.txt
		    sucursales2.open("Sucursales.txt",ios::app);
		    
			cout<<"Ingrese nombre de la sucursal"<<endl;
			// Ingresa el nombre de la sucursal a agregar
			cin.getline(nombreSuc,20);
			
			cout<<"Ingrese direccion de la sucursal"<<endl;
			// Ingresa la direccion de la sucursal a agregar
			cin.getline(direccionSuc,30);
			
			cout<<"Ingrese barrio de la sucursal"<<endl;
			//Ingresa el barrio de la sucursal a agregar
			cin.getline(barrioSuc,15);
			
			cout<<"Ingrese agente de la sucursal"<<endl;
			//Agrega el gerente de la sucursal
			cin.getline(agenteSuc,20);
			// Se inserta una nueva sucursal
			Sucursal.insertarSucursal(nombreSuc, direccionSuc, barrioSuc, agenteSuc); 
			// Se guarda la sucursal en el archivo sucursal.txt
			sucursales2<<nombreSuc<<":"<<direccionSuc<<":"<<barrioSuc<<":"<<agenteSuc<<endl;
			// Cierra el archivo sucursal.txt
			sucursales2.close();
		
		break;
		}
		// El caso  seria las Consultas o.O
		case 3:{
			//	cout<<"-------------------------------------------------------------- CONSULTAR DATOS -------------------------------------------------------"<<endl;
			
			Sucursal.sucu();
			Persona.retornarPersona(3);
			cout<<Persona.retornarHijo(1)<<endl;
			cout<<Persona.retornarHijo(2)<<endl;
			cout<<Persona.retornarHijo(3)<<endl;
			break;
		}	
		// El caso 4  seria editar los datos de alguna persona
		case 4:{
			//	cout<<"-------------------------------------------------------------- EDITAR DATOS -------------------------------------------------------"<<endl;
			int intid,sel;  
			int aux = atoi(id); // variable auxiliar que seria el id de la persona
		    
			if(aux>i){
		    	 aux++; // Si el id es mayor que las lineas del archivo se aumenta en 1
			}   
			// Ciclo do while para seleccionar que persona editar
			do{
				cout<<"Que persona deseas editar"<<endl;
				Persona.rePe(); //Metodo que retornar id y nombre de las personas que se encuentran en el archivo Personas.txt
				cin>>intid;
				if(intid>aux){ // Si el numero ingresado es mayor al aux seria incorrecto
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intid>aux);
			
			// Auxiliares para cambiar la informacion
			string  auxNom="",auxApe="",auxFij="",auxCel="",auxCor="",auxDir="",auxBar="",auxhij="",auxnumHij="";
			
			auxNom=Persona.retornarNo(intid); // recupera el nombre de la persona seleccionada
			auxApe=Persona.retornarAp(intid); // Recupera el apellido de la persona seleccionada
			auxFij=Persona.retornarFi(intid); // Recupera el fijo de la persona seleccionada
			auxCel=Persona.retornarCe(intid); // Recupera el celular de la persona seleccionada
			auxCor=Persona.retornarEm(intid); // Recupera el correo de la persona seleccionada
			auxDir=Persona.retornarDi(intid);  // Recupera la direccion de la persona seleccionada
			auxBar=Persona.retornarBa(intid); // Recupera el barrio de la persona seleccionada
			auxhij=Persona.retornarHi(intid); // Recupera la respuesta de N o S de si tiene hijos
			auxnumHij=Persona.retornarNumHij(intid); //Recupera el numero de hijos de la persona
			
			//Ciclo para seleccionar que datos editar
			do{
				cout<<"Seleciona el dato que deseas editar:\n1.Nombre\n2.Apellido"
				"\n3.Telefono Fijo\n4.Telefono Celular\n5.Correo"
				"\n6.Direccion\n7.Barrio\n8.actualizar info hijos\n9.Salir\n";
				cin>>sel;
				switch(sel){
					// Caso si cambio el nombre o estaba mal digitado
					case 1:
						cout<<"Seleccionaste nombre\nEl actual es: "<<auxNom<<endl; //Devuelve el nombre actual
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxNom; // Ingresa el nuevo nombre
						cout<<"El nuevo nombre es: "<<auxNom<<endl; // Imprime el nuevo nombre
						break;
						
					case 2:
						// Caso si cambio el apellido o estaba mal digitado
						cout<<"Seleccionaste apellido\nEl actual es: "<<auxApe<<endl; //Devuelve el apeliido actual
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxApe; // Ingresa nuevo apellido
						cout<<"El nuevo apellido  es: "<<auxApe<<endl; //Devuelve nuevo apellido
						break;
					case 3:
						// Cambio de numero fijo
						cout<<"Seleccionaste telefono fijo\nEl actual es: "<<auxFij<<endl; // Devuelve fijo actual
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxFij;// Ingresa nuevo fijo
						cout<<"El nuevo fijo es: "<<auxFij<<endl; //Devuelve nuevo fijo
						break;
						
					case 4:
						// Cambio de numero de celular
						cout<<"Seleccionaste telefono celular\nEl actual es: "<<auxCel<<endl; // Devuelve numero actual
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxCel;// Ingresa nuevo numero
						cout<<"El nuevo celular es: "<<auxCel<<endl // devuelve nuevo numero
						break;
						
					case 5:
						//Cambio de Correo
						cout<<"Seleccionaste Email\nEl actual es: "<<auxCor<<endl; //Correo actual
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxCor;//Ingresa nuevo correo
						cout<<"El nuevo Email es: "<<auxCor<<endl; // Devuelve nuevo correo
						break;
						
					case 6:
						//Cambio de direccion
						cout<<"Seleccionaste Direccion\nEl actual es: "<<auxDir<<endl; //Devuelve direccion actual
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxDir;//Ingresa nueva direccion
						cout<<"El nuevo dato es: "<<auxDir<<endl; //Devuelve direccion nueva
						break;
						
					case 7:
						//Cambio de barrio
						cout<<"Seleccionaste Barrio\nEl actual es: "<<auxBar<<endl;// Devuelve barrio actual
						cout<<"Ingresa el nuevo dato: "<<endl; 
						cin>>auxBar; // Ingresa nuevo barrio
						cout<<"El nuevo barrio es: "<<auxDir<<endl; // Devuelve nuevo barrio
						break;
					
					case 8:
						//Cambio en el numero de hijos;
						if(auxhij=="N"){
							cout<<"Ya tienes hijos? S o N"<<endl; // Si antes no tenia hijos pregunta si ya tiene hijos
							cout<<"\nEl actual es: "<<auxhij<<endl;  // Devuelve N o S
							cout<<"Ingresa el nuevo dato: "<<endl;
							cin>>auxhij; // Pide  la respuesta de la pregunta
							
						}else{
							cout<<"Cuantos hijos mas tuviste?"<<endl; // Si antes si tenia Hijos preguntara si tiene mas
						}
						cout<<"\nEl actual es: "<<auxnumHij<<endl; // devuelve numero actual de hijos
						cout<<"Ingresa el nuevo dato: "<<endl; // Ingresar cuantos hijos nacieron
						cin>>auxnumHij;
						cout<<"El nuevo Hijo es: "<<auxnumHij<<endl;
						break;
					
					default:
						break;
				}			
			}while(sel!=9);
			//Este string es una concatenacion  de todos los datos cambiados de la nueva persona
			char auxid[2];
			itoa(intid, auxid, 10);
			string id(auxid);
			string dato;
			dato =id+":"+auxNom+":"+auxApe+":"+Persona.retornarTi(intid)+":"+Persona.retornarNumId(intid)+":"+Persona.retornarGe(intid)+":"+auxFij+":"+auxCel+":"+auxCor+":"+Persona.retornarFn(intid)+
				":"+Persona.retornarEd(intid)+":"+Persona.retornarCn(intid)+":"+Persona.retornarPn(intid)+":"+Persona.retornarCr(intid)+":"+auxDir+":"+auxBar+":"+Persona.retornarAc(intid)+
				":"+auxhij+":"+auxnumHij+":"+Persona.retornarSu(intid);
				
			cout<<"Datos "<<dato<<endl;
			fclose(archivo);
			// llamado a la funcion editar que cambiara todos los datos que deba
			editar(dato, intid);
			break;
		
		}		

	}
	// Cierra archivo Hijos.txt
	fclose(hijosArch);
	//Cierra archivo
	fclose(archivo);
	//Ciera archivo Sucursales.txt
	fclose(sucursales);
	
}

void eliminar();

int main(int argc, char** argv) {

	// Persona de tipo de dato string
	persona<string> Persona;
	//Sucursal de tipo de dato string
	Sucursal<string> Sucursal;
	//Menu principal del programa
	cout<<"Ingrese el numero de la operacion que desee realizar.\n"
		  "1. Agregar Empleado.\n"
		  "2. Agregar Sucursal\n"
		  "3. Consultar Datos.\n"
		  "4. Editar Datos."<<endl;
	
	int opcion, dato;
	// Ciclo do while para que seleccione una opcion valida
	do{
		cin>>opcion;
		switch(opcion){
				//Llama a agregar empleado
			case 1:
				funcionPrincipal(1);
				//agregarEmpleado();
				break;
			case 2:
				// Llama a agregar sucursal
				funcionPrincipal(2);
				//agregarSucursal();
				break;
			case 3:	
				//Llama a las consultar datos
				funcionPrincipal(3);
				//ConsultarDatos();
				break;
			case 4:	
				//Llama a editar datos
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
// funcion para eliminar algun empleado

void eliminar(){
	FILE *archOrig, *archAux;  // Crea un archivo original y un auxiliar
	int del_line_num;
	int line_num = 0;
	char str[200];
	string contenido;  
	string reemplazar;
	
	//abre el archivo Personas.txt
	archOrig = fopen("Personas.txt","r");
	cout<<"antes de la modificacion"<<endl;
	print(archOrig);//Imprime el archivo antes de eliminar
	rewind(archOrig);
	
	cout<<"Ingrese el numero de linea que desea eliminar"<<endl;
	cin>>del_line_num; // Pide que empleado desea desaparecer
	
	//El archivo auxiliar abre el archivo replica.txt
	archAux = fopen("replica.txt", "w");
				
	while(fgets(str, 199, archOrig) != NULL){ // recorre el archivo original hasta que no encuentre mas daots
		line_num++; // aumenta la linea
		
		if(line_num != del_line_num){ // Mientras la linea sea diferente a la linea que desea borrar escribira los datos en el archivo replica.txt
			fputs(str, archAux);
		}
	}
	
	cout<<"SI se realizo el proceso"<<endl;
	fclose(archOrig); //Cierra el archivo original Personas.txt
	fclose(archAux); // Cierra el archivo auxiliar replica.txt
	remove("Personas.txt"); // Elimina el archivo personas
	rename("replica.txt","Personas.txt"); // al archivo replica.txt le cambia el nombre a Persona.txt
	cout<<"Cambio de nombre"<<endl;
}

//Metodo para editar los datos de una persona
void editar(string dato, int pos){
	
		char linea[200];
		strcpy(linea,dato.c_str());
	
		FILE *archOrig, *archAux;  //Crea archivo original y archivo auxiliar
		int del_line_num;
		int line_num = 0; //linea en el archivo
		char str[200];
		string contenido; 
		string reemplazar;
		
		archOrig = fopen("Personas.txt","r"); // archivo original abre el archivo Personas.txt
		cout<<"antes de la modificacion"<<endl;
		print(archOrig); //Imprime todos los datos antes de modificar
		rewind(archOrig);
			
		archAux = fopen("replica.txt", "w");  // archivo auxiliar abre el archivo replica.txt
					
		while(fgets(str, 199, archOrig) != NULL){  // Mientras tenga que datos leer
			line_num++;
			
			if(line_num != pos){  // Si la linea es diferente a la posicion que editamos lo agrega normal
				fputs(str, archAux);
			}else{
				fputs(linea, archAux); // Si la linea coincide con la posicion que editamos lo que copiaremos al archivo es la informacion que se cambio
			}
		}
		
		cout<<"SI se realizo el proceso"<<endl;
		fclose(archOrig);// Cierra el archivo original Personas.txt
		fclose(archAux);  // Cierra el archivo auxiliar replica.txt
		remove("Personas.txt");  // Elimina el archivo Personas.txt
		rename("replica.txt","Personas.txt"); // Cambia el nombre de replica por Personas.txt
		cout<<"Cambio de nombre"<<endl;
}
