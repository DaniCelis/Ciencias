#include <iostream>
#include "ListaDinamicaEnlazada.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	nodo<int> *lista = NULL;
	nodo<int> N;
	
	N.insertar(lista, 6);
	N.insertar(lista, 3);
	N.insertar(lista, 8);
	cout<<N.retornar(lista, 1);
	N.eliminar(lista, 6);
	cout<<N.retornar(lista, 1);
	
	
	
	return 0;
}
