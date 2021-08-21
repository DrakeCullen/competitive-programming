#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int arr[s.size()] = {}, sum = 0;
		if(s[0] == 'O') {arr[0]++; sum++;}
		for(int i=1;i<s.size();i++) {
			if(s[i] == 'O'){
				arr[i] = arr[i-1] + 1;
			} 
			sum += arr[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}


