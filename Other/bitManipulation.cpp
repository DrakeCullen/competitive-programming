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

int cntSetBits(int n) {
    int cnt=0;
    while(n>0) {
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout<<cntSetBits(11);
     // Compute the biggest power of 2 that is a divisor of x. Example: f(12) = 4
    // 1 << __builtin_ctz(x)
    // Compute the smallest power of 2 that is not smaller than x. Example: f(12) = 16
    // 1 << (32 - __builtin_clz (x - 1)) 
  return 0;
}
