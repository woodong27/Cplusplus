#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int R, C;
int ans = 0;
char board[21][21];
int visited[20][20];
deque<char> path;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

void backtrack(int ci, int cj) {
	if (ans < path.size()) {
		ans = path.size();
	}

	for (int i = 0; i < 4; i++) {
		int ni = ci + di[i];
		int nj = cj + dj[i];
		if (0 <= ni && ni < R && 0 <= nj && nj < C && !visited[ni][nj]) {
			if (find(path.begin(),path.end(),board[ni][nj])==path.end()) {
				visited[ni][nj] = 1;
				path.push_back(board[ni][nj]);
				backtrack(ni, nj);
				path.pop_back();
				visited[ni][nj] = 0;
			}
		}
	}
}

int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	path.push_back(board[0][0]);
	visited[0][0] = 1;
	backtrack(0, 0);

	cout << ans;

	return 0;
}