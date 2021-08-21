#include <iostream>
#include <climits>

using namespace std;

const int nMax = 100001;

bool isPrime[nMax];

void sieveOfErathosthenes(int n) {
	for(int i = 2; i <= n; i++) isPrime[i] = true;
	for(int i = 2; i <= n / 2; i++) {
		if(isPrime[i] == true) {
			for(int j = 2 * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}
}

int main() {
	int limit;
	cout<<"Enter a limit up to 100k: ";
	cin>>limit;
	sieveOfErathosthenes(limit);
	for(int i = 2; i <= limit; i++) {
		if(isPrime[i] == true) cout<<i<<' ';
	}
	return 0;
}
