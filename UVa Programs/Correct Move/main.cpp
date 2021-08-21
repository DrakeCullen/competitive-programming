#include <bits/stdc++.h>

using namespace std;

void getPost(int mat[12][12], int &r, int &c, int val) {
	while(mat[r][2] + 7 < val) r++;
	while(mat[r][c] != val) c++;
	//cout<<r<<' '<<c<<endl;
}

bool checkKing(int mat[12][12], int r, int c, int qr, int qc) {
	int v1,v2,v3,v4,v5;
	v1 = mat[qr][qc];
	v2 = mat[qr+1][qc];
	v3 = mat[qr-1][qc];
	v4 = mat[qr][qc+1];
	v5 = mat[qr][qc-1];
	if(mat[r+1][c] != v1 || mat[r+1][c] != v2 || mat[r+1][c] != v3 || mat[r+1][c] != v4 || mat[r+1][c] != v5 && mat[r+1][c] != 0)
		return true;
	if(mat[r-1][c] != v1 || mat[r-1][c] != v2 || mat[r-1][c] != v3 || mat[r-1][c] != v4 || mat[r-1][c] != v5 && mat[r-1][c] != 0)
		return true;
	if(mat[r][c+1] != v1 || mat[r][c+1] != v2 || mat[r][c+1] != v3 || mat[r][c+1] != v4 || mat[r][c+1] != v5 && mat[r][c+1] != 0)
		return true;
	if(mat[r][c-1] != v1 || mat[r][c-1] != v2 || mat[r][c-1] != v3 || mat[r][c-1] != v4 || mat[r][c-1] != v5 && mat[r][c-1] != 0)
		return true;	
	return true;	
}

int main() {
	int mat[12][12], sum = 0, k, q, newQ;
	for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)
			mat[i][j] = 0;
	for(int i=2;i<10;i++)
		for(int j=2;j<10;j++)
			mat[i][j] = sum++;
	while(cin>>k>>q>>newQ) {
		bool state= false, move = false, cont = false, poss = true, queenBlock = false;
		if(k == q) state = true;
		int r1,r2,r3,c1,c2,c3;
		r1=r2=r3=c1=c2=c3 = 2;
		getPost(mat,r1,c1,k);
		getPost(mat,r2,c2,q);
		getPost(mat,r3,c3,newQ);
		if(c3 == c1 && r3 == r1) move = true;
		if(c3 != c2 && r3 != r2) poss = false;
		while(r2 != r3) {
			if(r3 > r2 && r2 < 9) {
				++r2;
				if(r2 == r1) move = true; 
			} else if(r2 > r3 && r2 > 2) {
				--r2;
				if(r2 == r1) move = true;
			}
		}
		//cout<<c2<<' '<<c3;
		while(c2 != c3) {
			if(c3 > c2 && c2 < 9) {
				++c2;
				if(c2 == c1) move = true;
			} else if(c2 > c3 && c2 > 2){
				--c2;
				if(c2 == c1) move = true;
			}
		}
		if(mat[r3+1][c3] == mat[r1][c1] || mat[r3-1][c3] == mat[r1][c1] || mat[r3][c3+1] == mat[r1][c1] ||
		   mat[r3][c3-1] == mat[r1][c1]) queenBlock = true;
		cont = checkKing(mat,r1,c1,r3,c3);
		if(!state && !move && queenBlock) cout<<"Move not allowed"<<endl;
		else if(state) cout<<"Illegal state"<<endl;
		else if(move || !poss) cout<<"Illegal move"<<endl;
		else if(cont) cout<<"Continue"<<endl;
		else cout<<"Stop"<<endl;
		
	}		
	return 0;
}


//|| mat[r3+1][c3+1] == mat[r1][c1] || mat[r3+1][c3-1] == mat[r1][c1] ||
//		   mat[r3-1][c3+1] == mat[r1][c1] || mat[r3-1][c3-1] == mat[r1][c1]





