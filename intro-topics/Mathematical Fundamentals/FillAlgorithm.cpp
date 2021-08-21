#include <iostream>
#include <climits>

using namespace std;

const int NMAX = 1005;

char a[NMAX][NMAX];
bool vis[NMAX][NMAX];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

bool isValid(int row, int col, int n, int m) {
	if(row < 1 || row > n || col < 1 || col > m)
		return false;
	if(a[row][col] == '#' || vis[row][col])
		return false;
	return true;	
}

void fillAlgo(int row, int col, int& cellsCnt, int n, int m) {
	cellsCnt++;
	vis[row][col] = true;
	for(int dir = 0; dir < 4; dir++) 
		if(isValid(row + dx[dir], col + dy[dir], n, m))
			fillAlgo(row + dx[dir], col + dy[dir], cellsCnt, n, m);
}

int main() {
	int n, m, islandsCnt = 0, maxCellsCnt = 0;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin>>a[i][j];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(isValid(i, j, n, m)) {
				islandsCnt++;
				int cellsCnt = 0;
				fillAlgo(i, j, cellsCnt, n, m);
				maxCellsCnt = max(maxCellsCnt, cellsCnt);
			}
	
	cout<<islandsCnt<<' '<<maxCellsCnt<<endl;		
	return 0;
}
