#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, string, string> myTuple;

bool cmp(myTuple one, myTuple two) {
	auto &[age, first, last] = one;
	auto &[age2, first2, last2] = two;
	if(age != age2) return age < age2;
	if(last != last2) return last > last2;
	return first < first2;
}

int main()
{
    vector<myTuple> people;
    people.push_back(make_tuple(20, "drake", "cullen"));
    people.push_back(make_tuple(10, "drake", "cullen"));
    people.push_back(make_tuple(50, "drake", "cullen"));
    people.push_back(make_tuple(20, "brock", "cullen"));
    people.push_back(make_tuple(20, "drake", "rullen"));
    sort(people.begin(), people.end(), cmp);
    for(auto it:people)
		cout<<get<0>(it)<<' '<<get<1>(it)<<' '<<get<2>(it)<<endl;

}
