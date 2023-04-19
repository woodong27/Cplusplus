#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int board[10][10];
int n, m;
int ladder[101];
int snake[101];
int visited[10][10];

int snake_ladder() {
	deque<pair<int, int>> q;
	q.push_back({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		int current = board[ci][cj];
		if (current == 100) {
			return visited[ci][cj];
		}
		q.pop_front();
		for (int i = 1; i <= 6; i++) {
			int ni, nj;
			int next = current + i;
			if (next <= 100) {
				if (snake[next]) {
					next = snake[next];
				}
				else if (ladder[next]) {
					next = ladder[next];
				}
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (board[i][j] == next) {
							ni = i; nj = j;
						}
					}
				}
				if (!visited[ni][nj]) {
					q.push_back({ ni,nj });
					visited[ni][nj] = visited[ci][cj] + 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int cnt = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = cnt;
			cnt++;
		}
	}

	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		ladder[s] = e;
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		snake[s] = e;
	}

	int ans = snake_ladder() - 1;

	cout << ans << '\n';

	return 0;
}