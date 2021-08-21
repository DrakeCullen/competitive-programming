#include <bits/stdc++.h>

using namespace std;


int main() {
	map<int,int> m;
	m[2] = 2; m[15] = 3; m[0] = 4; m[9] = 5; m[1] = 6; m[20] = 7;
	int prev = 0, temp, curr;
	for(int i=8; i<=30000000; i++) {
		if(m[prev] != 0) {
			curr = prev;
			prev = i - m[prev];
			m[curr] = i;
			
		} else {
			m[prev] = i;
			curr = prev;
			prev = 0;
		}
	}
	cout<<prev;	
	return 0;
}

