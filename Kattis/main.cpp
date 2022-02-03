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
typedef vector<pair<string,int>> vsi;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef unordered_map<int,int> umpii;
typedef map<int,bool> mpib;
typedef map<int,list<int>> mpili;
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

int main() {
  ll n,l,p,tot,offset=1,temp,large=0,close,closeIndex,fullest=0;
  cin>>n>>l>>p;
  ll doors[n], pass[n];
  REP(i, n) {
    doors[i] = (l/2)*offset;
    offset += 2;
    pass[i] = 0;
  }
  tot = n*l;
  REP(i, p) {
    cin>>temp;
    close = INF;
    temp = tot - temp;
    REP(j, n) {
      if (abs(temp - doors[j]) < close) {
        close = abs(temp - doors[j]);
        closeIndex = j;
      }
    }
    pass[closeIndex]++;
    large = max(close, large);
  }
  REP(i, n) fullest = max(fullest, pass[i]);
  cout<<large<<endl<<fullest;

  return 0;
}