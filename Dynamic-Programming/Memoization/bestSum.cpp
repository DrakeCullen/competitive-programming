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


vector<ll> bestSum(ll sum, vector<ll> &arr, unordered_map<ll, vector<ll>> &memo) {
	if (memo.count(sum)) return memo[sum];
	if (sum == 0) return vector<ll>(1, -1);
	if (sum < 0)  return vector<ll>(); 
	
	vector<ll> shortestCombination;
	
	for(int i = 0; i < arr.size(); i++){ 
		vector<ll> remainderResult = bestSum(sum - arr[i], arr, memo); 
		if (remainderResult.size() > 0)  {
			remainderResult.PB(arr[i]);
			if (shortestCombination.size() == 0 || remainderResult.size() < shortestCombination.size())
				shortestCombination = remainderResult;
		}
	}
	
	memo[sum] = shortestCombination;
	return shortestCombination;
}

void printValues(vector<ll> res) {
	for (auto p:res) if (p != -1)cout<<p<<' ';
	cout<<endl;
}

void findSum(int sum, vector<ll> arr, unordered_map<ll, vector<ll>> &memo) {
	vector<ll> res = bestSum(sum, arr, memo);
	if (res.size() == 0) cout<<"null"<<endl;
	else printValues(res);
}

int main() {
	vector<ll> arr1 = {5, 3, 4, 7};
	vector<ll> arr2 = {2, 3, 5};
	vector<ll> arr3 = {1, 4, 5};
	vector<ll> arr4 = {1, 2, 5, 25};
	unordered_map<ll, vector<ll>> memo;
	findSum(7, arr1, memo);
	memo.clear();
	findSum(8, arr2, memo);
	memo.clear();
	findSum(8, arr3, memo);
	memo.clear();
	findSum(100, arr4, memo);
}




