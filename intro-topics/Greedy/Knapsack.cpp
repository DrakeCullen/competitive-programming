#include <bits/stdc++.h>

using namespace std;

struct item {
	double v, w, vpu;
	void calc() {vpu = v / w; }
	bool operator<(const item &other) {
		return vpu > other.vpu;
	}
};

int solve(vector<item> items, double capacity) {
	double ans = 0, cnt = 0, wt = 0;
	int i = 0;
	while(i < items.size() && cnt < capacity) {
		ans += items[i].v;
		items[i].w--;
		cnt++;
		if(items[i].w == 0) i++;
	}
	return ans;
}

int main() {
	double capacity = 10;
	int n;
	cin>>n;
	vector<item> items(n);
	for(int i=0; i<n;i++) {
		cin>>items[i].v>>items[i].w;
		items[i].calc();
	}
	sort(items.begin(), items.end());
	cout<<solve(items, capacity);
	return 0;
}

