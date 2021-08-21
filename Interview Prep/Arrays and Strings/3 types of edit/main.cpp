#include <bits/stdc++.h>

using namespace std;

int main()
{
	string string1,string2;
	int hash1[26]={0};
	int hash2[26]={0};
	int count=0;
	cin>>string1>>string2;
	
	for(int i=0;i<string1.size();i++)
		hash1[(int)string1[i]-97]++;
	for(int i=0;i<string2.size();i++)
		hash2[(int)string2[i]-97]++;
	for(int i=0;i<26;i++)
	{
		if(hash1[i] != hash2[i])
			count++;	
	}
	if(string1.size() == string2.size())
		count/=2;
	if(count<2) cout<<"true";
	else cout<<"false";
	
	
		
	return 0;
}
