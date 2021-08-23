// Not working!

#include <bits/stdc++.h>

using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ll long long
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<pii> vii;
typedef vector<pair<string,int>> vsi;
typedef vector<vi> vvi;
typedef map<ll,ll> mpll;
typedef map<int,bool> mpib;
typedef map<int,list<pii>> mpili;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef unordered_set<int> usi;
typedef priority_queue<int> pqi;
typedef priority_queue<int,vi,greater<int>> rpqi;
typedef stack<int> stki;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

vector<list<string>> countConstruct(string target, vs &wordBank) {
	vector<vector<list<string>>> table(target.length() + 1, vector<list<string>>(0, list<string>(0)));;
	vector<list<string>> orig;
	list<string> emptyList;
	emptyList.PB("");
	orig.PB(emptyList);
	table[0] = orig;
	
	REP(i, target.length() + 1) 
		REP(j, wordBank.size()) 
			if (target.substr(i, wordBank[j].length()) == wordBank[j]) {
				vector<list<string>> newList = table[i];
				REP(k, newList.size())
					newList[k].PB(wordBank[j]);
				table[i + wordBank[j].length()] = newList;
			}
				
	return table[target.length()];
}

void printResult(string target, vs &wordBank) {
	vector<list<string>> res = countConstruct(target, wordBank);
	cout<<target<<':'<<endl;
	if (res.size() == 0) cout<<"[]";
	else
		for (auto list:res) {
			for (auto ele:list)cout<<ele<<' ';
			cout<<endl;
		}
	cout<<endl;
}

int main() {
	vector<string> numbers0 = {"purp", "p", "ur", "le", "purpl"};
	vector<string> numbers1 = {"ab", "abc", "cd", "def", "abcd"};
	vector<string> numbers2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"	};
	vector<string> numbers3 = {"a", "p", "ent", "enter", "ot", "o", "t"};
	vector<string> numbers4 = {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeee"};

	printResult("purple", numbers0);
	printResult("abcdef", numbers1);
	printResult("skateboard", numbers2);
	printResult("enterapotentpot", numbers3);
	printResult("eeeeeeeeeeeeeeeeeeeef", numbers4);
}











