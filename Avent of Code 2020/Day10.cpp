#include <bits/stdc++.h>

using namespace std;



int main() {
	const int SIZE = 103;
	vector<int> arr;
	int one,three,maxNum,temp;
	one=three=maxNum=0;
	for(int i=0;i<SIZE;i++) {
		cin>>temp;
		arr.push_back(temp);
		maxNum = max(maxNum,temp);
	}
	arr.push_back(0);
	arr.push_back(maxNum+3);
	sort(arr.begin(), arr.end());	
	for(unsigned long long i=1;i<SIZE+2;i++) {
		if(arr[i]-arr[i-1] == 1) one++;
		else if(arr[i]-arr[i-1] == 3) three++;
	}
	cout<<one*three; //2263
	return 0;
}




