#include <bits/stdc++.h>

using namespace std;

const string a[] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};
 
int main(){
	int t, i, k;
    cin>>t;
 
    while(t--){
        int amp, freq;
       cin>>amp>>freq;
 
        while(freq--){
            for(i = 1; i < amp; ++i)
               cout<<a[i]<<endl;
 
            for(k = i; k; --k)
                cout<<a[k]<<endl;
 
            if(freq || t)
               cout<<endl;
        }
    }
    return 0;
}
