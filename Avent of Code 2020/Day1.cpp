#include <bits/stdc++.h>

using namespace std;

void findProd(vector<int> &v) {
	for(int i=0;i<v.size() - 2;i++) {
		for(int j=i+1;j<v.size() - 1;j++) {
			for(int k=j+1;k<v.size();k++) {
				if(v[i] + v[j] + v[k] == 2020) {
					cout<<v[i]*v[j]*v[k];
					return;
				}
			}
		}	
	}
}

int main() {
	//Part 1 
	/*
	vector<int> v;
	int n = 200, temp, num1, num2;
	while(n--) {
		cin>>temp;
		v.push_back(temp);
	}
	for(int i=0;i<v.size();i++) {
		num1 = v[i];
		auto it = find(v.begin(), v.end(), 2020 - num1);
		if(it != v.end()) {
			num2 = *it;
			break;
		}
	}
	cout<<num1*num2;
	//output -> 471019
	* */
	
	vector<int> v;
	int n = 200, temp, num1, num2;
	while(n--) {
		cin>>temp;
		v.push_back(temp);
	}
	findProd(v); //103927824
	return 0;
}



