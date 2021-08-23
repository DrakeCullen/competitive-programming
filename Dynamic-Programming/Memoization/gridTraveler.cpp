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


ll gridTraveler(ll m, ll n, unordered_map<string, ll> &memo) {
	if (memo.count(to_string(m) + ',' + to_string(n))) return memo[to_string(m) + ',' + to_string(n)];
	if (memo.count(to_string(n) + ',' + to_string(m))) return memo[to_string(n) + ',' + to_string(m)];
	if (m == 1 && n == 1) return 1;
	if (m == 0 || n == 0) return 0;
	memo[to_string(n) + ',' + to_string(m)] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
	return memo[to_string(n) + ',' + to_string(m)];
}

int main() {
	unordered_map<string, ll> memo;
	cout<<gridTraveler(1, 1, memo)<<endl;
	cout<<gridTraveler(2, 3, memo)<<endl;
	cout<<gridTraveler(3, 2, memo)<<endl;
	cout<<gridTraveler(3, 3, memo)<<endl;
	cout<<gridTraveler(18, 18, memo)<<endl;
}


