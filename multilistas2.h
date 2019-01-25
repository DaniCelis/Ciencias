#ifndef MULTILISTAS2_H
#define MULTILISTAS2_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

template <class T>
struct nodo{
	T info;
	nodo<T> *sig;
};
template<class T>
struct nodoHijos{
	int idPadre;
	string nomb;
	string fechaNaci;
	int edad;
	nodoHijos<T> *sig;
};

template<class T>
struct nodoSucursal{
	char nombre[20];
	char dire[30];
	char barrio[15];
	char gere[20];
	nodoSucursal<T> *sig;	
};


template <class T>
struct nodoPersona{
	char id[3];
	char nombre[10];
	char apellido[20];
	char settipoid[2];
	char numid[15];
	char genero[2];
	char telf[10];
	char telc[10];
	char mail[30];
	char fecnac[10];
	char edad[2];
	char cidnac[15];
	char paisnac[15];
	char cidres[15];
	char dire[30];
	char barrio[15];
	char hijos[2];
	char numhijos[2];
	char sucursal[15];
	nodoHijos<T> nhijos;
	nodoSucursal<T> sucu;
	nodoPersona<T> *sig;
};

template<class T>
class Hijos{
	nodoHijos<T> *cab;
	public:
		Hijos(){
			cab=new nodoHijos<T>;
			cab->nomb="";
			cab->fechaNaci="";
			cab->edad=0;
			cab->sig=NULL;
		}
		
	void insertarHijo(T dato, string fech, int edad);
	T retornarHijo(int pos);
};

template<class T>
class Sucursal{
	nodoSucursal<T> *cab;
	public:
		Sucursal(){
			cab=new nodoSucursal<T>;
			cab->nombre;
			cab->dire;
			cab->barrio;
			cab->gere;
			cab->sig=NULL;
			
		}
		
//	void insertarSucursal(char nombre[20], char direccion[30], char barrio[15], char gerente[20]);
//	T retornarSucursal(int pos);
//	void sucu();
};

template<class T>
class persona{
	
	nodoPersona<T> *cabP;
	nodoHijos<T> *cabH;
	nodoSucursal<T> *cabS;
	public:
		persona(){
			cabP = new nodoPersona<T>;
			cabP->id;
			cabP->nombre;
			cabP->apellido;
			cabP->settipoid;
			cabP->numid;
			cabP->genero;
			cabP->telf;
			cabP->telc;
			cabP->mail;
			cabP->fecnac;
			cabP->edad;
			cabP->cidnac;
			cabP->paisnac;
			cabP->cidres;
			cabP->dire;
			cabP->barrio;
			cabP->hijos;
			cabP->numhijos;
			cabP->sucursal;
		//	cabP->hijos=NULL;
			cabH=new nodoHijos<T>;
			cabH->nomb="";
			cabH->fechaNaci="";
			cabH->edad=0;
			cabH->sig=NULL;
		//	cabP->sucu=NULL;
//			cabS=new nodoSucursal<T>;
//			cabS->nombre="";
//			cabS->dire="";
//			cabS->barrio="";
//			cabS->gere="";
//			cabS->sig=NULL;
		
			cabP->sig=NULL;
			
		}
		
	void insertarPersona(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
			 char ingfechaNac[10], char ingedad[2], char ingciudadNac[15], char ingpaisNac[15], char ingciudadRes[15], char ingdireccion[30], char ingbarrio[15], char hijos[2], char ingnumhijos[2], char sucursal[15]);
	void insertarHijo(int idPadre, string nombreHijo, string fechanaci, int edad);
	void insertarSucursal(char nombre[20], char direccion[30], char barrio[15], char gerente[20]);
	T retornarSucursal(int pos);
	T retornarHijo(int pos);
	void retornarPersona(int pos);
	void sucu();
	
	//metodos de consulta
	
	void buscarSucursal(string texto);
	
	
};
template <class T>
class lista{
	
	nodo<T> *cab;
	
	public:
		lista(){
			cab = new nodo<T>;
			cab->info ="";
			cab->sig=NULL;
		}
		
	void insertarLista(T dato);
	T retornarLista(int pos);
};
//metodos lista
template <class T>
void persona<T>::insertarPersona(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
			 char ingfechaNac[10], char ingedad[2], char ingciudadNac[15], char ingpaisNac[15], char ingciudadRes[15], char ingdireccion[30], char ingbarrio[15], char hijos[2], char ingnumhijos[2], char sucursal[15]){
	nodoPersona<T> *aux, *aux1=cabP;
	aux = new nodoPersona<T>;
	aux->id[3] = ingid[3];
	aux->nombre[10] = ingnombre[10];
	aux->apellido[20]= ingapellido[20];
	aux->settipoid[2] = settipoid[2];
	aux->numid[15]= ingdocumento[15];
	aux->genero[2] = genero[2];
	aux->telf[10] = ingfijo[10];
	aux->telc[10] = ingcelular[10];
	aux->mail[30] = ingemail[30];
	aux->fecnac[10] = ingfechaNac[10];
	aux->edad[2] = ingedad[2];
	aux->cidnac[15] = ingciudadNac[15];
	aux->paisnac[15] = ingpaisNac[15];
	aux->cidres[15] = ingciudadRes[15];
	aux->dire[30] = ingdireccion[30];
	aux->barrio[15] = ingbarrio[15];
	aux->hijos[2] = hijos[2];
	aux->numhijos[2] = ingnumhijos[2];
	aux->sucursal[15] = sucursal[15];
	
	aux->sig = NULL;
	
	while(aux1->sig != NULL){
		aux1 = aux1->sig;
	}
	
	
	aux1->sig = aux;
	cout<<aux->nombre<<endl;	
	
	cout<<"Persona Agregada a Lista"<<endl;
}


template<class T>
void persona<T>::retornarPersona(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	cout<< aux1->nombre;
}

//metodos de lista
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
template<class T>
void persona<T>::insertarHijo(int idPadre, string nombre, string fech, int edad){
	nodoHijos<T> *aux,*aux1=cabH;
	aux= new nodoHijos<T>;
	aux->idPadre= idPadre;
	aux->nomb=nombre;
	aux->fechaNaci= fech;
	aux->edad= edad;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}

template<class T>
T persona<T>::retornarHijo(int pos){
    int i;
	nodoHijos<T> *aux,*aux1=cabH;
	aux=new nodoHijos<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->nomb;
}
//Metodos sucursal
template<class T>
void persona<T>::insertarSucursal(char nombre[20], char direccion[30], char barrio[15], char gerente[20]){
	nodoSucursal<T> *aux,*aux1=cabS;
	aux= new nodoSucursal<T>;
	aux->nombre[20]=nombre[20];
	aux->dire[30]= direccion[30];
	aux->barrio[15]= barrio[15];
	aux->gere[20]= gerente[20];
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}

template<class T>
T persona<T>::retornarSucursal(int pos){
    int i;
	nodoSucursal<T> *aux,*aux1=cabS;
	aux=new nodoSucursal<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->nombre;
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
void persona<T>::sucu(){
	int cont=1;
	nodoSucursal<T> *aux,*aux1=cabS;
	aux=new nodoSucursal<T>;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		cout<<cont<<". "<<aux1->nombre<<endl;
		cont++;
		
	}
}
#endif
