#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int N, K;
int visited[100001] = { -1 };

int moving(int selection, int cur) {
	if (selection == 0) {
		return cur * 2;
	}
	else if (selection == 1) {
		return cur + 1;
	}
	else {
		return cur - 1;
	}
}

int main() {

	cin >> N >> K;

	int ans = 0;

	//queue선언해서 배열 넣어주기
	queue<pair<int, int>> q;
	q.push(pair<int, int>(N, 0));

	//cout << q.front().first;
	//cout << q.front().second;
	while (!q.empty()) {
		int current = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (current == K) {
			ans = cnt;
			break;
		}
		for (int i = 0; i < 3; i++) {
			int nextp = moving(i, current);
			if ((nextp >= 0 && nextp <= 100000) && visited[nextp] == -1) {
				visited[nextp] = current;
				q.push(pair<int, int>(nextp, cnt + 1));
			}
		}
	}

	cout << ans << endl;

	deque<int> path;
	int start = K;
	while (1) {
		path.push_front(start);
		start = visited[start];
		if (start == N) {
			break;
		}
	}
	if (path.front() != N) {
		path.push_front(N);
	}
	
	for (int i = 0; i < path.size(); i++) {
		cout << path[i];
	}
	
	return 0;
}