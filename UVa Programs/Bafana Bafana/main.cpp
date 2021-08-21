#include <bits/stdc++.h>

using namespace std;


int main() {
  int t,n,k,p,c=0;
  cin>>t;
  while(t--) {
	  cin>>n>>k>>p;
	  while(p--) {
		  k++;
		  if(k > n) k = 1;
	  }
	  cout<<"Case "<<++c<<": "<<k<<endl;
  }
  return 0;
}

