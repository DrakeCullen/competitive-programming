#include <bits/stdc++.h>

using namespace std;

void createRight(vector<int> &right, vector<int> h);
void createLeft(vector<int> &left, vector<int> h);
long long maxRectArea(vector<int> h);

int main() {
	vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
	cout<<maxRectArea(heights); 
	return 0;
}

void createRight(vector<int> &right, vector<int> h) {
	stack<int> st;
	for(int i = 0; i < right.size(); i++) {
		while(!st.empty() && h[i] < h[st.top()]) {
			right[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
}

void createLeft(vector<int> &left, vector<int> h) {
	stack<int> st;
	for(int i = left.size() - 1; i >= 0; i--) {
		while(!st.empty() && h[i] < h[st.top()]) {
			left[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
}

long long maxRectArea(vector<int> h) {
	int n = h.size();
	long long ans = 0;
	vector<int> left(n, -1), right(n, n);
	
	createRight(right, h);
	createLeft(left, h);
	
	for(int k = 0; k < n; k++) 
		ans = max(ans, h[k] * (right[k] - left[k] - 1) * 1LL);
	return ans;
}
