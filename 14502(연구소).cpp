#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int map[8][8];
int visited[8][8] = { 0 };
deque<pair<int,int>> starts;
int ans = 0;
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };

void bfs() {
	int copied_map[8][8] = { 0 };
	copy(&map[0][0], &map[0][0] + 64, &copied_map[0][0]);
	memset(visited, 0, sizeof(visited));
	deque<pair<int, int>> q(starts);
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (0 <= ni && ni < n && 0 <= nj && nj < m && !copied_map[ni][nj] && !visited[ni][nj]) {
				q.push_back({ ni,nj });
				visited[ni][nj] = 1;
				copied_map[ni][nj] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copied_map[i][j] == 0) {
				cnt++;
			}
		}
	}

	ans = max(ans, cnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				starts.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				for (int ii = i; ii < n; ii++) {
					for (int jj = 0; jj < m; jj++) {
						if (map[ii][jj] == 0) {
							map[ii][jj] = 1;
							for (int iii = ii; iii < n; iii++) {
								for (int jjj = 0; jjj < m; jjj++) {
									if (map[iii][jjj] == 0) {
										map[iii][jjj] = 1;
										bfs();
										map[iii][jjj] = 0;
									}
								}
							}
							map[ii][jj] = 0;
						}
					}
				}
				map[i][j] = 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}