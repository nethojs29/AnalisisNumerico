/*
  Nombre: Trapecios
  Autor: Jesús Ernesto Jaramillo Salazar
  Fecha: 4/12/14
  Descripcion: Programa encuentra una aproximación a la integral utilizando el método de los trapecios.
*/
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double evaluar(double);
double sumatoria(double[],int);
double integrar(double[],int);

int main(){

    cout<<"         Programa para calcular una aproximaci\xa2n a la integral definida \n             de la funci\xa2n: x^7+8x^3+x^-2 en el intervalo [1,2]";

    int n;
    double a,b,h;
    do{
        cout<<"\n\na: ";
        cin>>a;
        if(a==0) cout<<"la funci\xa2 se indefine en 0, favor de dar otro valor.";
    }while(a==0);

    do{
        cout<<"b: ";
        cin>>b;
        if(b==0) cout<<"la funci\xa2 se indefine en 0, favor de dar otro valor.";
    }while(b==0);

    cout<<"\nN\xa3mero de particiones: ";
    cin>>n;

    double X[n+1];
    h=(b-a)/n;
    X[0]=a;
    X[n]=b;

    for(int i=1;i<n;++i){
        X[i]=a+i*h;
    }
    cout<<"Aproximadamente el resultado es: "<<integrar(X,n);

    cout<<endl;
    system("pause");
    return 0;
}

double evaluar(double x){
    return pow(x,7)+8*pow(x,3)+(1/pow(x,2));
}

double sumatoria(double X[],int n){
    double suma = 0;
    for(int i=1;i<n;++i){
        suma+=evaluar(X[i]);
    }
    return 2*suma;
}

double integrar(double X[],int n){
    return (X[n]-X[0])*(evaluar(X[0])+sumatoria(X,n)+evaluar(X[n]))/(2*n);
}
