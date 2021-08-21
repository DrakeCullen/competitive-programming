#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1001;

bool a[NMAX][NMAX];
int n, m, maxLen[NMAX][NMAX]; // maxLen[i][j] = max x such as (i 0 x + 1, j - x + 1) -->
							  // (i, j) full of 1s.
							  // maxLen[i][j] = min(maxLen[i-1][j], maxLen[i][j-1], maxLen[i-1][j-1]

int maxSizeSquare() {
	int ans = 0;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j<= m; j++) {
			if(a[i][j] == 0)
				maxLen[i][j] = 0;
			else
				maxLen[i][j] = min(maxLen[i-1][j], min(maxLen[i][j-1], maxLen[i-1][j-1])) + 1;
			ans = max(ans, maxLen[i][j]);	
		}
	return ans;
}

int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j = 1; j <= m; j++)
			cin>>a[i][j];
	cout<<maxSizeSquare();		
	return 0;
}



