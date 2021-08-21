#include <bits/stdc++.h>

using namespace std;

int main() {
	int maxNum = 0;
	string inp;
	for(int i=0;i<884;i++) {
		int l = 0, h = 127, cl = 0, cu = 7;
		cin>>inp;
		for(int j=0;j<7;j++) {
			if(inp[j] == 'B')
				l = ceil((l + h) / 2);
			else
				h = (l + h) / 2;
		}
		for(int j=7;j<10;j++) {
			if(inp[j] == 'R')
				cl = ceil((cl + cu) / 2);
			else
				cu = (cl + cu) / 2;
				
		}
		maxNum = max(maxNum, (l + 1) * 8 + cu);
		//cout<<l<<' '<<cu<<' '<<maxNum;
	}
	cout<<maxNum; //955
	return 0;
}






