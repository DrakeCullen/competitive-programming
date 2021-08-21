#include <bits/stdc++.h>

using namespace std;

int main() {
	priority_queue<int> pq;
	int n, t, one, two, res = 0;
	cin>>n;
	while(n--) {
		cin>>t;
		pq.push(-t);
	}
	while(pq.size() > 1) {
		one = -pq.top();
		pq.pop();
		two = -pq.top();
		pq.pop();
		res += one + two;
		pq.push(-(one + two));
	}
	cout<<res;
	return 0;
}
