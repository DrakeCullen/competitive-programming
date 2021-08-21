#include <bits/stdc++.h>

using namespace std;

struct event {
	char type;
	double time;
	bool operator<(const event &other) {
		return time < other.time;
	}
};

int main() {
	int n, free = 0, tot = 0; 
	cin>>n;
	vector<event> events(n*2);
	for(int i=0; i<n*2; i++) {
		cin>>events[i].time;
		events[i++].type = 'a';
		cin>>events[i].time;
		events[i].type = 'd';
	}
	sort(events.begin(), events.end());
	for(auto p:events) {
		if(p.type == 'a') {
			if(free == 0) tot++;
			else free--;
		} else
			free++;
	}
	cout<<tot;
	return 0;
}


