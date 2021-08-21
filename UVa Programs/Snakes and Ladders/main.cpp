#include <bits/stdc++.h>

using namespace std;

struct player {
	int pos = 1;
	char dir='L';
};

void init(int board[10][10], int obstacles[10][10]) {
	int c = 100;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++) {
			board[i][j] = c--;
			obstacles[i][j] = 0;
		}
}

void findPos(int board[10][10], int val, int &row, int &col) {
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(board[i][j] == val) {
				row = i;
				col = j;
				return;
			}
}

void setObst(int board[10][10], int obstacles[10][10], int obst) {
	int bot, top, r1, r2, c1, c2;
	for(int i=0;i<obst;i++) {
		cin>>bot>>top;
		findPos(board, bot, r1, c1);
		findPos(board, top, r2, c2);
		obstacles[r1][c1] = top;
		obstacles[r2][c2] = bot;
	}
}

void print(int arr[10][10]) {
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) 
			cout<<arr[i][j]<<' ';
		cout<<endl;	
	}
}

void movePlayer(int board[10][10], int obstacles[10][10], player &p, int move) {
	int r,c, count=0;
	findPos(board, p.pos, r, c);
	while(count < move) {
		if(p.dir == 'L') {
			if(c > 0) c--;
			else if (r!=0)	{r--; p.dir = 'R';}
			else if (r == 0 && c == 0) break;
		} else {
			if(c < 10) c++;
			else if (r!=0)	{r--; p.dir = 'L';}
			else if (r == 0 && c == 0) break;
		}
		count++;
	}
	if(obstacles[r][c] != 0) p.pos = obstacles[r][c];
	else p.pos = board[r][c];
}

int main() {
	int n, p, obst, rolls, move;
	int board[10][10], obstacles[10][10];
	cin>>n;
	while(n--) {
		cin>>p>>obst>>rolls;
		player players[p];
		int i=0,j;
		init(board, obstacles);
		setObst(board, obstacles, obst);
		while(i < rolls) {
			j = i;
			cin>>move;
			movePlayer(board, obstacles, players[i%p], move);
			i++;
			if(players[j%p].pos == 100) break;
		}
		while(i < rolls) {cin>>move; i++;}
		for(int i=0;i<p;i++)
			cout<<"Position of player "<<i+1<<" is "<<players[i].pos<<'.'<<endl;
	}
	return 0;
}


