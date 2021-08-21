#include <iostream>

using namespace std;

int main()
{
	bool isOdd=false, isPalindrome=true;
	int hash[26]={0};
	string input;
	getline(cin,input);
	for(int i=0;i<input.size();i++)
	{
		if(input[i] >= 'a' && input[i] <= 'z')
		{
			hash[(int)input[i]-97]++;
		}
	}
	
	
	
	for(int i=0;i<26;i++)
	{
		if(hash[i] % 2 == 1)
		{
			if(isOdd)
			{
				isPalindrome=false;
				break;
			}
			else
				isOdd=true;
				
		}
	}
	
	if(isPalindrome)
		cout<<"true";
	else
		cout<<"false";
}
