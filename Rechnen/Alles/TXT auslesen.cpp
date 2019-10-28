//Nicola Bühler
//2018
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int main(){
	cout << "Der Text\n";
	ifstream myfile;
	string line;
	myfile.open ("Baum.txt", ios::out);
	
	  if (myfile.is_open())
  {
	 while ( getline (myfile,line) )
    {
      cout << line << '\n';
      ofstream newbaum;
      newbaum.open("NewBaum.txt", ios::in);
      
	   
    }
	myfile.close();
return 0;
}
}
