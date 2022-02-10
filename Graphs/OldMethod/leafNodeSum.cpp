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
typedef unordered_set<bool> usb;
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
	mpili adj;
	
	int leafSum(int v) {  
		if (adj[v].size() == 0) return v;
		int total = 0;
	
		
		for (auto vertice:adj[v]) 
			total += leafSum(vertice.F);
		
		return total;
	}
	
	void addEdge(int v1, int v2, int w=0) { adj[v1].PB(MP(v2, w)); }
};

int main() {
	Graph g;
	g.addEdge(5, 4);
    g.addEdge(5, 3);
    g.addEdge(4, 1);
    g.addEdge(4, -6);
    g.addEdge(1, 2);
    g.addEdge(1, 9);
    g.addEdge(3, 0);
    g.addEdge(3, 7);
    g.addEdge(3, -4);
    g.addEdge(7, 8);
 

    cout<<g.leafSum(5);
}
