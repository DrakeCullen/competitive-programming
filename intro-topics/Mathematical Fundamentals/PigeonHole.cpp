/*
 * Given an integer m, find a number consisting only of digits 0 and 1
 * which is divisible by m. 
 */
 
#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100005;
int fr[NMAX];

void findNumber(int n) {
    int curRem = 0;
    for(int i = 0; i < n; i++) {
        curRem = (curRem * 10 + 1) % n;
        if(curRem == 0) {
            for(int j = 0; j <= i; j++)
                cout << 1;
            return;
        }
        if(fr[curRem] != 0) {
            for(int j = 0; j < i - fr[curRem]; j++)
                cout << 1;
            for(int j = 0; j < fr[curRem]; j++)
                cout << 0;
            return;
        }
        fr[curRem] = i;
    }
}

int main()
{
    int n;
    cin >> n;
    findNumber(n);
    return 0;
}
