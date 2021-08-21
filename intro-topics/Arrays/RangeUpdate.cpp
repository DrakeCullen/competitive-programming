#include <bits/stdc++.h>

using namespace std;

const int SIZE = 9;

int b[SIZE], s[SIZE], a[SIZE] = {2, -7, 10, 3, -1, 19, -20, 23, 17};

void update(int x, int y, int val, int size) {
	b[x] += val;
	if(y+1<size) b[y+1] -= val;
}

void buildFinalArray(int size) {
	s[0] = b[0];
	a[0] += s[0];
	for(int i=1;i<size;i++){
		s[i] = s[i-1] + b[i];
		a[i] += s[i];
	} 
}

int main() {
	update(2,6,5,SIZE);
	update(3,7,2,SIZE);
	update(1,5,-1,SIZE);
	buildFinalArray(SIZE);
	for(auto i:a) cout<<i<<' ';
	return 0;
}

