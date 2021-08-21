#include <bits/stdc++.h>

using namespace std;

void updateRange(bool valid[1000], string num) {
	int dash = num.find('-');
	int start = stoi(num.substr(0, dash));
	int stop = stoi(num.substr(dash + 1));
	for(int i = start; i <= stop; i++) valid[i] = 1;
}

void processString(bool valid[1000], string inp) {
	stringstream ss(inp);
	string word;
	while(getline(ss, word, ' ')) {
		if(isdigit(word[0]))
			updateRange(valid, word);
	}
}

void checkTicket(bool valid[1000], int &res, string inp) {
	stringstream ss(inp);
	string value;
	while(getline(ss, value, ',')) 
		if(!valid[stoi(value)]) 
			res += stoi(value);
	
}

int main() {
	int res = 0;
	bool valid[1000] = {0};
	string inp;
	while(getline(cin, inp)) {
		if(inp.length() == 0) break;
		processString(valid, inp);
	}
	getline(cin, inp);
	getline(cin, inp);
	getline(cin, inp);
	getline(cin, inp);
	for(int i=0; i<238; i++) {
		getline(cin, inp);
		checkTicket(valid, res, inp);
	}
	cout<<res;
	return 0;
}
