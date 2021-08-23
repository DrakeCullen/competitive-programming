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

list<ll> howSum(ll n, vector<ll> &numbers) {
	vector<list<ll>> res(n+1);
	res[0].PB(0);
	
	REP(i, n+1) {
		if (res[i].size() > 0)
			REP(j, numbers.size())
				if (i + numbers[j] <= n && (res[i].size() < res[i+numbers[j]].size() || res[i+numbers[j]].size() == 0)) {
					res[i+numbers[j]] = res[i]; 
					res[i+numbers[j]].PB(numbers[j]); 
				} 
	}
	return res[n];
}

void printRes(ll n, vector<ll> &numbers) {
	list<ll> res = howSum(n, numbers);
	if (res.size() == 0) cout<<"[]";
	else 
		for (auto ele:res) if (ele != 0)cout<<ele<<' ';
	cout<<endl;
}

int main() {
	vector<ll> numbers1 = {5, 3, 4, 7};
	vector<ll> numbers2 = {2, 3, 5};
	vector<ll> numbers3 = {1, 4, 5};
	vector<ll> numbers4 = {1, 2, 5, 25};

	printRes(7, numbers1);
	printRes(8, numbers2);
	printRes(8, numbers3);
	printRes(100, numbers4);
}








