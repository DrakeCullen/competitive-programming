#include <bits/stdc++.h>

using namespace std;

int main() {
	/*int n, x, y, ca = 1, dig;
	string inp, temp;
	char c;
	cin>>n;
	cin.ignore();
	while(n--) {
		vector<string> top, bot;
		string cards;
		y = 0;
		for(int i=0;i<27;i++) {
			cin>>temp;
			bot.push_back(temp);
		}
		for(int i=0;i<25;i++) {
			cin>>temp;
			top.push_back(temp);
		}
		for(auto p:top) cout<<p[0]<<p[1]<<' ';
		cout<<endl;
		for(auto p:bot) cout<<p[0]<<p[1]<<' ';
		cout<<endl;
		for(int i=0;i<3;i++) {
			if(isdigit(top[0][0])) x = (int)top[0][0] - 48;
			else x = 10;
			y += x;
			top.erase(top.begin());
			if(10 - x > 0) top.erase(top.begin(), top.begin() + (10 - x)); 
		}
		bot.insert(bot.end(), top.begin(), top.end());
		int pos= bot.size() - y;
		for(auto p:bot) cout<<p[0]<<p[1]<<' ';
		cout<<endl;
		cout<<y<<endl;
		cout<<"Case "<<ca++<<": "<<bot[pos][0]<<bot[pos][1]<<endl;
	}
	return 0;*/
	map<char,int> cards;

	cards['2'] = 2;
	cards['3'] = 3;
	cards['4'] = 4;
	cards['5'] = 5;
	cards['6'] = 6;
	cards['7'] = 7;
	cards['8'] = 8;
	cards['9'] = 9;
	cards['T'] = 10;
	cards['J'] = 10;
	cards['Q'] = 10;
	cards['K'] = 10;
	cards['A'] = 10;

	int cases,i,j,y,x,top,k;
	string buffer;
	deque<string> deck;
	vector<string> hand;

	//vector<string>::reverse_iterator rit;
	//vector<string>::iterator it;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		for(j=0;j<52;j++){
			cin>>buffer;
			deck.push_back(buffer);
		}
		y = 0;
		
		hand.insert(hand.begin(),deck.begin()+27,deck.end());
		
		deck.erase(deck.begin()+27,deck.end());
		for(j=0;j<3;j++){
			
			x = cards[deck.back()[0]];
			y += x;
			
			deck.pop_back();
			deck.erase(deck.begin()+deck.size()-(10-x),deck.end());
		}
		deck.insert(deck.end(),hand.begin(),hand.end());
		printf("Case %d: %s\n",i,deck[y-1].c_str());
		deck.clear();
		hand.clear();
	}
	return 0;

}




