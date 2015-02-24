/*
  Nombre: Interpolación
  Autor: Jesús Ernesto Jaramillo Salazar
  Fecha: 24/11/14
  Descripcion:
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>
using namespace std;


float interpolacion(float [], int, float&, float[]);
float encontrarB(float [], float [], int);
int main(){

	cout<<"Programa que utiliza el metodo del polinomio\ninterpolante para aproximar un valor\n\n";

	char nombreArchivo[30];
	cout<<"Escribe el nombre del archivo de la matriz: ";
	cin.getline(nombreArchivo, 30);
	ifstream entrada(nombreArchivo);
	if(!entrada){
		cout<<"Archivo no disponible."<<endl;
		system("pause");
		return 0;
	}
	int n;
	entrada>>n;
	float X[n], Y[n], B[n], x;


	cout<<"x = ";
	cin>>x;
	for(int j=0;j<n;++j){
		entrada>>X[j];
		entrada>>Y[j];
	}

	for(int i=0; i<n; ++i){
		float auxX[i+1], auxY[i+1];
		for(int j=0; j<i+1; ++j){
			auxX[j] = X[j];
			auxY[j] = Y[j];
		}
		B[i] = encontrarB(auxX, auxY, i+1);
	}
	cout<<"Aproximaci\xa2n: "<<interpolacion(B,n,x,X);

	cout<<endl;
	system("pause");
	return 0;
}

float encontrarB(float X[], float Y[], int n)
{
	if(n<2) return Y[0];
	else{
		float x1[n-1], x2[n-1], y1[n-1], y2[n-1];
		for(int i=0; i<n-1; ++i){
			x1[i] = X[i];
			x2[i] = X[i+1];
			y1[i] = Y[i];
			y2[i] = Y[i+1];

		}
		return ( (encontrarB(x2, y2, n-1) - encontrarB(x1, y1, n-1)) / (X[n-1]-X[0]) );
	}
}

float interpolacion(float B[], int n, float &x, float X[])
{
	float suma = 0, resultado = 0;
	for(int i=0; i<n; ++i){
		suma = B[i];
		for(int j=0; j<i; ++j) suma *= (x - X[j]);
		resultado += suma;
	}
	return resultado;
}
