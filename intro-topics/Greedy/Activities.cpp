#include <bits/stdc++.h>

using namespace std;

struct activity {
	int start, finish;
	bool operator<(const activity &other) {
		return finish < other.finish;
	}
};

int main() {
	int n, cnt = 0, curr;
	cin>>n;
		vector<activity> activities(n);
	for(int i = 0; i < n; i++)
		cin>>activities[i].start>>activities[i].finish;
	sort(activities.begin(), activities.end());
	curr = activities[0].finish;
	for(int i = 0; i < activities.size(); i++) {
		if(activities[i].start >= curr) {
			cnt++;
			curr = activities[i].finish;
		}
	}
	cout<<cnt;
	return 0;
}


