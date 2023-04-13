#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, M;
char board[11][11];
int visited[10][10] = { 0 };
int si_red, sj_red, si_blue, sj_blue, ei,ej;
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };

int moving(int rsi, int rsj, int bsi, int bsj) {
	deque<pair<int, int>> redq;
	deque<pair<int, int>> blueq;
	redq.push_back({ rsi,rsj });
	blueq.push_back({ bsi,bsj });

	int cnt_red;
	visited[rsi][rsj] = 1;
	while (!redq.empty()) {
		int ci = redq.front().first;
		int cj = redq.front().second;
		cout << ci << cj;
		if (board[ci][cj] == 'O') {
			cnt_red = visited[ci][cj];
			break;
		}
		for (int i = 0; i < 4; i++) {
			for (int m = 1; m < 10; m++) {
				int ni = ci + m * di[i];
				int nj = cj + m * dj[i];
				if (board[ni][nj] != '#' && board[ni][nj] != 'B' && !visited[ni][nj]) {
					visited[ni][nj] = visited[ci][cj]+1;
				}
				else if (m!=1 && board[ni][nj]=='#' && board[ni-di[i]][nj-dj[i]]=='.') {
					redq.push_back({ ni - di[i],nj - dj[i] });
				}

			}
		}
	}
	return cnt_red;

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				si_red = i;
				sj_red = j;
			}
			else if (board[i][j] == 'B') {
				si_blue = i;
				si_blue = j;
			}
		}
	}

	int red_result=moving(si_red, sj_red, si_blue, sj_blue);
	cout << red_result;
	return 0;
}