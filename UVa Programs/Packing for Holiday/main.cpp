#include <bits/stdc++.h>

using namespace std;

int main() {
	int t,l,w,h,count=0;
	cin>>t;
	while(t--) {
		cin>>l>>w>>h;
		if(l <= 20 && w <= 20 && h <= 20) cout<<"Case "<<++count<<": good"<<endl;
		else cout<<"Case "<<++count<<": bad"<<endl;
	}
	return 0;
}

