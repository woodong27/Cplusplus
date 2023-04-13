#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int t, h, w;
char building[101][101];
int ans=0;
deque<char> keys;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

deque<pair<int, int>> find_starts() {
	deque<pair<int, int>> result;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
				if (isalpha(building[i][j])) {
					if (islower(building[i][j])) {
						keys.push_back(building[i][j]);
						building[i][j] = '.';
						result.push_back(make_pair(i, j));
					}
					else if (find(keys.begin(), keys.end(), tolower(building[i][j])) != keys.end()) {
						result.push_back(make_pair(i, j));
					}
				}
				else if (building[i][j] == '$') {
					building[i][j] = '.';
					result.push_back(make_pair(i, j));
					ans++;
				}
				else if (building[i][j] == '.') {
					result.push_back(make_pair(i, j));
				}
			}
		}
	}
	return result;
}

int bfs(deque<pair<int,int>> dq) {
	int length = 0;
	int visited[100][100] = { 0 };
	deque<pair<int, int>> q(dq);
	while (!q.empty()) {
		length++;
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop_front();
		if (building[ci][cj] == '$') {
			building[ci][cj] = '.';
			ans++;
		}
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if ((0 <= ni && ni < h && 0 <= nj && nj < w)&&!visited[ni][nj]) {
				if (isalpha(building[ni][nj])) {
					if (islower(building[ni][nj])) {
						keys.push_back(building[ni][nj]);
						building[ni][nj] = '.';
						q.push_back({ ni, nj });
					}
					else if (find(keys.begin(), keys.end(), tolower(building[ni][nj])) != keys.end()) {
						q.push_back({ ni, nj });
					}
				}
				else if (building[ni][nj] != '*') {
					q.push_back({ ni, nj });
				}
				visited[ni][nj] = 1;
			}
		}
	}
	return length;
}

int main() {

	cin >> t;
	for (int tc = 0; tc < t; tc++) {

		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
			}
		}

		string temp;
		cin >> temp;

		keys.clear();
		if (temp[0] != '0') {
			for (int i = 0; i < temp.size(); i++) {
				keys.push_back(temp[i]);
			}
		}

		ans = 0;
		int temp1 = 0;
		int temp2 = keys.size();
		while (1) {
			deque<pair<int, int>>starts(find_starts());
			if (starts.empty()) {
				break;
			}

			int moved_distance = bfs(starts);
			if (moved_distance > temp1) {
				temp1 = moved_distance;
				temp2 = keys.size();
			}
			else if (keys.size() > temp2) {
				temp2 = keys.size();
			}
			else {
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
