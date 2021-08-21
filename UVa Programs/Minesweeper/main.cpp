#include <bits/stdc++.h>

using namespace std;

void read(vector<vector<char>> &v) {
	for(int i=1;i<v.size()-1;i++)
        for(int j=1;j<v[i].size()-1;j++)
            cin>>v[i][j];
}

void print(vector<vector<int>> &v) {
	for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++) {
            if(v[i][j] == -1)cout<<'*';
            else cout<<v[i][j];
		}
        cout<<endl;
    }   
}

void bombCount(vector<vector<char>> mat, vector<vector<int>> &res, int i, int j) {
	int count=0;
	if(mat[i+1][j] == '*') count++;
	if(mat[i-1][j] == '*') count++;
	if(mat[i][j+1] == '*') count++;
	if(mat[i][j-1] == '*') count++;
	if(mat[i+1][j+1] == '*') count++;
	if(mat[i+1][j-1] == '*') count++;
	if(mat[i-1][j+1] == '*') count++;
	if(mat[i-1][j-1] == '*') count++;
	res[i-1][j-1]=count;
}

int main() {
	int n=1,m=1,c=1;
	while(cin>>n>>m) {
		if(n==0 && m==0) break;
		if(c!=1)cout<<endl;
		vector<char> row(m+2, '.');
		vector<int> nRow(m, 0);
		vector<vector<char>> mat(n+2, row) ;
		vector<vector<int>> res(n, nRow);
		read(mat);
		for(int i=1;i<mat.size()-1;i++)
			for(int j=1;j<mat[i].size()-1;j++) {
				if(mat[i][j] == '*') res[i-1][j-1] = -1;
				else bombCount(mat,res,i,j);
		}
		cout<<"Field #"<<c++<<':'<<endl;
		print(res);

	}
	return 0;
}

