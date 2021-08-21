#include <bits/stdc++.h>

using namespace std;

/*void findMin(int earliest, int time, int &id, int &min) {
	int arrival = earliest;
	while(arrival % time != 0) arrival++;
		if(arrival - earliest < min) {
			min = arrival - earliest;
			id = time;
		}
}*/


int main() {
	//Part 1
	/*
	int earliest, min = INT_MAX, id;
	string inp, time;
	
	cin>>earliest>>inp;
	stringstream ss(inp);
	while(getline(ss, time, ',')) {
		if(time != "x")
			findMin(earliest, stoi(time), id, min);
	}
	cout<<min*id; //115
	*/
	
	string inp, time;
	int pos, max = INT_MIN;
	vector<int> v;
	
	cin>>inp;
	stringstream ss(inp);
	while(getline(ss, time, ',')) {
		if(time == "x") v.push_back(-1);
		else v.push_back(stoi(time));
	}
	for (int i=0;i<v.size();i++) {
		v[i] += i;
		if(v[i] > max) {
			max = v[i];
			pos = i;
		}
	}
	cout<<max<<' '<<pos<<' '<<v[pos];
	return 0;
}

