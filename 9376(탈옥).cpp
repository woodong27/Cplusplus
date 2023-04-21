#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int t, h, w;
int visited[102][102][3];
char jail[103][103];
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };
int ans;

void bfs(int si, int sj, int scnt){
	visited[si][sj][scnt] = 0;
	deque<pair<int, int>> q;
	q.push_back({ si,sj });
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (0 <= ni && ni < h + 2 && 0 <= nj && nj < w + 2 && visited[ni][nj][scnt] == -1) {
				if (jail[ni][nj] == '.') {
					q.push_front({ ni,nj });
					visited[ni][nj][scnt] = visited[ci][cj][scnt];
				}
				else if (jail[ni][nj] == '#') {
					q.push_back({ ni,nj });
					visited[ni][nj][scnt] = visited[ci][cj][scnt] + 1;
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

		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
					jail[i][j] = '.';
				}
				else {
					cin >> jail[i][j];
				}
			}
		}

		memset(visited, -1, sizeof(visited));
		bfs(0, 0, 0);
		int cnt = 1;
		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (jail[i][j] == '$') {
					jail[i][j] = '.';
					bfs(i, j, cnt);
					cnt++;
				}
			}
		}
		
		ans = h * w;
		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				int temp;
				if (jail[i][j] != '*') {
					temp = visited[i][j][0] + visited[i][j][1] + visited[i][j][2];
					if (jail[i][j] == '#') {
						temp -= 2;
					}
					if (temp > 0) {
						ans = min(ans, temp);
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}