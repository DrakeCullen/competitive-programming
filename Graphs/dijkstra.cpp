// Doesn't work on negative values
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
	usi vis;
	mpili adj;
	
public:
	void addEdge(int v1, int v2, int w=0) { adj[v1].push_back(MP(v2, w)); }
	
	vi dijkstra(int n, int s) {
		vi dist(n, INT_MAX);
		dist[s] = 0;
		priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> ipq;
		
		ipq.push(MP(s, 0));
		while (ipq.size() != 0) {
			int index = ipq.top().F;
			int minValue = ipq.top().S;
			ipq.pop();
			for (auto edge:adj[index]) {
				int newDist = minValue + edge.S;
				if (newDist < dist[edge.F]) {
					dist[edge.F] = newDist;
					ipq.push(MP(edge.F, newDist));
				}
			}
		}
		return dist;
	}
	
};



int main()
{
	Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 20);
    g.addEdge(2, 1, 3);
    g.addEdge(2, 4, 12);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 1);
	vi res = g.dijkstra(6, 0);
	cout<<"distance from 0 to all the other nodes:"<<endl;
	for (auto r:res) cout<<r<<' ';
    return 0;
}
