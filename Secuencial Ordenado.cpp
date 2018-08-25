#include <iostream>
#include<conio.h>
#include <time.h>
#include <sys/time.h>
#include <windows.h>
#include <ctime>
#include <stdio.h>

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int BusquedaSecuencialOrdenado(int a[], int n){
	
	int dato=n;
	int i;
	int j=0;
	for(i=0;i<n;i++){
		if(a[i]==dato){
			j=1;
//			cout<<"El numero esta en la pos "<<i+1;
		}
	}
	if(j==0){
//		cout<<"no se encontro el numero";
	}

	
} 





int main(int argc, char** argv) {
	
	int n=0;
	do{
		cin>>n;
		int a[n];
		
		
		int aux=n;
		srand(time(NULL));
	    LARGE_INTEGER t_inic, t_fina;
	  	double sec;
	  	srand(time(NULL));
	  	for(int i=0;i<n;i++){
			a[i]=i+1;
		}
		
		QueryPerformanceCounter(&t_inic);
		BusquedaSecuencialOrdenado(a,n);
		QueryPerformanceCounter(&t_fina);
		sec = performancecounter_diff(&t_fina, &t_inic);
		cout<<endl;
		printf("%.16g\n", sec * 1000.0);
	}
	while(n!=0);
	
	
	
}



