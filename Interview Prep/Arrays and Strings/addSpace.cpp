#include <bits/stdc++.h>

using namespace std;
 
int main(){
	string s1,s2="" ;
	getline(cin,s1);
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==' ')
			s2+="%20";
		else 
			s2+=s1[i];
	}
	cout<<s2;
	return 0;
}
