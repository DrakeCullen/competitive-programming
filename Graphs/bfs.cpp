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

class Graph {
private:
	usi visited;
	mpili adj;
	
	void bfs(int s, int prev[]) {
		qi q;
		visited.insert(s);
		q.push(s);
		while(!q.empty()) {
			int v = q.front();
			visited.insert(v);
			q.pop();
			//cout<<v<<' ';
			
			for (auto vertice:adj[v]) 
				if (!visited.count(vertice.F)) {
					visited.insert(vertice.F);
					q.push(vertice.F);
					prev[vertice.F] = v;
				}
		}
	}
	
	vi reconstructPath(int s, int e, int prev[]) {
		vi path;
		for (auto at = e; at != -1; at = prev[at])
			path.PB(at);
		reverse(path.begin(), path.end());
		
		if (path[0] == s)
			return path;
		return {};
	}
	
public:
	void addEdge(int v1, int v2, int w=0) { adj[v1].push_back(MP(v2, w)); }
	
	vi findFhortestPath(int s, int e, int n) {
		int prev[n];
		REP(i, n) prev[i] = -1;
		
		
		bfs(s, prev);
		return reconstructPath(s, e, prev);
	}
};

int main() {
    Graph g;
    vi shortestPath;
    g.addEdge(0, 9);
    g.addEdge(0, 7);
    g.addEdge(0, 11);
    g.addEdge(9, 8);
    g.addEdge(9, 10);
    g.addEdge(11, 7);
    
    g.addEdge(7, 3);
    g.addEdge(7, 6);
    g.addEdge(10, 1);
    g.addEdge(8, 1);
    g.addEdge(8, 12);
    g.addEdge(6, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.addEdge(12, 2);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    shortestPath = g.findFhortestPath(0, 12, 13);
    for (int vertice:shortestPath) cout<<vertice<<' ';
}
