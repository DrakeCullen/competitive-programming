#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,k,temp,gcd = 360;
	cin>>n>>k;
	while(n--){
		cin>>temp;
		gcd = __gcd(gcd,temp);
	}
	while(k--) {
		cin>>temp;
		if(temp % gcd == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
	
}
