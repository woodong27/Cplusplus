#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N, stime, etime;
deque<pair<int, int>> meetings;

bool compare(pair<int,int>&a, pair<int,int>&b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stime >> etime;
		meetings.push_back({ stime, etime });
	}

	sort(meetings.begin(), meetings.end(), compare);

	int cnt = 0;
	while (!meetings.empty()) {
		int s = meetings.front().first;
		int e = meetings.front().second;
		meetings.pop_front();
		while (!meetings.empty() && meetings.front().first < e) {
			meetings.pop_front();
		}
		cnt += 1;
	}

	cout << cnt << '\n';

	return 0;
}