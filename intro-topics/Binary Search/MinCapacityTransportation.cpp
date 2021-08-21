#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100005;

int maxVal(int a[], int n) {
	int maxVal = a[0];
	for(int i = 1; i < n; i++)
		maxVal = max(maxVal, a[i]);
	return maxVal;	
}

long long sumOf(int a[], int n) {
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	return sum;	
}

int numOfRides(int a[], int n, long long capacity) {
	int ans = 1;
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		if(sum + a[i] <= capacity)
			sum += a[i];
		else {
			ans++;
			sum = a[i];
		}	
	}
	return ans;
}

long long bSearch(int a[], int n, int target) {
	int left = maxVal(a, n), right = sumOf(a, n), ans;
	while(left <= right) {
		long long mid = (left + right) / 2;
		if(numOfRides(a, n, mid) > target) 
			left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	return ans;
}

int main() 
{ 
	int n, k, a[NMAX];
	cin>>n>>k;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	cout<<bSearch(a, n, k);	
    return 0; 
} 



