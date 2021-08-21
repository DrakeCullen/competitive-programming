#include <bits/stdc++.h>

using namespace std;

int clock(int one, int two) {
    one += 40;
    one -= two;
    return one % 40 * 9;
}

int counterClock(int one, int two) {
    two += 40;
    two -= one;
    return two % 40 * 9;
}

int main() {
  int one=-1, two=-1, three=-1, four=-1;
  while(cin>>one>>two>>three>>four) {
      if(one == 0 && two == 0 && three == 0 && four == 0) break;
      long long ans = 1080;
      
      ans += clock(one, two);
      ans += counterClock(two, three);
      ans += clock(three, four);
      
      cout<<ans<<endl;
  }
  
  return 0;
}
