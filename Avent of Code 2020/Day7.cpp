#include <bits/stdc++.h>

using namespace std;

int findSpaces(string word, int max) {
	int space = 0, i = 0;
	while(space < max && space < word.size()) {
		if(word[i] == ' ') space++;
		if(space == 2) break;
		i++;
	}
	return i;
}


void extract(string line, vector<string> &start, vector<vector<string>> &map) {
	int space = 0, end;
	string temp;
	end = findSpaces(line, 2);
	temp = line.substr(0,end);
	start.push_back(temp);
	line = line.substr(end + 16, line.size());
	end = findSpaces(line, 2);
	temp = line.substr(0,end);
	map[start.size() - 1].push_back(temp);
	line = line.substr(end + 1, line.size());
	cout<<temp<<endl;
	while(end + 7 < line.size()) {
		end = findSpaces(line, 2);
		temp = line.substr(0,end);
		line = line.substr(end + 1);
		map[start.size() - 1].push_back(temp);
		cout<<temp<<endl;
		if(end + 7 < line.size()) {
			line = line.substr(end + 1, line.size());
			end = findSpaces(line, 3);
			line = line.substr(end + 1, line.size());
		}
	}
	
}

int main() {
	vector<string> start;
	vector<vector<string>> map(9);
	string line;
	for(int i=0;i<9;i++) {
		getline(cin, line);
		extract(line, start, map);
	}
	
	return 0;
}




