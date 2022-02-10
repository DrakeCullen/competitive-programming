#include <bits/stdc++.h>

using namespace std;

void setHashValues(vector<int> &hashes,string sequence)
{
	for(unsigned int i=0; i<sequence.length();i++)
	{
		if(sequence[i] == 'A')
			hashes[0]++;
		else if(sequence[i] == 'C')
			hashes[1]++;
		else if(sequence[i] == 'G')
			hashes[2]++;
		else if(sequence[i] == 'T')
			hashes[3]++;
	}
}

int main()
{
	vector<string> vectorOfSequences={"AAA","TAA","TAT","ATA"};
	vector<int> temp={0,0,0,0};
	vector<vector<int>> hashTables;
	set<vector<int>> uniqueHashTables;

	for(unsigned int i=0;i<vectorOfSequences.size();i++)
	{
		hashTables.push_back(temp);
		setHashValues(hashTables[i],vectorOfSequences[i]);
	}

	
	for(unsigned int i=0;i<hashTables.size();i++)
		uniqueHashTables.insert(hashTables[i]);
		

	cout<<"There are a total of "<<uniqueHashTables.size()<<" combinations!";
	
}
