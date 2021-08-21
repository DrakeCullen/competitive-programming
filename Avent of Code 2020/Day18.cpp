#include <bits/stdc++.h>

using namespace std;

int main() {
	queue<int> vals;
	queue<char> sym;
	int temp, tot = 0;
	string inp, num;
	getline(cin, inp);
	for(int i = 0; i < inp.size(); i++) {
		if(isalpha(inp[i])) {
			num = inp[i];
			vals.push(stoi(num));
		}
		else if (inp[i] == '(' && inp[i] != ' ')
			sym.push(inp[i]);
	}
	return 0;
}
