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

bool canSum(ll n, vector<ll> &numbers) {
	bool res[n+1];
	REP(i, n+1) res[i] = 0;
	res[0]=1;
	
	REP(i, n+1) {
		if (res[i])
			REP(j, numbers.size()) 
				if (i + numbers[j] <= n) res[i+numbers[j]] = 1; 
	}
	return res[n];
}

int main() {
	vector<ll> numbers1 = {2, 3};
	vector<ll> numbers2 = {5, 3, 4, 7};
	vector<ll> numbers3 = {2, 4};
	vector<ll> numbers4 = {2, 3, 5};
	vector<ll> numbers5 = {7, 14};

	cout<<canSum(7, numbers1)<<endl;
	cout<<canSum(7, numbers2)<<endl;
	cout<<canSum(7, numbers3)<<endl;
	cout<<canSum(8, numbers4)<<endl;
	cout<<canSum(300, numbers5)<<endl;
}








