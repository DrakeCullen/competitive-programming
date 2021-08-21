#include <bits/stdc++.h>

using namespace std;

int main() {
	string s,res;
	int count=0;
	while(cin>>s) {
		if(s == "#") break;
		if(s=="HELLO") res="ENGLISH";
	    else if(s=="HOLA") res="SPANISH"; 
	    else if(s=="HALLO") res="GERMAN"; 
	    else if(s=="BONJOUR") res="FRENCH"; 
	    else if(s=="CIAO") res="ITALIAN"; 
	    else if(s=="ZDRAVSTVUJTE") res="RUSSIAN"; 
	    else res="UNKNOWN";
   cout<<"Case "<<++count<<": "<<res<<endl;
	}
	return 0;
}

