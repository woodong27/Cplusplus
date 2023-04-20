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
deque<pair<pair<int, int>,int>> prisoners_position;

int bfs(int si, int sj, int scnt) {
	memset(visited, 0, sizeof(visited));


}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> h >> w;
		
		prisoners_position.clear();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> jail[i][j];
				if (jail[i][j] == '$') {
					prisoners_position.push_back({ { i,j },0 });
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