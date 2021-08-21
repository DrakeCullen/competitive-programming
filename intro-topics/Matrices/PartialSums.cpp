#include <bits/stdc++.h>

using namespace std;

const int n = 7, m = 7;

// O(n X m)
void initialize(int a[n][m], int s[n][m]) {
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) 
			s[i][j] = 0;
	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			s[i][j] = s[i][j-1] + s[i-1][j] + a[i][j] - s[i-1][j-1];
		}
	}
}

// O(1)
int partialSum(int s[n][m], int l1, int c1, int l2, int c2) {
	return s[l2][c2] - s[l1 - 1][c2] - s[l2][c1 - 1] + s[l1 - 1][c1 - 1];
}

int main() {
	int a[n][m] = { {0,  0,   0,  0,  0,  0, 0},
					{0, 1,  7,  12, 10, 1,  0},
					{0, 11, 7, -10,  1, 3, 13},
					{0, -2, 9,  -5,  2, 4,  7},
					{0, 4, 14,  -9,  3, 13,-6},
					{0, -7, -8, -9, 12, 6,  4},
					{0, 2, -13, 10, 11, 8,  7}};
	int s[n][m];
	initialize(a, s);
	cout<<partialSum(s, 3, 2, 5, 4);				
	
	return 0;
}



