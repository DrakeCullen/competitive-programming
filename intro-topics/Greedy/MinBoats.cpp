#include <bits/stdc++.h>

using namespace std;

int minNumOfBoats(vector<int> wt, int w, int b) {
	sort(wt.begin(), wt.end());
	int n = wt.size(), ans = 0, p = 0;
	vector<bool> isTaken(n, false);
	priority_queue<pair<int, int>> q;
	for(int i = n - 1; i >= 0; i--) {
		while(p < i && wt[p] + wt[i] <= w)
			q.push({wt[p], p++});
		if(isTaken[i]) continue;
		while(!q.empty() && wt[i] - q.top().first <= b) {
			if(isTaken[q.top().second]) {
				q.pop();
				continue;
			}
		isTaken[i] = isTaken[q.top().second] = true;
		q.pop();
		break;	
		}
	ans++;
	}
	return ans;
}

int main() {
	vector<int> wt = {81, 37, 32, 88, 55, 93, 45, 72};
	int b = 10, w = 100;
	cout<<minNumOfBoats(wt, w, b);
	return 0;
}


