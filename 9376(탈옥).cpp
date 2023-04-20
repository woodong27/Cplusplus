#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

int t, h, w;
int visited[100][100];
char jail[101][101];
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };
int prisoners;

int bfs(int si, int sj, int is_opened) {
	int catched_num = 0;
	int result = 0;
	
	deque<pair<pair<int, int>, int>> q;
	memset(visited, 0, sizeof(visited));
	visited[si][sj] = 1;
	q.push_back({ {si,sj},is_opened });

	while (!q.empty()) {
		int ci = q.front().first.first;
		int cj = q.front().first.second;
		int opened=q.front().second;
		if (jail[ci][cj] == '$') {
			catched_num++;
			result += opened;
			if (catched_num == prisoners) {
				return result;
			}
		}
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (0 <= ni && ni < h && 0 <= nj && nj < w) {
				if (!visited[ni][nj]) {

				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> h >> w;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> jail[i][j];
			}
		}

		prisoners = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (jail[i][j] == '$') {
					prisoners++;
				}
			}
		}

		int result = 0;
		int ans = h * w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					if (jail[i][j] == '#') {
						result = bfs(i, j, 1);
						ans = min(ans, result);
					}
					else if (jail[i][j] == '.') {
						result = bfs(i, j, 0);
						ans = min(ans, result);
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}