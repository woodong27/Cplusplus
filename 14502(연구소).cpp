#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n, m;
int map[8][8];
int visited[8][8] = { 0 };
deque<pair<int,int>> starts;
int ans = 0;
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };

void bfs() {
	deque<pair<int, int>> q(starts);
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (0 <= ni && ni < n && 0 <= nj && nj < m && map[ni][nj]==0 && !visited[ni][nj]) {
				q.push_back({ ni,nj });
				visited[ni][nj] = 1;
			}
		}
	}
}

int counting() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
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
				visited[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				for (int ii = i; ii < n; ii++) {
					for (int jj = j + 1; jj < m; jj++) {
						if (map[ii][jj] == 0) {
							map[ii][jj] = 1;
							for (int iii = ii; iii < n; iii++) {
								for (int jjj = jj + 1; jjj < m; jjj++) {
									if (map[iii][jjj] == 0) {
										map[iii][jjj] = 1;
										bfs();
										ans = max(ans, counting());
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