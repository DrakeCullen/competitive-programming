#include <bits/stdc++.h>

using namespace std;

bool diff(string guess, vector<string> orig) {
	for(int i=0;i<orig.size();i++) {
		string word = orig[i];
		int cnt = 0;
		for(int j=0;j<word.size();j++) {
			if(word[i] != guess[i]) cnt++;
			if(cnt > 1) return false;
		}
	}
	return true;
}

int main() {
	int t, n, m, c;
	string temp, guess;
	cin>>t;
	while(t--) {
		bool isValid = false;
		cin>>n>>m;
		c = n;
		vector<string> perm(m, ""), orig;
		while(n--) {
			cin>>temp;
			orig.push_back(temp);
			for(int i=0;i<temp.size();i++)
				perm[i] += temp[i];	
		}
		for(int i=0;i<c;i++) {
			guess = "";
			for(int j=0;j<perm.size();j++) {
				guess += perm[j][i];
			}
			if(diff(guess, orig)) {
				isValid = true;
				break;
			}
		}
		if(isValid) cout<<guess<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}



