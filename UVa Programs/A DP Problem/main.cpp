#include <bits/stdc++.h>

using namespace std;

char sym = '+';

void findStop(string &s, int &stop, string &dig) {
	if(s[stop - 1] == '+') sym = '+';
	if(s[stop- 1] == '-') sym = '-';
	while(s[stop] != '+' && s[stop] != '='  && s[stop] != '-' && stop < s.length()) dig += s[stop++];
}

int findX(string s) {
	if(s[s.length() - 1] != 'x') return 0;
	if(s.length() == 1) return 1;
	return s.length();
}

int main() {
	int n, stop;
	double left, leftX, right, rightX;
	string inp, temp;
	cin>>n;
	while(n--) {
		sym = '+';
		stop = 0;
		left=leftX=right=rightX=0;
		cin>>inp;
		while(stop < inp.size()) {
			temp="";
			findStop(inp, stop, temp); stop++;
			//cout<<temp<<' '<<sym<<' '<<endl;
			if(temp[0] != '0'){
				if(findX(temp) == 0) {
					if(sym == '+') left += stoi(temp);
					else left += stoi(temp) * - 1;
				}
				else if(findX(temp) == 1) {
					if(sym == '+') leftX += 1;
					else leftX -= 1;
				}
				else {
					if(sym == '+') leftX += stoi(temp.substr(0,temp.size() - 1));
					else leftX += stoi(temp.substr(0,temp.size() - 1)) * -1;
			}
			}
			if(inp[stop - 1] == '=') break;
		}
		stop++;
		while(stop < inp.size()) {
			temp="";
			findStop(inp, stop, temp); stop++;
			//cout<<temp<<' '<<sym<<' '<<endl;
			if(temp[0] != 0){
			if(findX(temp) == 0) {
				if(sym == '+') right += stoi(temp);
				else right += stoi(temp) * - 1;
			}
			else if(findX(temp) == 1) {
				if(sym == '+') rightX += 1;
				else rightX -= 1;
			}
			else {
				if(sym == '+') rightX += stoi(temp.substr(0,temp.size() - 1));
				else rightX += stoi(temp.substr(0,temp.size() - 1)) * -1;
			}
		}
			if(inp[stop - 1] == '=') break;
		}
		left -= right;
		rightX -= leftX;
		cout<<"vals "<<left<<' '<<rightX;
		if(left == 0 && rightX == 0) cout<<"IDENTITY"<<endl;
		else if(left != 0 && rightX == 0) cout<<"IMPOSSIBLE"<<endl;
		else cout<<floor(left/rightX)<<endl;
	}
	return 0;
}


