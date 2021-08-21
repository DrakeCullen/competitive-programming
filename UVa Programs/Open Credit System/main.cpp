#include <bits/stdc++.h>

using namespace std;

int main() {
	long long t,n;
	cin>>t;
	while(t--) {
		long long maxi=INT_MIN,diff=INT_MIN,temp;
		cin>>n;
		cin>>maxi;
		n--;
		while(n--){
			cin>>temp;
			if(maxi - temp > diff) diff = maxi - temp;
			if(temp > maxi) maxi = temp;

		}
		
		cout<<diff<<endl;		
		
	}
	return 0;
}

