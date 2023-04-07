#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int calculate(int selection, int num) {
	if (selection == 0) {
		return num + 1;
	}
	else if (selection == 1) {
		return num - 1;
	}
	else {
		return num * 2;
	}
}

int main() {
	
	int N, K;
	int visited[100001];

	cin >> N >> K;
	fill_n(visited, 100001, 0);

	int ans = 0;
	
	deque<int> q;
	q.push_back(N);

	while (!q.empty()) {
		int current;
		current= q.front();
		q.pop_front();
		if (current == K) {
			ans = visited[current];
			break;
		}
		for (int i = 0; i < 3; i++) {
			int nextp;
			nextp = calculate(i, current);
			if ((nextp >= 0 && nextp <= 100000) && (visited[nextp] == 0)) {
				visited[nextp] = visited[current] + 1;
				q.push_back(nextp);
			}
		}
	}

	cout << ans << endl;
	return 0;
}