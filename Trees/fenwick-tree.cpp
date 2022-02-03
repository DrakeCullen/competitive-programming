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
typedef vector<ll> vl;
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

class FenwickTreeRangeQueryPointUpdate {
	private:
		// The size of the array holding the Fenwick tree values
		int N;

		// This array contains the Fenwick tree ranges
		vl tree;
		
		int lsb(int i) {
			// Isolates the lowest one bit value
			return i & -i;
		}

		// Computes the prefix sum from [1, i], O(log(n))
		long prefixSum(int i) {
			long sum = 0L;
			while (i != 0) {
				sum += tree[i];
				i &= ~lsb(i); // Equivalently, i -= lsb(i);
			}
			return sum;
		}
		
	public:
		// Create an empty Fenwick Tree with 'sz' parameter zero based.
		FenwickTreeRangeQueryPointUpdate(int sz) {
			N = sz + 1;
			tree.resize(N);
		}

		// Construct a Fenwick tree with an initial set of values.
		// The 'values' array MUST BE ONE BASED meaning values[0]
		// does not get used, O(n) construction.
		FenwickTreeRangeQueryPointUpdate(vl values) {
			N = values.size();
			values[0] = 0L;

			// Make a clone of the values array since we manipulate
			// the array in place destroying all its original content.
			tree = values;

			for (int i = 1; i < N; i++) {
				int parent = i + lsb(i);
				if (parent < N) tree[parent] += tree[i];
			}
		}		

		// Returns the sum of the interval [left, right], O(log(n))
		long sum(int left, int right) {
			return prefixSum(right) - prefixSum(left - 1);
		}

		// Get the value at index i
		long get(int i) {
			return sum(i, i);
		}

		// Add 'v' to index 'i', O(log(n))
		void add(int i, long v) {
			while (i < N) {
				tree[i] += v;
				i += lsb(i);
			}
		}

		// Set index i to be equal to v, O(log(n))
		void set(int i, long v) {
			add(i, v - sum(i, i));
		}
};

int main() {
	vl input = {0, 3, 4, -2, 7, 3, 11, 5, -8, -9, 2, 4, -8};
	FenwickTreeRangeQueryPointUpdate ft(input);
	cout<<ft.sum(1,3);
	return 0;
}
