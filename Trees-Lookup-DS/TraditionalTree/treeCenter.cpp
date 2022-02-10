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
public:
	void addEdge(int v1, int v2, int w=0) { adj[v1].push_back(MP(v2, w)); }
	
	vi treeCenters(int n) {
		int degree[n];
		vi leaves;
		REP(i, n) {
			degree[i] = adj[i].size();
			if (degree[i] == 0 || degree[i] == 1) {
				leaves.PB(i);
				degree[i] = 0;
			}
		}
		int count = leaves.size();
		while(count < n) {
			vi newLeaves;
			for (auto node:leaves) {
				for (auto neighbor:adj[node]) {
					degree[neighbor.F] -= 1;
					if (degree[neighbor.F] == 1)
						newLeaves.PB(neighbor.F);
				}
				degree[node] = 0;
			}
			count += newLeaves.size();
			leaves = newLeaves;
		}
		return leaves;
	}
	
};

int main() {
    Graph g;
    vi shortestPath;
    g.addEdge(2, 3);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(6, 9);
    g.addEdge(3, 1);
    g.addEdge(1, 0);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 8);

    g.addEdge(3, 2);
    g.addEdge(6, 3);
    g.addEdge(7, 3);
    g.addEdge(9, 6);
    g.addEdge(1, 3);
    g.addEdge(0, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 4);
    g.addEdge(8, 4);
	
	vi res = g.treeCenters(10);
	for (auto center:res) cout<<center<<' ';
    
}
