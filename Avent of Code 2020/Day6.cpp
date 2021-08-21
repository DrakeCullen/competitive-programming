#include <bits/stdc++.h>

using namespace std;

int main() {
	//Part 1
	/*
	string inp="f";
	int sum=0;
	while(true) {
		bool arr[26] = {0};
		int count = 0;
		while(getline(cin,inp)){
			if(inp == "") 
				break;
			for(int i=0;i<inp.size();i++)
				arr[(int)inp[i] - 97] = 1;
		}
		for(int i=0;i<26;i++)
			if(arr[i])
				count++;
		sum+=count;
		cout<<sum<<endl;		
	}
	*/
	string inp="f";
	int sum=0;
	while(true) {
		int arr[26] = {0};
		int people = 0, cnt = 0;
		while(getline(cin,inp)){
			people++;
			if(inp == "") 
				break;
			for(int i=0;i<inp.size();i++)
				arr[(int)inp[i] - 97]++;
		}
		people--;
		for(int i=0;i<26;i++) 
			if(arr[i] == people)
				cnt++;	
		sum+=cnt;
		cout<<people<<' '<<sum<<endl;		
	}
	//3394
	
	return 0;
}



