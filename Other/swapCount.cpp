// Count number of swaps in bubblesort in O(nlog(n))
#include <bits/stdc++.h>

using namespace std;
#define LSOne(S) ((S) & -(S))  
#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)
#define modulo(S, N) ((S) & (N-1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S-1)))
#define nearestPowerOfTwo(S) (1<<lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S+1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))
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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<ll> vll;
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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


ll merge(vector<ll> &arr, vector<ll> &temp, int left, int mid, int right) {
    int i=left,j=mid,k=left; ll cnt=0;
    while(i<mid && j<=right) {
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else {
            temp[k++]=arr[j++];
            cnt+=(mid-i);
        }
    }
    while(i<mid) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];
    for(int it=left;it<=right;it++) arr[it]=temp[it];
    return cnt;
}

ll mergeSort(vector<ll> &arr, vector<ll> &temp, int left, int right) { 
    ll cnt=0;
    if (right > left) {
        int mid = (right+left)/2;
        cnt+=mergeSort(arr, temp, left, mid);
        cnt+=mergeSort(arr, temp, mid+1, right);
        cnt+=merge(arr, temp, left, mid+1, right);
    }
    return cnt;
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; scanf("%lld", &n); vector<ll> arr(n), temp(n); 
    REP(i,n) scanf("%lld", &arr[i]);
    printf("%lld",mergeSort(arr, temp, 0, arr.size()-1));
    return 0;
} 
