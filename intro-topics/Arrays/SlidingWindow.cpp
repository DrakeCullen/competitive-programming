#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100005;

int freq[NMAX];

int slidingWindow(int a[], int n, int k) {
	int ans = 0, cnt = 0, right;
	for(right = 1; right <= n; right++) {
		if(++freq[a[right]] == 1) 
			cnt++;
		if(cnt > k) 
			break;
	}
	if(cnt <= k)
		return n;
	if(--freq[a[right--]] == 0)
		cnt--;
	for(int left = 2; left <= n; left++) {
		if(--freq[a[left - 1]] == 0)
			cnt--;
		while(right < n) {
			if(++freq[a[++right]] == 1)
				cnt++;
			if(cnt > k)
				break;
		}	
		if(cnt <= k)
			return max(ans, n - left + 1);
		if(--freq[a[right--]] == 0)
				cnt--;
		ans = max(ans, right - left + 1);		
	}
	return ans;	
}

int main() { 
    int n, k, a[NMAX];
    cin>>n>>k;
    for(int i = 1; i<= n; i++)
		cin>>a[i];
	cout<<slidingWindow(a, n, k);	
    return 0; 
} 



