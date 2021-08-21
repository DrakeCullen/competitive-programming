#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned long long hash, opp,temp1,temp2;
	while(cin>>hash>>opp) {
		temp1 = max(opp,hash);
		temp2 = min(opp,hash);
		cout<<temp1-temp2<<endl;
	}
	return 0;
}




