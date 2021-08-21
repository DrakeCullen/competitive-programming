#include <bits/stdc++.h>

using namespace std;


int main() {
  double n,temp;
  cin>>n;
  while(n--) {
	  cin>>temp;
	  cout<<(long)(-1+sqrt(1+8*temp))/2<<endl;
  }
  
  return 0;
}
