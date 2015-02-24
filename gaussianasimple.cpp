/*
  Nombre: Gaussiana con pivoteo
  Autor: Jesús Ernesto Jaramillo Salazar
  Fecha: 4/12/14
  Descripcion: Programa que utiliza el método Gaussiano con pivoteo para resolver un SEL.
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include <iomanip>
#include <conio2.h>
using namespace std;

class Matriz{
    public:
        Matriz(int);
        ~Matriz();
        void setA(int,int,float);
        void eliminacionGaussiana();
        void sustitucionPaAtras();
        float**A;
        int n;
};

int main(){

    textcolor(WHITE);
    char nombreArchivo[20];
	int n;
	float aux;
	ifstream entrada;

	do{
		cout<<"Escribe el nombre del archivo de la matriz: ";
		cin.getline(nombreArchivo, 20);
		entrada.open(nombreArchivo);
	}while(!entrada);

	entrada>>n;
	if(n<=0 || n>10){
        cout<<"La dimensi\xa2n de la matriz es incorrecta n = (0,10]"<<endl;
        system("pause");
        return 0;
    }

    Matriz A(n);

    for(int i=0; i<n; ++i)
		for(int j=0; j<n+1; ++j){
			entrada>>aux;
			A.setA(i, j, aux);
		}
    cout<<endl<<"Matriz dada:"<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<=n;++j){
            cout<<setw(10)<<A.A[i][j];
        }
        cout<<endl;
    }

        A.eliminacionGaussiana();
        textcolor(WHITE);
        cout<<"Soluciones: ";
        for(int i=0;i<n;++i){
            textcolor(YELLOW);
            cout<<A.A[i][n]<<"    ";
        }
    textcolor(WHITE);
    cout<<endl;
    system("PAUSE");
    return 0;
}

Matriz::Matriz(int _n): n(_n){
    A = new (nothrow) float *[n];
    for(int i=0;i<n;++i)
        A[i] = new (nothrow) float [n*(n+1)];
}

Matriz::~Matriz()
{
    delete [] A [0];
    delete [] A;
}

void Matriz::setA(int i, int j, float valor){
	A[i][j] = valor;
}

void Matriz::eliminacionGaussiana(){
    float t=0,pivote=0;
    int r=0;

    for(int i=0;i<n;++i){
        r=i;
        for(int j=i+1;j<n;++j){
            if(abs(A[j][i])>abs(A[r][i])){
                r = j;
            }
        }

        for(int j=i+1;j<n;++j){
            pivote = A[j][i]/A[i][i];
            for(int k=n;k>=i;--k){
                A[j][k]=A[j][k]-A[i][k]*pivote;
            }
        }
    }

    cout<<endl<<endl;
        for(int i=0;i<n;++i){
        for(int j=0;j<=n;++j){
            cout<<setw(15)<<A[i][j];
        }
        cout<<endl;
        }

    sustitucionPaAtras();
}

void Matriz::sustitucionPaAtras(){
    float t;
    for(int i=n-1;i>=0;--i){
        t=0.0;
        for(int j=i+1;j<n;++j){
            t+=A[i][j]*A[j][n];
        }
        A[i][n]=(A[i][n]-t)/A[i][i];
    }
}
