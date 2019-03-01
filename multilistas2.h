#ifndef MULTILISTAS2_H
#define MULTILISTAS2_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
//Plantilla para que se pueda usar con cualquier tipo de dato
template <class T>
//Estructura nodo que tiene informacion y apunta a un nodo siguiente
struct nodo{
	T info;
	nodo<T> *sig;
};
//Estructura nodo hijos que servira para guardar los datos de los hijos 
template<class T>
struct nodoHijos{
	string idPadre;  //Id del padre
	string nomb;	//Nombre del hijo
	string fechaNaci; //Fecha de nacimiento del hijo
	string edad;   // Edad del hijo
	nodoHijos<T> *sig,*ant;  //Apuntadores al siguiente hermano y al anterior
};
//Estructura nodo Sucursal que servira para guardar los datos de las sucursales 
template<class T>
struct nodoSucursal{
	string nombreSucu;    //Nombre de la sucursal
	string direccionSucu;  //Direccion de la sucursal
	string barrioSucu; // Barrio de la sucursal
	string agenteSucu;  //Gerente de la sucursal
	nodoSucursal<T> *sig;	// Apuntador a la siguiente sucursal
};

//Estructura nodo Ciudad que servira para guardar los datos de los paises y ciudadaes
template<class T>
struct nodoCiudad{
	string ciudad;    //Nombre de la ciudad
	string pais;    // Pais al que pertenece
	nodoCiudad<T> *sig;	 // Apuntador a la siguiente ciudad y pais
};

//Estructura nodo Persona que servira para guardar los datos del empleado
template <class T>
struct nodoPersona{
	string id;    //Id de la empresa para el empleado
	string nombre;  // Nombre del empleado
	string apellido; // Apellido del empleado
	string settipoid; // Tipo de identificacion ( Cedula ciudadania,Cedula extranjera o tarjeta de identidad)
	string numid;    // numero de identificacion del empleado
	string genero;  //Genero del empleado F o M
	string telf;  // Telefono fijo del empleado
	string telc;  //Telefono celular del empleado
	string mail;  // Correo electronico del empleado
	string fecnac;    //Fecha de nacimiento del empleado
	string edad;  // Edad del empleado
	string cidnac;  // Ciudad de nacimiento del empleado
	string paisnac;  // Pais de nacimiento del empleado
	string cidres;  // Ciudad de residencia del empleado
	string dire;   // Direccion del empleado
	string barrio;  // Barrio del empleado
	string actividad;  // Actividad del empleado
	string hijos;   // Respuesta S o N de si tiene hijos
	string numhijos;  // Numero de hijos que tiene el empleado
	string sucursal;   // Nombre de la sucursal
	nodoHijos<T> nhijos;  // Conexion con el la estructura nodos hijos para recuperar facilmente los hijos
	nodoSucursal<T> sucu;  // Conexion con la estructura nodo sucursal para recuperar facilmente la sucursal
	nodoPersona<T> *sig;  // Apuntador a la siguiente persona ingresada
};

// Clase hijos que usa la estructura nodo Hijos 
template<class T>
class Hijos{
	nodoHijos<T> *cab;    //apuntador que servira como el primer nodo
	public:
		Hijos(){ // Constructor de la clase Hijos
			cab=new nodoHijos<T>;   // crea un nodo Hijos y ese es donde apunta cabeza
			cab->idPadre="";  // el id del padre es null
			cab->nomb="";     // El nombre del hijo es null
			cab->fechaNaci="";   //La fecha de nacimiento del hijo es null
			cab->edad="";   // La edad del hijo es null
			cab->sig=0;   // No tiene siguiente hijo
			cab->ant=0; // No tiene anterior hijo
		}
		
	void insertarHijo(T dato, string fech, int edad);   //Metodo para insertar hijos 
	T retornarHijo(int pos);   //Metodo para retornar el nombre de un hijo en alguna posicion
};

