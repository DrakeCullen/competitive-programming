#include <bits/stdc++.h>

using namespace std;

void getFactors(int cubes, vector<long long> &v) {
	for(int i=1;i<=sqrt(cubes);i++) {
		if(cubes % i == 0){
			 v.push_back(i);
			if(pow(i,2) != cubes) v.push_back(cubes / i);
		}
	}
}

int main() {
  long long cubes,l,w,h,minimum = INT_MAX;
  vector<long long> factors;
  cin>>cubes;
  getFactors(cubes,factors);
  sort(factors.begin(),factors.end());
  for(int i=0;i<factors.size();i++) {
	  w = factors[i];
	  long long extra = cubes / factors[i];
	  for(int j=0;j<factors.size();j++) {
		  if(extra % factors[j] == 0) {
			  l = extra/factors[j];
			  h = factors[j];
			  if(l*w*h == cubes) minimum = min(minimum, 2*l*w + 2*l*h + 2 * w * h);
		  }
	  }
  }
  	  cout<<minimum<<endl;

  
  return 0;
}
