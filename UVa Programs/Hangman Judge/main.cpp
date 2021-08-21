#include <bits/stdc++.h>

using namespace std;

bool complete(bool let[26], bool pick[26]) {
	for(int i=0;i<26;i++) 
		if(let[i] == 1 && pick[i] == 0) return false;
	return true;
}



int main() {
	int round=1;
	while(cin>>round){
		if(round==-1) break;
		string solution, guess;
		int stroke=0;
		bool let[26]={0}, pick[26]={0};
		cin>>solution>>guess;
		for(int i=0; i<solution.size(); i++)
			let[(int)solution[i] - 97] = 1;
		for(int i=0; i<guess.size(); i++) {
			int pos = (int)guess[i] - 97;
			if(pick[pos] == 0 && let[pos] == 0)
				stroke++;
			pick[pos] = 1;
			if(complete(let,pick)) break;
		}
		cout<<"Round "<<round++<<endl;
		if(stroke < 7 && !complete(let,pick)) cout<<"You chickened out."<<endl;
		else if(stroke >= 7) cout<<"You lose."<<endl;
		else cout<<"You win."<<endl;
	}

	return 0;
}