//Clase sucursal que usa la estructura nodo Sucursal
template<class T>
class Sucursal{
	nodoSucursal<T> *cab; //apuntador que servira como el primer nodo
	public:
		Sucursal(){   // Constructor de la clase Sucursal
			cab=new nodoSucursal<T>; // Crea un nodo sucursal y cab apuntara a ese nodo
			cab->nombreSucu="";   //El nombre de la sucursal es null
			cab->direccionSucu="";  // La direccion de la sucursal es null
			cab->barrioSucu=""; // El barrio de la sucursal es null
			cab->agenteSucu="";   // El gerente de la sucursal es null
			cab->sig=NULL;  // la siguiente sucursal es null
			
		}
		
	void insertarSucursal(char nombre[20], char direccion[30], char barrio[15], char gerente[20]);  //Metodo para insertar una sucursal
	T retornarSucursal(int pos); //Metodo para retornar el nombre de una sucursal en una posicion
	void sucu(); // Retorna todas las sucursales insertadas enumeradas
};

//Clase Ciudad que usa la estructura nodo Ciudad
template<class T>
class Ciudad{
	nodoCiudad<T> *cab; //apuntador que servira como el primer nodo
	public:
		Ciudad(){ // Constructor de la clase ciudad
			cab=new nodoCiudad<T>; //Crea un nodo ciudad y cab apuntara a ese nodo
			cab->ciudad="";   // Ciudad es null
			cab->pais="";   // Pais es null
			cab->sig=NULL;	// El siguiente nodoCiudad es null
		}
		
	void insertarCiudad(char ciudad[15], char pais[15]);   //Metodo para insertar una ciudad y un pais
	T retornarCiudad(int pos);    // Metodo para retornar una ciudad en una posicion
	T retornarPais(int pos);     // Metodo para retornar un pais en una posicion
	void ciud();   //Metodo que retorna todos las ciudades y paises enumerados
};

//Clase Persona que usa la estructura nodoPersona
template<class T>
class persona{
	
	nodoPersona<T> *cabP;   
	nodoHijos<T> *cabH;    //Apuntador que servira como el primer nodoHijos
	nodoSucursal<T> *cabS;   //Apuntador que servira como el primer nodo Sucursal
	public:
		persona(){   // Constructor de la clase Persona
			cabP = new nodoPersona<T>;  // Todos los atributos de persona estaran en null
			cabP->id="";
			cabP->nombre="";
			cabP->apellido="";
			cabP->settipoid="";
			cabP->numid="";
			cabP->genero="";
			cabP->telf="";
			cabP->telc="";
			cabP->mail="";
			cabP->fecnac="";
			cabP->edad="";
			cabP->cidnac="";
			cabP->paisnac="";
			cabP->cidres="";
			cabP->dire="";
			cabP->barrio="";
			cabP->actividad="";
			cabP->hijos="";
			cabP->numhijos="";
			cabP->sucursal="";
		//	cabP->hijos=NULL;
			cabH=new nodoHijos<T>;  //Todos los atributos de hijos estaran null
			cabH->idPadre="";
			cabH->nomb="";
			cabH->fechaNaci="";
			cabH->edad="";
			cabH->sig=0;
			cabH->ant=0;
		//	cabP->sucu=NULL;
			cabS=new nodoSucursal<T>;   // Todos los atributos de sucursal estaran null
			cabS->nombreSucu="";
			cabS->direccionSucu="";
			cabS->barrioSucu="";
			cabS->agenteSucu="";
			cabS->sig=NULL;

			cabP->sig=NULL;
			
		}
	//Metodo para insertar una persona
	void insertarPersona(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
			 char ingfechaNac[10], char ingedad[2], char ingciudadNac[15], char ingpaisNac[15], char ingciudadRes[15], char ingdireccion[30], char ingbarrio[15], char ingactividad[25], char hijos[2], char ingnumhijos[2], char sucursal[15]);
	
