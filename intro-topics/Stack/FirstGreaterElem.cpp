#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100005;

void buildAns(int a[], int n, int ans[]) {
	stack<int> s;
	for(int i = 0; i < n; i++) {
		while(!s.empty() && a[s.top()] < a[i]) {
			ans[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
}

int main() {
	int ans[NMAX], a[NMAX], n;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	buildAns(a, n, ans);	
	for(int i = 0; i < n; i++) {
		cout<<ans[i]<<' ';
	}
	return 0;
}
