#include <bits/stdc++.h>

using namespace std;

int main() {
	int b=-1,n=-1,d,c,v,temp;
	while(cin>>b>>n && (b != 0 && n != 0)){
		bool isValid = true;
		vector<int> vec(b);
		for(int i=0;i<b;i++) {
			cin>>temp;
			vec[i] = temp;
		}
		for(int i=0;i<n;i++){
			cin>>d>>c>>v;
			vec[d-1] -= v;
			vec[c-1] += v;
		}
		for(auto p:vec)
			if(p < 0) {
				isValid = false;
				break;
			}
			
		if(isValid) cout<<'S'<<endl;
		else cout<<'N'<<endl;	
		
	}
	return 0;
}



