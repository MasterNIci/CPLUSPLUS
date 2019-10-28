//------------------------------
//Version:  1.0
//ProName: Alles Rechnen
//Nicola Bühler
//------------------------------

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int main(){
	
	system("color 02");
	//variabeln
	int zahl1=1;
	int zahl2=2;
	int zahl3=3;
	int zahl4=4;
	int zahl5=5;
	int zahl6=6;
	int zahl7=7;
	int zahl8=8;
	int zahl9=9;
	int zahl10=10;
	int zahl11=11;
	int zahl12=12;
	int zahl13=13;
	int zahl14=14;
	int ergebnis1;
	int ergebnis2;
	int erg3;
	int erg4;
	int erg5;
	int erg6;
	int erg7;
	int erg8;
	int erg9;
	int erg10;
	int erg11;
	int erg12;
	int roller=0;
	int dasda;
	
	cout << "|*************************************************************************************************|\n";
	cout << "|\t\t\t\t\t   Willkommen   \t\t\t\t\t  |\n";
	cout << "|\t\t\t\t\t\t\t\t\t\t\t\t  |\n";
	cout << "|*************************************************************************************************|\n";
	cout << "| 1) Zahlen                                                                                       |\n";
	cout << "| 2) Rechnen                                                                                      |\n";
	cout << "|*************************************************************************************************|\n";
	cin >> dasda;

	switch(dasda){
	case 1 :
		system("CLS");
		cout << "|*************************************************************************************************|\n";
		cout << "|\t\t\t\t\t   Willkommen   \t\t\t\t\t  |\n";
		cout << "|\t\t\t\t\t\t\t\t\t\t\t\t  |\n";
		cout << "|*************************************************************************************************|\n";
		cout << "|                                                                                                 |\n";
		cout << "|                                                                                                 |\n";
		cout << "|*************************************************************************************************|\n";
		while(roller<100){
		ergebnis1=zahl1*zahl2;
		ergebnis2=zahl1*zahl3;
		erg3=zahl1*zahl4;
		erg4=zahl1*zahl5;
		erg5=zahl1*zahl6;
		erg6=zahl1*zahl7;
		erg7=zahl1*zahl8;
		erg8=zahl1*zahl9;
		erg9=zahl1*zahl10;
		erg10=zahl1*zahl11;
		erg11=zahl1*zahl12;
		
		cout << zahl1 << "> \t| " << ergebnis1 << "\t" << ergebnis2 << "\t" << erg3 << "\t" << erg4 << "\t" << erg5 << "\t" << erg6 << "\t" << erg7 << "\t" << erg8 << "\t" << erg9 << "\t" << erg10 << "\t" << erg11 << "\t  |\n";
		zahl1++;
		roller++;
		Sleep(400);
		}
		break;
	case 2 :
		system("CLS");
		cout << "|*************************************************************************************************|\n";
		cout << "|\t\t\t\t\t   Willkommen   \t\t\t\t\t  |\n";
		cout << "|\t\t\t\t\t\t\t\t\t\t\t\t  |\n";
		cout << "|*************************************************************************************************|\n";
		cout << "|                                                                                                 |\n";
		cout << "|                                                                                                 |\n";
		cout << "|*************************************************************************************************|\n";
		cout << "| 1) Plus Rechnen";
		cout << "| 2) Mal Rechnen";
		break;	
	}
}
