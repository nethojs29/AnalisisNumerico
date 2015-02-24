/*
	Nombre: Newton-Raphson
	Autor:	Jesús Ernesto Jaramillo Salazar
	Fecha:	29 /9/2014
	Descripcion: Programa para calcular la raiz de una funcion mediante el metodo de Newton-Raphson.
*/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <windows.h>

using namespace std;
/////////////////////////////
double f(double);

int main()
{
 	double xi,xAnt,df,xRaiz,vActual,h=0.0001,tolerancia;
 	int n;
 	cout<<"           Programa que con el m\x82todo de secante resuelve la ecuaci\xa2n:"<<endl;
 	cout<<"                               f(x)=e^(x-1)-5x^3"<<endl<<endl;
 	cout<<"Numero maximo de iteraciones: ";
 	cin>>n;
 	cout<<"Tolerancia: ";
 	cin>>tolerancia;
 	cout<<"Valor inicial: ";
 	cin>>xi;

 	if (f(xi)==0){
      cout<<"Has dado el valor de la ra\xa1z como valor inicial"<<endl;
      system("pause");
      return 0;
    }
 	for(int i=0; i<n;++i){
		  df=(f(xi+h)-f(xi))/h;
		  if (df!=0){
	 		xRaiz=xi-(f(xi)/df);
          }

        if(f(xRaiz)!=0){
            xAnt=xi;
            xi=xRaiz;
            vActual=abs((xRaiz-xAnt)/xRaiz);
        }
        cout<<i+1<<"    "<<xi<<"       "<<f(xi)<<"      "<<df<<"      "<<xRaiz<<"     "<<vActual<<endl;
        if(vActual < tolerancia) break;
    }

    cout<<endl<<endl<<"La aproximaci\xa2n a la ra\xa1z es: "<<xi<<endl<<endl;

    system ("pause");
}

double f(double x){
    return (exp(x-1)-5*pow(x,3));
}
