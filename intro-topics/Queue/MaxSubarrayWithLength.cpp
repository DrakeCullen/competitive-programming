#include <bits/stdc++.h>

using namespace std;

int maxSum(int a[], int n, int A, int B) {
	int ans = 0;
	vector<int> s(n + 1, 0);
	deque<int> dq;
	dq.push_back(0);
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for(int right = 1; right <= n; right++) {
		if(!dq.empty() && dq.front() < right - B)
			dq.pop_front();
		if(right >= A)
			ans = max(ans, s[right] - s[dq.front()]);
		while(!dq.empty() && s[dq.back()] >= s[right])
			dq.pop_back();
		dq.push_back(right);	
	}
	return ans;
}

int main(){
    int n = 8, A = 2, B = 4;
    int a[] = {0, 2, -9, 7, -2, 8, -1, 1};
	cout<<maxSum(a, n, A, B);
}
