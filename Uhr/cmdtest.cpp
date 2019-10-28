//test cmd UHR
//Ist Eine Uhr über CMD
//Nicola Bühler
//Datum: 2018

#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main(){
	int a=5;
	while(a>=0){
	cout << "  \263--------------\263\n";
	cout << "  \263  Willkommen  \263\n";
	cout << "  \263--------------\263\n";
	
	system("color 02");
	cout << "\t"; 
	system("time /t"); //cout << "|\r|";
	cout << "  \263--------------\263\n";
	cout << "  \300==============\331\n";
	
	
		Sleep(3600);
		system("CLS");
		}
return 0;
}
