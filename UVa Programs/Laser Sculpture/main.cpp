#include <bits/stdc++.h>

using namespace std;
  
int main() 
{ 
    int h,l,temp;
    while(1) {
		cin>>h;
		if(h==0) break;
		cin>>l;
		int count=0;
		while(l--) {
			cin>>temp;
			if(temp <= h && temp != 0) count++;
		}
		cout<<count;
	}                          
    return 0; 
} 

