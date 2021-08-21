#include <bits/stdc++.h>

using namespace std;

int main() {
	//Part 1
	/*
	int trees = 0;
	string line;
	for(int cnt=0,i=0;cnt<323;cnt++, i= (i + 3) % 31) {
		cin>>line;
		if(line[i] == '#') trees++;
	}
	cout<<trees; //198
	*/
	
	unsigned long long t1, t2, t3, t4, t5;
	t1 = t2 = t3 = t4 = t5 = 0;
	string line;
	int mod = 31;
	for(int cnt=0,i1=0, i2=0, i3=0, i4=0, i5=0;cnt<323;cnt++, 
		i1 = (i1 + 1) % mod, i2= (i2+ 3) % mod, i3 = (i3 + 5) % mod,
		i4 = (i4 + 7) % mod)  {
		cin>>line;
		if(line[i1] == '#') t1++;
		if(line[i2] == '#') t2++;
		if(line[i3] == '#') t3++;
		if(line[i4] == '#') t4++;
		if((cnt + 1) % 2 == 0) {
			i5 = (i5 + 1) % mod;
			if(line[i5] == '#') t5++;
		}
		//cout<<i1<<' '<<i2<<' '<<i3<<' '<<i4<<' '<<i5<<endl;
	}
	//cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<' '<<t5;
	cout<<t1*t2*t3*t4*t5; //5140884672
	return 0;
}



