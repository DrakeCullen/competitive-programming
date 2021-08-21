#include <bits/stdc++.h>

using namespace std;

bool isNum(char inp){
	return inp != 'C' && inp != 'H' && inp != 'O'&& inp != 'N';
}

double getVal(char val) {
	if(val == 'C') return 12.01;
	else if(val == 'H') return 1.008;
	else if(val == 'O') return 16.00;
	return 14.01;
}

int main() {
  int t;
  string inp, temp;
  cin>>t;
  while(t--) {
	  double s = 0;
	  int i = 0;
	  cin>>inp;
	  while(i + 1 < inp.size()) {
		  if(isNum(inp[i+1])) {
			  temp = inp[i+1];
			  int let = i;
			  while(i < inp.size() && isNum(inp[i+1])) {
					  i++;
					  temp += inp[i+1];
			  }
			  s += getVal(inp[let]) * stoi(temp);
			  if(i < inp.size()) i++;
		  } else {
			  s += getVal(inp[i]);
			  i++; 
		  }
	  }
	  if(i < inp.size()) s += getVal(inp[i]);
	  cout<<fixed<<showpoint<<setprecision(3)<<s<<endl;
  }
  return 0;
}

