/*
  Nombre: Simpson
  Autor: Jesús Ernesto Jaramillo Salazar
  Fecha: 9/12/14
  Descripcion: Programa encuentra una aproximación a la integral utilizando el método de Simpson.
*/
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

double evaluar(double);
double sumatoriaPares(double[],int);
double sumatoriaImpares(double[],int);
double sumatoria(double[],int,int);
double integrarUnTercio(double[],int,double);
double integrarTresOctavos(double[],int,double);

int main(){

    int n;
    double a,b,h;

    cout<<"     Programa que mediante el m\xa82todo de simpson, encuentra una aproximaci\xa2n \n                   a la integral de la funci\xa2n f(x)=3x^2+1/x"<<endl<<endl;

    do{
        cout<<"\n\na: ";
        cin>>a;
        if(a==0) cout<<"la funci\xa2 se indefine en 0, favor de dar otro valor."<<endl;
    }while(a==0);

    do{
        cout<<"b: ";
        cin>>b;
        if(b==0 || b<=a) cout<<"la funci\xa2 se indefine en 0, favor de dar otro valor."<<endl;
    }while(b==0 || b<=a);

    do{
        cout<<"N\xa3mero de particiones: ";
        cin>>n;
        if(n<=0) cout<<"N\xa3mero de particiones no v\xa0lido"<<endl;
    }while(n<=0);

    double X[n+1];
    h=(b-a)/n;
    X[0]=a;
    X[n]=b;

    for(int i=1;i<n;++i){
        X[i]=a+i*h;
    }

    if(n%2==0){
        cout<<integrarUnTercio(X,n,h)<<endl;
    }else{
        cout<<integrarUnTercio(X,n-3,h)+integrarTresOctavos(X,n,h)<<endl;
    }

    cout<<endl;
    system("pause");
    return 0;
}

double evaluar(double x){
    return 1/pow(x,2);
}

double integrarUnTercio(double X[],int n,double h){
    double pares=0,impares=0;
    for(int i=1;i<n;++i){
        if(i%2==0) pares+=evaluar(X[i]);
        else impares+=evaluar(X[i]);
    }
    return (((h)*(evaluar(X[0])+4*impares+2*pares+X[n]))/3);
}

double integrarTresOctavos(double X[],int n,double h){
    return 3*h/8*(evaluar(X[n-3])+3*evaluar(X[n-2])+3*evaluar(X[n-1])+evaluar(X[n]));
}
