#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	char a[5][4*n];
	for(int i=0;i<5;i++)
		for(int j=0;j<4*n;j++)
			cin>>a[i][j];
	
	for(int i=0;i<4*n;i+=4) {
		if(a[0][i] == '.') cout<<1;
		else if(a[0][i] == '*' && a[3][i] == '*') cout<<2;
		else if(a[0][i] == '*' && a[3][i] == '.') cout<<3;
	}
	cout<<endl;
	return 0;
}





