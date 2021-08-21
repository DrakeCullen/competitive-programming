#include <bits/stdc++.h>

using namespace std;

int maxLeftSum(int a[], int left, int mid) {
	int maxS = a[mid], sum = 0;
	for(int l = mid; l >= left; l--) {
		sum += a[l];
		maxS = max(maxS, sum);
	}
	return maxS;
}

int maxRightSum(int a[], int mid, int right) {
	int maxS = a[mid + 1], sum = 0;
	for(int r = mid + 1; r <= right; r++) {
		sum += a[r];
		maxS = max(maxS, sum);
	}
	return maxS;
}

int maxSumSubarray(int a[], int left, int right) {
	if(left == right) return a[left];
	int mid = (left + right) / 2;
	int ans = max(maxSumSubarray(a, left, mid), maxSumSubarray(a, mid + 1, right));
	
	return max(ans, maxLeftSum(a, left, mid) + maxRightSum(a, mid, right));
}

int main() {
	int a[] = {5, -6, 3, 4, -2, 3, -3};
	cout<<maxSumSubarray(a, 0, 6);  
	return 0;
}
