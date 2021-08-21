#include <bits/stdc++.h>

using namespace std;

const int ROW = 99, COL = 100;

bool isEmpty(char mat[ROW][COL], int i, int j) {
	if(mat[i+1][j] != '#' && mat[i-1][j] != '#' && mat[i][j+1] != '#' &&
	mat[i][j-1] != '#' && mat[i+1][j+1] != '#' && mat[i+1][j-1] != '#' &&
	mat[i-1][j+1] != '#' && mat[i-1][j-1] != '#')
		return true;
	return false;
}

bool isSorrounded(char mat[ROW][COL], int i, int j) {
	int count = 0;
	if(mat[i+1][j] == '#') count++;
	if(mat[i-1][j] == '#') count++;
	if(mat[i][j+1] == '#') count++;
	if(mat[i][j-1] == '#') count++;
	if(mat[i+1][j+1] == '#') count++;
	if(mat[i+1][j-1] == '#') count++;
	if(mat[i-1][j+1] == '#') count++;
	if(mat[i-1][j-1] == '#') count++;
	return count >= 4;
}

void copy(char mat[ROW][COL], char temp[ROW][COL]) {
	for(int i=0;i<ROW;i++)
		for(int j=0;j<COL;j++)
			temp[i][j]=mat[i][j];
}

int main() {
	char mat[ROW][COL], temp[ROW][COL];
	int occ = 0;
	bool changeMade = true;
	for(int i=0;i<ROW;i++)
		for(int j=0;j<COL;j++)
			mat[i][j]='.';
	for(int i=1;i<ROW-1;i++)
		for(int j=1;j<COL-1;j++)
			cin>>mat[i][j];	
	while(changeMade) {	
		changeMade = false;
		copy(mat,temp);	
		for(int i=1;i<ROW-1;i++) {
			changeMade = false;
			for(int j=1;j<COL-1;j++) {
				if(mat[i][j] == 'L') {
					if(isEmpty(mat,i,j)) {
						temp[i][j] = '#';
						changeMade = true;
					}
				} else if(mat[i][j] == '#') {
					if(isSorrounded(mat,i,j)) {
						temp[i][j] = 'L';
						changeMade = true;
					}
				}
			}
		}
		copy(temp,mat);
	}
	for(int i=1;i<ROW-1;i++)
		for(int j=1;j<COL-1;j++) {
			if(mat[i][j] == '#') occ++;
		}
	cout<<occ;	//2489
	return 0;
}

