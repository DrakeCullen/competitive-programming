#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	long long one,two;
	cin>>t;
	while(t--) {
		cin>>one>>two;
		if(one < two) cout<<'<'<<endl;
		else if(one > two) cout<<'>'<<endl;
		else cout<<'='<<endl;
	}
	return 0;
}
