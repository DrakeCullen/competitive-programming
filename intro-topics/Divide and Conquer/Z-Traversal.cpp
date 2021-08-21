#include <bits/stdc++.h>

using namespace std;

int getValue(int n, int x, int y) {
	if(n == 0) return 1;
	if(x <= pow(2, n - 1)) {
		if(y <= pow(2, n - 1))
			return getValue(n - 1, x, y);
		return pow(2, 2 * n - 2) + getValue(n - 1, x, y - pow(2, n - 1));	
	}
	if(y <= pow(2, n - 1))
		return pow(2, 2 * n - 2) + getValue(n - 1, x - pow(2, n - 1), y);
	return 3 *(pow(2, 2 * n - 2)) + getValue(n - 1, x - pow(2, n - 1), y - pow(2, n - 1));	
}

int main() {
	cout<<getValue(2, 3, 4);
	return 0;
}
