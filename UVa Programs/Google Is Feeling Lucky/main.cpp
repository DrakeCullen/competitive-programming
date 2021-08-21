#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, c=1, rank;
	string url;
	string u[10] = {""};
	int rel[10] = {0};
	cin>>t;
	while(t--) {
		int max = 0;
		for(int i=0;i<10;i++) {
			cin>>url>>rank;
			if(rank >= max) {
				max = rank;
				u[i] = url;
				rel[i] = rank;
			}
		}
		
		cout<<"Case #"<<c++<<": ";
		for(int i=0;i<10;i++) {
			if(rel[i] == max)
				cout<<endl<<u[i];
		}
	}
	return 0;
}




