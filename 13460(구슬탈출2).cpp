#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, M;
char board[11][11];
int visited_red[10][10] = { 0 };
int visited_blue[10][10] = { 0 };
int si_red, sj_red, si_blue, sj_blue, ei,ej;
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };

int moving(int rsi, int rsj, int bsi, int bsj) {
	deque<pair<int, int>> redq;
	deque<pair<int, int>> blueq;
	redq.push_back({ rsi,rsj });
	blueq.push_back({ bsi,bsj });

	int cnt_red = 0;
	int cnt_blue = 0;
	visited_red[rsi][rsj] = 1;
	visited_blue[bsi][bsj] = 1;
	while (!redq.empty()) {
		int rci = redq.front().first;
		int rcj = redq.front().second;
		if (rci == ei && rcj == ej) {
			cnt_red = visited_red[rci][rcj];
		}
		for (int i = 0; i < 4; i++) {
			for (int m = 1; m < 10; m++) {
				int rni = rci + di[i] * m;
				int rnj = rcj + dj[i] * m;
				if (board[rni][rnj] == '.' && !visited_red[rni][rnj]) {
					visited_red[rni][rnj] = visited_red[rci][rcj] + 1;
				}
				else if (board[rni][rnj] == 'O' && !visited_red[rni][rnj]) {
					redq.push_back({ rni,rnj });
					visited_red[rni][rnj] = visited_red[rci][rcj] + 1;
				}
				else if ((board[rni][rni] == '#' && m > 1) || (board[rni][rnj] == 'B' && m>1)){
					redq.push_back({ rni - di[i],rnj - dj[i] });
				}
			}
		}
	}
	while (!blueq.empty()) {
		int bci = blueq.front().first;
		int bcj = blueq.front().second;
		if (bci == ei && bcj == ej) {
			cnt_red = visited_red[bci][bcj];
		}
		for (int i = 0; i < 4; i++) {
			for (int m = 1; m < 10; m++) {
				int bni = bci + di[i] * m;
				int bnj = bcj + dj[i] * m;
				if (board[bni][bnj] == '.' && !visited_red[bni][bnj]) {
					visited_red[bni][bnj] = visited_red[bci][bcj] + 1;
				}
				else if (board[bni][bnj] == 'O' && !visited_red[bni][bnj]) {
					redq.push_back({ bni,bnj });
					visited_red[bni][bnj] = visited_red[bci][bcj] + 1;
				}
				else if ((board[bni][bni] == '#' && m > 1) || (board[bni][bnj] == 'B' && m > 1)) {
					redq.push_back({ bni - di[i],bnj - dj[i] });
				}
			}
		}
	}

	if (cnt_red > 10 || cnt_red == cnt_blue) {
		return -1;
	}
	else {
		return cnt_red;
	}
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

	int ans=moving(si_red, sj_red, si_blue, sj_blue);
	cout << ans << endl;

	return 0;
}