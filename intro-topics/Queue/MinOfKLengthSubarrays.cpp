#include <bits/stdc++.h>

using namespace std;

vector<int>solve(int mas[],int n,int k){
    deque<int>deq;
    vector<int>ans;
    for(int i=1; i<=n; i++){
        while(!deq.empty()&&mas[deq.back()]>=mas[i])
            deq.pop_back();
        
        if(!deq.empty()&&deq.front()==i-k)
            deq.pop_front();
        
        deq.push_back(i);
        if(i>=k)
            ans.push_back(mas[deq.front()]);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    int mas[n+1];
    for(int i=1; i<=n; i++)
        cin>>mas[i];
    
    vector<int>ans=solve(mas,n,k);

    for(int i:ans)
        cout <<i<<' ';
}
