#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> p;

bool cmp(p one, p two) {
	return one.first / one.second < two.first / two.second;
}

int main() {
	vector<p> fractions;
	fractions.push_back(make_pair(1.0, 2.0));
	fractions.push_back(make_pair(1.0, 3.0));
	fractions.push_back(make_pair(2.0, 5.0));
	fractions.push_back(make_pair(2.0, 3.0));
	sort(fractions.begin(), fractions.end(), cmp);
	for(auto it: fractions)
		cout<<it.first<<'/'<<it.second<<" = "<<it.first/it.second<<endl;
}
