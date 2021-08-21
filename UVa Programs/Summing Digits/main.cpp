#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	while(cin>>n && n != 0) {
		while(n > 9) {
			long long temp = 0;
			while(n > 0) {
				temp += n % 10;
				n /= 10;
			}
			n = temp;
		}
		cout<<n<<endl;
	}
	return 0;
}

