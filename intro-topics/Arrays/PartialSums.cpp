#include <bits/stdc++.h>

using namespace std;

void buildPartialSums(int a[], int s[], int size) {
	s[0] = a[0];
	for(int i=1;i<size;i++) s[i] = s[i-1] + a[i];
}

long long query(int x, int y, int s[]) {
	return s[y] - s[x-1];
}

int main() {
	int size = 8;
	int s[size], a[size] = {7, -2, 3, 9, -11, 5, 1, -3};
	buildPartialSums(a,s,8);
	cout<<query(2,5,s);
	return 0;
}
