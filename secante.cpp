/*
    Nombre: Secante
    Autor: Jesús Ernesto Jaramillo Salazar
    Fecha: Octubre 8 2014
    Descripción: Programa que calculará una aproximación a la raíz de f(x)=arcsen(x)-e^-2x con el método de Secante
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <conio2.h>
#include <cmath>

using namespace std;

double f(double);

int main(){
    double x1=-1,x2=1,x3, fx1, fx2, fx3,error=1,tolerancia;
    int i=5,n;
    gotoxy(15,1);
    cout<<"Programa para calcular una aproximaci\xa2n de la ra\xa1z de";
    gotoxy(7,2);
    cout<<" f(x)=arcsen(x)-e^-2x con el m\x82todo de Secante en el intervalo [-1,1]"<<endl<<endl;

    cout<<"N\xa3mero de iteraciones: ";
    cin>>n;
    cout<<"Tolerancia: ";
    cin>>tolerancia;

    system("cls");


    if (abs(f(x1))<abs(f(x2))){
         double aux = x1;
         x1 = x2;
         x2 = aux;
      }

    fx1=f(x1);
    fx2=f(x2);

    gotoxy(3,i);
    cout<<"n"<<"  x(n-1)"<<"     xn"<<"          f(x n-1)"<<"        f(xn)"<<"        error";

    for(int j=0;j<n;++j){
         x3=x2-(fx2*(x1-x2))/(fx1-fx2);
         fx3=f(x3);




         gotoxy(3,i+1); cout<<j+1;
         gotoxy(6,i+1); cout<<x2;
         gotoxy(16,i+1); cout<<x1;
         gotoxy(30,i+1); cout<<fx2;
         gotoxy(44,i+1); cout<<fx1;
         gotoxy(58,i+1); cout<<abs((fx2-fx1));

         x1=x2;
         x2=x3;
         fx1=f(x1);
         fx2=f(x2);
         fx3=f(x3);
         error=abs((fx2-fx1));
         i++;

        if(error<tolerancia) break;
    }
    cout<<endl;
    system("Pause");
    return 0;
}

double f(double x){
    return (asin(x)-exp(-2*x));
}
