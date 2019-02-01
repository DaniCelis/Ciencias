#include <iostream>
#include <conio.h>
#include "LibreriaPila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	
//	char c; 
//	Pila<char> guardar(50);
//	while(cin.get(c)){
//	 while(c>='0' && c<='9'){
//	 	cout.put(c); cin.get(c);
//	}
//	
//	  if (c==')') cout.put(guardar.sacar());
//	  if (c=='+') guardar.meter(c);
//	  if (c=='*') guardar.meter(c);
//	  if (c!='(') cout << ' ';
//	  
//	}
//	
//	cout<<'\n';
	
	char d; 
	Pila<char> acc(50);
	int x;
		
	while(cin.get(d) && d!='\n'){
		
		
		x=0;
		while (d==' ') cin.get(d); 
		while(d>= '0' && d<='9'){
			x=10*x + (d-'0'); cin.get(d);
		}
		if (d == '+') x= acc.sacar() + acc.sacar();
		if (d== '*') x= acc.sacar() * acc.sacar();
		acc.meter(x);
		cout<<x<<endl;
		
		if(acc.vacia()==1){
			break;
		}
		
	}
	cout<<"sale";
	cout << acc.sacar()<< '\n';

	return 0;
}
