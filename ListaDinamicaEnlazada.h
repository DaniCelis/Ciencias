#ifndef LISTADINAMICAENLAZADA_H
#define LISTADINAMICAENLAZADA_H
#include <iostream>
using namespace std;

template <class T>
class nodo{
	T info;
	nodo *sig;

	public:
		nodo(){
			T info = NULL;
			sig = NULL;
		}
		
		void insertar(nodo *&lista, T dato){
			nodo *Nodo;
			Nodo = new nodo<T>;
			Nodo -> info = dato;
			
			nodo *aux1= lista;
			nodo *aux2;
			
			while((aux1 != NULL) && (aux1->info < dato)){
					aux2 = aux1;
					aux1 = aux1->sig;
			}
			if(lista == aux1){
				lista = Nodo;
			}else{
				aux2->sig = Nodo; 
			}
			Nodo->sig = aux1;
			
		}
		
		T retornar(nodo *lista, int pos){
			int i;
			nodo *Actual;
			Actual = new nodo<T>;
			Actual = lista;
			
			while((Actual !=NULL)&& (i<pos)){
				Actual = Actual->sig;
				i++;
			}
			return Actual->info;
		}
		
//		void buscar(nodo *&lista, T dato){
//			bool retorno = false;
//			
//			nodo *Actual;
//			Actual = new nodo<T>;
//			Actual = lista;
//			
//			while((Actual != NULL) && (Actual->info <= dato )){
//				if(Actual->info == dato){
//					retorno = true;
//				}
//				Actual = Actual->sig;
//				
//			}
//		}
		
		void eliminar(nodo *&lista, T dato){
			if(lista !=NULL){
				nodo *borrar;
				nodo *ant = NULL;
				
				borrar = lista;
				
				while((borrar != NULL) && (borrar->info != dato)){
					ant = borrar;
					borrar = borrar->sig;
					
				}
				
				if(ant == NULL){
					lista = lista->sig;
					delete borrar;  
				}else{
					ant->sig = borrar->sig;
					delete borrar;
				}
			}
		}


		
};
#endif
