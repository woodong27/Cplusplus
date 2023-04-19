#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int n, m;
int map[1000][1000];
int visited[1000][1000] = { 0 };
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };

int moving() {
	deque<pair<pair<int, int>, int>> q;
	q.push_back({ {0,0},0 });
	visited[0][0] = 1;
	while (!q.empty()) {
		int ci = q.front().first.first;
		int cj = q.front().first.second;
		int broken = q.front().second;
		if (ci == n - 1 && cj == m - 1) {
			return visited[ci][cj];
		}
		cout << ci << cj << broken << endl;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (0 <= ni && ni < n && 0 <= nj && nj < m) {
				//�湮�� �� ������
				if (!visited[ni][nj]) {
					//���� �μ����� ������ �״�� ����
					if (map[ni][nj] == 0) {
						q.push_back({ {ni,nj},broken });
						visited[ni][nj] = visited[ci][cj] + 1;
					}
					//����ĭ�� ���̰� ���� �μ����� ���ٸ� ���� �μ��� ������
					//broken+1�� �� �μ��� ǥ��
					else if (map[ni][nj] == 1 && !broken) {
						q.push_back({ {ni,nj},broken + 1 });
						visited[ni][nj] = visited[ci][cj] + 1;
					}
				}
				//�湮�� �� ������
				//������ ���� �μ��� �湮�ߴµ� �̹��� ���� �Ⱥμ��� �Դٸ� �� �� ����
				else {
					if (!broken) {
						if (map[ni][nj] == 0) {
							q.push_back({ {ni,nj},broken });
							visited[ni][nj] = visited[ci][cj] + 1;
						}
						else if (map[ni][nj] == 1) {
							q.push_back({ {ni,nj},broken + 1 });
							visited[ni][nj] = visited[ci][cj] + 1;
						}
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			map[i][j] = temp[j]-'0';
		}
	}

	int ans = moving();

	cout << ans << '\n';

	return 0;
}