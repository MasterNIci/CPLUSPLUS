//
//Nicola Bühler
//ASCII
//



#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(){
	
	system("color 02");
	
	int iii=0;
	int leange=0;
	int anzahl=0;
	int zahl=0;
	
	

	
	
	
	
	string a1="0001";
	string a2="0010";
	string a3="0011";
	string a4="0100";
	string a5="0101";
	string a6="0110";
	string a7="0111";
	string a8="1000";
	string a9="1001";
	string a10="1010";
	string a11="1011";
	string a12="1100";
	string a13="1101";
	string a14="1110";
	string a15="1111";	
	
	string a="01100001";
	string aa="a";
	string b="01100010";
	string bb="b";
	string c="01100011";
	string cc="c";
	string d="01100100";
	string dd="d";
	string e="01100101";
	string ee="e";
	string f="01100110";
	string ff="f";
	string g="01100111";
	string gg="g";
	string h="01101000";
	string hh="h";
	string i="01101001";
	string ii="i";
	string j="01101010";
	string jj="j";
	string k="01101011";
	string kk="k";
	string l="01001100";
	string ll="l";
	string m="01001101";
	string mm="m";
	string n="01001110";
	string nn="n";
	string o="01101111";
	string oo="o";
	string p="01110000";
	string pp="p";
	string q="01110001";
	string qq="q";
	string r="01110010";
	string rr="r";
	string s="01110011";
	string ss="s";
	string t="01110100";
	string tt="t";
	string u="01110101";
	string uu="u";
	string v="01110110";
	string vv="v";
	string w="01110111";
	string ww="w";
	string x="01111000";
	string xx="x";
	string y="01111001";
	string yy="y";
	string z="01111010";
	string zz="z";
	
	int roller=1;
	int switcher;
	
	while(roller){

	string test;
	string eingab;
	

		
	ofstream hexnici;
	hexnici.open("codenici.txt", ios::app);
	

		cout << "Wahl 1 oder 2\n";
		cout << "1) Zahlen\n";
		cout << "2) Buchstaben\n";
	cin >> switcher;
	fflush(stdin);
	
	switch(switcher){
	case 1 :
	cout << "Zahl: ";
	cin >> test;
	fflush(stdin);
	

	
	if(test==a){
	cout << "a";
	eingab=a;
	}
	if(test==b){
	cout << "b";
	eingab=b;
	}
	if(test==c){
	cout << "c";
	eingab=c;
	}
	if(test==d){
	cout << "d";
	eingab=d;
	}
	if(test==e){
	cout << "e";
	eingab=e;
	}
	if(test==f){
	cout << "f";
	eingab=f;
	}
	if(test==g){
	cout << "g";
	eingab=g;
	}
	if(test==h){
	cout << "h";
	eingab=h;
	}
	if(test==i){
	cout << "i";
	eingab=i;
	}
	if(test==j){
	cout << "j";
	eingab=j;
	}
	if(test==k){
	cout << "k";
	eingab=k;
	}
	if(test==l){
	cout << "l";
	eingab=l;
	}
	if(test==m){
	cout << "m";
	eingab=m;
	}
	if(test==n){
	cout << "n";
	eingab=n;
	}
	if(test==o){
	cout << "o";
	eingab=o;
	}
	if(test==p){
	cout << "p";
	eingab=p;
	}
	if(test==q){
	cout << "q";
	eingab=q;
	}
	if(test==r){
	cout << "r";
	eingab=r;
	}
	if(test==s){
	cout << "s";
	eingab=s;
	}
	if(test==t){
	cout << "t";
	eingab=t;
	}
	if(test==u){
	cout << "u";
	eingab=u;
	}
	if(test==v){
	cout << "v";
	eingab=v;
	}
	if(test==w){
	cout << "w";
	eingab=w;
	}
	if(test==x){
	cout << "x";
	eingab=x;
	}
	if(test==y){
	cout << "y";
	eingab=y;
	}
	if(test==z){
	cout << "z";
	eingab=z;
	}
	cout << "\n";

	hexnici << test << " " << eingab << "\n\r";


	break;

	case 2 :
		cout << "Buchstaben: ";
		cin >> test;
//		fflush(stdin);
		
		while(test[iii]!='\0'){
			iii++;
			if(iii==iii){
			leange++;
			}
			}
			
			while(anzahl<=leange){
			
		
		if(test[zahl]=='a'){
			cout << a << "\n";
			eingab=a;
		}
		if(test[zahl]=='b'){
			cout << b << "\n";
			eingab=b;
			}
		if(test[zahl]=='c'){
			cout << c << "\n";
			eingab=c;
			}
		if(test[zahl]=='d'){
			cout << d << "\n";
			eingab=d;
			}
		if(test[zahl]=='e'){
			cout << e << "\n";
			eingab=e;
			}
		if(test[zahl]=='f'){
			cout << f << "\n";
			eingab=f;
			}
		if(test[zahl]=='g'){
			cout << g << "\n";
			eingab=g;
			}
		if(test[zahl]=='h'){
			cout << h << "\n";
			eingab=h;
			}
		if(test[zahl]=='i'){
			cout << i << "\n";
			eingab=i;
			}
		if(test[zahl]=='j'){
			cout << j << "\n";
			eingab=j;
			}
		if(test[zahl]=='k'){
			cout << k << "\n";
			eingab=k;
			}
		if(test[zahl]=='l'){
			cout << l << "\n";
			eingab=l;
			}
		if(test[zahl]=='m'){
			cout << m << "\n";
			eingab=m;
			}
		if(test[zahl]=='n'){
			cout << n << "\n";
			eingab=n;
			}
		if(test[zahl]=='o'){
			cout << o << "\n";
			eingab=o;
			}
		if(test[zahl]=='p'){
			cout << p << "\n";
			eingab=p;
			}
		if(test[zahl]=='q'){
			cout << q << "\n";
			eingab=q;
		}
		if(test[zahl]=='r'){
			cout << r << "\n";
			eingab=r;
		}
		if(test[zahl]=='s'){
			cout << s << "\n";
			eingab=s;
		}
		if(test[zahl]=='t'){
			cout << t << "\n";
			eingab=t;
		}
		if(test[zahl]=='u'){
			cout << u << "\n";
			eingab=u;
		}
		if(test[zahl]=='v'){
			cout << v << "\n";
			eingab=v;
		}
		if(test[zahl]=='w'){
			cout << w << "\n";
			eingab=w;
		}
		if(test[zahl]=='x'){
			cout << x << "\n";
			eingab=x;
		}
		if(test[zahl]=='y'){
			cout << y << "\n";
			eingab=y;
		}
		if(test[zahl]=='z'){
			cout << z << "\n";
			eingab=z;
		}
		anzahl++;
		zahl++;
		
		hexnici << test[zahl] << " " << eingab << "\n\r";		
		}
		
		break;
		}

}
return 0;
}

