#include <bits/stdc++.h>

using namespace std;

long long maxSumSubarray(int a[], int n) {
	if(n == 0) return 0;
	int s[n], ans = a[0], min = 0;
	s[0] = a[0];
	for(int i=1;i<n;i++)
		s[i] = s[i-1] + a[i];
	
	for(int i=0;i<n;i++) {
		if(s[i] - min > ans)
			ans = s[i] - min;
		if(s[i] < min)
			min = s[i];
	}	
	return ans;
}

int main() {
	int a[7] = {5, -6, 3, 4, -2, 3, -3};
	cout<<maxSumSubarray(a, 7);
	return 0;
}



