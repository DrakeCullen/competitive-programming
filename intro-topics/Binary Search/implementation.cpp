#include <bits/stdc++.h>

using namespace std;

int bSearch(int a[], int n, int target) {
	int left = 0, right = n - 1, mid;
	while(left <= right) {
		mid = (left + right) / 2;
		if(a[mid] == target)
			return mid;
		else if(a[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main() 
{ 
	int n = 6;
	int a[n] = {1, 3, 5, 7, 9, 11};
	cout<<bSearch(a,n,7);
    return 0; 
} 


