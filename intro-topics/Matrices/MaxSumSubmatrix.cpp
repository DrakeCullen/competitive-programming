#include <bits/stdc++.h>

using namespace std;

const int NMAX = 101, MMAX = 101;

int a[NMAX][MMAX], n, m;
long long upSum[NMAX][NMAX]; // upSum[i][j] = a[1][j] + a[2][j] + ... + a[i][j] 

long long maxSumSubarray(long long a[], int n) {
	long long ans = a[1], sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += a[i];
		ans = max(ans, sum);
		if(sum < 0)
			sum = 0;
	}
	return ans;
}

long long maxSumSubmatrix() {
	for(int i = 1; i<= n; i++)
		for(int j = 1; j <= m; j++)
			upSum[i][j] = upSum[i - 1][j] + a[i][j];
	
	long long v[MMAX]; // v[i] = a[r1][i] + a[r1+1][i] + ... + a[r2][i]	
	long long ans = a[1][1];
	for(int r1 = 1; r1 <= n; r1++)
		for(int r2 = r1; r2 <= n; r2++) {
			for(int i = 1; i <= m; i++)
				v[i] = upSum[r2][i] - upSum[r1 - 1][i];
			ans = max(ans, maxSumSubarray(v, m));	
		}
	return ans;	
}


int main() {
	cin>>n>>m;
	for(int i = 1; i <= n; i++)	
		for(int j = 1; j <= m; j++)
			cin>>a[i][j];
	cout<<maxSumSubmatrix();		
	
	return 0;
}



