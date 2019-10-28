//Test Pannel
//Der Trojaner.exe
//Feuer Ball.bat
//Prüfungs ausschnitt 1.02.2019
//Master Nici 

#include <iostream>

using namespace std;

int main(){
	
	char dasda;
	double geld;
	double flaschen;
	int a;
	int b;
	double rabbat;
	
	
	cout << "Switch\n";
	cout << "1) Flaschen\n";
	cout << "2) A oder B\n";
	cout << "3) 1 oder 2\n";
	cout << "E) Exit\n";
	
	cin >> dasda;
	
	
	switch(dasda){
		case ('1') :
			
			cout << "3.50 Fr.\n";
			cout << "10 Flaschen\n";
			cout << "5% Zins\n";
			cout << "Wie viele Flaschen haben sie: \n";
			cin >> flaschen;
			
			geld=flaschen*3.50;
			if(flaschen>=10){
				cout << "5% auf die Flaschen ";
				rabbat=geld/100*5;
				geld=geld-rabbat;
				
			}
			cout << geld;
			break;
		case ('2') :
			cout << "A oder B\n";
			cout << "Ist A oder B das Max oder Min\n"; 
			cout << "A>";
			cin >> a;
			cout << "\nB>";
			cin >> b;
			cout << "\n";
			if(a<b){
			cout << "A ist Min\n";
			cout << "B ist Max\n";
			}else if(a>b){
			cout << "B ist Min\n";
			cout << "A ist Max\n";
			}
			break;
		case ('3') :
			cout << "1 oder 2\n";
			cout << "Gebene Sie eine Zahl Zwischen 1 oder 2 ein\n";
			cin >> a;
			if(a == 1 || a == 2){
				cout << "es ist korrekt\n";
			}else{
				cout << "Nicht Korrekt\n";			
			
			}
			break;
		case ('E') : 
			cout << "E für Exit\n";
			break;	
		
	
	}
	
	return 0;
}
