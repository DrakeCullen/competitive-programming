// ONLY works on DAGS

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

class Graph {
public:
	usi v;
	mpili adj;
	
	void addEdge(int v1, int v2, int w=0) { adj[v1].push_back(MP(v2, w));}
	
	vi topologicalSort(int n) {
		vi ordering(n,0);
		int i = n - 1;
		for (int at = 0; at < n; at++) {
			if (!v.count(at))
				i = dfs(i, at, ordering);
		}
		return ordering;
	}
	int dfs(int i, int at, vi &ordering) {
		v.insert(at);
		
		for (auto vertice:adj[at])
			if (!v.count(vertice.F))
				i = dfs(i, vertice.F, ordering);
		ordering[i] = at;
		return i - 1;
	}
	
	vi dagShortestPath(int start, int n) {
		vi topSort = topologicalSort(n);
		vi dist(n, INT_MAX);
		dist[start] = 0;
		
		REP(i, n) {
			int nodeIndex = topSort[i];
				for (auto vertice:adj[nodeIndex]) {
					int newDist = dist[nodeIndex] + vertice.S;
					if (dist[vertice.F] == INT_MAX) dist[vertice.F] = newDist;
					else dist[vertice.F] = min(dist[vertice.F], newDist);
				}
		}
		return dist;
	}
};

int main() {
	Graph g;
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 6, 11);
    g.addEdge(1, 5, 11);
    g.addEdge(3, 4, -4);
    g.addEdge(3, 5, 5);
    g.addEdge(3, 6, 2);
    g.addEdge(4, 7, 9);
    g.addEdge(5, 7, 1);
    g.addEdge(6, 7, 2);

 
    vi res = g.dagShortestPath(0, 8);
    for (auto v:res) cout<<v<<' ';
    
}


