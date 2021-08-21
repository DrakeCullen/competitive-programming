#include <bits/stdc++.h>

using namespace std;

int main() {
	string sOne,sTwo;
	while(getline(cin,sOne) && getline(cin,sTwo)) {
		int one=0,two=0,temp=0;
		for(int i=0;i<sOne.length();i++) {
			if((int)sOne[i] >= 65 && (int)sOne[i] <= 90) one += (int)sOne[i] - 64;
			else if((int)sOne[i] >= 97 && (int)sOne[i] <= 122) one += (int)sOne[i] - 96;
		}
		for(int i=0;i<sTwo.length();i++) {
			if((int)sTwo[i] >= 65 && (int)sTwo[i] <= 90) two += (int)sTwo[i] - 64;
			else if((int)sTwo[i] >= 97 && (int)sTwo[i] <= 122) two += (int)sTwo[i] - 96;
		}
		while(one > 9) {
			while(one > 0) {
				temp += one % 10;
				one /= 10;
			}
			one = temp;
			temp = 0;
		}
		temp=0;
		while(two > 9) {
			while(two > 0) {
				temp += two % 10;
				two /= 10;
			}
			two = temp;
			temp = 0;
		}
		double oneF=one*1.0, twoF = two*1.0;
		if(one < two) cout<<fixed<<setprecision(2)<<oneF/twoF * 100.0<<" %"<<endl;
		else cout<<fixed<<setprecision(2)<<twoF/oneF * 100.0<<" %"<<endl;

	}
	return 0;
}

