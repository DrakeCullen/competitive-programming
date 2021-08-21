#include <bits/stdc++.h>

using namespace std;

int main() {
	int x=0,y=0,dist, degr=90;
	string inp,cmd;
	for(int i=0;i<783;i++){
		cin>>inp;
		dist = stoi(inp.substr(1));
		if(inp[0] == 'N') y += dist;
		else if(inp[0] == 'S') y -= dist;
		else if(inp[0] == 'W') x -= dist;
		else if(inp[0] == 'E') x += dist;
		else if(inp[0] == 'R')
			degr =  (degr + dist) % 360;
		else if(inp[0] == 'L')
			degr = (degr - dist) % 360;
		else {
			if(degr == 90) x += dist;
			else if(degr == 0) y += dist;
			else if(degr == 270) x -= dist;
			else if(degr == 180) y -= dist;
		}
	}
	cout<<abs(x)+abs(y); //9704
	//962
	return 0;
}

