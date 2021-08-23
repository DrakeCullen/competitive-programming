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

ll gridTraveler(ll m, ll n) {
	ll table[m+1][n+1];
	REP(i, m + 1) REP(j, n + 1) table[i][j] = 0;
	table[1][1] = 1;
	
	REP(i, m + 1) {
		REP(j, n + 1) {
			if (i+1 <= m) table[i+1][j] += table[i][j];
			if (j+1 <= n) table[i][j+1] += table[i][j];
		}
	}
	return table[m][n];
}

int main() {
	cout<<gridTraveler(1, 1)<<endl;
	cout<<gridTraveler(2, 3)<<endl;
	cout<<gridTraveler(3, 2)<<endl;
	cout<<gridTraveler(3, 3)<<endl;
	cout<<gridTraveler(18, 18)<<endl;
}







