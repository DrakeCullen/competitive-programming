#include <bits/stdc++.h>

using namespace std;

int main()
{
	set<int> unique;
	set<int>::const_iterator it;
	string input,res;
	int i=0;
	cin>>input;
	while(i<input.size())
	{
		int count=0;
		char temp=input[i];
		while(input[i] == temp)
		{
			count++;
			i++;
		}
		res+=temp;
		res+=to_string(count);
		unique.insert(count);
	}
	
	it = unique.begin();
	if(unique.size() == 1 && *it == 1)
		cout<<input;
	else cout<<res;
	return 0;
}
