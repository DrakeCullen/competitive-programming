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


bool canConstruct(string target, vector<string> &wordBank, unordered_map<string, bool> &memo) {
	if (memo.count(target)) return memo[target];
	if (target == "") return true;
	
	REP(i, wordBank.size()) {
		if (target.find(wordBank[i]) == 0) {
			string suffix = target.substr(wordBank[i].length());
			if (canConstruct(suffix, wordBank, memo)) {
				memo[target] = true;
				return true;
			} 
		}
	}
	memo[target] = false;
	return false;
}



int main() {
	vector<string> arr1 = {"ab", "abc", "cd", "def", "abcd"};
	vector<string> arr2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	vector<string> arr3 = {"a", "p", "ent", "enter", "ot", "o", "t"};
	vector<string> arr4 = {"e", "ee", "eee", "eeee", "eeeeee"};
	unordered_map<string, bool> memo;
	cout<<canConstruct("abcdef", arr1, memo)<<endl;
	memo.clear();
	cout<<canConstruct("skateboard", arr2, memo)<<endl;
	memo.clear();
	cout<<canConstruct("enterapotentpot", arr3, memo)<<endl;
	memo.clear();
	cout<<canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", arr4, memo)<<endl;
}





