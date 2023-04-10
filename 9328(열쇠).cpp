#include <iostream>
#include <tuple>
#include <deque>
#include <string>

using namespace std;

typedef struct {
	int i;
	int j;
	int cnt;
}point;

int t, h, w;
char building[101][101];
int visited[100][100];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

void bfs(deque<point> p, deque<char> k) {
	deque<point> q(p);
	deque<char> keys(k);
	while (!q.empty()) {
		int ci, cj, cnt;
		ci = q.front().i;
		cj = q.front().j;
		cnt = q.front().cnt;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni, nj;
			ni = ci + di[i];
			nj = cj + dj[i];
			if (0 <= ni && ni <= h && 0 <= nj && nj <= w && visited[ni][nj]!=0) {
				if (building[ni][nj] != '*') {

				}
			}
		}

	}
}

int main() {

	int ans = 0;
	cin >> t;
	deque<point> starts;
	deque<char> keys;

	for (int tc = 0; tc < t; tc++) {

		cin >> h >> w;
		
		string temp;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
				if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && building[i][j] == '.') {
					starts.push_back({ i,j,0 });
				}
			}
		}

		cin >> temp;

		if (temp[0] != '0') {
			for (int i = 0; i < temp.size(); i++) {
				keys.push_back(temp[i]);
			}
		}

		bfs(starts, keys)

	}

	return 0;
}
