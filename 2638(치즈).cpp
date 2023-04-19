#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;
int cheese[100][100] = { 0 };
int visited[100][100] = { 0 };
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

int check_cheese_leftover() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cheese[i][j] == 1) {
				return 1;
			}
		}
	}
	return 0;
}

void set_air_boundry() {
	memset(visited, 0, sizeof(visited));
	deque<pair<int, int>>q;
	q.push_back({ 0,0 });
	visited[0][0] = -1;
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (0 <= ni && ni < n && 0 <= nj && nj < m && visited[ni][nj]==0) {
				if (!cheese[ni][nj]) {
					q.push_back({ ni,nj });
					visited[ni][nj] = -1;
				}
			}
		}
	}
}

void melting() {
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
		}
	}

	int flag = check_cheese_leftover();
	int cnt = 0;
	while (flag) {
		cnt += 1;
		set_air_boundry();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cheese[i][j] == 1 && !visited[i][j]) {

				}
			}
		}
	}
	


	return 0;
}