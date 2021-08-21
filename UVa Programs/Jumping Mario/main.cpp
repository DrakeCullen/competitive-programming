#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,n,c=1;
	cin>>t;
	while(t--) {
		int high=0,low=0,last,temp;
		cin>>n;
		cin>>last;
		n--;
		while(n--) {
			cin>>temp;
			if(temp > last) high++;
			else if(temp < last) low++;
			last = temp;
		}
		cout<<"Case "<<c++<<": "<<high<<' '<<low<<endl;
	}
	return 0;
}
