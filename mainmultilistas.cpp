#include <iostream>
#include <string>
#include "Multilistas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int opcionmenu=0;
	carrera<int> Sis;
	carrera<int> Ele;
	carrera<int> Ind;
	carrera<int> Cat;
	
	hobbie<int> Dan;
	hobbie<int> Nat;
	hobbie<int> Bei;
	hobbie<int> Bas;
	
	edad<int> Edad;
	
	
	int ingid=1;
	string ingcarrera="";
	string inghobbie="";
	int ingedad = 0;
	do{
		
		cout<<"Menu: \n1. Ingrese Datos \n2. Consulte Datos\n4. Eliminar Datos\n4. Terminar"<<endl;
		cin>>opcionmenu;
		if(opcionmenu>4){
			cout<<"Numero Invalido"<<endl;
		}else{
			switch(opcionmenu){
				case 1: 
					
					cout<<"Ingrese ID"<<endl;
					cin>>ingid;
					cout<<"Ingrese Carrera"<<endl;
					cin>>ingcarrera;
					
					if(!ingcarrera.compare("Sistemas")){
						Sis.insertarCarrera(ingid);
					}else if(!ingcarrera.compare("Electrica")){
						Ele.insertarCarrera(ingid);
					}else if(!ingcarrera.compare("Industrial")){
						Ind.insertarCarrera(ingid);
					}else if(!ingcarrera.compare("Catastral")){
						Cat.insertarCarrera(ingid);
					}else{
						cout<<"Dato incorrecto"<<endl;
						break;
					}
					cout<<"Ingrese Hobbie"<<endl;
					cin>>inghobbie;
					if(!inghobbie.compare("Danza")){
						Dan.insertarHobbie(ingid);
					}else if(!inghobbie.compare("Natacion")){
						Nat.insertarHobbie(ingid);
					}else if(!inghobbie.compare("Beisbol")){
						Bei.insertarHobbie(ingid);
					}else if(!inghobbie.compare("Basket")){
						Bas.insertarHobbie(ingid);
					}else{
						cout<<"Dato incorrecto"<<endl;
						break;
					}
					cout<<"Ingrese Edad"<<endl;
					cin>>ingedad;
					Edad.insertarEdad(ingid);
					break;
					
				case 2 : 
					cout<<"Consulte Datos"<<endl;
					//Aqui falta hacer la estructura de la consulta, pero ya estan bien
					cout<<Dan.retornarHobbie(1)<<endl;
					cout<<Sis.retornarCarrera(1)<<endl;
					cout<<Edad.retornarEdad(1)<<endl;
					
					break;
				case 3:
					cout<<"Eliminar Datos"<<endl;
					//No he implementado ninguno de eliminar porque no super como jeje
					//cout<<Sis.eliminarCarrera(1);
					break;
			}
		}
		
	}while(opcionmenu!=4);

}
