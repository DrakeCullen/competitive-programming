#include <bits/stdc++.h>

using namespace std;

vector<int> findSum(vector<int> nums, int s) {
	int n = nums.size();
	unordered_map<int, vector<int>> mySums;
	for(int i = 0; i < n; i++) 
		for(int j = i; j < n; j++)
			for(int k = j; k < n; k++)
				mySums[nums[i] + nums[k] + nums[k]] = {nums[i], nums[j], nums[k]};
	
	for(int i = 0; i < n; i++) 
		for(int j = i; j < n; j++)
			for(int k = j; k < n; k++) {
				if(mySums.find(s - nums[i] - nums[j] - nums[k]) != mySums.end()) {
					vector<int> v = mySums[s - nums[i] - nums[j] - nums[k]];
					return {nums[i], nums[j], nums[k], v[0], v[1], v[2]};
				}
			}
	return {};
}

int main() {
	vector<int> v = {3, 7, 2, -1, -10}, res;
	res = findSum(v, 21);
	for(auto p:res) cout<<p<<' ';
	return 0;
}

