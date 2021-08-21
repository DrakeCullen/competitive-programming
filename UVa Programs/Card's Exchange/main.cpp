#include <bits/stdc++.h>

using namespace std;
	

int main() {
	int one, two, temp;
	
	while(1) {
		cin>>one>>two;
		int a[100001] = {0}, b[100001] = {0}, aTot = 0, bTot = 0;
		if(one == 0 && two == 0) break;
		for(int i=0;i<one;i++) {
			cin>>temp;
			a[temp]++;
		}
		for(int i=0;i<two;i++) {
			cin>>temp;
			b[temp]++;
		}
		for(int i=0;i<100001;i++) {
			if(a[i] > 0 && b[i] == 0) aTot++;
			else if(b[i] > 0 && a[i] == 0) bTot++;
		}
		cout<<min(aTot, bTot)<<endl;
	}
	return 0;
}