	void insertarHijo(char idPadre[2], char nombreHijo[25], char fechanaci[10], char edad[2]); //Metodo para insertar los hijos a esa persona
	T retornarHijo(int pos);  //Metodo para retornar el nombre del hijo en una posicion
	void retornarPersona(int pos);  //Metodo para retornar todos los datos de una persona en una posicion
	T retornarNo(int pos);    //Metodo para retornar el nombre de la persona en una posicion
	T retornarAp(int pos); 		 //Metodo para retornar el apellido de la persona en una posicion
	T retornarFi(int pos); 		 //Metodo para retornar el telefono fijo de la persona en una posicion
	T retornarCe(int pos);		 //Metodo para retornar el celular de la persona en una posicion
	T retornarEm(int pos);		 //Metodo para retornar el correo de la persona en una posicion
	T retornarDi(int pos); 		 //Metodo para retornar la direccion de la persona en una posicion
	T retornarBa(int pos);		 //Metodo para retornar el barrio de la persona en una posicion
	T retornarHi(int pos);  	//Metodo para retornar el si tiene hijos o no de la persona en una posicion
	T retornarNumHij(int pos);     //Metodo para retornar el numero de hijos de la persona en una posicion
	T retornarTi(int pos); 		 //Metodo para retornar el tipo de id de la persona en una posicion
	T retornarNumId(int pos); 	 //Metodo para retornar el numero de id de la persona en una posicion
	T retornarGe(int pos);		 //Metodo para retornar el genero de la persona en una posicion
	T retornarFn(int pos);		 //Metodo para retornar la fecha de nacimiento de la persona en una posicion
	T retornarEd(int pos);		 //Metodo para retornar la edad  de la persona en una posicion
	T retornarCn(int pos);		 //Metodo para retornar la ciudad de nacimiento de la persona en una posicion
	T retornarPn(int pos);		 //Metodo para retornar el pais de nacimiento de la persona en una posicion
	T retornarCr(int pos);		 //Metodo para retornar la ciudad de residencia de la persona en una posicion
	T retornarAc(int pos);   	  //Metodo para retornar la actividad de la persona en una posicion
	T retornarSu(int pos);		 //Metodo para retornar el nombre de la sucursal de la persona en una posicion
	
	void rePe();  //Metodo que retorna el nombre de las personas y los enumera
	//void sucu();
	
	//metodos de consulta
	
	void buscarSucursal(string texto);   // Metodo para buscar las sucursales
	
	
};
//Clase lista que implementa la estructura nodo
template <class T>
class lista{
	
	nodo<T> *cab; //Apuntador que servira como el primer nodo
	
	public:
		lista(){ // Constructor de la clase Lista
			cab = new nodo<T>;  //Crea un nodo y  cab apunta a el
			cab->info ="";      //Info y siguiente seran nulos
			cab->sig=NULL;
		}
		
	void insertarLista(T dato); // Inserta en la lista un dato
	T retornarLista(int pos);   // Retorna el dato en una posicion
};
//metodos lista

//Metodo Persona

