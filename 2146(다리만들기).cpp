#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N;
int sea[100][100];
int visited[100][100] = { 0 };
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

void bfs(int si, int sj, int cnt) {
	deque<pair<int, int>> q;
	q.push_back({ si,sj });
	visited[si][sj] = cnt;
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (0 <= ni && ni < N && 0 <= nj && nj < N && sea[ni][nj]==1 && !visited[ni][nj]) {
				q.push_back({ ni,nj });
				visited[ni][nj] = cnt;
			}
		}
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sea[i][j];
		}
	}

	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (sea[i][j] == 1 && !visited[i][j]) {
				bfs(i, j, num);
				num++;
			}
		}
	}

	vector <pair<int, pair<int, int>>> islands;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) {
				islands.push_back({ visited[i][j],{i,j} });
			}
		}
	}

	sort(islands.begin(), islands.end());
	
	int ans = N * 2;
	for (int cnt = 1; cnt < num; cnt++) {
		for (int i = 0; i < islands.size(); i++) {
			if (islands[i].first == cnt) {
				for (int j = i + 1; j < islands.size(); j++) {
					if (islands[j].first != cnt) {
						int manhattan_distance = abs(islands[i].second.first - islands[j].second.first) + abs(islands[i].second.second - islands[j].second.second);
						ans = min(ans, manhattan_distance);
					}
				}
			}
		}
	}

	ans -= 1;
	cout << ans << endl;

	return 0;
}