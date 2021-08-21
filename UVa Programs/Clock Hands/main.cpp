#include <bits/stdc++.h>

using namespace std;

void readInp(string inp, double &hour, double &min) {
	string tempHr, tempMin;
	if(inp[1] == ':') {
			tempHr = inp[0];
			tempMin = inp.substr(2);
			hour = stoi(tempHr);
			min = stoi(tempMin);
	}else {
			tempHr = inp.substr(0,2);
			tempMin = inp.substr(3);
			hour = stoi(tempHr);
			min = stoi(tempMin);
	}
}

void update(double &hour, double &min) {
	if(hour == 0) hour = 12;
	if(min == 0) min = 60;
}

int main() {
	string inp;
	double hour, min, frac, diff;
	while(cin>>inp) {
		readInp(inp, hour, min);
		if(hour == 0 && min == 0) break;
		update(hour, min);
		if(min != 60) {frac = min / 60.0; hour += frac;}
		min = min * 6;
		hour = hour * 30;
		diff = abs(min - hour);
		if(360 - diff < diff) diff = 360 - diff;
		cout<<fixed<<showpoint<<setprecision(3)<<diff<<endl;
	}
	return 0;
}