//Metodo para insertar una persona
template <class T>
void persona<T>::insertarPersona(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
			 char ingfechaNac[10], char ingedad[2], char ingciudadNac[15], char ingpaisNac[15], char ingciudadRes[15], char ingdireccion[30], char ingbarrio[15], char ingactividad[25], char hijos[2], char ingnumhijos[2], char sucursal[15]){
	
	
	string idAux(ingid);                  // Se pasa cada atributo de char a string para facilitar la insercion de los datos
	string nombreAux(ingnombre);
	string apellidoAux(ingapellido);
	string settAux(settipoid);
	string documentoAux(ingdocumento);
	string generoAux(genero);
	string fijoAux(ingfijo);
	string celularAux(ingcelular);
	string emailAux(ingemail);
	string fechaNacAux(ingfechaNac);
	string edadAux(ingedad);
	string ciudadNacAux(ingciudadNac);
	string paisNacAux(ingpaisNac);
	string ciudadResAux(ingciudadRes);
	string direccAux(ingdireccion);
	string barrioAux(ingbarrio);
	string actividadAux(ingactividad);
	string hijosAux(hijos);
	string numHijosAux(ingnumhijos);
	string sucursalAux(sucursal);	
	
	
	nodoPersona<T> *aux, *aux1=cabP;   // Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux = new nodoPersona<T>;   // Se crea un nuevo nodo
	aux->id = idAux;            // Los parametros se pasan a cada atributo correspondiente de persona
	aux->nombre = nombreAux;
	aux->apellido= apellidoAux;
	aux->settipoid = settAux;
	aux->numid= documentoAux;
	aux->genero = generoAux;
	aux->telf= fijoAux;
	aux->telc = celularAux;
	aux->mail = emailAux;
	aux->fecnac= fechaNacAux;
	aux->edad = edadAux;
	aux->cidnac = ciudadNacAux;
	aux->paisnac= paisNacAux;
	aux->cidres = ciudadResAux;
	aux->dire = direccAux;
	aux->barrio = barrioAux;
	aux->actividad = actividadAux;
	aux->hijos = hijosAux;
	aux->numhijos = numHijosAux;
	aux->sucursal = sucursalAux;
	
	aux->sig = NULL;   // La siguiente persona es null
	
	while(aux1->sig != NULL){  //Empieza en la cabeza y si hasta que encuentre que el siguiente es null
		aux1 = aux1->sig;
	}
	
	aux1->sig = aux;	//Cuando la encuentra en ese null inserta el nuevo nodo
	
//	cout<<"Persona Agregada a Lista"<<endl;
}

//Metodo para retornar las personas enumeradas
template<class T>
void persona<T>::rePe(){
	nodoPersona<T> *aux,*aux1=cabP;     // Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux=new nodoPersona<T>;
	while(aux1->sig!=NULL){   //mientras encuentre otra persona 
		aux1=aux1->sig;    //Pasara a la siguiente persona
		cout<<aux1->id<<". "<<aux1->nombre<<endl; // Imprime el id y el nombre de la persona
	}
}

//Metodo para imprimir el nombre de la persona en una posicion
template<class T>
void persona<T>::retornarPersona(int pos){
    	int i; // Auxiliar que ayudara con las iteracions del for
	nodoPersona<T> *aux,*aux1=cabP;  // Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){  // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	cout<< aux1->nombre;   // Devuelve el nombre de la persona 
}

//template<class T>
//void persona<T>::retornarPosicion(int id){
//    int i;
//	nodoPersona<T> *aux,*aux1=cabP;
//	aux=new nodoPersona<T>;
//	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
//		aux1=aux1->sig;
//	}
//	cout<< aux1->nombre;
//}

//Metodo para retornar el noombre en string
template<class T>
T persona<T>::retornarNo(int pos){
    int i;		// Auxiliar que ayudara con las iteracions del for
	nodoPersona<T> *aux,*aux1=cabP;		 // Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->nombre;  // Retorna el nombre de la persona
}

//Metodo para retornar el apellido en string
template<class T>
T persona<T>::retornarAp(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->apellido; //Retorna el apellido 
}

//Metodo para retornar telefono fijo
template<class T>
T persona<T>::retornarFi(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){  // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->telf;  //Retorna el Telefono
}

//Metodo para retornar Celular
template<class T>
T persona<T>::retornarCe(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->telc;  //Retorna el celular
}
//Metodo para retornar el correo
template<class T>
T persona<T>::retornarEm(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;  //Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){  // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->mail;   //Retorna Correo
}


//Metodo para retornar la direccion
template<class T>
T persona<T>::retornarDi(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){  // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->dire;  // Retorna la direccion
}

//Metodo para retornar el barrio
template<class T>
T persona<T>::retornarBa(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){  // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->barrio;  //Retorna el barrio
}
//Metodo para retornar Si tiene Hijos o no
template<class T>
T persona<T>::retornarHi(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; // Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->hijos;  // Retorna S o N dependiendo si tiene hijos o no
}

//Metodo para retornar el numero de hijis
template<class T>
T persona<T>::retornarNumHij(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; // Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->numhijos;  //Retorna el numero de hijos
}

