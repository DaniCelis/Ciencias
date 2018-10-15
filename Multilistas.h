#ifndef MULTILISTAS_H
#define MULTILISTAS_H
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

/*class nombre{
	T nom;
	nombre<T> *sig;
	
	public:
		nombre(){
			T nom = NULL;
			sig = NULL;
		}
		
	void insertar(T nomb);
	void palabraOrden(string uno, string dos);
	T eliminar(T nomb);
};
*/
template <class T>
class carrera{
	nodo<T> *cab;
	
	public:
		carrera(){
			cab = new nodo<T>;
			cab->info = NULL;
			cab->sig=NULL;
			 
		}
		
	void insertarCarrera(T dato);
	T retornarCarrera(int pos);
	T eliminarCarrera(T dato);
};

template <class T>
class hobbie{
	nodo<T> *cab;
	
	public:
		hobbie(){
			cab = new nodo<T>;
			cab->info = NULL;
			cab->sig=NULL;
			 
		}
		
	void insertarHobbie(T dato);
	T retornarHobbie(int pos);
	T eliminarHobbie(T dato);
};

template <class T>
class edad{
	nodo<T> *cab;
	
	public:
		edad(){
			cab = new nodo<T>;
			cab->info = NULL;
			cab->sig=NULL;
			 
		}
		
	void insertarEdad(T dato);
	T retornarEdad(int pos);
//	T eliminarEdad(T dato);
};
//FUNCIONES DE CARRERA

template <class T>
void carrera<T>::insertarCarrera(T dato){
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
T carrera<T>::retornarCarrera(int pos){
    int i;
	nodo<T> *aux,*aux1=cab;
	aux=new nodo<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->info;
}

/*template<class T>
T carrera<T>::eliminarCarrera(T dato){
    nodo<T> *aux,*aux1=cab;
    aux = new nodo<T>;
    aux->info = dato;
    while(aux1->sig->info != dato || aux1->sig != NULL){
    	aux1 = aux1->sig;
	}
	aux1->sig = aux1->sig->sig;
	return aux->info;
	delete aux;
}
*/

//FUNCIONES DE HOBBIE

template <class T>
void hobbie<T>::insertarHobbie(T dato){
	nodo<T> *aux, *aux1=cab;
	aux = new nodo<T>;
	aux->info = dato;
	aux->sig = NULL;
	
	aux->sig = aux1->sig;
	aux1->sig = aux;
}

template<class T>
T hobbie<T>::retornarHobbie(int pos){
    int i;
	nodo<T> *aux,*aux1=cab;
	aux=new nodo<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->info;
}

//FUNCIONES DE EDAD

template <class T>
void edad<T>::insertarEdad(T dato){
	nodo<T> *aux, *aux1=cab;
	aux = new nodo<T>;
	aux->info = dato;
	aux->sig = NULL;
	
	while(aux1->info > aux->info && aux1->sig->info > aux->info){
		aux1 = aux1->sig; 
	}
	
	aux->sig = aux1->sig;
	aux1->sig = aux;
}

template<class T>
T edad<T>::retornarEdad(int pos){
    int i;
	nodo<T> *aux,*aux1=cab;
	aux=new nodo<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->info;
}





/*template<class T>
void nombre<T>::insertar(T nomb){
	int i;
	nombre<T> *aux,*aux1;
	aux= new nombre<T>;
	aux->nom=nomb;
	while(palabraOrden(aux1->nom, aux->nom) && aux1->sig!=NULL){
		cout<<"mas mayor";
	}
	
	aux->sig=aux1->sig;
	aux1->sig->ant=aux;
	
}
template<class T>
bool nombre<T>::palabraOrden(string palabra1, string palabra2){
	
	char *nom1 = new char[palabra1.length()+1];
	strcpy(nom1, palabra1.c_str());

	

//	if(strcmp(nom1,nom2)>0){
	//	return false;
	//}else{
	//	return true;
	//}

}
*/

#endif
