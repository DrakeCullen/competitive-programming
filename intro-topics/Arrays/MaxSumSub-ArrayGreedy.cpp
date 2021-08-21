#include <bits/stdc++.h>

using namespace std;

long long maxSumSubarray(int a[], int n) {
	long long ans = a[0], sum = 0;
	int left = 0, right = 0;
	for(int i=0;i<n;i++) {
		sum += a[i];
		if(sum > ans) {
			ans = sum;
			right = i;
		}
		if(sum < 0) {
			sum = 0;
			left = i+1;
		}
	}
	cout<<left<<' '<<right<<endl;
	return ans;
}

int main() {
	int a[7] = {5, -6, 3, 4, -2, 3, -3};
	cout<<maxSumSubarray(a, 7);
	return 0;
}



