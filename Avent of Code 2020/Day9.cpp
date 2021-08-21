#include <bits/stdc++.h>

using namespace std;

//Part 1
bool isValid(long long v[], int start, int stop, long long value) {
	for(int i=start;i<stop-1;i++)
		for(int j=i+1;j<stop;j++) 
			if(v[i] + v[j] == value)
				return true;
	return false;			
}

void startStop(long long v[], int &i, int &j) {
	for(i=0;i<999;i++)
		for(j=i+1;j<1000;j++) {
			long long sum = 0;
			for(int k=i;k<=j;k++)
				sum += v[k];
			if(sum == 3199139634) return;
		}
}		

int main() {
	//Part 1
	/*long long v[1000], last;
	bool done = false;
	for(int i=0;i<25;i++)
		cin>>v[i];

	for(int i=25; i<1000;i++) {
		cin>>v[i];
		if(!done)
			if(!isValid(v, i - 25, i, v[i])) {done = true; last = i;}
	}
	cout<<v[last]; // 3199139634
	*/
	
	//Part 2
	int start, stop;
	long long v[1000], minimum = INT_MAX, maximum = INT_MIN;
	for(int i=0;i<1000;i++)
		cin>>v[i];
	startStop(v, start, stop);
	for(int i=start;i<=stop;i++) {
		minimum = min(minimum, v[i]);
		maximum = max(maximum, v[i]);
	}
	cout<<maximum + minimum; // 438559930
	return 0;
}





