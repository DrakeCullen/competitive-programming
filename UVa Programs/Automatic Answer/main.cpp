#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		n = (((n * 567) / 9) + 7492) * 235 / 47 - 498;
		n/=10;
		cout<<abs(n%10)<<endl; 
	}
	return 0;
}



