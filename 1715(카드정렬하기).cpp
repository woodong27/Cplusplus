#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, cards, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cards;
		pq.push(cards);
	}

	int temp = 0;
	int cnt = 0;
	while (!pq.empty()) {
		temp += pq.top();
		pq.pop();
		cnt++;

		if (cnt == 2) {
			ans += temp;
			cnt = 0;
			pq.push(temp);
			temp = 0;
		}
	}

	cout << ans << '\n';

	return 0;
}