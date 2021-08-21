#include <bits/stdc++.h>

using namespace std;

int main() {
	//Part 1
	/*
	int vals = 1000, min, max, valid = 0;
	char policy, temp;
	string password;
	
	while(vals--) {
		int cnt = 0;
		cin>>min>>temp>>max>>policy>>temp>>password;
		for(int i=0;i<password.size();i++)
			if(password[i] == policy)
				cnt++;	
		if(cnt >= min && cnt <= max) valid++;
	}
	cout<<valid; //645
	*/
	
	//Part 2
	int vals = 1000, min, max, valid = 0;
	char policy, temp;
	string password;
	
	while(vals--) {
		int cnt = 0;
		cin>>min>>temp>>max>>policy>>temp>>password;
		if (password[min - 1] == policy && password[max - 1] != policy || password[min - 1] != policy && password[max - 1] == policy) valid++;
	}
	cout<<valid; //737
	
	return 0;
}



