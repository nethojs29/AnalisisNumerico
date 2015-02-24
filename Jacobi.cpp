/*
*	Nombre: Jacobi
*	Autor:	Jesús Ernesto Jaramillo Salazar
*	Fecha:	01/Nov/2014
*	Descripcion: Programa que resuelve un SEL utilizando el método iterativo de Jacobi.
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include <conio.h>
#include <conio2.h>
#define MAXN 10

using namespace std;
class Matriz{
public:
	Matriz(int);
	~Matriz();
	void setA(int, int, double);
	void jacobi();
	int dominancia();
	double **A;
private:
    double *aux;
	double *X;
	int n;
};

int main(){

	char nombreArchivo[20];
	int n;
	ifstream entrada;
	short int si = 0;
	int dah;

	do{
		if(si == 1) cout<<"Nombre de archivo incorrecto"<<endl;
		cout<<"Escribe el nombre del archivo de la matriz: ";
		cin.getline(nombreArchivo, 20);
		entrada.open(nombreArchivo);
		si = 1;
	}while(!entrada);

	double aux;
	entrada>>n;
	if(n<0 || n>MAXN){
        cout<<"La dimensi\xa2n de la matriz es incorrecta n = (0,10]"<<endl;
        system("pause");
        return 0;
    }
	Matriz arreglo(n);

    for(int i=0; i<n; ++i)
		for(int j=0; j<n+1; ++j){
			entrada>>aux;
			arreglo.setA(i, j, aux);
		}

    cout<<endl<<"SEL dado en el archivo: "<<endl<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<n+1;++j)
            cout<<arreglo.A[i][j]<<" ";
        cout<<endl<<endl;
    }
    if(arreglo.dominancia()==1){
        cout<<"Error. La matriz no es diagonalmente dominante"<<endl;
    }else{
        arreglo.jacobi();
    }
	cout<<endl;
	system("pause");
	return 0;

}
//***********************************
Matriz::Matriz(int _n): n(_n){
    A = new (nothrow) double *[n];
    A[0] = new (nothrow) double [n*(n+1)];
    X = new (nothrow) double[n];
    aux = new (nothrow) double[n];

    for (int i=1; i<n; i++) A[i] = A[i-1]+(n+1);

    for(int i=0; i<n; ++i)
        for(int j=0; j<n+1; ++j) A[i][j] = 0;
	for(int i=0; i<n; ++i) X[i] = 0;
	for(int i=0;i<n;++i) aux[i] = 0;
}

Matriz::~Matriz(){
    delete [] A [0];
    delete [] A;
    delete [] X;
}

void Matriz::setA(int i, int j, double valor){
	A[i][j] = valor;
}

int Matriz::dominancia(){
    double sumatoria=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j){
                sumatoria+=abs(A[i][j]);
            }
        }
        if(abs(A[i][i]) < sumatoria){
                return 1;
        }
        sumatoria=0;
    }
    return 0;
}

void Matriz::jacobi(){
	double sumatoria = 0;
	double error = 0;
	int it=1;
	double tol;

	cout<<endl<<endl<<"Tolerancia: ";
	cin>>tol;

    do{
        cout<<" iteraci\xa2n "<<it<<endl<<endl;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(j!=i){
                    sumatoria+=A[i][j]*aux[j];
                }
                X[i] = (A[i][n] - sumatoria)/A[i][i];

            }
            error = abs((X[i]-aux[i])/X[i])*100;
            cout<<"            x("<<i+1<<")"<<" = "<<X[i]<<" || "<<"error: "<<error<<"%"<<endl<<endl;
            sumatoria = 0;
        }
        for(int m=0;m<n;++m) aux[m] = X[m];
        it++;
    }while(error>tol);
}
