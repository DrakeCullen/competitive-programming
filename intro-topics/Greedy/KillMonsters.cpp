#include <bits/stdc++.h>

using namespace std;

int killMonsters(int hp, int potions, vector<int> dmg) {
	priority_queue<int> kills;
	int cnt = 0;
	for(int i = 0; i < dmg.size(); i++) {
		if(dmg[i] <= 0) hp += abs(dmg[i]);
		else {
			hp -= dmg[i];
			kills.push(dmg[i]);
			while(hp <= 0 && potions > 0 && kills.empty() == false) {
				cnt++;
				hp += kills.top();
				kills.pop();
				potions--;
			}
			if(hp < 0) return i;
			if(hp == 0) return i + 1;
		}
	}
	return cnt;
}

int main() {
	int n, k, x;
	cin>>n>>k>>x; //n - # monsters, k - # potions, x - health
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<killMonsters(x, k, v);
	return 0;
}