//Metodo para retornar el tipo de id
template<class T>
T persona<T>::retornarTi(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; // Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->settipoid;  //Retorna el tipo de id puede ser CC CE o TI
}

//Metodo para retornar el numero de id
template<class T>
T persona<T>::retornarNumId(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->numid;  //Retorna el numero de id
}

//Metodo para retornar el genero
template<class T>
T persona<T>::retornarGe(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;  //Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->genero; //Retorna el genero puede ser M o F
}

//Metodo para retornar la fecha de nacimiento
template<class T>
T persona<T>::retornarFn(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->fecnac; //Rertorna la fecha de nacimiento
}
//Metodo para retornar edad
template<class T>
T persona<T>::retornarEd(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 el cual empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->edad; //Retorna la edad
}

//Metodo para retornar la ciudad de nacimietno
template<class T>
T persona<T>::retornarCn(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;  //Se declara un nodoPersona aux y aux1 el cual empezara en cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->cidnac;  //Retorna ciudad de nacimiento
}

//Metodo para retonar pais de nacimiento
template<class T>
T persona<T>::retornarPn(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;   //Se declara un nodoPersona aux y aux1 el cual empezara en cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->paisnac;  //Retorna el pais de nacimiento
}

//Metodo para retornar la ciudad de residencia
template<class T>
T persona<T>::retornarCr(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;  //Se declara un nodoPersona aux y aux1 el cual empezara en cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->cidres;  //Retorna la ciudad de residencia
}

//Metodo para retornar la actividad laboral
template<class T>
T persona<T>::retornarAc(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;  //Se declara un nodoPersona aux y aux1 el cual empezara en cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ // Se hara esta iteracion mientras i sea menor a la posicion que se paso por el parametro y la siguiente persona no sea null
		aux1=aux1->sig;
	}
	return aux1->actividad; //Retorna la actividad
}

//Metodo para retornar el nombre de la sucursal
template<class T>
T persona<T>::retornarSu(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP; //Se declara un nodoPersona aux y aux1 el cual empezara en cabeza
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->sucursal;  //Retorna el nombre de la sucursal
}

//metodos de lista
//Metodo para insertar en la lista (No lo acabo de comentariar porque puede que lo editemos)
template<class T>
void lista<T>::insertarLista(T dato){
	nodo<T> *aux,*aux1=cab;   
	aux= new nodo<T>;
	aux->info=dato;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}
//Metodo para retornar un dato en una posicion (Lo mismo que el anterior)
template<class T>
T  lista<T>::retornarLista(int pos){
    int i;
	nodo<T> *aux,*aux1=cab;
	aux=new nodo<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->info;
}
//metodos nodoHijos
//Metodo para insertar el hijo 
template<class T>
void persona<T>::insertarHijo(char idPadre[2], char nombre[25], char fech[10], char edad[2]){

	string idAux(idPadre);   //Pasamos los parametros de char a string
	string nomAux(nombre);
	string fechaAux(fech);
	string edadAux(edad);
	
	nodoHijos<T> *aux,*auxT,*aux1=cabH;  //Declaramo dos nodoHijos aux y aux1 que empezara en la cabeza de hijos
	aux=new nodoHijos<T>;  //Creamos un nodoHijo
	aux->idPadre = idAux;   //  Le pasamos el id del padre a ese nuevo nodo
	aux->nomb = nomAux; 	//  Le pasamos el nombre a ese nuevo nodo
	aux->fechaNaci = fechaAux; //  Le pasamos la fecha de nacimiento a ese nuevo nodo
	aux->edad = edadAux; //  Le pasamos la edad a ese nuevo nodo
	aux->sig=0;
	while(aux1->sig != 0 && aux1->edad < aux->edad){  //Este while nos servira hasta que no encuentre a un siguiente o la edad sea mayor que el que esta comparando
		aux1=aux1->sig;
	}
	auxT=aux1; //Creamos un auxiliar
	if(aux1->edad > aux->edad){ // Cambia la forma para que este organizado ascendentemente
			auxT=aux1;  
           		 aux1=aux;
			aux=auxT;
			aux1->ant=aux->ant;
			aux->ant->sig=aux1;
	}
	aux1->sig=aux;
	aux->ant=aux1;
}

