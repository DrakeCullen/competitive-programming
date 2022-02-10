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

int dr[] = {-1, 1, 0, 0};
int dc[] = {0,0,1,-1};
int L,R,C,sl,sr,sc; 


class Graph {
public:
	map<tuple<int, int, int>, bool> visited;
	queue<tuple<int, int, int>> q;
	map<tuple<int,int,int>, list<tuple<int,int,int>>> adj;
	
	void addEdge(tuple<int,int,int> v1, tuple<int,int,int> v2) { adj[v1].push_back(v2); }
	
	void exploreNeighbors(vector<vector<vector<char>>> m, int l, int r, int c) {
		REP(i,4) {
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (rr<0 || cc <0 || rr>= R || cc >= C) continue;
			addEdge(make_tuple(l, r,c), make_tuple(l, rr,cc));
		}
	}
	
	void exploreLevels(vector<vector<vector<char>>> m, int l, int r, int c) {

		if (l - 1 >= 0)
			if (visited[make_tuple(l -1, r,c)] == 0) 
				addEdge(make_tuple(l, r,c), make_tuple(l - 1, r,c));
		
		if (l + 1 < L)
			if (visited[make_tuple(l + 1, r,c)] == 0) 
				addEdge(make_tuple(l, r,c), make_tuple(l + 1, r,c));

		//q.push(make_tuple(lChange, r,c));
		//visited[make_tuple(lChange, r,c)] = 1;
	
	}
	
	int solve(vector<vector<vector<char>>> m) {
		int count=0;
		q.push(make_tuple(sl, sr, sc));
		visited[make_tuple(sl, sr, sc)] = 1;
		while (q.size() > 0) {
			visited[q.front()] = 1;
			tuple<int,int,int> v = q.front();
			int l = get<0>(q.front());
			int r = get<1>(q.front());
			int c = get<2>(q.front());
			q.pop();
			
			for (auto vertice:adj[v]) {
				if (!visited[vertice] && m[l][r][c] != '#') {
					if (m[l][r][c] == 'E') return count;
					visited[vertice] = 1;
					q.push(vertice);
				}
			}
			count++;
		}
		return -1;
	}
	
	void readInput(vector<vector<vector<char>>> &dungeon) {
		REP(i, L) {
			REP(j, R) {
				REP(k, C) {
					cin>>dungeon[i][j][k];
					if (dungeon[i][j][k] == 'S') { sl=i;sr=j;sc=k;}
				}
			}
		}
	}
	
	void createDungeon(vector<vector<vector<char>>> &dungeon) {
		REP(i, L) 
			REP(j, R) 
				REP(k, C) {
					exploreNeighbors(dungeon, i, j, k);
					exploreLevels(dungeon, i, j, k);
				}
	}	
};

int main() {
	L=R=C=1;
	while(cin>>L>>R>>C) {
		if (L == 0 && R == 0 && C == 0) break;
		Graph g;
		vector<vector<vector<char>>> dungeon(L, vector<vector<char>>(R, vector<char>(C, '.')));
		g.readInput(dungeon);
		g.createDungeon(dungeon);
		int res = g.solve(dungeon);
		if (res == -1) cout<<"Trapped!"<<endl;
		else cout<<"Escaped in "<<res/L<<" minute(s)."<<endl;
	}
 
}
