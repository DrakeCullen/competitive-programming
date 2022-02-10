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
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pair<string,int>> vsi;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
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

struct Edge {
  int vertex, weight;
};

bool operator <(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

class Graph {
private:
    usi vis;
    unordered_map<int,list<Edge>> adj;
    
public:
    void addEdge(int v1, int v2, int w=0) { 
    Edge e;
    e.vertex = v2;
    e.weight = w;
    adj[v1].push_back(e);
  }
  
    int mst(int size) {
      priority_queue<Edge> ipq;
      int currSize = 0, minDist = 0;

      ipq.push({0, 0});
      while (currSize < size) {
        Edge e = ipq.top();
        ipq.pop();
        if (vis.count(e.vertex)) continue;
        minDist += e.weight;
        currSize++;
        vis.insert(e.vertex);
        for (auto edge:adj[e.vertex]) 
            if (!vis.count(edge.vertex)) 
                ipq.push(edge); 
      }
      return minDist;
    }
    
};



int main()
{
  int t,m,c,tEdge,i,j,d,res;
  cin>>t;
  while(t--) {
    Graph g;
    cin>>m>>c;
    REP(k, (c*(c-1))/2) {
      cin>>i>>j>>d;
      g.addEdge(i,j,d);
      g.addEdge(j,i,d);
    }
   if (g.mst(c)+c > m) cout<<"no"<<endl;
   else cout<<"yes"<<endl;
  }
    
  return 0;
}