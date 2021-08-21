#include <bits/stdc++.h>

using namespace std;

int main() {
	char c;
	int m,n,t;
	cin>>t;
	while(t--) {
		cin>>c>>m>>n;
		if(c == 'r') cout<<min(m,n)<<endl;
		else if(c == 'k') cout<<((m*n)+1)/2<<endl;
		else if(c == 'Q') cout<<min(m,n)<<endl;
		else if(c == 'K') cout<<((n+1)/2)*((m+1)/2)<<endl;
	}
	return 0;
}







