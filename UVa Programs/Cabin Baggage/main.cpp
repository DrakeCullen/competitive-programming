#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tot=0;
	double l,wid,d,weight;
	cin>>t;
	while(t--){
		cin>>l>>wid>>d>>weight;
		if(((l<=56 && wid <=45 && d <= 25) || l+wid+d <= 125) && weight <= 7) {
			cout<<1<<endl;
			tot++;
		}else cout<<0<<endl;
	}
	cout<<tot<<endl;
	return 0;
}






