#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100001;

int a[NMAX], n;
bool freq[NMAX];

int longestConsecNumsSubarray() {
    int ans = 0;
    for(int Left = 1; Left <= n; Left++) {
        for(int i = 1; i <= n; i++)
            freq[i] = false;
        int Min = a[Left], Max = a[Left];
        for(int Right = Left; Right <= n; Right++) {
            if(freq[a[Right]] == true)
                break;
            freq[a[Right]] = true;
            Min = min(Min, a[Right]);
            Max = max(Max, a[Right]);
            if(Right - Left == Max - Min)
                ans = max(ans, Right - Left + 1);
        }
    }
    return ans;
}

int main() 
{ 
    cin>>n;
    for(int i = 1; i <= n; i++)
		cin>>a[i];
	cout<<longestConsecNumsSubarray();	
    return 0; 
} 


