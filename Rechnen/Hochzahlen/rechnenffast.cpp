//Name: Nicola Bühler
//Datum: 2018
//Pro: Kann Hochzahlen in Hochzahlen berechenen

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	
	int a;
	int b;
	int c;
	int e;
	double t;
//	int d;
	double h;
	double z;
	double s;
	
	cout << "Zahl1: ";
	cin >> a;
	cout << "Zahl2moder: ";
	cin >> b;
	cout << a << "\n";
	cout << b << "\n";
	e=a%b;
	cout << e << "\n";

	cout << "Hochzahl: ";
	cin >> h;
	
	s=e;
	cout << s << "\n";
	z=h;
	cout << z << "\n";
	while(z>=2){
	e=s*e;
	z--;
	}
	cout << e << "\n";
	e=e%b;
	cout << e << "\n";
}
