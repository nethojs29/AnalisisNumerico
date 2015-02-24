/*
  Nombre: Interpolación de Lagrange
  Autor: Jesús Ernesto Jaramillo Salazar
  Fecha: 30/11/14
  Descripcion: Programa que mediante el método del polinomio interpolante de Lagrange encuentra una aproximación a x
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>

using namespace std;

void capturar(ifstream&, int&, float [], float [], float&);
float interpolar(float [], float [], int &, float &);

int main(){
    int n;
    float X[n], Y[n], B[n], x;

	cout<<"Programa que mediante el m\x82todo del polinomio interpolante de Lagrange encuentra una aproximaci\xa2n\n\n";

	char nombreArchivo[30];
	cout<<"Nombre del archivo: ";
	cin.getline(nombreArchivo, 30);
	ifstream entrada(nombreArchivo);

	if(!entrada){
		cout<<"No se encontr\xa2 archivo.."<<endl;
		system("pause");
		return 0;
	}


	entrada>>n;
	capturar(entrada, n, X, Y, x);

	cout<<"Aproximaci\xa2n: "<<interpolar(X,Y,n,x);

	cout<<endl;
	system("pause");
	return 0;
}
//********************************
void capturar(ifstream &entrada, int &n, float X[], float Y[], float &x)
{
	cout<<"X = ";
	cin>>x;
	for(int i=0;i<n;i++){
		entrada>>X[i];
		entrada>>Y[i];
    }
}
//********************************
float interpolar(float X[], float Y[], int &n, float &x)
{
    float suma = 0;
    float aux = 1;
    for(int i=0; i<n; ++i){
        aux = 1;
        for(int j=0; j<n; ++j){
            if(j!=i){
                aux *= (x-X[j])/(X[i]-X[j]);
            }
        }
        suma += Y[i] * aux;
    }
    return suma;
}
