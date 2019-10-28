//

#include <iostream>
#include <cstdlib>

using namespace std;

void ling();
void ausgab(double *sum, double *volumen);
void eingab(double *a, double *b, double *c, double *sum, double *volumen);


int main(){
	
	double a;
	double b;
	double c;
	double sum;
	double volumen;
	
	
	eingab(&a, &b, &c, &sum, &volumen);
	ausgab(&sum, &volumen);
	
}

void ling(){
	cout << "---------------------------\n";
}

void ausgab(double *sum, double *volumen){
	cout << *sum << "cm\n";
	cout << *volumen << "liter\n";
}

void eingab(double *a, double *b, double *c, double *sum, double *volumen){
	
	ling();
	cout << "Geben Sie Seite A in cm ein : ";
	cin >> *a;
	ling();
	cout << "Geben Sie Seite B in cm ein : ";
	cin >> *b;
	ling();
	cout << "Geben Sie Seite C in cm ein : ";
	cin >> *c;
	
	*sum=*a * *b * *c;
	*volumen=*sum;
	*volumen=*volumen/1000;
}


