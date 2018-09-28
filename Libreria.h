template <class T, class S>
struct nodo{T dato;
            S desc;
			nodo<T, S> sig;};
			
			
template <class T, class S>			
void AgregarNodo(nodo<T, S> *cab, T dato, S desc){
	nodo<T, S> *aux = new nodo<T, S>;
	
	aux->sig = cab;
	cab = aux;
}

template< class T >
void imprimirArreglo( const T *arreglo, const int contador )
{ for ( int i = 0; i < contador; i++ )
      cout << arreglo[ i ] << " ";
   cout << endl;
}
