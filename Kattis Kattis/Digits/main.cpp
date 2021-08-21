#include <bits/stdc++.h>

using namespace std;

int solve(int count, string inp){
	string size = to_string(inp.size());
	
	if(size == inp) return count;
	
	return solve(++count, size);
}

int main() {
	string inp;
	int res;
	while(cin>>inp) {
		if(inp == "END") break;
		res = solve(1,inp);
		cout<<res<<endl;
	}
	return 0;
}