template<class T>
//Metodo para retornar el hijo en una posicion
T persona<T>::retornarHijo(int pos){
    int i;
	nodoHijos<T> *aux,*aux1=cabH; //Declara dos nodoHijos aux y aux1 que empezara en la cabeza de hijos
	aux=new nodoHijos<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){  //Ciclo para encontrar la posicion que se pide
		aux1=aux1->sig;
	}
	return aux1->nomb; //Retorna el nombre del hijo
}
//Metodos sucursal
template<class T>
//Metodo para insertar una sucursal
void Sucursal<T>::insertarSucursal(char nombre[20], char direccion[30], char barrio[15], char gerente[20]){
	
	string nombreAux(nombre);		//Pasamos los parametros de char a string
	string direccionAux(direccion);
	string barrioAux(barrio);
	string gerenteAux(gerente);
	
	nodoSucursal<T> *aux,*aux1=cab;  //Declaramos dos nodoSucursal aux y aux1 que empezara en la cabeza de las sucursales
	aux= new nodoSucursal<T>;		//Creamos un nuevo nodo el cual sera aux
	aux->nombreSucu = nombreAux;  		//Le pasamos los parametros al nuevo nodo
	aux->direccionSucu = direccionAux;
	aux->barrioSucu = barrioAux;
	aux->agenteSucu = gerenteAux;
	aux->sig=NULL;
	while(aux1->sig !=NULL){  //Ciclo para encontrar la ultima sucursal
		aux1=aux1->sig;
	}
	aux1->sig=aux;	//Se agrega en la ultima posicion
}

template<class T>
//Metodo para retornar  la sucursal en una posicion
T Sucursal<T>::retornarSucursal(int pos){
	
    int i;
	nodoSucursal<T> *aux,*aux1=cab;  //Declaramos dos nodoSucursal aux y aux1 que empezara en la cabeza de las sucursales
	aux=new nodoSucursal<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){ //Ciclo para encontrar la posicion que se paso por parametro
		aux1=aux1->sig;
	}
	
	return aux1->nombreSucu;	//Retorna el nombre de la sucursal
}


template<class T>
void persona<T>::buscarSucursal(string texto){
	int i,cont=0;
	nodoPersona<T> *aux,*aux1=cabP;
	while(aux1->sig!=NULL){
		if(aux1->sucursal==texto){
			cont++;
		}
		aux1=aux1->sig;
	}
	cout<<cont<<endl;
}

template<class T>
void Sucursal<T>::sucu(){
	int cont=1;
	nodoSucursal<T> *aux,*aux1=cab;
	aux=new nodoSucursal<T>;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		cout<<cont<<". "<<aux1->nombreSucu<<endl;
		cont++;
	}
}

template<class T>
void Ciudad<T>::insertarCiudad(char ciudad[15], char pais[15]){
	
	string ciudadAux(ciudad);
	string paisAux(pais);
	
	
	nodoCiudad<T> *aux,*aux1=cab;
	aux= new nodoCiudad<T>;
	aux->ciudad= ciudadAux;
	aux->pais = paisAux;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}

template<class T>
T Ciudad<T>::retornarCiudad(int pos){
	
    int i;
	nodoCiudad<T> *aux,*aux1=cab;
	aux=new nodoCiudad<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	
	return aux1->ciudad;
}

template<class T>
T Ciudad<T>::retornarPais(int pos){
	
    int i;
	nodoCiudad<T> *aux,*aux1=cab;
	aux=new nodoCiudad<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	
	return aux1->pais;
}

template<class T>
void Ciudad<T>::ciud(){
	int cont=1;
	nodoCiudad<T> *aux,*aux1=cab;
	aux=new nodoCiudad<T>;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		cout<<cont<<". "<<aux1->ciudad<<endl;
		cont++;
	}
}
#endif
