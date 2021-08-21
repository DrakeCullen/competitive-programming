#include <bits/stdc++.h>

using namespace std;
  
int main() 
{ 
    int n,b,h,w,p,a;
    while(cin>>n>>b>>h>>w){
		int cost=INT_MAX;
		bool isPos=false;
		
		for(int i=0;i<h;i++)
		{
			cin>>p;
			bool isRoom=false;
			for(int j=0;j<w;j++)
			{
				cin>>a;
				if(a >= n)
					isRoom=true;
			}
			
			if(isRoom)
			{
				if (p * n <= b && p*n < cost)
				{
					isPos = true;
					cost = p*n;
				}
			}
		}       
		
		if(isPos) cout<<cost<<endl;
		else cout<<"stay home"<<endl; 
	}                            
    return 0; 
} 
