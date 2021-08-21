#include <bits/stdc++.h>

using namespace std;

char sym;

void findStop(string &s, int &stop, string &dig) {
	while(s[stop] != '+' && s[stop] != '='  && s[stop] != '-' && stop < s.length()) dig += s[stop++];
	if(s[stop] == '+') sym = '+';
	if(s[stop] == '-') sym = '-';
}

int main() {
	int stop=0, count = 0;
	string inp, a, b, c;
	while(cin>>inp) {
		stop = 0;
		a=b=c="";
		findStop(inp, stop, a); stop++;
		findStop(inp, stop, b); stop++;
		findStop(inp, stop, c);
		if(c != "?") {
			if(sym == '+') {
				if(stoi(a) + stoi(b) == stoi(c)) count++;
			} else {
				if(stoi(a) - stoi(b) == stoi(c)) count++;	
			}
		}	
	}
	cout<<count<<endl;
	return 0;
}

