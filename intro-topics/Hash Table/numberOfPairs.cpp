#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, sum, temp, ans = 0;
	unordered_map<int, int> cnt;
	cin>>sum>>n;
	int arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];
	for(int i = 0; i < n; i++) {
		ans += cnt[sum - arr[i]];
		cnt[arr[i]]++;
	}
	cout<<ans;
	return 0;
}
