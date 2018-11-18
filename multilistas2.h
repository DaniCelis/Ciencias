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
	string nombre;
	string dire;
	string barrio;
	string gere;
	nodoSucursal<T> *sig;	
};

template <class T>
struct nodoPersona{
	int id;
	string nombre;
	string  apellido;
	string  tipoId;
	int numid;
	char sexo;
	int telf;
	int telc;
	string mail;
	string fecnac;
	int edad;
	string cidnac;
	string paisnac;
	string cidres;
	string dire;
	string barrio;
	string acti;
	int numhijos;
	string sucursal;
	nodoHijos<T> hijos;
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
			cab->nombre="";
			cab->dire="";
			cab->barrio="";
			cab->gere="";
			cab->sig=NULL;
			
		}
		
	void insertarSucursal(string nombre, string direccion, string barrio, string gerente);
	T retornarSucursal(int pos);
	void sucu();
};

template<class T>
class persona{
	
	nodoPersona<T> *cabP;
	nodoHijos<T> *cabH;
	nodoSucursal<T> *cabS;
	public:
		persona(){
			cabP = new nodoPersona<T>;
			cabP->id=0;
			cabP->nombre="";
			cabP->apellido="";
			cabP->tipoId="";
			cabP->numid=0;
			cabP->sexo=0;
			cabP->telf=0;
			cabP->telc=0;
			cabP->mail="";
			cabP->fecnac="";
			cabP->edad=0;
			cabP->cidnac="";
			cabP->paisnac="";
			cabP->cidres="";
			cabP->dire="";
			cabP->barrio="";
			cabP->numhijos=0;
			cabP->sucursal="";
		//	cabP->hijos=NULL;
			cabH=new nodoHijos<T>;
			cabH->nomb="";
			cabH->fechaNaci="";
			cabH->edad=0;
			cabH->sig=NULL;
		//	cabP->sucu=NULL;
			cabS=new nodoSucursal<T>;
			cabS->nombre="";
			cabS->dire="";
			cabS->barrio="";
			cabS->gere="";
			cabS->sig=NULL;
		
			cabP->sig=NULL;
			
		}
		
	void insertarPersona(int id, string nombre, string apellido, string tipoId, int numid, char sexo, int telf, int telc, string mail, string fecnac, int edad,
		string cidnac, string paisnac, string cidres, string dire, string barrio, int numhijos, string sucursal);
	void insertarHijo(int idPadre, string nombreHijo, string fechanaci, int edad);
	void insertarSucursal(string nombre, string direccion, string barrio, string gerente);
	T retornarSucursal(int pos);
	T retornarHijo(int pos);
	T retornarPersona(int pos);
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
void persona<T>::insertarPersona(int id, string nombre, string apellido, string tipoId, int numid, char sexo, int telf, int telc, string mail, string fecnac, int edad,
								string cidnac, string paisnac, string cidres, string dire, string barrio, int numhijos, string sucursal){
	nodoPersona<T> *aux, *aux1=cabP;
	aux = new nodoPersona<T>;
	aux->id = id;
	aux->nombre = nombre;
	aux->apellido = apellido;
	aux->tipoId = tipoId;
	aux->numid = numid;
	aux->sexo = sexo;
	aux->telf = telf;
	aux->telc = telc;
	aux->mail = mail;
	aux->fecnac = fecnac;
	aux->edad = edad;
	aux->cidnac= cidnac;
	aux->paisnac = paisnac;
	aux->cidres = cidres;
	aux->dire = dire;
	aux->barrio = barrio;
	aux->numhijos = numhijos;
	aux->sucursal = sucursal;
	
	aux->sig = NULL;
	
	while(aux1->sig != NULL){
		aux1 = aux1->sig;
	}
	
	aux1->sig = aux;
}

template<class T>
T persona<T>::retornarPersona(int pos){
    int i;
	nodoPersona<T> *aux,*aux1=cabP;
	aux=new nodoPersona<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->nombre;
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
void persona<T>::insertarSucursal(string nombre, string direccion, string barrio, string gerente){
	nodoSucursal<T> *aux,*aux1=cabS;
	aux= new nodoSucursal<T>;
	aux->nombre=nombre;
	aux->dire= direccion;
	aux->barrio= barrio;
	aux->gere= gerente;
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
