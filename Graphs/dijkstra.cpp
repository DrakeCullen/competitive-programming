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

template <class T1, class T2,
          class Comparator = greater<T2>,
          class Hash = hash<T1> >
  
class indexed_priority_queue {
  
    // Storing indices of values using key
    unordered_map<T1, long long int, Hash> m;
  
    // Container
    vector<pair<T1, T2> > v;
  
    // Size
    long long numberOfElement;
  
    // Creating a instance of Comparator class
    Comparator comp;
  
    // Max Capacity
    long long capacity = LLONG_MAX;
  
    // Obtaing the index value from hash map
    long long int getValueIndex(T1 key)
    {
        if (m[key] == 0) {
            cout << "No Such Key Exist";
            return -1;
        }
        return v[m[key] - 1];
    }
  
    // heapify the container
    void heapify(vector<pair<T1, T2> >& v,
                 long long int heap_size,
                 long long index)
    {
        long long leftChild = 2 * index + 1,
                  rightChild = 2 * index + 2,
                  suitableNode = index;
  
        if (leftChild < heap_size
            && comp(v[suitableNode].second,
                    v[leftChild].second)) {
            suitableNode = leftChild;
        }
  
        if (rightChild < heap_size
            && comp(v[suitableNode].second,
                    v[rightChild].second)) {
            suitableNode = rightChild;
        }
  
        if (suitableNode != index) {
  
            // swap the value
            pair<T1, T2> temp = v[index];
            v[index] = v[suitableNode];
            v[suitableNode] = temp;
  
            // updating the map
            m[v[index].first] = index + 1;
            m[v[suitableNode].first]
                = suitableNode + 1;
  
            // heapify other affected nodes
            heapify(v, numberOfElement,
                    suitableNode);
        }
    }
  
public:
    indexed_priority_queue()
    {
        numberOfElement = 0;
        m.clear();
        v.clear();
    }
  
    void push(T1 key, T2 value)
    {
        if (numberOfElement == capacity) {
            cout << "Overflow";
            return;
        }
        if (m[key] != 0) {
            cout << "Element Already Exists";
            return;
        }
  
        // Adding element
        v.push_back(make_pair(key, value));
        numberOfElement++;
        m[key] = numberOfElement;
  
        long long index = numberOfElement - 1;
  
        // Comparing to parent node
        while (index != 0
               && comp(v[(index - 1) / 2].second,
                       v[index].second)) {
  
            // swap the value
            pair<T1, T2> temp = v[index];
            v[index] = v[(index - 1) / 2];
            v[(index - 1) / 2] = temp;
  
            // updating the map
            m[v[index].first] = index + 1;
            m[v[(index - 1) / 2].first]
                = (index - 1) / 2 + 1;
  
            // updating index in map
            index = (index - 1) / 2;
        }
    }
  
    void pop()
    {
        if (numberOfElement == 0) {
            cout << "UnderFlow";
            return;
        }
  
        // Removing element
        v.erase(v.begin());
        numberOfElement--;
        heapify(v, numberOfElement, 0);
    }
  
    pair<T1, T2> top() { return v[0]; }
  
    long long int size() { return numberOfElement; }
  
    bool empty() { return numberOfElement == 0; }
  
    void changeAtKey(T1 key, T2 value)
    {
        if (m[key] == 0) {
            cout << "No Such Key Exist";
            return;
        }
        long long index = m[key] - 1;
        v[index].second = value;
  
        // Comparing to child nodes
        heapify(v, numberOfElement, index);
  
        // Comparing to Parent Node
        while (index != 0
               && comp(v[(index - 1) / 2].second,
                       v[index].second)) {
  
            // swap the value
            pair<T1, T2> temp = v[index];
            v[index] = v[(index - 1) / 2];
            v[(index - 1) / 2] = temp;
  
            // updating the map
            m[v[index].first] = index + 1;
            m[v[(index - 1) / 2].first]
                = (index - 1) / 2 + 1;
  
            // updating index in map
            index = (index - 1) / 2;
        }
    }
    
    int contains(T1 key)
    {
        if (m[key] == 0)
            return 0;
        return 1;
    }
};
  
void display(indexed_priority_queue<int, int> IPQ)
{
    indexed_priority_queue<int, int> temp = IPQ;
    while (!IPQ.empty()) {
        pair<int, int> tmp;
        tmp = IPQ.top();
        IPQ.pop();
        cout << "( " << tmp.first << ", "
             << tmp.second << " ) ";
    }
    cout << '\n';
}

class Graph {
private:
	usi vis;
	mpili adj;
	
public:
	void addEdge(int v1, int v2, int w=0) { adj[v1].push_back(MP(v2, w)); }
	
	vi dijkstra(int n, int s) {
		vi dist(n, INT_MAX);
		dist[s] = 0;
		indexed_priority_queue<int, int> ipq;
		
		ipq.push(s, 0);
		while (ipq.size() != 0) {
			int index = ipq.top().F;
			int minValue = ipq.top().S;
			ipq.pop();
			vis.insert(index);
			if (dist[index] < minValue) continue;
			for (auto edge:adj[index]) {
				if (vis.count(edge.F)) continue;
				int newDist = dist[index] + edge.S;
				if (newDist < dist[edge.F]) {
					dist[edge.F] = newDist;
					if (!ipq.contains(edge.F))
						ipq.push(edge.F, newDist);
					else
						ipq.changeAtKey(edge.F, newDist);
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
