/*
Nombre del programa: Gauss Jordan
Nombre: Jesús Ernesto Jaramillo Salazar
Fecha: 26/10/2014
Descripción: Programa que con el método Gauss Jordan resuelve un sistema de ecuaciones de n orden.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <iomanip>
#define MAXN 10

using namespace std;


class Matriz{
public:
    Matriz(int);
    ~Matriz();
    void cerosArriba(int , int , int);
    void cerosAbajo(int , int , int);
    int invertir();
    void gaussJordan(float []);
    void resolver(float []);
    void ponerA(int, int, float);
private:
    float**A, **identidad;
    int n;
};


int main ()
{
    char nombreArchivo[20];
	int n;
	ifstream entrada;

	do{
		cout<<"Escribe el nombre del archivo de la matriz: ";
		cin.getline(nombreArchivo, 20);
		entrada.open(nombreArchivo);
	}while(!entrada);

	float aux;
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
			arreglo.ponerA(i, j, aux);
		}
	float X[n];
	int aux1 = arreglo.invertir();
	if(aux==1){
        cout<<"El sistema no se puede invertir, no se puede encontrar soluci\xa2n"<<endl;
    }else{
        arreglo.gaussJordan(X);
        arreglo.resolver(X);
    }

    entrada.close();

    system("pause");
    return 0;
}

Matriz::Matriz(int _n): n(_n)
{

        A = new (nothrow) float *[n];
        identidad = new (nothrow) float*[n];
        for(int i=0;i<n;++i){
            A[i] = new (nothrow) float [n*(n+1)];
            identidad[i] = new (nothrow) float [n*n];
        }


    for (int i=1; i<n; i++) A[i] = A[i-1]+(n+1);
    for(int i=0; i<n; ++i)
        for(int j=0; j<n+1; ++j) A[i][j]=0;

    for (int i=1; i<n; i++) identidad[i] = identidad[i-1]+(n);

    for(int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if(i==j){
				identidad[i][j]=1;
			}else identidad[i][j]=0;
		}
    }
}

Matriz::~Matriz()
{
    delete [] A [0];
    delete [] A;
    delete [] identidad [0];
    delete [] identidad;
}

void Matriz::cerosArriba(int i, int j, int n)
{
	float aux=0;

	for(int k=0;k<i;k++){
		aux=A[k][j]*-1;
			for(int l=0;l<n;l++){
				A[k][l]=(A[k][l])+A[i][l]*aux;
				identidad[k][l]=(identidad[k][l])+identidad[i][l]*aux;
			}
	}
}

void Matriz::cerosAbajo(int i, int j, int n)
{
	float aux=0;

	for(int k=n-1;k>i;k--){
		aux=A[k][j]*-1;
		for(int c=0;c<n;c++){
			A[k][c]=(A[k][c])+A[i][c]*aux;
			identidad[k][c]=(identidad[k][c])+identidad[i][c]*aux;
		}
	}
}

int Matriz::invertir()
{
	int i,j,k;
	int aux1=0,aux2=0;
	float aux3;
	float aux[MAXN];
	j=1;

	while (A[0][0]==0){
		for(i=0;i<n;i++){
			aux[i]=A[0][i];
			A[0][i]=A[j][i];
			A[j][i]=aux[i];
		}
		j++;
	}

	for(i=0;i<n;i++) {
		aux1=0;
		j=0;
		while(aux1==0) {
			if(A[i][j]!=0) {
				if(A[i][j]!=1) {
					aux3=pow(A[i][j],-1);
					for(k=0;k<n;k++){
						A[i][k]=(A[i][k])*aux3;
						identidad[i][k]=(identidad[i][k])*aux3;
					}
				}
				cerosArriba(i,j,n);
				cerosAbajo(i,j,n);
				aux1=1;
			}
			j++;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j){
				if(A[i][j]!=1) aux2=1;
			}
			else{
				if(A[i][j]!=0) aux2=1;
			}
        }
	if(aux2==1) return 1;
}

void Matriz::gaussJordan(float X[])
{
    float b[n];
    //Capturar b
    for(int i=0; i<n; ++i) b[i] = A[i][n+1];

    for(int i=0; i<n; ++i) X[i] = 0;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            X[i] = X[i] + identidad[i][j]*b[i];
        }
    }
}

void Matriz::resolver(float X[])
{
   float aux;
   for(int i=n-1;i>=0;i--){
      aux=0;
      for(int j=i+1;j<n;j++) aux+=identidad[i][j]*X[j];
      X[i]=(A[i][n]-aux)/A[i][i];
   }
   cout<<"\n\nLas soluciones son:"<<endl;
   for(int i=0;i<n;i++) cout<<"X"<<i+1<<" = "<<X[i]<<endl;
}

void Matriz::ponerA(int i, int j, float valor)
{
	A[i][j] = valor;
}
