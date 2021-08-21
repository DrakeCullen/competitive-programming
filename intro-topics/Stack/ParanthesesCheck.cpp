#include <bits/stdc++.h>

using namespace std;

int typeOf(char c) {
	if(c == '(' || c == ')') return 0;
	if(c == '[' || c == ']') return 1;
	return 2;
}

bool validParanthesis(string s) {
	stack<char> brackets;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
			brackets.push(s[i]);
		else {
			if(!brackets.empty() && typeOf(brackets.top()) == typeOf(s[i]))
				brackets.pop();
			else
				return false;
		}	
	}		
	return brackets.empty();
}

int main() {
	string inp;
	cin >> inp;
	cout<<validParanthesis(inp);
	return 0;
}
