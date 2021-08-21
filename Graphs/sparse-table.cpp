/**
 * Implementation of a sparse table which is a data structure that can very quickly query a range on
 * a static array in O(1) for overlap friendly functions (idempotent functions) like min, max and
 * gcd using O(n*logn) memory

 */


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

class MinSparseTable {
	private:
		// The number of elements in the original input array.
		int n;

		// The maximum power of 2 needed. This value is floor(log2(n))
		int P;

		// Fast log base 2 logarithm lookup table, 1 <= i <= n
		vi log2;

		// The sparse table values.
		vvi dp;

		// Index Table (IT) associated with the values in the sparse table. This table
		// is only useful when we want to query the index of the min (or max) element
		// in the range [l, r] rather than the value itself. The index table doesn’t
		// make sense for most other range query types like gcd or sum.
		vvi it;
		
	public:
	
		MinSparseTable(vi values) {
			n = values.size();
			P = (std::log2(n) / std::log2(2));
			dp.resize(P+1, vi(n));
			it.resize(P+1, vi(n));

			REP(i, n) {
			  dp[0][i] = values[i];
			  it[0][i] = i;
			}

			log2.resize(n+1);
			for (int i = 2; i <= n; i++) 
			  log2[i] = log2[i / 2] + 1;
			

			// Build sparse table combining the values of the previous intervals.
			for (int p = 1; p <= P; p++) {
			  for (int i = 0; i + (1 << p) <= n; i++) {
				int leftInterval = dp[p - 1][i];
				int rightInterval = dp[p - 1][i + (1 << (p - 1))];
				dp[p][i] = min(leftInterval, rightInterval);

				// Propagate the index of the best value
				if (leftInterval <= rightInterval)
				  it[p][i] = it[p - 1][i];
				else 
				  it[p][i] = it[p - 1][i + (1 << (p - 1))];
			  }
			}
		}
		
		// Do a min query on the interval [l, r] in O(1).
		//
		// We can get O(1) query by finding the smallest power of 2 that fits within
		// the interval length which we'll call k. Then we can query the intervals
		// [l, l+k] and [r-k+1, r] (which likely overlap) and apply the function
		// again. Some functions (like min and max) don't care about overlapping
		// intervals so this trick works, but for a function like sum this would
		// return the wrong result since it is not an idempotent binary function
		// (aka an overlap friendly function).
		long queryMin(int l, int r) {
			int length = r - l + 1;
			int p = log2[length];
			int k = 1 << p; // 2 to the power of p
			return min(dp[p][l], dp[p][r - k + 1]);
		}

		// Returns the index of the minimum element in the range [l, r].
		int queryMinIndex(int l, int r) {
			int length = r - l + 1;
			int p = log2[length];
			int k = 1 << p; // 2 to the power of p
			long leftInterval = dp[p][l];
			long rightInterval = dp[p][r - k + 1];
			if (leftInterval <= rightInterval)
			  return it[p][l];
			return it[p][r - k + 1];
		}
};

int main() {
    // index values: 0, 1,  2, 3, 4,  5, 6
    vi values = {1, 2, -3, 2, 4, -1, 5};
    MinSparseTable sparseTable(values);

    cout<<sparseTable.queryMin(1, 5)<<endl; // prints -3
    cout<<sparseTable.queryMinIndex(1, 5)<<endl; // prints 2

    cout<<sparseTable.queryMin(3, 3)<<endl; // prints 2
    cout<<sparseTable.queryMinIndex(3, 3)<<endl; // prints 3

    cout<<sparseTable.queryMin(3, 6)<<endl; // prints -1
    cout<<sparseTable.queryMinIndex(3, 6)<<endl; // prints 5
 }
