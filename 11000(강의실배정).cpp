#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

int N, start_time, end_time;
deque<pair<int, int>> lessons;
priority_queue<int, vector<int>, greater<int>> classes;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start_time >> end_time;
		lessons.push_back({ start_time, end_time });
	}

	sort(lessons.begin(), lessons.end());

	while (!lessons.empty()) {
		int s = lessons.front().first;
		int e = lessons.front().second;
		lessons.pop_front();

		if (classes.empty()) {
			classes.push(e);
		}
		else {
			if (classes.top() <= s) {
				classes.pop();
			}
			classes.push(e);
		}
	}

	int ans = classes.size();

	cout << ans << '\n';

	return 0;
}