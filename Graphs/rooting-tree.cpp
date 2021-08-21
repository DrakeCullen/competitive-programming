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

class TreeNode {
public:
	int id;
	TreeNode* parent;
	list<TreeNode*> children;
	TreeNode(int newId, TreeNode* newParent, list<TreeNode*> newChildren) {
		id = newId;
		parent = newParent;
		children = newChildren;
	}
};

class Graph {
public:
	mpili adj;
	
	void addEdge(int v1, int v2, int w=0) { adj[v1].PB(MP(v2, w)); }
};

TreeNode* buildTree(Graph g, TreeNode* node, TreeNode* parent) {
	for (auto childId:g.adj[node->id]) {
		if (parent != nullptr && childId.F != parent->id)
			continue;
		TreeNode* child = new TreeNode(childId.F, node, {});
		node->children.PB(child);
		buildTree(g, child, node);
	}
	return node;
}

TreeNode* rootTree(Graph g, int rootId = 0) {
	TreeNode* root = new TreeNode(rootId, nullptr , {});
	return buildTree(g, root, nullptr);
}

int main() {
	Graph g;
	g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 3);
    g.addEdge(2, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);


	
	TreeNode* root = rootTree(g, 6);
	for (auto v:root->children)
		cout<<v->id<<' ';
}
