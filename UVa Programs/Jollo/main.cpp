#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c,x,y;
	while(cin>>a>>b>>c>>x>>y) {
		if(a==0 && b==0 && c==0 && x==0 && y==0) break;
		vector<int> princess, prince;
		int wins = 0, maximum = -1;
		princess.push_back(a); princess.push_back(b); princess.push_back(c);
		prince.push_back(x); prince.push_back(y); prince.insert(prince.begin(),0);
		sort(princess.begin(), princess.end());
		sort(prince.begin(), prince.end());
		do {
			do {
				if(prince[0] == 0) {
					if((prince[1] > princess[1] && prince[2] < princess[2]) || (prince[1] < princess[1] && prince[2] > princess[2]))
						maximum = max(maximum, princess[0] + 1);
					else if (prince[1] < princess[1] && prince[2] < princess[2])
					maximum = INT_MAX;
						
				}
				else if(prince[1] == 0) {
					if((prince[0] > princess[0] && prince[2] < princess[2]) || (prince[0] < princess[0] && prince[2] > princess[2]))
						maximum = max(maximum, princess[1] + 1);
					else if (prince[0] < princess[0] && prince[2] < princess[2])
						maximum = INT_MAX;	
				}
				else if(prince[2] == 0) {
					if((prince[1] > princess[1] && prince[0] < princess[0]) || (prince[1] < princess[1] && prince[0] > princess[0]))
						maximum = max(maximum, princess[2] + 1);
					else if (prince[1] < princess[1] && prince[0] < princess[0])
						maximum = INT_MAX;	
				} 
				//cout<<"princess: "<<princess[0]<<' '<<princess[1]<<' '<<princess[2]<<endl;
				//cout<<"prince: "<<prince[0]<<' '<<prince[1]<<' '<<prince[2]<<endl;
				//cout<<"max "<<maximum<<endl;
			}while(next_permutation(prince.begin(), prince.end()));
			//cout<<endl;
		}while(next_permutation(princess.begin(), princess.end()));
		if(maximum != -1 && maximum != INT_MAX)
			cout<<maximum<<endl;
		else cout<<-1<<endl;	
	}
	cout<<endl;
	
	return 0;
}






