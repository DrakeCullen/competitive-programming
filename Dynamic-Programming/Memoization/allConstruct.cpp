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


vvs allConstruct(string target, vector<string> &wordBank, unordered_map<string, vvs> &memo) {
	if (memo.count(target)) return memo[target];
	if (target == "") { vector<vector<string>> temp(1, vector<string>(1, "")); return temp; }
	
	vvs result;
	
	REP(i, wordBank.size()) {
		if (target.find(wordBank[i]) == 0) {
			string suffix = target.substr(wordBank[i].length());
			vvs suffixWays = allConstruct(suffix, wordBank, memo);
			REP(j, suffixWays.size()) {
				suffixWays[j].insert(suffixWays[j].begin(), wordBank[i]);
				result.PB(suffixWays[j]);
			}
			
		}
	}
	
	memo[target] = result;
	return result;
}

void printResult(string target, vector<string> &wordBank, unordered_map<string, vvs> &memo) {
	vvs res = allConstruct(target, wordBank, memo);
	REP(i, res.size()) {
		REP(j, res[i].size())
			cout<<res[i][j]<<", ";
		cout<<endl;
	}
}


int main() {
	vector<string> arr0 = {"purp", "p", "ur", "le", "purpl"};
	vector<string> arr1 = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
	vector<string> arr2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	vector<string> arr3 = {"a", "aa", "aaa", "aaaa", "aaaaaa"};
	
	unordered_map<string, vvs> memo;
	printResult("purple", arr0, memo);
	memo.clear();
	printResult("abcdef", arr1, memo);
	memo.clear();
	printResult("skateboard", arr2, memo);
	memo.clear();
	printResult("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz", arr3, memo);
}






