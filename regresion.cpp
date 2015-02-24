/*
  Nombre: Regresion Polinomial
  Autor: Jesús Ernesto Jaramillo Salazar
  Fecha: 4/12/14
  Descripcion: Programa que utiliza el método del Regresión polinomial para encontrar el polinomio que modela el SEL generado por los datos
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include <iomanip>
using namespace std;

class Regresion{
    public:
        int n,m;
        float *X,*Y;
        float** aux;
        float** auxGauss;

        void capturar(ifstream&);
        float sumatoria(float[],int);
        float sumatoriaEnY(float[],int);
        void generarMatriz();
        void llenarMatriz();
        void eliminacionGaussiana();
        void sustitucionPaAtras();


};

int main(){

    Regresion r;

    cout<<"           Programa que mediante el m\xa82todo de regresi\xa2n polinomial\n      llega a una ecuaci\xa2n que modela un SEL generado por los datos dados\n\n";

    char nombreArchivo[30];
    cout<<"Nombre del archivo donde est\xa0n los datos necesarios: ";
    cin.getline(nombreArchivo, 30);
    ifstream entrada(nombreArchivo);
    if(!entrada){
            cout<<"Archivo no existe."<<endl;
            system("pause");
            return 0;
    }
    entrada>>r.n;

    r.X = new (nothrow) float[r.n];
    r.Y = new (nothrow) float[r.n];

    r.capturar(entrada);
    r.generarMatriz();
    r.llenarMatriz();


    cout<<"\n\n SEL generado por los valores dados:\n\n";

    for(int i=0;i<r.m;++i){
        for(int j=0;j<r.m+1;++j){

            cout<<setw(10)<<r.aux[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
    r.eliminacionGaussiana();

    cout<<"Soluciones: ";
    for(int i=0;i<r.m;++i){
        cout<<r.aux[i][r.m]<<"    ";
    }

    cout<<"\n\n\nEcuaci\xa2n final que modela el sistema:\n\n";
    cout<<"Y = ("<<r.aux[0][r.m]<<") + ";
    for(int i=1;i<r.m;++i){
        cout<<"("<<r.aux[i][r.m]<<")x^"<<i<<" + ";
    }
    cout<<"\b\b  \n\n";


    cout<<endl;
    system("PAUSE");
    return 0;
}

void Regresion::capturar(ifstream& captura){
    cout<<"Dame el valor de m: ";
    cin>>m;
    m++;
    for(int i=0; i<n; ++i){
        captura>>X[i];
        captura>>Y[i];
    }
}

float Regresion::sumatoria(float X[],int exponente){
    float suma = 0;
    for(int i=0;i<n;++i){
        suma += pow(X[i],exponente);
    }
    return suma;
}

float Regresion::sumatoriaEnY(float X[],int exponente){
    float suma = 0;
    for(int i=0;i<n;++i){
        suma += pow(X[i],exponente)*Y[i];
    }
    return suma;
}

void Regresion::llenarMatriz(){
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            if(i==j && j==0){
                aux[i][j]=n;
            }else{
                aux[i][j] = sumatoria(X,i+j);
            }
        }
    }
    for(int i=0;i<m;++i){
        aux[i][m] = sumatoriaEnY(X,i);
    }
}

void Regresion::generarMatriz(){
    aux = new (nothrow) float *[m];
    for(int i=0;i<m;++i){
        aux[i] = new (nothrow) float[m*(m+1)];
    }
}

void Regresion::eliminacionGaussiana(){
    float t=0,pivote=0;
    int r=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<=m;++j){
            aux[i][j]*=1e10;
        }
    }
    for(int i=0;i<m;++i){
        r=i;
        for(int j=i+1;j<m;++j){
            if(abs(aux[j][i])>abs(aux[r][i])){
                r = j;
            }
        }
        if(r!=i){
            for(int k=i;k<=m;++k){
                t=aux[i][k];
                aux[i][k]=aux[r][k];
                aux[r][k]=t;
            }
        }
        for(int j=i+1;j<m;++j){
            pivote = aux[j][i]/aux[i][i];
            for(int k=m;k>=i;--k){
                aux[j][k]=aux[j][k]-aux[i][k]*pivote;
            }
        }
    }
    sustitucionPaAtras();
}

void Regresion::sustitucionPaAtras(){
    float t;
    for(int i=m-1;i>=0;--i){
        t=0.0;
        for(int j=i+1;j<m;++j){
            t+=aux[i][j]*aux[j][m];
        }
        aux[i][m]=(aux[i][m]-t)/aux[i][i];
    }
}
