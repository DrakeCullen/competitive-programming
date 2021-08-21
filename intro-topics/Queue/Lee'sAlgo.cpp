#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
const int NMAX = 100005;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int leeAlgo(p src, p dst, int n, int m, bool a[NMAX][NMAX]);

int main() {
	bool a[NMAX][NMAX];
	int n, m, dist[NMAX][NMAX];
	return 0;
}

int leeAlgo(p src, p dst, int n, int m, bool a[NMAX][NMAX], int dist[NMAX][NMAX]) {
	queue<p> q;
	dist[src.first][src.second] = 1;
	q.push(src);
	while(!q.empty()) {
		p cell = q.front();
		if(cell == dst)
			return dist[cell.first][cell.second] - 1;
		q.pop();
		for(int dis = 0; dis < 4; dis++) {
			if(a[cell.first + dx[dis]][cell.second + dy[dis]] == 1 && 
			   dist[cell.first + dx[dis]][cell.second + dy[dis]] == 0) {
				   dist[cell.first + dx[dis]][cell.second + dy[dis]] = dist[cell.first][cell.second] + 1;
				   q.push(make_pair(a[cell.first + dx[dis]][cell.second + dy[dis]], dist[cell.first + dx[dis]][cell.second + dy[dis]]));
			   }
					
		}	
	}
	return -1;
}
