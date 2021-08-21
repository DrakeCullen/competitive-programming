#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n,temp,c=1;
	cin>>t;
	while(t--) {
		int maximum=INT_MIN;
		cin>>n;
		while(n--) {
			cin>>temp;
			maximum = max(maximum,temp);
		}
		cout<<"Case "<<c++<<": "<<maximum<<endl;
	}
	return 0;
}

