#include <iostream>

using namespace std;

int fastExpo(long long a, long long n, int mod) {
	if(n == 0) return 1;
	if(n % 2 == 0)
		return fastExpo((a * a) % mod, n/2, mod);
	return (a * fastExpo(a, n - 1, mod) % mod);	
}

int itFastExpo(long long a, long long n, int mod) {
	int ans = 1;
	while(n > 0) {
		if(n % 2 == 0) {
			a = (a * a) % mod;
			n /= 2;
		} else {
			n--;
			ans = (a * ans) % mod;
		}
	}
	return ans;
}

int main() {
	cout<<fastExpo(5, 13, 1000000007)<<endl;
	cout<<itFastExpo(5,13,1000000007);
	return 0;
}

/*  Walkthrough for iterative approach:
 * 	a = 2, n = 13 --> 2^13, ans = 1
	1. n is odd : (2 ^ 12), a = 2, n = 12, ans = 2;
	2. n is even : (4^6), a = 4, n = 6, ans = 2;
	3. n is even : (16^3), a = 16, n = 3, ans = 2;
	4. n is odd : 16^2, a = 16, n = 2, ans = 32;
	5. n is even : 256^1, a = 256, n = 1, ans = 32;
	6. n is odd : 256^0, a = 256, n = 0, ans = 32 * 256 = 8192
 */
