#include <bits/stdc++.h>

using namespace std;

//Part 2
bool testSolution(vector<pair<string, int>> v) {
	int count = 0, i = 1;
	bool b[612] = {0};
	while(i < 612) {
		if(b[i] == 1) break;
		else b[i] = 1;
		if(v[i].first == "acc") {count+=v[i].second; i++;}
		else if(v[i].first == "nop") i++;
		else i += v[i].second;
	}
	if(i == 611 || i == 612){ cout<<count; return 1;}
	return 0;
}

int main() {
	//Part 1
	/*
	string s, num;
	int val,i=1, count=0;
	bool b[612] = {0};
	vector<pair<string, int>> v(612);
	for(int i=1;i<612;i++) {
		getline(cin, s);
		num = s.substr(5);
		if(s[4] == '+') val = stoi(num);
		else val = stoi(num) * -1;
		v[i] = (make_pair(s.substr(0,3), val));
	}
	while(1) {
		if(b[i] == 1) break;
		else b[i] = 1;
		if(v[i].first == "acc") {count+=v[i].second; i++;}
		else if(v[i].first == "nop") i++;
		else i += v[i].second;
	}
	cout<<count; //1941
	*/
	
	string s, num;
	int val;
	vector<pair<string, int>> v(612);
	for(int i=1;i<612;i++) {
		getline(cin, s);
		num = s.substr(5);
		if(s[4] == '+') val = stoi(num);
		else val = stoi(num) * -1;
		v[i] = (make_pair(s.substr(0,3), val));
	}
	for(int i = 1;i<612;i++) {
		if(v[i].first == "jmp") {
			v[i].first = "nop";
			if(testSolution(v)) break;
			else v[i].first = "jmp";
		} else if(v[i].first == "nop") {
			v[i].first = "jmp";
			if(testSolution(v)) break;
			else v[i].first = "nop";
		}
	}
	
	return 0;
}




