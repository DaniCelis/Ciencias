#ifndef MULTILISTAS2_H
#define MULTILISTAS2_H


template<class tipoElemento>
class Pila{
	public:
	    Pila(int max);
	    ~Pila();
	    void meter(tipoElemento v);
	    tipoElemento sacar();
	    int vacia();
	private:
   		struct nodo{
		   tipoElemento clave; struct nodo *siguiente;};
   		struct  nodo *cabeza, *z;
 };

template<class tipoElemento>
Pila<tipoElemento>::Pila(int max){
	cabeza = new nodo;  
	z=new nodo;
	cabeza->siguiente=z; 
	z->siguiente =z;
}

template<class tipoElemento>
Pila<tipoElemento>::~Pila(){
	struct nodo *t=cabeza;
	while (t!=z)
       {cabeza=t;  t->siguiente;  delete cabeza;}
}

template<class tipoElemento>
void Pila<tipoElemento>::meter(tipoElemento v){
	struct nodo *t=new nodo;
	t->clave = v;  t->siguiente=cabeza->siguiente;
	cabeza->siguiente=t;
}

template<class tipoElemento>
tipoElemento Pila<tipoElemento>::sacar(){
	tipoElemento x;
	struct nodo *t = cabeza->siguiente;
	cabeza->siguiente = t->siguiente; x=t->clave;
	delete t; return x;
}

template<class tipoElemento>
int Pila<tipoElemento>::vacia(){
	return cabeza->siguiente == z;
}






#endif
