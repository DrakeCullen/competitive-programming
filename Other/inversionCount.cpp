#include <bits/stdc++.h>

using namespace std;
#define LSOne(S) ((S) & -(S))  
#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)
#define modulo(S, N) ((S) & (N-1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S-1)))
#define nearestPowerOfTwo(S) (1<<lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S+1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))
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
#define LLINF 4e18;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<pair<string,int>> vsi;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef map<int,bool> mpib;
typedef map<int,list<pii>> mpili;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef unordered_set<int> usi;
//typedef priority_queue<int> pqi;
//typedef priority_queue<int,vi,greater<int>> rpqi;
typedef stack<int> stki;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#include <bits/extc++.h>                         // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

ll inversions(vector<int>& v) {
    ost s; ll ans=0;
    REP(i,v.size()) s.insert(i+1);
    for(auto i : v) {
        ans += s.order_of_key(i);
        s.erase(i);
    }

    return ans;
}

ll getInvCount(vector<int>& v) {
    ll key,invcount=0;
    ost s;
    s.insert(v[0]);
    for (int i = 1; i < v.size(); i++) {
        s.insert(v[i]);
        key = s.order_of_key(v[i] + 1);
        invcount += s.size() - key;
    }
    return invcount;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int n;
  cin >> n;

  vector<int> v1(n);
  vector<int> v2(n);

  for(auto& i : v1) {
      cin >> i;
  }

  for(auto& i : v2) {
      cin >> i;
  }

  ll i1 = getInvCount(v1); 
  ll i2 = getInvCount(v2); 

  return 0;
} 