#include <bits/stdc++.h>

using namespace std;

int wordCount(string s)
{
	stringstream str(s);
	string temp;
	int count = 0;
	
	while(str >> temp)
		count++;
	return count;	
}

void printFrequency(string s)
{
	map<string,int> freq;
	stringstream str(s);
	string temp;
	
	while(str >> temp)
		freq[temp]++;
		
	
	map<string,int>::iterator it;
	for(it=freq.begin(); it != freq.end(); it++)
			cout<<it->first<<"->"<<it->second<<endl;
}

int main()
{
	string input;
	getline(cin,input);
	
	//cout<<wordCount(input);
	printFrequency(input);
	return 0;
}
