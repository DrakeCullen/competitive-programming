#include <bits/stdc++.h>

using namespace std;

void update(string inp, int &iVal, int &guess, int &count) {
	if(inp == "++i") {
			++iVal;
			if(guess == iVal) count++;
			else iVal= guess;
		}
		else if(inp == "i++") {
			if(guess == iVal) count++;
			else iVal = guess;
			iVal++;
		}
		else if(inp == "--i") {
			--iVal;
			if(guess == iVal) count++;
			else iVal= guess;
		}
		else if(inp == "i--") {
			if(guess == iVal) count++;
			else iVal= guess;
			 iVal--;
		}
		else if(inp == "i") {
			if(guess == iVal) count++;
			else iVal= guess;
	}
}

int main() {
	string start, inp;
	int t, iVal, count, guess;
	while(cin>>start>>t) {
		count = 0;
		if(start == "0" && t == 0) break;
		if(start[0] == '0' && start[1] == 'x') {
			stringstream ss;
			ss << hex << start;
			ss >> iVal;
		}
		else if(start[0] == '0') iVal = stoi(start, 0, 8);
		else iVal = stoi(start);
		
		for(int i=0; i<t; i++) {
			cin>>inp>>guess;
            update(inp, iVal, guess, count);
        }
		cout<<count<<endl;
	}

  return 0;
}

