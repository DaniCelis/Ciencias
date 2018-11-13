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
	T nomb;
	string fechaNaci;
	int edad;
	nodoHijos<T> *sig;
};
template<class T>
struct nodoSucursal{
	T nombre;
	char dire;
	string barrio;
	string gere;	
};
template <class T>
struct nodoPersona{
	int id;
	T nombre;
	string  apellido;
	string  tipoId;
	int numid;
	char sexo;
	int telf;
	int telc;
	string mail;
	char fecnac;
	string cidnac;
	string paisnac;
	string cidres;
	char dire;
	string barrio;
	string acti;
	int numhijos;
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
class persona{
	nodoPersona<T> *cabP;
	nodoHijos<T> *cabH;
	nodoSucursal<T> *cabS;
};
template <class T>
class lista{
	
	nodo<T> *cab;
	
	public:
		lista(){
			cab = new nodo<T>;
			cab->info = NULL;
			cab->sig=NULL;
		}
		
	void insertarLista(T dato);
	T retornarLista(int pos);
};
//metodos lista
template <class T>
void lista<T>::insertarLista(T dato){
	nodo<T> *aux, *aux1=cab;
	aux = new nodo<T>;
	aux->info = dato;
	aux->sig = NULL;
	
	while(aux1->sig != NULL){
		aux1 = aux1->sig;
	}
	
	aux1->sig = aux;
}

template<class T>
T lista<T>::retornarLista(int pos){
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
void Hijos<T>::insertarHijo(T dato, string fech, int edad){
	nodoHijos<T> *aux,*aux1=cab;
	aux= new nodoHijos<T>;
	aux->nomb=dato;
	aux->fechaNaci= fech;
	aux->edad= edad;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}

template<class T>
T Hijos<T>::retornarHijo(int pos){
    int i;
	nodoHijos<T> *aux,*aux1=cab;
	aux=new nodoHijos<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->nomb;
}
#endif
