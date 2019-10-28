//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string fix1(string str1){
	cout << "Name:\t\t ";
	cin >> str1;
	return(str1);
}
string fix2(string str2){
	cout << "Nachname:\t ";
	cin >> str2;
	return(str2);
}
string zweier(string wolle1, string wolle2){ 
	cout << "Zwei String:\t "<< wolle1 << " ";
	cout << wolle2;
	return(wolle1 + wolle2);
}

int main(){
	string str1;
	string str2;
	string wolle1;
	string wolle2;
	
	wolle1=fix1(str1);
	wolle2=fix2(str2);
	
	zweier(wolle1, wolle2);
	
}
