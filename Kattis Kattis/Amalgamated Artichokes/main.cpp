#include <bits/stdc++.h>

using namespace std;

int main() {
	double p,a,b,c,d,n;
	while(cin>>p>>a>>b>>c>>d) {
		cin>>n;
		double diff = 0;
		double max = p * (sin(a + b) + cos(c + d) + 2);
		for(int k=2;k<=n;k++) {
			double temp = p * (sin(a * k + b) + cos(c * k + d) + 2);
			if(temp > max)
				max = temp;
			else {
				if(max - temp > diff)
					diff = max - temp;
			}	
		}
		cout<<showpoint<<fixed<<setprecision(10)<<diff<<endl;
	}
	return 0;
}

